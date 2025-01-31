// Syed Zahran 
// roll No 24K-0672

// Code for 7 days

#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_CITIES = 4;
const int NUM_DAYS = 7;

void inputAQI(int aqi[NUM_CITIES][NUM_DAYS]) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "Enter AQI values for City " << (i + 1) << " over " << NUM_DAYS << " days:\n";
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Day " << (j + 1) << ": ";
            cin >> aqi[i][j];
        }
    }
}

void calculateWeeklyAverage(int aqi[NUM_CITIES][NUM_DAYS], double averages[NUM_CITIES]) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        int sum = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            sum += aqi[i][j];
        }
        averages[i] = static_cast<double>(sum) / NUM_DAYS;
    }
}

void identifyCriticalDays(int aqi[NUM_CITIES][NUM_DAYS]) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "Critical pollution days for City " << (i + 1) << ": ";
        bool hasCriticalDays = false; 
        for (int j = 0; j < NUM_DAYS; ++j) {
            if (aqi[i][j] > 150) {
                cout << "Day " << (j + 1) << " ";
                hasCriticalDays = true;
            }
        }
        if (!hasCriticalDays) {
            cout << "None";
        }
        cout << endl;
    }
}

void visualizeAQI(int aqi[NUM_CITIES][NUM_DAYS]) {
    cout << "\nAQI Visualization:\n";
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "City " << (i + 1) << ":\n";
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Day " << (j + 1) << ": ";
            int stars = aqi[i][j] / 50; 
            for (int k = 0; k < stars; ++k) {
                cout << "*";
            }
            cout << " (" << aqi[i][j] << ")\n";
        }
    }
}

void generateReport(int aqi[NUM_CITIES][NUM_DAYS], double averages[NUM_CITIES]) {
    cout << "\nWeekly AQI Report:\n";
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "City " << (i + 1) << " - Average AQI: " << fixed << setprecision(2) << averages[i] << endl;
    }
    identifyCriticalDays(aqi); 
    visualizeAQI(aqi); 

int main() {
    int aqi[NUM_CITIES][NUM_DAYS];
    double averages[NUM_CITIES];

    inputAQI(aqi);
    calculateWeeklyAverage(aqi, averages);
    generateReport(aqi, averages);

    return 0;
}





// Code for 28 days

// Code for 28 days






#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_CITIES = 4;
const int NUM_DAYS = 28; 

void inputAQI(int aqi[NUM_CITIES][NUM_DAYS]) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "Enter AQI values for City " << (i + 1) << " over " << NUM_DAYS << " days:\n";
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Day " << (j + 1) << ": ";
            cin >> aqi[i][j];
        }
    }
}

void calculateWeeklyAverage(int aqi[NUM_CITIES][NUM_DAYS], double averages[NUM_CITIES][4]) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        for (int week = 0; week < 4; ++week) {
            int sum = 0;
            for (int day = 0; day < 7; ++day) {
                sum += aqi[i][week * 7 + day];
            }
            averages[i][week] = static_cast<double>(sum) / 7;
        }
    }
}

void identifyCriticalDays(int aqi[NUM_CITIES][NUM_DAYS]) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "Critical pollution days for City " << (i + 1) << ": ";
        bool hasCriticalDays = false; 
        for (int j = 0; j < NUM_DAYS; ++j) {
            if (aqi[i][j] > 150) {
                cout << "Day " << (j + 1) << " ";
                hasCriticalDays = true; 
            }
        }
        if (!hasCriticalDays) {
            cout << "None"; 
        }
        cout << endl;
    }
}

void visualizeAQI(int aqi[NUM_CITIES][NUM_DAYS]) {
    cout << "\nAQI Visualization:\n";
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "City " << (i + 1) << ":\n";
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Day " << (j + 1) << ": ";
            int stars = aqi[i][j] / 50; 
            for (int k = 0; k < stars; ++k) {
                cout << "*";
            }
            cout << " (" << aqi[i][j] << ")\n";
        }
    }
}

void findMostImprovedCity(double averages[NUM_CITIES][4]) {
    double maxImprovement = 0;
    int mostImprovedCity = -1;

    for (int i = 0; i < NUM_CITIES; ++i) {
        double improvement = averages[i][0] - averages[i][3];
        if (improvement > maxImprovement) {
            maxImprovement = improvement;
            mostImprovedCity = i;
        }
    }

    if (mostImprovedCity != -1) {
        cout << "City " << (mostImprovedCity + 1) << " has the most improved air quality with a drop of " 
             << fixed << setprecision(2) << maxImprovement << " in average AQI.\n";
    } else {
        cout << "No city showed improvement in air quality.\n";
    }
}

void generateReport(int aqi[NUM_CITIES][NUM_DAYS], double averages[NUM_CITIES][4]) {
    cout << "\nMonthly AQI Report:\n";
    for (int i = 0; i < NUM_CITIES; ++i) {
        cout << "City " << (i + 1) << " - Weekly Averages:\n";
        for (int week = 0; week < 4; ++week) {
            cout << "Week " << (week + 1) << ": " << fixed << setprecision(2) << averages[i][week] << endl;
        }
    }
    identifyCriticalDays(aqi);
    visualizeAQI(aqi); 
    findMostImprovedCity(averages);
}

int main() {
    int aqi[NUM_CITIES][NUM_DAYS];
    double weeklyAverages[NUM_CITIES][4];

    inputAQI(aqi);
    calculateWeeklyAverage(aqi, weeklyAverages);
    generateReport(aqi, weeklyAverages);

    return 0;
}


