#include <bits/stdc++.h>
using namespace std;

class CongViec
{
private:
    char maCV[10];
    char thoiGianBatDau[15];
    char thoiGianKetThuc[15];

public:
    CongViec(){};
    CongViec(char maCV[10],
             char thoiGianBatDau[15],
             char thoiGianKetThuc[15]);
    ~CongViec();
    void Xuat();
    long getThoiGianBatDau();
    long getThoiGianKetThuc();
    long getThoiGianLamViec();
};

CongViec::CongViec(char maCV[10],
                   char thoiGianBatDau[15],
                   char thoiGianKetThuc[15])
{
    strcpy(this->maCV, maCV);
    strcpy(this->thoiGianBatDau, thoiGianBatDau);
    strcpy(this->thoiGianKetThuc, thoiGianKetThuc);
}

CongViec::~CongViec()
{
}

void CongViec::Xuat()
{
    cout << left << setw(20) << maCV << setw(12) << thoiGianBatDau
         << setw(12) << thoiGianKetThuc << endl;
}

long CongViec::getThoiGianBatDau()
{
    return long(this->thoiGianBatDau);
}

long CongViec::getThoiGianKetThuc()
{
    return long(this->thoiGianKetThuc);
}

long CongViec::getThoiGianLamViec()
{
    return long(this->thoiGianKetThuc) - long(this->thoiGianBatDau);
}

string ChuyenDoiThoiGian(long time)
{
    string str;
    
}

long TongThoiGian(CongViec cv[], int k)
{
    if (k < 0)
        return 0;
    return TongThoiGian(cv, k - 1) + cv[k].getThoiGianLamViec();
}

int main(int argc, char const *argv[])
{
    int n = 8;
    CongViec cv[8] = {
        CongViec("CV01", "1667831224", "1667917624"),
        CongViec("CV02", "1667831224", "1667917624"),
        CongViec("CV03", "1667831224", "1667917624"),
        CongViec("CV04", "1667831224", "1667917624"),
        CongViec("CV05", "1667831224", "1667917624"),
        CongViec("CV06", "1667831224", "1667917624"),
        CongViec("CV07", "1667831224", "1667917624"),
        CongViec("CV08", "1667831224", "1667917624")};

    return 0;
}
