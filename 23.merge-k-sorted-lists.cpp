#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

void printvector(const vector<ListNode *> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i]->val << " ";
    cout << endl;
}
void myinsertsort(vector<ListNode *> &list, ListNode *toinsert)
{
    int begin = 0;
    int end = list.size();

    while (begin < end)
    {
        int mid = begin + (end - begin) / 2;

        if (toinsert->val >= list[mid]->val)
            end = mid;
        else
            begin = mid + 1;
    }

    list.insert(list.begin() + begin, toinsert);
}
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> heads;
        for (auto l : lists)
            if (l)
                heads.push_back(l);

        if (heads.empty())
            return nullptr;

        sort(heads.begin(), heads.end(),
             [](ListNode *a, ListNode *b)
             { return a->val > b->val; });

        ListNode *newhead = heads.back();
        heads.pop_back();

        ListNode *tmp = newhead->next;
        newhead->next = nullptr;
        if (tmp)
            myinsertsort(heads, tmp);

        ListNode *mainitr = newhead;

        while (!heads.empty())
        {
            ListNode *last = heads.back();
            heads.pop_back();

            tmp = last->next;
            last->next = nullptr;

            mainitr->next = last;
            mainitr = last;

            if (tmp)
                myinsertsort(heads, tmp);
        }

        return newhead;
    }
};

ListNode *buildList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *cur = head;
    for (int i = 1; i < vals.size(); i++)
    {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

int main()
{
    Solution s;
    // Input: lists = [[1,4,5],[1,3,4],[2,6]]
    vector<vector<int>> data = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}};

    vector<ListNode *> lists;
    for (auto &v : data)
    {
        lists.push_back(buildList(v));
    }
    ListNode *result = s.mergeKLists(lists);

    // Expected output: 1->1->2->3->4->4->5->6
    printList(result);

    return 0;
}