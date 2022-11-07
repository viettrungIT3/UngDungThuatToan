#include <bits/stdc++.h>
using namespace std;

void DaoNguocChuoi(char *str, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    char ch = *(str + start);
    *(str + start) = *(str + end);
    *(str + end) = ch;
    DaoNguocChuoi(str, start+1, end-1);
}

int main(int argc, char const *argv[])
{
    char *str = new char[255];
    cin >> str;
    DaoNguocChuoi(str, 0, strlen(str)-1);
    cout << str;
    return 0;
}
