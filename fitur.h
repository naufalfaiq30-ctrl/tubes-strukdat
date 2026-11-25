#ifndef FITUR_H
#define FITUR_H

#include "mll.h"
#include "bst.h"

/*
I.S. : rata terdefinisi
F.S. : Mengembalikan huruf predikat A sampai E berdasarkan nilai rata-rata
*/
string konversiPredikat(float rata);

/*
I.S. : LK, T, kodeKelas, dan s terdefinisi
F.S. : Jika kelas ada, kapasitas belum penuh, dan NIS belum terdaftar, siswa ditambahkan ke MLL dan BST
*/
void tambahSiswa(ListKelas &LK, BST &T, string kodeKelas, Siswa s);

/*
I.S. : LK, T, dan kodeKelas terdefinisi
F.S. : Jika kelas ditemukan, seluruh siswa pada kelas dihapus dari MLL dan BST, lalu elemen kelas dihapus dari LK
*/
void hapusKelasTotal(ListKelas &LK, BST &T, string kodeKelas);

/*
I.S. : LK, T, nis, t, uts, dan uas terdefinisi
F.S. : Nilai siswa diperbarui pada MLL dan posisi nodenya di BST disesuaikan dengan nilai rata-rata baru
*/
void updateNilai(ListKelas &LK, BST &T, string nis, float t, float uts, float uas);

/*
I.S. : root terdefinisi, no bernilai 0
F.S. : Menampilkan maksimal 10 siswa dengan nilai rata-rata tertinggi (reverse in-order) beserta kelas dan predikatnya
*/
void top10Besar(adrNode root, int &no);

/*
I.S. : LK, T, nis, dan kodeTujuan terdefinisi
F.S. : Jika syarat tingkat sama dan kapasitas kelas tujuan mencukupi, siswa dipindah ke kelas tujuan dan BST diperbarui
*/
void pindahKelas(ListKelas &LK, BST &T, string nis, string kodeTujuan);

/*
I.S. : LK dan kkm terdefinisi
F.S. : Menampilkan daftar siswa dengan nilai di bawah kkm serta kelas dengan rata-rata nilai tertinggi
*/
void laporanKelasDanKKM(ListKelas LK, float kkm);

/*
I.S. : LK terdefinisi
F.S. : Menampilkan seluruh siswa beserta kelas, rata-rata nilai, dan predikat hurufnya
*/
void tampilPredikatSemua(ListKelas LK);

#endif
