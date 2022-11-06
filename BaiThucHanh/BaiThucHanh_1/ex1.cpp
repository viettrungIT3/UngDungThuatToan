#include <bits/stdc++.h>
using namespace std;

// Bài tập 1: Cài đặt chương trình sinh các chuỗi nhị phân độ dài n.

// Sinh cau hinh moi tu cau hinh da co
void next_config(int x[], int n, int i)
{
    x[i] = 1;
    i++;

    // x[i+1], ..., x[n] = 0;
    while (i <= n)
    {
        x[i] = 0;
        i++;
    }
}

// Hien thi mot cau hinh
void view_config(int x[], int n) 
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

// Liet ke cac cau hinh
void list_configs(int n) {
    int i;
    int x[n+1] = {0};
    do
    {
        view_config(x, n); // Hien thi cau hinh
        i = n;
        while ( i> 0 && x[i] == 1)
            i--;
        if ( i > 0) // chua phai cau hinh cuoi
            next_config(x, n, i);
    } while ( i > 0 );
    
}

int main(int argc, char const *argv[])
{
    list_configs(3);
    return 0;
}
