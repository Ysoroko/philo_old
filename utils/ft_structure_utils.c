/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/17 15:42:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Create a new t_main_args structure using malloc and set all its values to 0
/// Returns NULL pointer if the malloc call fails
t_main_args	*ft_new_main_args(void)
{
	t_main_args	*ret;

	ret = malloc(sizeof(t_main_args));
	if (!ret)
		return (NULL);
	ret->n_philos = 0;
	ret->t_to_die = 0;
	ret->t_to_sleep = 0;
	ret->t_to_eat = 0;
	ret->n_to_eat = 0;
	return (ret);
}
