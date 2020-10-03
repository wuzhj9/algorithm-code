#include <iostream>
#include <ctime>

using namespace std;

int RandomizedPartition(int * a, int start, int end)
{
    int i, j, temp;
    srand(int(time(0)));
    i =  rand()%(end-start+1) + start;
    cout << i << endl;
    temp = a[i];
    a[i] = a[start];
    a[start] = temp;
    i = start+1;
    j = end;
    while (true)
    {
        while(a[j] > a[start]) j--;
        while(i < j && a[i] <= a[start]) i++;
        if (i >= j) break;
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    temp = a[j];
    a[j] = a[start];
    a[start] = temp;
    return j;
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