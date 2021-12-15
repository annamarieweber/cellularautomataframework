#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace matplot;

int main() {
    int _rows = 5;
    int _columns = 5;

    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    std::vector<std::vector<int>> _data(_rows, std::vector<int>(_columns,0));

    for (auto it1 = _data.begin(); it1 != _data.end(); it1++) {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            *it2 = dis(gen); // dereference iterator, set the value
            std::cout << std::setw(4) << *it2;
        }
        std::cout << '\n';
    }


    heatmap(_data)->normalization(matrix::color_normalization::rows);

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
