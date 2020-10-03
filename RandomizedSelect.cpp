/***************************************************
 * 利用快排的随机划分思想来选择第k小元素
 ***************************************************/

#include <iostream>
#include <ctime>

using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int RandomizedPartition(int * a, int start, int end)
{
    int i, j;
    srand(int(time(0)));
    i = rand()%(end-start+1) + start;
    Swap(a[start], a[i]);
    i = start;
    j = start+1;
    while (j <= end)
    {
        if (a[j] <= a[start])
        {
            i++;
            Swap(a[i], a[j]);
        }
        j++;
    }
    Swap(a[i], a[start]);
    return i;
}

int RandomizedSelect(int * a, int start, int end, int k)
{
    if (start == end)
        return a[start];
    int pivot = RandomizedPartition(a, start, end);
    int j = pivot - start + 1;
    if (j == k)
        return a[pivot];
    else if (j > k)
        return RandomizedSelect(a, start, pivot-1, k);
    else
        return RandomizedSelect(a, pivot+1, end, k-j);
}

void QuickSort(int * a, int start, int end)
{
    if (start >= end)
        return;
    int i = RandomizedPartition(a, start, end);
    QuickSort(a, start, i-1);
    QuickSort(a, i+1, end);
}

int main()
{
    int n, k, * a, *b;
    cout << "Input the number of integer: ";
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << "Input k: ";
        cin >> k;
        a = new int[n];
        b = new int[n];
        srand(int(time(0)));
        for (int i = 0; i < n; i++)
        {
            a[i] = rand();
            b[i] = a[i];
            cout << a[i] << " ";
        }
        cout << endl;
        QuickSort(a, 0, n-1);
        cout << "The kth of QuickSort: ";
        cout << a[k-1] << endl;
        cout << "The kth of RandomizedSelect: ";
        cout << RandomizedSelect(b, 0, n-1, k) << endl;
        delete [] a;
        delete [] b;
        cout << "Input the number of integer: ";
    }
    return 0;
}