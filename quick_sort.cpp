#include <iostream>
using namespace std;

void swap(int *array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

int partition1(int *array, int low, int high)
{
    int pivotkey = array[low];
    while(low<high)
    {
        if(low<high && array[high]>=pivotkey)
        {
            high--;
        }
        swap(array, low, high);
        if(low<high && array[low]<=pivotkey)
        {
            low--;
        }
        swap(array, low, high);
    }
    return low;
}

int partition2(int *array, int low, int high)
{
    int m = (low + high) / 2;
    if (array[low] > array[high])
    {
        swap(array, low, high);
    }
    if(array[m]>array[high])
    {
        swap(array, m, high);
    }
    if(array[m]>array[low]) // 交换使array[low]为中间值
    {
        swap(array, low, m);
    }

    int pivotkey = array[low];

    while(low<high)
    {
        while(low<high && array[high]>=pivotkey)   //从左向右找第一个比枢轴大的数
       {
            high--;
       }
       array[low] = array[high];
       while(low<high && array[low]<=pivotkey)   // 从右向左找第一个比枢轴小的数
       {
           low++;
       }
       array[high] = array[low];
    }
    array[low] = pivotkey;
    return low;
}

void quick_sort1(int *array, int low, int high)
{
    if(low<high)
    {
        int pivot = partition1(array, low, high);
        quick_sort(array, low, pivot-1);
        quick_sort(array, pivot+1, high);
    }
}

void quick_sort2(int *array, int low, int high)
{
    while(low<high)
    {
        int pivot = partition2(array, low, high);
        quick_sort(array, low, pivot-1);
        low = pivot + 1;    // 尾递归
    }
}



void quick_sort3(int *array, int low, int high)
{
    if(high-low>MAX_LENGTH_INSERT_SORT)
    {
        while(low<high)
        {
            int pivot = partition2(array, low, high);
            quick_sort1(array, low, pivot-1);
            low = pivot + 1;
        }
    }
    else
    {
        insert_sort(array);
    }
}