#include <bits/stdc++.h>
using namespace std;

// Bài toán 2: cho 2 xâu lý tự T và P chỉ gồm các ký tự {'0' .. '9', 'a' .. 'z', 'A' .. 'Z'}
// Yêu cầu: Kiêm tra xem P có phải là một xâu con của T hay không?
// Phương pháp:
//  - So sánh ngược từ ký tự cuối của O trở về đầu
//  - Giả sử vị trí bắt đầu so sánh trong T là i và trị trí cuối cùng của P là P[v] (v= strlen(P))
//  - Ta sẽ so sánh T[i] với P[v] và dịch chuyển về đầu
//  - Nếu việc khợp từng ksy tự vượt qua được P[0] thì O có nặt trọng T
//  - Ngược lại (có T[i] != P[v])
//     - Nếu T[i] không có trong P, nthif i = i + v
//     - Ngược lại (T[i] có trong P) gọi x là vị trí xuất hiện đầu tiên của T[i] trong P (T[i] = P[x]), thì i = i + v - x -1


int char_in_string(char c, char *S){
    int i = 0, n = strlen(S);
    while (i < n)
    {
        if( S[i] == c)  return i;
        i++;
    }
    return -1;
}
int IndexOf(char *p, char *t)
{
    int dem = 0;
    int i = strlen(p);
    int v = strlen(p);
    while (i < strlen(t))
    {
        int x = v - 1,
            j = i - 1;
        while (t[j] == p[x] && x > -1)
        {
            j--;
            x--;
        }
        if (x < 0)
        {
            dem++;
            i = i + v;
        }
        else
        {
            x = char_in_string(t[j], p);
            if (x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }

    return dem;
}

int main(int argc, char const *argv[])
{
    char p[100] = {'T', 'r', 'u', 'o', 'n', 'g', ' ', 'D', 'a', 'i', ' ', 'H', 'o', 'c', ' ', 'C', 'N', 'H', 'N'};
    char t[10] = {'a', 'i'};
    cout << IndexOf(p, t);
    return 0;
}
