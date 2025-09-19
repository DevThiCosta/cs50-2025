#include <stdio.h>
#include <cs50.h>

void meow(int n);
int get_positive_int(void);

/* int main(void)
{
   int i = 0;
    while(i >= 2)
    {
        printf("meow\n");
        i++;
    }
}*/


int main(void)
{
  int times = get_positive_int();
  meow(times);
}

int get_positive_int(void)
{
    int n;
    do
    {
      n = get_int("Positive integer: ");
    }
    while (n < 1);
    return n;
}

void meow(int n)
{
  for (int i = 0; i < n; i++)
    {
      printf("meow\n");
    }
}
