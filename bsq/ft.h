#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		**create_mtx(int m);
int		*fill_map_and_mtx(int fd, int **mtx, int *n_and_symbols, int m);
void	print_map(int fd, int *max);
int		*get_n(int fd);
void	free_mtx(int **mtx);
int		get_m(int fd);
void	print_error(void);
void	no_file(void);

#endif