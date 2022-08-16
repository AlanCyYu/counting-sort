#include <stdint.h>
#include "counting_sort.h"

void CountingSort(int16_t* arrIn, int16_t* arrOut, int16_t arrSize, int16_t maxInt)
{
    int16_t count[maxInt+1];

    for (int16_t i = 0; i < (maxInt+1); i++)
    {
        count[i] = 0;
    }

    for (int16_t i = 0; i < arrSize; i++)
    {
        count[arrIn[i]]++;
    }

    for (int16_t i = 1; i < (maxInt+1); i++)
    {
        count[i] += count[i-1];
    }

    for (int16_t i = (arrSize-1); i >= 0; i--)
    {
        arrOut[count[arrIn[i]]-1] = arrIn[i];
        count[arrIn[i]]--;
    }
}