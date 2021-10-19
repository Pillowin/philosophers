/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 07:43:32 by agautier          #+#    #+#             */
/*   Updated: 2021/10/19 11:20:22 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Secure printing of infos with mutex.
*/
t_bool	print(t_mutex *print, uint64_t timestamp, uint8_t index, char *action)
{
	if (pthread_mutex_lock(print) != 0)
		return(print_error(ERR_LOCK));
	printf("%llu\t%u is %s\n", timestamp, index, action);
	if (pthread_mutex_unlock(print) != 0)
		return(print_error(ERR_LOCK));
	return (TRUE);
}
