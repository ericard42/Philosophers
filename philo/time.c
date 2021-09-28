/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:11:59 by ericard           #+#    #+#             */
/*   Updated: 2021/09/28 16:17:26 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	g_time(void)
{
	struct timeval time;
	unsigned int	mil_seconds;

	mil_seconds = 0;
	gettimeofday(&time, NULL);
	mil_seconds = time.tv_usec * 0.001 + time.tv_sec * 1000;
	return (mil_seconds);
}	

void	p_wait(unsigned int time)
{
	unsigned int	end_time;
	
	end_time = g_time() + time;
	while (g_time() < end_time)
		usleep(1000);
}