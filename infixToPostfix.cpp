#include<bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if(op=='+'|| op=='-')
        return 1;
    if(op=='/'|| op=='*')
        return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix="";
    for(char ch: infix)
    {
        if(isalnum(ch)) //case 1
            postfix+=ch;
        else if(ch=='(') //case2
            st.push(ch);
        else if(ch==')') //case3
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }
        else //case 4
        {
            while(!st.empty() && precedence(st.top())>=precedence(ch))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty())
    {
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}
int main()
{
    string test="(A+B)*(C-D)";
    cout<<"postfix: "<<infixToPostfix(test)<<endl;
    return 0;
}