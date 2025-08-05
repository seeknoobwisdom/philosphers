/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:51:18 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/04/23 10:37:51 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	error_msg(char *s, t_table *par, t_philospher *p, int malloc)
{
	if (malloc)
	{
		if (par->death)
			free(par->death);
		if (par->fork)
			free(par->fork);
		if (p)
			free(p);
	}
	return (printf("%s", s));
}

void	print_routine(t_philospher *p, char *action)
{
	pthread_mutex_lock(p->par->death);
	if (p->par->over)
	{
		pthread_mutex_unlock(p->par->death);
		return ;
	}
	printf("%ldms %d %s\n", time_now() - p->thread_start,
		p->id, action);
	pthread_mutex_unlock(p->par->death);
}
