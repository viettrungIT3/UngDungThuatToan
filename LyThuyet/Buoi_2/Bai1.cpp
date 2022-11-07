#include <bits/stdc++.h>
using namespace std;

void next_config(char x[], int n, int i)
{
    x[i] = 'b';
    i++;
    while (i <= n)
    { // Dat x[i+1], …, x[n] = 0
        x[i] = 'a';
        i++;
    }
}

void view_config(char x[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

void listing_configs(int n)
{
    int i;
    char x[n+1];
    for (int j = 1; j <= n; j++)
    {
        x[j] = 'a';
    }
    
    do
    {
        view_config(x, n);
        i = n;
        while (i > 0 && x[i] == 'b')
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
    listing_configs(6);
    return 0;
}
