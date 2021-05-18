/* CD159：合并两个有序的单链表 */ 
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
		//assert(*lastpp == NULL);
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


list_node *link_list(list_node *head, list_node *last, list_node *ptr) 
{
	//assert(ptr != NULL);
	if (head == NULL) {
		//assert(last == NULL);
		return ptr;
	} else {
		last->next = ptr;
		return head;
	}
}

list_node *merge_list(list_node *head1, list_node *head2)
{
	list_node *ptr1 = head1;
	list_node *ptr2 = head2;

	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}

	list_node *new_head = NULL;
	list_node *new_last = NULL;
	while (ptr1 != NULL && ptr2 != NULL) {
		if (ptr1->val < ptr2->val) {
			list_node *tmp = ptr1->next;
			add_list(&new_head, &new_last, ptr1);
			ptr1 = tmp;
		} else {
			list_node *tmp = ptr2->next;
			add_list(&new_head, &new_last, ptr2);
			ptr2 = tmp;
		}
	}

	if (ptr1 != NULL) {
		new_head = link_list(new_head, new_last, ptr1);
	} else {
		new_head = link_list(new_head, new_last, ptr2);
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
//int main ()
//{
//    list_node * head1 = input_list();
//    list_node * head2 = input_list();
//    list_node * new_head = merge_list(head1, head2);
//    print_list(new_head);
//    return 0;
//}
