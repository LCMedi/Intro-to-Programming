#include <iostream>
#include <random>
using namespace std;

int main() {

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribFloat(-1.0, 1.0);
    int pts = 0; //number of pts inside the circle
    int samples; //number of random samples to generate

    cout << "Enter the number of Monte-Carlo samples: ";
    cin >> samples;

    for(int i = 0; i < samples; i++) {
        double x = distribFloat(gen);
        double y = distribFloat(gen);
        double distance_sqrd = x*x + y*y;

        if (distance_sqrd <= 1) {
            pts++;
        }

    }

    double estimated_pi = 4.0 * pts / samples;

    cout << "Estimated value of pi = " << estimated_pi << endl;

    return 0;
}