/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/13 01:30:38 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
**
*/
int	main(int argc, char **argv)
{
	uint64_t	start_time;

	if (argc < 5 || argc > 6)
		return (print_error(ERR_ARGS));
	(void)argv;
	start_time = get_timestamp();
	while (1)
		fprintf(stderr, "start_time = %llu\n", get_timestamp() - start_time);
	return (EXIT_SUCCESS);
}
