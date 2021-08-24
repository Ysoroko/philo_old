/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:12:48 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/24 11:25:32 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Working in milliseconds!
/// 1ms = 1000us (microseconds, usleep +)
int	ft_setup_start_time(t_philo *philo)
{
	struct timeval	time_value;
	suseconds_t		in_milliseconds;

	if (gettimeofday(&time_value, NULL) == -1)
		return (-1);
	in_milliseconds = time_value.tv_usec / 1000 + time_value.tv_sec * 1000;
	philo->start_time = in_milliseconds;
	return (0);
}

/// Stores the current time (in microseconds) in philo->current_time
/// Returns 0 in case of success or -1 if a call to gettimeofday function fails
int	ft_get_current_time(t_philo *philo)
{
	struct timeval	time_value;
	suseconds_t		in_milliseconds;
	suseconds_t		start_time;

	if (gettimeofday(&time_value, NULL) == -1)
		return (-1);
	start_time = philo->start_time;
	in_milliseconds = time_value.tv_usec / 1000 + time_value.tv_sec * 1000;
	philo->current_time = in_milliseconds;
	return (0);
}

/// A replacement of usleep function which works with microseconds.
/// Pauses the execution of the calling thread for n_milliseconds milliseconds.
/// Returns -1 in case of error or 0 in case of success.
int	ft_msleep(int n_milliseconds)
{
	useconds_t	in_microseconds;

	in_microseconds = (useconds_t)n_milliseconds * 1000;
	return (usleep(in_microseconds));
}
