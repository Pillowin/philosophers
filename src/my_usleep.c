/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:37:58 by agautier          #+#    #+#             */
/*   Updated: 2021/10/27 19:02:20 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Custom implementation of usleep.
*/
void	my_usleep(t_rules *rules, useconds_t us)
{
	uint64_t	now;

	now = get_timestamp();
	while (get_running(rules) && get_timestamp() < now + us / 1000)
		usleep(10);
}
