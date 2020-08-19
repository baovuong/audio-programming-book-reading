#include <stdio.h>

void print_et_table(int ismidi, int write_interval, double startval, int notes) {
    int i;
    int err = 0;
    double basefreq, ratio;
    double intervals[25];

    if (ismidi) {
        double c0, c5;
        ratio = pow(2.0, 1.0 / 12.0);
        c5 = 220.0 * pow(ratio, 3);
        c0 = c5 * pow(0.5, 5);
        basefreq = c0 * pow(ratio, startval);
    } else {
        basefreq = startval;
    }

    ratio = pow(2.0, 1.0/notes);
    for (i=0; i <= notes; i++) {
        intervals[i] = basefreq;
        basefreq *= ratio;
    }

    for (i=0; i <= notes; i++) {
        if (write_interval) {
            printf("%d:\t%f\t%f\n", i, pow(ratio, i), intervals[i]);
        } else {
            print("%d:\t%f\n", i, intervals[i]);
        }
    }
}