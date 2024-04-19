/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:43:03 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 13:47:24 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void    *check_dead(void *p)
{
    t_philo *philo;

    philo = (t_philo *)p;
    ft_usleep(philo->rules->t_die + 1);
    pthread_mutex_lock(&(philo->rules->mutex_eat));
    pthread_mutex_lock(&(philo->rules->stop_philo));
    if (is_dead(philo, 0) == 0 && get_time() - philo->last_meal >= (long)(philo->rules->t_die))
    {
        ft_print(philo, " died\n");
        is_dead(philo, 1);
    }
    pthread_mutex_unlock(&(philo->rules->mutex_eat));
    pthread_mutex_unlock(&(philo->rules->stop_philo));
    return (NULL);
}

void    take_fork(t_philo *philo)
{
    pthread_mutex_lock(&(philo->fork_l));
    ft_print(philo, " has taken fork\n");
    if (philo->rules->n_philo == 1)
    {
        ft_usleep(philo->rules->t_die + 1);
        return ;
    }
    pthread_mutex_lock(philo->fork_r);
    ft_print(philo, " has taken fork\n");
}

void    philo_eat(t_philo *philo)
{
    ft_print(philo, " is eating\n");
    pthread_mutex_lock(&(philo->rules->mutex_eat));
    ft_usleep(philo->rules->t_eat);
    philo->last_meal = get_time();
    philo->meal_count++;
    pthread_mutex_unlock(&(philo->rules->mutex_eat));
    pthread_mutex_unlock(&(philo->fork_l));
    pthread_mutex_unlock(philo->fork_r);
    ft_print(philo, " is sleeping\n");
    ft_usleep(philo->rules->t_sleep);
    ft_print(philo, " is thinking\n");
}

void    *philo_rutine(void *p)
{
    t_philo *philo;
    pthread_t   thread;

    philo = (t_philo *)p;
    if (philo->id % 2 == 0)
        ft_usleep(philo->rules->t_eat / 10);
    while (is_dead(philo, 0) == 0)
    {
        pthread_create(&thread, NULL, check_dead, p);
        take_fork(philo);
        if (philo->rules->n_philo != 1)
            philo_eat(philo);
        pthread_detach(thread);
        if (philo->rules->must_eat == 1)
		{
            pthread_mutex_lock(&(philo->rules->stop_philo));
            if (philo->meal_count == philo->rules->n_meals)
            {
                pthread_mutex_unlock(&(philo->rules->stop_philo));
                return(NULL);
            }
			pthread_mutex_unlock(&(philo->rules->stop_philo));
		}
        pthread_mutex_lock(&(philo->rules->stop_philo));
        pthread_mutex_unlock(&(philo->rules->stop_philo));
    }
    return NULL;
}