#include <iostream>
using namespace std;

// Bài tập 5: Cài đặt bài toán sinh dãy nhị phân theo phương pháp quay lui

int n, x[100];

void show(int x[])
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        x[k] = i;
        if (k == n)
            show(x);
        else
            Try(k + 1);
    }
}

int main(int argc, char const *argv[])
{
    n = 5;
    Try(1);
    return 0;
}
