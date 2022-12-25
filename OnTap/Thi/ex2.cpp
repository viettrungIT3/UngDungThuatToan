#include <bits/stdc++.h>
using namespace std;

// Bài 2: Cho danh sách d có n lớp học phần, mỗi lớp học gồm các thông tin: mã lớp, số
// học sinh, số học sinh nữ. Cho một số nguyên dương n và một phòng học p gồm k chỗ ngồi.
// Viết chương trình thực hiện:
// Khởi tạo danh sách d gồm 7 đến 10 lớp học phần (ko nhập từ bàn phím), sao cho danh
// sách được sắp xếp theo chiều giảm dần của số học sinh.
// Sử dụng chiến lược tham lam: Cho biết cần lấy từ ít nhất bao nhiêu lớp trong danh sách
// d để được số học sinh lớn hơn n.
// Sử dụng quy hoạch động: Cần ghép những lớp nào vào phòng học p để được tổng số
// học viên không vượt quá k mà tổng số học sinh nữ đạt được nhiều nhất.
// Sử dụng thuật toán xử lý xâu ký tự để xác định một xâu s có phải là xâu con của một
// xâu st hay không. Hiển thị thông tin các lớp học phần thuộc ngành công nghệ thông tin
// (mã lớp có chứa “it”).

class Lop
{
private:
    string maLop;
    int soHS;
    int soHS_Nu;

public:
    Lop(){};
    Lop(string maLop,
        int soHS,
        int soHS_Nu);
    ~Lop();
    friend int Lay_n_Lop_ThamLam(Lop d[], int n);
    friend void HienThi(Lop d[], int n);
    friend void Algorithm(Lop d[], int n, int F[11][100], int k);
    friend void Result(Lop d[], int n, int F[11][100], int k);
    friend void Show_it(Lop d[], int n, string s);
};

Lop::Lop(string maLop,
         int soHS,
         int soHS_Nu)
{
    this->maLop = maLop;
    this->soHS = soHS;
    this->soHS_Nu = soHS_Nu;
}

Lop::~Lop()
{
}

void HienThi(Lop d[], int n)
{
    cout << "Danh sach tat ca cac lop hoc: " << endl;
    cout << setw(10) << "Ma lop" << setw(10) << "So HS" << setw(10) << "So HS nu" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << d[i].maLop << setw(10) << d[i].soHS << setw(10) << d[i].soHS_Nu << endl;
    }
}

int Lay_n_Lop_ThamLam(Lop d[], int n)
{
    int i = n, countL = 0;
    while (i > 0)
    {
        if (d[i].soHS > n)
            countL++;
        i--;
    }
    return countL;
}

void Algorithm(Lop d[], int n, int F[11][100], int k)
{
    long temp;
    for (int i = 0; i <= k; i++)
    {
        F[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            F[i][j] = F[i - 1][j];                                 // Không lấy được gói thứ i
            temp = F[i - 1][j - d[i - 1].soHS] + d[i - 1].soHS_Nu; // Lấy được gói thứ i
            if (d[i - 1].soHS <= j && F[i][j] < temp)
            {
                F[i][j] = temp;
            }
        }
    }
}

void Result(Lop d[], int n, int F[11][100], int k)
{
    int i = n - 1, j = k;

    cout << "De .. thi can ghep cac lop co ma: ";
    while (i != 0 && j >= 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << d[i - 1].maLop << ", ";
            j = j - d[i - 1].soHS;
        }
        i--;
    }
    cout << endl;
}

void Show_it(Lop d[], int n, string s)
{
    int countS = 0;
    cout << "Cac lop hoc phan nao thuoc nganh CNTT la: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (d[i].maLop.find(s) != -1)
        {
            cout << setw(10) << d[i].maLop << setw(10) << d[i].soHS << setw(10) << d[i].soHS_Nu << endl;
            countS++;
        }
    }
    if (countS == 0)
    {
        cout << "Khong co." << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n = 8, k = 99;
    Lop d[n] = {
        Lop("it01", 70, 10),
        Lop("it02", 68, 12),
        Lop("it03", 66, 6),
        Lop("it04", 54, 8),
        Lop("it05", 60, 14),
        Lop("it06", 58, 10),
        Lop("HTTT01", 50, 5),
        Lop("HTTT02", 42, 7)};
    int F[11][100];

    HienThi(d, n);
    cout << Lay_n_Lop_ThamLam(d, n) << endl;

    Algorithm(d, n, F, k);
    Result(d, n, F, k);

    Show_it(d, n, "it");

    return 0;
}
