#include "fitur.h"

string konversiPredikat(float rata) {
    string predikat = "E";
    if (rata >= 85.0f) {
        predikat = "A";
    } else if (rata >= 75.0f) {
        predikat = "B";
    } else if (rata >= 65.0f) {
        predikat = "C";
    } else if (rata >= 55.0f) {
        predikat = "D";
    }
    return predikat;
}

void tambahSiswa(ListKelas &LK, BST &T, string kodeKelas, Siswa s) {
    adrKelas K = findKelas(LK, kodeKelas);
    adrKelas cek = nullptr;
    if (K != nullptr && K->info.jumlah < K->info.kapasitas && findSiswa(LK, s.nis, cek) == nullptr) {
        s.rata = (s.tugas + s.uts + s.uas) / 3.0f;
        insertFirstSiswa(K, alokasiSiswa(s));

        InfoBST infoB;
        infoB.rata = s.rata;
        infoB.nis = s.nis;
        infoB.nama = s.nama;
        infoB.kodeKelas = K->info.kode;
        insertNode(T.root, infoB);

        cout << "  [OK] Siswa " << s.nama << " masuk ke kelas " << K->info.kode
             << " (Rata-rata: " << fixed << setprecision(2) << s.rata << ")\n";
    } else {
        cout << "  [GAGAL] Cek kode kelas, kapasitas, atau duplikat NIS.\n";
    }
}

void hapusKelasTotal(ListKelas &LK, BST &T, string kodeKelas) {
    adrKelas P = nullptr;
    deleteKelas(LK, kodeKelas, P);
    if (P != nullptr) {
        adrSiswa S = P->firstSiswa;
        while (S != nullptr) {
            adrSiswa hapusS = S;
            S = S->next;
            deleteNode(T.root, hapusS->info.rata, hapusS->info.nis);
            delete hapusS;
        }
        delete P;
        cout << "  [OK] Kelas " << kodeKelas << " beserta seluruh siswanya telah dihapus.\n";
    } else {
        cout << "  [GAGAL] Kelas " << kodeKelas << " tidak ditemukan.\n";
    }
}

void updateNilai(ListKelas &LK, BST &T, string nis, float t, float uts, float uas) {
    adrKelas K = nullptr;
    adrSiswa S = findSiswa(LK, nis, K);
    if (S != nullptr && K != nullptr) {
        deleteNode(T.root, S->info.rata, S->info.nis);
        S->info.tugas = t;
        S->info.uts = uts;
        S->info.uas = uas;
        S->info.rata = (t + uts + uas) / 3.0f;

        InfoBST infoB;
        infoB.rata = S->info.rata;
        infoB.nis = S->info.nis;
        infoB.nama = S->info.nama;
        infoB.kodeKelas = K->info.kode;
        insertNode(T.root, infoB);

        cout << "  [OK] Nilai " << S->info.nama << " diperbarui -> Rata-rata: "
             << fixed << setprecision(2) << S->info.rata
             << " (Predikat " << konversiPredikat(S->info.rata) << ")\n";
    } else {
        cout << "  [GAGAL] Siswa dengan NIS " << nis << " tidak ditemukan.\n";
    }
}

void top10Besar(adrNode root, int &no) {
    if (root != nullptr && no < 10) {
        top10Besar(root->right, no);
        if (no < 10) {
            no = no + 1;
            cout << "  #" << no << "  [" << root->info.nis << "] " << left << setw(18) << root->info.nama
                 << " | Kelas: " << setw(8) << root->info.kodeKelas
                 << " | Rata: " << fixed << setprecision(2) << root->info.rata
                 << " (" << konversiPredikat(root->info.rata) << ")\n";
        }
        top10Besar(root->left, no);
    }
}

void pindahKelas(ListKelas &LK, BST &T, string nis, string kodeTujuan) {
    adrKelas asal = nullptr, tujuan = findKelas(LK, kodeTujuan);
    adrSiswa S = findSiswa(LK, nis, asal);
    if (S != nullptr && asal != nullptr && tujuan != nullptr &&
        asal->info.tingkat == tujuan->info.tingkat && tujuan->info.jumlah < tujuan->info.kapasitas) {
        adrSiswa dipindah = nullptr;
        deleteSiswa(asal, nis, dipindah);
        if (dipindah != nullptr) {
            insertFirstSiswa(tujuan, dipindah);
            updateKelasBST(T.root, nis, tujuan->info.kode);
            cout << "  [OK] " << dipindah->info.nama << " pindah dari " << asal->info.kode
                 << " ke " << tujuan->info.kode << ".\n";
        }
    } else {
        cout << "  [GAGAL] Pastikan NIS & kelas valid, tingkat sama, dan slot tersedia.\n";
    }
}

void laporanKelasDanKKM(ListKelas LK, float kkm) {
    adrKelas P = LK.first, terbaik = nullptr;
    float maxRata = -1.0f;
    int jumlahRemed = 0;

    cout << "\n==========================================================\n";
    cout << "           LAPORAN KELAS TERBAIK & SISWA < KKM            \n";
    cout << "==========================================================\n";
    cout << "Daftar Siswa di Bawah KKM (" << fixed << setprecision(2) << kkm << "):\n";

    while (P != nullptr) {
        adrSiswa S = P->firstSiswa;
        float sum = 0.0f;
        int n = 0;
        while (S != nullptr) {
            sum = sum + S->info.rata;
            n = n + 1;
            if (S->info.rata < kkm) {
                jumlahRemed = jumlahRemed + 1;
                cout << "  " << jumlahRemed << ". [" << S->info.nis << "] " << left << setw(18) << S->info.nama
                     << " | Kelas: " << setw(8) << P->info.kode
                     << " | Rata: " << fixed << setprecision(2) << S->info.rata << "\n";
            }
            S = S->next;
        }
        if (n > 0 && (sum / n) > maxRata) {
            maxRata = sum / n;
            terbaik = P;
        }
        P = P->next;
    }

    if (jumlahRemed == 0) {
        cout << "  Tidak ada siswa yang nilainya di bawah KKM.\n";
    }

    cout << "\nKelas dengan Rata-Rata Tertinggi:\n";
    if (terbaik != nullptr) {
        cout << "  -> Kelas " << terbaik->info.kode << " (Wali: " << terbaik->info.wali
             << ") | Rata-rata: " << fixed << setprecision(2) << maxRata << "\n";
    } else {
        cout << "  -> Belum ada data siswa.\n";
    }
    cout << "==========================================================\n";
}

void tampilPredikatSemua(ListKelas LK) {
    adrKelas P = LK.first;
    cout << "\n==========================================================\n";
    cout << "                  PREDIKAT NILAI SISWA                    \n";
    cout << "==========================================================\n";
    if (P == nullptr) {
        cout << "  Belum ada data.\n";
    }
    while (P != nullptr) {
        adrSiswa S = P->firstSiswa;
        while (S != nullptr) {
            cout << "  [" << S->info.nis << "] " << left << setw(18) << S->info.nama
                 << " | Kelas: " << setw(8) << P->info.kode
                 << " | Rata: " << fixed << setprecision(2) << S->info.rata
                 << " | Predikat: " << konversiPredikat(S->info.rata) << "\n";
            S = S->next;
        }
        P = P->next;
    }
    cout << "==========================================================\n";
}
