#include"seaborn.h"


int main() {
    using namespace matplot;
    import seaborn as sns


    std::vector<std::vector<double>> data = {
        {12, 135, 20, 0, 127}, {0, 1, 0, 0, 1},  {19, 31, 81, 8, 49},
        {9, 18, 42, 2, 85},    {0, 5, 3, 0, 17}, {31, 143, 135, 6, 23},
        {32, 102, 54, 6, 7},   {5, 11, 4, 0, 4}, {16, 41, 13, 3, 22},
        {18, 70, 37, 1, 19}};

    heatmap(data)->normalization(matrix::color_normalization::columns);

    title("Count of Cause vs. Region");
    auto ax = gca();
    ax->x_axis().ticklabels(
        {"MidWest", "NorthEast", "SouthEast", "SouthWest", "West"});
    ax->y_axis().ticklabels(
        {"Attack", "Earthquake", "Energy emergency", "Equipment fault", "Fire",
         "Severe Storm", "Thunder Storm", "Unknown", "Wind", "Winter Storm"});
    xlabel(ax, "Region");
    ylabel(ax, "Cause");
    float w = ax->width();
    ax->width(w * 0.85f);
    ax->x_origin(ax->x_origin() + w * 0.1f);

    show();
    return 0;
}


import matplotlib.pyplot as plt
import seaborn as sns
from matplotlib.animation import FuncAnimation

# generate random noise for the heatmap
rnd_data = np.random.normal(0, 1, (500, 100, 100))

def my_func(i):
    ax.cla()
    sns.heatmap(rnd_data[i, ...],
                ax = ax,
                cbar = True,
                cbar_ax = cbar_ax,
                vmin = rnd_data.min(),
                vmax = rnd_data.max())

grid_kws = {'width_ratios': (0.9, 0.05), 'wspace': 0.2}
fig, (ax, cbar_ax) = plt.subplots(1, 2, gridspec_kw = grid_kws, figsize = (12, 8))
anim = FuncAnimation(fig = fig, func = my_func, frames = 200, interval = 50, blit = False)

plt.show()