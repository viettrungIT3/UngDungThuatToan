#include <iostream>
using namespace std;

// Bài 1: Cài đặt chương trình cho bài toán đổi tiền – COIN CHANGING

void quickSort(int a[], int left, int right)
{
    int p = a[(left + right) / 2];
    int i = left, j = right;
    while (i < j)
    {
        while (a[i] > p)
            i++;
        while (a[j] < p)
            j--;

        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right)
        quickSort(a, i, right);

    if (left < j)
        quickSort(a, left, j);
}

void Sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

bool CASHIERS_ALGORITHM(int C[], int m, long n, int *S)
{
    int i;
    for (i = 0; i <= m; i++)
    {
        S[i] = 0;
    }
    i = 0;
    while (n > 0 && i < m)
    {
        S[i] = n / C[i];    // Số đồng nhiều nhất có thể lấy
        n = n - S[i] * C[i];    // Số tiền còn lại
        i++;
    }
    if (n > 0)

        return false;
    else
        return true;
}

int main(int argc, char const *argv[])
{
    long n = 34, m = 5;
    int C[] = {1, 10, 5, 25, 100};
    int *S = new int[m];
    quickSort(C, 0, m);
    // Sort(C, m);
    // for (int i = 0; i < m; i++)
    // {
    //     cout << C[i] << " ";
    // }

    if (CASHIERS_ALGORITHM(C, m, n, S))
    {
        for (int i = 0; i < m; i++)
        {
            if ( S[i] > 0)
            cout << "Co " << S[i] <<" to menh gia " << C[i] << " dong." <<  endl;
        }
    }
    else
        cout << "No solution";

    return 0;
}
