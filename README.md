\# Manajemen Kelas Sekolah (MLL-00 \& BST)



Program berbasis console dalam bahasa C++ untuk mengelola data kelas, siswa, nilai, serta peringkat nilai menggunakan struktur data Multi Linked List (MLL-00) dan Binary Search Tree (BST) pada Tugas Besar mata kuliah Struktur Data.



\## Anggota Kelompok

\- Muhammad Naufal Faiq Aljizrawi - 103012500028

\- Muhammad Fakhri Saleh - 103012530020

\- Muhammad Zahid Alfathin - 103012500214



\## Struktur Data yang Digunakan

1\. \*\*Multi Linked List (MLL-00 / Relasi 1-N)\*\*

&#x20;  - \*\*Parent (`Kelas`):\*\* Menyimpan data kelas (`kode`, `tingkat`, `wali`, `kapasitas`, `jumlah`) menggunakan \*insert last\*.

&#x20;  - \*\*Child (`Siswa`):\*\* Berada di dalam tiap elemen kelas, menyimpan data siswa (`nis`, `nama`, `tugas`, `uts`, `uas`, `rata`) menggunakan \*insert first\*.

2\. \*\*Binary Search Tree (BST)\*\*

&#x20;  - Menggunakan nilai rata-rata siswa (`rata`) sebagai `key` untuk pencarian dan pemeringkatan.

&#x20;  - Nilai lebih kecil masuk ke \*subtree\* kiri, sedangkan nilai sama atau lebih besar masuk ke \*subtree\* kanan.



\## Fitur Program

\- \*\*Operasi MLL:\*\* Tambah kelas, tambah siswa ke kelas, tampilkan seluruh kelas dan siswa, cari kelas/siswa, hapus siswa/kelas, dan hitung jumlah siswa pada kelas.

\- \*\*Operasi BST:\*\* Insert node, cari node, hapus node (0, 1, dan 2 anak), traversal (\*in-order\*, \*pre-order\*, \*post-order\*), nilai minimum dan maksimum, tinggi pohon, serta jumlah node.

\- \*\*Fungsionalitas Khusus Topik 4:\*\*

&#x20; - Input / update nilai siswa beserta pembaruan posisinya di BST.

&#x20; - Menampilkan peringkat 10 besar sekolah (\*reverse in-order\*).

&#x20; - Memindahkan siswa ke kelas setingkat dengan pengecekan kapasitas.

&#x20; - Menampilkan kelas dengan rata-rata nilai tertinggi dan daftar siswa dengan nilai di bawah KKM.

\- \*\*Fitur Tambahan:\*\* Konversi nilai rata-rata ke predikat huruf (`A` - `E`).



\## Cara Menjalankan Program

Pastikan seluruh file (`mll.h`, `mll.cpp`, `bst.h`, `bst.cpp`, `fitur.h`, `fitur.cpp`, `main.cpp`) berada dalam satu folder, lalu jalankan:



```bash

g++ main.cpp mll.cpp bst.cpp fitur.cpp -o program\_kelas

./program\_kelas

