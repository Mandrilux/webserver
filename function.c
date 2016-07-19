#include "data.h"

long file_size(const char *filename)
{
  struct stat s;

  if  (stat(filename,&s) != 0)
    return -1;
  return s.st_size;
}
