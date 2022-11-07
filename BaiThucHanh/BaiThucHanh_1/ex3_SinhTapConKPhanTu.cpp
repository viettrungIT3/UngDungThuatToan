#include <iostream>
using namespace std;

// Bài tập 3: Cài đặt chương trình sinh các tập con k phần tử của tập S = {1, 2, …, n}.

// Sinh cấu hình mới từ cấu hình đang có
void next_config(int x[], int k, int i)
{
    x[i] += 1;
    i++;
    while (i <= k) // x[i+1], ..., x[k] = cận dưới
    {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

// Hiển thị một cấu hình
void view_config(int x[], int k)
{
    for (int i = 1; i <= k; i++)
        cout << x[i];
    cout << endl;
}

// Liệt kệ các cấu hình
void listing_configs(int k, int n)
{
    int i, x[k + 1] = {0};
    // Cấu hình đầu tiền {1 2 ... k}
    for (int i = 1; i <= k; i++)
    {
        x[i] = i;
    }
    do
    {
        view_config(x, k); // In cấu hình
        // Tìm phần tử đầu tiên chưa đạt giới hạn trên
        i = k;
        while (i > 0 && x[i] == n - k + i)
            i--;

        if (i > 0) // Chưa đạt cấu hình cuối
            next_config(x, k, i);

    } while (i > 0);
}

int main(int argc, char const *argv[])
{
    listing_configs(3, 5);
    return 0;
}
