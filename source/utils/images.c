/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:40:50 by zwong             #+#    #+#             */
/*   Updated: 2022/10/13 10:41:07 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*my_xpm_to_img(t_game *game, char *str)
{
	int	*xsize;
	int	*ysize;

	xsize = &game->img_size.x;
	ysize = &game->img_size.y;
	return (mlx_xpm_file_to_image(game->mlx, str, xsize, ysize));
}
