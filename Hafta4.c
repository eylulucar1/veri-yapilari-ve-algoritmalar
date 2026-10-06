#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region Ornek1






/*
addSongToEnd(Node** head,char* isim) -> sona ekle
removeSong(Node** head,char* isim) -> kaldır
playNext() ve playPrevious() -> öncekini ve sonrakini oynat
Menü: Kullanıcı seçimleriyle listeyi yönetsin.
Liste boşken liste boş uyarısı verin.
*/
typedef struct Song{
    char name[50];
    struct Song* next;
    struct Song* prev;
}Song;
void addSongToEnd(Song** head,char* isim){
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name,isim);
    newSong->prev=NULL; newSong->next=NULL;
    if(*head == NULL){
        *head = newSong;
        return;
    }
    Song* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->prev = temp;
}
void removeSong(Song** head,char* isim){
    if(*head == NULL){
        printf("Liste bos!");
        return;
    }
    Song* temp = *head;
    while(temp != NULL){
        if(strcmp(temp->name,isim)==0){
            if(temp == *head){
                *head = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            if (temp->prev != NULL) {
               temp->prev->next = temp->next;
            }
            printf("'%s' listeden kaldirildi.\n", temp->name);
            free(temp); 
            return;
        }
        temp = temp->next;
    }
    printf("'%s' listede bulunamadi.\n", isim);
}
void playNext(Song** current){
    if(*current==NULL){
        printf("NULL\n");
        return;
    }
    if((*current)->next == NULL){ 
        printf("Sarki listesi sonlanmistir.\n");
        return;
    }
    *current = (*current)->next;
    printf("%s sarkisi oynatiliyor\n",(*current)->name);
}
void playPrevious(Song** current){
    if(*current == NULL){
        printf("NULL\n");
        return;
    }
    if((*current)->prev == NULL){ 
        printf("Zaten listenin basindasiniz.\n");
        return;
    }
    *current = (*current)->prev;
    printf("%s sarkisi oynatiliyor\n",(*current)->name);
}
void displayPlaylist(Song* head){
    if(head==NULL){
        printf("Liste bos!");
        return;
    }
    Song* current = head;
    while(current != NULL){
        printf("%s\n",current->name);
        current = current->next; 
    }
}
int main(){
    Song* head = NULL; 
    addSongToEnd(&head,"cumlelerim");
    Song* current = head;
    addSongToEnd(&head,"askin ertesi");
    addSongToEnd(&head,"diger yarim");
    addSongToEnd(&head,"gidisat");
    addSongToEnd(&head,"tiryakinim");
    addSongToEnd(&head,"git");
    addSongToEnd(&head,"yok baska hayalim");
    removeSong(&head,"gidisat");
    playNext(&current);
    playPrevious(&current);
    displayPlaylist(head);

    return 0;
}







#pragma endregion
#pragma region Ornek2






/*
Undo (Geri Alma) Özelliği Simülasyonu
İstenilenler:
 Kullanıcı “metin ekle” diyerek bir kelime girer → stack’e eklenir.
 “undo” seçerse son eklenen kelime geri alınır (pop edilir).
 “show” seçerse şu ana kadar eklenen kelimeleri gösterir.
Beklenen örnek kullanım:
 &gt; add Merhaba
 &gt; add Dünya
 &gt; show -&gt; Merhaba Dünya
 &gt; undo
 &gt; show -&gt; Merhaba
*/
#define MAX 100
typedef struct Stack{
    char dizi[MAX][50];
    int top;
}Stack;

void init(Stack *stack){
    stack->top == -1;
}
void push(Stack* s, char* yeniKelime) {
    if (s->top >= MAX - 1) {
        printf("Hata: Yigit dolu!\n");
        return;
    }
    s->top++;
    strcpy(s->dizi[s->top], yeniKelime);
}
char* pop(Stack *stack) {
    if(stack->top >= 0){

        return stack->dizi[stack->top--]; 
    }
    return NULL;
}
void show(Stack *stack){
    void show(Stack *stack){
    if (stack->top == -1) {
        printf("Gosterilecek kelime yok.\n");
        return;
    }

    for(int i = 0; i <= stack->top; i++){
        printf("%s ", stack->dizi[i]);
    }
    printf("\n"); // Alt satıra geçmek için
}
}
int main(){
    Stack stack;
    init(&stack);
    
    char secenek[50];
    char kelime[50]; 

    printf("Komutlar: add <kelime>, undo, show, exit\n");

    while (1) {
        printf("> ");
        scanf("%s", secenek); 

        if (strcmp(secenek, "add") == 0) {
            scanf("%s", kelime); 
            push(&stack, kelime);
        } 
        else if (strcmp(secenek, "undo") == 0) {
            pop(&stack);
        } 
        else if (strcmp(secenek, "show") == 0) {
            show(&stack); 
        } 
        else if (strcmp(secenek, "exit") == 0) {
            break; 
        } 
        else {
            printf("Gecersiz komut!\n");
        }
    }
}






#pragma endregion
#pragma region Ornek3






/*
Bu uygulama bir yazıcının işlem sırasını taklit edecek.
Her eklenen dosya kuyruğa alınır, “Yazdır” komutuyla sıradaki iş çıkarılır.
Yapılacaklar:
 enqueuePrintJob(Queue* q, char* dosyaAdı)
 processNextJob(Queue* q)
 showQueue(Queue q)
 Menü: 1) Yeni dosya ekle, 2) Yazdır, 3) Kuyruğu göster
İpucu:
 Kuyruk boşken yazdırma işlemi yapılmamalı.
 FIFO mantığına dikkat edin.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dosyalar[MAX][50]; 
    int front;             
    int rear;               
    int count;              
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

void enqueuePrintJob(Queue* q, char* dosyaAdi) {
    
    if (q->count == MAX) {
        printf("Hata: Yazici hafizasi dolu, dosya eklenemez!\n");
        return;
    }
    
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->dosyalar[q->rear], dosyaAdi);
    q->count++;
    
    printf(">> '%s' yazici kuyruguna eklendi.\n", dosyaAdi);
}

void processNextJob(Queue* q) {
    if (q->count == 0) {
        printf("!! Uyari: Kuyruk bos, yazdirilacak dosya yok.\n");
        return;
    }
    
    printf(">> YAZDIRILIYOR... : %s\n", q->dosyalar[q->front]);
    
    
    q->front = (q->front + 1) % MAX;
    q->count--;
}

void showQueue(Queue* q) {
    if (q->count == 0) {
        printf("Kuyruk su an bos.\n");
        return;
    }
    
    printf("\n--- Mevcut Yazici Kuyrugu ---\n");
    
    int geciciIndex = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d. Sirada: %s\n", i + 1, q->dosyalar[geciciIndex]);
        geciciIndex = (geciciIndex + 1) % MAX; 
    }
    printf("-----------------------------\n");
}

int main() {
    Queue yaziciKuyrugu;
    initQueue(&yaziciKuyrugu);
    
    int secim;
    char dosyaAdi[50];
    
    while(1) {
        printf("\n[ YAZICI KONTROL PANELI ]\n");
        printf("1) Yeni dosya ekle\n");
        printf("2) Yazdir\n");
        printf("3) Kuyrugu goster\n");
        printf("4) Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim); 
        
        switch (secim) {
            case 1:
                printf("Yazdirilacak dosyanin adi: ");
                scanf("%s", dosyaAdi);
                enqueuePrintJob(&yaziciKuyrugu, dosyaAdi);
                break;
            case 2:
                processNextJob(&yaziciKuyrugu);
                break;
            case 3:
                showQueue(&yaziciKuyrugu);
                break;
            case 4:
                printf("Yazici kapatiliyor...\n");
                return 0; 
            default:
                printf("Hatali secim, lutfen 1-4 arasi bir rakam girin.\n");
        }
    }
    
    return 0;
}






#pragma endregion