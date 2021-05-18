
/* CD100��è������ */

/* ��˼�� 
 * 1. �������֮��Ŷ��֡�
 * 2. ������������������ڱ��ڵ��������һ���ڵ㣬ɾ�����һ���ڵ�Ĳ�����ͬ�����⡣  
 * 3. �Զ������������Ƿ�����ָ�򸸽ڵ�ָ�롣 
 * 4. �����в��룬ɾ���ڵ�ע�⣺ָ��ĸ��£��Լ�ָ�������˳���Լ������Ľڵ������ 
 *	  ��һ���ڵ�����������
 * 5. ���������ӵ�ָ������ĺ��壬��ȷѭ������ʽ֮���ٶ���д�� 
 */ 




#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int ISDOG = 1;
const int ISCAT = 0;


/* Pet has 2 derived classes : Cat, Dog*/
class Pet {
public: 
 	string type; 
	int number;  /*the number of Pet */
	
	Pet(){
		
	}; 
	Pet(string type, int number){
		this->type = type;
		this->number = number;
	}

	string get_pet_type(){
		return this->type;
	}

	int get_pet_number() {
		return this->number;
	}


	~Pet(){

	}

};




class Dog:public Pet {

public:
	Dog(){
		
	};
	Dog(string type, int number) {
		this->type = type;
		this->number = number;
	}

	~Dog(){

	}
	
	string get_pet_type(){
		return this->type;
	}

	int get_pet_number() {
		return this->number;
	}


};


class Cat:public Pet {
public:
	Cat() {
		
	};
	Cat(string type, int number) {
		this->type = "cat";
		this->number = number;
	}

	~Cat(){

	}
	
	string get_pet_type(){
		return this->type;
	}

	int get_pet_number() {
		return this->number;
	}

};

class PetNode {

public:
	int pet_type;  /* pet_type is 1 when the type of pet is "dog" */
	Pet pet;
	PetNode *next_pet;
	PetNode *prev_pet;

	PetNode(){
		
	};
	PetNode(int pet_type, Pet inpet, PetNode* prev_pet, PetNode* next_pet) {
		this->pet_type = pet_type;
		this->next_pet = next_pet;
		this->prev_pet = prev_pet;
		this->pet = inpet;
		
	}

	~PetNode() {

	}

};



class PetQueue {
public:
	int len;
	int dognum;
	int catnum;
	PetNode *head;
	PetNode *last;


	int add(string type, int number);
	void poll_all();
	void poll_dog();
	void poll_cat();
	int is_empty();
	int is_dog_empty();
	int is_cat_empty();
	int print_and_removepet(const int pet_type);
	

	PetQueue();
	~PetQueue();
	
};



PetQueue::PetQueue() {
	this->len = 0;
	this->dognum = 0;
	this->catnum = 0;
	this->head = NULL;
	this->last = NULL;
}


PetQueue::~PetQueue(){

}


int PetQueue::add(string type, int number){
	int pet_type = 0;
	PetNode *tmp;

	if (type == "dog"){
		pet_type = 1;
		this->dognum++;
		Dog pet(type, number);
		tmp = new PetNode(pet_type, pet, NULL, NULL);
	} else if(type == "cat") {
		pet_type = 0;
		this->catnum++;
		Cat pet(type, number);
		tmp = new PetNode(pet_type, pet, NULL, NULL);
	} else {
		/* TODO: handle the valid type error */
	}
	
	if (this->head == NULL) {
		this->head = tmp;
		this->last = tmp;
		this->head->prev_pet = NULL;
		this->last->next_pet = NULL;
	} else {
		(this->last)->next_pet = tmp;
	    tmp->prev_pet = this->last;
	    this->last = tmp;
		tmp->next_pet = NULL;	
	}

	this->len++;
	return number;
}


void PetQueue::poll_all(){
	PetNode *ptr = this->head;
	if (!is_empty()) {
		while (ptr != NULL) {
			
			PetNode *tmp = ptr->next_pet;
			ptr->next_pet = NULL;
			ptr->prev_pet = NULL;
			
			cout<<((ptr->pet).get_pet_type())<<" "<<((ptr->pet).get_pet_number())<<endl;
			
			if ((ptr->pet).get_pet_type() == "dog") {   /*�����˸���dognum */ 
				this->dognum--;
			} else {
				this->catnum--;
			}
			
			delete ptr;
			ptr = tmp;
			this->len--; 
		}

	}

	this->head = NULL;
	this->last = NULL;
	/* TODO: hanlde the error, poll pet from a null queue */ 
	return;

}



void PetQueue::poll_dog() {
	print_and_removepet(ISDOG);

}

void PetQueue::poll_cat() {
	print_and_removepet(ISCAT);
}

int PetQueue::print_and_removepet(const int pet_type) {
	
	PetNode *head_ptr = NULL;
	PetNode *last_ptr = NULL;
	PetNode *ptr = this->head; 
	int sum = 0;
	
	if ((pet_type == ISDOG && this->dognum == 0) || 
			pet_type == ISCAT && this->catnum == 0) {
		return 0;		
	}
	
	
	while (ptr != NULL) {
		
		if (ptr->pet_type == pet_type) { 
			PetNode *tmp = ptr->next_pet;
			ptr->next_pet = NULL;
			ptr->prev_pet = NULL;
			cout<<(ptr->pet).get_pet_type()<<" "<<(ptr->pet).get_pet_number()<<endl;
			delete ptr;
			ptr = tmp;
			
			if (pet_type == ISDOG) {
				this->dognum--;
			} else {
				this->catnum--;
			}
			
			this->len--;
			sum++;
		} else {
			if (head_ptr != NULL) {
				last_ptr->next_pet = ptr;
				ptr->prev_pet = last_ptr;
				last_ptr = ptr;
				ptr = ptr->next_pet;
				last_ptr->next_pet = NULL;	
			} else {
				head_ptr = ptr;
				last_ptr = ptr;
				ptr = ptr->next_pet;
				last_ptr->next_pet = NULL;
			}

		}
	}
	
	if (head_ptr != NULL) {
		last_ptr->next_pet = NULL;
	}
	
	this->head = head_ptr;
	this->last = last_ptr;
	
	return sum;
	
}

int PetQueue::is_empty() {
	return (this->len == 0) ? 1 : 0;
}


int PetQueue::is_dog_empty() {
	return (this->dognum == 0) ? 1 : 0;
}


int PetQueue::is_cat_empty() {
	return (this->catnum == 0) ? 1 : 0;
}



int main()
{
	int N;
	PetQueue pet_que;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string cmd = "";
		cin >> cmd;
		
		if (cmd == "add") {
			
			string type = "";
			int number = 0;
			cin >> type >> number;	
			pet_que.add(type, number); 
		} else if(cmd == "pollAll") {
			pet_que.poll_all();
			
		} else if(cmd == "pollDog") {	
			pet_que.poll_dog();
			
		} else if(cmd == "pollCat") {
			pet_que.poll_cat();
			
		} else if(cmd == "isEmpty") {
			
			if (pet_que.is_empty())
				cout<<"yes"<<endl;
			else 
				cout<<"no"<<endl;
		} else if(cmd == "isDogEmpty") {
			
			if (pet_que.is_dog_empty())
				cout<<"yes"<<endl;
			else 
				cout<<"no"<<endl;
		} else if(cmd == "isCatEmpty") {
			if(pet_que.is_cat_empty())
				cout<<"yes"<<endl;
			else 
				cout<<"no"<<endl;
	    } else {
	    	/* handle the invalid input */
		}
	}

	return 0;
}


