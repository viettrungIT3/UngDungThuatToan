#include <bits/stdc++.h>
using namespace std;

// Bài 1: Khởi tạo số nguyên dương k và mảng a gồm ít nhất 15 số nguyên. Tìm số nhỏ
// nhất m trong mảng a sao cho m > k bằng chiến lược đệ quy/ chia để trị.

// Đệ quy
int Min_K_DeQuy(int a[], int n, int k)
{
    if (n == 0)
    {
        if (a[n] > k)
        {
            return a[n];
        }
        else
        {
            return INT_MAX;
        }
    }
    if (a[n - 1] > k)
    {
        return a[n - 1] < Min_K_DeQuy(a, n - 1, k) ? a[n - 1] : Min_K_DeQuy(a, n - 1, k);
    }
    else
        return Min_K_DeQuy(a, n - 1, k);
}

// Chia để trị
int min_K_ChiaDeTri(int a[], int l, int r, int k)
{
    if (l == r)
    {
        if (a[l] > k)
        {
            return a[l];
        }
        else
        {
            return INT_MAX;
        }
    }
    else
    {
        int m = (l + r) / 2;
        int m1 = min_K_ChiaDeTri(a, l, m, k);
        int m2 = min_K_ChiaDeTri(a, m + 1, r, k);
        return min(m1, m2);
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int k = 20;
    int arr[k + 1];
    for (int i = 0; i < k; i++)
    {
        arr[i] = (int)rand() % 100;
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << Min_K_DeQuy(arr, k - 1, k) << endl;
    cout << min_K_ChiaDeTri(arr, 0, k - 1, k);

    return 0;
}
