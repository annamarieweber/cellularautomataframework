#include"Seaborn.h"
#include <matplot/matplot.h>
#include <ctime>
using namespace matplotlib;
using namespace seaborn;
int main() {

    # generate random noise for the heatmap
    double rnd_data = random(normal(0, 1, (500, 100, 100))

    void my_func(int i)
    {
        ax.cla();
        heatmap(rnd_data[i, ...],ax = ax,cbar = True,cbar_ax = cbar_ax,vmin = rnd_data.min(),vmax = rnd_data.max());

    }
    grid_kws = {'width_ratios': (0.9, 0.05), 'wspace': 0.2}
    fig, (ax, cbar_ax) = plt.subplots(1, 2, gridspec_kw = grid_kws, figsize = (12, 8))
    matplotlib.animation(fig = fig, func = my_func, frames = 200, interval = 50, blit = False);

    show();

    return 0;

}


