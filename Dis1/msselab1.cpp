#include <stdio.h>

union bitmask
{
  struct 
  {
  unsigned int flag1:2;
  unsigned int flag2:4;
  unsigned int flag3:2;
  unsigned int flag4:1;
  unsigned int flag5:1;
  unsigned int flag6:1;
  unsigned int flag7:1;
  unsigned int flag8:19;
  } bitfield;
  unsigned int init;
};

char chararr[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x0 };
unsigned long longa[] = {0,0,0,0,0,0,0,0};
int main(int argc, char* argv[])
{
  char charvar = 0x24;
  int  intvar = 0;
  long longvar = 0;
  unsigned char ucharvar = 0;
  unsigned int uintvar = 0;
  unsigned long var = 0;
  
  bitmask mask = {.init = 0 };
  printf("character charvar is %c\n", charvar);
  printf("string chararr is: %s\n", chararr);
  return 0;
}
