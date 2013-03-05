// rocks.c test for uniformity of prng

#include </sdcard/Documents/rocks.h>
#include <iostream.h>

#define random_max 9
#define random_min 0
#define bin_number (random_max-random_min)+1
#define bin[bin_number] 0

int main ()
{
	for (int i=random_min; i=<random_max; i++)
	{
		printf("\033[2;%dH%d", i, i);
	}
   
   for (;;)
   {
      int random = rand_int()
}
