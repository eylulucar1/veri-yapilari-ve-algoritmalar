#include <stdio.h>
int main(){
#pragma region Soru1
/*C programlama dilinde 10 elemanlı bir tamsayı dizisi tanımlayınız. Kullanıcıdan dizinin 10
elemanını alınız ve daha sonra bu elemanları ekrana yazdırınız.*/
    int sayilar[10];
    printf("Lütfen 10 adet sayi girisi yapiniz\n");
    printf("----------------------------------\n");
    for(int i=0;i<10;i++){
        printf("%d. Eleman : ",i+1);
        scanf("%d",&sayilar[i]);
    }
    printf("\nGirdiğiniz Sayilar: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", sayilar[i]);
    }
    printf("\n");
    return 0;
    /* 
    --- KARMAŞIKLIK ANALİZİ ---

    Değişkenlerin Tanımı:
    n: Dizideki eleman sayısı (Bu kodda n = 10).
    a: Döngü içerisinde yapılan işlemlerin (printf, scanf, artırma, koşul) zaman maliyeti katsayısı.
    b: Döngü dışındaki sabit atamaların ve program başlangıç/bitiş işlemlerinin zaman maliyeti.

    1. T(n) Zaman Maliyeti:
    Programda n defa dönen iki adet ardışık döngü bulunmaktadır. Döngülerin çalışma süresi eleman sayısına (n) bağlı olarak doğrusal artar.
    Formül: T(n) = a * n + b

    2. O(n) Zaman Karmaşıklığı (Time Complexity):
    T(n) = a * n + b denkleminde, Big-O notasyonu gereği sabitler (a ve b katsayıları) göz ardı edilir. En yüksek dereceli terim n olduğu için karmaşıklık doğrusal zamandır.
    Sonuç: O(n)

    3. S(n) Alan Karmaşıklığı (Space Complexity):
    Programda n boyutunda (10 elemanlı) bir tamsayı dizisi tanımlanmıştır. Bellekte kaplanan alan eleman sayısına (n) doğrudan bağlıdır ve doğrusal olarak artar. Geri kalan değişkenler (i, n vb.) sabit alan kaplar O(1).
    Sonuç: O(n)
    */
#pragma endregion
#pragma region Soru2
/*Kullanıcıdan bir tam sayı alın ve bu sayının bir Palindrom Sayı olup olmadığını bulan C
programını yazın.*/
   int sayi;
   printf("Lütfen bir sayi giriniz: ");
   scanf("%d",&sayi);
   printf("Girilen Sayi: %d\n",sayi);
   int kalan,ters=0;
   while(sayi != 0){
    kalan = sayi%10;
    ters =(ters*10) + kalan;
    sayi /= 10;
   }
   printf("Girilen sayinin tersi : %d",ters);
#pragma endregion
}