#include <cmath>
#include <vector>
#include <stdexcept>

struct Point{
    double x;
    double y;
    double z;
};

double dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point cross(const Point&a, const Point&b){
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

bool areCoplanar(const Point& a, const Point& b, const Point& c, const Point& d) {
    Point ab = {b.x - a.x, b.y - a.y, b.z - a.z};
    Point ac = {c.x - a.x, c.y - a.y, c.z - a.z};
    Point ad = {d.x - a.x, d.y - a.y, d.z - a.z};
    return std::abs(dot(cross(ab, ac), ad)) < 1e-9;
}

bool areCoplanar(const std::vector<Point>& points) {
    if (points.size() < 4) return false;
    return areCoplanar(points[0], points[1], points[2], points[3]);
}




std::vector<Point>& makeTetrahedron(std::vector<Point>& points) {
    if (points.size() < 4) {
        throw std::invalid_argument("Not enough points to form a tetrahedron.");
    }

    
    std::vector<Point> tetrahedron;

    // Find 2 farthest pts

    if (areCoplanar(tetrahedron[0], tetrahedron[1], tetrahedron[2], tetrahedron[3])) {
        throw std::invalid_argument("Points are coplanar; cannot form a tetrahedron.");
    }



    return tetrahedron;
}

class Polyhedron{
    public:
        Polyhedron(const std::vector<Point>& points): vertices(points) {            
            if (vertices.size() < 4) {
                throw std::invalid_argument("Not enough points to form a tetrahedron.");
            }
            if (areCoplanar(points[0], points[1], points[2], points[3])) {
                throw std::invalid_argument("Cannot construct Polyhedron: input points do not form a valid tetrahedron.");
            }

            
        }

    private:
        std::vector<Point> vertices;
};

 
