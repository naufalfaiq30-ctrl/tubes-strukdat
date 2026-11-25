#include <iostream>
#include <iomanip>
#include <string>
#include "mll.h"
#include "bst.h"
#include "fitur.h"
using namespace std;

/*
I.S. : LK dan T kosong
F.S. : Terisi data awal beberapa kelas dan siswa untuk pengujian program
*/
void isiDataAwal(ListKelas &LK, BST &T) {
    Kelas k1;
    k1.kode = "10A";
    k1.tingkat = 10;
    k1.wali = "Bu Ani";
    k1.kapasitas = 3;
    k1.jumlah = 0;
    insertLastKelas(LK, alokasiKelas(k1));

    Kelas k2;
    k2.kode = "10B";
    k2.tingkat = 10;
    k2.wali = "Pak Rian";
    k2.kapasitas = 2;
    k2.jumlah = 0;
    insertLastKelas(LK, alokasiKelas(k2));

    Siswa s1;
    s1.nis = "101";
    s1.nama = "Raka";
    s1.tugas = 85;
    s1.uts = 88;
    s1.uas = 90;
    s1.rata = 0;
    tambahSiswa(LK, T, "10A", s1);

    Siswa s2;
    s2.nis = "102";
    s2.nama = "Dimas";
    s2.tugas = 65;
    s2.uts = 70;
    s2.uas = 68;
    s2.rata = 0;
    tambahSiswa(LK, T, "10B", s2);
}

int main() {
    ListKelas LK;
    BST T;
    createListKelas(LK);
    createBST(T);
    isiDataAwal(LK, T);

    int pil = -1;
    while (pil != 0) {
        cout << "\n==========================================================\n";
        cout << "          MANAJEMEN KELAS SEKOLAH (MLL-00 + BST)          \n";
        cout << "==========================================================\n";
        cout << "  1. Tambah Kelas Baru\n";
        cout << "  2. Tambah Siswa ke Kelas\n";
        cout << "  3. Tampilkan Semua Kelas & Siswa\n";
        cout << "  4. Input / Update Nilai Siswa\n";
        cout << "  5. Tampilkan Peringkat 10 Besar Sekolah\n";
        cout << "  6. Pindahkan Siswa ke Kelas Setingkat\n";
        cout << "  7. Laporan Kelas Terbaik & Siswa di Bawah KKM\n";
        cout << "  8. Info BST (Traversal, Min/Max, Tinggi, Node)\n";
        cout << "  9. Predikat Nilai Siswa (A - E)\n";
        cout << " 10. Hapus Kelas Beserta Siswanya\n";
        cout << "  0. Keluar\n";
        cout << "==========================================================\n";
        cout << "Pilih menu: ";
        cin >> pil;

        if (pil == 1) {
            Kelas k;
            cout << "Kode Kelas : ";
            cin >> k.kode;
            cout << "Tingkat    : ";
            cin >> k.tingkat;
            cin.ignore();
            cout << "Wali Kelas : ";
            getline(cin, k.wali);
            cout << "Kapasitas  : ";
            cin >> k.kapasitas;
            k.jumlah = 0;
            insertLastKelas(LK, alokasiKelas(k));
            cout << "  [OK] Kelas " << k.kode << " ditambahkan.\n";
        } else if (pil == 2) {
            string kd;
            Siswa s;
            cout << "Kode Kelas : ";
            cin >> kd;
            cout << "NIS        : ";
            cin >> s.nis;
            cin.ignore();
            cout << "Nama Siswa : ";
            getline(cin, s.nama);
            cout << "Nilai Tugas: ";
            cin >> s.tugas;
            cout << "Nilai UTS  : ";
            cin >> s.uts;
            cout << "Nilai UAS  : ";
            cin >> s.uas;
            s.rata = 0;
            tambahSiswa(LK, T, kd, s);
        } else if (pil == 3) {
            showAll(LK);
        } else if (pil == 4) {
            string nis;
            float t, uts, uas;
            cout << "NIS Siswa  : ";
            cin >> nis;
            cout << "Nilai Tugas: ";
            cin >> t;
            cout << "Nilai UTS  : ";
            cin >> uts;
            cout << "Nilai UAS  : ";
            cin >> uas;
            updateNilai(LK, T, nis, t, uts, uas);
        } else if (pil == 5) {
            int no = 0;
            cout << "\n==========================================================\n";
            cout << "               PERINGKAT 10 BESAR SEKOLAH                 \n";
            cout << "==========================================================\n";
            if (T.root == nullptr) {
                cout << "  Belum ada data nilai.\n";
            } else {
                top10Besar(T.root, no);
            }
            cout << "==========================================================\n";
        } else if (pil == 6) {
            string nis, kd;
            cout << "NIS Siswa         : ";
            cin >> nis;
            cout << "Kode Kelas Tujuan : ";
            cin >> kd;
            pindahKelas(LK, T, nis, kd);
        } else if (pil == 7) {
            float kkm;
            cout << "Batas KKM: ";
            cin >> kkm;
            laporanKelasDanKKM(LK, kkm);
        } else if (pil == 8) {
            cout << "\n==========================================================\n";
            cout << "                      STATISTIK & BST                     \n";
            cout << "==========================================================\n";
            cout << "[In-Order]\n";
            inOrder(T.root);
            cout << "[Pre-Order]\n";
            preOrder(T.root);
            cout << "[Post-Order]\n";
            postOrder(T.root);
            adrNode mn = findMin(T.root), mx = findMax(T.root);
            cout << "----------------------------------------------------------\n";
            cout << "Min Rata-rata : " << (mn != nullptr ? mn->info.rata : 0.0f) << "\n";
            cout << "Max Rata-rata : " << (mx != nullptr ? mx->info.rata : 0.0f) << "\n";
            cout << "Tinggi Pohon  : " << getHeight(T.root) << "\n";
            cout << "Jumlah Node   : " << countNodes(T.root) << "\n";
            cout << "==========================================================\n";
        } else if (pil == 9) {
            tampilPredikatSemua(LK);
        } else if (pil == 10) {
            string kd;
            cout << "Kode Kelas yang akan dihapus: ";
            cin >> kd;
            hapusKelasTotal(LK, T, kd);
        } else if (pil == 0) {
            cout << "Program selesai. Sampai jumpa!\n";
        } else {
            cout << "  [!] Pilihan tidak valid.\n";
        }
    }

    return 0;
}
