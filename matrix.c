#include <stdio.h>
#include <stdlib.h>

// print_matrix �Լ�: 2���� �迭�� ������ ����� ���.
void print_matrix(int **matrix, int row, int column) { // 3���� ����(2���� ���� �迭�� ����Ű�� ���� ������, ���� ����, ���� ����)�� ����.
    printf("\nMatrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// addition_matrix �Լ�: �� ���� ����� ���Ͽ� ���ο� ����� ����.
void addition_matrix(int **a, int **b, int **result, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result[i][j] = a[i][j] + b[i][j]; // �� ��� ���� �׸��� ���� ���� ���ο� ����� ��ġ�� ����.
        }
    }
}

// subtraction_matrix �Լ�: �� ���� ����� ���� ���ο� ����� ����.
void subtraction_matrix(int **a, int **b, int **result, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result[i][j] = a[i][j] - b[i][j]; // �� ��� ���� �׸��� ���� ���� ���ο� ����� �ش� ��ġ�� ����.
        }
    }
}

// transpose_matrix �Լ�: �־��� ����� ��ġ ����� ����.
void transpose_matrix(int **matrix, int **result, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result[j][i] = matrix[i][j]; // ���� ����� ��Ҹ� ��ġ ����� ��ġ�� ����.
        }
    }
}

// multiply_matrix �Լ�: �� ���� ����� ���ؼ� ���ο� ����� ����(ù ��° ����� ���� ���� �� ��° ����� ���� ���� ���ƾ� ��.).
void multiply_matrix(int **a, int **b, int **result, int row_a, int column_a, int column_b) {
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < column_b; j++) {
            result[i][j] = 0;
            for (int k = 0; k < column_a; k++) {
                result[i][j] += a[i][k] * b[k][j]; // ù ��° ����� �� ��� �� ��° ����� �� ���� ���� ���� ���ο� ��Ŀ� �ش��ϴ� ��ġ�� ���Ͽ� ����.
            }
        }
    }
}

// free_matrix �Լ�: ������ �Ҵ�� �޸𸮸� ����.
void free_matrix(int **matrix, int row) {
    for (int i = 0; i < row; i++) {
        free(matrix[i]); // �Ű������� ���� ����� �� �࿡ free �Լ��� ȣ��.
    }
    free(matrix); // ��� ��ü�� ����.
}

// main �Լ�
int main() {
    printf("[----- [������]  [2022041043] -----]\n");
    int row_a, column_a, row_b, column_b;

    // ����ڷκ��� ��� A�� ��� ���� �Է� ����.
    printf("Enter row and column of matrix A: ");
    scanf("%d %d", &row_a, &column_a); 

    // ����ڷκ��� ��� B�� ��� ���� �Է� ����.
    printf("Enter row and column of matrix B: ");
    scanf("%d %d", &row_b, &column_b); 

    // ����� ���� ���� ��� A�� ���� ���� ��� B�� ���� ���� ������ Ȯ��.
    if (column_a != row_b) {
        printf("Invalid dimensions for multiplication!\n"); // �ٸ� ��� ���ڿ� ��� �� ���α׷� ����.
        return 0;
    }

    // malloc �Լ��� ����Ͽ� ������ ��Ŀ� ���� �Ҵ�.
    int **matrix_a = (int **) malloc(row_a * sizeof(int *));
    for (int i = 0; i < row_a; i++) {
        matrix_a[i] = (int *) malloc(column_a * sizeof(int));
    }

    int **matrix_b = (int **) malloc(row_b * sizeof(int *));
    for (int i = 0; i < row_b; i++) {
        matrix_b[i] = (int *) malloc(column_b * sizeof(int));
    }

    int **result = (int **) malloc(row_a * sizeof(int *));
    for (int i = 0; i < row_a; i++) {
        result[i] = (int *) malloc(column_b * sizeof(int));
    }

    // ����ڷκ��� ��� A, B�� ���� ���� �Է� ����.
    printf("Enter elements of matrix A:\n");
        for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < column_a; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < row_b; i++) {
        for (int j = 0; j < column_b; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    // print_matrix �Լ��� ȣ���Ͽ� ����ڷκ��� �Է� ���� ��� A, B�� �� ���.
    print_matrix(matrix_a, row_a, column_a);
    print_matrix(matrix_b, row_b, column_b);

    // addition_matrix �Լ��� ȣ���Ͽ� ��� ���.
    addition_matrix(matrix_a, matrix_b, result, row_a, column_a);
    printf("\nAddition of matrices A and B:\n");
    print_matrix(result, row_a, column_a);

    // subtraction_matrix �Լ��� ȣ���Ͽ� ��� ���.
    subtraction_matrix(matrix_a, matrix_b, result, row_a, column_a);
    printf("\nSubtraction of matrices A and B:\n");
    print_matrix(result, row_a, column_a);

    // malloc �Լ��� ����� ���� �Ҵ� �� transpose_matrix �Լ��� ȣ���Ͽ� ��� ���.
    int **transpose = (int **) malloc(column_a * sizeof(int *));
    for (int i = 0; i < column_a; i++) {
        transpose[i] = (int *) malloc(row_a * sizeof(int));
    }
    transpose_matrix(matrix_a, transpose, row_a, column_a);
    printf("\nTranspose of matrix A:\n");
    print_matrix(transpose, column_a, row_a);

    // multiply_matrix �Լ��� ȣ���Ͽ� ��� ���.
    multiply_matrix(matrix_a, matrix_b, result, row_a, column_a, column_b);
    printf("\nMultiplication of matrices A and B:\n");
    print_matrix(result, row_a, column_b);

    // free_matrix �Լ��� ȣ���Ͽ� �������� �Ҵ�� �޸𸮸� ����.
    free_matrix(matrix_a, row_a);
    free_matrix(matrix_b, row_b);
    free_matrix(result, row_a);
    free_matrix(transpose, column_a);

    return 0;
}