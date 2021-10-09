/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:38:53 by agautier          #+#    #+#             */
/*   Updated: 2021/10/09 20:20:48 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** Return current timestamp.
*/
uint64_t get_timestamp()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec / 1000 + tv.tv_usec * 1000);
}


/*
**
*/
int main(void)
{
	printf("Hello World!\n");
	return (EXIT_SUCCESS);
}
