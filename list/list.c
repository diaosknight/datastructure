#include<iostream>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand() % x)
using namespace std;

// * Definition for singly-linked List;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// * Reverse a singly linked list;

ListNode* reverseList(ListNode* head)
{
    if(head == NULL)
    return NULL;

    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* next = NULL;

    while(cur)
    {
        next = cur->next;
        if(pre == head)
        {
            pre->next = NULL;
        }
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

// * Create a singly linked list using head inserting;
ListNode* createList(int n)
{
    ListNode *head = new ListNode(random(100));
    srand((int) time(0));
    for(int i = 1; i < n; i++)
    {
        ListNode *cur = new ListNode(random(100));
        cur->next = head->next;
        head->next = cur;
    }
    return head;

}

// * show the element of singly linked list;
ListNode* showList(ListNode* head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "create a random integer linked list which has n element" << endl;
    cout << "input an integer n:" ;
    cin >> n;
    cout << endl;
    ListNode* head = createList(n);
    cout << "output the current Linked list" <<endl;
    showList(head);
    head = reverseList(head);
    cout << "output the reverseList:" << endl;
    showList(head);
    return 0;
}

