#include <iostream>
#include <string>

using namespace std;

extern string slotMobil[3];
extern string slotMotor[3];

extern int hitungTarif(int jenis, int durasi);
extern void cetakKarcis(string plat, int jenis, int durasi, int total);

void kendaraanMasuk() {
    int jenis;
    string plat;
    bool slotKetemu = false;

    cout << "\n--- MENU KENDARAAN MASUK ---\n";
    cout << "1. Mobil\n";
    cout << "2. Motor\n";
    cout << "Pilih jenis kendaraan (1/2): ";
    cin >> jenis;

    if (jenis != 1 && jenis != 2) {
        cout << "Pilihan jenis kendaraan tidak valid!\n";
        return;
    }

    cout << "Masukkan Plat Nomor Kendaraan: ";
    cin >> plat;

    if (jenis == 1) {
        for (int i = 0; i < 3; i++) {
            if (slotMobil[i] == "") {
                slotMobil[i] = plat;
                cout << "Mobil dengan plat " << plat << " berhasil parkir di Slot Mobil ke-" << (i + 1) << "\n";
                slotKetemu = true;
                break;
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            if (slotMotor[i] == "") {
                slotMotor[i] = plat;
                cout << "Motor dengan plat " << plat << " berhasil parkir di Slot Motor ke-" << (i + 1) << "\n";
                slotKetemu = true;
                break;
            }
        }
    }

    if (!slotKetemu) {
        cout << "Maaf, Slot Parkir untuk jenis kendaraan ini sudah PENUH!\n";
    }
}

void kendaraanKeluar() {
    string platCari;
    bool ditemukan = false;
    int durasi = 0;

    cout << "\n--- MENU KENDARAAN KELUAR ---\n";
    cout << "Masukkan Plat Nomor yang akan keluar: ";
    cin >> platCari;

    for (int i = 0; i < 3; i++) {
        if (slotMobil[i] == platCari) {
            cout << "Kendaraan ditemukan di Slot Mobil ke-" << (i + 1) << "\n";
            cout << "Masukkan durasi parkir (dalam jam): ";
            cin >> durasi;

            slotMobil[i] = "";
            cout << "Mobil dengan plat " << platCari << " telah keluar dari area parkir.\n";
            
            int total = hitungTarif(1, durasi);
            cetakKarcis(platCari, 1, durasi, total);
            
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        for (int i = 0; i < 3; i++) {
            if (slotMotor[i] == platCari) {
                cout << "Kendaraan ditemukan di Slot Motor ke-" << (i + 1) << "\n";
                cout << "Masukkan durasi parkir (dalam jam): ";
                cin >> durasi;

                slotMotor[i] = "";
                cout << "Motor dengan plat " << platCari << " telah keluar dari area parkir.\n";
                
                int total = hitungTarif(2, durasi);
                cetakKarcis(platCari, 2, durasi, total);
                
                ditemukan = true;
                break;
            }
        }
    }

    if (!ditemukan) {
        cout << "Plat nomor " << platCari << " tidak ditemukan di dalam sistem parkir!\n";
    }
}