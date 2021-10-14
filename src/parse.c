/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:54:16 by agautier          #+#    #+#             */
/*   Updated: 2021/10/14 20:12:31 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	parse(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_error(ERR_ARGS));
	(void)argv;
	return (TRUE);
}
