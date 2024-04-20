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

typedef struct l_rules t_rules;

typedef struct s_philo
{
    int				id;
	int				meal_count;
	bool			is_eating;
	pthread_t		thread;
	long int		last_meal;
	struct l_rules	*rules;
	pthread_mutex_t *fork_r;
	pthread_mutex_t fork_l;
}       t_philo;

struct l_rules
{
    int				must_eat;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	int				stop_flag;
	long int		time_start;
	t_philo			*philo;
	pthread_mutex_t stop_philo;
	pthread_mutex_t mutex_eat;
	pthread_mutex_t mutex_dead;
	pthread_mutex_t mutex_ft_print;
	pthread_mutex_t mutex_dead_aux;
};



//*** MAIN ***
int     main(int argc, char *argv[]);

//*** ERRORS ***

void    ft_error_msg(char *str);

//*** FUNCT ***

void    	ft_checkargs(int argc, char **argv);
void    	ft_check_must_eat(int argc, t_rules *rules);
int     	ft_isnum(char *str);
int     	ft_atoi(char *str);
void    	ft_set_parameters(char **argv, t_rules *rules);
void		*philo_rutine(void *p);
void 		ft_init(t_rules *rules);
int			is_dead(t_philo *philo, int nb);
long		get_time(void);
void		ft_usleep(int ms);
void		ft_print(t_philo *philo, char *str);
void    	philo_eat(t_philo *philo);
void    	take_fork(t_philo *philo);

//*** FREE ***
void	free_program(t_rules *rules);

#endif
