#include<iostream>
using namespace std;

int binarySearch(int a[], int length, int value)
{
    int low  =  0;
    int high = length - 1;
    int mid = 0;
    
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(a[mid] == value)
        return mid;
        else if(a[mid] > value)
        high = mid - 1;
        else
        low = mid + 1;
    }

    return -1;
}

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* searchBST(TreeNode* head, int value)
{
    if(head == NULL)
    return NULL;

    if(head->val == value)
    return head;

    if(head->val > value)
    searchBST(head->left, value);
    else
    searchBST(head->right, value);   
}

TreeNode* insertBST(TreeNode* head, int value)
{
    if(head == NULL)
    {
        head = new TreeNode(value);
        return head;
    }

    if(head->val > value)
    head->left = insertBST(head->left, value);
    else
    head->right = insertBST(head->right, value);

    return head;
}

void insertBST2(TreeNode* head, int value)
{
    if(head == NULL)
    {
        head = new TreeNode(value);
        return;
    }

    while(head)
    {
        if(head->val > value)
        {
            if(head->left == NULL)
            {
                head->left = new TreeNode(value);
                return;
            }
            else
            {
                head = head->left;
            }   
        }
        else
        {
            if(head->right == NULL)
            {
                head->right = new TreeNode(value);
                return;
            }
            else
            {
                head = head->right;
            }
            
        }

    }
}

TreeNode* deleteBST(TreeNode* head, int value)
{
    TreeNode* cur = searchBST(head, value);

    if(cur == NULL)
    return NULL;
    
    deleteBST(head, cur);
}

TreeNode* deleteBST(TreeNode* head, TreeNode* cur)
{
        
}

int main()
{
    return 0;
}
