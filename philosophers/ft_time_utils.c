/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:12:48 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 10:21:56 by ysoroko          ###   ########.fr       */
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
	printf("Milliseconds since 1/1/1970: [%d]\n", in_milliseconds);
	return (0);
}
