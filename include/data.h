
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <string.h>

		/* date.c */

char		 *get_date_system();

		/* error.c */

int		 log_error(char *msg, int status, char *file, char *flag, int display);
int		 log_std_error(char *str, int status, char *file, char *flag, int display);
char		 *get_date_system();

		/* main.c */

int		 main();

#endif /* DATA_H_ */
