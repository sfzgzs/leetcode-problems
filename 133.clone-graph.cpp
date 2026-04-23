#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<int, Node *> visited;
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        Node *head = new Node(node->val);
        visited[node->val] = head;

        stack<Node *> st;
        st.push(node);

        while (!st.empty())
        {
            Node *current = st.top();
            st.pop();

            for (Node *neigh : current->neighbors)
            {
                if (visited.find(neigh->val) == visited.end())
                {
                    visited[neigh->val] = new Node(neigh->val);
                    st.push(neigh);
                }
                visited[current->val]->neighbors.push_back(visited[neigh->val]);
            }
        }

        return head;
    }
};