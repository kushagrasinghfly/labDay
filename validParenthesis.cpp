#include <iostream>
#include <stack>
using namespace std;

bool isValidParentheses(string expr) {
    stack<char> st;
    
    for (char ch : expr) 
    {
        if (ch == '(' || ch == '{' || ch == '[')  //case 1
            st.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']')  //case 2
        {
            if (st.empty()) return false;           //if brackets end and stack is empty return false cause its valid
            
            char top = st.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) 
                st.pop(); 
            else 
                return false;
        }
    }
    
    return st.empty(); // If stack is empty, parentheses are balanced
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    
    if (isValidParentheses(expr)) 
        cout << "Valid Parentheses" << endl;
    else 
        cout << "Invalid Parentheses" << endl;
    return 0;
}
