/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //implementing a searching algorithm
  int low=0;
  int high=n-1;
  
  while(low <= high)
  {
    int mid = low + (high - low) / 2;
  if(value==values[mid])
    return true;
  else if(value>values[mid])
  {
      low=mid+1;
  }
  else
  {
      high=mid-1;
  }
  }
return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
     for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            {
                if(values[i]>values[j])
                {
                    int temp=values[i];
                    values[i]=values[j];
                    values[j]=temp;
                }
            }
    }
    return;
}
