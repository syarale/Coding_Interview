/* CD168：二叉树的按层打印与ZigZag打印 */ 

#include <iostream>
#include <queue>
#include <stack>
using namespace std;


struct treeNode
{
    int val;
    struct treeNode *lch, *rch;
      
    treeNode(){}
    treeNode(int v):val(v), lch(nullptr), rch(nullptr){}
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

void bfs_print(const treeNode *root)
{
	int layers;
	int curr_node_num, next_node_num;
	queue<const treeNode *> bfsque;
	const treeNode *ptr;
	
	ptr = root;
	if (ptr == NULL) {
		return;
	}

	bfsque.push(ptr);
	layers = 1;
	curr_node_num = 1;
	next_node_num = 0;
	cout << "Level " << layers << " : ";
	while (!bfsque.empty()) {
		const treeNode *tmp = bfsque.front();
		bfsque.pop();
		cout << tmp->val << " ";
		if (tmp->lch != NULL) {
			bfsque.push(tmp->lch);
			next_node_num++;
		}

		if (tmp->rch != NULL) {
			bfsque.push(tmp->rch);
			next_node_num++;
		}
		
		curr_node_num--;
		if (curr_node_num == 0 && !bfsque.empty()) {
			//assert(next_node_num == 0);
			layers++;
			curr_node_num = next_node_num;
			next_node_num = 0;
			cout << endl;
			cout << "Level " << layers << " : ";
		}
	}

	return;
}


void tranvers_oddlayer(stack<const treeNode *>& odd_layer, 
	stack<const treeNode *>& even_layer)
{
	while (!odd_layer.empty()) {
		const treeNode *tmp = odd_layer.top();
		odd_layer.pop();
		if (tmp->lch != NULL) {
			even_layer.push(tmp->lch);
		}

		if (tmp->rch != NULL) {
			even_layer.push(tmp->rch);
		}
		cout << tmp->val << " ";
	}
	return;
}


void tranvers_evenlayer(stack<const treeNode *>& odd_layer, 
	stack<const treeNode *>& even_layer)
{
	while (!even_layer.empty()) {
		const treeNode *tmp = even_layer.top();
		even_layer.pop();
		if (tmp->rch != NULL) {
			odd_layer.push(tmp->rch);
		}

		if (tmp->lch != NULL) {
			odd_layer.push(tmp->lch);
		}
		cout << tmp->val << " ";
	}
	return;
}

void tranvers(int layers, 
	stack<const treeNode *>& odd_layer, stack<const treeNode *>& even_layer)
{
	if (layers % 2 == 0) {
		if (even_layer.empty()) {
			return;
		}
		cout << "Level " << layers << " from right to left: ";
		tranvers_evenlayer(odd_layer, even_layer);
		cout << endl;
	} else {
		if (odd_layer.empty()) {
			return;
		}
		cout << "Level " << layers << " from left to right: ";
		tranvers_oddlayer(odd_layer, even_layer);
		cout << endl;
	}
	
	return;
}

void zigzag_print(const treeNode *root)
{
	stack<const treeNode *> odd_layer;
	stack<const treeNode *> even_layer;
	int layers;
	const treeNode *ptr = root;

	if (ptr == NULL) {
		return;
	}
	
	layers = 1;
	odd_layer.push(ptr);
	for (;;) {
		if ((layers % 2 != 0 && odd_layer.empty()) || 
			(layers % 2 == 0 && even_layer.empty())){
			break;
		}
		tranvers(layers, odd_layer, even_layer);
		layers++;
	}

	return;
}


int main()
{
    int n, r;


    scanf("%d %d", &n, &r);
    treeNode* root = new treeNode(r);
    createTree(root);

	//assert(root != NULL);
	bfs_print(root);
	cout << endl;
	zigzag_print(root);


    return 0;
}
