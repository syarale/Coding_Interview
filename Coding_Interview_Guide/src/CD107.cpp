/* CD107: 反转单向链表,反转双向链表 */
 
#include<bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};
struct double_list_node{
    int val;
    struct double_list_node *pre, *next;
};

list_node *input_list(void)
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

double_list_node * input_double_list(void)
{
    int n, val;
    double_list_node * phead = new double_list_node();
    double_list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
            cur_pnode->pre = NULL;
        }
        else {
            double_list_node * new_pnode = new double_list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            new_pnode->pre = cur_pnode;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

list_node *reverse_list(list_node *head)
{
    list_node *ptr = head;
    list_node *new_head = NULL;
    
    if (head == NULL) {
    	return head;
	}
    
    while (ptr != NULL) {
    	list_node *tmp = ptr;
    	ptr = ptr->next;
    	tmp->next = new_head;
    	new_head = tmp;
	}
    
    return new_head;

}

double_list_node *reverse_double_list(double_list_node *head)
{
    double_list_node *ptr = head;
    double_list_node *new_head = NULL;
	
	if (head == NULL) {
		return head;
	} 
	while (ptr != NULL) {
		double_list_node *tmp = ptr;
		
		ptr = ptr->next;
		tmp->next = new_head;
		if (new_head != NULL) {
			new_head->pre = tmp;
		}
		new_head = tmp;
	}
    new_head->pre = NULL;
    
    return new_head;

}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

void print_double_list(double_list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    list_node * head = input_list();
    double_list_node * double_head = input_double_list();
    list_node * new_head = reverse_list(head);
    double_list_node * new_double_head = reverse_double_list(double_head);
    print_list(new_head);
    print_double_list(new_double_head);
    return 0;
}
