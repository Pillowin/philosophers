/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:54:16 by agautier          #+#    #+#             */
/*   Updated: 2021/10/17 02:22:49 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**	Convert a string into a number.
*/
static uint16_t	my_atoi(char *str)
{
	uint16_t	nbr;
	uint8_t		i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

/*
**	Check if a number is valid and lesser than max.
*/
static t_bool	is_valid_nbr(char *str, uint16_t max)
{
	uint8_t		i;
	uint32_t	nbr;

	i = 0;
	while (str[i])
	{
		if (i > 5 || str[i] < '0' || str[i] > '9')
			return (FALSE);
		i += 1;
	}
	nbr = my_atoi(str);
	if (nbr > max)
		return (FALSE);
	return (TRUE);
}

/*
**	Return FALSE if an arg is not valid.
*/
static t_bool	check_args(int argc, char **argv)
{
	uint8_t	i;

	if (argc < 5 || argc > 6)
		return (print_error(ERR_ARGS_NB));
	i = 1;
	while (i < argc)
	{
		if (((i == 1 || i == 5) && !is_valid_nbr(argv[i], UINT8_MAX))
			|| !is_valid_nbr(argv[i], UINT16_MAX))
			return (print_error(ERR_ARGS_NB + i));
		i += 1;
	}
	return (TRUE);
}

/*
**	Parse args and fill a philo struct.
*/
t_bool	parse(int argc, char **argv, t_rules **rules)
{
	if (!check_args(argc, argv))
		return (FALSE);
	(*rules)->nb_philo = my_atoi(argv[1]);
	(*rules)->time_to_die = my_atoi(argv[2]);
	(*rules)->time_to_eat = my_atoi(argv[3]);
	(*rules)->time_to_sleep = my_atoi(argv[4]);
	(*rules)->nb_must_eat = UINT8_MAX;
	if (argc == 6)
		(*rules)->nb_must_eat = my_atoi(argv[5]);
	return (TRUE);
}
