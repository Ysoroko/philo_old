/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:32:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/24 12:19:10 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// The routine where each philosopher will eat, sleep and think
/// 1: They eat if both their forks are available
/// 2: They sleep after they finished eating
/// 3: They think after they finished sleeping
/// !!! If at any moment they didn't eat for t_to_die milliseconds, they die
static int	ft_philo_routine(t_philo *philo)
{
	while (philo->n_seconds_without_eating < philo->t_to_die)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}

/// Function called to clean up the memory
/// To clean up:
/// 1) Free the address of left fork
/// 2) Destroy the mutex of the same left fork
///	3) Free the address of the "displaying" mutex
/// 4) Free t_philo structure itself

static int	ft_cleanup_threads_and_mutexes(t_philo *philo)
{
	if (pthread_mutex_destroy(philo->left_fork))
	{
		free(philo);
		free(philo->left_fork);
		return (-1);
	}
	free(philo->left_fork);
	free(philo->displaying);
	free(philo);
	return (0);
}

/// Function called when creating a new thread
void	*ft_thread_function(void *arg)
{
	t_philo	*philo;

	usleep(100);
	philo = (t_philo *)arg;
	if (ft_setup_start_time(philo) == -1)
		return (NULL);
	//ft_print_philo(philo);
	ft_philo_routine(philo);
	if (!arg)
		ft_cleanup_threads_and_mutexes(arg);
	return (arg);
}
