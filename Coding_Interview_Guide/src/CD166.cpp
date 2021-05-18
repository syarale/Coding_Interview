/* CD166：找到二叉树中的最大搜索二叉子树 */
 
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_VAL = 1000001;
const int MIN_VAL = -1;

struct treeNode
{
    int val;
    struct treeNode *lch, *rch;
      
    treeNode(){}
    treeNode(int v):val(v), lch(nullptr), rch(nullptr){}
};

struct search_tree_info
{
	int max_val, min_val, max_size;
	treeNode *sub_root;
	//search_tree_info() {};
	search_tree_info():
		max_val(MIN_VAL), min_val(MAX_VAL), max_size(0), sub_root(NULL) {};
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

void copy_info(search_tree_info *src, search_tree_info *des)
{
	des->max_size = src->max_size;
	des->max_val = src->max_val;
	des->min_val = src->min_val;
	des->sub_root = src->sub_root;
	return;
}

void get_max_tree(treeNode *root, search_tree_info *infop)
{
	//assert(root != NULL);
	if (root->lch == NULL && root->rch == NULL) {  // leaf node  
		infop->max_size = 1;
		infop->max_val = root->val;
		infop->min_val = root->val;
		infop->sub_root = root;
		return;
	}

	if (root->lch != NULL && root->rch == NULL) {
		search_tree_info *left_info = new search_tree_info();
		get_max_tree(root->lch, left_info);
		if (root->lch == left_info->sub_root && root->val >= left_info->max_val) {
			infop->max_size = left_info->max_size + 1;
			infop->max_val = root->val;
			infop->min_val = left_info->min_val;
			infop->sub_root = root;
		} else {
			copy_info(left_info, infop);
		}
		delete left_info;
		return;
	}
	
	if (root->lch == NULL && root->rch != NULL) {
		search_tree_info *right_info = new search_tree_info();
		get_max_tree(root->rch, right_info);
		if (root->rch == right_info->sub_root && root->val <= right_info->min_val) {
			infop->max_size = right_info->max_size + 1;
			infop->min_val = root->val;
			infop->max_val = right_info->max_val;
			infop->sub_root = root;	
		} else {
			copy_info(right_info, infop);
		}
		delete right_info;
		return;
	}

	search_tree_info *left_info = new search_tree_info();
	search_tree_info *right_info = new search_tree_info();
	get_max_tree(root->lch, left_info);
	get_max_tree(root->rch, right_info);
	if (root->lch == left_info->sub_root && root->rch == right_info->sub_root &&
		left_info->max_val <= root->val && root->val <= right_info->min_val) {
		infop->max_size = left_info->max_size + right_info->max_size + 1;
		infop->max_val = right_info->max_val;
		infop->min_val = left_info->min_val;
		infop->sub_root = root;
	} else {
		if (left_info->max_size > right_info->max_size) {
			copy_info(left_info, infop);
		} else {
			copy_info(right_info, infop);
		}
	}


	delete left_info;
	delete right_info;
	return;
}


int main()
{
    int n, r;
	int max_val, min_val, max_size;
	treeNode *sub_root;
	search_tree_info *tree_infop = new search_tree_info();

    scanf("%d %d", &n, &r);
    treeNode* root = new treeNode(r);
    createTree(root);

	//assert(root != NULL);
	get_max_tree(root, tree_infop);
	sub_root = tree_infop->sub_root;
	if (sub_root != NULL) {
		cout << tree_infop->max_size;
	}

	delete tree_infop;
    return 0;
}
