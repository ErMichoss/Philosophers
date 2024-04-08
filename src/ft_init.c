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
/*Esto inicializa filosofos con cubiertos*/
void ft_init(t_rules *rules)
{
    int i:

    i = -1;
    while(++i < rules->n_philo)
    {
        rules->philo[i].id = i + 1; // Initialises philo's id
        rules->philo[i].last_meal = 0; // Initialises the last meal to 0
        rules->philo[i].fork_r = NULL; // Initialises the r fork to NULL for the moment
        rules->philo[i].rules = rules; // Points to the rules struct
        rules->philo[i].meal_count = 0; // Initialises the meal count to 0
        pthread_mutex_init(&(rules->philo[i].fork_l), NULL); // Initiañoses the left fork
        if (i != rules->n_philo - 1) // Points to the left fork of the philo on the right
            rules->philo[i].fork_r = &rules->philo[i + 1].fork_l;
        else // the last is the first
            rules->philo[i].fork_r = &rules->philo[0].fork_l;

        if (pthread_create(&rules->philo[i].thread, NULL, &philo_rutine, &(rules->philo[i])) != 0)
            ft_error_msg("Problema al generar hilo");
    }
}