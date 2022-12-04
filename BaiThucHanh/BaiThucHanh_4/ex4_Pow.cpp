#include <bits/stdc++.h>
using namespace std;

float Pow(float a, int n)
{
    if (n == 1)
    {
        return a;
    }
    float temp = Pow(a, n/2);
    
    return (n % 2 ==  1) ? temp * temp * a : temp * temp;
}

int main(int argc, char const *argv[])
{
    int n = 3;
    float a = 3.01;

    cout << Pow(a, n);
    
    return 0;
}
