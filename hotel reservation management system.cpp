#include <iostream>
#include <string>
using namespace std;

const int MAX_ROOMS = 3;
const double ROOM_PRICES_USD[] = {100.0, 120.0, 80.0};

int main() {
    string roomNames[MAX_ROOMS] = {"101", "102", "103"};
    int roomAvailability[MAX_ROOMS] = {5, 3, 2};
    double totalJumlahHargaUSD = 0.0;

    while (true) {
        cout << "Selamat datang di sistem manajemen reservasi hotel" << endl;

        for (int i = 0; i < MAX_ROOMS; i++) {
            cout << "Kamar " << roomNames[i] << ": Tersedia " << roomAvailability[i] << " - Harga: $" << ROOM_PRICES_USD[i] << " per malam" << endl;
        }

        string roomNumber;
        int numRooms, numNights;
        cout << "Masukkan nomor kamar yang ingin dipesan: ";
        cin >> roomNumber;
        cout << "Masukkan jumlah kamar yang dipesan: ";
        cin >> numRooms;
        cout << "Masukkan jumlah malam menginap: ";
        cin >> numNights;

        bool roomAvailable = false;
        double hargaKamarUSD = 0.0;
        double totalBiayaUSD = 0.0;

        for (int i = 0; i < MAX_ROOMS; i++) {
            if (roomNames[i] == roomNumber) {
                if (roomAvailability[i] >= numRooms) {
                    roomAvailable = true;
                    hargaKamarUSD = ROOM_PRICES_USD[i] * numNights;
                    totalBiayaUSD = hargaKamarUSD * numRooms;
                    roomAvailability[i] -= numRooms; // Mengurangi stok kamar
                    totalJumlahHargaUSD += totalBiayaUSD; // Menambahkan total harga ke totalJumlahHargaUSD
                }
                break;
            }
        }

        if (roomAvailable) {
            cout << "Kamar tersedia. Harga per kamar: $" << hargaKamarUSD << " - Total harga reservasi: $" << totalBiayaUSD << endl;
        } else {
            cout << "Kamar tidak tersedia atau jumlah kamar yang diminta tidak mencukupi." << endl;
        }

        string anotherReservation;
        cout << "Ingin melakukan reservasi lagi? (ya/tidak): ";
        cin >> anotherReservation;
        if (anotherReservation != "ya") {
            break;
        }
    }

    if (totalJumlahHargaUSD > 0) {
        cout << "Total jumlah harga dari semua reservasi dalam USD: $" << totalJumlahHargaUSD << endl;
    } else {
        cout << "Tidak ada reservasi yang dibuat." << endl;
    }

    cout << "Terima kasih telah menggunakan sistem manajemen reservasi hotel kami." << endl;

    return 0;
}

