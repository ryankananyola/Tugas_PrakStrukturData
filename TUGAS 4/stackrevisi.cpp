#include <iostream>
#include <malloc.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;
Node* sampah = nullptr;

void judul(){
    cout << "==============================" << endl;
    cout << "|         TUGAS STACK        |" << endl;
    cout << "| Yohanes Febryan Kana Nyola |" << endl;
    cout << "|        NIM 123220198       |" << endl;
    cout << "==============================" << endl << endl;
}

void buatStack(){
    top = nullptr;
    sampah = nullptr;
}

bool stackKosong() {
    return top == nullptr;
}

bool stackSampahKosong(){
    return sampah == nullptr;
}

void push(int infoBaru) {
    Node* nodeBaru = (Node*)malloc(sizeof(Node));
    nodeBaru->data = infoBaru;
    nodeBaru->next = top;
    top = nodeBaru;
} 

void pop() {
    if (stackKosong()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    
    Node* hapus = top;
    top = top->next;
    
    hapus->next = sampah;
    sampah = hapus;
}

void cetakStack(){
    if(stackKosong()){
        cout << "Stack Masih Kosong!" << endl;
    } else{
        Node* hapus = top;
        while(hapus != NULL){
            cout << hapus->data << " ";
            hapus = hapus->next;
        }
        cout << endl;
    }
}

void tampilkanTumpukanSampah() {
    if (stackSampahKosong()) {
        cout << "Tumpukan Sampah Kosong" << endl;
    }
    else {
        Node* hapus = sampah;
        cout << "Isi Tumpukkan Sampah: ";
        cout << endl;
        while (hapus != nullptr) {
            cout << hapus->data << " ";
            hapus = hapus->next;
        }
        cout << endl;
    }
}

int main() {
    int pilih,pilihMenu, input;
    char kembali = 'y', pilihpop;

    while (kembali == 'y'){

        system("cls");
        judul();

        cout << "MENU UTAMA STACK" << endl;
        cout << " 1. Push " << endl;
        cout << " 2. Lihat " << endl;
        cout << " 3. Pop " << endl;
        cout << " 4. Tumpukan Sampah " << endl;
        cout << " 0. Exit " << endl << endl;
        cout << " Pilih Menu : ";
        cin >> pilihMenu;

        if (pilihMenu == 1){
            system("cls");
            judul();

            cout << " 1. Menu Push " << endl;
            cout << "---------------" << endl;
            cout << " Masukkan nilai yang ingin di Push : ";
            cin >> input;

            push(input);

            cout << endl << " Nilai telah di Push " << endl;
            cout << "Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
        else if (pilihMenu == 2){
            system("cls");
            judul();

            cout << " 2. Menu Lihat " << endl;
            cout << "----------------" << endl;
            cout << endl;

            cetakStack();

            cout << endl << "Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }

        else if (pilihMenu == 3){
            system("cls");
            judul();

            cout << " 3. Menu Pop " << endl;
            cout << "--------------" << endl;
            pop();

            cout << "Pop Telah Dilakukan" << endl;
            
            cout << endl << "Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }

        else if (pilihMenu == 4) {
            system("cls");
            judul();

            cout << " 4. Menu Tumpukan Sampah " << endl;
            cout << "--------------------------" << endl;

            tampilkanTumpukanSampah();

            cout << endl << "Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }

        else if (pilihMenu == 0){
            system("cls");
            judul();

            cout << "Apakah Yakin ingin Keluar ?" << endl;
            cout << "1. Keluar" << endl;
            cout << "2. Kembali Ke Menu" << endl;
            cout << "Pilih : ";
            cin >> pilih;
            
            if(pilih == 1){
                system("cls");
                judul();
                cout << "SAMPAI JUMPA DI LAIN WAKTU" << endl;
                return 0;
            } else if(pilih == 2){
                kembali ='y';
            } else {
                cout << "Pilihan tidak tersedia" << endl;
            }
        }

         else{
            cout << " Menu Tidak Tersedia " << endl;
            cout << endl << "Kembali ke Menu Utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
    }
}
