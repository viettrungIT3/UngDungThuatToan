#include <iostream>
using namespace std;

// Bài tập 10: Cài đặt chương trình tính tổng các số lẻ trong một dãy n số nguyên bằng đệ quy.

int TongChuSo(int n)
{
    if (n == 0)
        return 0;

    if (n % 2 == 0)
        return TongChuSo(n / 10);
    else
        return TongChuSo(n / 10) + n % 10;
}

int main(int argc, char const *argv[])
{
    cout << TongChuSo(1234);
    return 0;
}
