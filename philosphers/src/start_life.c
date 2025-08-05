/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:51:12 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/04/23 08:57:03 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	someone_died(t_philospher *p)
{
	print_routine(p, DIE);
	p->par->over = 1;
	p->dead = 1;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	return (1);
}

int	check_death(t_philospher *p)
{
	long int	now;

	pthread_mutex_lock(p->par->death);
	now = time_now() - p->meal;
	if (now >= p->par->time_to_die)
	{
		pthread_mutex_unlock(p->par->death);
		return (someone_died(p));
	}
	pthread_mutex_unlock(p->par->death);
	return (0);
}

void	ft_sleep_and_think(t_philospher *p)
{
	sleep_mili(p->par->time_to_sleep);
	print_routine(p, SLEEP);
	print_routine(p, THINK);
}

void	ft_eat(t_philospher *p)
{
	pthread_mutex_lock(p->left_fork);
	print_routine(p, FORK);
	pthread_mutex_lock(p->right_fork);
	print_routine(p, FORK);
	p->meal = time_now();
	sleep_mili(p->par->time_to_eat);
	print_routine(p, EAT);
	p->iter_num++;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	*thread_routine(void *job)
{
	t_philospher	*p;

	p = (t_philospher *)job;
	while (!p->par->ready)
		continue ;
	if (p->id % 2 == 1)
		sleep_mili(p->par->time_to_eat * 0.9 + 1);
	while (!p->par->over)
	{
		ft_eat(p);
		ft_sleep_and_think(p);
	}
	return (NULL);
}
