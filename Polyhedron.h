#pragma once
#include <vector>

struct Point {
    double x, y, z;
};

class Polyhedron {
public:
    Polyhedron(const std::vector<Point>& points);

    // Optionally, add public methods for interacting with the polyhedron
    // e.g., getVertices(), volume(), etc.

private:
    std::vector<Point> vertices;
};

// Geometric utility functions (not class members)
bool areCoplanar(const Point& a, const Point& b, const Point& c, const Point& d);
bool areCoplanar(const std::vector<Point>& points); 