/* CD48: ��ӡ������������Ĺ������� */ 

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //����Ľڵ�


list_node *input_list(void)              //��������
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

void sol(list_node *a_head, list_node *b_head)
{
    list_node *a_ptr = a_head;
	list_node *b_ptr = b_head;
	
	while(a_ptr != NULL && b_ptr != NULL) {
		if (a_ptr->val == b_ptr->val) {
			printf("%d ", a_ptr->val);
			a_ptr = a_ptr->next;
			b_ptr = b_ptr->next;
		} else if (a_ptr->val < b_ptr->val) {
			a_ptr = a_ptr->next;
		} else {
			b_ptr = b_ptr->next;
		}
	} 
}

int main ()
{
    list_node * a_head = input_list(); // A �����ͷ�ڵ�
    list_node * b_head = input_list(); // B �����ͷ�ڵ�
    sol(a_head, b_head);
    return 0;
}

