/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:43:03 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 13:47:24 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_program(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->n_philo)
	{
		pthread_mutex_destroy(&rules->philo[i].fork_l);
		pthread_mutex_destroy(rules->philo[i].fork_r);
	}
	free(rules->philo);
	pthread_mutex_destroy(&rules->mutex_ft_print);
	pthread_mutex_destroy(&rules->stop_philo);
	pthread_mutex_destroy(&rules->mutex_eat);
	pthread_mutex_destroy(&rules->mutex_dead);
}

void	ft_check_must_eat(int argc, t_rules *rules)
{
	if (argc == 5)
		rules->must_eat = 0;
	else
		rules->must_eat = 1;
}

void	ft_checkargs(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_error_msg("Invalid number of arguments");
	else if (argc < 5 || argc > 6)
		ft_error_msg("Invalid number of arguments");
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isnum(argv[i]) == 1)
			ft_error_msg("Invalid type of arguments");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_rules	rules;

	ft_checkargs(argc, argv);
	ft_check_must_eat(argc, &rules);
	ft_set_parameters(argv, &rules);
	ft_init(&rules);
	free_program(&rules);
	return (0);
}
