/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:04:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/17 16:23:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/// Check the arguments of our program for errors.
/// Returns 1 and displays the corresponding error message if an error is found
/// Returns 0 otherwise.
static int	ft_main_args_error(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 6 || argc < 5)
		return (ft_puterr("Wrong number of arguments"));
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_strchr(BASE_TEN, argv[i][j]))
				return (ft_puterr("Found non numerical input"));
		}
		if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > INT_MAX)
			return (ft_puterr("Outside integers in range [1 ; 2147483647]"));
	}
	return (0);
}

/// Create a new t_main_args structure using malloc and set up its values.
/// Returns NULL pointer if the malloc call fails
static t_main_args	*ft_initialize_main_args_struct(int argc, char **argv)
{
	t_main_args	*ret;

	ret = malloc(sizeof(t_main_args));
	if (!ret)
		return (NULL);
	ret->n_philos = (int)(ft_atol(argv[1]));
	ret->t_to_die = (int)(ft_atol(argv[2]));
	ret->t_to_eat = (int)(ft_atol(argv[3]));
	ret->t_to_sleep  = (int)(ft_atol(argv[4]));
	if (argc == 6)
		ret->n_to_eat = (int)(ft_atol(argv[5]));
}

/*
** 1 - number of philosophers
** 2 - time to die
** 3 - time to eat
** 4 - time to sleep
** (optionnal) 5 - number of times they need to eat
*/

int	main(int argc, char **argv)
{
	//pthread_t	thread;
	t_main_args	*main_args;

	if (ft_main_args_error(argc, argv))
		return (-1);
	main_args = ft_initialize_main_args_struct(argc, argv);
	if (!main_args)
		return (ft_puterr("Call to malloc function returned a NULL pointer"));
	return (0);
}
