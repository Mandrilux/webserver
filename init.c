#include "data.h"

int	init_dir(char *path)
{
  if (mkdir(path, 644) == -1)
    {
      perror(path);
      return -1;
    }
  return 1;
}
