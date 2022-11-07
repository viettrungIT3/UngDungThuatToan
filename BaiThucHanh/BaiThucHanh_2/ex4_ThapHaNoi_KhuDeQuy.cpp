#include <bits/stdc++.h>
using namespace std;

// Bài tập 4: Cài đặt bài toán tháp Hà Nội theo thuật toán khử đệ quy

typedef struct
{
    int n;
    char a, b, c;
} Call;

typedef struct
{
    int top;
    Call *a;
} Stack;

void create(Stack &s)
{
    s.top = -1;
    s.a = new Call[1];
}

bool empty(Stack s)
{
    return (s.top == -1);
}

void push(Stack &s, Call call)
{
    s.top++;
    s.a = (Call *)realloc(s.a, (s.top + 1) * sizeof(Call));
    s.a[s.top] = call;
}

void pop(Stack &s, Call &call)
{
    call = s.a[s.top];
    s.a = (Call *)realloc(s.a, (s.top) * sizeof(Call));
    s.top--;
}
int main()
{
    int n = 5, k;
    Stack s;
    char a, b, c;
    Call call = {n, 'A', 'B', 'C'};
    create(s);
    push(s, call);
    do
    {
        pop(s, call);
        a = call.a;
        b = call.b;
        c = call.c;
        if (call.n == 1)
            cout << "chuyen 1 dia tu coc " << a << " sang coc " << c << endl;
        else
        {
            k = call.n - 1;

            call.n = k;
            call.a = b;
            call.b = a;
            call.c = c;
            push(s, call);

            call.n = 1;
            call.a = a;
            call.b = b;
            call.c = c;
            push(s, call);

            call.n = k;
            call.a = a;
            call.b = c;
            call.c = b;
            push(s, call);
        }
    } while (!empty(s));
    return 0;
}
