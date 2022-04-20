/*****+-**--------*--*-*-**---*---*--***-*-**-******************************
*
*  Lab #:12
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
*
******+-**--------*--*-*-**---*---*--***-*-**-*****************************/

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: 
*
*  Function Return Type: 
*
*  Parameters (list data type, name, and comment one per line):
*  1.
*  2. 
*  3. 
*
*  Function Description: 
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void filterArray(int*, int);
void getSeed();
int getArrSize();
void printLocations (int*, int);
void fillArray(int, int*);
int getValue(int*, int);
void setValue(int*, int, int);

int main(void)
{
  int *data;
  int size;
  //int i;

  getSeed();
  size = getArrSize();

  data = (int*)malloc(sizeof(int) * size);
  fillArray(size, data);
  printLocations(data, size);
/* to print values 
  for (i = 0; i < size; i++)
  {
      printf("%d, ", data[i]);
      
  } */
  
  return 0;
}

void getSeed()
{
  int seed; // stores the seed value from the user

  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &seed);

    if (seed <= 0)
    {
      printf("\nError! Positive seed values only!!\n\n");
    }
  } while (seed <= 0);
  srand(seed);

}

int getArrSize()
{
  int arrSize;

  do
  {
    printf("Enter desired data set size -> ");
    scanf("%d", &arrSize);

    if (arrSize <= 0)
    {
      printf("\nError! Positive values only!!\n\n");
    } 
  } while (arrSize <= 0);

  return arrSize;
}

void fillArray(int size, int *array)
{
  int x; // index value for the array iteration

  for(x = 0; x < size; x++)
  {
    array[x] = rand() % 1000;
  }
}

void filterArray(int *array, int size)
{
  
  int index;
  for(index = 0; index < size; index++)
  {
    if(getValue(array, index) % 9 == 0)
    {
      setValue(array, index, getValue(array, index) %  10); // set the number to the first digit
    }
    else
    {
      setValue(array, index, -1);
    }
  }
}

void printLocations (int *array, int size)
{
  int index;//The location in the array that is being evaluated 
  int count;//The number possible locations

  printf("\nPossible locations:");

  for (index = 0; index < size; index++)
  {
    if (getValue(array, index) == 0)
    {
      printf(" %d", index);
      count++;
    }
  }

  if (count == 0)
  {
    printf(" None");
  }
}

void findSounds(int *array, int size)
{
  int index;
  for(index = 0; index < size; index++)
  {
    // checks for index above value
    if(index + getValue(array, index) < size)
    {
      setValue(array, index + getValue(array, index), 0);
    }

    // checks for index below value
    if(index - getValue(array, index) >= 0)
    {
      setValue(array, index - getValue(array, index), 0);
    }
  }
}

int getValue(int *array, int index)
{
  return *(array + index);
}

void setValue(int *array, int index, int value)
{
  *(array + index) = value;
}