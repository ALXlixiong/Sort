#include "sort.h"



void Swap(int *p1,int *p2)
{
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void BubbleSort(int arr[],int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    int j = 0;
    int flag = 0;
    for(;j<size-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        flag = 1;
        Swap(&arr[j],&arr[j+1]);
      }
    }
    if(flag == 0)
      break;
  }
}

void PrintSort(int arr[],int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void Sorttest()
{
  int arr[] = {8,5,1,0,3,77,3,21,2,4,1,7,6,3};
  int size = sizeof(arr)/sizeof(int);

  PrintSort(arr,size);
  BubbleSort(arr,size);
  PrintSort(arr,size);
}
