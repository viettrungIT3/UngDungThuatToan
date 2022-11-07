#include <iostream>
using namespace std;

// Bài tập 4: Cài đặt chương trình liệt kê các cách lấy 4 sinh viên từ 6 sinh viên gồm:
// Trang, Cong, Trung, Binh, Hoan, Mai.

string arr[] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};

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
        cout << arr[x[i] - 1] << " ";
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
    listing_configs(4, 6);
    return 0;
}
