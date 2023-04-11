#include <stdio.h>
#include <stdlib.h>

// print_matrix 함수: 2차원 배열로 구성된 행렬을 출력.
void print_matrix(int **matrix, int row, int column) { // 3개의 인자(2차원 정수 배열을 가리키는 이중 포인터, 행의 개수, 열의 개수)를 받음.
    printf("\nMatrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// addition_matrix 함수: 두 개의 행렬을 더하여 새로운 행렬을 만듦.
void addition_matrix(int **a, int **b, int **result, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result[i][j] = a[i][j] + b[i][j]; // 각 행과 열의 항목을 더한 값을 새로운 행렬의 위치에 저장.
        }
    }
}

// subtraction_matrix 함수: 두 개의 행렬을 빼서 새로운 행렬을 만듦.
void subtraction_matrix(int **a, int **b, int **result, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result[i][j] = a[i][j] - b[i][j]; // 각 행과 열의 항목을 빼서 값을 새로운 행렬의 해당 위치에 저장.
        }
    }
}

// transpose_matrix 함수: 주어진 행렬의 전치 행렬을 만듦.
void transpose_matrix(int **matrix, int **result, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result[j][i] = matrix[i][j]; // 원래 행렬의 요소를 전치 행렬의 위치에 저장.
        }
    }
}

// multiply_matrix 함수: 두 개의 행렬을 곱해서 새로운 행렬을 만듦(첫 번째 행렬의 열의 수와 두 번째 행렬의 행의 수가 같아야 함.).
void multiply_matrix(int **a, int **b, int **result, int row_a, int column_a, int column_b) {
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < column_b; j++) {
            result[i][j] = 0;
            for (int k = 0; k < column_a; k++) {
                result[i][j] += a[i][k] * b[k][j]; // 첫 번째 행렬의 각 행과 두 번째 행렬의 각 열을 곱한 값을 새로운 행렬에 해당하는 위치에 더하여 저장.
            }
        }
    }
}

// free_matrix 함수: 동적을 할당된 메모리를 해제.
void free_matrix(int **matrix, int row) {
    for (int i = 0; i < row; i++) {
        free(matrix[i]); // 매개변수로 받은 행렬의 각 행에 free 함수를 호출.
    }
    free(matrix); // 행렬 전체를 해제.
}

// main 함수
int main() {
    printf("[----- [이은총]  [2022041043] -----]\n");
    int row_a, column_a, row_b, column_b;

    // 사용자로부터 행렬 A의 행과 열을 입력 받음.
    printf("Enter row and column of matrix A: ");
    scanf("%d %d", &row_a, &column_a); 

    // 사용자로부터 행렬 B의 행과 열을 입력 받음.
    printf("Enter row and column of matrix B: ");
    scanf("%d %d", &row_b, &column_b); 

    // 행렬의 곱을 위해 행렬 A의 열의 수와 행렬 B의 행의 수가 같은지 확인.
    if (column_a != row_b) {
        printf("Invalid dimensions for multiplication!\n"); // 다를 경우 문자열 출력 및 프로그램 종료.
        return 0;
    }

    // malloc 함수를 사용하여 각각의 행렬에 동적 할당.
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

    // 사용자로부터 행렬 A, B의 값을 각각 입력 받음.
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

    // print_matrix 함수를 호출하여 사용자로부터 입력 받은 행렬 A, B의 값 출력.
    print_matrix(matrix_a, row_a, column_a);
    print_matrix(matrix_b, row_b, column_b);

    // addition_matrix 함수를 호출하여 결과 출력.
    addition_matrix(matrix_a, matrix_b, result, row_a, column_a);
    printf("\nAddition of matrices A and B:\n");
    print_matrix(result, row_a, column_a);

    // subtraction_matrix 함수를 호출하여 결과 출력.
    subtraction_matrix(matrix_a, matrix_b, result, row_a, column_a);
    printf("\nSubtraction of matrices A and B:\n");
    print_matrix(result, row_a, column_a);

    // malloc 함수를 사용한 동적 할당 및 transpose_matrix 함수를 호출하여 결과 출력.
    int **transpose = (int **) malloc(column_a * sizeof(int *));
    for (int i = 0; i < column_a; i++) {
        transpose[i] = (int *) malloc(row_a * sizeof(int));
    }
    transpose_matrix(matrix_a, transpose, row_a, column_a);
    printf("\nTranspose of matrix A:\n");
    print_matrix(transpose, column_a, row_a);

    // multiply_matrix 함수를 호출하여 결과 출력.
    multiply_matrix(matrix_a, matrix_b, result, row_a, column_a, column_b);
    printf("\nMultiplication of matrices A and B:\n");
    print_matrix(result, row_a, column_b);

    // free_matrix 함수를 호출하여 동적으로 할당된 메모리를 해제.
    free_matrix(matrix_a, row_a);
    free_matrix(matrix_b, row_b);
    free_matrix(result, row_a);
    free_matrix(transpose, column_a);

    return 0;
}