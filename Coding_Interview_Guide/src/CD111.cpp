/* CD111: 判断一个链表是否为回文结构 */ 

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

/* solution 1: O(N) time, O(N) space */
list_node * check(list_node * head)
{
	stack<int> comp;
	bool is_palindrome;
	list_node* tmp;

	if (head == NULL) {
		return NULL;
	}

	tmp = head;
	while (tmp != NULL) {
		comp.push(tmp->val);
		tmp = tmp->next;
	}

	tmp = head;
	is_palindrome = true;
	while (tmp != NULL) {
		if (tmp->val != comp.top()) {
			is_palindrome = false;
			break;
		}
		tmp = tmp->next;
		comp.pop();
	}

	if (is_palindrome) {
		printf("true");
	} else {
		printf("false");
	}

	return tmp;
}

int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}
