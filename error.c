/*
** display.c for  in /home/baptiste/dev_stage/moulinette
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Fri Jul  1 11:33:51 2016
** Last update Wed Jul 13 11:22:44 2016 
*/

#include "data.h"

int	log_error(char *msg, int status, char *file, char *flag, int display)
{
  FILE *fd;
  char  *date;

  date = get_date_system();
  if (display == 1)
    printf("[%s] %s\n", date, msg);
  if ((fd = fopen(file, "a+")) == NULL)
    return (status);
  fprintf(fd, "[%s] [%s] %s\n", flag, date, msg);
  fclose(fd);
  free(date);
  return (status);
}

int	log_std_error(char *str, int status, char *file, char *flag, int display)
{
  FILE *fd = NULL;
  char	*error = NULL;
  char	*date = NULL;

  date = get_date_system();
  error = strerror(errno);
  if (display == 1)
    printf("[%s] %s %s\n", date, str, error);
  if ((fd = fopen(file, "a+")) == NULL)
    return (status);
  fprintf(fd, "[%s] [%s] %s %s\n", flag, date, str, error);
  fclose(fd);
  free(date);
  return (status);
}

char *get_date_system()
{
  char date[64];
  time_t now = time(NULL);
  char  *tmp = NULL;

  struct tm * tm = localtime(&now);
  strftime(date, sizeof date, "%B %d, %Y %H:%M:%S", tm);
  #ifdef __linux__
  tmp = strdup(date);
  #elif _WIN32
  tmp = _strdup(date);
  #endif
  return (tmp);
}
