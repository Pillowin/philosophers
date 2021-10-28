/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/28 02:39:23 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Init philos.
*/
static t_bool	init_philos(t_rules *rules, t_philo **philos)
{
	t_philo	philo;
	uint8_t	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * rules->nb_philo);
	if (!*philos)
		return (print_error(rules, ERR_MALLOC));
	i = 1;
	while (i <= rules->nb_philo)
	{
		philo.rules = rules;
		philo.index = i;
		(*philos)[i - 1] = philo;
		i += 1;
	}
	return (TRUE);
}

/*
**	Init forks.
*/
static t_bool	init_forks(t_philo *philos)
{
	uint8_t	i;

	i = 1;
	while (i <= philos->rules->nb_philo)
	{
		if (i > 1)
			philos[i - 2].lfork = &philos[i - 1].rfork;
		if (pthread_mutex_init(&philos[i - 1].rfork, NULL) != 0)
			return (print_error(philos->rules, ERR_INIT));
		if (pthread_mutex_init(&philos[i - 1].mut, NULL) != 0)
			return (print_error(philos->rules, ERR_INIT));
		i += 1;
	}
	philos[i - 2].lfork = &philos[0].rfork;
	return (TRUE);
}

/*
**	TODO: mutex destroy
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
		return (EXIT_FAILURE);
	if (!init_forks(philos))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&rules.print, NULL) != 0)
		return (print_error(philos->rules, ERR_INIT));
	if (pthread_mutex_init(&rules.mut, NULL) != 0)
		return (print_error(philos->rules, ERR_INIT));

	i = 0;
	while (i < rules.nb_philo)
	{
		if (pthread_create(&((philos[i]).thread), NULL, &routine,
				&(philos[i])) != 0)
			return (EXIT_FAILURE + print_error(philos->rules, ERR_CREATE));	// TODO: free and destroy 
		i += 1;
	}

	while (get_running(&rules) && watcher(philos) == TRUE)
		usleep(100);

	i = 0;
	while (i < rules.nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (EXIT_FAILURE + print_error(philos->rules, ERR_JOIN));
		i += 1;
	}
	i = 0;
	while (i < rules.nb_philo)
	{
		if (pthread_mutex_destroy(&(philos[i].rfork)) != 0)
			return (EXIT_FAILURE + print_error(philos->rules, ERR_DESTROY));
		if (pthread_mutex_destroy(&(philos[i].mut)) != 0)
			return (EXIT_FAILURE + print_error(philos->rules, ERR_DESTROY));
		i += 1;
	}
	if (pthread_mutex_destroy(&rules.print) != 0)
		return (EXIT_FAILURE + print_error(philos->rules, ERR_DESTROY));
	if (pthread_mutex_destroy(&rules.mut) != 0)
		return (EXIT_FAILURE + print_error(philos->rules, ERR_DESTROY));

	free(philos);
	philos = NULL;

	return (EXIT_SUCCESS);
}
