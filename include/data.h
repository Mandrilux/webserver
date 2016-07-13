
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

int		 log_error(char *msg, int status, char *file, char *flag, int display);
int		 log_std_error(char *str, int status, char *file, char *flag);
int		 log_error_file(char *flag, char *ip, char *file_err, char *log);
char		 *get_date_system();

		/* str.c */

char		 *epur_str(char *str);

		/* main.c */

int		 main();
int		 read_weft(SOCKET csock);
int		 send_weft(SOCKET csock);

#endif /* DATA_H_ */
