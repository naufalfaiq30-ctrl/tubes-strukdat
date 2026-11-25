#include "bst.h"

void createBST(BST &T) {
    T.root = nullptr;
}

adrNode alokasiNode(InfoBST d) {
    adrNode P = new NodeBST;
    P->info = d;
    P->left = nullptr;
    P->right = nullptr;
    return P;
}

void insertNode(adrNode &root, InfoBST d) {
    if (root == nullptr) {
        root = alokasiNode(d);
    } else if (d.rata < root->info.rata) {
        insertNode(root->left, d);
    } else {
        insertNode(root->right, d);
    }
}

adrNode searchNode(adrNode root, float key) {
    adrNode curr = root, hasil = nullptr;
    while (curr != nullptr && hasil == nullptr) {
        if (curr->info.rata == key) {
            hasil = curr;
        } else if (key < curr->info.rata) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return hasil;
}

adrNode findMin(adrNode root) {
    adrNode curr = root;
    if (curr != nullptr) {
        while (curr->left != nullptr) {
            curr = curr->left;
        }
    }
    return curr;
}

adrNode findMax(adrNode root) {
    adrNode curr = root;
    if (curr != nullptr) {
        while (curr->right != nullptr) {
            curr = curr->right;
        }
    }
    return curr;
}

void deleteNode(adrNode &root, float key, string nis) {
    if (root != nullptr) {
        if (key < root->info.rata) {
            deleteNode(root->left, key, nis);
        } else if (key > root->info.rata) {
            deleteNode(root->right, key, nis);
        } else if (root->info.nis != nis) {
            deleteNode(root->right, key, nis);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                adrNode t = root;
                root = root->right;
                delete t;
            } else if (root->right == nullptr) {
                adrNode t = root;
                root = root->left;
                delete t;
            } else {
                adrNode succ = findMin(root->right);
                root->info = succ->info;
                deleteNode(root->right, succ->info.rata, succ->info.nis);
            }
        }
    }
}

void inOrder(adrNode root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << "  [" << root->info.nis << "] " << left << setw(18) << root->info.nama
             << " | Kelas: " << setw(8) << root->info.kodeKelas
             << " | Rata: " << fixed << setprecision(2) << root->info.rata << "\n";
        inOrder(root->right);
    }
}

void preOrder(adrNode root) {
    if (root != nullptr) {
        cout << "  [" << root->info.nis << "] " << left << setw(18) << root->info.nama
             << " | Kelas: " << setw(8) << root->info.kodeKelas
             << " | Rata: " << fixed << setprecision(2) << root->info.rata << "\n";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(adrNode root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << "  [" << root->info.nis << "] " << left << setw(18) << root->info.nama
             << " | Kelas: " << setw(8) << root->info.kodeKelas
             << " | Rata: " << fixed << setprecision(2) << root->info.rata << "\n";
    }
}

int getHeight(adrNode root) {
    int h = 0;
    if (root != nullptr) {
        int l = getHeight(root->left), r = getHeight(root->right);
        h = 1 + (l > r ? l : r);
    }
    return h;
}

int countNodes(adrNode root) {
    int c = 0;
    if (root != nullptr) {
        c = 1 + countNodes(root->left) + countNodes(root->right);
    }
    return c;
}

void updateKelasBST(adrNode root, string nis, string kodeBaru) {
    if (root != nullptr) {
        if (root->info.nis == nis) {
            root->info.kodeKelas = kodeBaru;
        }
        updateKelasBST(root->left, nis, kodeBaru);
        updateKelasBST(root->right, nis, kodeBaru);
    }
}
