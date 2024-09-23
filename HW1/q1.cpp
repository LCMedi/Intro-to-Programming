#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    double weight_lbs, weight_kgs, height_meters, bmi;
    int height_feet, height_inches;
    const double  MIN_BMI = 18.5;
    const double  MAX_BMI = 24.9;

    cout << "Enter your weight (in lbs): ";
    cin >> weight_lbs;

    cout << "Enter your height (ft and inches): " << endl;
    cout << "Feet: ";
    cin >> height_feet;
    cout <<  "Inches: ";
    cin >> height_inches;
    
    weight_kgs = weight_lbs * 0.4536;
    
    height_inches += height_feet * 12;
    height_meters = height_inches * 0.0254;
    double height_sqrd = pow(height_meters,2);

    bmi = weight_kgs/height_sqrd;
    
    double min_weight = (MIN_BMI * height_sqrd)/0.4536;
    double max_weight = (MAX_BMI * height_sqrd)/0.4536;
    
    cout << fixed << setprecision(2);
    cout << "Your height in meters is " << height_meters << " m." << endl;
    cout << "Your weight in Kgs is " << weight_kgs << "Kgs." << endl;

    cout << "Your BMI is " << bmi << "." << endl;
    cout << "Your minimum healthy weight is " << min_weight << " lbs." << endl;
    cout << "Your maximum healthy weight is " << max_weight << " lbs." << endl;

    return 0;

}
