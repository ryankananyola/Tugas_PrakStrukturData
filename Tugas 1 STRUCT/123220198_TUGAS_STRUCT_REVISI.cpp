#include <iostream>
#include <cstring>
using namespace std;

// fungsi judul
void judul()
{
    cout << "|==============================|" << endl;
    cout << "|            TUGAS 1           |" << endl;
    cout << "|  YOHANES FEBRYAN KANA NYOLA  |" << endl;
    cout << "|         NIM 123220198        |" << endl;
    cout << "|==============================|" << endl;
}

// Definisi struct untuk merepresentasikan informasi tentang buah
struct Buah
{
    char nama[30];
    float harga;
};

int i, banyakdata, pilih, cardat;
char menu;

// fungsi untuk mencari data buah berdasarkan nama dalam array struct
int caridatanama(const string &carinama, const Buah listBuah[], int nobuah)
{
    int j = 0;
    bool hasil = false;
    for (j = 0; j < nobuah; j++)
    {
        if (listBuah[j].nama == carinama)
        {
            hasil = true;
            break;
        }
    }
    if (hasil)
    {
        return j;
    }
    else
        return 999;
}

int main()
{

    Buah listBuah[5];
    int nobuah = sizeof(listBuah) / sizeof(listBuah[0]);

menu:

    system("cls");
    judul();

    // menu utama
    cout << endl
         << "== DATA NAMA BUAH ==" << endl;
    cout << " 1. Input Data Buah " << endl;
    cout << " 2. Lihat Data Buah " << endl;
    cout << " 3. Cari Data Buah " << endl;
    cout << " Pilih Menu : ";
    cin >> pilih;

    // percabangan menu
    if (pilih == 1)
    {
        system("cls");
        judul();

        cout << endl
             << " 1. Input Data Buah " << endl;
        cout << "------------------------" << endl;
        cout << "  Banyak Data : ";
        cin >> banyakdata;

        //perulangan pada input data
        for (i = 1; i <= banyakdata; i++)
        {
            cout << endl
                 << " Data ke-" << i << endl
                 << endl;
            cout << " Nama Buah  : ";
            cin.ignore();
            cin.getline(listBuah[i].nama, 30);
            cout << " Harga Buah : ";
            cin >> listBuah[i].harga;
            cout << endl;
        }
    }
    if (pilih == 2)
    {
        system("cls");
        judul();

        cout << endl
             << " 2. Output Data Buah " << endl;
        cout << "------------------------" << endl;
        cout << " Banyak Data yang ingin ditampilkan : ";
        cin >> banyakdata;
        
        //perulangan pada output data
        for (i = 1; i <= banyakdata; i++)
        {
            cout << " Data ke-" << i << endl;
            cout << " Nama Buah  : " << listBuah[i].nama << endl;
            cout << " Harga Buah : " << listBuah[i].harga << endl
                 << endl;
        }
    }

    if (pilih == 3)
    {
        system("cls");
        judul();

        cout << " 3. Cari Data Buah " << endl;
        cout << "------------------------" << endl;
        cout << " Cari Data Berdasarkan : " << endl;
        cout << " 1. Nama " << endl;
        cout << " 2. Rentang Harga " << endl;
        cout << " Pilih : ";
        cin >> cardat;

        if (cardat == 1)
        {
            system("cls");
            cout << " Cari Data Berdasarkan Nama " << endl;
            cout << "-----------------------------" << endl;
            cout << " Silahkan Masukkan Nama Buah dari Data yang ingin dicari : ";
            string carinama;
            cin >> carinama;
            int result = caridatanama(carinama, listBuah, nobuah);

            if (result != 999)
            {
                cout << "---------------------------" << endl;
                cout << "Data Buah dengan nama '" << listBuah[result].nama << "' : " << endl;
                cout << "Nama Buah  : " << listBuah[result].nama << endl;
                cout << "Harga Buah : " << listBuah[result].harga << endl;
                cout << "Data berhasil DITEMUKAN" << endl;
            }
            else
            {
                cout << "Data Buah dengan nama '" << carinama << "' tidak ditemukan." << endl;
            }
        }
        if (cardat == 2)
        {
            system("cls");
            cout << " Cari Data Berdasarkan Rentang Harga " << endl;
            cout << "-------------------------------------" << endl;
            cout << " Silahkan Masukkan Rentang Harga Buah dari Data yang ingin dicari : ";

            int batasbawah, batasatas;
            cout << endl
                 << " Masukkan harga minimal  : ";
            cin >> batasbawah;
            cout << " Masukkan harga maksimal : ";
            cin >> batasatas;

            bool ditemukan = false;
            cout << endl
                 << " Data Buah dengan kisaran harga '" << batasbawah << "-" << batasatas << "' : " << endl;
            for (int i = 0; i < 5; i++)
            {
                if (listBuah[i].harga >= batasbawah && listBuah[i].harga <= batasatas)
                {
                    cout << " Nama Buah  : " << listBuah[i].nama << endl;
                    cout << " Harga Buah : " << listBuah[i].harga << endl
                         << endl;
                    ditemukan = true;
                }
            }

            if (!ditemukan)
            {
                cout << endl
                     << " Tidak ada Data Buah dengan kisaran harga tersebut." << endl;
            }
        }
    }

    cout << endl
         << " Kembali ke Menu ? (y/t) : ";
    cin >> menu;

    if (menu == 'Y' || menu == 'y')
    {
        goto menu;
    }
    else if (menu == 'N' || menu == 'n')
    {
        return 0;
    }
    else
    {
        cout << " Program Error " << endl;
    }

    return 0;
}