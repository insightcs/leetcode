#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX_LENGTH_INSERT_SORT 11

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

void swap(vector<int>& array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

/**
 * 三路快排
 * */
vector<int> partition3(vector<int>& array, int low, int high)
{
    srand((unsigned)time(nullptr));
    int random_num = rand() % (high-low+1)+low;
    int pivotkey = array[random_num];

    int lt = low - 1;   // array[low...lt] < pivotkey
    int gt = high + 1;  // array[gt...high] > pivotkey
    int pos = low;
    while(pos<gt)
    {
        if (array[pos] < pivotkey)
        {
            swap(array, pos++, ++lt);
        }
        else if (array[pos] > pivotkey)
        {
            swap(array, pos, --gt);
        }
        else
        {
            pos++;
        }
    }
    return vector<int>{lt, gt};
}


void quick_sort1(int *array, int low, int high)
{
    if(low<high)
    {
        int pivot = partition1(array, low, high);
        quick_sort1(array, low, pivot-1);
        quick_sort1(array, pivot+1, high);
    }
}

void quick_sort2(int *array, int low, int high)
{
    while(low<high)
    {
        int pivot = partition2(array, low, high);
        quick_sort2(array, low, pivot-1);
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
            quick_sort3(array, low, pivot-1);
            low = pivot + 1;
        }
    }
    else
    {
        //insert_sort(array, high-low);
    }
}

void quick_sort4(vector<int>& array, int low,  int high)
{
    if(low<high)
    {
        vector<int> pivot = partition3(array, low, high);
        quick_sort4(array, low, pivot[0]);
        quick_sort4(array, pivot[1], high);
    }
}

vector<int> generate_random_array(int n, int range_low, int range_high)
{
    vector<int> array(n);
    srand((unsigned)time(nullptr));
    for(int i=0;i<n;i++)
    {
        array[i] = rand() % (range_high-range_low+1) + range_low;
    }
    return array;
}


int main(int argc, char* argv[])
{
    vector<int> array = generate_random_array(10, 0, 5);
    cout << "before sort:" << endl;
    for(int i=0;i<10;i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    quick_sort4(array, 0, 9);
    cout << "after sort:" << endl;
    for(int i=0;i<10;i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    return 0;
}