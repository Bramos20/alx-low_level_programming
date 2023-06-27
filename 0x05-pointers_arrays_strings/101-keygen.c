#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int random_number;
    int count;
    int remaining_total;

    srand(time(NULL));
    for (count = 0, remaining_total = 2772; remaining_total > 122; count++)
    {
        random_number = (rand() % 125) + 1;
        printf("%c", random_number);
        remaining_total -= random_number;
    }
    printf("%c", remaining_total);

    return 0;
}
