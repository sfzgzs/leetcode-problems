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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // ListNode *reverseList(ListNode *head)
    // {
    //     if (head == nullptr || head->next == nullptr)
    //         return head;

    //     ListNode *newHead = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return newHead;
    // }
    ListNode *revHelp(ListNode *newone, ListNode *nextstep)
    {
        if (nextstep == nullptr)
            return newone;

        ListNode *next = nextstep->next;
        nextstep->next = newone;
        return revHelp(nextstep, next);
    }

    ListNode *reverseList(ListNode *head)
    {
        return revHelp(nullptr, head);
    }
};
int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode *reversed = s.reverseList(head);

    for (ListNode *p = reversed; p != nullptr; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << endl;

    return 0;
}