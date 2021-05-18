
/* 
 * CD113：将单向链表按某值划分成左边小、中间相等、右边大的形式 
 * 时间复杂度：O(N), 空间复杂度 O(1)
 *  
 * “墨痕断处听江流 ” -- 2020.11.19. 
 */


#include <iostream>
#include <stdio.h>
//#include <assert.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

struct list_info {
	struct list_node *head;
	struct list_node *last;
};

void print_list(list_node* ptr)
{
	list_node *p = ptr;
	while (p != NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	return;
}

list_info* init_list(list_info *ptr)
{
  
	list_info *new_list;
	if (ptr != NULL) {
		ptr->head = NULL;
		ptr->last = NULL;	  
	}
	new_list = ptr;
	return new_list;
}

int pivot;
list_node* input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d%d", &n, &pivot);
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

list_info* add_list(list_info* list_ptr, list_node* node_ptr)
{
//	assert(list_ptr != NULL);
//	assert(node_ptr != NULL);
	if (list_ptr->head == NULL) {
		list_ptr->head = node_ptr;
		list_ptr->last = node_ptr;
		node_ptr->next = NULL;
	} else {
		(list_ptr->last)->next = node_ptr;
		list_ptr->last = node_ptr;
		node_ptr->next = NULL;
	}
	return list_ptr;
	
}

list_info* link_list(list_info* list_ptr1, list_info* list_ptr2)
{
//	assert(ptr1 != NULL);
//	assert(ptr2 != NULL);

	list_info* new_list;
	if (list_ptr1->head == NULL) {
		new_list = list_ptr2;
	} else if (list_ptr2->head == NULL) {
		new_list = list_ptr1;
	} else {
		(list_ptr1->last)->next = list_ptr2->head;
		list_ptr1->last = list_ptr2->last;
		(list_ptr2->last)->next = NULL;
		new_list = list_ptr1;
	}

	return new_list;
}




list_node* list_partition(list_node *head, int pivot)
{

    list_node *ptr;
	list_info *new_list;
    list_info *smaller_list = new list_info();
    list_info *equal_list = new list_info();
    list_info *larger_list = new list_info();
    
    smaller_list = init_list(smaller_list);
    equal_list = init_list(equal_list);
    larger_list = init_list(larger_list);

    if (head == NULL || head->next == NULL) {
    	return head;
	}
	
	ptr = head;	
	while (ptr != NULL) {
		list_node *tmp = ptr->next;
		if (ptr->val < pivot) {
			smaller_list = add_list(smaller_list, ptr);
		} else if(ptr->val == pivot) {
			equal_list = add_list(equal_list, ptr);
		} else {
			larger_list = add_list(larger_list, ptr);
		}
		ptr = tmp;
	}
	
	new_list = link_list(smaller_list, equal_list);
	new_list = link_list(new_list, larger_list);	
	list_node *ret = new_list->head;
	
	delete smaller_list;
	delete equal_list;
	delete larger_list;
	return ret;
}


int main()
{
    list_node *head = input_list();
    list_node *new_head = list_partition(head, pivot);
	print_list(new_head);
    return 0;
}
  
