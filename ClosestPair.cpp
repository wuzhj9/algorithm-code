/***
 * 寻找平面内最接近点对
 ***/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

struct Point
{
    float x;
    float y;
    Point(float x=0, float y=0) : x(x), y(y) {}
};

struct A_Point
{
    float x;
    float y;
    int index;
    A_Point(float x=0, float y=0, int i=0) : x(x), y(y), index(i) {}
};

float Dist(Point a, Point b)
{
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool CmpX(Point a, Point b)
{
    return a.x < b.x;
}

bool CmpY(A_Point a, A_Point b)
{
    return a.y < b.y;
}

void Closest(Point X[], A_Point Y[], int low, int high, Point &a, Point &b, float &d)
{
    int m, j, k;
    float dl, dr;
    Point al, bl, ar, br;
    if (high - low == 1)
    {
        a = X[low];
        b = X[high];
        d = Dist(a, b);
    }
    else if (high - low == 2)
    {
        dl = Dist(X[low], X[low+1]);
        dr = Dist(X[low+1], X[low+2]);
        d = Dist(X[low], X[low+2]);
        if (dl <= dr && dl <= d)
        {
            d = dl;
            a = X[low];
            b = X[low+1];
        }
        else if (dr <= d)
        {
            d = dr;
            a = X[low+1];
            b = X[low+2];
        }
        else
        {
            a = X[low];
            b = X[low+2];
        }
    }
    else
    {
        m = low + (high-low)/2;
        A_Point * SL = new A_Point[m-low+1];
        A_Point * SR = new A_Point[high-m];
        j = k = 0;
        for (int i = 0; i < (high - low + 1); i++)
        {
            if (Y[i].index <= m)
                SL[j++] = Y[i];
            else
                SR[k++] = Y[i];
        }
        Closest(X, SL, low, m, al, bl, dl);
        Closest(X, SR, m+1, high, ar, br, dr);
        if (dl < dr)
        {
            a = al;
            b = bl;
            d = dl;
        }
        else
        {
            a = ar;
            b = br;
            d = dr;
        }
        Point * Z = new Point[high-low+1];
        j = 0;
        for (int i = 0; i < (high-low+1); i++)
        {
            if (abs(X[m].x - Y[i].x) < d)
            {
                Z[j].x = Y[i].x;
                Z[j++].y = Y[i].y;
            } 
        }
        for (int i = 0; i < j; i++)
        {
            for (int k = i+1; k < j && Z[k].y - Z[i].y < d; j++)
            {
                dl = Dist(Z[i], Z[k]);
                if (dl < d)
                {
                    a = Z[i];
                    b = Z[k];
                    d = dl;
                }
            }
        }
        delete [] SL;
        delete [] SR;
        delete [] Z;
    }
}

void ClosestPair(Point X[], int n, Point &a, Point &b, float &d)
{
    if (n < 2)
        d = 0;
    else
    {
        sort(X, X+n, CmpX);
        A_Point * Y = new A_Point[n];
        for (int i = 0; i < n; i++)
        {
            Y[i].x = X[i].x;
            Y[i].y = X[i].y;
            Y[i].index = i;
        }
        sort(Y, Y+n, CmpY);
        Closest(X, Y, 0, n-1, a, b, d);
        delete [] Y;
    }
}

int main()
{
    int n;
    Point a, b;
    float d;

    cout << "Input the num of points: ";
    while (cin >> n)
    {
        if (n == 0)
            break;
        Point * points = new Point[n];
        srand(unsigned(time(NULL)));
        cout << "The points as follow:\n";
        for (int i = 0; i < n; i++)
        {
            points[i].x = (rand()%20000)/100-100;
            points[i].y = (rand()%20000)/100-100;
            cout << "(" << points[i].x << "," << points[i].y << ")\n";
        }
        ClosestPair(points, n, a, b, d);
        cout << "The closest point is: "
             << "(" << a.x << "," << a.y << "), "
             << "(" << b.x << "," << b.y << ")\n";
        cout << "The distance is: " << sqrt(d) << endl;
        delete [] points;
    }
    return 0;
}