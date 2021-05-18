
/* LeetCode 160�������������ཻ(�޻�) */
/* ������Ա��������ָ�ϡ� �ڶ��£������������ཻ��һϵ������ ����ĿΪ�������л��������޻����Ѷȸ��� */ 

/* 
 * Definition for singly-linked list.
 * struct ListNode {
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
private:
	int length(const ListNode *head) {
		int len = 0;
		const ListNode *ptr = head;
		
		if (head == NULL) {
			return 0;
		}
		
		while (ptr != NULL) {
			len++;
			ptr = ptr->next;
		}
		len++;
		return len;
	}
	
	ListNode* move(ListNode **ptr, int dis) {
		if (ptr == NULL || *ptr == NULL) {
			return NULL;
		}
		
		ListNode *ret = *ptr;
		for (int i = 0; i < dis; i++) {
			ret = ret->next;
		}
		
		return ret;
	}
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
		if (headA == NULL || headB == NULL) {
        	return NULL;
		}
		
		int lenA = length(headA);
		int lenB = length(headB);
		if (lenA > lenB) {
			ptrA = move(&ptrA, lenA - lenB);
		} else {
			ptrB = move(&ptrB, lenB - lenA);
		}
		
		while (ptrA != NULL && ptrB != NULL && ptrA != ptrB) {
			ptrA = ptrA->next;
			ptrB = ptrB->next;
		}
		
		if (ptrA == NULL || ptrB == NULL) {
			return NULL;
		} else {
			return ptrA;
		}
    }
};

