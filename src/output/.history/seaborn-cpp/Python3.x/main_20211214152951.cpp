#include"seaborn.h"
#include <matplot/matplot.h>

int main() {
    using namespace matplotlib;
    using namespace seaborn;

 


    std::vector<std::vector<double>> data_;

    heatmap(data)->normalization(matrix::color_normalization::columns);

    title("");
    auto ax = gca();
    ax->x_axis().ticklabels(
        {""});
    ax->y_axis().ticklabels(
        {""});
    xlabel(ax, "");
    ylabel(ax, "");
    float w = ax->width();
    ax->width(w * 0.85f);
    ax->x_origin(ax->x_origin() + w * 0.1f);

    matplotlib.animation(fig = fig, func = my_func, frames = 200, interval = 50, blit = False)


    show();
    return 0;
}


