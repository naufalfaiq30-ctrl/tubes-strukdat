#include "mll.h"

void createListKelas(ListKelas &LK) {
    LK.first = nullptr;
}

adrKelas alokasiKelas(Kelas k) {
    adrKelas P = new ElmKelas;
    P->info = k;
    P->info.jumlah = 0;
    P->firstSiswa = nullptr;
    P->next = nullptr;
    return P;
}

void insertLastKelas(ListKelas &LK, adrKelas P) {
    if (LK.first == nullptr) {
        LK.first = P;
    } else {
        adrKelas Q = LK.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrSiswa alokasiSiswa(Siswa s) {
    adrSiswa S = new ElmSiswa;
    S->info = s;
    S->next = nullptr;
    return S;
}

void insertFirstSiswa(adrKelas K, adrSiswa S) {
    if (K != nullptr && S != nullptr) {
        S->next = K->firstSiswa;
        K->firstSiswa = S;
        K->info.jumlah = K->info.jumlah + 1;
    }
}

adrKelas findKelas(ListKelas LK, string kode) {
    adrKelas P = LK.first, hasil = nullptr;
    while (P != nullptr && hasil == nullptr) {
        if (P->info.kode == kode) {
            hasil = P;
        }
        P = P->next;
    }
    return hasil;
}

adrSiswa findSiswa(ListKelas LK, string nis, adrKelas &asal) {
    adrKelas P = LK.first;
    adrSiswa hasil = nullptr;
    asal = nullptr;
    while (P != nullptr && hasil == nullptr) {
        adrSiswa S = P->firstSiswa;
        while (S != nullptr && hasil == nullptr) {
            if (S->info.nis == nis) {
                hasil = S;
                asal = P;
            }
            S = S->next;
        }
        P = P->next;
    }
    return hasil;
}

void deleteSiswa(adrKelas K, string nis, adrSiswa &S) {
    S = nullptr;
    if (K != nullptr && K->firstSiswa != nullptr) {
        adrSiswa curr = K->firstSiswa, prev = nullptr;
        bool ketemu = false;
        while (curr != nullptr && !ketemu) {
            if (curr->info.nis == nis) {
                ketemu = true;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        if (ketemu) {
            S = curr;
            if (prev == nullptr) {
                K->firstSiswa = curr->next;
            } else {
                prev->next = curr->next;
            }
            S->next = nullptr;
            K->info.jumlah = K->info.jumlah - 1;
        }
    }
}

void deleteKelas(ListKelas &LK, string kode, adrKelas &P) {
    P = nullptr;
    if (LK.first != nullptr) {
        adrKelas curr = LK.first, prev = nullptr;
        bool ketemu = false;
        while (curr != nullptr && !ketemu) {
            if (curr->info.kode == kode) {
                ketemu = true;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        if (ketemu) {
            P = curr;
            if (prev == nullptr) {
                LK.first = curr->next;
            } else {
                prev->next = curr->next;
            }
            P->next = nullptr;
        }
    }
}

void showAll(ListKelas LK) {
    adrKelas P = LK.first;
    cout << "\n==========================================================\n";
    cout << "               DAFTAR SEMUA KELAS & SISWA                 \n";
    cout << "==========================================================\n";
    if (P == nullptr) {
        cout << "  Belum ada data kelas.\n";
    }
    while (P != nullptr) {
        cout << "\n+--------------------------------------------------------+\n";
        cout << "| Kelas      : " << left << setw(15) << P->info.kode
             << " | Tingkat   : " << setw(12) << P->info.tingkat << "|\n";
        cout << "| Wali Kelas : " << left << setw(15) << P->info.wali
             << " | Terisi    : " << P->info.jumlah << "/" << setw(9) << P->info.kapasitas << "|\n";
        cout << "+--------------------------------------------------------+\n";
        adrSiswa S = P->firstSiswa;
        if (S == nullptr) {
            cout << "  (Belum ada siswa di kelas ini)\n";
        }
        int no = 1;
        while (S != nullptr) {
            cout << "  " << no << ". [" << S->info.nis << "] " << left << setw(18) << S->info.nama
                 << " | Rata-rata: " << fixed << setprecision(2) << S->info.rata << "\n";
            no = no + 1;
            S = S->next;
        }
        P = P->next;
    }
    cout << "==========================================================\n";
}

int countSiswa(adrKelas K) {
    int n = 0;
    if (K != nullptr) {
        adrSiswa S = K->firstSiswa;
        while (S != nullptr) {
            n = n + 1;
            S = S->next;
        }
    }
    return n;
}
