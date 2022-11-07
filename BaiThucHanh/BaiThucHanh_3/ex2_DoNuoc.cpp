#include <iostream>
using namespace std;

// Bài 2: Cài đặt chương trình cho bài toán đổ nước

int c[10] = {100, 25, 10, 5, 1};
int s[10];
int n = 6, m = 5;
int binhnuoc()
{
    for (int i = 0; i < m; i++)
        s[i] = 0;
    int i = m - 1, dem = 0;
    while (n > 0 && i >= 0)
    {
        if (n - c[i] >= 0)
        {
            s[i]++;
            n = n - c[i];
            dem++;
            i--;
        }
        else
            break;
    }
    return dem;
}
int main()
{
    cout << binhnuoc() << endl;
    cout << "result" << endl;
    for (int i = 0; i < m; i++)
        cout << "\t" << c[i] << ":" << s[i] << endl;

    return 0;
}
