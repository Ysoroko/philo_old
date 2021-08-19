/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:32:41 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/19 10:06:55 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Function called when creating a new thread
void	*ft_thread_function(void *arg)
{
	printf("Bonjour\n");
	printf("Au revoir\n");
	return (arg);
}
