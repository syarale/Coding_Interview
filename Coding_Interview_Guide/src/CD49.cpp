/* CD49: 在单链表中删出倒数第K个节点 */ 

#include<bits/stdc++.h>
#include<stdio.h> 
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

int K;

list_node *input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


/* 
 * filename: CD49.cpp (remove_last_kth_node function)
 * author: leisy
 * date:  2020.10.1
 * version: 1.0
 * description: 《programmer code interview》, charpter 2, CD49.  
 *     Delete the last KTH node of a single linked list.
 */
list_node * remove_last_kth_node(list_node *head, int K)
{
	int tmp = 0;
	
	if (head == NULL || K <= 0) {
    	return head;
	} 
	
	
    list_node *last_kth = head;
    list_node *detector = head;

	while (tmp < K - 1 && detector != NULL) {
		detector = detector->next;
		tmp ++;
	}
	
	if (detector == NULL) {
		return last_kth;
	}
	
	/* add auxiliary nodes before head. */
	list_node *aux_node = new list_node();   /* p_last_kth point to the parent node of last_kth(last k-th node) */
	list_node *p_last_kth = aux_node;
	p_last_kth->val = 0;
	p_last_kth->next = head;
	while (detector->next != NULL) {
		detector = detector->next;
		last_kth = last_kth->next;
		p_last_kth = p_last_kth->next; 
	}
	
	/* if delete the first node of list, update head. */
	if (last_kth == head) {
		head = head->next;
	} 
	
	p_last_kth->next = last_kth->next;
	
	last_kth->next = NULL;
	free(last_kth);
	last_kth = NULL;
	
	/* free auxiliary node */
	aux_node->next = NULL;
	free(aux_node);
	aux_node = NULL;
	
	return head;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main ()
{
    list_node * head = input_list(); // 链表的头节点
    list_node * rhead = remove_last_kth_node(head, K);
    print_list(rhead);
    return 0;
}
