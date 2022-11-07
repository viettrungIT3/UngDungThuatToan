#include <iostream>
using namespace std;

// Bài tập 8: Cài đặt bài toán tám hậu theo phương pháp quay lui

int a[20];

bool Safety(int k, int i)
{
    for (int j = 1; j < k; j++)
        if (a[j] == i || abs(j - k) == abs(a[j] - i))
            return false;
    return true;
}

void view(int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}

void Try(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (Safety(k, i))
        {
            a[k] = i;
            if (k == n)
                view(n);
            else
                Try(k + 1, n);
        }
    }
}
int main()
{
    int n = 8;
    Try(1, n);
    return 0;
}
