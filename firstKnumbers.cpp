#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <ctime>

std::vector<int> printUsingPriorityQueueAndStack(std::vector<int> &vec, int k)
{
    std::vector<int> result;
    std::priority_queue<int> p_queue;
    std::stack<int> stack;
    for (int a : vec)
    {
        p_queue.push(a);
    }
    std::cout << "using priority queue and stack: " << std::endl;
    while (k > 0 && !p_queue.empty())
    {
        stack.push(p_queue.top());
        p_queue.pop();
        k--;
    }
    while (!stack.empty())
    {
        result.push_back(stack.top());
        stack.pop();
    }
    return result;
    // complexity: O(n*logn)---priority queue push;
    //             k*O(1)---priority queue top;
    //             O(n*logn)---priority queue pop;
    //             k*O(1)---stack push;
    //             k*O(1)---stack pop;
}

std::vector<int> printUsingPriorityQueue(std::vector<int> &vec, int k)
{
    std::vector<int> result;
    std::priority_queue<int, std::vector<int>, std::greater<int>> p_queue;
    for (int a : vec)
    {
        p_queue.push(a);
    }
    std::cout << "using priority queue: " << std::endl;
    int count = p_queue.size() - k + 1;
    while (!p_queue.empty())
    {
        if (count > 1)
        {
            p_queue.pop();
            count--;
        }
        else
        {
            result.push_back(p_queue.top());
            p_queue.pop();
        }
    }
    return result;
    // complexity: O(n*logn)---priority queue push;
    //             k*O(1)---priority queue top;
    //             O(n*logn)---priority queue pop;
}

std::vector<int> get_top_k_nums_limited(std::vector<int> &vec, int k)
{
    std::vector<int> result;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int count = k;
    for (int number : vec) // o(n)
    {
        if (count != 0)
        {
            pq.push(number); //k*o(log k)
            count--;
        }
        else if (number > pq.top())
        {
            pq.pop();// n-k o(log k)
            pq.push(number);// n-k o(log k)
        }
    }

    while (!pq.empty()) // 2*o(k)
    {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
int main()
{
    std::vector<int> vec(15);
    srand(time(0));
    for (int i = 0; i < 15; i++)
    {
        vec[i] = rand() % 100;
    }
    for (int a : vec)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::vector<int> version1 = printUsingPriorityQueueAndStack(vec, 5);
    for (int a : version1)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::vector<int> version2 = printUsingPriorityQueue(vec, 5);
    for (int a : version2)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::vector<int> limited = get_top_k_nums_limited(vec, 5);
    for (int a : limited)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------------------" << std::endl;

    return 0;
}