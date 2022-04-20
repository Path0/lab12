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

void filterArray(int[]);
void getSeed();
int getArrSize();
void printLocations (int[], int);
void fillArray(int, int[]);

int main(void)
{
  int *data;
  int size;

  getSeed();
  size = getArrSize();

  data = (int*)malloc(sizeof(int) * size);
  fillArray(size, data);

  
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

void fillArray(int size, int array[])
{
  int x; // index value for the array iteration

  for(x = 0; x < size; x++)
  {
    array[x] = rand() % 1000;
  }
}

void filterArray(int array[], int size)
{
  
  int index;
  for(index = 0; index < size; index++)
  {
    if(array[index] % 9 == 0)
    {
      array[index] = array[index] % 10; // set the number to the first digit
    }
    else if(array[index] % 10 == 0)
    {
      array[index];
    }
  }
}

void printLocations (int array[], int size)
{
  int index;
  int count;

  printf("\nPossible locations:");

  for (index = 0; index < size; index++)
  {
    if (array[index] == 0)
    {
      printf(" %d", index);
      count++;
    }
  }
}