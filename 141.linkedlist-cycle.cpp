/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    // Space O(1)
    // bool hasCycle(ListNode *head) {
    //     if (!head || !head->next) return false; // empty or single node

    //     ListNode* slow = head;
    //     ListNode* fast = head;

    //     while (fast && fast->next) {
    //         slow = slow->next;          // move one step
    //         fast = fast->next->next;    // move two steps

    //         if (slow == fast) return true; // cycle detected
    //     }

    //     return false; // no cycle
    // }

    // Space O(n)
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> prev;
        ListNode *next = head;
        while (next != nullptr)
        {
            if (prev.find(next) != prev.end())
                return true;
            prev.insert(next);
            next = next->next;
        }
        return false;
    }
};
