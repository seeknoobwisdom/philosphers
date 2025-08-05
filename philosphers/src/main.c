/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:51:06 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/04/23 10:41:25 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philospher(t_table *p, t_philospher *philo)
{
	int	i;

	i = -1;
	while (++i < p->num)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].iter_num = 0;
		philo[i].thread_start = 0;
		philo[i].meal = 0;
		philo[i].par = p;
		philo[i].left_fork = &p->fork[i];
		philo[i].right_fork = 0;
	}
	return (0);
}

static int	init_table_mutex(t_table *p)
{
	int	i;

	i = -1;
	p->death = 0;
	p->fork = 0;
	p->death = malloc(sizeof(pthread_mutex_t));
	if (!p->death)
		return (error_msg("Error\nMutex death: malloc failed\n", p, 0, 1));
	p->fork = malloc(sizeof(pthread_mutex_t) * p->num);
	if (!p->fork)
		return (error_msg("Error\nMutex fork: malloc failed\n", p, 0, 1));
	if (pthread_mutex_init(p->death, NULL) == -1)
		return (error_msg("Error\nMutex init failed\n", p, 0, 1));
	while (++i < p->num)
		if (pthread_mutex_init(&p->fork[i], NULL) == -1)
			return (error_msg("Error\nMutex init failed\n", p, 0, 1));
	return (0);
}

static int	init_table(t_table *p, char **ag)
{
	int	mutex;

	mutex = -1;
	p->num = ft_atoi(ag[1]);
	p->time_to_die = ft_atoi(ag[2]);
	p->time_to_eat = ft_atoi(ag[3]);
	p->time_to_sleep = ft_atoi(ag[4]);
	p->max_eat = -2;
	p->check_meal = 0;
	p->start = 0;
	p->ready = 0;
	if (ag[5])
	{
		p->check_meal = 1;
		p->max_eat = ft_atoi(ag[5]);
	}
	p->over = 0;
	if (p->num > 0)
		mutex = init_table_mutex(p);
	return (mutex || p->num <= 0 || p->time_to_die <= 0 || p->time_to_eat <= 0
		|| p->time_to_sleep <= 0 || p->max_eat == 0);
}

int	main(int ac, char **ag)
{
	t_table	p;

	if ((ac != 5 && ac != 6) || init_table(&p, ag))
		return (error_msg("Error: invalid arguments\n", &p, 0, 1));
	if (philosophers(&p))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
