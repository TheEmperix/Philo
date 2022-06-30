/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:11:01 by woberon           #+#    #+#             */
/*   Updated: 2022/06/25 16:11:02 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	print_error(int code)
{
	printf("Error: ");
	if (code == 1)
		printf("wrong number of arguments.\n");
	else if (code == 2)
		printf("arguments are not correct.\n");
	else if (code == 3)
		printf("malloc allocation error.\n");
	else if (code == 4)
		printf("semafor creation error.\n");
	else if (code == 5)
		printf("fork error.\n");
	else if (code == 6)
		printf("failed to create the thread.\n");
	else if (code == 7)
		printf("failed to join the thread.\n");
	return (1);
}

void	ft_free(t_philo *all)
{
	sem_unlink("print");
	sem_unlink("fork");
	sem_close(all->sem_print);
	sem_close(all->sem_fork);
	free(all->pid);
	free(all);
}
