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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        for (int i = 0; i < n; i++)
            ptr2 = ptr2->next;
        if (ptr2 == nullptr)
        {
            head = head->next;
            return head;
        }
        while (ptr2 != nullptr && ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr1->next->next;
        return head;
    }
};

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

int main()
{
    Solution s;

    ListNode *list1 = createList(vector<int>{0, 0, 2, 3, 4, 5});

    int a = 3, b = 4;

    cout << "Original list1: ";
    printList(list1);

    ListNode *rmvd = s.removeNthFromEnd(list1, 3);

    cout << "\nResulting list: ";
    printList(rmvd);
}