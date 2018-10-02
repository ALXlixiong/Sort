#include "sort.h"

int GetMiddleIndex(int arr[],int left,int right)
{
  int mid = left +((right-left)>>1);
  if(arr[left]<arr[right])
  {
    if(arr[mid]<arr[left])
      return left;
    else if(arr[mid]>arr[right])
      return right;
    else 
    {
      return mid;
    }
  }
  else 
  {
    if(arr[mid]>arr[left])
      return left;
    else if(arr[mid]<arr[right])
      return right;
    else 
      return mid;
  }
}

void Swap(int *p1,int *p2)
{
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

//前后指针法
int Partion1(int arr[],int left,int right)
{
  //[)左闭右开
  //找基准值i(优化找基准值)
  int mid = GetMiddleIndex(arr,left,right);
  if(mid != right-1)
    Swap(&arr[mid],&arr[right-1]);
  int key = arr[right-1];
  int start = left;
  int end = right-1;
  while(start<end)
  {
    //从左往右找比基准值大的元素
    while(start<end && arr[start]<=key)
    {
      start++;
    }
    //从右往左找比基准值小的元素
    while(start < end &&arr[end]>=key)
    {
      end--;
    }

    if(start<end)
      Swap(&arr[start],&arr[end]);

  }
  if(start != right-1)
    Swap(&arr[start],&arr[right-1]);//注：此处不可以和key交换
  return start;
}







//挖坑法
int Partion2(int arr[],int left,int right)
{
  //找基准值（优化）
  int mid = GetMiddleIndex(arr,left,right);
  if(mid != right-1)
    Swap(&arr[mid],&arr[right-1]);
  int key = arr[right-1];//刚开始key的位置就是坑
  int start = left;
  int end = right-1;

  while(start<end)
  {
    //从左往右找比基准值大的元素，填坑
    while(start<end && arr[start]<=key)
    {
      start++;
    }
    if(start<end)
    {
      arr[end] = arr[start];
      end--;
    }
    //从右往左找比基准值小的元素，填坑
    while(start<end && arr[end]>=key)
    {
      end--;
    }

    if(start<end)
    {
      arr[start] = arr[end];
      start++;
    }
  }
  arr[start] = key;//相遇填补最后一个坑
  return start;
}


//前后指针
  

int Partion3(int arr[],int left,int right)
{
  int mid = GetMiddleIndex(arr,left,right);
  if(mid != right-1)
    Swap(&arr[mid],&arr[right-1]);
  int key = arr[right-1];
  int cur = left;
  int pre = cur-1;

  while(cur<right)
  {
    if(arr[cur]<key && ++pre != cur)
      Swap(&arr[pre],&arr[cur]);

    ++cur;
  }
  if(++pre != right-1)
    Swap(&arr[pre],&arr[right-1]);
  return pre;
}


void QuickSort(int arr[],int left,int right)
{
  if((right-left)>1)
  {
    //左闭右开
    int boundary = Partion3(arr,left,right);
    QuickSort(arr,left,boundary);
    QuickSort(arr,boundary+1,right);
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
  int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
  //int arr[] = {2,4,1};
  int size = sizeof(arr)/sizeof(int);

  PrintSort(arr,size);
  QuickSort(arr,0,size);
  PrintSort(arr,size);
}
