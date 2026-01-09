class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k <= 1)
            return head;

        int len = 0;
        ListNode *itr = head;
        while (itr)
        {
            len++;
            itr = itr->next;
        }

        int groupsCount = len / k;
        if (groupsCount == 0)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prevGroupEnd = &dummy;
        ListNode *curr = head;

        while (groupsCount--)
        {
            ListNode *groupStart = curr;
            ListNode *prev = nullptr;

            for (int i = 0; i < k; i++)
            {
                ListNode *nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            prevGroupEnd->next = prev;
            groupStart->next = curr;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
