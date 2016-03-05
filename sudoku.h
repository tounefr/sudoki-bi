/*
** sudoku.h for  in /home/thomas/Documents/epitech/sudoki-bi
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Feb 28 15:30:18 2016 Thomas HENON
** Last update Sun Feb 28 16:27:29 2016 thomas
*/

#ifndef __SUDOKU_H__
# define __SUDOKU_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct		s_linkedlist
{
  struct s_linkedlist	*next;
  void			*data;
  unsigned int		nbr_elems;
}			t_linkedlist;

/*
** clean.c
*/
char	**clean_map(char **map_uncleaned);
void	clean_maps(t_linkedlist *maps);

/*
** linkedlists.c
*/
char		push_back(t_linkedlist **head, void *data);
t_linkedlist	*new_elem(void *data);
void		free_list(t_linkedlist *head);
void		delete_elem(t_linkedlist **head, void *ptr);
t_linkedlist	*get_elem(t_linkedlist *head, int i);

/*
** display.c
*/
void		display_wrong_sudoku();
void		display_sudoku(t_linkedlist *maps);
void		aff_sudoku(char **sudo);
void		debug_map(char **map);

/*
** load_map.c
*/
char	**load_map(int *error);
char	load_maps(t_linkedlist **maps);

/*
** parsing.c
*/
char	parse_map_line(char *line);
char	parse_map(char **map);

/*
** resolv_sudoku.c
*/
int		line_col_is_ok(const t_coord coord, char **sudo, int nb);
int		in_square_is_ok(const t_coord coord, char **sudo, int nb);
int		resolv_sudoku(char **sudo, int pos);

/*
** util.c
*/
void	free_map(char **map);
void	init_buffer(char *buffer, int size);
void	free_maps(t_linkedlist *maps);

#endif
