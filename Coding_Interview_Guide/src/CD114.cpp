/* CD114: 两个单链表生成相加链表 */ 

#include <iostream>
#include <stack>
#include <stdio.h> 
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
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


/* My work: push_val() */
void push_val(const list_node* head, stack<int>& num)
{
	const list_node *ptr;
	if (head == NULL) {
		return;
	}
	
	ptr = head;
	while (ptr != NULL) {
		num.push(ptr->val);
		ptr = ptr->next;
	}
	
	return;
}


/* My work: get_val() */ 
int pop_val(stack<int>& num)
{
	if (num.empty()) {
		return 0;
	} else {
		int ret = num.top();
		num.pop();
		return ret;
	}
}


/* Mywork: add_node() */

void add_node(int val, list_node **head, list_node **last)
{
	//assert(head != NULL);
	//assert(last != NULL);
	list_node *ptr = new list_node;
	ptr->val = val;
	ptr->next = NULL;
	if (*head == NULL) {
//		assert(*last == NULL);
		*head = ptr;
		*last = ptr;
	} else {
		ptr->next = *head;
		*head = ptr;
	}
	return;	
} 


/* My work: sum_to_list() */
list_node* sum_to_list(stack<int> num1, stack<int> num2)
{
//	assert(!num1.empty());
//	assert(!num2.empty());	
	
	list_node *sum_head = NULL;
	list_node *sum_last = NULL;
	int carry = 0, digit = 0;
	int val1  = 0, val2  = 0;
	
	while ((!num1.empty()) || (!num2.empty())) {
		int sum_val;
		
		val1 = pop_val(num1); // the num1 will call pop() and return the val.
		val2 = pop_val(num2);
		sum_val = val1 + val2 + carry;
		digit = sum_val % 10;
		add_node(digit, &sum_head, &sum_last);
		carry = sum_val / 10;
	}
	
	if (carry != 0) {
		add_node(carry, &sum_head, &sum_last);
	}
	
	return sum_head;
}


/* My work: add_list() */
list_node* add_list(list_node *head1, list_node *head2)
{
    stack<int> num1;
	stack<int> num2;
	list_node *sum_head;

	if (head1 == NULL || head2 == NULL) {
		return NULL;
	}	
	
	push_val(head1, num1);
	push_val(head2, num2);
	sum_head = sum_to_list(num1, num2);
	 
	return sum_head;
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
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}
