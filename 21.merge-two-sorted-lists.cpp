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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main()
{
    Solution s;

    // list1 = [0,1,2,3,4,5], list2 = [1000000,1000001,1000002]
    // a = 3, b = 4
    ListNode *list1 = createList(vector<int>{0, 0, 2, 3, 4, 5});
    ListNode *list2 = createList(vector<int>{4, 7, 9});

    int a = 3, b = 4;

    cout << "Original list1: ";
    printList(list1);
    cout << "list2: ";
    printList(list2);

    ListNode *merged = s.mergeTwoLists(list1, list2);

    cout << "\nMerged list: ";
    printList(merged);

    return 0;
}