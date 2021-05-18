
/* CD187：派对的最大快乐值 */ 

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
  

void get_max_happiness(treeNode* root, int& max_happiness, int& yes_x, int& no_x) {
    int yes_lch = 0, no_lch = 0;
    int yes_rch = 0, no_rch = 0;
    int lch_max_happiness = 0, rch_max_happiness = 0;
    
    if (root == NULL) {
        yes_x = 0;
        no_x = 0;
        return;
    }
     
    get_max_happiness(root->lch, lch_max_happiness, yes_lch, no_lch);
    get_max_happiness(root->rch, rch_max_happiness, yes_rch, no_rch);
    
    yes_x = root->val + no_lch + no_rch;
    no_x = max(yes_lch, no_lch) + max(yes_rch, no_rch);
    max_happiness = max(yes_x, no_x);
    
    return;
}


int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    treeNode* root = new treeNode(r);
    createTree(root);
    
    int max_happiness = 0;
    int l_happiness = 0;
    int r_happiness = 0;
    
    get_max_happiness(root, max_happiness, l_happiness, r_happiness);
    cout<<max_happiness;
    

    return 0;
}
