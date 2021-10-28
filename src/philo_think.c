/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:41:32 by agautier          #+#    #+#             */
/*   Updated: 2021/10/28 18:32:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Print thinking message and wait until philo can use his both forks to eat.
*/
t_bool	philo_think(t_philo *philo)
{
	if (!get_running(philo->rules)
		|| !print(philo->rules, philo->index, "is thinking"))
		return (FALSE);
	if (pthread_mutex_lock(philo->lfork) != 0)
		return (print_error(philo->rules, ERR_LOCK));
	if (!print(philo->rules, philo->index, "has taken a fork"))
		return (FALSE);
	if (philo->rules->nb_philo == 1)
		return (FALSE);
	if (pthread_mutex_lock(&philo->rfork) != 0)
		return (print_error(philo->rules, ERR_LOCK));
	if (!print(philo->rules, philo->index, "has taken a fork"))
		return (FALSE);
	return (TRUE);
}
