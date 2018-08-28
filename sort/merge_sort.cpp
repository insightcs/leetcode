#include <iostream>
#include <vector>
using namespace std;

void merge_array(int *array, int start, int mid, int end, int *temp)
{
    int i = start, j = mid + 1;
    int k = 0;
    while(i<=mid&&j<=end)
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
    while(j<=end)
    {
        temp[k++] = array[j++];
    }
    for(i=0;i<k;i++)
    {
        array[i+start] = temp[i];
    }
}

void sort(int *array, int start, int end, int *temp)
{
    if(start<end)
    {
        int mid = (start + end) / 2;
        sort(array, start, mid, temp);
        sort(array, mid+1, end, temp);
        merge_array(array, start, mid, end, temp);
    }
}

/* time: O(nlogn)
 * memory: O(n+logn)*/
void merge_sort(int *array, int length)
{
    int *temp = new int[length] ();
    if (temp != nullptr)
    {
        sort(array, 0, length - 1, temp);
        delete[] temp;
    }
}
