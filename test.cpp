#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubble_sort(vector<int>& array)
{
    int n = array.size();
    bool flag = true;
    for(int i=0;i<n && flag;i++)
    {
        flag = false;
        for(int j=n-2;j>=i;j--)
        {
            if(array[j+1]<array[j])
            {
                flag = true;
                swap(array[j],array[j+1]);
            }
        }
    }
}

void select_sort(vector<int>& array)
{
    int n = array.size();
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(array[j]<array[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            swap(array[min], array[i]);
        }
    }
}

void insert_sort(vector<int>& array)
{
    int n = array.size();
    for(int i=1;i<n;i++)
    {
        if(array[i-1]>array[i])
        {
            int temp = array[i];
            int j = i-1;
            for(;j>=0&&array[j]>temp;j--)
            {
                array[j+1] = array[j];
            }
            array[j+1] = temp;
        }
    }
}

void shell_sort(vector<int>& array)
{
    int n = array.size();
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int j=gap;j<n;j++)
        {
            if(array[j-gap]>array[j])
            {
                int temp = array[j];
                int k = j - gap;
                for(;k>=0&&array[k]>temp;k--)
                {
                    array[k+gap] = array[k];
                }
                array[k+gap] = temp;
            }
        }
    }
}

void adjust_heap(vector<int>& array, int s, int n)
{
    int i = 2 * s + 1;
    int temp = array[s];
    while(i<n)
    {
        if(i+1<n && array[i+1]>array[i])
        {
            i++;
        }
        if(temp>=array[i])
        {
            break;
        }
        array[s] = array[i];
        s = i;
        i = 2 * s + 1;
    }
    array[s] = temp;
}

void heap_sort(vector<int>& array)
{
    int n = array.size();
    for(int i=n/2-1;i>=0;i--)
    {
        adjust_heap(array, i, n);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(array[0], array[i]);
        adjust_heap(array, 0, i);
    }
}

void merge_sorted_array(vector<int>& array, int left, int mid, int right, vector<int>& temp)
{
    int k = 0;
    int i = left, j = mid + 1;
    while (i<=mid && j<=right)
    {
        if(array[i]<array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++] = array[i++];
    }
    while(j<=right)
    {
        temp[k++] = array[j++];
    }
    for(int i=0;i<k;i++)
    {
        array[i+left] = temp[i];
    }
}

void merge_sort(vector<int>& array, int left, int right, vector<int>& temp)
{
    if(left<right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid, temp);
        merge_sort(array, mid+1, right, temp);
        merge_sorted_array(array, left, mid, right, temp);
    }
}

int partition1(vector<int>& array, int left, int right)
{
    int pivot = array[left];
    while(left<right)
    {
        while(left<right && array[right]>=pivot)
        {
            right--;
        }
        array[left] = array[right];
        while(left<right && array[left]<=pivot)
        {
            left++;
        }
        array[right] = array[left];
    }
    array[left] = pivot;
    return left;
}

vector<int> partition2(vector<int>& array, int left, int right)
{
    int lt = left -1 , gt = right + 1;// array[left...lt] < pivot   array[gt...right] > pivot
    int pos = left;
    int pivot = array[left];
    while(pos<gt)
    {
        if(array[pos]<pivot)
        {
            swap(array[pos++], array[++lt]);
        }
        else if(array[pos]>pivot)
        {
            swap(array[pos], array[--gt]);
        }
        else
        {
            pos++;
        }
    }
    return {lt, gt};
}

void quick_sort(vector<int>& array, int left, int right)
{
    if(left<right)
    {
        int pivot = partition1(array, left, right);
        quick_sort(array, left, pivot-1);
        quick_sort(array, pivot+1, right);
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
    vector<int> array = generate_random_array(10, 0, 10);
    //vector<int> temp(array.size());
    quick_sort(array, 0, array.size()-1);
    return 0;
}