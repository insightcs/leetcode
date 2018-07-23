#include <iostream>
using namespace std;

void swap(int *array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

void heap_adjust(int *array, int s, int n)
{
    int temp = array[s];
    int i = 2 * s + 1;
    while(i<n)
    {
        if(i+1<n && array[i]<array[i+1])   // 找到较大的子节点
        {
            i++;
        }
        if(temp>=array[i])
        {
            break;
        }
        array[s] = array[i];    // 较大的子节点上移
        s = i;
        i = 2 * s + 1;
    }
    array[s] = temp;
}

/* time: O(nlogn)
 * memory: O(1) */
void heap_sort(int *array, int length)
{
    for(int i=length/2-1;i>=0;i--)   // 建立大顶堆
    {
        heap_adjust(array, i, length);
    }
    for(int i=length-1;i>0;i--)
    {
        swap(array, 0, i);          // 删除根节点
        heap_adjust(array, 0, i);   // 余下的节点构成大顶堆
    }
}
