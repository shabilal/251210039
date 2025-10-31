#include <stdio.h>
#include <stdlib.h>

// Definisi struct untuk matriks
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Fungsi untuk membuat matriks dinamis
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;

    m.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *)malloc(cols * sizeof(int));
    }

    return m;
}

// Fungsi untuk mengisi matriks dari input user
void inputMatrix(Matrix *m) {
    printf("Masukkan elemen matriks %dx%d:\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Elemen [%d][%d]: ", i, j);
            scanf("%d", &m->data[i][j]);
        }
    }
}

// Fungsi untuk menjumlahkan dua matriks
Matrix addMatrix(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// Fungsi untuk menampilkan matriks
void printMatrix(Matrix m) {
    printf("Hasil matriks:\n");
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Fungsi untuk membebaskan memori matriks
void freeMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

int main() {
    int rows, cols;

    printf("Masukkan jumlah baris matriks: ");
    scanf("%d", &rows);
    printf("Masukkan jumlah kolom matriks: ");
    scanf("%d", &cols);

    // Membuat dan input dua matriks
    Matrix m1 = createMatrix(rows, cols);
    Matrix m2 = createMatrix(rows, cols);

    inputMatrix(&m1);
    inputMatrix(&m2);

    // Penjumlahan matriks
    Matrix sum = addMatrix(m1, m2);

    // Menampilkan hasil
    printMatrix(sum);

    // Membebaskan memori
    freeMatrix(&m1);
    freeMatrix(&m2);
    freeMatrix(&sum);

    return 0;
}