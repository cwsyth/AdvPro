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
    float x[N], y[N];
    float a = 0.0;

    for(i = 0; i < N; ++i) {
        a += x[i] * y[i];
    }

    return 0;
}