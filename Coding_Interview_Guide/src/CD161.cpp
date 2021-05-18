/* CD161：用非递归方式实现二叉树的先序，中序，和后序遍历 */ 

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
  
struct treeNode
{
    int val;
    struct treeNode *lch, *rch;
      
    treeNode(){}
    treeNode(int v):val(v), lch(nullptr), rch(nullptr){}
};
  
//void createTree(treeNode* root)
//{
//    int r, lch, rch;
//    scanf("%d %d %d", &r, &lch, &rch);
//    if(lch){
//        root->lch = new treeNode(lch);
//        createTree(root->lch);
//    }
//    if(rch){
//        root->rch = new treeNode(rch);
//        createTree(root->rch);
//    }
//}
  
void visit(const treeNode *ptr)
{
	cout << ptr->val << " ";
	return;
}

void preorder(const treeNode *root)
{
	const treeNode *ptr;
	stack<treeNode* > buff;
	
	if (root == NULL) {
		return;
	}
	
	ptr = root;
	for (;;) {
		if (ptr != NULL) {
			visit(ptr);
			if (ptr->rch != NULL) {
				buff.push(ptr->rch);
			}
			ptr = ptr->lch;
		} else {
			if (!buff.empty()) {
				ptr = buff.top();
				buff.pop();
			} else {
				break;
			}
		}
	}
	cout << endl;
	return;
}
  
void inorder(const treeNode *root)
{
	const treeNode *ptr;
	stack<const treeNode* > buff;
	
	if (root == NULL) {
		return;
	}
	
	ptr = root;
	for (;;) {
		if (ptr != NULL) {
			buff.push(ptr);
			ptr = ptr->lch;
		} else {
			if (!buff.empty()) {
				ptr = buff.top();
				buff.pop();
				visit(ptr);
				ptr = ptr->rch;
			} else {
				break;
			}
		}
	}
	cout << endl;
	return;

}
  
void posorder(const treeNode *root)
{
	int is_scaned;           // node has been scaned.
	const treeNode *ptr;
	stack<pair<const treeNode *, int> > buff;   // <node, is_scaned>

    if (root == NULL) {
        return;
    }

	ptr = root;
	is_scaned = 0;
	for (;;) {
		if (ptr == NULL && buff.empty()) {
			break;
		}

		if (ptr != NULL) {
			if (!is_scaned) {
				buff.push(pair<const treeNode *, int>(ptr, 1));
				if (ptr->rch != NULL) {
					buff.push(pair<const treeNode *, int>(ptr->rch, 0));
				}
				ptr = ptr->lch;
				continue;
			}
			visit(ptr);
		}

		if (!buff.empty()) {
			pair<const treeNode *, int> tmp = buff.top();
			buff.pop();
			ptr = tmp.first;
			is_scaned = tmp.second;
		} else {
			ptr = NULL;
		}
	}
		
	return;
}
//  
//int main()
//{
//    int n, r;
//    scanf("%d %d", &n, &r);
//    treeNode* root = new treeNode(r);
//    createTree(root);
//    preorder(root);
//    inorder(root);
//    posorder(root);
//      
//    return 0;
//}
