#include<stdio.h>
#include<stdlib.h>

struct data{
	int age;
	struct data *next;
	struct data *prev;
	
};

struct data *head =NULL;
struct data *tail = NULL;

struct data *create_node(int age){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->prev = NULL;
	node->age = age;
	return node;
}

void push_head(int age){
	struct data* node = create_node(age);
	node->next = head;
	head->prev = node;	
	head = node;
}

void push_tail(int age){
	struct data *node = create_node(age);
	node->prev= tail;
	tail->next= node;
	
	tail = node;
}

void print_linked_list(){
	struct data *temp = head;
	int count = 1;
	while (temp!=NULL){
		printf("data ke %d :%d \n",count,temp->age);
		temp = temp->next;
		count++;
	}	
}

struct data *push_mid(struct data *head, int age, int pos) {
    if (pos == -69) {
        int count = 0;
        if (head == NULL) {
            printf("Linked List is Empty");
        }
        struct data *ptr = head;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        pos = count / 2 + 1;
    }
    struct data *node = create_node(age);
    if (pos == 1) {
        push_head(age);
    }
    struct data *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp != NULL) {
        node->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = node;
        }
        node->prev = temp;
        temp->next = node;
    } 
    return head;
}


struct data *pop_search(struct data *head, int pos) {
    struct data *temp = head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
    return head;
}


void pop_head(){
	struct data *temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);	
}

void pop_tail(){
	struct data *temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	free(temp);
}

int main(){
	head = create_node(2);
	tail = create_node(5);
	
	head->next = tail;
	tail->prev = head;
	
	push_head(1);//depan
	push_tail(10);//belakang
	push_mid(head, 4, -69);
	
	pop_head(); //hapus depan
	pop_tail(); //hapus belakang
	pop_search(head, 3);

	print_linked_list();//parameter kosong tetap pakek parameter
	return 0;
}
