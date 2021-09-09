#include <stdio.h>
#include <stdlib.h>
#include <cstring>

void printnumber(char*list, int target)
{
  if (target == 1)
  {
  printf("%s1\n", list);
  return;
  }
  else{
    const unsigned int position = strlen(list);
    sprintf(list+position, "%d ", target);
    printnumber(list, target -1 );
  }
}

// void printnumber(char*list, int target)
// {
//   if (target == 0)
//   {
//   printf("%s\n", list);
//   return;
//   }
//   else{
//     const unsigned int position = strlen(list);
//     sprintf(list+position, "%d ", target);
//     printnumber(list, target -1 );
//   }
// }  

int main(int argc, char* argv[])
{
  if (argc != 2)
    {
    printf("usage: hw2.2  number\n");
    return EXIT_FAILURE;  
    }
  unsigned int target = atoi(argv[1]);

  char* list = new char[target + 10];
  printnumber(list, target);

  delete list;
  return EXIT_SUCCESS;
}
