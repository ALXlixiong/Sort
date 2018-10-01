#include "sort.h"

//直接插入排序
//最优情况下时间复杂度O(N)
//一般情况下时间复杂度O(N2)

void InsertSort(int arr[],int size)
{
  int i = 1;
  for(;i<size;i++)
  {
    int key = arr[i];
    int end = i-1;
    while(end>=0 && key<arr[end])
    {
      arr[end+1] = arr[end];
      end--;
    }
    arr[end+1] = key;
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
  int arr[] = {2,4,6,7,1,8,9,0,3,5};
  int size = sizeof(arr)/sizeof(arr[0]);
  PrintSort(arr,size);
  InsertSort(arr,size);
  PrintSort(arr,size);
}
