#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <cstring>

using namespace std;

void judul()
{
    cout << "|==============================|" << endl;
    cout << "|          TUGAS LIST 2        |" << endl;
    cout << "|  YOHANES FEBRYAN KANA NYOLA  |" << endl;
    cout << "|         NIM 123220198        |" << endl;
    cout << "|==============================|" << endl
         << endl;
}

typedef struct
{
    char namabuah[30];
    int hargabuah;
} Buah;

struct Node
{
    Buah info;
    Node *next;
} *kepala, *ekor, *awal, *akhir, *bantu;

void buatListBaru();
void sisipList(Buah infobaru);
void cetakList();
void hapusList(string target);
int listkosong();

int main()
{

    buatListBaru();
    int pilihmenu, i = 0, jumlahdata = 0;
    string kembali = "y";
    char nama[30];
    Buah databuah;

    while (kembali == "y")
    {

        menu:

        system("cls");
        judul();

        cout << "== MENU UTAMA ==" << endl;
        cout << " 1. Input Data buah " << endl;
        cout << " 2. Lihat Data buah " << endl;
        cout << " 3. Hapus Data Buah " << endl;
        cout << " Pilih : ";
        cin >> pilihmenu;

        if (pilihmenu == 1)
        {
            system("cls");
            judul();

            cout << " 1. Menu Input Data Buah " << endl;
            cout << "--------------------------" << endl;
            cout << " Masukkan jumlah data : ";
            cin >> jumlahdata;
            cout << endl;

            for (int i = 1; i <= jumlahdata; i++)
            {
                cout << " Data ke-" << i << endl;
                cin.ignore();
                cout << " Masukkan Nama Buah  : ";
                cin.getline(databuah.namabuah, 30);
                cout << " Masukkan Harga Buah : ";
                cin >> databuah.hargabuah;
                cout << endl;
                sisipList(databuah);
            }

            cout << " Data telah tersimpan !!!" << endl;
            cout << " Kembali ke menu utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }

        else if (pilihmenu == 2)
        {
            system("cls");
            judul();

            cout << " 2. Menu Lihat Data Buah " << endl;
            cout << "--------------------------" << endl;

            cetakList();

            cout << " Kembali ke menu utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }

        else if (pilihmenu == 3)
        {
            system("cls");
            judul();

            cout << " 3. Menu Hapus Data Buah " << endl;
            cout << "--------------------------" << endl;
            cout << " Masukkan nama buah yang ingin dihapus : ";
            cin.ignore();
            cin.getline(nama, 30);

            hapusList(nama);

            cout << " Kembali ke menu utama ? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
    }
}

void buatListBaru()
{
    kepala = (Node*) malloc(sizeof(Node));
    ekor = (Node*) malloc(sizeof(Node));
    kepala->info.hargabuah = -1;
    kepala->next = ekor;
    ekor->info.hargabuah = 9999;
    ekor->next = NULL;
}

int listkosong()
{
    if (kepala->next == ekor){
        return (true);
    }
    else{
        return (false);
    }
}

void sisipList(Buah infoBaru)
{
    Node *bantu, *nodeBaru;
    nodeBaru = (Node*) malloc(sizeof(Node));
    nodeBaru->info = infoBaru;
    bantu = kepala;

    while (infoBaru.hargabuah > bantu->next->info.hargabuah)
    {
        bantu = bantu->next;
    }
    nodeBaru->next = bantu->next;
    bantu->next = nodeBaru;
}

void cetakList()
{
    Node *bantu;
    bantu = kepala->next;

    while (bantu != ekor)
    {
        cout << " Nama Buah  : " << bantu->info.namabuah << endl;
        cout << " Harga Buah : " << bantu->info.hargabuah << endl;
        cout << endl;
        bantu = bantu->next;
    }
}

void hapusList(string target)
{
    if (kepala->next == ekor)
    {
        cout << " Data tidak ada " << endl;
    }
    else
    {
        Node *bantu = kepala;
        while (bantu->next->next != ekor && bantu->next->info.namabuah != target)
        {
            bantu = bantu->next;
        }
        if (bantu->next->info.namabuah != target)
        {
            cout << " Data tidak ditemukan! " << endl;
        }
        else
        {
            Node *hapus = bantu->next;
            bantu->next = hapus->next;
            free(hapus);
            cout << " Data ditemukan dan berhasil dihapus " << endl;
        }
    }
}