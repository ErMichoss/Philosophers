/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:51:31 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 13:53:22 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
    int				id; // the id of the philo
	int				meal_count; // the number of meals it has had
	int				is_eating; // a flag to know if the philo is eating
	pthread_t		thread; // the thread (this is the philosopher)
	long int		last_meal; // the last meal the philo had
	struct s_rules	*rules; // a pointer to ther rules struct
	pthread_mutex_t *fork_r; // a pointer to the fork of the philospher to the right
	pthread_mutex_t fork_l; // left fork
}       t_philo;

typedef struct s_rules
{
    int				must_eat; // a flag to know if the program must stop at a number of meals
	int				n_philo; // number of philos
	int				t_die; // death time
	int				t_eat; // eat time
	int				t_sleep; // sleep time
	int				n_meals; // numbre of meals
	int				stop_flag; // a flag to stop
	long int		time_start;
	t_philo			*philo; // array of philo's struct
	pthread_mutex_t stop_philo; // mutex declared to stop the philo's ruting
	pthread_mutex_t mutex_eat; // mutex declared for eating
	pthread_mutex_t mutex_dead; // mutex declared for checking death
	pthread_mutex_t mutex_print; // mutex declared for printing
}   t_rules;



//*** MAIN ***
int     main(int argc, char *argv[]);

//*** ERRORS ***

void    ft_error_msg(char *str);

//*** FUNCT ***

void    ft_checkargs(int argc, char **argv);
void    ft_check_must_eat(int argc, t_rules *rules);
int     ft_isnum(char *str);
int     ft_atoi(char *str);
void    ft_set_parameters(char **argv, t_rules *rules);
void	*philo_rutine(void *phi);
void 	ft_init(t_rules *rules);
int	is_dead(t_philo *philo, int nb);
long long	timestamp(void);
void	ft_usleep(int ms);
void	print(t_philo *philo, char *str);


#endif
