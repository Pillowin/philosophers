/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 07:43:32 by agautier          #+#    #+#             */
/*   Updated: 2021/10/24 02:26:05 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Secure printing of infos with mutex.
*/
t_bool	print(t_rules *rules, uint8_t index, char *action)
{
	if (pthread_mutex_lock(&rules->mut) != 0)
		return (print_error(rules, ERR_LOCK));
	if (rules->running == FALSE)
		return (TRUE);
	if (pthread_mutex_unlock(&rules->mut) != 0)
		return (print_error(rules, ERR_UNLOCK));
	if (pthread_mutex_lock(&rules->print) != 0)
		return (print_error(rules, ERR_LOCK));
	printf("%llu\t%u %s\n", get_timestamp(), index, action);
	if (pthread_mutex_unlock(&rules->print) != 0)
		return (print_error(rules, ERR_UNLOCK));
	return (TRUE);
}
