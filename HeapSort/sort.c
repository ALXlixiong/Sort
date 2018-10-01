#include "sort.h"

//void SelectSort(int arr[],int size)
//{
//  int i = 0;
//  for(;i<size;i++)
//  {
//    int min = i+1;
//    int j = 0;
//    for(j = min;j<size;j++)
//    {
//      if(arr[j]<arr[min])
//        min = j;
//    }
//    if(arr[i]>arr[min]){
//      int tmp = arr[i];
//      arr[i] = arr[min];
//      arr[min] = tmp;
//    }
//  }
//}

//优化：一次排两个，最大和最小

void Swap(int *p1,int *p2)
{
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

//void SelectSort_op(int arr[],int size)
//{
//  int begin = 0;
//  int end = size-1;
//  while(begin<=end)
//  {
//    int maxPos = begin;
//    int minPos = begin;
//
//    int i = begin;
//    while(i<=end)
//    {
//      if(arr[i]>arr[maxPos])
//        maxPos = i;
//      if(arr[i]<arr[minPos])
//        minPos = i;
//      i++;
//    }
//    if(maxPos != end)
//    {
//      Swap(&arr[maxPos],&arr[end]);
//    }
//
//    //做小的元素可能在end位置，在进行最小元素交换时，
//    //可能又把最大值交换到最小位置处，所以在交换完
//    //要对minPos重标记
//    if(minPos == end)
//      minPos = maxPos;
//    
//    if(minPos != begin)
//    {
//      Swap(&arr[minPos],&arr[begin]);
//    }
//    begin++;
//    end--;
//  }
//}
//

//堆排序——升序——大堆
//降序——小堆
void HeapAdjust(int *arr,int size,int parent)
{
  //默认左孩子最大
  int max_child = (parent<<1)+1;
  
  while(max_child<size)
  {
    //找最大孩子，前提右孩子存在
    if(max_child+1<size && arr[max_child]<arr[max_child+1])
      max_child +=1;

    if(arr[parent]<arr[max_child])
    {
      Swap(&arr[parent],&arr[max_child]);
      parent = max_child;
      max_child = (parent<<1)+1;
    }
    else 
      return ;
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

//堆排序
void HeapSort(int *arr,int size)
{
  while(size>0)
  {
    Swap(&arr[0],&arr[size-1]);
    size--;
    HeapAdjust(arr,size,0);
  }
}

void Sorttest()
{
  int arr[] = {3,2,1,5,7,6,4,9,0,8};
  int size = sizeof(arr)/sizeof(int);
  int root = (size-2)>>1;
  for(;root>=0;root--)
  {
    HeapAdjust(arr,size,root);
  }

  PrintSort(arr,size);
  HeapSort(arr,size);
  PrintSort(arr,size);
}
