/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:55:10 by grenaud-          #+#    #+#             */
/*   Updated: 2022/03/19 02:13:54 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <unistd.h>

typedef struct	s_data
{
	void	*img;
	void	*floor;
	void	*mlx_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

/* typedef struct s_game_map
{
	int		map_height;
	int		map_length;
	int		player_position_x;
	int		player_position_y;
	int		game_score;
	int		max_score;
	char	**map_data;
	int		game_over;
	int		steps;
	void	*wall;
	void	*exit;
	void	*player;
	void	*bg;
	void	*star;
	void	*enemy;
	void	*marvin;
	int		drawP;
	int		*enemyPos;
	int		enemySet;
	char	*err_msg;
}	t_game_map;

typedef struct s_render_v {
	void	*mlx;
	void	*win;
}	t_render_v; */

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

/* void	ft_marvin4_img(t_render_v **vars, t_game_map **map)
{
	char		*marvin;
	static void	*img;
	int			pos[2];

	marvin = "./assets/four.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &pos[0], &pos[1]);
	(*map)->marvin = img;
} */

/* int	deal_key(int key, void *param, void *mlx)
{
	ft_putchar('X');
	mlx_pixel_put(mlx);
	return (0);
} */

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*relative_path= "./four.xpm";
	char	*relative_path_floor= "./floor1.xpm";
	int		img_width;
	int		img_height;
	/* char	str[] = "111111"; */
	int		x;
	int		y;
	int		i;
	int		j;
	t_data	img;
	t_data	floor;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 640, "mlx 42");
	floor.floor = mlx_xpm_file_to_image(mlx_ptr, relative_path_floor, &img_width, &img_height);
	img.img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while(j < 11)
	{
		while(i < 11)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, floor.floor, x, y);
			x += 64;
			i++;
		}
		x = 0;
		i = 0;
		y += 64;
		j++;
	}
	/* my_mlx_pixel_put(&img, 60, 60, 0x00FF0000); */
	mlx_pixel_put(mlx_ptr, win_ptr, 300, 60, 0x00FF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 400, 60, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 100, 100);
 	/* mlx_key_hook(win_ptr, deal_key, (void *)0); */
	mlx_loop(mlx_ptr);
}