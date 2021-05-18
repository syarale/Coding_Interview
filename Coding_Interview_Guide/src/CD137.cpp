/* CD137：删除无序单链表中值重复出现的节点 */ 
#include <iostream>
#include <stdio.h> 
#include <set>
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

void remove_node(list_node *pre_rm, list_node *rm)
{
    //assert(pre_rm != NULL && rm != NULL);
    pre_rm->next = rm->next;
    delete rm;
    return;
}

list_node *remove_rep(list_node *head)
{
   list_node *new_head = head;
   set<int> vset;
   
   /* has 0 node or 1 node */
   if (head == NULL || head->next == NULL) {
   	  return head;
   }
   
   /* has 2 node */
   if ((head->next)->next == NULL) {
       if ((head->val) == (head->next)->val) {
           return head->next;
       } else {
           return head;
       }
   }
   
   list_node *pre_ptr = head;
   list_node *ptr = head->next;
   vset.insert(head->val); 
   while (ptr != NULL) {
       int val = ptr->val;
       if (vset.find(val) != vset.end()) {
           list_node *tmp = ptr->next;
           remove_node(pre_ptr, ptr);
           ptr = tmp;
       } else {
           pre_ptr = ptr;
           ptr = ptr->next;
           vset.insert(val);
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
//    list_node * new_head = remove_rep(head);
//    print_list(new_head);
//    /* 没有释放空间 */ 
//    return 0;
//}
