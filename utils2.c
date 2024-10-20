/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:55:49 by asmae             #+#    #+#             */
/*   Updated: 2024/10/20 15:04:24 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_tst(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->mutex_last_eat);
	philo->last_eat = ft_time();
	pthread_mutex_unlock(&philo->arg->mutex_last_eat);
	ft_sleep(philo->arg->t_eat);
	ft_count(philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	ft_fun(t_philo	*philo)
{
	pthread_mutex_lock(&philo->arg->mutex_last_eat);
	if (philo->arg->died)
	{
		pthread_mutex_unlock(&philo->arg->mutex_last_eat);
		return (0);
	}
	pthread_mutex_unlock(&philo->arg->mutex_last_eat);
	if (philo->id % 2 != 0)
		usleep(20000);
	return (1);
}

void	ft_check_n(t_tab *arr, t_args *arg, int *i, int *n)
{
	pthread_mutex_lock(&arg->mutex_nb_eat);
	if (arg->n_eat != -1 && arr->philos[*i].nb_eat >= arg->n_eat)
	{
		pthread_mutex_lock(&arg->mutex1);
		arr->philos[*i].check = 1;
		pthread_mutex_unlock(&arg->mutex1);
		(*n) += 1;
	}
	pthread_mutex_unlock(&arg->mutex_nb_eat);
	(*i) += 1;
}

int	ft_check_mu(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->mutex_nb_eat);
	if (philo->check)
	{
		pthread_mutex_unlock(&philo->arg->mutex_nb_eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->arg->mutex_nb_eat);
	return (0);
}
