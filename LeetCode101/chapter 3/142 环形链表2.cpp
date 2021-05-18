// 142����������2

// solution: ����ָ�룬Floyd ��Ȧ��

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        if (head == nullptr) {
            return head;
        } 
        
        do {
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            
            slow = slow->next;
            fast = (fast->next)->next;
        } while (slow != fast);
        
        // exist cycle
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        } 
        
        return fast;
    }
}; 
