#include <bits/stdc++.h>
using namespace std;

int TKNP_DQ(int a[], int n, int c)
{
    int L = 0, R = n - 1, M;
    do
    {
        M = (L + R) / 2;
        if (a[M] > c)
            R = M - 1;
        if (a[M] < c)
            L = M - 1;
    } while (a[M] != c && L < R);
    if (a[M] == c)
        return M;
    return -1;
}

int main(int argc, char const *argv[])
{
    int a[10] = {1, 3, 4, 5, 7, 8, 9, 10, 12};
    int c = 10;
    int n = 10;

    cout << TKNP_DQ(a, n, c);
    return 0;
}
