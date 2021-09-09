#include <stdio.h>
#include <stdlib.h>
#include <cstring>

// void printnumber(char*list, int target)
// {
//   if (target == 0)
//   {
//   printf("%s\n", list);
//   return;
//   }
//   else{
//     for(int k = 1; k <= target ; k++){
//       const unsigned int position = strlen(list);
//       sprintf(list+position, "%d ", k);
//     // printf("%s\n", list);
//       printnumber(list, k -1);
//     }
//   }
// }

void printnumber(char*list, int target, int position)
{
  if (target == 0)
  {
  printf("%s\n", list);
  return;
  }
  else{
    for(int k = 1; k <= target ; k++){
      sprintf(list+position, "%d ", k);
    // printf("%s\n", list);
      const unsigned int newposition = strlen(list);
      printnumber(list, k -1 , newposition);
    }
  }
}

// // Decreasing Sequence
// void printnumber(char*list, int target, int position)
// {
//   if (target == 0)
//   {
//   printf("%s\n", list);
//   return;
//   }
//   else{
//     for(int k = target; k >= 1 ; k--){
//       sprintf(list+position, "%d ", k);
//       const unsigned int newposition = strlen(list);
//       printnumber(list, k -1 , newposition);
//     }
//   }
// }

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("usage: hw2.2  number\n");
    return EXIT_FAILURE;
  }
  unsigned int target = atoi(argv[1]);

  char *list = new char[1000];
  int position = 0;
  // printnumber(list, target);
  printnumber(list, target, position);

  delete list;
  return EXIT_SUCCESS;
}
