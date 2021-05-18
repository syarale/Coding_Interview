/* CD160：按照左右半区的方式重新组合单链表 */ 
#include <iostream>
#include <stdio.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};


//list_node * input_list(void)
//{
//    int n, val;
//    list_node * phead = new list_node();
//    list_node * cur_pnode = phead;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; ++i) {
//        scanf("%d", &val);
//        if (i == 1) {
//            cur_pnode->val = val;
//            cur_pnode->next = NULL;
//        }
//        else {
//            list_node * new_pnode = new list_node();
//            new_pnode->val = val;
//            new_pnode->next = NULL;
//            cur_pnode->next = new_pnode;
//            cur_pnode = new_pnode;
//        }
//    }
//    return phead;
//}

void add_list(list_node **headpp, list_node **lastpp, list_node *ptr)
{
	//assert(headpp != NULL && lastpp != NULL && ptr != NULL);
	if (*headpp == NULL) {
		// assert(*lastpp == NULL);
		*headpp = ptr;
		*lastpp = ptr;
		(*lastpp)->next = NULL;
	} else {
		(*lastpp)->next = ptr;
		*lastpp = ptr;
		(*lastpp)->next = NULL;
	}
	return;
}


int get_len(list_node *ptr)
{
	int len = 0;
	list_node *tmp = ptr;
	while (tmp != NULL) {
		len++;
		tmp = tmp->next;
	}
	return len;
}

list_node* relocate(list_node *head)
{
	int len = get_len(head);
	int half_len = len / 2;

	// 节点数小于三时，链表无需调整
	if (len <= 3) {
		// if head == NULL, then len = 0;
		return head;
	}

	list_node *left_head = head;
	list_node *left_last = head;
	for (int i = 0; i < half_len - 1; i++) {
		left_last = left_last->next;
	}

	list_node *right_head = left_last->next;
	left_last->next = NULL;

	//cout << "left_head: " << left_head->val << endl;
	//cout << "right_head: " << right_head->val << endl;

	list_node *new_head = NULL;
	list_node *new_last = NULL;
	list_node *ptr1 = left_head;
	list_node *ptr2 = right_head;
	while (ptr1 != NULL && ptr2 != NULL) {
		list_node *tmp1 = ptr1->next;
		list_node *tmp2 = ptr2->next;
		add_list(&new_head, &new_last, ptr1);
		add_list(&new_head, &new_last, ptr2);
		ptr1 = tmp1;
		ptr2 = tmp2;
	}

	if (ptr1 != NULL) {
		// can not happen
		add_list(&new_head, &new_last, ptr1);
	}  else if (ptr2 != NULL) {
		// may happen
		add_list(&new_head, &new_last, ptr2);
	}

	return new_head;
}

//void print_list(list_node * head)
//{
//    while (head != NULL) {
//        printf("%d ", head->val);
//        head = head->next;
//    }
//    puts("");
//}
//
//
//int main ()
//{
//    list_node * head = input_list();
//    list_node * new_head = relocate(head);
//    print_list(new_head);
//    return 0;
//}
