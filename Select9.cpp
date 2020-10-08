/*********************************************
 * 线性时间选择第k个元素（按5个一组分）
 *********************************************/

#include <iostream>
#include <ctime>

using namespace std;

template<class Type>
void Swap(Type &a, Type &b)
{
    Type temp = a;
    a = b;
    b = temp;
}

template<class Type>
int RandomizedPartition(Type * a, int start, int end)
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

template<class Type>
void QuickSort(Type * a, int start, int end)
{
    if (start >= end)
        return;
    int i = RandomizedPartition(a, start, end);
    QuickSort(a, start, i-1);
    QuickSort(a, i+1, end);
}

template<class Type>
void MySort(Type * a, int start, int num)
{
    for (int i = 0; i <= num/2; i++)
    {
        for (int j = start+num-1; j > start+i; j--)
        {
            if (a[j] < a[j-1])
                Swap(a[j], a[j-1]);
        }
    }
}

template<class Type>
void Partition(Type * a, int start, int end, Type pivot, int &i, int &j)
{
    int k = start;
    i = start-1;
    j = start-1;
    while (k <= end)
    {
        if (a[k] < pivot)
        {
            j++;
            Swap(a[j], a[k]);
            i++;
            Swap(a[i], a[j]);
        }
        else if (a[k] == pivot)
        {
            j++;
            Swap(a[j], a[k]);
        }
        k++;
    }
}

template<class Type>
Type Select(Type * a, int start, int end, int k)
{
    if (end - start < 242)
    {
        QuickSort(a, start, end);
        return a[start+k-1];
    }
    for (int i = 0; i < (end-start+1)/9; i++)
    {
        MySort(a, start+9*i, 9);
        Swap(a[start+i], a[start+9*i+4]);
    }
    Type pivot = Select(a, start, start+(end-start+1)/9-1, (end-start+1)/18);
    int s, m;
    Partition(a, start, end, pivot, s, m);
    int j = s - start + 1;
    if (k <= j) 
        return Select(a, start, s, k);
    else if (k <= m - start + 1)
        return pivot;
    else
        return Select(a, m+1, end, k-(m - start + 1)); 
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
            //cout << a[i] << " ";
        }
        //cout << endl;
        QuickSort(a, 0, n-1);
        cout << "The kth of QuickSort algorithm: ";
        cout << a[k-1] << endl;
        cout << "The kth of Select algorithm: ";
        cout << Select(b, 0, n-1, k) << endl;
        delete [] a;
        delete [] b;
        cout << "Input the number of integer: ";
    }
    return 0;
}
