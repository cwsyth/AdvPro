#include <iostream>
#include <time.h>
#include <iomanip>

void f(int i) {
    int x = i * i + i;
}

int main() {
    struct timespec start, end;
    
    // start time
    clock_gettime(CLOCK_REALTIME, &start);

    // loop to measure
    for (int i = 1; i <= 1000; ++i) {
        f(i);
    }

    // end time
    clock_gettime(CLOCK_REALTIME, &end);

    // difference start & end time
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    std::cout << std::fixed << "time: " << elapsed_time << " seconds";

    return 0;
}
