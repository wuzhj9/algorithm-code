/***
 * given n, print the legal combination of n pairs of brackets
 ***/

#include <iostream>

using namespace std;

void PrintBrack(int n, int left, int right, string s)
{
    if (left == n && right == n)
    {
        cout << s << endl;
        return;
    }
    if (left < n)
        PrintBrack(n, left+1, right, s+"(");
    if (right < left && right < n)
        PrintBrack(n, left, right+1, s+")");
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        PrintBrack(n, 0, 0, "");
    }
    return 0;
}