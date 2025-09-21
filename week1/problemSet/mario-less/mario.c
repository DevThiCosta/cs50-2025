#include <cs50.h>
#include <stdio.h>

int get_height(void);
void draw_pyramid(int height);
void print_spaces(int count);
void print_hashes(int count);

int main(void)
{
    int height = get_height();
    draw_pyramid(height);
}

int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height (1–8): ");
    }
    while (h < 1 || h > 8);
    return h;
}

void draw_pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        print_spaces(height - i);
        print_hashes(i);
        printf("\n");
    }
}

void print_spaces(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf(" ");
    }
}

void print_hashes(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("#");
    }
}
