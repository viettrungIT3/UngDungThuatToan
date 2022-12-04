#include <bits/stdc++.h>
using namespace std;

float Tong(float a[], int l, int r)
{

    if (l == r)
    {
        return (a[l] > 0) ? a[l] : 0;
    }

    int m = (l + r) / 2;
    return Tong(a, l, m) + Tong(a, m + 1, r);
}

int main(int argc, char const *argv[])
{
    int n = 20;
    float a[n + 1];

    for (int i = 0; i < n; i++)
    {
        a[i] = (float)rand() / RAND_MAX * 100 - 50;
        cout << a[i] << " ";
    }
    cout << endl;

    cout << Tong(a, 0, n-1);

    return 0;
}
