/*
** main.c for  in /home/thomas/Documents/epitech/sudoki-bi
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Feb 28 15:30:05 2016 Thomas HENON
** Last update Sun Feb 28 16:36:25 2016 thomas
*/

#include "sudoku.h"

int		main()
{
  t_linkedlist	*maps;

  if (!load_maps(&maps))
    {
      printf("MAP ERROR\n");
      return (1);
    }
  clean_maps(maps);
  display_sudoku(maps);
  free_list(maps);
  return (0);
}
