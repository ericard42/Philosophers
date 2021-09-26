/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:40:21 by ericard           #+#    #+#             */
/*   Updated: 2021/09/26 15:50:46 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	overflow(long int neg)
{
	if (neg == 1)
		return (-1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	long int	nbr;
	long int	neg;
	size_t		i;

	i = 0;
	neg = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = 10 * nbr + (long int)(str[i] - 48);
		i++;
	}
	if (nbr < 0)
		return (overflow(neg));
	return (nbr * neg);
}
