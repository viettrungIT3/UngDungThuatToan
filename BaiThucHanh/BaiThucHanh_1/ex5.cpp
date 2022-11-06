#include <iostream>
using namespace std;

// Bài tập 5: Cài đặt chương trình sinh các hoán vị của tập S = {1, 2, …, n}.

// Đảo giá trị 2 phần tử
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hiển thị một cấu hình
void view_config(int x[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

// Sinh cấu hình mới từ cấu hình đã có
void next_config(int x[], int n, int i)
{
    // Tìm x[k] bé nhất trong đoạn cưới lớn hơn x[i]
    int k = n;
    while (x[k] < x[i])
        k--;

    // Đảo giá trị x[i] và x[k]
    Swap(x[i], x[k]);

    // Đảo ngược đoạn cuối
    int j = n;
    i++;
    while (i < j)
    {
        Swap(x[i], x[j]);
        i++;
        j--;
    }
}

void listing_configs(int n)
{
    int i, x[n + 1] = {0};
    // Cấu hình đầu tiên {1, 2, ..., n}
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
    do
    {
        // In một câú hình
        view_config(x, n);

        // Tìm phần từ liền trước đoạn cuối giảm dần
        i = n - 1;

        while (i > 0 && x[i] > x[i + 1])
            i--;

        // Nếu chưa phải là cấu hình cuối
        if (i > 0)
            next_config(x, n, i);

    } while (i > 0);
}

int main(int argc, char const *argv[])
{
    listing_configs(3);
    return 0;
}
