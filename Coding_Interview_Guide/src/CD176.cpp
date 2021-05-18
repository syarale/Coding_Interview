
// CD176：在二叉树中找到两个节点的最近公共祖先 
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

TreeNode* get_lowest(TreeNode* curr, TreeNode* node1, TreeNode* node2) {
    // assert(o1 != o2);
    TreeNode* left_ret;
    TreeNode* right_ret;
    
    if (curr == NULL || curr == node1 || curr == node2) {
        return curr;
    }
    
    left_ret = get_lowest(curr->left, node1, node2);
    right_ret = get_lowest(curr->right, node1, node2);
    if (left_ret == NULL && right_ret == NULL) {
        return NULL;
    }
    
    if (left_ret != NULL && right_ret != NULL) {
        return curr;
    }
    
    if (left_ret == NULL && right_ret != NULL) {
        return right_ret;
    } else {
        return left_ret;
    }
     
}


int main()
{
    int n,p;
    cin>>n>>p;
    TreeNode* root = new TreeNode(p);
    for (int i=0; i<n; i++)
        create(root, n);
    
    int o1, o2; 
    cin>>o1>>o2;
    TreeNode* tar1 = findTar(root, o1);
    TreeNode* tar2 = findTar(root, o2);
    TreeNode* lowest_ancestor = get_lowest(root, tar1, tar2);
    if (lowest_ancestor == NULL) {
        cout<<"ERROR";
    } else {
        cout<<lowest_ancestor->val;
    }
    
    return 0;
} 
