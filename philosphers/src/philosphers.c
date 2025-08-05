/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:51:09 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/04/23 10:41:27 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_meals(t_philospher p, int last)
{
	if (p.par->check_meal
		&& last == p.par->num - 1
		&& p.iter_num == p.par->max_eat)
		return (sleep_mili(300));
	return (0);
}

static void	check_thread(t_table *p, t_philospher *philo)
{
	int	i;

	while (!p->ready)
		continue ;
	while (!p->over)
	{
		i = -1;
		while (++i < p->num)
			if (check_death(&philo[i]) || check_meals(philo[i], i))
				p->over = 1;
	}
	if (p->check_meal && philo[p->num - 1].iter_num == p->max_eat)
	{
		sleep_mili(5 * p->num);
		printf("						\n");
		printf("  All philosophers have eaten %d times\n", p->max_eat);
		return ;
	}
	return ;
}

static int	init_thread(t_table *p, t_philospher *philo)
{
	int	i;

	i = -1;
	while (++i < p->num)
	{
		philo[i].right_fork = philo[(i + 1) % p->num].left_fork;
		if (pthread_create(&philo[i].life_tid, NULL,
				&thread_routine, &philo[i]) == -1)
			return (error_msg("Error\nFailed to create thread\n", p, philo, 2));
	}
	i = -1;
	p->start = time_now();
	while (++i < p->num)
	{
		philo[i].thread_start = p->start;
		philo[i].meal = p->start;
	}
	p->ready = 1;
	return (0);
}

static void	end_thread(t_table *p, t_philospher *philo)
{
	int	i;

	i = -1;
	while (++i < p->num)
		pthread_join(philo[i].life_tid, (void *)&philo[i]);
	pthread_mutex_destroy(p->death);
	pthread_mutex_destroy(p->fork);
	free(p->death);
	free(p->fork);
	free(philo);
}

int	philosophers(t_table *params)
{
	t_philospher	*philo;

	philo = malloc(sizeof(t_philospher) * params->num);
	if (!philo || init_philospher(params, philo))
		return (EXIT_FAILURE);
	if (init_thread(params, philo))
		return (EXIT_FAILURE);
	check_thread(params, philo);
	end_thread(params, philo);
	return (0);
}
