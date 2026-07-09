#include <stdlib.h>
#include "generator.h"

void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

void generateAscending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
}

void generateDescending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}
void copyArray(int source[], int destination[], int n)
{
    for (int i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }

}
