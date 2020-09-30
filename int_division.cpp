#include <iostream>
#include <string>

using namespace std;

int IntDivision(int n, int m, string s)
{
    if (n == 1)
    {
    	if (s == "")
    		cout << "1" << endl;
    	else
        	cout << s+"+1" << endl;
        return 1;
    }
    if (m == 1)
    {
    	if (s == "")
    		return IntDivision(n-m, m, "1");
    	else
        	return IntDivision(n-m, m, s+"+1");
    }
    if (m >= n)
    {
    	if (s == "")
    		cout << to_string(n) << endl;
    	else
        	cout << s+"+"+to_string(n) << endl;
        return 1 + IntDivision(n, n-1, s);
    }
    else
    {
    	if (s == "")
    		return IntDivision(n-m, m, to_string(m)) + IntDivision(n, m-1, s);
    	else
    		return IntDivision(n-m, m, s+"+"+to_string(m)) + IntDivision(n, m-1, s);
	}
}

int main()
{
    int n, num;
    cout << "Input num: ";
    while (cin >> n)
    {
        if (n == 0)
            break;
        num = IntDivision(n, n, "");
        cout << "The number of division: " << num << endl;
        cout << "Input num: ";
    }
    return 0;
}