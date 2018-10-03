#include "sort.h"


void MergeData(int arr[],int left,int mid,int right,int *temp)
{
  //左闭右开[)
  int begin1 = left,end1 = mid;
  int begin2 = mid,end2 = right;
  int index = left;
  while(begin1<end1 && begin2<end2)
  {
    if(arr[begin1]<arr[begin2])
      temp[index++] = arr[begin1++];
    else 
      temp[index++] = arr[begin2++];
  }

  while(begin1<end1)
    temp[index++] = arr[begin1++];
  while(begin2<end2)
    temp[index++] = arr[begin2++];
}

void _MergeSort(int arr[],int left,int right,int *temp)
{
  if((right-left)>1)
  {
    //分组
    int mid = left +((right-left)>>1);
    _MergeSort(arr,left,mid,temp);
    _MergeSort(arr,mid,right,temp);
    //归并
    MergeData(arr,left,mid,right,temp);
    memcpy(arr+left,temp+left,(right-left)*sizeof(int));
  }
}

//封装
void MergeSort(int arr[],int size)
{
  int *temp = (int *)malloc(sizeof(int)*size);
  assert(temp);
  _MergeSort(arr,0,size,temp);
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
  MergeSort(arr,size);
  PrintSort(arr,size);
}
