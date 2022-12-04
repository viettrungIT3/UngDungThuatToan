#include <bits/stdc++.h>
using namespace std;

class HocSinh
{
private:
    string firstName;
    string lastName;
    int year;
    string address;

public:
    HocSinh(string firstName,
            string lastName,
            int year,
            string address);
    string getFirstName() { return firstName; };
    string getLastName() { return lastName; };
    int getYear() { return year; };
    string getAddress() { return address; };
    ~HocSinh();

    void Show();
    // friend void QuickSort(HocSinh li, int left, int right);
    // friend void Display(HocSinh li[], int n);
};

HocSinh::HocSinh(string firstName,
                 string lastName,
                 int year,
                 string address)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->year = year;
    this->address = address;
}

HocSinh::~HocSinh()
{
}

void HocSinh::Show()
{
    cout << left << setw(12) << firstName << setw(15) << lastName
         << setw(6) << year << setw(20) << address << endl;
}

void Display(HocSinh li[], int n)
{
    cout << left << setw(12) << "FirstName" << setw(15) << "LastName"
         << setw(6) << "Year" << setw(20) << "Address" << endl;
    for (int i = 0; i < n; i++)
    {
        li[i].Show();
    }
    cout << endl;
}

void QuickSort(HocSinh li[], int left, int right)
{
    int p = (left + right) / 2;
    int i = left;
    int j = right;

    do
    {
        string temp = li[p].getFirstName();
        while (li[i].getFirstName().compare(temp) < 0)
            i++;
        while (li[j].getFirstName().compare(temp) > 0)
            j--;
        if (i <= j)
        {
            HocSinh hs = li[i];
            li[i] = li[j];
            li[j] = hs;
            i++;
            j--;
        }

    } while (i <= j);

    if (i < right)
        QuickSort(li, i, right);
    if (left < j)
        QuickSort(li, left, i);
}

int TimKiemVTTheoTen(HocSinh li[], int left, int right, string name)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (name == li[mid].getFirstName())
        return mid;

    if (name < li[mid].getFirstName())
        return TimKiemVTTheoTen(li, left, mid - 1, name);

    if (name > li[mid].getFirstName())
        return TimKiemVTTheoTen(li, mid + 1, right, name);
}

int main(int argc, char const *argv[])
{
    int n = 6;
    HocSinh list[6] = {
        HocSinh("Trung", "Nguyen", 2001, "Thai Nguyen"),
        HocSinh("Hoa", "Ngu", 2001, "Nam Dinh"),
        HocSinh("Kien", "Nguyen", 2001, "Vinh Phuc"),
        HocSinh("Giang", "Ta", 2001, "Thai Binh"),
        HocSinh("Lan", "Nguyen", 2001, "Hoa Binh"),
        HocSinh("Thao", "Trieu", 2001, "Lang Son")};

    Display(list, n);
    QuickSort(list, 0, n - 1);

    Display(list, n);

    int ind = TimKiemVTTheoTen(list, 0, n - 1, "Trung");

    if (ind == -1)
        cout << "Khong tim thay!";
    else
    {
        cout << "Thong tin cua hoc sinh tim thay dau tien: " << endl;
        cout << "Ten: " << list[ind].getFirstName() << " " << list[ind].getLastName() << endl;
        cout << "Nam sinh: " << list[ind].getYear() << endl;
        cout << "Dia chi: " << list[ind].getAddress() << endl;
    }

    return 0;
}
