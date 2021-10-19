/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:41:32 by agautier          #+#    #+#             */
/*   Updated: 2021/10/18 14:42:39 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**
*/
void	philo_think(t_philo *philo)
{
	printf("%llu\t%u is thinking\n",
		get_timestamp() - philo->rules->start_time, philo->index);
}
