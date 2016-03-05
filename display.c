/*
** display.c for  in /home/thomas/Documents/epitech/sudoki-bi
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Feb 28 15:29:53 2016 Thomas HENON
** Last update Sun Feb 28 16:26:33 2016 thomas
*/

#include "sudoku.h"

void	display_wrong_sudoku()
{
  int		x;
  int		y;

  printf("|------------------|\n");
  y = -1;
  while (++y < 9)
    {
      x = -1;
      printf("|");
      while (++x < 9)
	printf(" X");
      printf("|\n");
    }
  printf("|------------------|\n");
}

void	display_sudoku(t_linkedlist *maps)
{
  char	**map;
  int	pos;

  pos = 0;
  while (maps)
    {
      map = (char**)maps->data;
      if (!resolv_sudoku(map, pos))
	display_wrong_sudoku();
      else
	aff_sudoku(map);
      if (maps->next)
	printf("####################\n");
      maps = maps->next;
    }
}

void		aff_sudoku(char **sudo)
{
  int		x;
  int		y;

  printf("|------------------|\n");
  y = -1;
  while (++y < 9)
    {
      x = -1;
      printf("|");
      while (++x < 9)
	printf(" %d", sudo[y][x]);
      printf("|\n");
    }
  printf("|------------------|\n");
}

void	debug_map(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    printf("%s", map[i++]);
}
