#include <iostream>
#include <vector>
#include <string>


struct Tugas {
    int id;
    std::string deskripsi;
    std::string petugas;
    bool selesai;
};

class ManajemenKebersihan {
private:
    std::vector<Tugas> daftarTugas;
    int nextId;

public:
    ManajemenKebersihan() : nextId(1) {}

    
    void tambahTugas() {
        std::string deskripsi, petugas;
        
        std::cout << "Deskripsi tugas: ";
        std::getline(std::cin, deskripsi);
        std::cout << "Nama petugas: ";
        std::getline(std::cin, petugas);

        if (!deskripsi.empty() && !petugas.empty()) {
            daftarTugas.push_back({nextId++, deskripsi, petugas, false});
            std::cout << "Tugas ditambahkan!\n";
        } else {
            std::cout << "Deskripsi dan petugas harus diisi!\n";
        }
    }

    
    void tampilkanTugas() {
        if (daftarTugas.empty()) {
            std::cout << "Tidak ada tugas.\n";
            return;
        }

        std::cout << "\nDaftar Tugas:\n";
        for (const auto& tugas : daftarTugas) {
            std::cout << tugas.id << ". " << tugas.deskripsi 
                     << " (Petugas: " << tugas.petugas << ") - "
                     << (tugas.selesai ? "Selesai" : "Belum selesai") << "\n";
        }
    }

    
    void selesaikanTugas() {
        int id;
        std::cout << "ID tugas yang selesai: ";
        std::cin >> id;

        for (auto& tugas : daftarTugas) {
            if (tugas.id == id) {
                tugas.selesai = true;
                std::cout << "Tugas selesai!\n";
                return;
            }
        }
        std::cout << "ID tidak ditemukan!\n";
    }
};

int main() {
    ManajemenKebersihan manajer;
    int pilihan;

    while (true) {
        std::cout << "\nMenu:\n"
                  << "1. Tambah Tugas\n"
                  << "2. Lihat Tugas\n"
                  << "3. Selesaikan Tugas\n"
                  << "4. Keluar\n"
                  << "Pilihan: ";
        
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan) {
            case 1:
                manajer.tambahTugas();
                break;
            case 2:
                manajer.tampilkanTugas();
                break;
            case 3:
                manajer.selesaikanTugas();
                break;
            case 4:
                std::cout << "Program selesai.\n";
                return 0;
            default:
                std::cout << "Pilihan tidak valid!\n";
        }
    }
}