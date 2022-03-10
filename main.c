/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:55:10 by grenaud-          #+#    #+#             */
/*   Updated: 2022/03/10 17:05:33 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <unistd.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* int	deal_key(int key, void *param)
{
	ft_putchar('X');
	mlx_pixel_put(mlx_ptr);
	return (0);
} */

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 60, 60, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 100, 100);
/* 	mlx_key_hook(win_ptr, deal_key, (void *)0);*/
	mlx_loop(mlx_ptr);
}