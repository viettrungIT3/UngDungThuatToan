#include <bits/stdc++.h>
using namespace std;

// Tim phan tu luon nhat cua trong day bang phuong phap chia de tri

int TimMax(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        int m1 = TimMax(a, l, m);
        int m2 = TimMax(a, m+1, r);
        if (m1 > m2)
            return m1;
        else 
            return m2;
    }
    return a[l];
}

int main(int argc, char const *argv[])
{
    int a[10] = {1, 3, 4, 9, 6, 7, 5, 4};
    cout << TimMax(a, 0, 9);
    return 0;
}
