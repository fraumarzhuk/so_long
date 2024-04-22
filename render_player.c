#include "so_long.h"
void render_player(t_data *img, void	*mlx, void *mlx_win, t_args *args, char	*player_path)
{
/* 	char	*player_path = "./img/player/player_1.xpm"; */
	int		img_width = 65;
	int		img_height = 33;

	img->img = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img->img, args->player_x * 65, args->player_y * 65);
}
