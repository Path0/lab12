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
*  Program Description: This program asks for a seed and size value for an array, 
*  making sure it is of correct parameters, and generates an array with random numbers 
*  (0-999 inclusive). It then finds each element that is a multiple of 9, replaces the element with its ones value, and finds if the new element + or - the index is within the array size, and replaces the found index with 0
*
******+-**--------*--*-*-**---*---*--***-*-**-*****************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void filterArray(int*, int);
void getSeed();
int getArrSize();
void printLocations (int*, int);
void fillArray(int*, int);
int getValue(int*, int);
void setValue(int*, int, int);
void findSounds(int*, int);

int main(void)
{
  int *data; //creates a pointer variable that will be used to become an array of a specified size
  int size; // stores the specified size value

  getSeed();
  
  size = getArrSize();

  data = (int*)malloc(sizeof(int) * size);
  
  fillArray(data, size);
  filterArray(data, size);
  findSounds(data, size);
  printLocations(data, size);
  
  return 0;
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getSeed()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line): NONE
*
*  Function Description: Gets the seed input from the user that will be used 
*  to calculate random values. Also gets the maximum value allowed in the random
*  numbers
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
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

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getArrSize
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*  N/A 
*
*  Function Description: Returns the user-inputted size for the array's data
*  set. Checks value for validity and keeps asking until the user inputs
*  a valid value.
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
int getArrSize()
{
  int arrSize; // stores the specified size value

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

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: fillArray()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int *array // accesses the pointer array
*  2. int size // the specified size value
*
*  Function Description: 
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
void fillArray(int *array, int size)
{
  int x; // index value for the array iteration

  for(x = 0; x < size; x++)
  {
    array[x] = rand() % 1000;
  }
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: fillerArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1.int, *array, the randomly generated array from values from 0 - 999
*  2.int, size, the user inputed size of the array
*  3. 
*
*  Function Description: Checks if the random value is divisable by 9. 
*  If it is sets the value of that location in the array to the digit in its
*  ones place. If it is not, sets the value to -1. 
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
void filterArray(int *array, int size)
{
  
  int index; // index of the array used in for loop
  
  for(index = 0; index < size; index++)
  {
    if(getValue(array, index) % 9 == 0)
    {
      setValue(array, index, getValue(array, index) %  10); // set the number to the first digit
    }
    else
    {
      setValue(array, index, -1); // if it's not divisible by 9 then set it to -1
    }
  }
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: printLocations
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int, *array, the array with the possible locations of the sound
*  2. int, size, the user inputed size of the array
*  3. 
*
*  Function Description: Prints the location of the possible sounds in the array
*  does this by if the value is 0 at a certain location in the array and if it is
*  then outputs that location in the array
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
void printLocations (int *array, int size)
{
  int index;//The location in the array that is being evaluated 
  int count;//The number possible locations

  count = 0;

  printf("\nPossible locations:");

  for (index = 0; index < size; index++)
  {
    if (getValue(array, index) == 0) // if it's 0, then there could be a sound here
    {
      printf(" %d", index);
      count++;
    }
  }

  if (count == 0) // if no possible locations, print none
  {
    printf(" None");
  }

  printf("\n");
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: findSounds
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int *array // array to find and edit sound locations in
*  2. int size // size of the array
*
*  Function Description: given an array and its size, finds values that are
*  not -1 and sets indexes that number away in either direction to 0, if
*  such indices exist.
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
void findSounds(int *array, int size)
{
  int index; // index variable for array iterations
  
  for(index = 0; index < size; index++)
  {
    if(getValue(array, index) != -1) // if it's not -1, something is interesting
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
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*  1.int *array // array to get the value from
*  2.int index // index in the array to get the value from
*
*  Function Description: gets the value from the specified array pointer
*  and returns it as an integer.
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
int getValue(int *array, int index)
{
  return * (array + index); // basically return array[index]; but pointers
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: setValue
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int *array // array to set the value in
*  2. int index // index to set the value in
*  3. int value // value to set in the array
*
*  Function Description: sets the value in the array specified at the index
*  specified.
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
void setValue(int *array, int index, int value)
{
  * (array + index) = value; // basically array[index] = value; but with pointers
}