/* CD139：单链表的选择排序 */

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
//        }
//    }
//    return phead;
//}


/* [head, ptr), 返回第一个值大于num的节点的前驱节点 */ 
list_node* get_insert_loc(list_node *head, list_node *last, int num)
{
    list_node *ptr = head;
    
    //assert(head != NULL)
    if (num <= head->val) {
        return NULL;
    } 
    
    while (ptr->next != last && (ptr->next)->val < num) {
        ptr = ptr->next;
    }
    
    return ptr;
}


list_node* selection_sort(list_node *head)
{
    list_node *new_head = head;
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    list_node *ptr = head->next;
    list_node *pre_ptr = head;
    while (ptr != NULL) {
        list_node *tmp = ptr->next;
        list_node *insertp = get_insert_loc(new_head, ptr, ptr->val);  // [new_head, ptr)
        if (insertp == NULL) {
            // 插在head之前
            ptr->next = new_head;
            new_head = ptr;
            pre_ptr->next = tmp;
            ptr = tmp;
        } else if (insertp->next != ptr) {
            list_node *p = insertp->next;
            insertp->next = ptr;
            ptr->next = p;
            pre_ptr->next = tmp;
            ptr = tmp;
        }  else {
            pre_ptr = pre_ptr->next;
            ptr = tmp;    
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
//
//int main ()
//{
//    list_node * head = input_list();
//    list_node * new_head = selection_sort(head);
//    print_list(new_head);
//    return 0;
//}
