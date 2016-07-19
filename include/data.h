
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include "serv.h"

		/* strtoword.c */

int		 count_words(char *str, char decoup);
int		 wordlen(char *str, char decoup);
char*		 complete_line(char *str, int nb, char decoup);
char		 **small_tab(char *str);
char		 **strtowordtab(char *str, char decoup);

		/* log.c */

int		 log_error_file(char *flag, char *ip, char *file_err, char *log);
int		 log_access_file(char *ip, char *type, char*agent, char *log);
char		 *get_date_system();

		/* free.c */

int		 free_double_char(char **tab);
void		 free_data(t_weft *data_code);

		/* function.c */

long		 file_size(const char *filename);

		/* weft.c */

int		 read_weft(SOCKET csock, char *ip);
int		 decode_weft(char **data, t_weft *data_code);
int		 get_page(t_weft *data_code);

		/* init.c */

int		 init_dir(char *path);
void		 init_data(t_weft *data_code);

		/* str.c */

char		 *epur_str(char *str);

		/* send.c */

int		 send_page(SOCKET csock, t_weft *data, char *ip);

		/* main.c */

int		 main();

#endif /* DATA_H_ */
