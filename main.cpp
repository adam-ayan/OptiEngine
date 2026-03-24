#include <iostream>
#include <fstream>
#include <vector>
#include <Polyhedron.h>



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

void findHull(const std::vector<Point>& points, std::vector<Point>& hull) {
    // Placeholder for convex hull algorithm
    // This function should implement the logic to find the convex hull of the points
    // and populate the 'hull' vector with the vertices of the convex polyhedron.
}

// void printPoint(const Point& p){
//     std::cout << "(" << p.x << ", " << p.y << ", " << p.z << ")\n";
// }
// void printPoints(const std::vector<Point>& points) {
//     for(int i=0; i<points.size(); i++) {
//         printPoint(points[i]);
//     }
// }

// void findExtrema(const std::vector<Point>& points, double& max_x, double& max_y, double& max_z, 
//                      double& min_x, double& min_y, double& min_z) {
//     if (points.empty()) return;

//     max_x = min_x = points[0].x;
//     max_y = min_y = points[0].y;
//     max_z = min_z = points[0].z;

//     for(int i=1; i<points.size(); i++) {
//         if(points[i].x > max_x) max_x = points[i].x;
//         if(points[i].y > max_y) max_y = points[i].y;
//         if(points[i].z > max_z) max_z = points[i].z;

//         if(points[i].x < min_x) min_x = points[i].x;
//         if(points[i].y < max_y) min_y = points[i].y;
//         if(points[i].z < min_z) min_z = points[i].z;
//     }

//     return;
// }


int main(){
    std::ifstream myfile;
    myfile.open("input.txt");
    std::vector<Point> points;
    while(myfile.peek() != EOF) {
        Point p;
        myfile >> p.x >> p.y >> p.z;
        points.push_back(p);
    }
    myfile.close();

    // double max_x, max_y, max_z, min_x, min_y, min_z;
    // findExtrema(points, max_x, max_y, max_z, min_x, min_y, min_z);

    if(points.size() < 4){
        std::cout << "Not enough points to form a tetrahedron.\n";
        return 0;
    }
    if(areCoplanar(points[0], points[1], points[2], points[3])){
        std::cout << "Points are coplanar, cannot form a tetrahedron.\n";
        return 0;
    }

    std::vector<Point> convexPolyhedron = {points[0], points[1], points[2], points[3]};
     

    for(int i=4; i<points.size(); i++) {
        
    }


    
    return 0;
} 