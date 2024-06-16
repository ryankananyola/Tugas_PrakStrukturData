#include <iostream>
#include <malloc.h>
using namespace std;

void judul(){
    cout << "====================================" << endl;
    cout << "|             TUGAS PTB            |" << endl;
    cout << "|    Yohanes Febryan Kana Nyola    |" << endl;
    cout << "|           NIM 123220198          |" << endl;
    cout << "====================================" << endl << endl;
}

struct mhs {
    string nama;
    int nim;
    int nilai;
};

struct PTB {
    mhs info;
    PTB *kiri, *kanan;
};

PTB *akar = NULL;
PTB *archiveAkar = NULL;

void buatPTB();
bool cekPTBKosong();
void sisipNode(mhs infobaru);
void cetak();
void preOrder(PTB* alamat);
void inOrder(PTB* alamat);
void postOrder(PTB* alamat);
void hapusNode(int infoHapus);
void sisipKeArchive(PTB* node);
void tampilkanArchive();



void buatPTB() {
    akar = NULL;
    archiveAkar = NULL;
}

bool cekPTBKosong() {
    return (akar == NULL);
}

void sisipNode(mhs infobaru) {
    PTB* NB = new PTB;
    PTB *bantu1, *bantu2;
    NB->info = infobaru;
    NB->kiri = NULL;
    NB->kanan = NULL;

    if (cekPTBKosong()) {
        akar = NB;
    } else {
        bantu1 = akar;
        bantu2 = akar;
        while (bantu1 != NULL && infobaru.nilai != bantu2->info.nilai) {
            bantu2 = bantu1;
            if (infobaru.nilai < bantu1->info.nilai)
                bantu1 = bantu2->kiri;
            else
                bantu1 = bantu2->kanan;
        }
         
            if (infobaru.nilai < bantu2->info.nilai)
                bantu2->kiri = NB;
            else{
                bantu2->kanan = NB;
        }
    }
}

void cetak() {
    cout << "\nPre-order" << endl;
    preOrder(akar);
    cout << "\nIn-order" << endl;
    inOrder(akar);
    cout << "\nPost-order" << endl;
    postOrder(akar);
    return;
}

void preOrder(PTB* alamat) {
    if (alamat != NULL) {
		cout << "Nama       : " << alamat->info.nama << endl;
        cout << "NIM        : " << alamat->info.nim << endl;
        cout << "Nilai      : " << alamat->info.nilai << endl << endl;
        preOrder(alamat->kiri);
        preOrder(alamat->kanan);
    }
}

void inOrder(PTB* alamat) {
    if (alamat != NULL) {
        inOrder(alamat->kiri);
        cout << "Nama       : " << alamat->info.nama << endl;
        cout << "NIM        : " << alamat->info.nim << endl;
        cout << "Nilai      : " << alamat->info.nilai << endl << endl;
        inOrder(alamat->kanan);
    }
}

void postOrder(PTB* alamat) {
    if (alamat != NULL) {
        postOrder(alamat->kiri);
        postOrder(alamat->kanan);
        cout << "Nama       : " << alamat->info.nama << endl;
        cout << "NIM        : " << alamat->info.nim << endl;
        cout << "Nilai      : " << alamat->info.nilai << endl << endl;
    }
}

