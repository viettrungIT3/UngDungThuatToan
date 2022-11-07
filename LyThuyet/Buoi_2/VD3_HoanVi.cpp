#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void view_config(int a[], int n)
{
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i == n - 1)
            continue;
        cout << ", ";
    }
    cout << "}" << endl;
}

void next_config(int x[], int n, int i)
{
    // tìm x[k] bé nhất trong đoạn cuối lớn hơn x[i]
    int k = n;
    while (x [k] < x [i])
    {
        k--;
    }

    // Đảo giá trị x[i] và x[k]
    swap(x[i], x[k]);

    // Đảo ngược đoạn cươi
    int j = n;
    i++;
    while (i < j)
    {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}

void listing_configs( int n)
{
    int i, x[n+1] = {0};

    // Cấu hình đầu tiên [1 2 .. n]
    for ( i = 1; i <= n; i++)
    {
        x[i] = i;
    }
    
    do
    {
        view_config(x, n);

        // Tìm phần tử liền trước đoạn cuối giảm dần
        i = n -1;
        while ( i > 0 && x[i] > x[i+1])
        {
            i--;
        }

        // Chưa phải cấu hình cuối
        if (i > 0)
        {
            next_config(x, n, i);
        }
        
    } while (i > 0);
    
}


int main(int argc, char const *argv[])
{
    listing_configs(9);
    return 0;
}
