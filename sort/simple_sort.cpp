#include <iostream>
#include <vector>
using namespace std;

void swap(int *array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

void bubble_sort1(int *array, int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(array[i]>array[j])
            {
                swap(array, i, j);
            }
        }
    }
}

void bubble_sort2(int *array, int length)
{
    for(int i=0;i<length;i++)
    {
        for(j=length-2;j>=i;j--)
        {
            if(array[j+1]<array[j])
            {
                swap(array, j, j+1);
            }
        }
    }
}

void bubble_sort3(int *array, int length)
{
    bool flag = true;
    for(int i=0;i<length&&flag;i++)
    {
        flag = false;
        for(int j=length-2;j>=i;j--)
        {
            if(array[j+1]<array[j])
            {
                swap(array, j, j+1);
                flag = true;
            }
        }
    }
}

void select_sort(int *array, int length)
{
    for(int i=0;i<length;i++)
    {
        int min = i;
        for(int j=i+1;j<length;j++)
        {
            if(array[j]<array[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            swap(array, i, min);
        }
    }
}

void insert_sort(int *array, int length)
{
    for(int i=1;i<length;i++)
    {
        if(array[i-1]>array[i])
        {
            int temp = array[i];
            for(int j=i-1;array[j]>temp;j--)
            {
                array[j+1] = array[j];
            }
            array[j+1] = temp;
        }
    }
}

void shell_sort(int *array, int length)
{
    for(int gap=length/2;gap>0;gap/=2)
    {
        for(int i=gap;i<length;i++)
        {
            if(array[i]<array[i-gap])
            {
                int temp = array[i];
                for(int j=i-gap;j>=0&&array[j]>temp;j-=gap)
                {
                    array[j+gap] = array[j];
                }
                array[j+gap] = temp;
            }
        }
    }
}

