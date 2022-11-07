#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> n >> m;
    int a[m + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = n + rand() % (m - n + 1);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
