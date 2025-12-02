#include <climits>
#include <iostream>
#include <string>
#include <stack>
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
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *newone = nullptr;
        ListNode *nextstep = head;

        while (nextstep != nullptr)
        {
            ListNode *next = nextstep->next;
            nextstep->next = newone;

            newone = nextstep;
            nextstep = next;
        }

        return newone;
    }
    ListNode *findMid(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode *head)
    {
        ListNode *mid = findMid(head);
        ListNode *secondHalf = mid->next;
        mid->next = nullptr;
        ListNode *endptr = reverse(secondHalf);
        ListNode *startptr = head;
        int count = 1;
        while (endptr != nullptr && startptr != nullptr)
        {
            count++;
            if (startptr == endptr)
                break;
            ListNode *tmpnextfromstart = startptr->next;
            ListNode *tmpnextfromend = endptr->next;
            startptr->next = endptr;
            endptr->next = tmpnextfromstart;
            startptr = tmpnextfromstart;
            endptr = tmpnextfromend;
        }
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next = new ListNode(6);

    cout << "original\n";
    printList(head);

    s.reorderList(head);
    // ListNode *aaaa = s.reverse(head);
    cout << "output\n";
    printList(head);
    return 0;
}