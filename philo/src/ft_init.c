/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:46:07 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 11:26:49 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void    ft_init(t_rules *rules)
{
    int i;

    rules->time_start = get_time();
    i = -1;
    while(++i < rules->n_philo)
    {
        //write(1, "Entra en bucle init\n", 20);
        rules->philo[i].id = i + 1; 
        rules->philo[i].last_meal = 0; 
        rules->philo[i].fork_r = NULL; 
        rules->philo[i].rules = rules; 
        rules->philo[i].meal_count = 0; 
        pthread_mutex_init(&(rules->philo[i].fork_l), NULL); 
        if (i != rules->n_philo - 1) 
            rules->philo[i].fork_r = &rules->philo[i + 1].fork_l;
        else
        { 
            rules->philo[i].fork_r = &rules->philo[0].fork_l;
            //write(1, "Coge el ultimo tenedor\n", 23);
        }
        pthread_create(&rules->philo[i].thread, NULL, &philo_rutine, &(rules->philo[i]));
    }
    i = -1;
	while (++i < rules->n_philo)
    {
        //write(1, "Espera a que terminen los threads\n", 34);
		pthread_join(rules->philo[i].thread, NULL);
    }
}