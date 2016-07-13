/*
** display.c for  in /home/baptiste/dev_stage/moulinette
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Fri Jul  1 11:33:51 2016
** Last update Wed Jul 13 14:34:03 2016 
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

int	log_std_error(char *str, int status, char *file, char *flag)
{
  FILE *fd = NULL;
  char	*error = NULL;
  char	*date = NULL;

  date = get_date_system();
  error = strerror(errno);
  if ((fd = fopen(file, "a+")) == NULL)
    return (status);
  fprintf(fd, "[%s] [%s] %s %s\n", date, flag, str, error);
  fclose(fd);
  free(date);
  return (status);
}

int	log_error_file(char *flag, char *ip, char *file_err, char *log)
{
  FILE *fd = NULL;
  char  *date = NULL;

  date = get_date_system();
  if ((fd = fopen(log, "a+")) == NULL)
    return (-1);
  fprintf(fd, "[%s] [%s] [client %s] File does not exist: %s\n", date, flag, ip, file_err);
  return (1);
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
