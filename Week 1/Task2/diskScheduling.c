// #include <stdio.h>
// #include <stdlib.h>
// void fcfs(int a[], int n, int head)
// {
//     int i, total = 0;
//     for(i = 0; i < n; i++) {
//         total += abs(head - a[i]);
//         head = a[i];
//     }
//     printf("FCFS movement = %d\n", total);
// }

// void scan(int a[], int n, int head, int max)
// {
//     int i, j, t, total = 0, cur = head;

//     for(i = 0; i < n; i++)
//         for(j = i+1; j < n; j++)
//             if(a[i] > a[j]) {
//                 t = a[i]; a[i] = a[j]; a[j] = t;
//             }

//     i = 0;
//     while(i < n && a[i] <= head) i++;

//     for(j = i-1; j >= 0; j--) {
//         total += abs(cur - a[j]);
//         cur = a[j];
//     }

//     total += cur;       // Move to cylinder 0
//     cur = 0;

//     for(j = i; j < n; j++) {
//         total += abs(cur - a[j]);
//         cur = a[j];
//     }

//     printf("SCAN movement = %d\n", total);
// }

// void cscan(int a[], int n, int head, int max)
// {
//     int i, j, t, total = 0, cur = head;

//     for(i = 0; i < n; i++)
//         for(j = i+1; j < n; j++)
//             if(a[i] > a[j]) {
//                 t = a[i]; a[i] = a[j]; a[j] = t;
//             }

//     i = 0;
//     while(i < n && a[i] <= head) i++;

//     for(j = i-1; j >= 0; j--) {
//         total += abs(cur - a[j]);
//         cur = a[j];
//     }

//     total += cur;       // Move to cylinder 0
//     cur = 0;

//     if(i < n) {
//         total += max;   // Jump from 0 to last cylinder
//         cur = max;

//         for(j = n-1; j >= i; j--) {
//             total += abs(cur - a[j]);
//             cur = a[j];
//         }
//     }

//     printf("C-SCAN movement = %d\n", total);
// }

// int main()
// {
//     int a[100], b[100], n, head, size, i;

//     printf("Enter number of requests: ");
//     scanf("%d", &n);

//     printf("Enter request queue: ");
//     for(i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//         b[i] = a[i];
//     }

//     printf("Enter initial head position: ");
//     scanf("%d", &head);

//     printf("Enter disk size: ");
//     scanf("%d", &size);

//     if(n <= 0 || n > 100 || size <= 0 ||
//        head < 0 || head >= size) {
//         printf("Invalid input");
//         return 0;
//     }

//     for(i = 0; i < n; i++)
//         if(a[i] < 0 || a[i] >= size) {
//             printf("Invalid cylinder");
//             return 0;
//         }

//     fcfs(a, n, head);
//     scan(a, n, head, size-1);
//     cscan(b, n, head, size-1);

//     return 0;
// }



#include <stdio.h>

void fcfs(int a[], int head, int n) {
    int total = 0;
    for (int i=0; i<n; i++) {
        total += abs(head - a[i]);
        head = a[i];
    }

    printf("FCFS Movement : %d", total);
}

void scan(int a[], int head, int n, int SIZE) {
    int total = 0;
    int i = 0;
    int curr = head;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            t = a[i];
            a[i] = b[j];
            a[j] = t;
        }
    }

    while (i < n && a[i] <= head) {
        i++;
    }
    // found our break point i-1 left | i --> right
    for (int j = i-1; j>=0; j--) {
        total += abs(curr - a[j]);
        curr = a[j];
    }

    total += curr;
    curr = 0;

    for (int j=i; j<n; j++) {
        total += abs(curr - a[j]);
        curr = a[j];
    }
    printf("Scan Movement : %d", total);
}

void cScan(int b[], int head, int n, int SIZE) {
    int MAX = SIZE;
    int total = 0;
    int curr = head;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            t = b[i];
            b[i] = b[j];
            b[j] = t;
        }
    }

    while (i < n && b[i] <= head) {
        i++;
    }

    for (int j = i-1; j>=0; j--) {
        total += abs(curr - b[j]);
        curr = b[j];
    }

    total += curr;
    curr = 0;
    if (i < n) {
        total += MAX;
        curr = MAX;
        for (int j = n-1; j>=i; j--) {
            total += abs(curr - b[j]);
            curr = b[j];
        }
    }

    printf("C Scan Movement : %d", total);
}

int main() {
    int a[100], b[100], head, n, SIZE;
    printf("Enter value of requests : ");
    scanf("%d", &n);

    printf("Taking values in queue")
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    printf("Enter value of head : ");
    scanf("%d", &head);

    printf("Enter valid Size value : ");
    scanf("%d", &SIZE);

    fcfs(a, head, n);
    scan(a, head, n, SIZE);
    cScan(b, head, n, SIZE - 1);
}