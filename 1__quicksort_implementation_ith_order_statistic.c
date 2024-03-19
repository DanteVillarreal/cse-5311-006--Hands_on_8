//This implementation of quicksort impelements both random and last element pivots. 
//Name: Dante Villarreal
//ID: 1001580411



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapElements(int* firstElement, int* secondElement)
{
    int temporary = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temporary;
}

int partitionArray(int array[], int lowIndex, int highIndex, int isRandomPivot)
{
    int pivotIndex;
    if (isRandomPivot)
    {
        pivotIndex = lowIndex + rand() % (highIndex - lowIndex);
    }
    else
    {
        pivotIndex = highIndex; // Non-random pivot is the last element
    }
    swapElements(&array[pivotIndex], &array[highIndex]);
    int pivot = array[highIndex];
    int i = (lowIndex - 1);

    for (int j = lowIndex; j <= highIndex - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swapElements(&array[i], &array[j]);
        }
    }
    swapElements(&array[i + 1], &array[highIndex]);
    return (i + 1);
}

void quicksortArray(int array[], int lowIndex, int highIndex, int isRandomPivot)
{
    if (lowIndex < highIndex)
    {
        int partitionIndex = partitionArray(array, lowIndex, highIndex, isRandomPivot);
        quicksortArray(array, lowIndex, partitionIndex - 1, isRandomPivot);
        quicksortArray(array, partitionIndex + 1, highIndex, isRandomPivot);
    }
}

//new code that utilizes ith order statistic
int ithOrderStatistic(int array[], int lowIndex, int highIndex, int i, int isRandomPivot)
{
    if (lowIndex == highIndex)
        return array[lowIndex];

    int partitionIndex = partitionArray(array, lowIndex, highIndex, isRandomPivot);

    int k = partitionIndex - lowIndex + 1;

    if (i == k) // pivot value is the answer
        return array[partitionIndex];
    else if (i < k)
        return ithOrderStatistic(array, lowIndex, partitionIndex - 1, i, isRandomPivot);
    else
        return ithOrderStatistic(array, partitionIndex + 1, highIndex, i - k, isRandomPivot);
}

int main() 
{
    srand(time(NULL)); // Seed the random number generator

    int array[] = {10, 7, 8, 9, 1, 5};
    int array_size = sizeof(array) / sizeof(array[0]);
    int i = 3; // Find the 3rd smallest element

    printf("The %dth order statistic is %d\n", i, ithOrderStatistic(array, 0, array_size - 1, i, 1));

    return 0;
}
