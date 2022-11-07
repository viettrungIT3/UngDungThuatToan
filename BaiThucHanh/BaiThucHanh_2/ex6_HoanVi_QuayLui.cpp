#include <iostream>
using namespace std;

// Bài tập 6: Cài đặt bài toán liệt kê hoán vị theo phương pháp quay lui

int n, x[100], dd[100];

void init()
{
    n = 3;
    for (int i = 1; i <= n; i++)
    {
        dd[i] = 0;
    }
}

void show(int x[])
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i <= n; i++)
    {
        if (dd[i] == 0) // i chưa được chọn trước đó
        {
            x[k] = i;
            if (k == n) // Tìm được phần tử cuối
                show(x);
            else
            {
                dd[i] = 1;  // Ghi nhận việc chọn i cho x[k]
                Try(k + 1);
                dd[i] = 0;  // Hủy ghi nhận việc chọn i cho x[k]
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    
    Try(1);
    return 0;
}
