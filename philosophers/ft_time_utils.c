/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:12:48 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 15:15:12 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Working in milliseconds!
/// 1ms = 1000us (microseconds, usleep +)
int	ft_setup_start_time(t_philo *philo)
{
	struct timeval	time_value;
	int				in_milliseconds;

	if (gettimeofday(&time_value, NULL) == -1)
		return (-1);
	in_milliseconds = time_value.tv_usec / 1000;
	philo->start_time = in_milliseconds;
	return (0);
}

/// Stores the current time (in microseconds) in philo->current_time
/// Returns 0 in case of success or -1 if a call to gettimeofday function fails
int	ft_get_current_time(t_philo *philo)
{
	struct timeval	time_value;
	int				in_milliseconds;

	if (gettimeofday(&time_value, NULL) == -1)
		return (-1);
	in_milliseconds = time_value.tv_usec / 1000;
	philo->current_time = in_milliseconds;
	return (0);
}
