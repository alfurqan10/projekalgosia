    #include <iostream>
    using namespace std;

    struct kendaraan
    {
        string plat;
        string jenis;
        string merk;
        string model;
        string pemilik;
        int tahun;
    };

    void inputData (kendaraan kdr[], int &jumlahkdr){
        int n;
        cout << "\nMasukkan jumlah kendaraan yang ingin diinput: ";
        cin >> n;
        cin.ignore();
        
        for (int i = 0; i < n; i++) {
            cout << "\nNomor plat: ";
            getline(cin, kdr[jumlahkdr].plat); 
            cout << "Jenis kendaraan : ";
            getline(cin, kdr[jumlahkdr].jenis); 
            cout << "Merk kendaraan : ";
            getline(cin, kdr[jumlahkdr].merk); 
            cout << "Model kendaraan: ";
            getline(cin, kdr[jumlahkdr].model); 
            cout << "Nama Pemilik : ";
            getline(cin, kdr[jumlahkdr].pemilik); 
            cout << "Tahun Produksi : ";
            cin  >> kdr[jumlahkdr].tahun;
            cin.ignore();
            jumlahkdr++;
        }
        cout << "\nData berhasil ditambahkan!\n";
    }
    void tampilData(kendaraan kdr [], int jumlahkdr){
        if (jumlahkdr == 0) { 
            cout << "\nData kendaraan kosong!\n";
            return;
        }
        
        cout << "\nData Kendaraan:\n";
        for (int i = 0; i < jumlahkdr; i++) {
            cout << "\nKendaraan ke-" << i + 1 << ":\n";
            cout << "Nomor plat        : " << kdr[i].plat << endl;
            cout << "Jenis Kendaraan   : " << kdr[i].jenis << endl;
            cout << "Merk Kendaraan    : " << kdr[i].merk << endl;
            cout << "Model Kendaraan   : " << kdr[i].model << endl;
            cout << "Nama Pemilik      : " << kdr[i].pemilik << endl;
            cout << "Tahun Produksi    : " << kdr[i].tahun << endl;
        }
    }
    void bubbleSort(kendaraan kdr[], int jumlahkdr) {
        if (jumlahkdr == 0) {
            cout << "\nData kendaraan kosong!\n";
            return;
        }
        for (int i = 0; i < jumlahkdr - 1; i++) {
            for (int j = 0; j < jumlahkdr - i - 1; j++) {
                if (kdr[j].tahun > kdr[j + 1].tahun) {
                    swap(kdr[j], kdr[j + 1]);
                }
            }
        }
        cout << "\nData berhasil diurutkan dengan Bubble Sort berdasarkan tahun produksi!\n";
        tampilData(kdr, jumlahkdr);
    }
    void sequentialSearch(kendaraan kdr[], int jumlahkdr) {
        if (jumlahkdr == 0) {
            cout << "\nData kendaraan kosong!\n";
            return;
        }
        string nama;
        cout << "\nMasukkan nama pemilik yang ingin dicari: ";
        cin.ignore();
        getline(cin, nama);

        bool found = false;
        for (int i = 0; i < jumlahkdr; i++) {
            if (kdr[i].pemilik == nama) {
                cout << "\nNama pemilik ditemukan!\n";
                cout << "Nomor plat        : " << kdr[i].plat << endl;
                cout << "Jenis Kendaraan   : " << kdr[i].jenis << endl;
                cout << "Merk Kendaraan    : " << kdr[i].merk << endl;
                cout << "Model Kendaraan   : " << kdr[i].model << endl;
                cout << "Nama Pemilik      : " << kdr[i].pemilik << endl;
                cout << "Tahun Produksi    : " << kdr[i].tahun << endl;
                found = true;
                
            }
        }
        if (!found) {
            cout << "\nPemilik " << nama << " tidak ditemukan!\n";
        }
    }

    int main (){
        int jumlahkdr = 0;
        kendaraan kdr[100];
        int menu;
        string ulang;
        do {
            cout << "--------------------\n";
            cout << "    Menu Pilihan" << endl;
            cout << "--------------------\n";
            cout << "1. Input Data " << endl;
            cout << "2. Tampil Data " << endl;
            cout << "3. Urutkan kendaraan (Bubble Sort) " << endl;
            cout << "4. Cari data kendaraan (Sequential Search) " << endl;
            cout << "5. Exit " << endl;
            cout << "Pilih Menu: ";
            cin >> menu;

            switch (menu) {
                case 1:
                    inputData(kdr, jumlahkdr);
                    break;
                case 2:
                    tampilData(kdr, jumlahkdr);
                    break;
                case 3:
                    bubbleSort(kdr, jumlahkdr);
                    break;
                    
                case 4:
                    sequentialSearch(kdr, jumlahkdr);
                    break;
                case 5:
                    cout << "Keluar dari program...\n";
                    return 0;
                default:
                    cout << "Pilihan tidak valid!\n";
            }

            cout << "\nIngin kembali ke menu? (y/n): ";
            cin >> ulang;
        } while (ulang == "y" || ulang == "Y");

        return 0;
    }
        


