#include<iostream>
using namespace std;

void insertSort(int a[], int length)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    for(i = 1 ; i < length; i++)
    {
        tmp = a[i];
        j = i - 1;
        
        while(j >= 0 && tmp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = tmp;
    }
}

void bubbleSort(int a[], int length)
{
    bool flag = false;
    for(int i = length - 1; i > 0; i--)
    {
        flag = false;
        for(int j = 0; j < i; j++)
        if(a[j] > a[j + 1])
        {
            flag = false;
            int tmp = a[j + 1];
            a[j + 1] = a[j];
            a[i] = tmp;
        }

        if(flag)
        return;
    }
}

void quickSort(int a[], int length)
{
    quickSort(a, 0, length - 1);
}

void quickSort(int a[], int left, int right)
{
    if(left == right)
    return;
    
    int key = a[left];
    int pos = partition(a, left, right);
    a[pos] = key;

    quickSort(a, left, pos - 1);
    quickSort(a, pos + 1, right);
}

int partition(int a[], int left, int right)
{
    int key = a[left];

    while(left < right)
    {
        while(left < right && a[right] >= key)
        {
            right--;
        }
        a[left] = a[right];
        while(left < right && a[left] <= key)
        {
            left++;
        }
        a[left] = a[right];
    }

    a[left] = key;
    return left;
}

pair<int, int> partition(int a[], int left, int right)
{
    int pos1 = left;
    int pos2 = right;
    int key1 = a[left];
    int key2 = a[right];

    while(key1 == key2 && right > left)
    {
        right--;
        key2 = a[right];
    }

    if(left == right)
    return make_pair(pos1, pos2);
    
    if(key1 > key2)
    swap(key1, key2);

    swap(a[right], a[pos2]);
    left = ++pos1;
    right = --pos2;
}

void simpleSelectSort(int a[], int length)
{
    int val = 0;
    int pos = 0;
    for(int i = 0; i < length; i++)
    {
        val = a[i];
        pos = i;

        for(j = i + 1; j < length; j++)
        {
            if(a[j] < val)
            {
                val = a[j];
                pos = j;
            }
        }

        swap(a[i], a[pos]);
    }
}

void minHeapSort(int a[], int length)
{
    int tmp;
    for(int i = length - 1; i > 0; i--)
    {
        tmp = a[i];
        a[i] = tmp;
        a[0] = tmp;
        minHeapFixdown(a, 0, i);
    }
}

void minHeap(int a[], int length)
{
    for(int i = length / 2 - 1; i >= 0; i--)
    {
        minHeapFixdown(a, i, n);
    }
}

void minHeapFixdown(int a[], int i, int n)
{
    int tmp = a[i];
    int j = 2 * j + 1;
    
    while(j < n)
    {
        if(j + 1 < n && a[j + 1] < a[j])
        j++;
        if(a[j] >= tmp)
        break;

        a[i] = a[j];
        i = j;
        j = 2 * j + 1; 
    }

    a[i] = tmp;
}

void mergeSort(int a[], int length)
{
    int *p = new int[length];
    mergeSort(a, 0, length - 1, p);
    delete[] p;
}

void mergeSort(int a[], int first, int last, int temp[])
{
    if(first == last)
    return;

    int mid = (first + last) / 2;
    mergeSort(a, first, mid, temp);
    mergeSort(a, mid + 1, last, temp);
    merge(a, first, mid, last, temp);
}

void merge(int a[], int first,int mid, int last, int temp[])
{
    int i = first;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j<= last)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while(j <= last)
    {
        temp[k] = a[j];
        k++;
        i++;
    }

    for(int i = 0; i < k; i++)
    {
        a[first + i] = temp[i];
    }
}

int main()
{
    
    return 0;
}
