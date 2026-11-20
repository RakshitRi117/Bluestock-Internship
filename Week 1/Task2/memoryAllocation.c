
// #include <stdio.h>

// void fit(int b[], int m, int p[], int n, int type)
// {
//     int temp[20], i, j, best;

//     for(i = 0; i < m; i++)
//         temp[i] = b[i];

//     for(i = 0; i < n; i++) {
//         best = -1;

//         for(j = 0; j < m; j++) {
//             if(temp[j] >= p[i]) {
//                 if(type == 1) {
//                     best = j;
//                     break;
//                 }

//                 if(best == -1 ||
//                   (type == 2 && temp[j] < temp[best]) ||
//                   (type == 3 && temp[j] > temp[best]))
//                     best = j;
//             }
//         }

//         if(best != -1) {
//             printf("P%d -> Block %d\n", i+1, best+1);
//             temp[best] -= p[i];
//         } else {
//             printf("P%d -> Not allocated\n", i+1);
//         }
//     }
// }

// int main()
// {
//     int b[20], p[20], m, n, i;

//     printf("Enter number of blocks: ");
//     scanf("%d", &m);

//     printf("Enter block sizes: ");
//     for(i = 0; i < m; i++)
//         scanf("%d", &b[i]);

//     printf("Enter number of processes: ");
//     scanf("%d", &n);

//     printf("Enter process sizes: ");
//     for(i = 0; i < n; i++)
//         scanf("%d", &p[i]);

//     printf("\nFirst Fit:\n");
//     fit(b, m, p, n, 1);

//     printf("\nBest Fit:\n");
//     fit(b, m, p, n, 2);

//     printf("\nWorst Fit:\n");
//     fit(b, m, p, n, 3);

//     return 0;
// }

#include <stdio.h>

void fit(int block[], int process[], int m, int p, int type) {
    int temp[20];
    for (int i=0; i<m; i++) {
        temp[i] = block[i];
    }

    for (int i=0; i<p; i++) {
        int best = -1;
        for (int j=0; j<m; j++) {
            if (temp[j] >= process[i]) {
                if (type == 1) {
                    best = j;
                    break;
                }

                if (best == -1 || type == 2 && temp[best] > temp[i] || type == 3 && temp[j] > temp[best]) {
                    best = j;
                }
            }
        }
        if (best != -1) {
            printf("process %d --> block %d ", i + 1, best + 1);
            temp[best] -= process[i];
        } else {
            printf("Cannot be allocated");
        }
    }
}



int main() {
    int block[20], process[20], m, p, type;
    printf("Enter number of blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes: ");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes: ");
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);

    printf("First Fit \n");
    fit(block, process, m, p, 1); // type 1
    fit(block, process, m, p, 2);
    fit(block, process, m, p, 3);
    return 0;
}