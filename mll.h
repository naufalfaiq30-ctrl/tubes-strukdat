#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Siswa {
    string nis, nama;
    float tugas, uts, uas, rata;
};

typedef struct ElmSiswa* adrSiswa;
struct ElmSiswa {
    Siswa info;
    adrSiswa next;
};

struct Kelas {
    string kode, wali;
    int tingkat, kapasitas, jumlah;
};

typedef struct ElmKelas* adrKelas;
struct ElmKelas {
    Kelas info;
    adrSiswa firstSiswa;
    adrKelas next;
};

struct ListKelas {
    adrKelas first;
};

/*
I.S. : Sembarang
F.S. : Terbentuk ListKelas kosong dengan LK.first bernilai nullptr
*/
void createListKelas(ListKelas &LK);

/*
I.S. : Data kelas k terdefinisi
F.S. : Mengembalikan alamat elemen Kelas baru dengan jumlah = 0, firstSiswa = nullptr, dan next = nullptr
*/
adrKelas alokasiKelas(Kelas k);

/*
I.S. : LK terdefinisi (boleh kosong), P menunjuk ke elemen Kelas baru
F.S. : Elemen P ditambahkan sebagai elemen terakhir pada LK
*/
void insertLastKelas(ListKelas &LK, adrKelas P);

/*
I.S. : Data siswa s terdefinisi
F.S. : Mengembalikan alamat elemen Siswa baru dengan next = nullptr
*/
adrSiswa alokasiSiswa(Siswa s);

/*
I.S. : K menunjuk ke elemen Kelas valid, S menunjuk ke elemen Siswa baru
F.S. : Elemen S ditambahkan di awal list siswa pada K dan K->info.jumlah bertambah 1
*/
void insertFirstSiswa(adrKelas K, adrSiswa S);

/*
I.S. : LK dan kode kelas terdefinisi
F.S. : Mengembalikan alamat elemen Kelas yang cocok dengan kode, atau nullptr jika tidak ditemukan
*/
adrKelas findKelas(ListKelas LK, string kode);

/*
I.S. : LK dan nis siswa terdefinisi
F.S. : Mengembalikan alamat elemen Siswa jika ditemukan dan mengisi asal dengan kelas tempat siswa berada, atau nullptr jika tidak ada
*/
adrSiswa findSiswa(ListKelas LK, string nis, adrKelas &asal);

/*
I.S. : K menunjuk ke elemen Kelas valid, nis terdefinisi
F.S. : Jika siswa dengan nis ditemukan di K, elemen dilepas dan disimpan di S serta K->info.jumlah berkurang 1
*/
void deleteSiswa(adrKelas K, string nis, adrSiswa &S);

/*
I.S. : LK dan kode kelas terdefinisi
F.S. : Jika kelas dengan kode ditemukan, elemen kelas dilepas dari LK dan disimpan di P
*/
void deleteKelas(ListKelas &LK, string kode, adrKelas &P);

/*
I.S. : LK terdefinisi
F.S. : Seluruh data kelas beserta daftar siswa di dalamnya ditampilkan ke layar
*/
void showAll(ListKelas LK);

/*
I.S. : K terdefinisi
F.S. : Mengembalikan jumlah elemen siswa pada kelas K
*/
int countSiswa(adrKelas K);

#endif
