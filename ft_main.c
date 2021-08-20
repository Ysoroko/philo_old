/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:04:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 11:09:31 by ysoroko          ###   ########.fr       */
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
/// Returns a NULL pointer if the malloc call fails
static t_main_args	*ft_initialize_main_args_struct(int argc, char **argv)
{
	t_main_args	*ret;

	ret = malloc(sizeof(t_main_args));
	if (!ret)
		return (ft_puterr_ptr("Couldn't malloc a t_main_args"));
	ret->n_philos = (int)(ft_atol(argv[1]));
	ret->t_to_die = (int)(ft_atol(argv[2]));
	ret->t_to_eat = (int)(ft_atol(argv[3]));
	ret->t_to_sleep = (int)(ft_atol(argv[4]));
	if (argc == 6)
		ret->n_to_eat = (int)(ft_atol(argv[5]));
	return (ret);
}

/// Initialize an array of threads of n_philos elements with malloc
/// Creates a thread for every philosopher and joins the threads
/// Returns a NULL pointer in case of an error
static pthread_t	*ft_initialize_threads(t_main_args *main_args)
{
	pthread_t	*ret;
	t_philo		*philo;
	int			i;

	ret = malloc(sizeof(*ret) * main_args->n_philos);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < main_args->n_philos)
	{
		philo = ft_initialize_philo(main_args, i + 1);
		if (!philo)
			return (ft_puterr_ptr("Failed to initialize a t_philo"));
		if (pthread_create(&(ret[i]), NULL, &ft_thread_function, philo))
			return (ft_puterr_ptr("Failed to create a thread"));
	}
	while (--i > 0)
	{
		if (pthread_join(ret[i], NULL))
			return (ft_puterr_ptr("Failed to join a thread"));
	}
	return (ret);
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
	t_main_args	*main_args;
	pthread_t	*philosophers;

	if (ft_main_args_error(argc, argv))
		return (-1);
	main_args = ft_initialize_main_args_struct(argc, argv);
	if (!main_args)
		return (-1);
	philosophers = ft_initialize_threads(main_args);
	if (!philosophers)
		return (-1);
	return (0);
}
