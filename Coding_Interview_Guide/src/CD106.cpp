/* CD106: 删除链表的中间节点 */ 


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
 * filename: CD106.cpp (remove_last_kth_node function)
 * author: leisy
 * date:  2020.10.1
 * version: 1.0
 * description: 《programmer code interview》, charpter 2, CD106.  
 *     Delete the intermediate nodes of the linked list.
 */
list_node *remove_kth_node(list_node *head, int K)
{

	int list_num = 0;
	int rmnode_th;               /* the k-th node will be deleted */
	list_node *count_ptr = head;
	
	if (head == NULL || head->next == NULL || K<= 0) {
		return head;
	}
	
	/* if the list has two node, remove the first node */
	if ((head->next)->next == NULL) {
		list_node *tmp = head;
		head = head->next;
		tmp->next = NULL;
		free(tmp);
		return head;
	}
	
	
    /* get the num of list */ 
    while (count_ptr != NULL) {
    	list_num ++;
    	count_ptr = count_ptr->next;
	}
	
//	printf("list num: %d\n", list_num);
	rmnode_th = ceil(double(list_num / 2.0));    /* note: cann't divided by 2(int), otherwise, the result will be int type */
//	printf("rmnode_th: %d\n", rmnode_th);
	
	/* now, the list has 3 node at least. */
	list_node *p_mid_node = head;     /* point to the parent of middle node(middle node will be removed) */
	for (int i = 0; i < rmnode_th - 2; i++) { 
		p_mid_node = p_mid_node->next;
	}
	
	list_node *mid_node = p_mid_node->next;   /* point to middle node */
	p_mid_node->next = mid_node->next;
	mid_node->next = NULL;
//	printf("mid val: %d\n", mid_node->val);
	free(mid_node);
	mid_node = NULL;
	
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
