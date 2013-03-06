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
int buffer_print();
void screen_init();

void buffer_init()
{
  for (int i=0; i<=bin_number; i++)
  {
    bin_array[i]=0;
  }
}

void screen_init()
{
  int n=random_min, triple_i;
  for (int i=random_min; i<=random_max; i++)
  {
    triple_i=i*3;
    printf("\033[2;%dH%d", triple_i, i);
    printf("\033[1;%dH%d", triple_i, n);
    n++;
  }
}


void buffer_update()
{
  int random=rand_int(random_min, random_max), array_number=random-random_min;
  bin_array[array_number]++;
}
  
int main ()
{
}