/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:47:58 by pherranz          #+#    #+#             */
/*   Updated: 2020/02/25 11:35:13 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &(argv[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
