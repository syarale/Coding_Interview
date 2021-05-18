/* CD157：一种怪异的节点删除方式 */ 

#include <iostream>
#include <stdio.h> 
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

//list_node * find_kth_node(list_node * head, int k)
//{
//    list_node * c = head;
//    for (int i = 1; i < k; ++i) c = c->next;
//    return c;
//}
//
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


void remove_node_wired(list_node *node)
{
    list_node *node_next = node->next;
    node->val = node_next->val;
    
    list_node *tmp = node_next->next;
    node->next = tmp;
    delete node_next; 
    return;
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
//    int n;
//    scanf("%d", &n);
//    list_node * node = find_kth_node(head, n);
//    remove_node_wired(node);
//    print_list(head);
//    return 0;
//}
