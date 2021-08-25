/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:04:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/25 11:43:01 by ysoroko          ###   ########.fr       */
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
	ret->n_to_eat = 0;
	if (argc == 6)
		ret->n_to_eat = (int)(ft_atol(argv[5]));
	return (ret);
}

/// Initialize an array of threads of n_philos elements with malloc
/// Creates a thread for every philosopher and joins the threads
/// Returns a NULL pointer in case of an error
static pthread_t	*ft_initialize_threads(t_main_args *main_args)
{
	pthread_t		*ret;
	t_philo			*philo;
	t_philo			*prev;
	t_philo			*first;
	pthread_mutex_t	*displaying;

	int			i;

	if (!ft_malloc(sizeof(*ret) * main_args->n_philos, (void **)&ret))
		return (ft_puterr_ptr("Failed to malloc the philosophers"));
	i = -1;
	prev = NULL;
	if (!ft_malloc(sizeof(pthread_mutex_t), (void **)&displaying))
		return (ft_free(ret, "Failed malloc a mutex for display", NULL));
	if (pthread_mutex_init(displaying, NULL))
		return (ft_free(displaying, "Failed to init a display mutex", NULL));
	while (++i < main_args->n_philos)
	{
		philo = ft_initialize_philo(main_args, i + 1, &first);
		if (!philo)
			return (ft_free(ret, "Failed to initialize a t_philo", NULL));
		if (ft_initialize_forks(philo, main_args->n_philos, prev, first))
			return (NULL);
		philo->displaying = displaying;
		if (pthread_create(&(ret[i]), NULL, &ft_thread_function, philo))
			return (ft_free(ret, "Failed to create a thread", NULL));
		prev = philo;
	}
	i = -1;
	while (++i < main_args->n_philos)
		if (pthread_join(ret[i], NULL))
			return (ft_free(ret, "Failed to join a thread", NULL));
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
	free(philosophers);
	return (0);
}
