/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:23:57 by asmae             #+#    #+#             */
/*   Updated: 2024/10/20 15:00:19 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				died;
	int				check_nb_eat;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_nb_eat;
	pthread_mutex_t	mutex1;
}	t_args;

typedef struct s_philo
{
	int		id;
	long	last_eat;
	long	start_time;
	int		nb_eat;
	void	*r_fork;
	void	*l_fork;
	int		check;
	t_args	*arg;
}	t_philo;

typedef struct s_tab
{
	t_philo			*philos;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
}	t_tab;

int		ft_atoi(char *str);
void	ft_print_die(t_philo *philo, char *str);
long	ft_time(void);
int		ft_check_args(int ac, char **av, t_args *arg);
void	ft_create(t_tab *arr, t_args *arg);
void	ft_count(t_philo *philo);
void	ft_init_mutex(t_tab *arr, t_args *arg);
void	ft_destroy(t_tab *arr, t_args *arg);
void	ft_free(t_tab *arr, t_args *arg);
int		ft_print_log(t_philo *philo, char *str);
void	*ft_routine(void *p);
int		ft_died(t_tab *arr, t_args *arg);
void	ft_join(t_tab *arr, t_args *arg);
void	ft_sleep(int time);
void	ft_check_n(t_tab *arr, t_args *arg, int *i, int *n);
void	ft_tst(t_philo *philo);
int		ft_fun(t_philo	*philo);
int		ft_check_mu(t_philo *philo);

#endif