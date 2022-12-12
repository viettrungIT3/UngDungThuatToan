#include <bits/stdc++.h>
using namespace std;

class MayTinh
{
private:
    string nhanHieu;
    float giaNhap;
    float giaBan;

public:
    MayTinh();
    MayTinh(string nhanHieu, float giaNhap, float giaBan);
    ~MayTinh();
    void Xuat();
};

MayTinh::MayTinh()
{
}

MayTinh::MayTinh(string nhanHieu, float giaNhap, float giaBan)
{
    this->nhanHieu = nhanHieu;
    this->giaNhap = giaNhap;
    this->giaBan = giaBan;
}

MayTinh::~MayTinh()
{
}

void MayTinh::Xuat()
{
    cout << left << setw(20) << nhanHieu << setw(10) << giaNhap << setw(10) << giaBan << endl;
}

int n = 8;
MayTinh mt[8] = {
    MayTinh("NH01", 1200, 1500),
    MayTinh("NH02", 1200, 1500),
    MayTinh("NH03", 1200, 1500),
    MayTinh("NH04", 1200, 1500),
    MayTinh("NH05", 1200, 1500),
    MayTinh("NH06", 1200, 1500),
    MayTinh("NH07", 1200, 1500),
    MayTinh("NH08", 1200, 1500)};

void HienThi(MayTinh mt[], int k)
{
    if (k < 0)
        return;
    else
    {
        mt[k].Xuat();
        HienThi(mt, k - 1);
    }
}

int main(int argc, char const *argv[])
{

    HienThi(mt, n-1);
    return 0;
}
