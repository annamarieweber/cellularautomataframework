#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace matplot;

int main() {
    int _rows = 5;
    int _columns = 5;
    int _num_states = 30;

//2d array randomly generated with the rows, number of state and columns predetermined 
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,_num_states);
    std::vector<std::vector<int>> _data(_rows, std::vector<int>(_columns,0));

    for (auto it1 = _data.begin(); it1 != _data.end(); it1++) {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            *it2 = dis(gen); // dereference iterator, set the value
            std::cout << std::setw(4) << *it2;
        }
        std::cout << '\n';
    }

//2d heatmap generation w/legend data and 
    heatmap(_data)->normalization(matrix::color_normalization::rows);

    title("Count of Cause vs. Region");
    auto ax = gca();
    ax->x_axis().ticklabels(
        { 0, 1, 2, 3});
    ax->y_axis().ticklabels(
        {"empty", "tree", "fire", "char"});
    xlabel(ax, "String States");
    ylabel(ax, "Num States");
    float w = ax->width();
    ax->width(w * 0.85f);
    ax->x_origin(ax->x_origin() + w * 0.1f);


    grid_kws = {'width_ratios': (0.9, 0.05), 'wspace': 0.2};
    fig, (ax, cbar_ax) = subplots(1, 2, gridspec_kw = grid_kws, figsize = (12, 8));
    FuncAnimation(fig = fig, func = my_func, frames = 200, interval = 50, blit = False);

    show();
    return 0;
}
