#include <iostream>
#include <vector>
#include <stack>

bool isValid(std::vector<char>& symbols)
{
    std::stack<char> openSymbols;
    for(int i = 0 ; i < symbols.size(); i++)
    {
        char c = symbols[i];
        if(c == '(' || c == '{' || c == '[')
        {
            openSymbols.push(c);
        }
        else
        {
            if(openSymbols.empty())
            {
                return false;
            }
            if(c == ')' && openSymbols.top() != '(')
            {
                return false;
            }
            else if(c == '}' && openSymbols.top() != '{')
            {
                return false;
            }
            else if(c == ']' && openSymbols.top() != '[')
            {
                return false;
            }
            else
            {
                openSymbols.pop();
            }
            if(i == symbols.size()-1 && !openSymbols.empty())
            {
                return false;
            }

        }
    }
    if(!openSymbols.empty())
    {
        return false;
    }
    return true;
}
int main()
{
    std::vector<char> n1  = {'{', '(', ')', '}', '[', ']'};//valid
    std::vector<char> n2  = {'[', ']', '(', ')', '{', '}'};//valid
    std::vector<char> n3  = {'(', '{', '[', ']', '}', ')'};//valid
    std::vector<char> n4  = {'[', '{', '(', ')', '}', ']'};//valid
    std::vector<char> n5  = {'(', ')', '{', '}', '[', ']'};//valid
    std::vector<char> n6  = {'[', '{', '}', '(', ')', '['};//invalid
    std::vector<char> n7  = {'{', '[', '(', ']', ')', '}'};//invalid
    std::vector<char> n8  = {'(', ')', '[', '}', '{', '}'};//invalid
    std::vector<char> n9  = {'[', '(', '(', '{', '}', ']'};//invalid
    std::vector<char> n10 = {'}', '}', ')', '{', '}', '}'};//invalid
    std::vector<char> n11 = {'{', '{', '(', ')', '[', ']', '}'};//invalid
    std::vector<char> n12 = {'{', '{', '(', ')', '[', ']', '}'};//invalid
    std::vector<char> n13 = {'(', '[', ')', ']', '[', ']'};//invalid


    std::cout << "n1: " << isValid(n1) << std::endl;
    std::cout << "n2: " << isValid(n2) << std::endl;
    std::cout << "n3: " << isValid(n3) << std::endl;          
    std::cout << "n4: " << isValid(n4) << std::endl;
    std::cout << "n5: " << isValid(n5) << std::endl;
    std::cout << "n6: " << isValid(n6) << std::endl;
    std::cout << "n7: " << isValid(n7) << std::endl;
    std::cout << "n8: " << isValid(n8) << std::endl;
    std::cout << "n9: " << isValid(n9) << std::endl;
    std::cout << "n10: "<< isValid(n10) << std::endl;
    std::cout << "n11: "<< isValid(n11) << std::endl;
    std::cout << "n12: "<< isValid(n12) << std::endl;
    std::cout << "n13: "<< isValid(n13) << std::endl;

    return 0;
}