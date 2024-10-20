/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:56:31 by asmae             #+#    #+#             */
/*   Updated: 2024/10/20 15:03:38 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->mutex_nb_eat);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->arg->mutex_nb_eat);
}

void	ft_print_die(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->arg->print_mutex);
	if (!philo->arg->died)
	{
		printf("%ld %d %s\n", (ft_time() - philo->start_time), philo->id, str);
	}
	pthread_mutex_unlock(&philo->arg->print_mutex);
}

long	ft_time(void)
{
	struct timeval	time;
	long			x;

	gettimeofday(&time, NULL);
	x = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (x);
}

int	ft_check_args(int ac, char **av, t_args *arg)
{
	(void)arg;
	if (ac >= 5 && ac <= 6)
	{
		if (ft_atoi(av[1]) == -1 || ft_atoi(av[2]) == -1
			|| ft_atoi(av[3]) == -1 || ft_atoi(av[4]) == -1)
			return (1);
		else
		{
			arg->nb_philos = ft_atoi(av[1]);
			arg->t_die = ft_atoi(av[2]);
			arg->t_eat = ft_atoi(av[3]);
			arg->t_sleep = ft_atoi(av[4]);
			if (ac == 6)
			{
				if (ft_atoi(av[5]) != -1)
					arg->n_eat = ft_atoi(av[5]);
				else
					return (1);
			}
			else
				arg->n_eat = -1;
			return (0);
		}
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)) && *str != '\0')
		str++;
	if (*str == '+')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (result);
}
