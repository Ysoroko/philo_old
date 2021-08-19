/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:24:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/18 15:39:26 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Displays the char argument.
/// Uses the specified file descriptor for output.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/// Displays the string argument.
/// Uses the specified file descriptor for output.
void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		ft_putchar_fd(str[i], fd);
	}
}

/// Displays the string argument followed by a newline character.
/// Uses the specified file descriptor for output.
void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		ft_putchar_fd(str[i], fd);
	}
	ft_putchar_fd('\n', fd);
}

/// Displays the integer n argument on the specified file descriptor
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	m = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		m *= -1;
	}
	if (m >= 10)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putnbr_fd(m % 10, fd);
	}
	else
	{
		ft_putchar_fd('0' + m, fd);
	}
}

/// Displays "Error" followed by its argument on STDERR (in red color)
/// Returns -1 if str argument is a NULL pointer or 1 otherwise
int	ft_puterr(char *str)
{
	if (!str)
		return (-1);
	ft_putstr_fd(BOLDRED, STDERR);
	ft_putendl_fd("Error:\t", STDERR);
	ft_putendl_fd(str, STDERR);
	ft_putstr_fd(COLOR_RESET, STDERR);
	return (1);
}
