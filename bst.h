#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct InfoBST {
    float rata;
    string nis, nama, kodeKelas;
};

typedef struct NodeBST* adrNode;
struct NodeBST {
    InfoBST info;
    adrNode left, right;
};

struct BST {
    adrNode root;
};

/*
I.S. : Sembarang
F.S. : Terbentuk pohon BST kosong dengan T.root bernilai nullptr
*/
void createBST(BST &T);

/*
I.S. : Data d terdefinisi
F.S. : Mengembalikan alamat NodeBST baru dengan left = nullptr dan right = nullptr
*/
adrNode alokasiNode(InfoBST d);

/*
I.S. : root terdefinisi (boleh nullptr), data d terdefinisi
F.S. : Node baru masuk ke BST terurut berdasarkan rata (nilai lebih kecil ke kiri, nilai sama atau lebih besar ke kanan)
*/
void insertNode(adrNode &root, InfoBST d);

/*
I.S. : root dan key terdefinisi
F.S. : Mengembalikan alamat node pertama dengan rata == key, atau nullptr jika tidak ditemukan
*/
adrNode searchNode(adrNode root, float key);

/*
I.S. : root, key, dan nis terdefinisi
F.S. : Node dengan rata == key dan nis yang sesuai dihapus dari BST (menangani 0, 1, dan 2 anak)
*/
void deleteNode(adrNode &root, float key, string nis);

/*
I.S. : root terdefinisi
F.S. : Menampilkan seluruh data node secara traversal in-order ke layar
*/
void inOrder(adrNode root);

/*
I.S. : root terdefinisi
F.S. : Menampilkan seluruh data node secara traversal pre-order ke layar
*/
void preOrder(adrNode root);

/*
I.S. : root terdefinisi
F.S. : Menampilkan seluruh data node secara traversal post-order ke layar
*/
void postOrder(adrNode root);

/*
I.S. : root terdefinisi
F.S. : Mengembalikan alamat node dengan nilai rata-rata terkecil, atau nullptr jika pohon kosong
*/
adrNode findMin(adrNode root);

/*
I.S. : root terdefinisi
F.S. : Mengembalikan alamat node dengan nilai rata-rata terbesar, atau nullptr jika pohon kosong
*/
adrNode findMax(adrNode root);

/*
I.S. : root terdefinisi
F.S. : Mengembalikan tinggi pohon BST (0 jika kosong)
*/
int getHeight(adrNode root);

/*
I.S. : root terdefinisi
F.S. : Mengembalikan jumlah total node pada BST
*/
int countNodes(adrNode root);

/*
I.S. : root, nis, dan kodeBaru terdefinisi
F.S. : Field kodeKelas pada node dengan nis yang cocok di BST diperbarui menjadi kodeBaru
*/
void updateKelasBST(adrNode root, string nis, string kodeBaru);

#endif
