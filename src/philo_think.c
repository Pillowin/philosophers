/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:41:32 by agautier          #+#    #+#             */
/*   Updated: 2021/10/19 11:26:41 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**
*/
void	philo_think(t_philo *philo)
{
	print(&philo->rules->print, get_timestamp() - philo->rules->start_time, philo->index, "thinking");
}
