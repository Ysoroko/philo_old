/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:03:02 by ysoroko           #+#    #+#             */
/*   Updated: 2021/09/02 12:12:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Prints the message status as required per subject
/// Ex: "2000 1 is sleeping"
/// Returns 0 in case of success, -1 in case of error
int	ft_print_status(t_philo *philo, int state)
{
	if (pthread_mutex_lock(philo->displaying))
		return (ft_puterr("Failed to lock display mutex"));
	if (ft_get_current_time(philo) == -1)
	{
		pthread_mutex_unlock(philo->displaying);
		return (ft_puterr("Failed to get current time"));
	}
	ft_putnbr_fd(philo->current_time - philo->start_time, STDOUT);
	ft_putchar_fd('\t', STDOUT);
	ft_putnbr_fd(philo->philo_number, STDOUT);
	ft_putchar_fd('\t', STDOUT);
	if (state == EATING)
		ft_putendl_fd("is eating", STDOUT);
	else if (state == FORK)
		ft_putendl_fd("has taken a fork", STDOUT);
	else if (state == SLEEPING)
		ft_putendl_fd("is sleeping", STDOUT);
	else if (state == THINKING)
		ft_putendl_fd("is thinking", STDOUT);
	else if (state == DIED)
		ft_putendl_fd("died", STDOUT);
	if (pthread_mutex_unlock(philo->displaying))
		return (ft_puterr("Failed to unlock display mutex"));
	return (0);
}

/// The special eating state in a case where there's only one philosopher
/// He will have one fork only (because one fork per philosopher)
/// He will grab the fork, wait for the second one, but since there is none
/// He will eventually die
static int	ft_eat_alone(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork))
		return (ft_puterr("Failed to lock left fork"));
	if (ft_print_status(philo, FORK))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	if (ft_msleep(philo->t_to_die + 10))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	if (pthread_mutex_unlock(philo->left_fork))
		return (ft_puterr("Failed to unlock left fork"));
	return (0);
}

/// Philosopher's "eating" state
/// The philosopher will take his 2 forks if available and start eating
/// Displays a message for each fork taken and when he starts to eat
/// Pauses the thread for t_to_eat milliseconds.
/// At the end updates the last time when the philosopher ate
/// Returns 0 in case of success, -1 in case of error
int	ft_eat(t_philo *philo)
{
	int	time_to_eat;

	if (!philo->right_fork)
		return (ft_eat_alone(philo));
	if (pthread_mutex_lock(philo->left_fork))
		return (ft_puterr("Failed to lock left fork"));
	if (pthread_mutex_lock(philo->right_fork))
		return (ft_puterr("Failed to lock right fork"));
	if (ft_print_status(philo, FORK) || ft_print_status(philo, FORK))
		return (-1);
	time_to_eat = philo->t_to_eat;
	if (ft_get_current_time(philo) == -1)
		return (ft_puterr("Failed to get current time"));
	if (ft_print_status(philo, EATING))
		return (-1);
	if (ft_msleep(philo->t_to_eat) == -1)
		return (ft_puterr("Failed to call usleep function"));
	if (pthread_mutex_unlock(philo->left_fork))
		return (ft_puterr("Failed to unlock left fork"));
	if (pthread_mutex_unlock(philo->right_fork))
		return (ft_puterr("Failed to unlock right fork"));
	if (ft_update_last_time_ate(philo))
		return (ft_puterr("Couldn't update last time the philosopher ate"));
	philo->n_times_ate++;
	return (0);
}

/// Philosopher's "sleeping" status he enters after he finished eating
/// Since the sleeping status is right after eating, we check in philosopher
/// ate enough times. If so, we quit.
/// Displays a message that the philosopher has started to sleep
/// Waits for t_to_sleep milliseconds
/// Returns 0 in case of success, -1 in case of error
int	ft_sleep(t_philo *philo)
{
	if (philo->n_to_eat && philo->n_times_ate >= philo->n_to_eat)
		return (1);
	if (ft_print_status(philo, SLEEPING) || ft_msleep(philo->t_to_sleep))
		return (-1);
	return (0);
}

/// Philosopher's "thinking" status he enters after he finished sleeping
/// Displays a message that the philosopher has started to think
/// Returns 0 in case of success, -1 in case of error
int	ft_think(t_philo *philo)
{
	if (ft_print_status(philo, THINKING))
		return (-1);
	return (0);
}
