/* CD156：将搜索二叉树转换成双向链表 */ 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
};

struct BST{
    int val;
    struct BST * lch, * rch;
};

//BST * input_BST()
//{
//    int n, fa, lch, rch;
//    scanf("%d", &n);
//    BST * root, * new_node;
//    map<int, BST *> mp;
//    for (int i = 1; i <= n; ++i) {
//        scanf("%d %d %d", &fa, &lch, &rch);
//        if (mp.find(fa) == mp.end()) {
//            new_node = (BST *)malloc(sizeof(BST));
//            mp[fa] = new_node;
//            new_node->val = fa;
//            if (i == 1) root = new_node;
//        }
//        if (lch && mp.find(lch) == mp.end()) {
//            new_node = (BST *)malloc(sizeof(BST));
//            mp[lch] = new_node;
//            new_node->val = lch; new_node->lch = new_node->rch = NULL;
//        }
//        if (rch && mp.find(rch) == mp.end()) {
//            new_node = (BST *)malloc(sizeof(BST));
//            mp[rch] = new_node;
//            new_node->val = rch; new_node->lch = new_node->rch = NULL;
//        }
//        mp[fa]->lch = (lch ? mp[lch] : NULL);
//        mp[fa]->rch = (rch ? mp[rch] : NULL);
//    }
//    return root;
//}


double_list_node* new_list_node(int val)
{
	double_list_node *ret = new double_list_node;
	ret->val = val;
	ret->next = NULL;
	ret->pre = NULL;
	return ret;
}

void link_node(double_list_node *pre, double_list_node *next) 
{
	// assert(pre != NULL && next != NULL);
	pre->next = next;
	next->pre = pre;
	return;
}

void bst_to_list(BST *root, double_list_node **headpp, double_list_node **lastpp)
{
	double_list_node *left_head, *left_last;
	double_list_node *right_head, *right_last;
	
	if (root == NULL) {
		*headpp = NULL;
		*lastpp = NULL;
		return;
	}

	double_list_node *tmp = new_list_node(root->val);
	bst_to_list(root->lch, &left_head, &left_last);
	bst_to_list(root->rch, &right_head, &right_last);
	
	if (left_head == NULL && right_head == NULL) {
		*headpp = tmp;
		*lastpp = tmp;
		return;
	}

	if (left_head == NULL) {
		link_node(tmp, right_head);
		*headpp = tmp;
		*lastpp = right_last;
		return;
	} 
	
	if (right_head == NULL) {
		link_node(left_last, tmp);
		*headpp = left_head;
		*lastpp = tmp;
	} else {
		link_node(left_last, tmp);
		link_node(tmp, right_head);
		*headpp = left_head;
		*lastpp = right_last;
	}

	return;
}


double_list_node* convert(BST *root)
{
	double_list_node *head, *last;
	if (root == NULL) {
		return NULL;
	}

	bst_to_list(root, &head, &last);
	return head;
}

//void print_double_list(double_list_node * head)
//{
//    while (head != NULL) {
//        printf("%d ", head->val);
//        head = head->next;
//    }
//    puts("");
//}
//
//int main ()
//{
//    BST * root = input_BST();
//    double_list_node * new_double_head = convert(root);
//    print_double_list(new_double_head);
//    return 0;
//}
