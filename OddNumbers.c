#include <stdio.h>
#include <stdlib.h>

int pos = 0;

void
printArray (int *arr, int pos)
{
  for (int x = 0; x < pos; x++)
    {
      if (arr[x] != 0)
	{
	  printf ("%d ", arr[x]);
	}
    }
}

int
push (int *array, int *size, int x)
{
  if (pos == *size)
    {				// Array is full
      *size = *size * 2;
      array = (int *) realloc (array, *size * sizeof (int));
      if (array == NULL)
	{
	  return 0;
	}
    }
  array[pos] = x;
  pos++;
  return 1;
}

int
isOddRange (int *array, int *size, int low, int high)
{
  for (int x = low; x <= high; x++)
    {
      if (x % 2 != 0)
	{			// The number is odd
	  push (array, size, x);
	}
    }
}



int
main ()
{
  int *array;
  int size = 2;
  array = (int *) calloc (size, sizeof (int));
  isOddRange (array, &size, 3, 100);
  printf ("the size is %d\n", size);
  printArray (array, size);



  return 0;
}
