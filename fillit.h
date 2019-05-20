/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:25:17 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/19 14:54:10 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/get_next_line.h"
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
	char				**solved_board;
	int					board_size;
	t_piece				*tmp_board;
	int					tetra_count;
	int					cur;
	int					valid;
}						t_board;

void					set_length(t_board *main_board);
t_piece					*add_lst_piece(t_piece *tmp, char *buf, int *arr, int a, int i);
void					print_board(t_board *main_board);
void					print_pieces(t_board *mst);
void					fillit(char *file);
int						read_file(char *file, t_board *n_board);
t_board					*new_board(int size);
int						is_valid_char(char c);
char					**error(void);
int						verify_file(t_board *main_board);
int						verify_tetra(char **tab, int i, int j, int hash);
int						check_horizonal(int i, int j, char **tab);
int						check_vertical(int i, int j, char **tab);
int						c_chk(int k, int i, int j, char **block); //
void					normalize_blocks(t_board *main_board);
void					generate_solution_board(t_board *main_board, int size);
void					solve(t_board *main_board);

// KATYA
int						verify_piece(t_piece *piece, char *buf);
int						*get_coordinates(char **piece);

//TESTS

char 					*resultToString(int result[8]);
int 					get_coordinates_test(char piece[4][4], int result[8]);


#endif
