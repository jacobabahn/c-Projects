//  Name: Jacob Bahn
//  Assignment number: 5
//  Assignment: Maze Construction with th Disjoint Set Data Structure
//  File name: bahn.cpp
//  Date last modified: November 11, distdist
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include <memory>
#include <GL/sgl.hpp>
#include <numeric>
#include <iostream>

class DisjointSet {
private:
    std::vector<int> set;
public:
    DisjointSet(int numElements) {
        set = std::vector<int>(numElements, 1);
        Split();
    };

    int Find(int i) {
        if (set[i] == i) {
            return i;
        }
        else {
            return Find(set[i]);
        }
    }

    void Union(int i, int j) {
        i = Find(i);
        j = Find(j);
        set[i] = j;

    }

    void Split() {
        std::iota(set.begin(), set.end(), 0);
    }

    int Cardinality() {
        int count = 0;
        for (int i = 0; i < set.size(); i++) {
            if (i == set[i]) {
                count += 1;
            }
        }
        //std::cout << count << "\n";
        return count;
    }
};

class GridWindow : public sgl::Window {
public:
    int dist = 20;
    // Constructor makes a width x height window
    GridWindow(double width, double height) :
        sgl::Window("Grid", 0, width, 0, height) {}

    // The paint method simply draws a grid
    void paint() override {
        sgl::set_color(sgl::BLACK);
        createMaze();
    }

    // createMaze draws the maze with the entrance and exit 
    void createMaze() {
        for (int x = 30; x <= get_max_x() - 30; x += dist) {
            sgl::draw_line(x, 30, x, get_max_y() - 30);
        }
        for (int y = 30; y <= get_max_y() - 30; y += dist) {
            sgl::draw_line(30, y, get_max_x() - 30, y);
        }
        sgl::set_color(sgl::WHITE);
        sgl::draw_line(30.0, 30.0, 30.0, 50.0);
        sgl::draw_line(dist * 40.0 + 30.0, dist * 24.0 + 30.0, dist * 40.0 + 30.0, dist * 24.0 + 30.0 + dist);
        configureMaze();
    }

    // configureMaze generates a random position and direction and then unions equivalence classes that are next to each other
    void configureMaze() {
        DisjointSet set(1000);

        while (set.Cardinality() > 1) {
            int x = (rand() % 39) + 1;
            int y = (rand() % 24) + 1;
            double x0, y0, x1, y1, in1, in2, rx0, rx1, rx2, rx3;
            x0 = (dist * x) + 30;
            y0 = (dist * y) + 30;

            if (setDirection() == 0) {
                rx0 = x0 - dist;
                rx1 = y0;
                rx2 = x0 - dist;
                rx3 = y0 - dist;
                x1 = x0 - dist;
                y1 = y0;
            }
            else if (setDirection() == 1) {
                rx0 = x0;
                rx1 = y0;
                rx2 = x0 - dist;
                rx3 = y0;
                x1 = x0;
                y1 = y0 + dist;
            }
            else if (setDirection() == 2) {
                rx0 = x0;
                rx1 = y0;
                rx2 = x0;
                rx3 = y0 - dist;
                x1 = x0 + dist;
                y1 = y0;
            }
            else {
                rx0 = x0;
                rx1 = y0 - dist;
                rx2 = x0 - dist;
                rx3 = y0 - dist;
                x1 = x0;
                y1 = y0 - dist;
            }
            in1 = setPoints(rx0, rx1);
            in2 = setPoints(rx2, rx3);

            if (set.Find(in1) != set.Find(in2)) {
                set.Union(in1, in2);
                sgl::draw_line(x0, y0, x1, y1);
            }
        }
    }
    // generates the direction for which the wall will be replaced.
    int setDirection() {
        return rand() % 4;
    }

    // retrieves the index
    int setPoints(int x, int y) {
        return (((y - 30) / dist)) * 40 + (((x - 30) / dist));
    }
};

int main() {
    // Make a window and start the application
    sgl::run<GridWindow>(860.0, 560.0);
}