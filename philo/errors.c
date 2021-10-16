/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:21:34 by ericard           #+#    #+#             */
/*   Updated: 2021/10/16 10:39:26 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(int error, t_frame *frame)
{
	if (error == ARGUMENT)
		printf("Error : Wrong arguments\n");
	if (error == MALLOC)
		printf("Error : Malloc crashed\n");
	if (error == PTHREAD)
		printf("Error : Pthread crashed\n");
	ft_close(frame);
	return (1);
}
