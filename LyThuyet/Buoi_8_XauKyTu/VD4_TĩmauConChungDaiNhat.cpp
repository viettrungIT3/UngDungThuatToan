#include <bits/stdc++.h>
using namespace std;

// Cài đặt: sử dụng bẳng phương án là một mảng 2 chiều L[len(A)][len(B)] để lưu hàm QHĐ L[i][j];

char a[10] = {'a', 'a', 'b', 'c', 'd'};
char b[10] = {'a', 'a'};
int m = strlen(a);
int n = strlen(b);
int L[5][2];

void algorith()
{
    for (int i = 0; i < m; i++)
    {
        L[i][0] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        L[0][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
}