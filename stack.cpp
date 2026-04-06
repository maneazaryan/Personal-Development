#include <iostream>
#include <string>
#include <stack>

double callculateNumber(std::string &line, int& index)
{
    double num = 0;
    for(; index < line.size(); index++)
    {
        char c = line[index];
        if (c >= '0' && c <= '9')
        {
            num = num * 10 + (c - '0');
        }
        else
        {
            break;
        }
    }
    index--;
    return num;
}

void calculate(std::stack<double> &numbers)
{
    if(numbers.empty())
    {
        std::cout << "Error: Empty line " << std::endl;
        return;
    }
    double result = 0;
    while(!numbers.empty())
    {
        result += numbers.top();
        numbers.pop();
    }
    std::cout << "Result: " << result << std::endl;
}

void parseLine(std::string& line)
{
    std::stack<double> numbers;
    double number = 0;
    char c = ' ';
    for (int i = 0; i < line.size(); i++)
    {
        if(i==0)
        {
            number = callculateNumber(line, i);
            numbers.push(number);
            number=0;
            continue;
        }

        if(i== line.size()-1)
        {
            break;
        }
        c = line[i];
        double nextNumber = callculateNumber(line, ++i);
        if(c == '+')
        {
            numbers.push(nextNumber);
            continue;
        }
        else if(c== '-')
        {
            nextNumber = (nextNumber==0)? nextNumber : -nextNumber;
            numbers.push(nextNumber);
        }
        else if(c== '*')
        {
            double lastNumber = numbers.top();
            numbers.pop();
            numbers.push(lastNumber*nextNumber);  
        }
        else if(c== '/')
        {
            double lastNumber = numbers.top();
            numbers.pop();
            if(nextNumber == 0)
            {
                std::cout << "Error: /0" << std::endl;
                return ;
            }
            numbers.push(lastNumber/nextNumber);
        }
    }

    // while (!numbers.empty())
    // {
    //     std::cout << "number in stack: " << numbers.top() << std::endl;
    //     numbers.pop();
    // }
    
    calculate(numbers);
}



//add more op????
bool getLine(std::string &line)
{
    std::cout << "Enter a math expression(last character must be '='): ";
    std::cin >> line;
    if (line.empty())
    {
        std::cout << "Error: empty line" << std::endl;
        return false;
    }
    char last = line[line.size() - 1];
    for (char c : line)
    {
        if ((c < '0' || c > '9') && c != '+' && c != '-' && c != '*' && c != '/' && c != '=')
        {
            std::cout << "Error: wrong character" << std::endl;
            return false;
        }
    }
    if (last != '=')
    {
        std::cout << "Error: wrong last element" << std::endl;
        return false;
    }
    return true;
}

int main()
{
    std::string line;
    while (true)
    {
        if (getLine(line))
        {
            if (!line.empty())
            {
                parseLine(line);
            }
        }
    }
    return 0;
}