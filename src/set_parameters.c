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

#include "philo.h"

void	ft_set_parameters(char **argv, t_rules *rules)
{
	pthread_mutex_init(&rules->mutex_ft_print, NULL);
	pthread_mutex_init(&rules->mutex_eat, NULL);
	pthread_mutex_init(&rules->mutex_dead, NULL);
	pthread_mutex_init(&rules->stop_philo, NULL);
	rules->n_philo = ft_atoi(argv[1]);
	if (rules->n_philo < 1)
		ft_error_msg("Number of philosphers not valid\n");
	rules->t_die = ft_atoi(argv[2]);
	rules->t_eat = ft_atoi(argv[3]);
	rules->t_sleep = ft_atoi(argv[4]);
	if (rules->must_eat == 1)
	{
		rules->n_meals = ft_atoi(argv[5]);
		if (rules->n_meals < 1)
			ft_error_msg("You must input a valid number of meals\n");
	}
	rules->stop_flag = 0;
	rules->philo = malloc(sizeof(t_philo) * rules->n_philo);
	if (rules->philo == NULL)
		ft_error_msg("Error trying to set the philo array\n");
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != 0)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
