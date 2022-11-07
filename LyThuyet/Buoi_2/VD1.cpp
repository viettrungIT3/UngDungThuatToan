#include <bits/stdc++.h>
using namespace std;

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}

void next_config(int x[], int n, int i) {}

void view_config(int x[], int n){}

void sinh_day_ma_nhi_phan(int n)
{
    // int x[n];
    // for (int i = 0; i < n; i++)
    // {
    //     x[i] = 0;
    // }

    // do
    // {
    //     xuat(x, n);
    //     for (int j = n - 1; j >= 0; j--)
    //     {
    //         if (x[j] == 0)
    //         {
    //             x[j] = 1;
    //             for (int z = j + 1; z < n; z++)
    //             {
    //                 x[z] = 0;
    //             }
    //         }
    //     }

    // } while (x[0] == 1);
    int i;
    int x[n+1] = {0};
    do
    {
        view_config(x, n);
        i = n;
        while (i> 0 && x[i] == 1) 
        {
            i--;
        }
        if (i > 0)
        {
            next_config(x, n, i);
        }
        
    } while (i > 0);
    
}

int main(int argc, char const *argv[])
{
    sinh_day_ma_nhi_phan(3);
    return 0;
}
