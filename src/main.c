/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/19 11:31:56 by agautier         ###   ########.fr       */
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
		return (print_error(ERR_MALLOC));
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
	uint8_t			i;

	i = 1;
	while (i <= philos->rules->nb_philo)
	{
		if (i > 1)
		{
			philos[i - 2].lfork = &philos[i - 1].rfork;
			fprintf(stderr, "l for %u\t%p\n", philos[i - 2].index, &philos[i - 1].rfork);
		}
		if (pthread_mutex_init(&philos[i - 1].rfork, NULL) != 0)
			return (print_error(ERR_INIT));
		fprintf(stderr, "r for %u\t%p\n", philos[i - 1].index, &philos[i - 1].rfork);
		i += 1;
	}
	philos[i - 2].lfork = &philos[0].rfork;
	fprintf(stderr, "l for %u\t%p\n", philos[i - 2].index, &philos[0].rfork);
	return (TRUE);
}

/*
**
*/
int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;
	uint8_t i;

	rules = (t_rules){0, 0, 0, 0, 0, 0, {0}};
	if (!parse(argc, argv, &rules))
		return (EXIT_FAILURE);
	
	if (!init_philos(&rules, &philos))
		return (EXIT_FAILURE);
	i = 0;
	while (i < rules.nb_philo)
	{
		fprintf(stderr, "phil index = %u\n", philos[i].index);
		i += 1;
	}

	if (!init_forks(philos))
		return (EXIT_FAILURE);

//	if (pthread_create(&philo.thread, NULL, &routine, &philo) != 0)
//		return (EXIT_FAILURE + print_error(ERR_THREAD));
//	if (pthread_create(&philo2.thread, NULL, &routine, &philo2) != 0)
//		return (EXIT_FAILURE + print_error(ERR_THREAD));

	rules.start_time = get_timestamp();
	fprintf(stderr, "start_time = %llu\n", rules.start_time);
	while (TRUE)
	{
		fprintf(stderr, "time = %llu\n", get_timestamp() - rules.start_time);
		usleep(100000);
	}

//	if (pthread_join(philo.thread, NULL) != 0)
//		return (EXIT_FAILURE + print_error(ERR_JOIN));
//	if (pthread_join(philo2.thread, NULL) != 0)
//		return (EXIT_FAILURE + print_error(ERR_JOIN));

	free(philos);
	philos = NULL;

	return (EXIT_SUCCESS);
}
