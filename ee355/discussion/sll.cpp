



class Node{
	int iD;
	Node* next;
}

class SLL {
	Node* search(int someID);
}

///Q1 which one? private, public, protected, friend
///Q2: design pseudo code for SLL::search

///1. public
///2. search ----
Node* SLL::search(int someID){
	Node* ptr = head;
	while(ptr){
		if ptr->id == id;
			return ptr;
		else 
			ptr = ptr->next;
	}
	return NULL;


}

bool SLL::remove(int id){

	Node* ptr = head;
	if !ptr
		return false;
	if ptr->id == id
		delete ptr;
		return true;

	while(ptr->next){
		if(ptr->next->id == id)

		if (ptr->next-> id== id){

			Node* toBeDeleted = ptr->next
			ptr->next = ptr->next->next;
			delete toBeDeleted;
			return true;
		}
		else
			ptr = ptr->next;
	}
	return false;
}