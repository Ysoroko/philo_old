/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:03:02 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/24 14:58:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Prints the message status as required per subject
/// Ex: "2000 1 is sleeping"
static	int	ft_print_status(t_philo *philo, int state)
{
	if (pthread_mutex_lock(philo->displaying))
		return (ft_puterr("Failed to lock display mutex"));
	if (ft_get_current_time(philo) == -1)
		return (ft_puterr("Failed to get current time"));
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

int	ft_eat(t_philo *philo)
{
	int	time_to_eat;

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
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, SLEEPING);
	ft_msleep(philo->t_to_sleep);
	return (0);
}

int	ft_think(t_philo *philo)
{
	ft_print_status(philo, THINKING);
	return (0);
}
