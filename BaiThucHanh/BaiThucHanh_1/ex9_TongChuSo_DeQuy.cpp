#include <iostream>
using namespace std;

//Bài tập 9: Cài đặt chương trình tính tổng các chữ số của số nguyên dương n bằng đệ quy.

int TongChuSo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return TongChuSo(n / 10) + n % 10;
}

int main(int argc, char const *argv[])
{
    cout << TongChuSo(1234);
    return 0;
}
