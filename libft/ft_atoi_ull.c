/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 03:06:50 by bhankey           #+#    #+#             */
/*   Updated: 2020/10/30 03:13:56 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				checkstr(const char *str)
{
	int i;

	i = 0;
	if (*str == '+')
	{
		str++;
		i++;
	}
	while (*str != '\0')
	{
		if (*str > '9' || *str < '0')
			return (-1);
		i++;
		str++;
	}
	return (i);
}

static void				skipwhitespace(const char **str)
{
	while (**str == ' ' || **str == '\n' || **str == '\t' || **str == '\v'
		|| **str == '\f' || **str == '\r')
		(*str)++;
}

unsigned long long int	ft_atoi_ull(const char *nptr)
{
	int						size;
	unsigned long long int	result;
	unsigned long long int	am;

	result = 0;
	am = 1;
	skipwhitespace(&nptr);
	if ((size = checkstr(nptr)) > 20)
		return (0);
	if (size == -1)
		return (0);
	while (--size >= 0)
	{
		if (nptr[size] != '+')
			result += (nptr[size] - '0') * am;
		am *= 10;
	}
	return (result);
}
