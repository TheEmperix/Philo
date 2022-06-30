/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:10:50 by woberon           #+#    #+#             */
/*   Updated: 2022/06/25 16:10:53 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

typedef struct s_philo
{
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_lunch;
	int			name;
	int			nbr_philo_eat;
	int			flag_of_death;
	long long	time_start;
	long long	time_last_eat;
	pid_t		*pid;
	pthread_t	track_death;
	sem_t		*sem_print;
	sem_t		*sem_fork;
}				t_philo;

int			check_arg(int ac, char **av);
t_philo		*init_philo(int ac, char **av);
int			small_free(t_philo *all, int code);
int			init_sem_pid(t_philo *all);
long long	ft_atoi(const char *str);
long long	get_timestamp(void);
void		ft_usleep(long long time);
int			print_error(int code);
void		ft_free(t_philo *all);
void		philo_print(t_philo *all, char *str);
int			philo_eat_sleep_think(t_philo *all);
int			killer(t_philo *all);
#endif
