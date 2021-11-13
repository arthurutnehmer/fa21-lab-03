#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src)
{
    int k,m;
    for (int i = 0; i < n; i += blocksize )
    {
        for ( int j = 0; j < n; j += blocksize ) {
            for ( k = i; (k < i + blocksize) & (k < n) ; k++ ) {
                for ( m = j; (m < j + blocksize) & (m < n); m++ ) {
                    dst[m + k*n] = src[k + m*n];
                }
            }
        }
    }

}
