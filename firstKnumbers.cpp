#include <iostream>
#include <array>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>

void printUsingPriorityQueueAndStack(std::array<int, 15>& arr, int k)
{
    std::priority_queue<int> p_queue;
    std::stack<int> stack;
    for(int a : arr)
    {
        p_queue.push(a);
    }
    std::cout << "using priority queue and stack: " << std::endl;
    while(k > 0 && !p_queue.empty())
    {
        stack.push(p_queue.top());
        p_queue.pop();
        k--;
    }
    while(!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
    // complexity: O(n*logn)---priority queue push;
    //             k*O(1)---priority queue top;
    //             O(n*logn)---priority queue pop;
    //             k*O(1)---stack push;
    //             k*O(1)---stack pop;
}

void  printUsingPriorityQueue(std::array<int, 15>& arr, int k)
{
    std::priority_queue<int,std::vector<int>, std::greater<int>> p_queue;
    for(int a : arr)
    {
        p_queue.push(a);
    }
    std::cout << "using priority queue: " << std::endl;
    int count = p_queue.size()-k+1;
    while (!p_queue.empty())
    {
        if(count > 1)
        {
            p_queue.pop();
            count--;
        }
        else
        {
            std::cout << p_queue.top() << " ";
            p_queue.pop();
        }

    }
    std::cout << std::endl;
    // complexity: O(n*logn)---priority queue push;
    //             k*O(1)---priority queue top;
    //             O(n*logn)---priority queue pop;
}
int main()
{
    std::array<int, 15> arr;
    srand(time(0));
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand()%100;
    }
    for(int a : arr)
    {
        std::cout << a << " ";  
    }
    std::cout << std::endl;
    printUsingPriorityQueueAndStack(arr, 5);
    std::cout << "-----------------------------" << std::endl;
    printUsingPriorityQueue(arr, 5);
    return 0;
}