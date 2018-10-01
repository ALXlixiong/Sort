#include "sort.h"

void SelectSort(int arr[],int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    int min = i+1;
    int j = 0;
    for(j = min;j<size;j++)
    {
      if(arr[j]<arr[min])
        min = j;
    }
    if(arr[i]>arr[min]){
      int tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
    }
  }
}

//优化：一次排两个，最大和最小

void Swap(int *p1,int *p2)
{
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void SelectSort_op(int arr[],int size)
{
  int begin = 0;
  int end = size-1;
  while(begin<=end)
  {
    int maxPos = begin;
    int minPos = begin;

    int i = begin;
    while(i<=end)
    {
      if(arr[i]>arr[maxPos])
        maxPos = i;
      if(arr[i]<arr[minPos])
        minPos = i;
      i++;
    }
    if(maxPos != end)
    {
      Swap(&arr[maxPos],&arr[end]);
    }

    //做小的元素可能在end位置，在进行最小元素交换时，
    //可能又把最大值交换到最小位置处，所以在交换完
    //要对minPos重标记
    if(minPos == end)
      minPos = maxPos;
    
    if(minPos != begin)
    {
      Swap(&arr[minPos],&arr[begin]);
    }
    begin++;
    end--;
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
  SelectSort_op(arr,size);
  PrintSort(arr,size);
}
