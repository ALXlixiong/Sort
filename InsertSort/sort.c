#include "sort.h"

//直接插入排序
//最优情况下时间复杂度O(N)
//一般情况下时间复杂度O(N2)

//void InsertSort(int arr[],int size)
//{
//  int i = 1;
//  for(;i<size;i++)
//  {
//    int key = arr[i];
//    int end = i-1;
//    while(end>=0 && key<arr[end])
//    {
//      arr[end+1] = arr[end];
//      end--;
//    }
//    arr[end+1] = key;
//  }
//}

//直接插入排序在手里面的已经有序了，所以我们可以用二分查找来找下一次需要插入的位置
void BinaryInsertSort(int arr[],int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    int key = arr[i];
    int right = i-1;
    int left = 0;
    int flag = 0;
    int mid = 0;
    while(left<=right)
    {
      mid = left + ((right-left)>>2);
      if(arr[mid]>key)
      {
        right = mid-1;
      }
      else if(arr[mid]<key)
      {
        left = mid+1;
      }
      else 
      {
        flag = 1;
        break;
      }
    }

    int end = i-1;
    while(end>right && flag == 0)
    {
      arr[end+1] = arr[end];
      end--;
    }

    while(end>mid && flag == 1)
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
  int arr[] = {2,4,6,22,0,1,7,1,8,9,0,3,5};
  int size = sizeof(arr)/sizeof(arr[0]);
  PrintSort(arr,size);
  BinaryInsertSort(arr,size);
  PrintSort(arr,size);
}
