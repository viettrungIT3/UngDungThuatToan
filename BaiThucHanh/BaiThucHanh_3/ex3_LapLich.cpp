#include <iostream>
using namespace std;

// Bài 3: Cài đặt chương trình cho bài toán lập lịch – INTERVAL SCHEDULING.

float s[5] = {8, 9, 10, 11, 12};
float f[5] = {8.5, 11, 11.5, 12.5, 13};
int kq[5] = {0, 0, 0, 0, 0};

void swap(float &a, float &b)
{
    float tmp = a;
    a = b;
    b = tmp;
}

void quickSort(float a[], int left, int right)
{
    float p = a[(left + right) / 2];
    int i = left, j = right;
    while (i < j)
    {
        while (a[i] < p)
            i++;
        while (a[j] > p)
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

void schedule()
{
    quickSort(f, 0, 4);
    float last_finish = 0;
    int i = 0;
    for (int i = 0; i < 5; i++)
    {
        if (s[i] >= last_finish)
        {
            kq[i] = 1;
            last_finish = f[i];
        }
    }
}

int main()
{
    schedule();
    for (int i = 0; i < 5; i++)
    {
        cout << kq[i] << " ";
    }
    return 0;
}