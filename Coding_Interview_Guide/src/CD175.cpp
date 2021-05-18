
// CD175：在二叉树中找到一个节点的后继节点 
#include <iostream> 
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* pre;
    TreeNode(int n): val(n), left(NULL), right(NULL), pre(NULL){}
};

void create(TreeNode*root, int &n)
{
    if (n == 0)
        return;
    int p, l, r;
    cin>>p>>l>>r;
    
    if (l)
    {
        TreeNode* left = new TreeNode(l);
        left->pre = root;
        root->left = left;    
        create(root->left, --n);
    }
    if (r)
    {
        TreeNode* right = new TreeNode(r);
        right->pre = root;
        root->right =right;
        create(root->right, --n);
    }
}


TreeNode* findTar(TreeNode* root, int tar)
{
    if (root == NULL)
        return NULL;
    if (root->val == tar)
        return root;
    TreeNode* r1 = findTar(root->left, tar);
    if (r1 != NULL)
        return r1;
    TreeNode* r2 = findTar(root->right, tar);
        return r2;
}


TreeNode* find_next(TreeNode* node) {
    // assert(node != NULL);
    
    // case 1: 'node' has a right-child tree, next node is in the child tree
    if (node->right != NULL) {
        TreeNode* ptr = node->right;
        while (ptr->left != NULL) {
            ptr = ptr->left;
        }
        return ptr;
    }
    
    // case 2: 'node' has not a right-child tree
    if (node == (node->pre)->left) {
        // case 2-1: 'node' is the left child tree
        return node->pre;
    } else {
        // case 2-2: 'node' is the right child tree
        TreeNode* ptr = node;
        while (ptr->pre != NULL && (ptr->pre)->right == ptr) {
            ptr = ptr->pre;
        }
        
        return ptr->pre;
    }
    
}


int main()
{
    int n,p;
    cin>>n>>p;
    TreeNode* root = new TreeNode(p);
    for (int i=0; i<n; i++)
        create(root, n);
    
    int tarval;
    cin>>tarval;
    TreeNode* tar = findTar(root, tarval);
    
    TreeNode* ret = find_next(tar);
    if (ret == NULL) {
        cout<<0;
    } else {
        cout<<ret->val;
    }
    
}
