/* CD158：向有序的环形单链表中插入新节点 */ 

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
//            if (i == n) {
//                new_pnode->next = phead;
//            }
//        }
//    }
//    return phead;
//}


list_node* insert_num(list_node *head, int num)
{
    list_node *node = new list_node;
    node->val = num;
    node->next = node;
    
    // has 0 node 
    if (head == NULL) {
        return node;
    } 
    
    // has 1 node
    if (head->next == NULL) {
       head->next = node;
       node->next = head;
       return head;
    }
    
    list_node *pre_ptr = head;
    list_node *ptr = head->next;
    while (ptr != head) {
        if (pre_ptr->val <= num && num <= ptr->val) {
            pre_ptr->next = node;
            node->next = ptr;
            break;
        } 
        pre_ptr = pre_ptr->next;
        ptr = ptr->next; 
    }
    
    if (ptr == head) {
        pre_ptr->next = node;
        node->next = ptr;
    }
    
    return head;
}

//void print_list(list_node * head)
//{
//    list_node * h = head;
//    while (1) {
//        printf("%d ", head->val);
//        if (head->next == h) break;
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
//    list_node * new_head = insert_num(head, n);
//    print_list(new_head);
//    return 0;
//}
