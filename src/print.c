/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 07:43:32 by agautier          #+#    #+#             */
/*   Updated: 2021/10/23 23:42:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Secure printing of infos with mutex.
*/
t_bool	print(t_rules *rules, uint8_t index, char *action)
{
	if (pthread_mutex_lock(&rules->print) != 0)
		return (print_error(ERR_LOCK));
	printf("%llu\t%u %s\n", get_timestamp(), index, action);
	if (pthread_mutex_unlock(&rules->print) != 0)
		return (print_error(ERR_UNLOCK));
	return (TRUE);
}
