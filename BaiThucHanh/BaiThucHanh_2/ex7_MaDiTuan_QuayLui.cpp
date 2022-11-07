#include <bits/stdc++.h>
using namespace std;

// Bài tập 7: Cài đặt bài toán mã đi tuần theo phương pháp quay lui

int a[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2}; // Bước đi trên bàn cờ theo chiều ngang
int b[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1}; // Bước đi tên bàn cờ theo chiều dọc
int **H;    // Mảng 2 chiều trên bàn cờ
int n;      // Kích thước bàn cờ
void Try(int k, int x, int y, int &success)
{
    int u, v, suc1, i = 0;
    do
    {
        i++;
        suc1 = 0;
        u = x + a[i];
        v = y + b[i];
        if (1 <= u && u <= n && 1 <= v && v <= n && H[u][v] == 0)
        {
            H[u][v] = k;
            if (k < n * n)  // Chưa hết các ô trên bàn cờ
            {
                Try(k + 1, u, v, suc1);
                if (!suc1)
                    H[u][v] = 0;
            }
            else
                suc1 = 1;
        }
    } while (!suc1 && (i < 8));
    success = suc1;
}
int main()
{
    int x, y, suc;

    // Khởi tạo bàn cờ
    n = 5;
    H = new int *[n + 1];
    for (int i = 1; i <= n; i++)
        H[i] = new int[n + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            H[i][j] = 0;

    // Chọn nước đi đầu tiền
    x = 1;
    y = 1;
    H[x][y] = 1;

    // Thứ tự nước đi thứ 2
    Try(2, x, y, suc);
    if (suc)
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << setw(3) << left << H[i][j];
            cout << endl;
        }
    else
        cout << "Khong tim thay nuoc di";
    return 0;
}
