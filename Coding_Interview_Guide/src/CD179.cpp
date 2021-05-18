/* CD179：二叉树节点间的最大距离问题 */ 

#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
  
struct treeNode
{
    int val;
    struct treeNode *lch, *rch;
      
    treeNode(){}
    treeNode(int v):val(v), lch(NULL), rch(NULL){}
};
  
void createTree(treeNode* root)
{
    int r, lch, rch;
    scanf("%d %d %d", &r, &lch, &rch);
    if(lch){
        root->lch = new treeNode(lch);
        createTree(root->lch);
    }
    if(rch){
        root->rch = new treeNode(rch);
        createTree(root->rch);
    }
}
  

void get_max_distance(treeNode* root, int& max_distance, int& height) {
    
    
    int l_height = 0;
    int r_height = 0;
    int l_max_distance = 0;
    int r_max_distance = 0;
    
    //todo:base
    if (root == NULL) {
        max_distance = 0;
        height = 0;
        return;
    }
    
    get_max_distance(root->lch, l_max_distance, l_height);
    get_max_distance(root->rch, r_max_distance, r_height);
    height = max(l_height, r_height) + 1;
    max_distance = max((l_height + r_height + 1), max(l_max_distance, r_max_distance));
    
    return;    
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    treeNode* root = new treeNode(r);
    createTree(root);
    
    int max_distance = 0;
    int height = 0;
    get_max_distance(root, max_distance, height);
    cout<<max_distance;

    return 0;
}
