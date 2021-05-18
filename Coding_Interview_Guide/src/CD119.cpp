/* CD119: 将单链表的每 K个节点之间逆序 */

//#include <iostream>
//#include <stdio.h> 
//using namespace std;

struct list_node{
    int val;
    struct list_node *next;
};

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
//list_node * input_list()
//{
//    int val, n;
//    scanf("%d", &n);
//    list_node * phead = new list_node();
//    list_node * cur_pnode = phead;
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


void reverse_list(list_node *head, list_node *last, list_node **headpp, list_node **lastpp)
{
//	assert(head != NULL && rhead != NULL, rlast != NULL);
	list_node *ptr = head;
	list_node *rhead = NULL;
	list_node *rlast = NULL;
	
	while (ptr != last) {
		list_node *tmp = ptr->next;
		if (rhead == NULL) {
			//assert(rlast == NULL);
			rhead = ptr;
			rlast = ptr;
			rlast->next = NULL;
		} else {
			ptr->next = rhead;
			rhead = ptr;
			
		}
		ptr = tmp;
	}
	
	*headpp = rhead;
	*lastpp = rlast;	
	return;
}


list_node *reverse_knode(list_node *head, int k)
{
	list_node *new_head = head;
	list_node *new_last = NULL;
	list_node *ptr = head;
	
	if (head == NULL || k <= 1) {
		return head;
	}
	
	while (ptr != NULL) {
		list_node *p = ptr;
		list_node *rhead, *rlast;
		for (int i = 0; i < k - 1; i++) {
			p = p->next;
			if (p == NULL) {
				break;
			}
		}
		
		if (p == NULL) {
			return new_head;
		}
		
		// reverse list [head, last)
		p = p->next;
		reverse_list(ptr, p, &rhead, &rlast);
		if (new_last == NULL) {
			new_head = rhead;
			new_last = rlast;
			new_last->next = p;
		} else {
			new_last->next = rhead;
			new_last = rlast;
			new_last->next = p;
		}
		
		ptr = p;
	}

	return new_head;
}

//int main ()
//{
//    list_node * head = input_list();
//    int K;
//    scanf("%d", &K);
//    list_node * new_head = reverse_knode(head, K);
//    print_list(new_head);
//    return 0;
//}
 
