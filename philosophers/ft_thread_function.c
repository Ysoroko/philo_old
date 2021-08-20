/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:32:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 10:35:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// typedef struct s_philo
// {
// 	int	philo_number;
// 	int	t_to_die;
// 	int	t_to_sleep;
// 	int	t_to_eat;
// 	int	n_to_eat;
// 	int	start_time;
// 	int	current_time;
// 	int	n_seconds_without_eating;
// 	int	state;
// }	t_philo;

static void	ft_philo_routine(t_philo *philo)
{
	while (philo->n_seconds_without_eating < philo->t_to_die)
	{
		
	}
}

/// Function called when creating a new thread
void	*ft_thread_function(void *arg)
{
	t_philo	*philo;

	usleep(100);
	philo = (t_philo *)arg;
	if (ft_setup_start_time(philo) == -1)
		return (NULL);
	ft_philo_routine(philo);
	free(arg);
	return (arg);
}
