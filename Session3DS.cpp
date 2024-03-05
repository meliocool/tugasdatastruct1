#include <stdio.h>
#include <stdlib.h>
struct data{
	int age;
	struct data *next; //self reference
};

struct data *create_node(int age){
	//alokasi memori secara dinamis menggunakan malloc
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->age = age;
	return node;
}

struct data *push_head(struct data *head, int age){
	struct data *node = create_node(age);
	node->next = head;
	head = node;
	return head;
}

struct data *push_tail(struct data *head, int age){
	struct data *node = create_node(age);
	struct data *temp = head; //variabel pembantu untuk cek node terakhir
	
	//assign temp ke node terakhir
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = node; //assign address baru ke node paling terakhir untuk simpan alamat node baru
	return head;
}

struct data *push_mid(struct data *head, int age, int pos){
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
        node->next = head;
        head = node;
        return head;
    }
    struct data *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}


struct data *pop_head(struct data *head){
	struct data *temp = head;
	//assign value baru di head untuk simpan dari data kedua
	head = head->next;
	free(temp); //free memory
	
	return head;
}

//hapus data paling terakhir
struct data *pop_tail(struct data *head){
	struct data *del = head;
	struct data *temp = head;
	
	for(;del->next != NULL;){
		temp = del;
		del = del->next;
	}
	temp->next = NULL;
	free(del);
	
	return head;
}

//hapus data tergantung posisi
struct data *pop_search(struct data *head, int pos){
	struct data *temp = head;
	int i = 1;
	while(i < pos - 1 && temp != NULL){
		temp = temp->next;
		i++;
	}
	struct data *del = temp->next;
	temp->next = del->next;
	free(del);
	return head;
}

void print_linked_list(struct data *head){
	struct data *temp;
	temp = head;
	
	int count = 1;
	for(;temp != NULL;){
		printf("Data ke-%d : %d\n", count, temp->age);
		temp = temp->next;
		count++;
	}
}

int main(){
	struct data *head; //pointer
	head = create_node(10);
	
	head = push_head(head, 5); //push head atau insert data di depan
	head = push_head(head, 2);
	head = push_tail(head, 15); //push tail atau insert data di belakang
	head = push_mid(head, 20, -69); //push mid atau insert data di tengah
	
	head = pop_head(head); //hapus data awal
	head = pop_tail(head); //hapus data akhir
	head = pop_search(head, 3); //hapus data di posisi ke-3
	
	print_linked_list(head);
	
	return 0;
}
