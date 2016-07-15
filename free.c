#include "data.h"

int	free_double_char(char **tab)
{
  int	i = -1;

  if (tab == NULL)
    return -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
  return 1;
}

void    free_data(t_weft *data_code)
{
  if (data_code->type != NULL)
    free(data_code->type);
  if (data_code->page != NULL)
    free(data_code->page);
  if (data_code->version != NULL)
    free(data_code->version);
}
