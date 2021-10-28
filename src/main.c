/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/28 16:10:20 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Start dinning philosophers problem simulation.
*/
int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;
	uint8_t	i;

	rules = (t_rules){0, 0, 0, 0, 0, 0, {0}, {0}, TRUE};
	if (!parse(argc, argv, &rules))
		return (EXIT_FAILURE);
	if (!init_philos(&rules, &philos))
		return (destroy(philos, PHILOS));
	if (!init_forks(philos))
		return (destroy(philos, FORKS));
	if (!init_mutex(philos))
		return (destroy(philos, MUTEXES));
	i = 0;
	while (i < rules.nb_philo)
	{
		if (pthread_create(&((philos[i]).thread), NULL, &routine,
				&(philos[i])) != 0)
			return (print_error(philos->rules, ERR_CREATE)
				+ destroy(philos, ALL));
		i += 1;
	}
	while (get_running(&rules) && watcher(philos))
		usleep(100);
	return (!destroy(philos, ALL));
}
