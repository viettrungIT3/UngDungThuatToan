#include <bits/stdc++.h>
using namespace std;

long *d;

long fibonacci(int n)
{
    if (n < 3)
        d[n] = 1;
    else
        d[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return d[n];
}
int main()
{
    int n;
    cin >> n;
    d = new long[n + 1];
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << fibonacci(i) << " ";
        sum += fibonacci(i);
    }

    cout << "\n"
         << sum;

    // cout << fibonacci(n);
    return 0;
}