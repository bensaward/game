/* rocks.h used for generating rocks for program.c
 *
 * put any test code in here ready to be transferred to program.c
 *
 */
#ifndef _ROCKS_H_
#define _ROCKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void rocks_init(int x, int y, int x_max, int y_max);
int rand_int(unsigned int min, unsigned int max);

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

#endif
