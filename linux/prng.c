#include <main.h>

int rand_int(unsigned int min, unsigned int max)
{
  int range = max - min, bin_size=RAND_MAX/(range+1), remainder=RAND_MAX % (range+1), bin_number = range+1; // min=1, max=10 |1-bin
  int bin[bin_number], random=rand(), max_bin, min_bin, discard_min=RAND_MAX-remainder-1;
  for (int i=0, x=min; i<bin_number; i++)
  {
    bin[i]=x;
    x++;
    max_bin=bin_size*(i+1);
    min_bin=bin_size*i;
    if (random>=min_bin)
    {
      if (random<max_bin)
      {
	  return bin[i];
	  break;
      }
    }
    if (random > discard_min)
    {
      rand_int(min, max);
    }
  }
}
