#include <bits/stdc++.h>
using namespace std;

// Bài tập 2: Cài đặt chương trình sinh các chuỗi ký tự độ dài chỉ chứa 2 ký tự ‘a’ và ký tự ‘b’

void next_config(char x[], int n, int i)
{
    x[i] = 'b';
    i++;

    // x[i], .., a[n] = 'a'
    while (i <= n)
    {
        x[i] = 'a';
        i++;
    }
}

// Hien thi cau hinh
void view_config(char x[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

// list config
void list_configs(int n)
{
    int i;
    char x[n + 1] = {'a'};
    for (i = 1; i <= n; i++)
        x[i] = 'a';
    do
    {
        view_config(x, n);
        i = n;
        while (i > 0 && x[i] == 'b')
            i--;
        if (i > 0)
            next_config(x, n, i);
    } while (i > 0);
}

int main(int argc, char const *argv[])
{
    list_configs(3);
    return 0;
}
