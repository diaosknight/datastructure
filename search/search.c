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
    {
        return searchBST(head->left, value);
    }
    else
    {
        return searchBST(head->right, value);  
    }
}

TreeNode* insertBST(TreeNode* head, int value)
{ 
    if(head == NULL)
    {
        head = new TreeNode(value);
        return head;
    }

    if(head->val > value)
    {
        head->left = insertBST(head->left, value);
    }
    else
    {
        head->right = insertBST(head->right, value);
    }

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

void deleteBST(TreeNode* head, int value)
{
    bool flag = false;
    TreeNode* pre = new TreeNode(0);
    pre->left = head;
    TreeNode* cur = head;
    
    while(!flag && cur)
    {
        if(cur->val == value)
        {
            flag = true;
        }
        else if(cur->val > value)
        {
            pre = cur;
            cur = cur->left;
        }
        else
        {
            pre = cur;
            cur = cur->right;
        }
    }
    
    if(flag == false)
    return;

    if(cur->left == NULL)
    {
        if(pre->left == cur)
        {
            pre->left = cur->right;
        }
        else
        {
            pre->right = cur->right;
        }

        break;
    }

    if(cur->right == NULL)
    {
        if(pre->left == cur)
        {
            pre->left = cur->left;
        }
        else
        {
            pre->right = cur->right;
        }

        break;
    }

    TreeNode* t = cur;
    TreeNode* s = cur->left;
    
    while(s->rchild)
    {
        t = s;
        s = s->rchild;
    }

    cur->val = s->val;
   
   if(s == cur->left)
    {
        cur->left = s->left;
    }
    else
    {
        t->left = s->left;
    }
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
