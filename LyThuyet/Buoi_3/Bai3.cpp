#include <bits/stdc++.h>
using namespace std;

long Tong_DeQuy(long n)
{
    if (n < 10)
    {
        return n;
    }
    return n % 10 + Tong_DeQuy(n / 10);
}

long Tong_Lap(int n)
{
    long sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    long n;
    cin >> n;
    cout << Tong_DeQuy(n) << endl;
    cout << Tong_Lap(n);
    return 0;
}
