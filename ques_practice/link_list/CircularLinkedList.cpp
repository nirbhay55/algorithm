#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insert(node* &head, int data){
	
	node* n = new node(data);
	if (head==NULL){
		head = n;
		return;
	}

	node* temp = head;
	while(temp->next!=NULL) {
	    temp = temp->next;
	}

	temp->next = n;
	return;
}

void display(node* head, int data){

	while(data--) {
	    cout<<head->data;
	    head = head->next;
	}
	return;
}

void detect(node* a){

	int count = 0;
	node* b=a->next->next;
	while(a->data != b->data) {
	    a = a->next;
	    b=b->next->next;
	    count++;
	}
	display(a,count);
}

int main(int argc, char const *argv[]){
	
	node* head=NULL;
	int data;
	cin>>data;
	
	while(data != -1) {
	    insert(head, data);
	    cin>>data;
	}
	detect(head);

	return 0;
}