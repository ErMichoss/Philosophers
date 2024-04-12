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
    printf("philos %d has taken fork\n", philo->id);
    if (philo->rules->n_philo == 1)
    {
        ft_usleep(philo->rules->t_die * 2);
        return ;
    }
    pthread_mutex_lock(philo->fork_r);
    printf("philo %d has taken fork\n", philo->id);
}

void    philo_eat(t_philo *philo)
{
    printf("philo %d is eating", philo->id);

}

void    *philo_rutine(void *phi)
{
    t_philo *philo;
    //eat, sleep, think, not die. :D
    philo = (t_philo *)phi;
    take_fork(philo);
    return NULL;
}