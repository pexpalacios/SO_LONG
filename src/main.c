#include "../so_long.h"

int	check_ber(char *map)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(name_end, ext, ft_strlen(name_end)) != 0)
	{
		free(name_end);
		return (0);
	}
	free(name_end);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	//argument check
	if (ac != 2)
		perror("Invalid number of arguments");
	//check if it's .ber
	if (check_ext())
		perror("File extension must be .ber");

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (free(game), 0);
	//parse map
	//check_map(av[1]);
	//initiate game
	game->mlx = mlx_init();
	if (!game->mlx)
		perror("Couldn't load mlx");
	game->window_x = game->map.lenline * TILE_SIZE;
	game->window_y = game->map.lencol * TILE_SIZE;
	game->window = mlx_new_window(game->mlx, game->window_x,
		game->window_y, "So_long");
	get_xmp_image(game);
	start_game(game);
	return (0);
}

void	start_game(t_game *game)
{
	draw_map(game);
	game->player.cont_moves = 0;
	game->player.items = 0;
	mlx_key_hook(game->window, key_input, game);
	mlx_hook(game->window, ClientMessage, LeaveWindowMask, close_game, game);
	mlx_loop(game->mlx);
}