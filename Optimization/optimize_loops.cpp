int main() {
    // a)
    int i;
    float x[N], y[N];

    x[0] = 0;
    if(N > 1) {
        x[N-1] = N-1;
    }

    for(i = 1; i < N-1; ++i) {
        x[i] = x[i] + y[i];
    }

    // b)
    int i;
    float a, x[N], y[N];

    if(a == 0.0) {
        for(i = 0; i < N; ++i) {
            x[i] = 0;
        }
    } 
    else {
        for(i = 0; i < N; ++i) {
            y[i] = x[i] * y[i];
        }
    }

    // c)
    int i;
    float a = 0.0f;
    float x[N], y[N];

    // use pointers to improve memory access
    float* px = x;
    float* py = y;

    // loop unrolling for optimization
    for (i = 0; i < N - 3; i += 4) {
        a += px[i] * py[i] +
            px[i + 1] * py[i + 1] +
            px[i + 2] * py[i + 2] +
            px[i + 3] * py[i + 3];
    }

    // handle any remaining elements
    for (; i < N; ++i) {
        a += px[i] * py[i];
    }

    return 0;
}