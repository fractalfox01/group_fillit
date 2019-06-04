/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:25:17 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/03 16:47:09 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_tetfile
{
	char				**piece;
	int					*sym_arr;
	int					width;
	int					height;
	int					row;
	int					col;
	int					p_num;
	struct s_tetfile	*next;
}						t_piece;

typedef struct			s_board
{
	char				**slv_b;
	int					b_size;
	t_piece				*tmp_b;
	int					tet_count;
	int					cur;
	int					valid;
}						t_board;

void					f_init(t_board *mst);
int     				start_size(int square);
void					set_length(t_board *main_board);
t_piece					*add_lst_piece(t_piece *tmp, char *buf, int *arr, int a, int i);
void					print_mst_board(t_board *mst);
void					fillit(char *file);
int						read_file(char *file, t_board *n_board, int i, int flag);
t_board					*new_board(int size);
//int						is_valid_char(char c);
char					**error(void);
int						verify_file(t_board *main_board);
int						verify_tetra(char **tab, int i, int j, int hash);
int						check_horizonal(int i, int j, char **tab);
int						check_vertical(int i, int j, char **tab);
int						c_chk(int k, int i, int j, char **block);
void					normalize_blocks(t_board *main_board);
void					generate_solution_board(t_board *main_board, int size);
void					solve(t_board *main_board);
int						verify_piece(t_piece *piece, char *buf);
int						*get_coordinates(char **piece, int i, int j);
t_piece					*get_piece(t_board *mst, int cur);
int						start_mapping(t_board *mst);
int						check_area(t_board *mst, char **solution_board);
void					map_piece(t_board *mst, t_piece *tetra, int col, int row);
int						backtrack(t_board *mst);
int						update_coord(t_board *mst, int cur);
void					zero_tetra(t_board *mst);

#endif