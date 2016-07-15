#include "data.h"

int     read_weft(SOCKET csock, char *ip)
{
  char  buff[1024] = {0};
  int   flag = 0;
  char  **line = NULL;
  char  *tmp = NULL;
  t_weft data_code;

  if ((flag = read(csock, buff, 1023)) == -1)
    return (-1);
  if ((tmp = epur_str(buff)) == NULL)
    exit (printf("ERROR MEMORY\n"));
  if ((line = strtowordtab(tmp, '\n')) == NULL)
    return (printf("ERROR MEMORY\n"));
  if (decode_weft(line, &data_code) == -1)
    return (printf("Erreur decode string\n"));
  /* printf("data_code.type = %s\n", data_code.type); */
  if (strcmp(data_code.page, "/") == 0)
    send_weft_200(csock, ip, data_code);
  else
    send_weft_404(csock, ip, data_code.page);
  free(tmp);
  /* free_double_char(path); */
  free_double_char(line);
  return (1);
}

int	decode_weft(char **data, t_weft *data_code)
{
  int	i = -1;
  char  **path = NULL;

  if (data == NULL)
    return (-1);
  data_code->type = NULL;
  data_code->host = NULL;
  data_code->user_agent = NULL;
  data_code->etat = NULL;
  data_code->page = NULL;
  data_code->version = NULL;
  while (data[++i] != NULL)
    {
      if (strstr(data[i],"GET") != NULL || strstr(data[i], "POST") != NULL)
	{
	  if ((path = strtowordtab(data[i], ' ')) == NULL)
	    return (-1);
	  data_code->type = path[0];
	  data_code->page = path[1];
	  data_code->version = path[2];
	}
      if (strstr(data[i],"Host:") != NULL)
	data_code->host = &(data[i][5]);
      if (strstr(data[i], "User-Agent:") != NULL)
	data_code->user_agent = &(data[i][11]);
      if (strstr(data[i], "Connection:") != NULL)
	data_code->etat = &(data[i][11]);
    }
  return (1);
}
