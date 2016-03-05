/*
** load_map.c for  in /home/thomas/Documents/epitech/sudoki-bi
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Feb 28 15:30:00 2016 Thomas HENON
** Last update Sun Feb 28 16:17:00 2016 thomas
*/

#include "sudoku.h"

char	**load_map(int *error)
{
  char	buffer[100];
  char	**map;
  int	i;

  memset(buffer, 0, 100);
  if (NULL == (map = malloc(sizeof(char*) * 12)))
    return (NULL);
  i = 0;
  while (i < 12)
    map[i++] = NULL;
  i = 0;
  while (i < 11 && fgets(buffer, sizeof(buffer), stdin))
    map[i++] = strdup(buffer);
  if (i < 11)
    {
      if (i > 0)
	*error = 1;
      free_map(map);
      return (NULL);
    }
  return (map);
}

char	load_maps(t_linkedlist **maps)
{
  char	**map;
  int	error;

  error = 0;
  *maps = NULL;
  while ((map = load_map(&error)))
    {
      if (parse_map(map) <= 0)
	return (0);
      push_back(maps, (void*)map);
    }
  if (*maps == NULL || error)
    return (0);
  return (1);
}
