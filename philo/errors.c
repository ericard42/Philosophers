/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:21:34 by ericard           #+#    #+#             */
/*   Updated: 2021/11/02 13:56:14 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(int error, t_frame *frame)
{
	if (error == ARGUMENT)
	{
		ft_putstr_fd("Error : Wrong arguments\n", 2);
		free(frame);
		return (ARGUMENT);
	}
	if (error == MALLOC)
		ft_putstr_fd("Error : Malloc crashed\n", 2);
	if (error == PTHREAD)
		ft_putstr_fd("Error : Pthread crashed\n", 2);
	ft_close(frame);
	return (error);
}
