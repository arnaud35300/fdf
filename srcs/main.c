/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:36:33 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/25 03:28:51 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*f;

	f = malloc(sizeof(t_fdf));
	if (!f || ac != 2 || !ft_strrstr(av[1], ".fdf") || !parse_map(f, av[1]))
		return (free_struct(f, print_error("Usage: ./fdf 42.fdf\n", 1)));
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 400, 400, "bonjour");
	(void)mlx;
	return (free_struct(f, 0));
}
