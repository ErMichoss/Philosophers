/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:43:03 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 13:47:24 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, int nb)
{
	pthread_mutex_lock(&(philo->rules->mutex_dead));
	if (nb == 1)
	{
		philo->rules->stop_flag = 1;
	}
	if (philo->rules->stop_flag == 1)
	{
		pthread_mutex_unlock(&(philo->rules->mutex_dead));
		return (1);
	}
	pthread_mutex_unlock(&(philo->rules->mutex_dead));
	return (0);
}

long	get_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1e3 + timeval.tv_usec / 1e3);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(ms / 10);
}

void	ft_print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&(philo->rules->mutex_ft_print));
	time = get_time() - philo->rules->time_start;
	if (is_dead(philo, 0) == 0)
	{
		printf("\033[0;92m");
		printf("%-6ld ", get_time() - philo->rules->time_start);
		printf("\033[0;93m");
		printf("%d ", philo->id);
		printf("\033[0;96m");
		printf("%s", str);
		printf("\033[0;39m");
	}
	pthread_mutex_unlock(&(philo->rules->mutex_ft_print));
}
