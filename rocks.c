// rocks.c test for uniformity of prng

#include </sdcard/Documents/rocks.h>
#include <iostream.h>

#define random_max 9
#define random_min 0
#define bin_number (random_max-random_min)+1

int bin_array[bin_number];

int buffer_init();
int buffer_update();
int buffer_print();
int screen_init();
int buffer_init()
{
  for (int i=0; i<bin_number; i++)
  {
    bin_array=0;
  }
}

int screen_init()
{
  int n=random_min, triple_i;
  for (int i=random_min; i=<random_max; i++)
  {
    triple_i=i*3;
    printf("\033[2;%dH%d", triple_i, i);
    printf("\033[1;%dH%d", triple_i, n);
    n++;
  }
  
int main ()
{
  for (;;)
  {
    int random = rand_int()
  }
}
