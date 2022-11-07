#include <iostream>
#include <stdio.h>
using namespace std;

int a[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
// bước đi trên bàn cờ chiều ngang
int b[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
// bước đi trên bàn cờ chiều ngang

int **H; // mảng 2 chiều biểu diễn bàn cờ
int n;   // kích thước bàn cờ

void Try(int k, int x, int y, int &success)
{
    // Thu nước đi tiếp theo
    // Success = true nếu đi được
    int u, v, suc1;
    int i = 0;
    do
    {
        i++;
        suc1 = 0;
        u = x + a[i];
        v = y + b[i];
        if (1 <= u && u <= n && 1 <= v && v <= n && H[u][v] == 0)
        {
            H[u][v] = k;
            if (k < n * n)
            {
                Try(k + 1, u, v, suc1);
                if (!suc1)
                {
                    H[u][v] = 0;
                }
            }
            else
                suc1 = 1;
        }

    } while (!suc1 && (i < 8));
}

int main(int argc, char const *argv[])
{
    int x, y, suc;
    n = 5;
    H = new int *[n + 1];
    for (int i = 1; i <= n; i++)
        H[i] = new int[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            H[i][j] = 0;
    // Chọn nước đi đầu tiên
    x = 5;
    y = 1;
    H[x][y];

    // Thu tu nước đi thứ 2
    Try(2, x, y, suc);
    if (suc)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << H[i][j] << "\t";
            cout << endl;
        }
    }
    else
        cout << "Khong tim duoc duong di nao!";

    return 0;
}