void hapusNode(int infoHapus){
    PTB *bantu1, *bantu2, *temp;
    if(cekPTBKosong()){
        cout<<"PTB dalam kondisi kosong!"<<endl;
    }else{
        bantu1 = akar;
        bantu2 = akar;
        while(bantu1 != NULL && infoHapus != bantu1->info.nim){
            bantu2 = bantu1;
            if(infoHapus < bantu1->info.nim){
                bantu1 = bantu2->kiri;
            }else{
                bantu1 = bantu2->kanan;
            }
        }
        if(bantu1 == NULL)
            cout << "\n Data dengan NIM " << infoHapus << " tidak ditemukan!\n";
        else {
            sisipKeArchive(bantu1);
            if(bantu1->kiri == NULL && bantu1->kanan == NULL){
                if(bantu1 == akar && bantu2 == akar){
                    akar = NULL;
                }else{
                    if(bantu1 == bantu2->kiri){
                        bantu2->kiri = NULL;
                    }else{
                        bantu2->kanan = NULL;
                    }
                }

            }else if(bantu1->kiri != NULL && bantu1->kanan != NULL){
                temp = bantu1->kiri;
                bantu2 = bantu1;
                while(temp->kanan != NULL){
                    bantu2 = temp;
                    temp = temp->kanan;
                }
                bantu1->info = temp->info;
                if(bantu2 == bantu1){
                    bantu2->kiri = temp->kiri;
                }else{
                    bantu2->kanan = temp->kiri;
                }
                delete temp;

            }else if(bantu1->kiri != NULL && bantu1->kanan == NULL){
                if(bantu1==bantu2){
                    akar = bantu1->kiri;
                }else{
                    if(bantu1 == bantu2->kiri){
                        bantu2->kiri = bantu1->kiri;
                    }else{
                        bantu2->kanan = bantu1->kiri;
                    }
                }
                delete bantu1;
            }else if(bantu1->kiri == NULL && bantu1->kanan != NULL){
                if(bantu1==bantu2){
                    akar = bantu1->kanan;
                }else{
                    if(bantu1 == bantu2->kanan){
                        bantu2->kanan = bantu1->kanan;
                    }else{
                        bantu2->kiri = bantu1->kanan;
                    }
                }
                delete bantu1;

            }
        }
    }
}

void sisipKeArchive(PTB* node) {
    PTB* NB = new PTB;
    NB->info = node->info;
    NB->kiri = NULL;
    NB->kanan = NULL;

    if (archiveAkar == NULL) {
        archiveAkar = NB;
    } else {
        PTB* bantu = archiveAkar;
        while (bantu->kanan != NULL) {
            bantu = bantu->kanan;
        }
        bantu->kanan = NB;
    }
}

void tampilkanArchive() {
    cout << "\n\nArchive Pre-order" << endl;
    preOrder(archiveAkar);
    cout << "\nArchive In-order" << endl;
    inOrder(archiveAkar);
    cout << "\nArchive Post-order" << endl;
    postOrder(archiveAkar);
}
int main() {
    system("cls");
    judul();

    buatPTB();

    int pil;
    char ulang;
    do {
		system("cls");
        judul();
        cout << "------------- MENU PTB --------------" << endl;
        cout << "|1.  Sisip Data Mahasiswa           |" << endl;
        cout << "|2.  Tampilkan PTB                  |" << endl;
        cout << "|3.  Hapus Data Mahasiswa           |" << endl;
        cout << "|4.  Tampilkan Archive              |" << endl;
        cout << "|5.  Keluar                         |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Pilih Menu: ";
        cin >> pil;

        switch (pil) {
            case 1: {
                system("cls");
                judul();

                mhs newmhs;
                
                cout << endl;
                cout << "================================" << endl;
                cout << "|        MENU SISIP DATA       |" << endl;
                cout << "================================" << endl << endl;

                cout << " Silahkan Input Data dibawah ini " << endl;
                cout << "Nama   : ";
                cin.ignore();
                getline(cin, newmhs.nama);
                cout << "NIM    : ";
                cin >> newmhs.nim;
                cout << "Nilai  : ";
                cin >> newmhs.nilai;
                
                sisipNode(newmhs);
                
                break;
            }
            case 2: {
                system("cls");
                judul();

                cout << endl;
                cout << "================================" << endl;
                cout << "|        MENU TAMPIL PTB       |" << endl;
                cout << "================================" << endl << endl;

                cetak();

                break;
            }

            case 3:
                system("cls");
                judul();

                cout << endl;
                cout << "===============================" << endl;
                cout << "|        MENU HAPUS DATA      |" << endl;
                cout << "===============================" << endl << endl;
                
                int nimhapus;
                cout << "Masukkan NIM Mahasiswa yang ingin dihapus: ";
                cin >> nimhapus;
                
                hapusNode(nimhapus);
                
                break;

            case 4:
                system("cls");
                judul();

                cout << endl;
                cout << "===============================" << endl;
                cout << "|    MENU SHOW ARCHIVE DATA   |" << endl;
                cout << "===============================" << endl << endl;
                
                tampilkanArchive();
                
                break;

            case 5:
                system("cls");
                cout << "SAMPAI BERTEMU KEMBALI";
                break;
            
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
        cout << endl;
		cout << "Kembali ke Menu (y/t) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
