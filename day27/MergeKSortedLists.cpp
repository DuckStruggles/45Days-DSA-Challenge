#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

struct compare
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->data > b->data;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    for (auto list : lists)
    {
        if (list)
            pq.push(list);
    }
    ListNode *dummy = new ListNode;
    dummy->next = nullptr;
    ListNode *tail = dummy;

    while (!pq.empty())
    {
        ListNode *curr = pq.top();
        pq.pop();
        tail->next = curr;
        tail = tail->next;

        if (curr->next)
            pq.push(curr->next);
    }
    return dummy->next;
}

int main()
{
    vector<vector<int>> v = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}};

    vector<ListNode *> lists;

    for (auto &a : v)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        for (int x : a)
        {
            ListNode *node = new ListNode;
            node->data = x;
            node->next = nullptr;

            if (!head)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }

        lists.push_back(head);
    }

    ListNode *ans = mergeKLists(lists);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}