#include <bits/stdc++.h>
using namespace std;

// Bài tập 8: Cài đặt chương trình cho bài toán tìm miền liên thông (trong slide).

int arr[5][6] = {{1, 1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 1, 1, 0},
                 {0, 1, 1, 0, 0, 1},
                 {0, 0, 1, 0, 1, 1}};
bool flag[5][6];
int so_mien;

void loang(int i, int j)
{
    flag[i][j] = true;
    if (i > 0 && (arr[i - 1][j] == arr[i][j]) && (!flag[i - 1][j]))
        loang(i - 1, j);
    if (i < 4 && (arr[i + 1][j] == arr[i][j]) && (!flag[i + 1][j]))
        loang(i + 1, j);
    if (j > 0 && (arr[i][j - 1] == arr[i][j]) && (!flag[i][j - 1]))
        loang(i, j - 1);
    if (j < 5 && (arr[i][j + 1] == arr[i][j]) && (!flag[i][j + 1]))
        loang(i, j + 1);
}
void demmien()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
        {
            if (!flag[i][j])
            {
                so_mien++;
            }
            loang(i, j);
        }
}
int main()
{
    demmien();
    cout << so_mien;
    return 0;
}
