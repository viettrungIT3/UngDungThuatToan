#include <iostream>
using namespace std;

void chuyen(int n, char a, char b, char c)
{
    if (n == 1)
        cout << a << " ---> " << c << endl;
    else
    {
        chuyen(n-1, a, c, b);
        chuyen(1, a, b, c);
        chuyen( n-1, b, a, c);
    }
}

int main(int argc, char const *argv[])
{
    chuyen(3, 'A', 'B', 'C');
    return 0;
}
