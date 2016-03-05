/*
** resolv_sudoku.c for  in /home/aurelien/rendu/Cycle_CPE/sudoki-bi
**
** Made by Aur�lien
** Login   <aurelien.bauer@epitech.net>
**
** Started on  Sat Feb 27 13:41:07 2016 Aur�lien
** Last update Sun Feb 28 15:28:43 2016 thomas
*/

#include "sudoku.h"

int		line_col_is_ok(const t_coord coord, char **sudo, int nb)
{
  int		i;

  i = -1;
  while (++i < 9)
    {
      if (sudo[coord.y][i] == nb)
	return (0);
    }
  i = -1;
  while (++i < 9)
    {
      if (sudo[i][coord.x] == nb)
	return (0);
    }
  return (1);
}

int		in_square_is_ok(const t_coord coord, char **sudo, int nb)
{
  int		i;
  int		j;
  int		x;
  int		y;

  i = 3 * (coord.x / 3);
  j = 3 * (coord.y / 3);
  y = -1;
  while (++y < 3)
    {
      x = -1;
      while (++x < 3)
	{
	  if ((sudo[j + y][i + x] == nb))
	    return (0);
	}
    }
  return (1);
}

int		resolv_sudoku(char **sudo, int pos)
{
  t_coord	coord;
  int		nb_test;

  if (pos == 9 * 9)
    return (1);
  coord.x = pos % 9;
  coord.y = pos / 9;
  if (sudo[coord.y][coord.x] != 0)
    return (resolv_sudoku(sudo, pos + 1));
  nb_test = 0;
  while (++nb_test <= 9)
    {
      if (in_square_is_ok(coord, sudo, nb_test) == 1 &&
	  line_col_is_ok(coord, sudo, nb_test) == 1)
	{
	  sudo[coord.y][coord.x] = nb_test;
	  if (resolv_sudoku(sudo, pos + 1) == 1)
	    return (1);
	}
    }
  sudo[coord.y][coord.x] = 0;
  return (0);
}
