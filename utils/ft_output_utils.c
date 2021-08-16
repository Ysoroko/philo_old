/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:24:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/16 14:00:37 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

int	ft_puterr(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	ft_putstr_fd(BOLDRED, STDERR);
	ft_putendl_fd("Error:\t", STDERR);
	while (str[++i])
	{
		ft_putchar_fd(str[i], STDERR);
	}
	ft_putchar_fd('\n', STDERR);
	ft_putstr_fd(COLOR_RESET, STDERR);
	return (1);
}
