/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:22:12 by asmae             #+#    #+#             */
/*   Updated: 2024/10/20 15:08:43 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_log(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->arg->print_mutex);
	if (!philo->arg->died)
		printf("%ld %d %s\n", (ft_time() - philo->start_time), philo->id, str);
	else
	{
		pthread_mutex_unlock(&philo->arg->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->arg->print_mutex);
	return (0);
}

void	*ft_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (!ft_fun(philo))
		return (NULL);
	while (1)
	{
		if (ft_check_mu(philo))
			return (NULL);
		pthread_mutex_lock(philo->r_fork);
		if (ft_print_log(philo, "has taken a fork"))
			return (NULL);
		pthread_mutex_lock(philo->l_fork);
		if (ft_print_log(philo, "has taken a fork"))
			return (NULL);
		if (ft_print_log(philo, "is eating"))
			return (NULL);
		ft_tst(philo);
		if (ft_print_log(philo, "is sleeping"))
			return (NULL);
		ft_sleep(philo->arg->t_sleep);
		if (ft_print_log(philo, "is thinking"))
			return (NULL);
	}
	return (NULL);
}

int	ft_died(t_tab *arr, t_args *arg)
{
	int	i;
	int	n;

	while (1)
	{
		i = 0;
		n = 0;
		while (i < arg->nb_philos)
		{
			pthread_mutex_lock(&arg->mutex_last_eat);
			if ((ft_time() - arr->philos[i].last_eat) > arg->t_die)
			{
				pthread_mutex_unlock(&arg->mutex_last_eat);
				ft_print_die(&arr->philos[i], "died");
				return (1);
			}
			pthread_mutex_unlock(&arg->mutex_last_eat);
			ft_check_n(arr, arg, &i, &n);
		}
		if (n == arg->nb_philos)
			return (1);
	}
	return (0);
}

void	ft_join(t_tab *arr, t_args *arg)
{
	int	i;

	i = 0;
	while (i < arg->nb_philos)
	{
		if (arg->nb_philos == 1)
			break ;
		pthread_join(arr->thread[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_tab	arr;
	t_args	arg;

	if (ft_check_args(ac, av, &arg) || arg.nb_philos < 1)
	{
		printf("errorrr\nYou should enter the right value");
		return (1);
	}
	ft_init_mutex(&arr, &arg);
	ft_create(&arr, &arg);
	if (ft_died(&arr, &arg))
	{
		arg.died = 1;
		ft_join(&arr, &arg);
		ft_free(&arr, &arg);
		return (0);
	}
	ft_join(&arr, &arg);
	ft_free(&arr, &arg);
	return (0);
}
