/*
** log.c for  in /home/baptiste/project/webserver
**
** Made by
** Login   <baptiste.heraud@epitech.eu>
**
** Started on  Sat Jul 16 11:43:13 2016
** Last update Sat Jul 16 11:43:23 2016 
*/

#include "data.h"

int	log_error_file(char *flag, char *ip, char *file_err, char *log)
{
  FILE *fd = NULL;
  char  *date = NULL;

  date = get_date_system();
  if ((fd = fopen(log, "a+")) == NULL)
      return -1;
  fprintf(fd, "[%s] [%s] [client %s] File does not exist: %s\n", date, flag, ip, file_err);
  fclose(fd);
  free(date);
  return 1;
}

int     log_access_file(char *ip, char *type, char*agent, char *log)
{
  FILE *fd = NULL;
  char  *date = NULL;

  date = get_date_system();
  if ((fd = fopen(log, "a+")) == NULL)
    return -1;
  fprintf(fd, "[%s] - - [%s] - %s - %s \n", ip, date, type, agent);
  fclose(fd);
  free(date);
  return 1;
}

char *get_date_system()
{
  char date[64];
  time_t now = time(NULL);
  char  *tmp = NULL;

  struct tm * tm = localtime(&now);
  strftime(date, sizeof date, "%B %d, %Y %H:%M:%S", tm);
  tmp = strdup(date);
  return tmp;
}
