#include <stdio.h>

void fifo(int reference[], int n, int f)
{
    int frame[20], i, j, pos = 0, hit, faults = 0;

    for(i = 0; i < f; i++) frame[i] = -1;

    for(i = 0; i < n; i++) {
        hit = 0;
        for(j = 0; j < f; j++)
            if(frame[j] == reference[i]) hit = 1;

        if(!hit) {
            frame[pos] = reference[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }

    printf("FIFO faults = %d\n", faults);
}

void lru(int reference[], int n, int f)
{
    int frame[20], last[20], i, j, v, hit, faults = 0;

    for(i = 0; i < f; i++)
        frame[i] = last[i] = -1;

    for(i = 0; i < n; i++) {
        hit = 0;
        for(j = 0; j < f; j++)
            if(frame[j] == reference[i]) {
                hit = 1;
                last[j] = i;
            }
        if(!hit) {
            v = 0;
            for(j = 1; j < f; j++)
                if(last[j] < last[v]) v = j;
            frame[v] = reference[i];
            last[v] = i;
            faults++;
        }
    }

    printf("LRU faults = %d\n", faults);
}

void lfu(int reference[], int n, int f)
{
    int frame[20], freq[20], time[20];
    int i, j, v, hit, faults = 0;

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++)
            if(frame[j] == reference[i]) {
                freq[j]++;
                hit = 1;
                break;
            }

        if(!hit) {
            v = 0;
            for(j = 1; j < f; j++)
                if(freq[j] < freq[v] ||
                  (freq[j] == freq[v] && time[j] < time[v]))
                    v = j;

            frame[v] = reference[i];
            freq[v] = 1;
            time[v] = i;
            faults++;
        }
    }

    printf("LFU faults = %d\n", faults);
}

int main()
{
    int reference[100], n, f, i;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &reference[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    if(f <= 0 || f > 20 || n <= 0 || n > 100) {
        printf("Invalid input");
        return 0;
    }

    fifo(reference, n, f);
    lru(reference, n, f);
    lfu(reference, n, f);

    return 0;
}
