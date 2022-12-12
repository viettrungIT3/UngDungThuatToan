#include <bits/stdc++.h>
using namespace std;

// Cho một sau ký tự S chỉ gồm cá chữ cái và chữ số
// Phương pháp: Thuật toán Z là xây dựng một mảng Z[..] với ý nghĩa Z[i] ;à dppk dào cải xâi tiền tố bắt đầu từ vị trí i.
// Ví dụ S = "ACBDABACBAC" thì:
//       Mảng Z = {1, 0, 0, 0, 1, 0, 3, 0, 0, 2, 0}

// Ứng dụng: Tìm trong xâu T có xem có bao nhiêu xâu con P trong đó
// Thuật toán: Xâu tiền tố của S là một xâu con của S tính từ vị trí đầu tiền
//    - Ta sẽ tạo một xâu mới S = P + "$" + T (Trong đó ký tự "$" không có trong T và P)
//    - Sau đó áp dụng thuật toán X để tìm các tiền tố của s
//    - Độ ...
// Phương pháp:
//    - Duyệt chuỗi S: i từ 1 đến n-1
//    - Mỗi vị trí i ta quản lí một đoạn [left, right] với rigth lớn nhất có thể sao cho
//    xâu con từ left tới right là tiền tố của xâu s
//    - ban đầu left = right = 0;
//    - Giả sử ở i ta đã có đoan [left, right] của vị trí i - 1 và giả sử đã tính được tất cả các  giá trị Z trước đó
//    Chia trường hợp để cập nhật left, right và Z[i] như sau:
//        1. Nếu i > right, trong trường hợp này không có tiền tố nào bắt đầu trước i và kết thúc sau i:
//            - Vì vậy ta gán lại left = i
//            - Cho r chạy từ i trở về lên để tìm đoạn [left, right] mới
//            - Z[i] = right - left + 1

void z_algo(char *s, int *z)
{
    int n = strlen(s), l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < l && s[r - 1] == s[r])
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else if (z[i - l] < r - i + 1)
        {
            z[i] = z[i - l];
        }
        else
        {
            l = i;
            while (r < n && s[r - l] == s[r])
            {
                r++;
            }
            z[i] == r - l;
            r--;
        }
    }
}

int main(int argc, char const *argv[])
{
    char p[100] = {'T', 'r', 'u', 'o', 'n', 'g', ' ', 'D', 'a', 'i', ' ', 'H', 'o', 'c', ' ', 'C', 'N', 'H', 'N'};
    char t[10] = {'a', 'i'};
    char s[110];
    
    return 0;
}
