#include <bits/stdc++.h>
using namespace std;

struct DS
{
    string s;
};

int n = 5;
DS ds[10] = {
    "Lorem ipsum dolor sit amet consectetur adipisicing elit. Dolores, est.",
    "Lorem, ipsum dolor sit amet",
    "Lorem ipsum dolor sit amet consectetur adipisicing elit. Distinctio officiis atque pariatur?",
    "Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatem ipsam animi quo dignissimos?",
    "Lorem ipsum dolor sit amet consectetur adipisicing elit. Dolorum saepe provident pariatur rerum illum!"};

int VT_Xau_DoDaiNhoNhat(int l, int r)
{
    if (l == r)
    {
        return l;
    }
    else
    {
        int m = (l + r) / 2;
        int vt1 = VT_Xau_DoDaiNhoNhat(l, m);
        int vt2 = VT_Xau_DoDaiNhoNhat(m + 1, r);
        return (ds[vt1].s.length() < ds[vt2].s.length()) ? vt1 : vt2;
    }
}

int main(int argc, char const *argv[])
{
    cout << VT_Xau_DoDaiNhoNhat(0, n - 1);
    return 0;
}
