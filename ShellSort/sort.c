#include "sort.h"

//希尔排序
//数据量比较大——不是接近有序
//利用插入排序的思想排序
//取步长step将数据量变小，使得接近有序
//接近有序：小的在左，不大不小的中间，大的右边


//时间复杂度：N^1.25—1.6N^1.25
//空间复杂度O(1)
void ShellSort(int arr[],int size)
{
  int step = size;
  //step/=2
  //step取奇数
  //step取素数
  //*******step = step/3 + 1********最优
  while(step>1)
  {
   step = step/3+1;
   int i = step;
   for(;i<size;i++)
   {
     int key = arr[i];
     int end = i-step;
     while(end>=0 && key<arr[end])
     {
       arr[end+step] = arr[end];
       end -= step;
     }
     arr[end+step] = key;
   }
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
  ShellSort(arr,size);
  PrintSort(arr,size);
}
