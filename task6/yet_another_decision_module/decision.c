#include "decision.h"
#include "data_stat.h"
#include <math.h>

int make_decision(double *data, int n)
{
    int decision = 1;

    double m = mean(data, n);
    double sigma = sqrt(variance(data, n));
    double max_value = max(data, n);
    double min_value = min(data, n);

    decision = decision && (max_value <= m + 3*sigma) &&
                           (min_value >= m - 3*sigma) &&
                           (m >= GOLDEN_RATIO);

    return decision;
}