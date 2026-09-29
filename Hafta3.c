#include <stdio.h>
#include <stdlib.h>
#pragma region Ornek_1
typedef struct Node{
    int data;
    Node* next;
}Node;
void addOrdered(Node** head,int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void removeNode(Node** head, int value) {
    //Liste tamamen boşsa yapacak bir şey yok
    if (*head == NULL) return;

    Node* temp = *head;

    //Silmek istediğimiz değer en baştaysa
    if (temp->data == value) {
        *head = temp->next; 
        free(temp);         
        return;
    }
    Node* prev = NULL;
    
    // temp null olana kadar veya aradığımız değeri bulana kadar ilerle
    while (temp != NULL && temp->data != value) {
        prev = temp;       // Geçerli düğümü önceki olarak kaydet
        temp = temp->next; // bi' sonrakine geç
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
void printList(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d->",current->data);
        if(current->next == NULL){
            printf("%d",current->data);
        }
        current = current->next;
    }
    printf("\n");
}
int count(Node* head){
    Node* current = head;
    int totalNode = 0;
    while(current != NULL){
        totalNode++;
        current = current->next;
    }
    return totalNode;
}
void clear(Node** head){
    Node* current = *head;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("Tum dugumler serbest birakildi.\n");
}
int main(){
    Node* head = NULL;
    Node* node1 = malloc(sizeof(Node));
    node1->data = 0;
    node1->next = NULL;
    head = node1;

    addOrdered(&head, 10);
    addOrdered(&head, 20);
    addOrdered(&head, 30);

    printList(head);
    
    printf("Dugum sayisi: %d\n", count(head));

    removeNode(&head, 10);
    removeNode(&head, 0);
    
    printList(head);

    clear(&head);

    return 0;
}
#pragma endregion
#pragma region Ornek_2
typedef struct NodeN{
    int data;
    NodeN* next;
}NodeN;


// ÖRNEK 2'NİN ÖNEMLİ FONKSİYONU


void insertAt(NodeN** head,int value,int position){
    NodeN* NewNode = malloc(sizeof(NodeN)); // 1. pozisyon = 0. index demektir. i'yi index için kullanacağım.
    NewNode->data = value;
    NodeN* current = *head;
    NodeN* prev = NULL;
    int i = 0;
    if(position == 0){
        NewNode->next = *head;
        *head = NewNode;
        return;
    }
    while((i < position) && (current != NULL)){
        prev = current;
        current = current->next;
        i++;
    }
    if (prev != NULL) {
        prev->next = NewNode;
    }
    NewNode->next = current;
}

void deleteAt(NodeN** head,int position){
    NodeN* temp = *head;
    NodeN* prev = NULL;
    if(position==0){
        if (temp == NULL) {
        return; 
    }
        *head = temp->next;
        free(temp);
        return;
    }
    int i=0;
    while((i<position) && (temp!=NULL)){
        prev = temp;
        temp = temp->next;
        i++;
    }
    if(temp == NULL){return;}
    prev->next = temp->next;
    free(temp);
}

// ÖRNEK 2'NİN ÖNEMLİ FONKSİYONLARI


void printList(NodeN* head){
    NodeN* current = head;
    while(current != NULL){
        printf("%d->",current->data);
        if(current->next == NULL){
            printf("NULL",current->data);
        }
        current = current->next;
    }
    printf("\n");
}
void clear(NodeN** head){
    NodeN* current = *head;
    while(current != NULL){
        NodeN* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("Tum dugumler serbest birakildi.\n");
}

int main(){
    NodeN *node = NULL;
    NodeN *node2 = malloc(sizeof(NodeN));
    NodeN *node3 = malloc(sizeof(NodeN));
    NodeN *node4 = malloc(sizeof(NodeN));
    NodeN *node5 = malloc(sizeof(NodeN));
    node2->data = 1; node2->next = node3; node = node2;
    node3->data = 2; node3->next = node4;
    node4->data = 3; node4->next = node5;
    node5->data = 4; node5->next = NULL;
    insertAt(&node,10,3);
    deleteAt(&node,2);
    printlist(node);
}
#pragma endregion
#pragma region Ornek_3
typedef struct NodeA{
    int data;
    NodeA next;
}NodeA;
int count(NodeA* head){
    NodeA* current = head;
    int totalNode = 0;
    while(current != NULL){
        totalNode++;
        current = current->next;
    }
    return totalNode;
}


// ÖRNEK 3'ÜN ÖNEMLİ FONKSİYONU


NodeA* findMiddle(NodeA* head) {
    if (head == NULL) {
        return NULL;
    }
    NodeA *slow = head; 
    NodeA *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         
        fast = fast->next->next;    
    }
    return slow;
}


// ÖRNEK 3'ÜN ÖNEMLİ FONKSİYONU


void printList(NodeA* head){
    NodeA* current = head;
    while(current != NULL){
        printf("%d->",current->data);
        if(current->next == NULL){
            printf("NULL",current->data);
        }
        current = current->next;
    }
    printf("\n");
}
void clear(NodeA** head){
    NodeA* current = *head;
    while(current != NULL){
        NodeA* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("Tum dugumler serbest birakildi.\n");
}
int main(){
    NodeA *head = NULL;
    NodeA *nodeOne = malloc(sizeof(NodeA));
    NodeA *nodeTwo = malloc(sizeof(NodeA));
    NodeA *nodeThree = malloc(sizeof(NodeA));
    NodeA *nodeFour = malloc(sizeof(NodeA));
    nodeOne->data = 1; nodeOne->next = nodeTwo; head = nodeOne; 
    nodeTwo->data = 2; nodeTwo->next = nodeThree;
    nodeThree->data = 3; nodeThree->next = nodeFour;
    nodeFour->data = 4; nodeTwo->next = NULL;
    findMiddle(head);
    printList(head);
    clear(&head);
}
#pragma endregion