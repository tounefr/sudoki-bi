/*
** util.c for  in /home/thomas/Documents/epitech/sudoki-bi
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Feb 28 15:30:21 2016 Thomas HENON
** Last update Sun Feb 28 16:35:05 2016 thomas
*/

#include "sudoku.h"

void	free_map(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    free(map[i++]);
  free(map);
}

void	init_buffer(char *buffer, int size)
{
  int	i;

  i = 0;
  while (i < size)
    buffer[i++] = 0;
}

void	free_maps(t_linkedlist *maps)
{
  char	**tmp;

  while (maps)
    {
      tmp = (char**)maps->data;
      free_map(tmp);
      maps = maps->next;
    }
}
