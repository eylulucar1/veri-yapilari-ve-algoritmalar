#include <stdio.h>
#include <stdlib.h>
/*Tüm örnekler için ortak kullanılacak düğüm yapısı*/
struct node{
    int data;
    struct node *next;
};
int main(){
#pragma region Soru1
/*Bir Node yapısı oluşturun. Node içerisinde 10 değerini saklayın ve ekrana yazdırın*/
struct node Node1 = {10,NULL};
printf("%d\n",Node1.data); //10
// VEYA
struct node *tut = &Node1;
printf("%d",tut->data); //10
#pragma endregion
#pragma region Soru2
/*10 ve 20 değerlerini içeren iki Node oluşturun ve 10->20->NULL listesini oluşturun*/
struct node Node1 = {10,NULL};
struct node Node2 = {20,NULL};
Node1.next = &Node2;
printf("The value inside the first node : %d\n",Node1.data);
printf("The value inside the second node: %d\n",Node1.next->data);
//VEYA
printf("The value inside the second node: %d\n",Node2.data);
#pragma endregion
#pragma region Soru3
/*10->20->30->NULL listesini oluşturun ve while kullanarak tüm elemanları yazdırın :)*/
struct node Node1 = {10,NULL};
struct node Node2 = {20,NULL};
struct node Node3 = {30,NULL};
struct node *current = &Node1;
Node1.next = &Node2;
Node2.next = &Node3;
while(current != 0){
    printf("%d ,",current->data);
    current = current->next;
}
#pragma endregion
#pragma region Soru4
/*malloc() kullanarak 10->20->30 NULL listesini oluşturun.*/
struct node* NodeA = (struct node*)malloc(sizeof(struct node));//C dili adreslerin sadece işaretçilerde (*) tutulmasına izin verir.
struct node* NodeB = (struct node*)malloc(sizeof(struct node));
struct node* NodeC = (struct node*)malloc(sizeof(struct node));
NodeA->data = 10;
NodeB->data = 20;
NodeB->data = 30;
NodeA->next = NodeB;
NodeB->next = NodeC;
NodeC->next = NULL;
struct node* current = NodeA; // Baştan başla
struct node* nextNode;

while (current != NULL) {
    nextNode = current->next; // Sıradakinin adresini kaybetmemek için yedekle
    free(current);            // Mevcut düğümü bellekten sil
    current = nextNode;       // Yedeklediğin bir sonraki düğüme geç
}
#pragma endregion
#pragma region Soru5
/*10->20->30->40->NULL listesinin kaç node içerdiğini bulunuz.*/
struct node a = {10,NULL};
struct node b = {20,NULL};
struct node c = {30,NULL};
struct node d = {40,NULL};
a.next = &b;
b.next = &c;
c.next = &d;
int nodeSayisi=0;
struct node *current = &a;
while(current != NULL){
    nodeSayisi ++;
    current = current->next;
}
printf("%d adet node vardır.",nodeSayisi);
#pragma endregion
#pragma region Soru6
/*10->20->30->40->NULL listesindeki değerlerin toplamını bulun.*/
int sum=0;
struct node a = {10,NULL};
struct node b = {20,NULL};
struct node c = {30,NULL};
struct node d = {40,NULL};
a.next = &b;
b.next = &c;
c.next = &d;
struct node *current = &a;
while(current != NULL){
    sum+=current->data;
    current = current ->next;
}
printf("Toplam : %d",sum);
#pragma endregion
#pragma region Soru7
/*Kullanıcının girdiği sayının 10->20->30->NULL listesinde olup olmadığını bulun.*/
int sayi;
printf("Bir sayi giriniz: ");
scanf("%d",&sayi);
int flag=1;
struct node a = {10,NULL};
struct node b = {20,NULL};
struct node c = {30,NULL};
struct node d = {40,NULL};
a.next = &b;
b.next = &c;
c.next = &d;
struct node *current = &a;
while(current != 0){
    if(current->data == sayi){
        printf("Sayi bulundu!");
        flag = 0;
        break;
    }
    current = current->next;
}
if(flag == 1){
    printf("Girmis oldugunuz sayi listede bulunmamaktadir.");
}

#pragma endregion
#pragma region Soru8
/*10->20->30->NULL listesinin başına 5 node unu ekleyin.*/
struct node a = {10,NULL};
struct node b = {20,NULL};
struct node c = {30,NULL};
struct node d = {40,NULL};
a.next = &b;
b.next = &c;
c.next = &d;
struct node *current = &a;
struct node *newNode = (struct node*)malloc(sizeof(struct node));
newNode -> data = 5;
newNode -> next = current;
current = newNode;
#pragma endregion
#pragma region Soru9
/*10->20->30->NULL listesinin sonuna 40 ekleyin*/
    struct node a = {10, NULL};
    struct node b = {20, NULL};
    struct node c = {30, NULL};
    struct node d = {40, NULL};

    a.next = &b;
    b.next = &c;
    c.next = &d;

    struct node *current = &a;

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 50;
    newNode->next = NULL;

    if (current == NULL) {
        current = newNode;
    } else {
        struct node *temp = current;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    struct node *printTemp = current;
    while (printTemp != NULL) {
        printf("%d -> ", printTemp->data);
        printTemp = printTemp->next;
    }
    printf("NULL\n");

    free(newNode);

#pragma endregion
#pragma region Soru10
/*Bağlı listeden belli bir elemanı silme*/

    // 1. Listeyi dinamik olarak (malloc ile) oluşturuyoruz
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *ikinci = (struct node*)malloc(sizeof(struct node));
    struct node *ucuncu = (struct node*)malloc(sizeof(struct node));
    struct node *dorduncu = (struct node*)malloc(sizeof(struct node));

    head->data = 10;      head->next = ikinci;
    ikinci->data = 20;    ikinci->next = ucuncu;
    ucuncu->data = 30;    ucuncu->next = dorduncu;
    dorduncu->data = 40;  dorduncu->next = NULL;

    int silinecekDeger = 20;

    // 2. SİLME İŞLEMİ
    struct node *temp = head;
    struct node *prev = NULL;

    // Durum A: Silinecek eleman listenin en başındaysa
    if (temp != NULL && temp->data == silinecekDeger) {
        head = temp->next; // Başlangıcı bir yana kaydır
        free(temp);        // Eski başı bellekten sil
    } 
    else {
        // Durum B: Silinecek elemanı arama
        while (temp != NULL && temp->data != silinecekDeger) {
            prev = temp;       // Bir önceki düğümü hafızada tut
            temp = temp->next; // Bir sonraki düğüme geç
        }

        // Eleman bulunduysa (temp NULL olmadıysa)
        if (temp != NULL) {
            prev->next = temp->next; // Silinecek düğümü aradan çıkar (atla)
            free(temp);              // Kopardığın düğümü bellekten sil
        }
    }

    // 3. Güncel listeyi yazdırma
    struct node *printTemp = head;
    while (printTemp != NULL) {
        printf("%d -> ", printTemp->data);
        printTemp = printTemp->next;
    }
    printf("NULL\n");
#pragma endregion
#pragma region Soru11
/*
 Ilk nodun tututuğu değeri getiren fonksiyon - insertBeginning()
 Tüm listeyi gösteren fonksiyon - display()
 Elaman ara - search()
*/

struct Node* head = NULL;

void insertBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    insertBeginning(10);
    insertBeginning(20);
    insertBeginning(30);

    display();

    if (search(20)) {
        printf("20 degeri listede var.\n");
    } else {
        printf("20 degeri listede yok.\n");
    }

    if (search(50)) {
        printf("50 degeri listede var.\n");
    } else {
        printf("50 degeri listede yok.\n");
    }

    return 0;
}
#pragma endregion
}