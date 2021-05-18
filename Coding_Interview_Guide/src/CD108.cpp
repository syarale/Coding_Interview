/* CD108: 反转部分单向链表 */
 
# include <bits/stdc++.h>
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


list_node *reverse_list(list_node *head, int L, int R)
{
	list_node *reverse_ptr = NULL;
	list_node *lth_ptr = NULL;    /* point to l-th node */
	list_node *p_lth_ptr = NULL;  /* point to parent of l-th node. */ 
	list_node *n_rth_ptr = NULL;  /* point to next of r-th node */
	
	/* assert(L > 0 && L <= R); */
    if (head == NULL) {
    	return head;
	}
	
	/* locate the L-th node */ 
	if (L >= 2) {
		int i = 0;
		p_lth_ptr = head;
		while (i < L - 2 && p_lth_ptr != NULL) {
			p_lth_ptr = p_lth_ptr->next;
			i++;
		}
		
		if (p_lth_ptr == NULL || p_lth_ptr->next == NULL) {   /* L > size of list */
			return head;
		}
		lth_ptr = p_lth_ptr->next; 
	} else {
	    lth_ptr = head;
	}
	
	/* reverse list from L-th to R-th node */
	list_node *new_head = NULL;
	list_node *new_back = lth_ptr;
	reverse_ptr = lth_ptr;
	for (int i = L; i <= R; i++) {
		if (reverse_ptr == NULL) {
			break;
		}
		
		list_node *tmp = reverse_ptr;
		reverse_ptr = reverse_ptr->next;
		tmp->next = new_head;
		new_head = tmp;
	}
	
	
	/* locate next node of r-th node */
	n_rth_ptr = reverse_ptr;  /* if R > size of list, n_rth_ptr = reverse_ptr = null */
	
	/* re-link list */
	if (p_lth_ptr != NULL) {
		p_lth_ptr->next = new_head;
	} else {
		head = new_head;
	}
	new_back->next = n_rth_ptr;
	
    return head;

}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    scanf("%d%d", &L, &R);
    list_node * new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}
