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

void    take_fork(t_philo *philo)
{
    //no salir de aqui hasta tener dos tenedores.
    pthread_mutex_lock(&(philo->fork_l));
    print(philo, "has taken fork\n");
    if (philo->rules->n_philo == 1)
    {
        ft_usleep(philo->rules->t_die * 2);
        return ;
    }
    pthread_mutex_lock(philo->fork_r);
    print(philo, "has taken fork\n");
}

void    philo_eat(t_philo *philo)
{
    print(philo, "is eating\n");
    pthread_mutex_lock(philo->rules->mutex_eat);
    philo->last_meal = timestamp();
    philo->meal_count++;
    pthread_mutex_unlock(philo->rules->must_eat);
    
}

void    *philo_rutine(void *phi)
{
    t_philo *philo;
    //eat, sleep, think, not die. :D
    philo = (t_philo *)phi;
    while (1)
    {
        take_fork(philo);
        philo_eat(philo);
    }
    return NULL;
}