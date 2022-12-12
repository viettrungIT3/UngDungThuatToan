#include <bits/stdc++.h>
using namespace std;

int Fibo( int n)
{
    int a[n];
    a[0] = a[1] = 1;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i-1] + a[i-2];         
    }
    return a[n-1];
}

int main(int argc, char const *argv[])
{
    cout << Fibo(6);
    return 0;
}
