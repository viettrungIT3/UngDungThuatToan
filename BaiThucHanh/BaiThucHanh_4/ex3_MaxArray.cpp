#include <bits/stdc++.h>
using namespace std;

float FindMax(float a[], int l, int r)
{
    if (l == r)
        return a[l];

    if ( r == l+1)
    {
        if (a[l] > a[r])
            return a[l];
        else return a[r];
    }
    else
    {
        int mid = (l + r)/2;
        float maxL = FindMax(a, l, mid);
        float maxR = FindMax(a, mid+1, r);
        cout << maxL << " " << maxR << endl;
        if (maxL > maxR)
            return maxL;
        else 
            return maxR;
    }
}

int main(int argc, char const *argv[])
{
    int n = 5;
    float arr[100];

    cout << "Mang dau tien: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = (float) rand() / RAND_MAX * 1000;
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << FindMax(arr, 0, n-1);
    
    return 0;
}
