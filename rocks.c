// rocks.c test for uniformity of prng

#include </mnt/sdcard/Documents/game/rocks.h>
#include <stdio.h>
#include <time.h>

#define random_max 9
#define random_min 0
#define bin_number (random_max-random_min)+1

int bin_array[bin_number];
void buffer_init();
void buffer_update();
void screen_print();

void buffer_init()
{
  for (int i=0; i<=bin_number; i++)
  {
    bin_array[i]=0;
  }
}

void screen_print()
{
  int n=0, triple_i;
  for (int i=random_min; i<=random_max; i++)
  {
    triple_i=i*3;
    printf("\033[2;%dH%d", triple_i, i);
    printf("\033[1;%dH%d", triple_i, bin_array[n]);
    n++;
  }
}


void buffer_update()
{
  int random=rand_int(random_min, random_max);
  int array_number=random-random_min;
  bin_array[array_number]++;
}

int main ()
{
	srand(0);
	buffer_init();
	screen_print();
	for (;;)
	{
	  	buffer_update();
	 	screen_print();
	}
	exit (0);
}
