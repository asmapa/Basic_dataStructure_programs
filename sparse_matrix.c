/*Sparse matrix operations
read 2 matrices
convert into tuple form
find transpose of tuple form
add to tuple form matrices*/

#include <stdio.h>

void convert(int a[][100], int m, int n, int b[][3]) {
    int nz = 0, k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                nz++;
                k++;
            }
        }
    }
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = nz;
}

void transpose(int a[][3], int b[][3]) {
    int n = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = n;

    int col_a = a[0][1];
    int q = 1;
    for (int i = 0; i < col_a; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j][1] == i) {
                b[q][0] = a[j][1];
                b[q][1] = a[j][0];
                b[q][2] = a[j][2];
                q++;
            }
        }
    }
}

void sparseAddition(int a[][3], int b[][3], int c[][3]) {
    int r1 = a[0][0];
    int c1 = a[0][1];
    int r2 = b[0][0];
    int c2 = b[0][1];

    if (r1 != r2 || c1 != c2) {
        printf("Addition is not possible due to different dimensions.\n");
    } else {
        c[0][0] = r1;
        c[0][1] = c1;
        int k = 1;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                int sum = 0;
                for (int m = 1; m <= a[0][2]; m++) {
                    if (a[m][0] == i && a[m][1] == j) {
                        sum += a[m][2];
                    }
                }
                for (int n = 1; n <= b[0][2]; n++) {
                    if (b[n][0] == i && b[n][1] == j) {
                        sum += b[n][2];
                    }
                }
                if (sum != 0) {
                    c[k][0] = i;
                    c[k][1] = j;
                    c[k][2] = sum;
                    k++;
                }
            }
        }
        c[0][2] = k - 1; // Set the correct number of non-zero elements
    }
}



int main() {
    int m, n;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &m, &n);

    int matrix1[100][100];
    int tuple1[1000][3];
    int transposed1[1000][3];

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    convert(matrix1, m, n, tuple1);
    transpose(tuple1, transposed1);

    printf("Tuple form of the first matrix:\n");
    for (int i = 0; i <= tuple1[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", tuple1[i][j]);
        }
        printf("\n");
    }

    printf("Transpose of the first matrix in tuple form:\n");
    for (int i = 0; i <= transposed1[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transposed1[i][j]);
        }
        printf("\n");
    }

    int m2, n2;

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &m2, &n2);

    int matrix2[100][100];
    int tuple2[1000][3];
    int transposed2[1000][3];

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    convert(matrix2, m2, n2, tuple2);
    transpose(tuple2, transposed2);

    printf("Tuple form of the second matrix:\n");
    for (int i = 0; i <= tuple2[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", tuple2[i][j]);
        }
        printf("\n");
    }

    printf("Transpose of the second matrix in tuple form:\n");
    for (int i = 0; i <= transposed2[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transposed2[i][j]);
        }
        printf("\n");
    }

    if (m != m2 || n != n2) {
        printf("Matrix addition is not possible due to different dimensions.\n");
    } else {
        int result[1000][3];
        sparseAddition(tuple1, tuple2, result);

        printf("Result of matrix addition in tuple form:\n");
        for (int i = 0; i <= result[0][2]; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

