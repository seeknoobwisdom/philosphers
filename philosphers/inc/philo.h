/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:51:23 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/04/23 10:41:23 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "is DEAD"
# define LEFT 0
# define RIGHT 1

typedef struct s_params
{
	int				num;
	int				ready;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				check_meal;
	int				over;
	long int		start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				iter_num;
	long int		thread_start;
	long int		meal;
	pthread_t		life_tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*par;
}	t_philospher;

int			philosophers(t_table *p);
int			init_philospher(t_table *p, t_philospher *philo);
int			check_death(t_philospher *p);
int			ft_atoi(const char *str);
int			sleep_mili(long int time);
int			error_msg(char *s, t_table *par, t_philospher *p, int malloc);
void		*thread_routine(void *job);
void		final_print(int alive);
void		print_routine(t_philospher *p, char *action);
long int	time_now(void);

#endif