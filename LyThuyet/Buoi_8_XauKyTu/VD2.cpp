#include <bits/stdc++.h>
using namespace std;

// Bài toán 2: cho 2 xâu lý tự T và P chỉ gồm các ký tự {'0' .. '9', 'a' .. 'z', 'A' .. 'Z'}
// Yêu cầu: Kiêm tra xem P có phải là một xâu con của T hay không?
// Phương pháp đơn gian: Sử dụng thuật toán lặp

int IndexOf(const char *p, const char *t)
{
    int m = strlen(p);
    int n = strlen(t) - m;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < m && t[i + j] == p[j])
        {
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char p[100] = {'T', 'r', 'u', 'o', 'n', 'g', ' ', 'D', 'a', 'i', ' ', 'H', 'o', 'c', ' ', 'C', 'N', 'H', 'N'};
    char t[10] = {'T', 'r'};
    cout << IndexOf(p, t);
    return 0;
}
