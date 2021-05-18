
// CD177：在二叉树中找到两个节点的最近公共祖先(进阶)
// 进阶：如果查询两个节点的最近公共祖先的操作特别频繁，
//       想办法让单条查询的查询时间变小 

#include <iostream>
#include <map>
#include <set> 
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

void dfs_tree(TreeNode* root, map<int, int>& parent_map) {
    if (root == NULL) {
        return;
    }
    
    TreeNode* left_ptr = root->left;
    TreeNode* right_ptr = root->right;
    
    // the root of the tree
    if (parent_map.empty()) {
        parent_map[root->val] = -2147483648;    
    }
    
    
    if (left_ptr != NULL) {
        int left_val = (left_ptr)->val;
        parent_map[left_val] = root->val;
        dfs_tree(left_ptr, parent_map);
    }
    
    if (right_ptr != NULL) {
        int right_val = (right_ptr)->val;
        parent_map[right_val] = root->val;
        dfs_tree(right_ptr, parent_map);
    }
    
    return;
}

void create_map(TreeNode* root, map<int, int>& parent_map) {
    TreeNode* ptr = root;
    dfs_tree(ptr, parent_map);
    return;
}



int get_lowest(int node1_val, int node2_val, map<int, int>& p_map) {
    set<int>parent_set;
    map<int, int>::iterator it1 = p_map.find(node1_val);
    
    if (it1 == p_map.end()) {
        return -1;
    }
    parent_set.insert(node1_val);
    
    while(it1 != p_map.end()) {
        parent_set.insert(it1->second);
        it1 = p_map.find(it1->second);
    }
    
    
    map<int, int>::iterator it2 = p_map.find(node2_val);
    while (parent_set.find(it2->first) == parent_set.end()) {
            it2 = p_map.find(it2->second);    
    }
    
    return it2->first;
}


int main()
{
    int n,p;
    int o1, o2;
    map<int, int> parent_map;
    
    cin>>n>>p;
    TreeNode* root = new TreeNode(p);
    for (int i = 0; i<n; i++)
        create(root, n);
    
    create_map(root, parent_map);
    
    
    
    
    int m;
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>o1>>o2;
        int lowest_ancestor = get_lowest(o1, o2, parent_map);
        if (lowest_ancestor == NULL) {
           cout<<"ERROR";
        } else {
          cout<<lowest_ancestor<<endl;
        }      
    }
    
    return 0;
} 
