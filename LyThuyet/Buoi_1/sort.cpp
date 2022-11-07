#include <iostream>
#include <stack>

using namespace std;

int minStack(stack<int> &s1, stack<int> &s2)
{
    int tmp = s1.empty() ? s2.top() : s1.top();
    if (!s1.empty())
    {
        s1.pop();
        while (!s1.empty())
        {
            if (s1.top() < tmp)
            {
                s2.push(tmp);
                tmp = s1.top();
            }
            else
            {
                s2.push(s1.top());
            }

            s1.pop();
        }
    }
    else
    {
        s2.pop();
        while (!s2.empty())
        {
            if (s2.top() < tmp)
            {
                s1.push(tmp);
                tmp = s2.top();
            }
            else
            {
                s1.push(s2.top());
            }
            s2.pop();
        }
    }
    return tmp;
}

stack<int> algo(stack<int> &s1)
{
    stack<int> s2;
    stack<int> s3;
    int minS;
    while (!s1.empty() || !s2.empty())
    {
        s3.push(minStack(s1, s2));
    }

    return s3;
}

int main()
{
    stack<int> myStack;

    myStack.push(3);
    myStack.push(2);
    myStack.push(5);
    myStack.push(4);
    myStack.push(1);

    stack<int> result = algo(myStack);

    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }

    return 0;
}