/* CD106-1: 删除链表的中间节点 */ 

#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

int K;

list_node * input_list(void) //读入链表
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
 * filename: CD106-1.cpp (remove_last_kth_node function)
 * author: leisy
 * date:  2020.10.1
 * version: 1.0
 * description: 《programmer code interview》, charpter 2, CD106-1.  
 *     Delete the K-th nodes of the linked list.
 */
list_node *remove_kth_node(list_node *head, int K)
{
	if (head == NULL || K<= 0) {
		return head;
	}
	
	/* add auxiliary nodes before head. */
	list_node *aux_node = new list_node();
	aux_node->val = 0;
	aux_node->next = head;
	list_node *p_kth_node = aux_node;     /* point to the parent of K-th node(k-th node will be removed) */
	
	/* now, the list has 1 node at least. */
	for (int i = 0; i < K - 1; i++) { 
		p_kth_node = p_kth_node->next;
		if (p_kth_node == NULL) {
			break;
		}
	}

	
	if (p_kth_node == NULL) {
		return head;
	}
	
	list_node *kth_node = p_kth_node->next;   /* point to k-th node */	
	
	/* if K-th node is the first node of list, update head pointer. */ 
	if (kth_node == head) {
		head = head->next;
	} 
		
	p_kth_node->next = kth_node->next;
		
	kth_node->next = NULL;
	free(kth_node);
	kth_node = NULL;
	
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
    list_node * rhead = remove_kth_node(head, K);
    print_list(rhead);
    return 0;
}
