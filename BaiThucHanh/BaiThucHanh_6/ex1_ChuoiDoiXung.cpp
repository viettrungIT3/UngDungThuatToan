#include <bits/stdc++.h>
using namespace std;

bool IsSymmetry(string x)
{
    int len = x.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (x[i] != x[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

string StringSymmetryAtK(string x, int k)
{
    int n = x.length();
    string strNew;
    int i = 1, countS;

    k--;
    strNew += x[k];
    while ( (k-i >= 0) && (k+i) < n )
    {
        if (x[k-i] == x[k+i])
        {
            strNew.insert(0, 1, x[k+i]);
            strNew += x[k+i];
            i++;
        }
        else
        {
            break;
        }
        
    }
    return strNew;
}

int main(int argc, char const *argv[])
{
    string s = "abcdcbb";
    cout << s << endl;

    if (IsSymmetry(s))
    {
        cout << "Chuoi tren la doi xung.";
    }
    else
    {
        cout << "Chuoi tren khong doi xung." << endl;
        int k = 4;
        cout << StringSymmetryAtK(s, k);
        // count << "Chuoi con: " << StringSymmetryAtK(s , k);
    }
    

    return 0;
}
