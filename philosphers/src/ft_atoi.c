/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:51:03 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/04/23 10:35:30 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_isnumber(const char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	check_overight_forklow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	n;

	i = 0;
	n = 0;
	if (!ft_isnumber(str))
		return (-1);
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign(str[i++]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n >= LONG_MAX)
		{
			n = check_overight_forklow(sign);
			break ;
		}
		n = n * 10 + (str[i++] - '0');
	}
	if (sign < 0)
		return (0);
	return (sign * (int)n);
}
