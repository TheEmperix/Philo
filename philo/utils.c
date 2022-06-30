/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:14:15 by woberon           #+#    #+#             */
/*   Updated: 2022/06/26 16:56:48 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int			res;
	long long	num;

	num = 0;
	res = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		res = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (num > 9223372036854775807u && res == 1)
		return (-1);
	else if (num > 9223372036854775808u && res == -1)
		return (0);
	return (num * res);
}

long long	get_timestamp(void)
{
	struct timeval	t;
	long long		now;

	gettimeofday (&t, NULL);
	now = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (now);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_timestamp();
	while (get_timestamp() - start < time)
		usleep(100);
}

int	ft_free(t_table *all)
{
	if (all->philo)
		free(all->philo);
	if (all->fork)
		free(all->fork);
	if (all->thread)
		free(all->thread);
	free(all);
	return (1);
}

void	ft_destroy_mutex(t_table *all)
{
	int	i;

	i = -1;
	while (++i < all->count_philo)
		if (pthread_mutex_destroy(&all->fork[i]))
			printf("Error destroy mutex %d.\n", i);
	pthread_mutex_destroy(&all->print);
}
