#include <iostream>
#include <stack>
#include <string>

bool is_operand(char);
bool is_operator(char);
int prior(char);

int main()
{
    std::stack<int> st;
    std::string input;
    std::cin >> input;
    for(int i = 0; i < input.size(); ++i)
    {
        if(input[i] == ' ')
        {
            continue;
        }
        else if(is_operand(input[i]))
        {
            std::cout << input[i];
        }
        else if(input[i] == '(')
        {
            st.push(input[i]);
        }
        else if(is_operator(input[i]))
        { 
            while(!st.empty() && (prior(st.top()) >= prior(input[i])))
            {
                std::cout << st.top();
                st.pop();
            }
            st.push(input[i]);
        }
        else if(input[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                std::cout << st.top();
                st.pop();
            }
            if(st.empty())
            {
                std::cout << "bad input was given" << std::endl;
            }
             else 
             { 
                st.pop();
             }
        }
        else 
        {
            std::cout << "wrong symbol was given" << std::endl;
        }
    }
    while(!st.empty())
    {
        std::cout << st.top();
        st.pop();
    }
    return 0;
}

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '^');
}

bool is_operand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int prior(char c)
{
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    if(c == '%')
        return 3; 
    if(c == '^')
        return 4; 
    if(c == '=')
      return 0;
}
