#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#include <hw1.1.h>

unsigned char masks[] = {0xF, 0x3, 0x1 };


unsigned int getLSBbyte(unsigned char byte)
{
  if (byte==0) throw std::runtime_error("invalid parameter - should not be 0");
  unsigned char flag = 0;
  unsigned short pos=0;
  unsigned short magic=4;
  for (unsigned int pos=0; pos<3; pos++)
    {
    if (!(byte&masks[pos])) 
      {
      flag |=magic;
      byte>>=magic;
      }
    magic>>=1; // magic 100 -> ? -> ?
    }
  unsigned int lsb = (flag&4)+(flag&2)+(flag&1);
  return lsb;
}


int main(int argc, char* argv[])
{
  if (argc !=2)
    {
    printf("usage hw1.1 number, for example hw1.1 250");
    return EXIT_FAILURE;
    }
  
  unsigned int input = atoi(argv[1]);
  unsigned int lsb = findLSB(input);
  printf("LSB = %d ", lsb);
  printf("\n");
  return EXIT_SUCCESS;
}

