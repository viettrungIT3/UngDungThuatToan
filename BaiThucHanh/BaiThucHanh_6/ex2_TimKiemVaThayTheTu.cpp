#include <bits/stdc++.h>
using namespace std;

// Đếm số chuỗi f có trong chuỗi s
int CountWorld(string str, string f)
{
    string s = str;
    int times = 0; // Biến đếm
    int lenS = s.length();
    int lenF = f.length();
    int pos = s.find(f);
    while (pos < lenS && pos != -1)
    {
        times++;
        s.erase(0, pos + lenF);
        lenS = s.length();
        pos = s.find(f);
    }

    return times;
}

// thay thế chuỗi f thành chuỗi c có trong chuỗi s
string ChangeWorld(string str, string f, string c)
{
    string s = str, sNew = "";
    int lenS = s.length();
    int lenF = f.length();
    int pos = s.find(f);
    while (pos < lenS)
    {
        sNew += s.substr(0, pos) + c;
        s.erase(0, pos + lenF);
        lenS = s.length();
        pos = s.find(f);
        if (pos == -1)
        {
            sNew += s.substr(0, lenS);
            break;
        }
    }

    return sNew;
}

int main(int argc, char const *argv[])
{
    string s = "Lorem ipsum dolor sit, child amet consectetur adipisicing elit. Laboriosam fugit exercitationem delectus quos alias non beatae recusandae child a minima nesciunt, minus molestiae velit, child aspernatur ratione, child ea libero sapiente asperiores child necessitatibus.";

    cout << CountWorld(s, "child") << endl;
    cout << ChangeWorld(s, "child", "children");

    return 0;
}
