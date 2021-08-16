/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:43:38 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/16 13:54:16 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

char	*ft_strchr(char *str, int c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		i++;
	}
	if (str[i] == c)
	{
		return (&str[i]);
	}
	return (0);
}

char	*ft_strchrset(char *str, char *charset)
{
	int		i;
	char	*found;

	if (!str || !charset)
		return (0);
	i = -1;
	while (str[++i])
	{
		found = ft_strchr(charset, str[i]);
		if (found)
			return (found);
	}
	return (0);
}

int	ft_isnum(char c)
{
	if (ft_strchr(BASE_TEN, c))
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	ret;
	int		sign;

	i = 0;
	ret = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && ft_isnum(str[i]))
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * sign);
}