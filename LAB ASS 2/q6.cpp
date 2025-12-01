#include <iostream>
#include <vector>
using namespace std;

// ========== Diagonal Matrix ==========
class DiagonalMatrix {
    int n;
    vector<int> d;

public:
    DiagonalMatrix(int n) : n(n), d(n, 0) {}

    void read() {
        cout << "Enter " << n << " diagonal elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
    }

    int get(int i, int j) const {
        if (i == j) return d[i];
        return 0;
    }

    void display() const {
        cout << "Diagonal matrix (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << "\n";
        }
    }
};

// ========== Tri-diagonal Matrix ==========
class TriDiagonalMatrix {
    int n;
    vector<int> a; // size = 3n - 2

public:
    TriDiagonalMatrix(int n) : n(n), a(3 * n - 2, 0) {}

    void read() {
        cout << "For tri-diagonal matrix of size " << n << "x" << n << ":\n";
        cout << "Enter " << n - 1 << " elements of lower diagonal (a[i][i-1]):\n";
        for (int i = 1; i < n; i++) {
            cin >> a[i - 1];
        }
        cout << "Enter " << n << " elements of main diagonal (a[i][i]):\n";
        for (int i = 0; i < n; i++) {
            cin >> a[(n - 1) + i];
        }
        cout << "Enter " << n - 1 << " elements of upper diagonal (a[i][i+1]):\n";
        for (int i = 0; i < n - 1; i++) {
            cin >> a[(2 * n - 1) + i];
        }
    }

    int get(int i, int j) const {
        if (i - j == 1) {
            return a[i - 1];
        } else if (i == j) {
            return a[(n - 1) + i];
        } else if (j - i == 1) {
            return a[(2 * n - 1) + i];
        }
        return 0;
    }

    void display() const {
        cout << "Tri-diagonal matrix (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << "\n";
        }
    }
};

// ========== Lower Triangular Matrix ==========
class LowerTriangularMatrix {
    int n;
    vector<int> a; // size = n(n+1)/2

    int index(int i, int j) const {
        return i * (i + 1) / 2 + j;
    }

public:
    LowerTriangularMatrix(int n) : n(n), a(n * (n + 1) / 2, 0) {}

    void read() {
        cout << "Enter elements of lower triangular matrix (row-wise):\n";
        for (int i = 0; i < n; i++) {
            cout << "Row " << i << " (0 to " << i << "): ";
            for (int j = 0; j <= i; j++) {
                cin >> a[index(i, j)];
            }
        }
    }

    int get(int i, int j) const {
        if (i >= j) return a[index(i, j)];
        return 0;
    }

    void display() const {
        cout << "Lower triangular matrix (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << "\n";
        }
    }
};

// ========== Upper Triangular Matrix ==========
class UpperTriangularMatrix {
    int n;
    vector<int> a; // size = n(n+1)/2

    int index(int i, int j) const {
        return i * n - (i * (i - 1)) / 2 + (j - i);
    }

public:
    UpperTriangularMatrix(int n) : n(n), a(n * (n + 1) / 2, 0) {}

    void read() {
        cout << "Enter elements of upper triangular matrix (row-wise):\n";
        for (int i = 0; i < n; i++) {
            cout << "Row " << i << " (" << i << " to " << n - 1 << "): ";
            for (int j = i; j < n; j++) {
                cin >> a[index(i, j)];
            }
        }
    }

    int get(int i, int j) const {
        if (i <= j) return a[index(i, j)];
        return 0;
    }

    void display() const {
        cout << "Upper triangular matrix (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << "\n";
        }
    }
};

// ========== Symmetric Matrix (store lower triangle) ==========
class SymmetricMatrix {
    int n;
    vector<int> a; // size = n(n+1)/2

    int indexLower(int i, int j) const {
        return i * (i + 1) / 2 + j;
    }

public:
    SymmetricMatrix(int n) : n(n), a(n * (n + 1) / 2, 0) {}

    void read() {
        cout << "Enter elements of symmetric matrix (lower triangle including diagonal):\n";
        for (int i = 0; i < n; i++) {
            cout << "Row " << i << " (0 to " << i << "): ";
            for (int j = 0; j <= i; j++) {
                cin >> a[indexLower(i, j)];
            }
        }
    }

    int get(int i, int j) const {
        if (i >= j) return a[indexLower(i, j)];
        return a[indexLower(j, i)];
    }

    void display() const {
        cout << "Symmetric matrix (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << "\n";
        }
    }
};

// ========== Main Menu ==========
int main() {
    int choice;
    while (true) {
        cout << "\nSPACE EFFICIENT MATRIX STORAGE MENU\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) break;

        int n;
        cout << "Enter order n of the matrix (n x n): ";
        cin >> n;

        if (choice == 1) {
            DiagonalMatrix dm(n);
            dm.read();
            dm.display();
        } else if (choice == 2) {
            TriDiagonalMatrix tm(n);
            tm.read();
            tm.display();
        } else if (choice == 3) {
            LowerTriangularMatrix lm(n);
            lm.read();
            lm.display();
        } else if (choice == 4) {
            UpperTriangularMatrix um(n);
            um.read();
            um.display();
        } else if (choice == 5) {
            SymmetricMatrix sm(n);
            sm.read();
            sm.display();
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
