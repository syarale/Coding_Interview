/* CD138：在单链表中删除指定值的节点 */
 
#include <iostream>
#include <stdio.h> 
using namespace std;

struct list_node{
    int val;
    struct list_node *next;
};

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


list_node *remove_value(list_node *head, int num)
{
    list_node *ptr = head;
    
    if (head == NULL) {
        return NULL;
    }
    
    while (ptr != NULL && ptr->val == num) {
        list_node *tmp = ptr->next;
        delete ptr;
        ptr = tmp;
    }
    
    if (ptr == NULL) {
        return NULL;
    }
    
    list_node *new_head = ptr;
    list_node *pre_ptr = ptr;
    ptr = ptr->next;
    while (ptr != NULL) {
        if (ptr->val == num) {
            list_node *tmp = ptr->next;
            pre_ptr->next = tmp;
            delete ptr;
            ptr = tmp;
        } else {
            pre_ptr = pre_ptr->next;
            ptr = ptr->next;
        }
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
//    list_node * head = input_list();
//    int num;
//    scanf("%d", &num);
//    list_node * new_head = remove_value(head, num);
//    print_list(new_head);
//    return 0;
//}
