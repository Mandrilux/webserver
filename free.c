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
