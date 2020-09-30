#include <iostream>

using namespace std;

void PrintBrace(int n, int left, int right, string s)
{
    if (left == n && right == n)
    {
        cout << s << endl;
        return;
    }
    if (left < n)
        PrintBrace(n, left+1, right, s+"(");
    if (right < left && right < n)
        PrintBrace(n, left, right+1, s+")");
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        PrintBrace(n, 0, 0, "");
    }
    return 0;
}