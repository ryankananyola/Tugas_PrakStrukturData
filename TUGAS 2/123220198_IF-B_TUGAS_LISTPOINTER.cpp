#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

void judul(){
    cout << "|==============================|" << endl;
    cout << "|       TUGAS LISTPOINTER      |" << endl;
    cout << "|  YOHANES FEBRYAN KANA NYOLA  |" << endl;
    cout << "|         NIM 123220198        |" << endl;
    cout << "|==============================|" << endl << endl;
}

typedef struct
{
    string namaBuah;
    int hargaBuah;
} buah;

struct Node
{
    buah info;
    Node *next;
} * awal, *akhir, *bantu, *hapus, *kepala, *ekor;


void buatListBaru();
void sisipNode(buah IB);
void hapusNode(string IH);
void bacaMaju();
void bacaMundur();
int listKosong();

int main()
{
    buatListBaru();
    int pilihmenu, pilihBaca, jumlahData = 0, i = 0;
    string kembali = "y", nama;
    buah Buah;

    while (kembali == "y")
    {

        menu :

        system("cls");
        judul();

        cout << "== MENU UTAMA ==" << endl;
        cout << " 1. Input Data buah " << endl;
        cout << " 2. Lihat Data buah " << endl;
        cout << " 3. Hapus Buah " << endl;
        cout << " Pilih : ";
        cin >> pilihmenu;

        if (pilihmenu == 1)
        {
            system("cls");
            judul();

            cout << " 1. Menu Input Data Buah " << endl;
            cout << "--------------------------" << endl << endl;
            cout << " Masukkan jumlah Data : ";
            cin >> jumlahData;
            cout << endl;
            for (int i = 1; i <= jumlahData; i++)
            {
                cout << " Data ke-" << i << endl;
                cin.ignore();
                cout << "Masukkan nama buah  : ";
                getline(cin, Buah.namaBuah);
                cout << "Masukkan harga buah : ";
                cin >> Buah.hargaBuah;
                cout << endl;
                sisipNode(Buah);
            }
            cout << " Data telah tersimpan! " << endl;
            cout << " Kembali ke menu awal? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
        else if (pilihmenu == 2)
        {
            system("cls");
            judul();

            cout << " 2. Menu Lihat Data Buah " << endl;
            cout << "--------------------------" << endl;
            cout << "1. Harga Terendah ke Tertinggi" << endl;
            cout << "2. Harga Tertinggi ke Terendah" << endl;
            cout << "Pilih : ";
            cin >> pilihBaca;
            cout << endl;
            if (pilihBaca == 1)
            {
                bacaMaju();
            }
            else if (pilihBaca == 2)
            {
                bacaMundur();
            }
            else
                cout << " Menu Tidak Ditemukan " << endl;

            cout << " Kembali ke menu awal? (y/n) : ";
            cin >> kembali;
            cout << endl;
        }
        else if (pilihmenu == 3)
        {
            system("cls");
            judul();
            
            cin.ignore();
            cout << " 3 Menu Hapus Data Buah " << endl;
            cout << "=========================" << endl;
            cout << endl << " Masukkan nama buah yang ingin dihapus " << endl;
            cout << " Nama buah : ";
            getline(cin, nama);
            hapusNode(nama);
            
            cout << " Kembali ke menu awal? (y/n)";
            cin >> kembali;
            cout << endl;
        }
        else
            cout << " Pilihan Menu tidak ada " << endl;
    }
}
void buatListBaru()
{
    kepala = new Node;
    ekor = new Node;
    kepala->info.hargaBuah = -9999;
    kepala->next = ekor;
    ekor->info.hargaBuah = 9999;
    ekor->next = NULL;
    awal = NULL;
    akhir = NULL;
}
int listKosong()
{
    if (kepala->next == ekor)
        return (true);
    else
        return (false);
}
void sisipNode(buah IB)
{
    Node *NB, *bantu;
    NB = new Node;
    NB->info = IB;
    bantu = kepala;
    while (IB.hargaBuah > bantu->next->info.hargaBuah)
        bantu = bantu->next;
    NB->next = bantu->next;
    bantu->next = NB;
}
void hapusNode(string IH)
{
    Node *hapus, *bantu;
    if (listKosong())
        cout << " List masih kosong " << endl;
    else
    {
        bantu = kepala;
        while (bantu->next != ekor && IH != bantu->next->info.namaBuah)
            bantu = bantu->next;

        if (IH == bantu->next->info.namaBuah)
        {
            hapus = bantu->next;
            bantu->next = hapus->next;
            free(hapus);
            cout << endl << " Data berhasil dihapus " << endl;
        }
        else
            cout << endl << " Data tidak ditemukan! ";
    }
}
void bacaMaju()
{
    Node *bantu;
    bantu = kepala->next;

    while (bantu != ekor)
    {
        cout << "Nama buah\t: " << bantu->info.namaBuah << endl;
        cout << "Harga buah\t: " << bantu->info.hargaBuah << endl;
        cout << endl;
        bantu = bantu->next;
    }
}
void bacaMundur()
{
    Node *depan, *bantu;
    depan = kepala;
    kepala = ekor;
    do
    {
        bantu = depan;
        while (bantu->next != ekor)
            bantu = bantu->next;
        ekor->next = bantu;
        ekor = bantu;
    } while (ekor != depan);
    ekor->next = NULL;
    bantu = kepala->next;
    while (bantu != ekor)
    {
        cout << "Nama buah   : " << bantu->info.namaBuah << endl;
        cout << "Harga buah  : " << bantu->info.hargaBuah << endl;
        cout << endl;
        bantu = bantu->next;
    }
}
