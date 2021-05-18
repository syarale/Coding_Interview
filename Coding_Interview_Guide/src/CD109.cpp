
/* CD109：环形单链表的约瑟夫问题 */ 

 
#include <iostream>
using namespace std;

struct node {
	int num;
	node* prev;
	node* next;
};


node* create_cycle(int len) {
	node* head;
	node* curr;
	if (len <= 0) {
		return NULL;
	}
	
	head = new node;
	head->num = 1;
	curr = head;
	
	for (int i = 2; i <= len; i++) {
		node* tmp = new node;
		tmp->num = i;
		curr->next = tmp;
		tmp->prev = curr;
		curr = tmp;
	} 
	
	head->prev = curr;
	curr->next = head;
	return head;
}


/* Remove node, and return the next node of curr */
node* remove_node(node* curr) {
	node* prev_curr = NULL;
	node* next_curr = NULL;
	
	if (curr == NULL || curr->next == curr) {
		return curr;
	}
	
	prev_curr = curr->prev;
	next_curr = curr->next;
	prev_curr->next = next_curr;
	next_curr->prev = prev_curr;
	delete curr;
	
	curr = next_curr;
	return curr;
}


/* 
 * Remove the m-th node from head point node of cycle-list
 * Return the next node of removed node
 */ 
node* remove_mth_node(node* head, int m) {
	node* new_head = NULL;
	node* curr = head;
	
	if (head == NULL || head->next == head) {
		return head;
	}
	
	for (int i = 0; i < m - 1; i++) {
		curr = curr->next;
	}
	new_head = remove_node(curr);
	return new_head;
}

int get_alive_node(node* head, int m) {
	node* curr = head;
	
	if (head == NULL) {
		return -1;
	}
	
	if (head->next == head) {
		return head->num;
	}
	
	while (curr->next != curr) {
		curr = remove_mth_node(curr, m);
	}
	
	return curr->num;
}

int main()
{
	int m, n, result;
	node* head;
	
	cin>>n>>m;
	head = create_cycle(n);

	result = get_alive_node(head, m);
	cout<<result;
	
	return 0;
}
