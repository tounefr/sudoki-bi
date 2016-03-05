/*
** parsing.c for  in /home/thomas/Documents/epitech/sudoki-bi
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Feb 28 15:30:11 2016 Thomas HENON
** Last update Sun Feb 28 16:26:15 2016 thomas
*/

#include "sudoku.h"

char	parse_map_line(char *line)
{
  int	i;

  if (line[0] != '|' || line[19] != '|')
    return (0);
  i = 1;
  while (i < 19)
    {
      if (line[i] < '0' || line[i] > '9')
	{
	  if (line[i] != ' ')
	    return (0);
	}
      i++;
    }
  return (1);
}
char	parse_map(char **map)
{
  int	i;

  i = 0;
  while (i < 11)
    {
      if (strlen(map[i]) != 21)
	return (-1);
      if (i == 0 || i == 10)
	{
	  if (strcmp("|------------------|\n", map[i]))
	      return (-2);
	}
      else if (!parse_map_line(map[i]))
	return (-3);
      i++;
    }
  return (1);
}
