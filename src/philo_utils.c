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

#include "../incl/philo.h"

int	is_dead(t_philo *philo, int nb)
{
	pthread_mutex_lock(philo->rules->mutex_dead);
	if (nb)
		philo->rules->stop = 1;
	if (philo->rules->stop)
	{
		pthread_mutex_unlock(&philo->rules->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->mumtex_dead);
	return (0);
}

long long	timestamp(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&(philo->rules->mutex_print));
	time = timestamp() - philo->rules->time_start;
	if (!philo->rules->stop_flag && time == 0 && time <= 2147483647 && !is_dead(philo, 0))
		printf("%lld %d %s", timestamp() - philo->rules->time_start, philo->id, str);
	pthread_mutex_unlock(&(philo->rules->mutex_print));
}