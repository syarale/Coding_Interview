/* leetcode 138: 复制含有随机指针节点的链表 */ 

//#include <map>
//#include <unordered_map>
//using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
		Node* ptr;
		map<Node*, Node*> node_map;
		//unordered_map<Node*, Node*> node_map;

		if (head == NULL) {
			return NULL;
		}

		ptr = head;
		while (ptr != NULL) {
			Node *copy_ptr = new Node(ptr->val);
			node_map.insert(pair<Node*, Node*>(ptr, copy_ptr));
			ptr = ptr->next;
		}

		ptr = head;
		Node *copy_head = node_map[head];
		while (ptr != NULL) {
			Node *copy_ptr = node_map[ptr];
			Node *next_ptr = node_map[ptr->next];
			Node *random_ptr = node_map[ptr->random];
			copy_ptr->next = next_ptr;
			copy_ptr->random = random_ptr;
			ptr = ptr->next;
		}

		return copy_head;
    }
};
