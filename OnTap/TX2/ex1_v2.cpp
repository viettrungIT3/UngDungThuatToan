#include <iostream>

using namespace std;

struct DienThoai
{
    string nh;
    int kt;
    double gia;
};

DienThoai dt[5] = {
    {"Nokia", 5, 900},
    {"Samsung", 5, 5000},
    {"Oppo", 3, 800},
    {"Huawai", 5, 2000},
    {"Apple", 4, 1000}};

void algorithm(double *F[6], int s)
{
    for (int j = 0; j <= s; j++)
    {
        F[0][j] = 0;
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            F[i][j] = F[i - 1][j];
            double tmp = F[i - 1][j - dt[i - 1].kt] + dt[i - 1].gia;
            if (j >= dt[i - 1].kt && tmp > F[i][j])
                F[i][j] = tmp;
        }
    }
}

void result(double *F[6], int s)
{
    cout << "Nhung chiec dien thoai da lay: " << endl;
    int i = 5, j = s;
    int count = 0;
    while (i > 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << dt[i - 1].nh << " " << dt[i - 1].gia << endl;
            j = j - dt[i - 1].kt;
            count++;
        }
        i--;
    }
    cout << "So chiec dien thoai co the lay duoc la: " << count << endl;
}

double dem_dt(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        int demL = dem_dt(l, m);
        int demR = dem_dt(m + 1, r);
        return (demL + demR);
    }
    else
    {
        if (dt[l].gia >= 3000 && dt[l].gia <= 6000)
        {
            cout << dt[l].nh << " " << dt[l].kt << " " << dt[l].gia << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int s;
    cout << "Nhap kich thuoc chiec tui: ";
    cin >> s;
    cout << "===================" << endl;

    double **F = new double *[5 + 1];
    for (int i = 0; i <= 5; i++)
    {
        F[i] = new double[s + 1];
    }

    algorithm(F, s);
    result(F, s);
    cout << "===================" << endl;

    cout << "So dien thoai gia tu 3000 den 6000 la: " << dem_dt(0, 5);
    return 0;
}
