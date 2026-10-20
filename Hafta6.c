#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int veri;
    struct Node* sag;
    struct Node* sol;
}Node;

Node* yeniDugum(int veri){
    Node *d = malloc(sizeof(Node));
    d->sag = NULL;
    d->sol = NULL;
    d->veri = veri;
    return d;
}

Node* ekle(Node* kok,int veri){
    if(kok==NULL){
        return yeniDugum(veri);
    }
    if(veri<kok->veri){
        kok->sol = ekle(kok->sol,veri);
    }
    else if(veri>kok->veri){
        kok->sag = ekle(kok->sag,veri);
    }
    return kok;
}

void inOrder(Node* kok){ // sol kök sag
    if(kok==NULL) return;
    inOrder(kok->sol);
    printf("%d ",kok->veri);
    inOrder(kok->sag);
}

void postOrder(Node* kok){
    if(kok==NULL) return;
    postOrder(kok->sol);
    postOrder(kok->sag);
    printf("%d ",kok->veri);
}

Node* ara(Node* kok,int aranan){
    if(kok==NULL || kok->veri == aranan) return kok;
    if(kok->veri < aranan){
        return ara(kok->sag,aranan);
    }
    else if(kok->veri > aranan){
        return ara(kok->sol,aranan);
    }
}

void findMin(Node* kok){
    while(kok->sol != NULL){
        kok = kok->sol;
    }
    printf("%d en kucuk elemandir\n",kok->veri);
}

int main(int argc, char *argv[]) {
    int arr[7] = {40,20,60,10,30,50,70};
    Node* kok = NULL;
    int i;
    for(i=0;i<7;i++){
        kok = ekle(kok,arr[i]);
    }
    inOrder(kok);
    printf("\n");
    postOrder(kok);
    printf("\n");
    Node* sonuc = ara(kok, 30);

    if (sonuc != NULL) {
        printf("30 degeri bulundu.\n");
    }
    else {
        printf("30 degeri bulunamadi.\n");
    }

    sonuc = ara(kok, 90);

    if (sonuc != NULL) {
        printf("90 degeri bulundu.\n");
    }
    else {
        printf("90 degeri bulunamadi.\n");
    }

    findMin(kok);
    return 0;
}

// 25 eklenirse 30 düğümünün sol altına yerleşir.
// printf() ilk satıra taşınırsa Preorder (kök-sol-sağ) dolaşması elde edilir.
// findMin() içinde sol yerine sağ takip edilirse 70 (en büyük değer) bulunur.