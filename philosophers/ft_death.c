/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:40:54 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/02 12:13:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// This is a thread function which will check the current time for every
/// philosopher and check if the philosopher has died
///
static void	*ft_check_time_and_death(void *arg)
{
	t_death_struct	*death_struct;
	t_philo			**philos;
	int				n_philos;
	useconds_t		current_time;
	useconds_t		time_without_eating;
	int				i;

	death_struct = (t_death_struct *)arg;
	philos = death_struct->philos;
	n_philos = death_struct->n_philos;
	while (1)
	{
		i = -1;
		while (++i < n_philos)
		{
			if (ft_get_current_time(philos[i]))
				return (NULL);
			current_time = philos[i]->current_time;
			time_without_eating = current_time - philos[i]->time_last_time_ate;
			if ((int)time_without_eating >= philos[i]->t_to_die)
			{
				ft_print_status(philos[i], DIED);
				return (NULL);
			}
		}
	}
	return (death_struct);
}

int	ft_initialize_death_check_thread(t_philo **philos, int n_ph, int t_to_die)
{
	pthread_t		d_thread;
	t_death_struct	*d_struct;

	d_struct = malloc(sizeof(t_death_struct));
	if (!d_struct)
		return (ft_puterr("Failed to malloc a t_death_struct"));
	d_struct->n_philos = n_ph;
	d_struct->philos = philos;
	d_struct->t_to_die = t_to_die;
	if (pthread_create(&d_thread, NULL, &ft_check_time_and_death, d_struct))
		return (ft_free_int_ret(d_struct, "Faild to create death thread", -1));
	if (pthread_join(d_thread, NULL))
		return (ft_free_int_ret(d_struct, "Failed to join death thread", -1));
	return (0);
}
