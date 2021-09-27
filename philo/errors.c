/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:21:34 by ericard           #+#    #+#             */
/*   Updated: 2021/08/31 09:45:12 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_error(int error)
{
	if (error == ARGUMENT)
		printf("Error : Wrong arguments\n");
	if (error == MALLOC)
		printf("Error : Malloc crashed\n");
	if (error == PTHREAD)
		printf("Error : Pthread crashed\n");
	return (1);
}