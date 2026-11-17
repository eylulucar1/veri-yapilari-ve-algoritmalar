#include <stdio.h>
#include <stdlib.h>

typedef struct BTS{
	int Deger;
	struct BTS* sol;
	struct BTS* sag;
}BTS;

void DegerEkle(BTS* kok, int Deger)
{
    if (kok == NULL)
    {
        return;
    }
    BTS* tmpDugum = kok;
    while (tmpDugum != NULL)
    {
        if (Deger > tmpDugum->Deger) 
        {
            if (tmpDugum->sag == NULL) 
            {
                BTS* yeniDugum = malloc(sizeof(BTS));
                yeniDugum->Deger = Deger; yeniDugum->sag = NULL; yeniDugum->sol = NULL; 
                tmpDugum->sag = yeniDugum;
                return;
            }
            tmpDugum = tmpDugum->sag; 
        }
        else
        {
            if (tmpDugum->sol == NULL) 
            {
                BTS* yeniDugum = malloc(sizeof(BTS));
                yeniDugum->Deger = Deger; yeniDugum->sag = NULL; yeniDugum->sol = NULL; 
                tmpDugum->sol = yeniDugum; 
                return;
            }
            tmpDugum = tmpDugum->sol;
        }
    }
}

void ara(BTS* kok, int ara){
    if(kok == NULL){
        printf("bosa kazdin");
        return;
    }
    if(kok->Deger == ara){ 
        printf("hazine kökte bulundu.");
        return;
    }
    BTS* yeni = kok;
    while(kok != NULL){
        if(ara < kok->Deger){ 
            printf("%d\n", kok->Deger); 
            kok = kok->sol; 
            if(kok == NULL) break; 
        }
        else if(ara > kok->Deger){
            printf("%d\n", kok->Deger);
            kok = kok->sag;
            if(kok == NULL) break; 
        }
        else{
            printf("Hazine bulundu!\n");
            return;
        }
    }
    printf("bosa kazdin\n");
    return;
}
void yukseklik(BTS* kok){
	int yuksek=0;
	while(kok != NULL){
		if(kok->sag != NULL) {
			kok = kok->sag;
			yuksek++;
		}
		else if(kok->sol != NULL) { 
			kok = kok->sol;
			yuksek++;
		}
		else break;
	}
	printf("En kotu durum : %d\n",yuksek);
}
int main(int argc, char *argv[]) {
	BTS *kok = malloc(sizeof(BTS));
	kok->Deger = 30; kok->sol = NULL; kok->sag = NULL; 
	int dizi[10] = {42,45,12,0,24,36,2,9,83,53};
	int i;
	for(i = 0; i < 10; i++){
		DegerEkle(kok, dizi[i]); 
	}
	int aranan = 24;
	ara(kok, aranan);
	yukseklik(kok);
	return 0;
}
