#include<iostream>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand() % x)
using namespace std;

// * Definition for singly-linked List;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// * Reverse a singly linked list;
ListNode* reverseList(ListNode* head)
{
    if(head == NULL)
    return NULL;

    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* nt = NULL;

    while(cur)
    {
        nt = cur->next;
        if(pre == head)
        {
            pre->next = NULL;
        }
        cur->next = pre;
        pre = cur;
        cur = nt;
    }

    return pre;
}

// * Create a singly linked list using head inserting;
ListNode* createList(int n)
{
    ListNode *head = new ListNode(random(2));
    srand((int) time(0));
    for(int i = 1; i < n; i++)
    {
        ListNode *cur = new ListNode(random(2));
        cur->next = head->next;
        head->next = cur;
    }

    return head;
}

// * Create a singly incremental  linked list using head inserting;
ListNode* createIncList(int n)
{
    ListNode *head = new ListNode(0);
    for(int i = 1; i < n; i++)
    {
        ListNode *cur = new ListNode(n - i);
        cur->next = head->next;
        head->next = cur;
    }

    return head;
}

// * show the element of singly linked list;
void  showList(ListNode* head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

// * find the last kth node in the linked List
ListNode* findLastKthNode(ListNode* head, int k)
{
    int cnt = 0;
    ListNode* cur = head;
    while(cur)
    {
        cnt++;
        if(cnt == k)
        break;
        cur = cur->next;
    }

    if(cnt != k)
    return NULL;

    while(cur->next)
    {
        head = head->next;
        cur = cur->next;
    }

    return head;
}

// * Delete Node(except the tail) in a Linked List 
// * linked list is 1 -> 2 -> 3 -> 4 and you are given the third node 
// * with value 3, the linked list should become 1 -> 2 -> 4
void deleteNode(ListNode* node)
{
    if(node == NULL)
    return;

    ListNode* tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
    delete tmp;
}

// * Delete Any Node in a Linked List 
void deleteAnyNode(ListNode* head, ListNode* node)
{
    if(!head || !node)
    return;
    
    if(node->next != NULL)
    {
        ListNode* tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
    else if(node == head)
    {
        delete node;
        node = NULL;
        head = NULL;
    }
    else
    {
        while(head->next != node)
        {
            head = head->next;
        }
        
        head->next = NULL;
        delete node;
    }
}

// * Remove Duplicates from Sorted List
// * For example,
// * Given 1->1->2->3->3, return 1->2->3
ListNode* deleteDuplicates(ListNode* head)
{
    if(head == NULL)
    return NULL;

    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* nt = NULL;
    
    while(cur)
    {
        nt = cur->next;

        if(pre->val == cur->val)
        {
            pre->next = nt;
            delete cur;
        }
        else
        {
            pre = cur;
        }

        cur = nt;
    }
    return head;
}

// * Merge two sorted linked lists and return it as a new list
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* head = new ListNode(0);
    ListNode* cur = head;

    while(l1 && l2)
    {
        if(l1->val > l2->val)
        {
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }
        else
        {
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        }
    }

    if(l1)
    cur->next = l1;

    if(l2)
    cur->next = l2;

    return head->next;
}

// * Swap Nodes in Pairs
// * For example,Given 1->2->3->4, 
// * you should return the list as 2->1->4->3.
ListNode* swapPairs(ListNode* head) 
{
    if(head == NULL)
    return NULL;

    ListNode* pnode = new ListNode(0);
    pnode->next = head;
    ListNode* pre = pnode;
    ListNode* cur = head;
    ListNode* nt = head->next;
    ListNode* tmp = NULL;

    while(cur && nt)
    {
        tmp = nt->next;
        pre->next = nt;
        nt->next = cur;
        pre = cur;
        cur = tmp;
        
        if(cur == NULL)
        break;

        nt = cur->next;
    }

    if(cur)
    {
        pre->next = cur;
    }
    else
    {
        pre->next = NULL;
    }

    return pnode->next;
}

// * reverse the nodes of a linked list k at a time
// * For example,
// * Given this linked list: 1->2->3->4->5
// * For k = 2, you should return: 2->1->4->3->5
// * For k = 3, you should return: 3->2->1->4->5
ListNode* reverseKGroup(ListNode* head, int k) 
{
    return NULL;
}

int main()
{
    int n;
    cout << "create a random integer linked list which has n element" << endl;
    cout << "input an integer n: ";
    cin >> n;
    ListNode* head = createList(n);
    cout << "output the current Linked list" << endl;
    showList(head);
    
    head = swapPairs(head);
    cout << "output the linked list which swaps every two adjacent nodes:" << endl;
    showList(head);

    head = reverseList(head);
    cout << "output the reverse List:" << endl;
    showList(head);
    
    cout << "create a random integer linked list which has n element" << endl;
    cout << "input an integer n: " ;
    cin >> n;
    head = createList(n);
    cout << "output the current Linked list" << endl;
    showList(head);
    
    head = deleteDuplicates(head);
    cout << "output the current Linked list whose duplicate nodes are deleted" << endl;
    showList(head);

    ListNode* secondNode = head->next;
    deleteNode(secondNode);
    cout << "output the current Linked list whose second node is deleted" << endl;
    showList(head);
    
    cout << "output the current Linked list whose first node is deleted" << endl;
    deleteAnyNode(head, head);
    showList(head);
    
    cout << "output the current Linked list whose last node is deleted" << endl;
    ListNode* cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    deleteAnyNode(head, cur);
    showList(head);
    
    cout << "input an integer n: " ;
    cin >> n;
    ListNode* head1 = createIncList(n);
    cout << "output the current first Sorted Linked list" << endl;
    showList(head1);
    
    cout << "input an integer n: " ;
    cin >> n;
    ListNode* head2 = createIncList(n);
    cout << "output the current second Sorted Linked list" << endl;
    showList(head2);

    head = mergeTwoLists(head1, head2);
    cout << "output a new list which merges two sorted linked lists" << endl; 
    showList(head);

    cout << " find the last third element in the linked list" << endl;
    cur = findLastKthNode(head, 3);
    if(cur)
    cout << cur->val << endl; 

    return 0;
}

