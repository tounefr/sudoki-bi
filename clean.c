/*
** clean.c for  in /home/thomas/Documents/epitech/sudoki-bi
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Feb 28 15:29:50 2016 Thomas HENON
** Last update Sun Feb 28 16:27:19 2016 thomas
*/

#include "sudoku.h"

char	**clean_map(char **map_uncleaned)
{
  int	i;
  int	i2;
  char	**map;

  if (NULL == (map = malloc(sizeof(char*) * 9)))
    return (NULL);
  i = 1;
  while (map_uncleaned[i] && i < 10)
    {
      i2 = 2;
      if (NULL == (map[i-1] = malloc(9)))
	return (NULL);
      while (map_uncleaned[i][i2] && i2 < 19)
	{
	  if (map_uncleaned[i][i2] != ' ')
	    map[i - 1][i2 / 2 - 1] = map_uncleaned[i][i2] - '0';
	  else
	    map[i - 1][i2 / 2 - 1] = 0;
	  i2 += 2;
	}
      i++;
    }
  return (map);
}

void	clean_maps(t_linkedlist *maps)
{
  char	**map_uncleaned;
  char	**map_cleaned;

  while (maps)
    {
      map_uncleaned = (char**)maps->data;
      map_cleaned = clean_map(map_uncleaned);
      free_map(map_uncleaned);
      maps->data = (void*)map_cleaned;
      maps = maps->next;
    }
}
