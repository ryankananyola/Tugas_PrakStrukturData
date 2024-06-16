#include <iostream>
#include <malloc.h>
#define MAX 10

using namespace std;

typedef float typeinfo;

struct typequeue{
    typeinfo info;
    typequeue* next;
};

struct queue{
    typequeue* depan;
    typequeue* belakang;
    typeinfo tumpukanSampah[MAX];
    int top;
};

queue Antrian;

void judul(){
    cout << "==============================" << endl;
    cout << "|         TUGAS QUEUE        |" << endl;
    cout << "| Yohanes Febryan Kana Nyola |" << endl;
    cout << "|        NIM 123220198       |" << endl;
    cout << "==============================" << endl << endl;
}

void buatQueue(){
    Antrian.depan = NULL;
    Antrian.belakang = NULL;
    Antrian.top = -1;
}

bool queueKosong(){
    if (Antrian.depan == NULL){
        return true;
    } else {
        return false;
    }
}

void enqueue(typeinfo infoBaru){
    typequeue* nodeBaru = (typequeue*) malloc(sizeof(nodeBaru));
    nodeBaru->info = infoBaru;
    nodeBaru->next = NULL;

    if (queueKosong()){
        Antrian.depan = nodeBaru;
        Antrian.belakang = nodeBaru;
    } else {
        Antrian.belakang->next = nodeBaru;
        Antrian.belakang = nodeBaru;
    }
}

void tumpukanSampah(typeinfo infoBaru){
    if (Antrian.top < MAX-1) {
        Antrian.top++;
        Antrian.tumpukanSampah[Antrian.top] = infoBaru;
    } else {
        cout << "Tumpukan Sampah Penuh" << endl;
    }
}

void dequeue(){
    if (queueKosong()){
        if (Antrian.top >= 0) {
            typeinfo info = Antrian.tumpukanSampah[Antrian.top];
            Antrian.top--;
            enqueue(info);
        } else {
            cout << "Queue Underflow" << endl;
        }
        return;
    }

    typequeue* hapus = Antrian.depan;
    Antrian.depan = Antrian.depan->next;

    if(Antrian.depan == NULL){
        Antrian.belakang = NULL;
    }

    tumpukanSampah(hapus->info);
    delete hapus;
}

void cetakQueue(){
    if (queueKosong()){
        cout << "Queue Underflow" << endl;
        return;
    }

    typequeue* hapus = Antrian.depan;
    while(hapus != NULL){
        cout << " " << hapus->info;
        hapus = hapus->next;
    }

    cout << endl;
}

void cetakSampah(){
    if (Antrian.top >= 0){
        cout << "Tumpukan Sampah: ";
        for (int i = Antrian.top; i>= 0; i--){
            cout << Antrian.tumpukanSampah[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Tumpukan Sampah Kosong" << endl;
    }
}

int main(){
    system("cls");
    judul();

    int pilihmenu, input;
    char kembali = 'y';

    buatQueue();

    while (kembali == 'y'){

        system("cls");
        judul();

        cout << "MENU UTAMA QUEUE" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Lihat Antrian" << endl;
        cout << "3. Dequeue" << endl;
        cout << "4. Tumpukan Sampah" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihmenu;

        if ( pilihmenu == 1 ){
            system("cls");
            judul();

            cout << "1. Enqueue" << endl;
            cout << "------------" << endl;
            cout << "Masukkan nilai yang ingin di tambah ke antrian : ";
            cin >> input;

            enqueue(input);

            cout << endl << " Nilai telah ditambahkan " << endl;
            cout << " Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
        else if ( pilihmenu == 2 ){
            system("cls");
            judul();

            cout << "2. Lihat Antrian" << endl;
            cout << "-----------------" << endl;
            cout << endl;

            cetakQueue();

            cout << endl << " Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
        else if ( pilihmenu == 3 ){
            system("cls");
            judul();

            cout << " 3. Dequeue " << endl;
            cout << "-------------" << endl;

            dequeue();

            cout << " Nilai telah dikeluarkan dari antrian " << endl;

            cout << endl << " Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
        else if ( pilihmenu == 4 ){
            system("cls");
            judul();

            cout << " 4. Tumpukkan Sampah " << endl;
            cout << "----------------------" << endl;

            cetakSampah();

            cout << endl << " Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
        else {
            cout << " Menu Tidak Tersedia " << endl;
            cout << endl << " Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
    }
}
