#include <iostream>
#include <vector>
#include <algorithm>

class MinHeap
{
private:
    std::vector<int> myVec = {1, 2, 3, 4, 5};

private:
    int rootIndex(int i)
    {
        return (i - 1) / 2;
    }

public:
    MinHeap() {};

    void push(int num)
    {
        myVec.push_back(num);
        int i = myVec.size() - 1;

        while (i > 0)
        {
            int parentI = rootIndex(i);
            if (myVec[parentI] > myVec[i])
            {
                std::swap(myVec[parentI], myVec[i]);
                i = parentI;
            }
            else
            {
                break;
            }
        }
    }

    void pop() // delete top
    {
        if (myVec.empty())
        {
            std::cout << "Error: Empty" << std::endl;
            return;
        }
        else if (myVec.size() == 1)
        {
            myVec.pop_back();
        }
        else
        {
            int i = 0;
            myVec[i] = myVec[myVec.size() - 1];
            myVec.pop_back();
            int k = i;
            while (i < myVec.size())
            {
                k = i;

                if (2 * i + 1 < myVec.size() && myVec[2 * i + 1] < myVec[k])
                {
                    k = 2 * i + 1;
                }
                if (2 * i + 2 < myVec.size() && myVec[2 * i + 2] < myVec[k])
                {
                    k = 2 * i + 2;
                }
                if (i != k)
                {
                    std::swap(myVec[i], myVec[k]);
                    i = k;
                }
                else
                {
                    break;
                }
            }
        }
    }

    int top() const
    {
        if (!myVec.empty())
        {
            return myVec[0];
        }
        std::cout << "Error: Empty" << std::endl;
        return -1;
    }

    int size() const
    {
        return myVec.size();
    }

    void print() const
    {
        for (int num : myVec)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    MinHeap minHeap;

    minHeap.push(5);
    minHeap.print();

    minHeap.push(4);
    minHeap.print();

    minHeap.push(3);
    minHeap.print();

    minHeap.push(2);
    minHeap.print();

    minHeap.push(1);
    minHeap.print();

    minHeap.push(0);
    minHeap.print();

    std::cout << "delete top element" << std::endl;
    minHeap.pop();
    minHeap.print();

    return 0;
}