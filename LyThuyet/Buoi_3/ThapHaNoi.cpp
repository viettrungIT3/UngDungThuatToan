#include <bits/stdc++.h>
using namespace std;

// stack s;

// cach 1
void chuyen(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Chuyen 1 dia tu " << a << " sang " << c << endl;
    }
    else
    {
        chuyen(n - 1, a, c, b);
        chuyen(1, a, b, c);
        chuyen(n - 1, b, a, c);
    }
}

// cach 2
// void chuyen2(int n, char a, char b, char c)
// {
//     push(s, (n, a, b, c));
//     while (!empy(s))
//     {
//         pop(s, (n, a, b, c));
//         if (n == 1)
//         {
//             cout << "Chuyen 1 dia tu " << a << " sang " << b << endl;
//         }
//         else
//         {
//             push(s, (n - 1, b, a, c));
//             push(s, (1, a, b, c));
//             push(s, (n - 1, a, c, b));
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    chuyen(3, 'A', 'B', 'C');
    return 0;
}
