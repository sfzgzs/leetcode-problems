#include <queue>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class SmallestInfiniteSet
{
public:
    int minIndex = 1;
    vector<bool> data;
    SmallestInfiniteSet()
    {
        for (int i = 0; i < 1002; i++)
            data.push_back(true);
        minIndex = 1;
    }

    int popSmallest()
    {
        int tmp = minIndex;
        data[minIndex] = false;
        while (!data[minIndex])
            minIndex++;
        return tmp;
    }

    void addBack(int num)
    {
        if (num < minIndex)
            minIndex = num;
        data[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */