#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int main() {

    int n, t; // n number of steps & t number of trials
    double eu_distance = 0; // Euclidean distance
    double avg_distance; // Averaged euclidean distance
    double theo_distance; // Theoretical distance

    cout << "Enter the number of steps of 2D Random Walk: ";
    cin >> n;
    cout << "Enter the number of trials: ";
    cin >> t;

    // Random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribInt(1,4);

    //  Iterate through t number of trials
    for (int i = 0; i < t; i++) {

        int x = 0, y = 0; // x,y coordinates starting at the origin (0,0)

        // Iterate through n number of steps
        for (int j = 0; j < n; j++) {

            int random_number = distribInt(gen); // Get a random number [1,4]

            switch (random_number) {
            case 1: // Move left
                x--;
                break;
            case 2: // Move right
                x++;
                break;
            case 3: // Move down
                y--;
                break;
            case 4: // Move up
                y++;
                break;
            default:
                break;
            }
        }

        eu_distance += sqrt(x*x + y*y); // Calculate euclidean distance for trial

    }

    avg_distance = eu_distance / t;
    theo_distance = sqrt(n);

    cout << "Expected distance: " << avg_distance << endl;
    cout << "Theoretical distance: " << theo_distance << endl;

    return 0;
}