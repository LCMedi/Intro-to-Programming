#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    double u1,u2,u3;
    double v1,v2,v3;

    cout << "Enter coordinates for vector u: ";
    cin >> u1 >> u2 >> u3;

    cout << "You entered u = [" << u1 << ", " << u2 << ", " << u3 << "]" << endl;

    cout << "Enter coordinates for vector v: ";
    cin >> v1 >> v2 >> v3;

    cout << "You entered v = [" << v1 << ", " << v2 << ", " << v3 << "]" << endl;

    double sum_u = pow(u1, 2) + pow(u2, 2) + pow(u3, 2);
    double sum_v = pow(v1, 2) + pow(v2, 2) + pow(v3, 2);

    double length_u = sqrt(sum_u);
    double length_v = sqrt(sum_v);

    double dot_product = u1*v1 + u2*v2 + u3*v3;
    
    double angle = acos((dot_product/(length_u*length_v))) * 180/M_PI;

    cout << "Length of u: ||u|| = " << length_u << endl;
    cout << "Length of v: ||v|| = " << length_v << endl;
    cout << "The dot product of u and v is uv = " << dot_product << endl;
    cout << "The angle of u and v is " << angle << " degrees." << endl;

    return 0;
}
