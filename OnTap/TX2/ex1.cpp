#include <bits/stdc++.h>
using namespace std;

class DienThoai
{
private:
    string nhanHieu;
    int kichThuoc;
    double giaBan;

public:
    DienThoai(string nhanHieu,
              int kichThuoc,
              double giaBan);
    ~DienThoai();
    friend void Algorithm(DienThoai dt[], int n, double F[10][10], int s);
    friend void Result(DienThoai dt[], int n, double F[10][10], int s);
    friend int DT36(DienThoai dt[], int l, int r);
};

DienThoai::DienThoai(string nhanHieu,
                     int kichThuoc,
                     double giaBan)
{
    this->nhanHieu = nhanHieu;
    this->kichThuoc = kichThuoc;
    this->giaBan = giaBan;
}

DienThoai::~DienThoai()
{
}

void Algorithm(DienThoai dt[], int n, double F[10][10], int s)
{
    double temp;
    for (int i = 0; i <= s; i++)
    {
        F[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            F[i][j] = F[i - 1][j];                               // Không lấy được gói thứ i
            temp = F[i - 1][j - dt[i-1].kichThuoc] + dt[i-1].giaBan; // Lấy được gói thứ i
            if (dt[i-1].kichThuoc <= j && F[i][j] < temp)
            {
                F[i][j] = temp;
            }
        }
    }
}

// Hiển thị chiếc điện thoại đã lấy (nhãn hiệu, giá bán) và số chiếc điện thoại
void Result(DienThoai dt[], int n, double F[10][10], int s)
{
    cout << "Max value: " << F[n-1][s] << endl;
    int i = n-1, j = s, count = 0;
    while (i != 0 && j >= 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << setw(10) << dt[i - 1].nhanHieu << setw(12) << dt[i - 1].giaBan<< endl;
            j = j - dt[i - 1].kichThuoc;
            count++;
        }
        i--;
    }
    cout << "So chiec dien thoai co the lay duoc la: " << count << endl;
}

// Bằng chiến lược chia để trị hãy cho biết có bao nhiêu chiếc điện thoại trong danh sách a có giá bán trong tầm giá từ 3 triệu đến 6 triệu.
int DT36(DienThoai dt[], int l, int r)
{
    if (l == r)
    {
        if (dt[l].giaBan >= 3000000 && dt[l].giaBan <= 6000000)
        {
            // cout << setw(10) << dt[l - 1].nhanHieu << setw(12) << dt[l - 1].giaBan<< endl;
            return 1;
        }
        else
            return 0;
    }
    int m = (l + r) / 2;
    return DT36(dt, l, m) + DT36(dt, m+1, r); 
}

int main(int argc, char const *argv[])
{
    int n = 6, s = 20;
    DienThoai dt[6] = {
        DienThoai("Iphon 5", 5, 5000000),
        DienThoai("Sumsung 5", 5, 6000000),
        DienThoai("Nokia 5", 5, 3000000),
        DienThoai("Iphon 4", 4, 4500000),
        DienThoai("IPhon 6", 6, 8000000),
        DienThoai("Iphon 3", 3, 2500000)};

    double F[10][10];    

    Algorithm(dt, n, F, s);
    Result(dt, n, F, s);

    cout << "So chiec dien thoai co gia tu 3tr den 6tr:" << DT36(dt, 0, n-1) << endl;

    return 0;
}
