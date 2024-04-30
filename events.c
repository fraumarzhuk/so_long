
#include "so_long.h"

int key_press(int keycode, t_env *env)
{
	// ESC key to exit
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->mlx_win);
		exit(1);
	}
	// move right
	if (keycode == 124 || keycode == 2)
		move_on_x(env, env->args->player_y, env->args->player_x + 1, 1);
	//move left
	if (keycode == 123 || keycode == 0)
		move_on_x(env, env->args->player_y, env->args->player_x - 1, -1);
	//move_up
	if (keycode == 126 || keycode == 13)
		move_on_y(env, env->args->player_y - 1, env->args->player_x, -1);
	//move_down
	if (keycode == 125 || keycode == 1)
		move_on_y(env, env->args->player_y + 1, env->args->player_x, 1);
	return (0);
}

void	move_on_y(t_env *env, int y, int x, int sign)
{
	if (env->args->map[y][x] != '1' && env->args->map[y][x])
	{
		env->args->player_y += sign;
		check_collects(env);
		render_everything(env->img, env->mlx, env->mlx_win, env->args);
		env->args->moves++;
		printf("Moves: %i\n", env->args->moves);
	}
}
void	move_on_x(t_env *env, int y, int x, int sign)
{
	if (env->args->map[y][x] != '1' && (env->args->map[y][x]) && env->args->map[y][x] != '\n')
	{
		env->args->player_x += sign;
		check_collects(env);
		if (sign == 1)
			env->img->player_back = false;
		else
			env->img->player_back = true;
		render_everything(env->img, env->mlx, env->mlx_win, env->args);
		env->args->moves++;
		printf("Moves: %i\n", env->args->moves);
	}
}

void	check_collects(t_env *env)
{
	if (env->args->map[env->args->player_y][env->args->player_x] == 'C')
	{
		env->args->map[env->args->player_y][env->args->player_x] = '0';
		env->args->collects_amount--;
	}
	if (env->args->collects_amount <= 0)
		env->args->collects_collected = true;
}
