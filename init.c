#include "data.h"

int	init_dir(char *path)
{
  if (mkdir(path, 644) == -1)
    {
      if(errno != EEXIST)
	{
	  perror(path);
	  return -1;
	}
    }
  return 1;
}

void    init_data(t_weft *data_code)
{
  data_code->type = NULL;
  data_code->host = NULL;
  data_code->user_agent = NULL;
  data_code->etat = NULL;
  data_code->page = NULL;
  data_code->version = NULL;
  data_code->code_page = NULL;
  data_code->error = 0;
}
