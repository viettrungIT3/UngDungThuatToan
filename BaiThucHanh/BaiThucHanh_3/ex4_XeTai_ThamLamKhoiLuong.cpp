#include <iostream>

using namespace std;

int t[7] = {0, 1, 2, 3, 4, 5, 6};
int k[7] = {0, 4, 2, 14, 3, 8, 9};
int xe[7] = {0, 0, 0, 0, 0, 0, 0};

void quickSort(int l, int r)
{
    int i = l;
    int j = r;
    int p = k[(i + j) / 2];
    while (i < j)
    {
        while (k[i] > p)
        {
            i++;
        }
        while (k[j] < p)
        {
            j--;
        }
        if (i <= j)
        {
            swap(k[i], k[j]);
            swap(t[i], t[j]);
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSort(i, r);
    }
    if (j > l)
    {
        quickSort(l, j);
    }
}

void show()
{
    for (int i = 1; i <= 6; i++)
    {
        if (xe[i] != 0)
            cout << xe[i] << " ";
    }
    cout << endl;
}

bool xe_tai(int m, int &soxe)
{
    quickSort(1, 6);
    int i = 1;
    soxe = 0;
    while (m > 0 && i <= 6)
    {
        if (m >= k[i])
        {
            m -= k[i];
            xe[i] = t[i];
            soxe++;
        }
        i++;
    }
    return (m > 0) ? false : true;
}

int main()
{
    int m, soxe;
    cout << "Nhap khoi luong hang: ";
    cin >> m;
    bool result = xe_tai(m, soxe);
    if (result)
    {
        cout << "So xe can dung la: " << soxe << endl;
        cout << "Xe duoc su dung la: " << endl;
        show();
    }
    else
    {
        cout << "Khong co xe nao duoc su dung!";
    }

    return 0;
}