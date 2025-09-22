#include <stdio.h>
#include <stdlib.h>

/*
* Base speed: 2.42 GHz
* Sockets: 1
* Cores: 4
* Logical processors: 8
* L1 cache: 320 kB
* L2 cache: 5.0 MB
* L3 cache: 8.0 MBs
*/

void ver_ijk(double* A, double* B, double* C, int n); // ver 1
void ver_jik(double* A, double* B, double* C, int n); // 2
void ver_ikj(double* A, double* B, double* C, int n); // 3
void ver_kij(double* A, double* B, double* C, int n); // 4
void ver_kji(double* A, double* B, double* C, int n); // 5
void ver_jki(double* A, double* B, double* C, int n); // 6

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage: ./project.exe <version> <matrix_size>\n");
        printf("version: 1 for ver_ijk, 2 for ver_jik, 3 for ver_ikj, 4 for ver_kij, 5 for ver_kji, 6 for ver_jki\n");
        printf("matrix_size: integer representing size of nxn matrix\n");
        return -1;
    }

    int ver = atoi(argv[1]);
    int n = atoi(argv[2]);

    double* A = (double*)malloc(n * n * sizeof(double));
    double* B = (double*)malloc(n * n * sizeof(double));
    double* C = (double*)malloc(n * n * sizeof(double));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    switch (ver) {
        case 1: 
            ver_ijk(A, B, C, n);
            break;
        case 2:
            ver_jik(A, B, C, n);
            break;
        case 3:
            ver_ikj(A, B, C, n);
            break;
        case 4:
            ver_kij(A, B, C, n);
            break;
        case 5:
            ver_kji(A, B, C, n);
            break;
        case 6:
            ver_jki(A, B, C, n);
            break;
        default:
            printf("Invalid version number!\n");
            free(A); free(B); free(C); 
            return -1;
    }

    free(A); free(B); free(C);
    return 0;

}

void ver_ijk(double* A, double* B, double* C, int n)
{
    int i, j, k;
    double sum;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            sum = 0.0;
            for (k = 0; k < n; k++)
                sum += A[i * n + k] * B[k * n + j];
            C[i * n + j] += sum;
        }
}

void ver_jik(double* A, double* B, double* C, int n)
{
    int i, j, k;
    double sum;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++) {
            sum = 0.0;
            for (k = 0; k < n; k++)
                sum += A[i * n + k] * B[k * n + j];
            C[i * n + j] += sum;
        }
}

void ver_ikj(double* A, double* B, double* C, int n)
{
    int i, j, k;
    double temp;
    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++) {
            temp = A[i * n + k];
            for (j = 0; j < n; j++)
                C[i * n + j] += temp * B[k * n + j];
        }
}

void ver_kij(double* A, double* B, double* C, int n)
{
    int i, j, k;
    double temp;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++) {
            temp = A[i * n + k];
            for (j = 0; j < n; j++)
                C[i * n + j] += temp * B[k * n + j];
        }
}

void ver_kji(double* A, double* B, double* C, int n)
{
    int i, j, k;
    double temp;
    for (k = 0; k < n; k++)
        for (j = 0; j < n; j++) {
            temp = B[k * n + j];
            for (i = 0; i < n; i++)
                C[i * n + j] += A[i * n + k] * temp;
        }
}
void ver_jki(double* A, double* B, double* C, int n)
{
    int i, j, k;
    double temp;
    for (j = 0; j < n; j++)
        for (k = 0; k < n; k++) {
            temp = B[k * n + j];
            for (i = 0; i < n; i++)
                C[i * n + j] += A[i * n + k] * temp;
        }
}

