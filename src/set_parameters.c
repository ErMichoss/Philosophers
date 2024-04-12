/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:46:07 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 11:26:49 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void    ft_set_parameters(char **argv, t_rules *rules)
{
    rules->n_philo = ft_atoi(argv[1]);
    if (rules->n_philo < 1)
        ft_error_msg("Number of philosphers not valid\n");
    rules->t_die = ft_atoi(argv[2]);
    rules->t_eat = ft_atoi(argv[3]);
    rules->t_sleep = ft_atoi(argv[4]);
    if (rules->must_eat == 1)
        rules->n_meals = ft_atoi(argv[5]);
    rules->philo = malloc(sizeof(t_philo) * rules->n_philo);
    if (rules->philo == NULL)
        ft_error_msg("Error trying to set the philo array\n");
}

int ft_atoi(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while(str[i] != 0)
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}