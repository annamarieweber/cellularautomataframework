#include"seaborn.h"


import numpy as np
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