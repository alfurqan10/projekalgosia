#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Barang {
    string nama;
    string kode;
    int harga;
    int stok;
    Barang* next;
};
    Barang* head = nullptr;

Barang* createBarang(string nama, string kode, int harga, int stok) {
    Barang* baru = new Barang;
    baru->nama = nama;
    baru->kode = kode;
    baru->harga = harga;
    baru->stok = stok;
    baru->next = nullptr;
    return baru;
    
}
void tambahBarang(string nama, string kode, int harga, int stok) {
    Barang* baru = createBarang(nama, kode, harga, stok);
    if (head == nullptr) {
        head = baru;
    } else {
        Barang* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}
void tampilkanBarang(bool termurah) {
    if (head == nullptr) {
        cout << "Belum ada data barang.\n";
        return;
    }

    // Hitung jumlah barang
    int jumlah = 0;
    Barang* temp = head;
    while (temp != nullptr) {
        jumlah++;
        temp = temp->next;
    }

    // Simpan pointer ke barang-barang dalam array
    Barang** arr = new Barang*[jumlah];
    temp = head;
    for (int i = 0; i < jumlah; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    // Urutkan array berdasarkan harga (Bubble Sort)
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((termurah && arr[j]->harga > arr[j+1]->harga) ||
                (!termurah && arr[j]->harga < arr[j+1]->harga)) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    // Tampilkan hasilnya
    cout << "========== STOK " << (termurah ? "TERMURAH" : "TERMAHAL") << " ==========\n";
    cout << "============================================================\n";
    cout << "| " << setw(10) << left << "Kode"
         << "| " << setw(20) << left << "Nama Barang"
         << "| " << setw(10) << "Harga"
         << "| " << setw(10) << "Stok"
         << "|\n";
    cout << "============================================================\n";

    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(10) << left << arr[i]->kode
             << "| " << setw(20) << left << arr[i]->nama
             << "| " << setw(10) << arr[i]->harga
             << "| " << setw(10) << arr[i]->stok
             << "|\n";
    }

    cout << "============================================================\n";

    delete[] arr; // Bebaskan memori
}
void hapusBarang(string kode) {
    if (head == nullptr) {
        cout << "Tidak ada data barang." << endl;
        return;
    }
    Barang* temp = head;
    Barang* prev = nullptr;
    while (temp != nullptr && temp->kode != kode) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Barang dengan kode " << kode << " tidak ditemukan." << endl;
        return;
    }
    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Barang dengan kode " << kode << " telah dihapus." << endl;
}
void menu() {
    cout << "===============================" << endl;
    cout << "| SITEM MANAJEMEN STOK GUDANG |" << endl;
    cout << "===============================" << endl;
    cout << "| 1. Tambah Barang            |" << endl;
    cout << "| 2. Tampilkan Barang         |"<< endl;
    cout << "| 3. Hapus Barang             |" << endl;
    cout << "| 4. Keluar                   |" << endl;
    cout << "===============================" << endl;
}
int main() {
    int pilihan;
    string nama, kode;
    int harga, stok;

    do {
        menu();
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
            int jumlah;
            cout << "Berapa banyak barang yang ingin diinput? ";
            cin >> jumlah;
            cin.ignore();
            for (int i = 0; i < jumlah; i++) {
                string nama, kode;
                int harga, stok;
                cout << "\nBarang ke-" << i+1 << endl;
                cout << "Nama Barang: "; getline(cin, nama);
                cout << "Kode Barang: "; getline(cin, kode);
                cout << "Harga: "; cin >> harga;
                cout << "Stok: "; cin >> stok;
                cin.ignore(); 
                tambahBarang(nama, kode, harga, stok);
            }
                 break;

            case 2:
                tampilkanBarang(true);
                cout << endl;
                tampilkanBarang(false);
                cout << endl;
                break;
            case 3:
                cout << "Masukkan kode barang yang ingin dihapus: ";
                cin >> kode;
                hapusBarang(kode);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}

