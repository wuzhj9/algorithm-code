/***************************************************
 * 快排中随机划分的另一种方法
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
    int n, * a;
    while (cin >> n)
    {
        if (n == 0)
            break;
        a = new int[n];
        srand(int(time(0)));
        for (int i = 0; i < n; i++)
        {
            a[i] = rand();
            cout << a[i] << " ";
        }
        cout << endl;
        QuickSort(a, 0, n-1);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        delete [] a;
    }
    return 0;
}