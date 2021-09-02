/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:32:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/02 15:18:54 by ysoroko          ###   ########.fr       */
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
	while (1)
	{
		if (*(philo->died) || ft_eat(philo))
			return (-1);
		if (*(philo->died) || ft_sleep(philo))
			return (-1);
		if (*(philo->died) || ft_think(philo))
			return (-1);
	}
	return (0);
}

/// Function called to clean up the memory
/// To clean up:
/// 1) Free the address of left fork
/// 2) Destroy the mutex of the same left fork
///	3) Free the address of the "displaying" mutex
/// 4) Destroy the mutex of "displaying" mutex
/// 5) Free t_philo structure itself
static int	ft_cleanup_threads_and_mutexes(t_philo *philo)
{
	if (pthread_mutex_destroy(philo->left_fork))
	{
		free(philo->left_fork);
		free(philo->displaying);
		free(philo);
		return (-1);
	}
	if (pthread_mutex_destroy(philo->displaying))
	{
		free(philo->left_fork);
		free(philo->displaying);
		free(philo);
		return (-1);
	}
	free(philo->left_fork);
	free(philo->displaying);
	free(philo);
	return (0);
}

/// Function called when creating a new thread
/// Sets up the starting time, enters the philopher's routine (eat-sleep-think)
/// At the end once out of the routine, cleans up the memory and the mutexes.
void	*ft_thread_function(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (ft_setup_start_time(philo) == -1)
		return (NULL);
	ft_philo_routine(philo);
	if (!philo)
		ft_cleanup_threads_and_mutexes(philo);
	return (NULL);
}
