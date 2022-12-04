#include <bits/stdc++.h>
using namespace std;

int Min(int a[], int l, int r)
{
    if (l == r)
    {
        return (a[l] % 2 == 0) ? a[l] : INT_MAX;
    }

    int m = (l + r) / 2;
    return (Min(a, l, m) < Min(a, m + 1, r)) ? Min(a, l, m) : Min(a, m + 1, r);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL)); 
    int n = 100;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 200 - 100;
        cout << a[i] << " " << endl;
    }

    cout << endl;
    cout << Min(a, 0, n - 1) << endl;
    return 0;
}
