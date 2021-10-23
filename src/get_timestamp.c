/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:08:31 by agautier          #+#    #+#             */
/*   Updated: 2021/10/23 23:44:07 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** Return current timestamp.
*/
uint64_t	get_timestamp(void)
{
	struct timeval	tv;
	static uint64_t	start_time = 0;

	gettimeofday(&tv, NULL);
	if (!start_time)
		start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start_time);
}
