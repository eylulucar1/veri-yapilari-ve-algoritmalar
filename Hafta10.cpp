/*
      A--------B
      |       / \
      D      C   E
      |----------|

      BFS : A->B->D->C->E
      DFS: A->B->C->E->D
*/



#include <iostream>
using namespace std;

#define N 5

const char *harfler[N] = {"A", "B", "C", "D", "E"};
const char *sehirler[N] = {"Istanbul", "Ankara", "Izmir", "Bursa", "Antalya"};

void kenarEkle(int adj[N][N], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void bfs(int adj[N][N], int baslangic) {
    int visited[N] = {0}; // baslangicta tüm elemanlar ziyaret edilmedi olarak isaretlenir
    int queue[N];
    int front = 0, rear = 0; // front cıkarılacak elemanin rear eklenecek elemanın konumunu tutar

    visited[baslangic] = 1; // istanbul ziyaret edildi
    queue[rear++] = baslangic; // istanbul kuyruğa eklendi

    cout << "BFS Dolasma Sirasi:" << endl;
    while (front < rear) { // kuyrukta bekleyen sehir oldugu sürece arama sürsün
        int u = queue[front++]; // en bastaki sehri u'ya kaydet ve kuyruktan cıkar
        cout << harfler[u] << " (" << sehirler[u] << ")";

        for (int v = 0; v < N; v++) { // u sehrinin komsuluklarını kontrol et kuyruğa ekle
            if (adj[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }

        if (front < rear) {
            cout << " -> ";
        }
    }
    cout << endl << endl;
}

void dfs(int adj[N][N], int u, int visited[N], int *sayac) {
    visited[u] = 1; // istanbul ziyaret edildi
    (*sayac)++;
    cout << harfler[u] << " (" << sehirler[u] << ")";
    
    if (*sayac < N) {
        cout << " -> ";
    }

    for (int v = 0; v < N; v++) { // u şehrinin komşularını küçük indisten büyüğe doğru sırayla tarar
        if (adj[u][v] == 1 && visited[v] == 0) {
            dfs(adj, v, visited, sayac); //Ziyaret edilmemiş ilk komşuyu bulduğunda dfs'i kendi içinde tekrar çağırarak en derine ilerler
        } // komşu kalmadığında bir önceki şehre geri döner.
    }
}

int main() {
    int adj[N][N] = {0};
    int visitedDFS[N] = {0};
    int sayac = 0;

    // Şehir bağlantılarının tanımlanması:
    // 0: A (İstanbul), 1: B (Ankara), 2: C (İzmir), 3: D (Bursa), 4: E (Antalya)
    kenarEkle(adj, 0, 1); // İstanbul - Ankara
    kenarEkle(adj, 0, 3); // İstanbul - Bursa
    kenarEkle(adj, 1, 2); // Ankara - İzmir
    kenarEkle(adj, 1, 4); // Ankara - Antalya
    kenarEkle(adj, 3, 4); // Bursa - Antalya

    // BFS Çalıştırma (A: İstanbul'dan başla)
    bfs(adj, 0);

    // DFS Çalıştırma (A: İstanbul'dan başla)
    cout << "DFS Dolasma Sirasi:" << endl;
    dfs(adj, 0, visitedDFS, &sayac);
    cout << endl;

    return 0;
}
