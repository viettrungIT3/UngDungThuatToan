#include <bits/stdc++.h>
using namespace std;

// Liệt kê các tập con k của phần tử

// Hiển thị cấu hình
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

// Sinh cấu hình mới từ một cấu hình đã có
void next_config(int x[], int k, int i)
{
    x[i] += 1;
    i++;

    // x[i+1], ..., x[k] = cận dưới
    while (i <= k)
    {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

void listing_configs(int k, int n)
{
    int i, x[k + 1] = {0};
    for (i = 1; i <= k; i++)
    {
        x[i] = i;
    }

    do
    {
        view_config(x, k);

        i = k;

        while (i > 0 && x[i] == n - k + i)
        {
            i--;
        }

        if (i > 0)
        {
            next_config(x, k, i);
        }

    } while (i > 0);
}

int main(int argc, char const *argv[])
{
    listing_configs(3, 5);
    return 0;
}
