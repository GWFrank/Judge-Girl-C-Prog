#include <stdio.h>

int mySign(int n) {
    if (n>0) return 1;
    else if (n<0) return -1;
    else return 0;
}

int main() {
    int k;
    scanf("%d", &k);

    int seg_type=0, seg_len=0;
    int long_seq_len=0, seq_len=0;

    int n;
    while (1) {
        scanf("%d", &n);

        if (seg_type == 0)
            seg_type = -mySign(n);
        
        if (mySign(n)*mySign(seg_type) > 0) {
            seg_len++;
        } else {
            if (seg_len > k) {
                seq_len++;
                if (seg_type>0 && seq_len>=3 && seq_len>long_seq_len)
                    long_seq_len = seq_len;
                if (seg_type > 0)
                    seq_len = 1;
                else
                    seq_len = 0;
            } else if (seg_len == k) {
                if (seq_len == 0) {
                    if (seg_type > 0)
                        seq_len = 1;
                    else
                        seq_len = 0;
                } else {
                    seq_len++;
                    if (seg_type>0 && seq_len>=3 && seq_len>long_seq_len)
                        long_seq_len = seq_len;
                }
            } else {
                seq_len = 0;
            }
            seg_len = 1;
            seg_type = mySign(n);
        }

        if (n == 0)
            break;
        
    }

    printf("%d\n", k*long_seq_len);

    return 0;
}