#include <iostream>
#include <vector>
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
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (size_t i = 1; i < vals.size(); i++)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *beforeA = list1;
        for (int i = 0; i < a - 1; i++)
        {
            beforeA = beforeA->next;
        }

        ListNode *afterB = beforeA;
        for (int i = a - 1; i <= b; i++)
        {
            afterB = afterB->next;
        }

        beforeA->next = list2;

        ListNode *tail = list2;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        tail->next = afterB;
        return list1;
    }
};

int main()
{
    Solution s;

    // list1 = [0,1,2,3,4,5], list2 = [1000000,1000001,1000002]
    // a = 3, b = 4
    ListNode *list1 = createList(vector<int>{0, 1, 2, 3, 4, 5});
    ListNode *list2 = createList(vector<int>{1000000, 1000001, 1000002});

    int a = 3, b = 4;

    cout << "Original list1: ";
    printList(list1);
    cout << "list2: ";
    printList(list2);

    ListNode *merged = s.mergeInBetween(list1, a, b, list2);

    cout << "\nMerged list: ";
    printList(merged);

    return 0;
}