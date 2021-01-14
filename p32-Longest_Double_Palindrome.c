#include <stdio.h>

int isPalindrome(int *seq, int start, int end) {
    int len = end-start+1;
    while (start <= end) {
        if (seq[start] != seq[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return len;
}

int main(){
    int seq[105];
    int seq_size = 0;

    int temp_num;
    while (scanf("%d", &temp_num) != EOF) {
        seq[seq_size] = temp_num;
        seq_size++;
    }

    int long_start=0,  long_len=0;

    for (int i=0; i<seq_size; i++) {
        for (int j=i; j<seq_size; j++) {
            int len = isPalindrome(seq, i, j);
            if (len>0) {
                for (int k=seq_size-1; k>=j+1; k--) {
                    int sec_len = isPalindrome(seq, j+1, k);
                    if (sec_len>0) {
                        if (sec_len+len>=long_len) {
                            long_len = sec_len+len;
                            long_start = i;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<long_len; i++) {
        printf("%d", seq[i+long_start]);
        if (i!=long_len-1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    // printf("\n");

    return 0;
}