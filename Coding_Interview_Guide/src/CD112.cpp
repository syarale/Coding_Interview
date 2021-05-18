/* CD112：判断一个链表是否为回文结构(进阶，时间复杂度 O(N), 空间复杂度O(1)) */ 

#include <stdio.h>
#include <stack>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
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


int count_len(list_node* ptr) {
	int len = 0;
	list_node* tmp = ptr;
	while (tmp != NULL) {
		len++;
		tmp = tmp->next;
	}

	return len;
}

/* 
 * Split the linked list into three sections. 
 * 
 * Input: head
 * Output: lhead, mid, rhead
 * 
 * If the linked list has an odd number of nodes, the middle section has just one node,
 * otherwise, has no node(mid is null). The lhead and rhead have same number of nodes.
 */
void split_list(list_node* head, list_node** lhead, list_node** mid, list_node** rhead) {
	int len, half_len;
	list_node* tmp;

	if (head == NULL || lhead == NULL || mid == NULL || rhead == NULL) {
		return;
	}

	len = count_len(head);
	if (len == 1) {
		*mid = NULL;
		*lhead = head;
		*rhead = head;
		return;
	}

	tmp = head;
	half_len = len / 2;
	for (int i = 0; i < half_len - 1; i++) {
		tmp = tmp->next;
	}

	*lhead = head;
	if ((len % 2) == 0) {
		*mid = NULL;
		*rhead = tmp->next;
		tmp->next = NULL;
	} else {
		*mid = tmp->next;
		*rhead = (tmp->next)->next;
		tmp->next = NULL;
		(*mid)->next = NULL;
	}

	return;
}


/* Unite three list to one list.
 * Return the head pointer of new list. */
list_node* unite_list(list_node* lhead, list_node* mid, list_node* rhead) {
	list_node* new_head = lhead;
	list_node* ptr = new_head;
	
	if (new_head == NULL) {
		return NULL;
	}

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	if (mid != NULL) {
		ptr->next = mid;
		mid->next = rhead;
	} else {
		ptr->next = rhead;
	}
	return new_head;

}

list_node* reverse_list(list_node* head) {
	list_node* ptr;
	list_node* new_head, *new_last;

	if (head == NULL || head->next == NULL) {
		return head;
	}

	new_head = head;
	new_last = head;
	ptr = head->next;
	while (ptr != NULL) {
		list_node* tmp = ptr->next;
		ptr->next = new_head;
		new_head = ptr;
		ptr = tmp;
	}
	new_last->next = NULL;
	return new_head;
}


int is_same_list(list_node* head1, list_node* head2) {
	list_node* ptr1 = head1;
	list_node* ptr2 = head2;

	if (head1 == NULL || head2 == NULL || head1 == head2) {
		return 1;
	}

	while (ptr1 != NULL && ptr2 != NULL) {
		if (ptr1->val != ptr2->val) {
			break;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	if (ptr1 == NULL && ptr2 == NULL) {
		return 1;
	} else {
		return 0;
	}
}

/* solution 2: O(N) time, O(1) space */
list_node * check(list_node * head)
{
	int is_palindrome;
	list_node* tmp1, *tmp2, *tmp3;
	list_node** lhead = &tmp1;
	list_node** mid = &tmp2;;
	list_node** rhead = &tmp3;
	list_node* new_head;

	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		printf("true");
		return head;
	}

	new_head = head;
	split_list(new_head, lhead, mid, rhead);
	*rhead = reverse_list(*rhead);
	
	is_palindrome = is_same_list(*lhead, *rhead);
	if (is_palindrome) {
		printf("true");
	} else {
		printf("false");
	}

	*rhead = reverse_list(*rhead);
	new_head = unite_list(*lhead, *mid, *rhead);

	return new_head;
}

int main ()
{
    int L, R;
	list_node * head = input_list();
	check(head);
    return 0;
}
