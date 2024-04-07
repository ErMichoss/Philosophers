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

void ft_init(t_rules *rules)
{
    int i:

    i = -1;
    while(++i < rules->n_philo)
    {
        rules->philo[i].id = i + 1;
        rules->philo[i].last_meal = 0;
        rules->philo[i].fork_r = NULL;
        rules->philo[i].rules = rules;
        rules->philo[i].meal_count = 0;
        pthread_mutex_init(&(rules->philo[i].fork_l), NULL);
        if (i != rules->n_philo - 1)
            rules->philo[i].fork_r = &rules->philo[i + 1].fork_l;
        else
            rules->philo[i].fork_r = &rules->philo[0].fork_l;
    }
}