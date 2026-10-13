#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id[20];           
    char data[20][100];    
    char durum[20][20];   
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = 0; 
}

void push(Stack *s, int id, char isim[]) {
    if (s->top == 20) {
        printf("Yigin Dolu! Baska hasta muayeneye alinamiyor.\n");
        return;
    }
    s->id[s->top] = id;
    strcpy(s->data[s->top], isim);
    strcpy(s->durum[s->top], "muayenede");
    s->top++;
}

void pop(Stack *s, int *cikarilan_id, char cikarilan_isim[]) {
    if (s->top == 0) {
        printf("Yigin Bos! Muayenede hasta yok.\n");
        *cikarilan_id = -1;
        return;
    }
    s->top--;
    *cikarilan_id = s->id[s->top];
    strcpy(cikarilan_isim, s->data[s->top]);
}


typedef struct {
    int id[20];
    char data[20][100];
    char durum[20][20];
    int rear;
    int front;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->rear = -1;
    q->front = -1;
    q->size = 0;
}

void enQueue(Queue *q, int id, char isim[]) {
    if (q->size == 20) {
        printf("Kuyruk Dolu! Yeni hasta kabul edilemiyor.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % 20; // Dairesel mantık 
    
    q->id[q->rear] = id;
    strcpy(q->data[q->rear], isim);
    strcpy(q->durum[q->rear], "bekliyor");
    q->size++;
}

void deQueue(Queue *q, int *cikarilan_id, char cikarilan_isim[]) {
    if (q->size == 0) {
        printf("Kuyruk Bos! Bekleyen hasta yok.\n");
        *cikarilan_id = -1;
        return;
    }
    *cikarilan_id = q->id[q->front];
    strcpy(cikarilan_isim, q->data[q->front]);
    
    q->front = (q->front + 1) % 20;
    q->size--;
    
    if (q->size == 0) {
        q->front = -1;
        q->rear = -1;
    }
}

typedef struct HastaDugumu {
    int id;
    char ad[100];
    char durum[20]; 
    struct HastaDugumu *next;
} HastaNode;

void addLinkedList(int id, char isim[], char durum[], HastaNode **head) {
    HastaNode *newNode = malloc(sizeof(HastaNode));
    newNode->id = id; 
    strcpy(newNode->ad, isim);
    strcpy(newNode->durum, durum); 
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    HastaNode *temp = *head; 
    while (temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = newNode;
}

void listGecmisKayitlar(HastaNode *head) {
    if (head == NULL) {
        printf("Gecmis kayit bulunamadi.\n");
        return;
    }
    HastaNode *temp = head;
    while (temp != NULL) {
        printf("ID: %d | Ad: %s | Durum: %s\n", temp->id, temp->ad, temp->durum);
        temp = temp->next;
    }
}

int main() {
    Queue hastaKuyrugu;
    Stack muayeneYigini;
    HastaNode *gecmisKayitlar = NULL; 
    
    initQueue(&hastaKuyrugu);
    initStack(&muayeneYigini);
    
    int sec = -1, id;
    char isim[100];
    
    while (sec != 0) {
        printf("\n--- HASTANE YONETIM SISTEMI ---\n");
        printf("1- Hastaneye Al (Kuyruga Ekle)\n");
        printf("2- Muayeneye Al (Kuyruktan Cikar, Yigina Ekle)\n");
        printf("3- Muayeneyi Tamamla (Yigindan Cikar, Gecmise Ekle)\n");
        printf("4- Bekleyen Hastalari Listele (Kuyruk)\n");
        printf("5- Gecmis Kayitlari Listele (Bagli Liste)\n");
        printf("0- Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &sec);
        
        switch (sec) {
            case 1:
                printf("Hasta ID giriniz: ");
                scanf("%d", &id);
                printf("Hasta Adini giriniz: ");
                scanf(" %99[^\n]", isim); // Boşluklu isim girebilmek için
                enQueue(&hastaKuyrugu, id, isim);
                printf("%s kuyruga eklendi.\n", isim);
                break;
                
            case 2:
                deQueue(&hastaKuyrugu, &id, isim);
                if (id != -1) {
                    push(&muayeneYigini, id, isim);
                    printf("%s muayene odasina alindi.\n", isim);
                }
                break;
                
            case 3:
                pop(&muayeneYigini, &id, isim);
                if (id != -1) {
                    addLinkedList(id, isim, "tamamlandi", &gecmisKayitlar);
                    printf("%s hastasinin muayenesi tamamlandi ve gecmise eklendi.\n", isim);
                }
                break;
                
            case 4:
                if (hastaKuyrugu.size == 0) {
                    printf("Kuyrukta bekleyen hasta yok.\n");
                } else {
                    printf("\n--- Bekleyen Hastalar ---\n");
                    int i = hastaKuyrugu.front;
                    for (int count = 0; count < hastaKuyrugu.size; count++) {
                        printf("ID: %d | Ad: %s | Durum: %s\n", 
                               hastaKuyrugu.id[i], hastaKuyrugu.data[i], hastaKuyrugu.durum[i]);
                        i = (i + 1) % 20;
                    }
                }
                break;
                
            case 5:
                printf("\n--- Gecmis Hasta Kayitlari ---\n");
                listGecmisKayitlar(gecmisKayitlar);
                break;
                
            case 0:
                printf("Sistemden cikiliyor...\n");
                break;
                
            default:
                printf("Gecersiz secim, lutfen tekrar deneyin.\n");
        }
    }
    
    return 0;
}
