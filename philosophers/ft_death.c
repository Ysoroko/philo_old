/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:40:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/03 14:26:51 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	ft_check_philo_death_and_n_ate(t_philo **philos, int n_philos)
{
	int				i;
	int				j;
	useconds_t		current_time;
	useconds_t		time_without_eating;

	i = -1;
	while (++i < n_philos && (!(*philos[i]->died)))
	{	
		if (ft_get_current_time(philos[i]))
			return (1);
		current_time = (philos[i])->current_time - (philos[i])->start_time;
		time_without_eating = current_time - (philos[i])->time_last_time_ate;
		if ((int)time_without_eating >= philos[i]->t_to_die)
		{
			*(philos[i]->died) = 1;
			ft_print_status(philos[i], DIED);
			return (1);
		}
		j = -1;
		while (++j < n_philos)
		{
			if ((philos[j]->n_to_eat) && (philos[j]->n_times_ate) < (philos[j]->n_to_eat))
				break ;
			if ((philos[j]->n_to_eat) && j == n_philos - 1 && (philos[j]->n_times_ate) >= (philos[j]->n_to_eat))
				return (1);
		}
	}
	return (0);
}

/// This is a thread function which will check the current time for every
/// philosopher and check if the philosopher has died
///
static void	*ft_check_time_and_death(void *arg)
{
	t_death_struct	*death_struct;
	t_philo			**philos;
	int				n_philos;

	death_struct = (t_death_struct *)arg;
	philos = death_struct->philos;
	n_philos = death_struct->n_philos;
	while (1)
	{
		ft_msleep(1);
		if (ft_check_philo_death_and_n_ate(philos, n_philos))
			return (arg);
	}
	return (arg);
}

pthread_t	*ft_initialize_death_check_thread(t_philo **p, int n_ph, int t_die)
{
	pthread_t		*d_thread;
	t_death_struct	*d_struct;

	d_struct = malloc(sizeof(t_death_struct));
	if (!d_struct)
		return ((pthread_t *)ft_puterr_ptr("Failed to malloc t_death_struct"));
	d_thread = malloc(sizeof(pthread_t));
	if (!d_thread)
		return (ft_free(d_struct, "Failed to malloc death_thread", NULL));
	d_struct->n_philos = n_ph;
	d_struct->philos = p;
	d_struct->t_to_die = t_die;
	if (pthread_create(d_thread, NULL, &ft_check_time_and_death, d_struct))
		return ((pthread_t *)ft_free(d_struct, "D Thread not created", NULL));
	return (d_thread);
}
