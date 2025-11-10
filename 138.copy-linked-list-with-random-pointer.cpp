#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mapping;
        Node *it = head;
        while (it != nullptr)
        {
            Node *newNode = new Node(it->val);
            mapping[it] = newNode;
            it = it->next;
        }
        it = head;
        while (it != nullptr)
        {
            mapping[it]->random = mapping[it->random];
            mapping[it]->next = mapping[it->next];
            it = it->next;
        }

        return mapping[head];
    }
};

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;

    n1->random = n3;
    n2->random = n1;
    n3->random = n3;

    Solution sol;
    Node *copiedHead = sol.copyRandomList(n1);

    Node *curr = copiedHead;
    while (curr != nullptr)
    {
        cout << "Node val: " << curr->val << ", ";
        if (curr->random)
            cout << "Random val: " << curr->random->val;
        else
            cout << "Random val: null";
        cout << endl;
        curr = curr->next;
    }

    return 0;
}