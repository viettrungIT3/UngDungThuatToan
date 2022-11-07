#include <bits/stdc++.h>
using namespace std;

int TongSoAmTrongMang(int a[], int n)
{
    if (n < 0)
        return 0;
    if (a[n] >= 0)
        return TongSoAmTrongMang(a, n - 1);
    return TongSoAmTrongMang(a, n - 1) + a[n];
}

int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    int sum = TongSoAmTrongMang(a, 5);
    if (sum == 0)
    {
        cout << "Mang khong co so am";
    } else
    {
        cout << sum;
    }
    
    
    return 0;
}
