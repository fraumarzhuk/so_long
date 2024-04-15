#include "so_long.h"

int insert_end(t_map **map, t_args *args)
{
	t_map *new_node;
	t_map *curr;
	
	curr = *map;
	new_node = ft_calloc(sizeof(t_map), 1);
	if (!new_node)
		so_short_error("Malloc failed!");
	new_node->next = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	new_node->line = get_next_line(args->fd);
	// printf("%s\n", new_node->line);
	if (!new_node->line)
		return (0);
	return(1);
}

int map_init(t_args *args)
{ 
	t_map	*map;
	int		i;

	args->line_count = 0;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		so_short_error("Malloc failed!");
	map->line = get_next_line(args->fd);
	map->next = NULL;
	while (insert_end(&map, args) != 0)
		args->line_count++;
	i = 0;
	args->map = ft_calloc(args->line_count + 1, sizeof(char *));
	if (!args->map)
		so_short_error("Malloc failed.");
	while (i < args->line_count && map)
	{
		args->map[i] = ft_strdup(map->line);
		map = map->next;
		printf("Check map 0: %s\n", args->map[i]);
		i++;
	}
	args->map[i] = NULL;
/* 	i = 0;
    while (args->map[i] != NULL) {
        printf("%s\n", args->map[i]);
        i++;
	} */
	return (1);
}