#include <stdexcept>
#include <hw1.1.h>

unsigned short masks4[] = {0xFFFF, 0xFF};

unsigned int findLSB(unsigned int var)
{
  if (var==0) throw std::runtime_error("invalid parameter - should not be 0");
  char* byte = (char*) &var;
  unsigned int clone = var;
  unsigned char flag = 0;
  unsigned short pos = 0;
  unsigned short magic = 16;
  unsigned short group = 2;
  for (unsigned int pos=0; pos<2; pos++)
    {
    if (!(clone&masks4[pos]))
      {
      flag += group;
      clone>>=magic;  
      }
    group--;
    magic>>=1;
    }
  unsigned int lsb = flag*8 + getLSBbyte(byte[flag]);
  return lsb;
}
