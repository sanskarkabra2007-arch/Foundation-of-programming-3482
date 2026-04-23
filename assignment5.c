#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void inputMatrix(int mat[MAX][MAX], int r, int c);
void displayMatrix(int mat[MAX][MAX], int r, int c);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r, int c);
void findSaddlePoint(int mat[MAX][MAX], int n);
float determinant(float mat[MAX][MAX], int n);
void inverseMatrix(float mat[MAX][MAX], int n);
int isMagicSquare(int mat[MAX][MAX], int n);
int main() {
    int choice, r, c, n;
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    float matf[MAX][MAX];
    while (1) {
        printf("\n--- Matrix Operations ---\n");
        printf("1. Addition of two matrices\n");
        printf("2. Saddle point of a matrix\n");
        printf("3. Inverse of a matrix (3x3)\n");
        printf("4. Magic square check\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter rows and columns: ");
                scanf("%d %d", &r, &c);
                printf("Enter Matrix 1:\n");
                inputMatrix(mat1, r, c);
                printf("Enter Matrix 2:\n");
                inputMatrix(mat2, r, c);
                addMatrices(mat1, mat2, res, r, c);
                printf("Resultant Addition:\n");
                displayMatrix(res, r, c);
                break;
            case 2:
                printf("Enter order of square matrix (n): ");
                scanf("%d", &n);
                printf("Enter Matrix:\n");
                inputMatrix(mat1, n, n);
                findSaddlePoint(mat1, n);
                break;
            case 3:
                printf("Enter order of square matrix (3x3 recommended): ");
                scanf("%d", &n);
                printf("Enter Matrix elements:\n");
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        scanf("%f", &matf[i][j]);
                inverseMatrix(matf, n);
                break;
            case 4:
                printf("Enter order of square matrix: ");
                scanf("%d", &n);
                printf("Enter Matrix:\n");
                inputMatrix(mat1, n, n);
                if (isMagicSquare(mat1, n))
                    printf("It is a Magic Square.\n");
                else
                    printf("It is not a Magic Square.\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = mat1[i][j] + mat2[i][j];
}
void findSaddlePoint(int mat[MAX][MAX], int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        int min_row = mat[i][0], col_idx = 0;
        for (int j = 1; j < n; j++) {
            if (mat[i][j] < min_row) {
                min_row = mat[i][j];
                col_idx = j;
            }
        }
        int is_saddle = 1;
        for (int k = 0; k < n; k++) {
            if (mat[k][col_idx] > min_row) {
                is_saddle = 0;
                break;
            }
        }
        if (is_saddle) {
            printf("Saddle point: %d at (%d, %d)\n", min_row, i, col_idx);
            found = 1;
        }
    }
    if (!found) printf("No saddle point exists.\n");
}
float determinant(float mat[MAX][MAX], int n) {
    float det = 0;
    if (n == 2) return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    float submat[MAX][MAX];
    for (int i = 0; i < n; i++) {
        int subi = 0;
        for (int j = 1; j < n; j++) {
            int subj = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                submat[subi][subj] = mat[j][k];
                subj++;
            }
            subi++;
        }
        det += (i % 2 == 0 ? 1 : -1) * mat[0][i] * determinant(submat, n - 1);
    }
    return det;
}
void inverseMatrix(float mat[MAX][MAX], int n) {
    float det = determinant(mat, n);
    if (det == 0) {
        printf("Inverse doesn't exist (Determinant is 0).\n");
        return;
    }
    float adj[MAX][MAX], submat[MAX][MAX], inv[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subi = 0;
            for (int r = 0; r < n; r++) {
                if (r == i) continue;
                int subj = 0;
                for (int c = 0; c < n; c++) {
                    if (c == j) continue;
                    submat[subi][subj] = mat[r][c];
                    subj++;
                }
                subi++;
            }
            float cofactor = ((i + j) % 2 == 0 ? 1 : -1) * determinant(submat, n - 1);
            adj[j][i] = cofactor;
        }
    }
    printf("Inverse Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%.2f\t", adj[i][j] / det);
        printf("\n");
    }
}
int isMagicSquare(int mat[MAX][MAX], int n) {
    int sumd1 = 0, sumd2 = 0;
    for (int i = 0; i < n; i++) {
        sumd1 += mat[i][i];
        sumd2 += mat[i][n - 1 - i];
    }
    if (sumd1 != sumd2) return 0;
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += mat[i][j];
            colSum += mat[j][i];
        }
        if (rowSum != sumd1 || colSum != sumd1) return 0;
    }
    return 1;
}
void inputMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}
void displayMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
