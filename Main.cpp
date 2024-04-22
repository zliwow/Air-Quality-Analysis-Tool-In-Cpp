using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <vector> // using vector here because my attempt of making custom vector class didn't work out
#include <sstream>

// Date class with required constructor and methods
class Date {
public:
    int Day;
    int month;
    int year;

    Date(int d, int m, int y) : Day(d), month(m), year(y) {}
};
// Time Class with required constructor and methods
class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
};
// AirQuality Class with Date, Time, Temperature, Relative Humidity and Absolute Humidity
// with appropriate constructor and methods
class airQuality {
public:
    Date date;
    Time time;
    double Temp;
    double AbsoluteHumidity;
    double RelativeHumidity;

    airQuality(Date d, Time t, double temp, double ah, double rh)
        : date(d), time(t), Temp(temp), AbsoluteHumidity(ah), RelativeHumidity(rh) {}
};

// Function 
void displayAverageTemperature(const vector<airQuality>& data, int month);
void displayAverageRelativeHumidity(const vector<airQuality>& data, int month);
void displayAverageAbsoluteHumidity(const vector<airQuality>& data, int month);
void displayDataByDateTime(const vector<airQuality>& data, const Date& date, const Time& time);
void displayHighestTemperature(const vector<airQuality>& data, int month);
void displayHighestRelativeHumidity(const vector<airQuality>& data, int month);
void displayHighestAbsoluteHumidity(const vector<airQuality>& data, int month);
void displayTemperatureAboveAverage(const vector<airQuality>& data, int month);
void displayRelativeHumidityAboveAverage(const vector<airQuality>& data, int month);
void displayAbsoluteHumidityAboveAverage(const vector<airQuality>& data, int month);

// Function to run test cases
void runTests() {
    // Test case 1: Display average temperature for a month
    {
        vector<airQuality> data;
        data.push_back(airQuality(Date(1, 1, 2023), Time(0, 0, 0), 25.5, 0.0, 0.0));
        data.push_back(airQuality(Date(2, 1, 2023), Time(0, 0, 0), 26.7, 0.0, 0.0));
        data.push_back(airQuality(Date(3, 1, 2023), Time(0, 0, 0), 24.3, 0.0, 0.0));

        cout << "Test Case 1: Display average temperature for a month" << endl;
        displayAverageTemperature(data, 1);
        cout << endl;
    }

    // Test case 2: Display average relative humidity for a month
    {
        vector<airQuality> data;
        data.push_back(airQuality(Date(1, 2, 2023), Time(0, 0, 0), 0.0, 0.0, 60.5));
        data.push_back(airQuality(Date(2, 2, 2023), Time(0, 0, 0), 0.0, 0.0, 62.3));
        data.push_back(airQuality(Date(3, 2, 2023), Time(0, 0, 0), 0.0, 0.0, 59.8));

        cout << "Test Case 2: Display average relative humidity for a month" << endl;
        displayAverageRelativeHumidity(data, 2);
        cout << endl;
    }

        // Test case 3: Display data for a specific date and time
    {
        vector<airQuality> data;
        data.push_back(airQuality(Date(1, 3, 2023), Time(10, 0, 0), 25.5, 0.0, 60.5));
        data.push_back(airQuality(Date(1, 3, 2023), Time(11, 0, 0), 26.7, 0.0, 62.3));
        data.push_back(airQuality(Date(2, 3, 2023), Time(10, 0, 0), 24.3, 0.0, 59.8));

        cout << "Test Case 3: Display data for a specific date and time" << endl;
        displayDataByDateTime(data, Date(1, 3, 2023), Time(10, 0, 0));
        cout << endl;
    }

    // Test case 4: Display highest temperature for a month
    {
        vector<airQuality> data;
        data.push_back(airQuality(Date(1, 4, 2023), Time(0, 0, 0), 25.5, 0.0, 0.0));
        data.push_back(airQuality(Date(2, 4, 2023), Time(0, 0, 0), 28.2, 0.0, 0.0));
        data.push_back(airQuality(Date(3, 4, 2023), Time(0, 0, 0), 24.3, 0.0, 0.0));

        cout << "Test Case 4: Display highest temperature for a month" << endl;
        displayHighestTemperature(data, 4);
        cout << endl;
    }

    // Test case 5: Display highest relative humidity for a month
    {
        vector<airQuality> data;
        data.push_back(airQuality(Date(1, 5, 2023), Time(0, 0, 0), 0.0, 0.0, 60.5));
        data.push_back(airQuality(Date(2, 5, 2023), Time(0, 0, 0), 0.0, 0.0, 65.8));
        data.push_back(airQuality(Date(3, 5, 2023), Time(0, 0, 0), 0.0, 0.0, 59.2));

        cout << "Test Case 5: Display highest relative humidity for a month" << endl;
        displayHighestRelativeHumidity(data, 5);
        cout << endl;
    }

    // Test case 6: Display dates and times when temperature is above average for a month
    {
        vector<airQuality> data;
        data.push_back(airQuality(Date(1, 6, 2023), Time(0, 0, 0), 25.5, 0.0, 0.0));
        data.push_back(airQuality(Date(2, 6, 2023), Time(0, 0, 0), 28.2, 0.0, 0.0));
        data.push_back(airQuality(Date(3, 6, 2023), Time(0, 0, 0), 24.3, 0.0, 0.0));

        cout << "Test Case 6: Display dates and times when temperature is above average for a month" << endl;
        displayTemperatureAboveAverage(data, 6);
        cout << endl;
    }

    // Test case 7: Display dates and times when relative humidity is above average for a month
    {
        vector<airQuality> data;
        data.push_back(airQuality(Date(1, 7, 2023), Time(0, 0, 0), 0.0, 0.0, 60.5));
        data.push_back(airQuality(Date(2, 7, 2023), Time(0, 0, 0), 0.0, 0.0, 65.8));
        data.push_back(airQuality(Date(3, 7, 2023), Time(0, 0, 0), 0.0, 0.0, 59.2));

        cout << "Test Case 7: Display dates and times when relative humidity is above average for a month" << endl;
        displayRelativeHumidityAboveAverage(data, 7);
        cout << endl;
    }

}

int main() {
    string filename = "AirQualityUCI.csv";
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    vector<airQuality> airData;
    string line;

    // Skip the header line
    getline(inputFile, line);

    // Read the file line by line
    while (getline(inputFile, line)) {
        // Parse the line and extract the values
        istringstream iss(line);
        string dateStr, timeStr, tempStr, rhStr, ahStr;

        // Read the values 
        getline(iss, dateStr, ',');
        getline(iss, timeStr, ',');
        // Skip the columns not needed for this analysis
        for (int i = 0; i < 10; i++) {
            string dummy;
            getline(iss, dummy, ',');
        }
        getline(iss, tempStr, ',');
        getline(iss, rhStr, ',');
        getline(iss, ahStr, ',');

        try {
            // Extract the date values
            int month = stoi(dateStr.substr(0, 2));
            int day = stoi(dateStr.substr(3, 2));
            int year = stoi(dateStr.substr(6, 4));
            Date date(day, month, year);

            // Extract the time values
            int hours = stoi(timeStr.substr(0, 2));
            int minutes = stoi(timeStr.substr(3, 2));
            int seconds = stoi(timeStr.substr(6, 2));
            Time time(hours, minutes, seconds);

            // Extract the temperature, relative humidity, and absolute humidity values
            double temperature = stod(tempStr);
            double relativeHumidity = stod(rhStr);
            double absoluteHumidity = stod(ahStr);

            // Create an airQuality object and add it to the vector
            airQuality airObj(date, time, temperature, absoluteHumidity, relativeHumidity);
            airData.push_back(airObj);
        }
        catch (const invalid_argument& e) {
            // Skip the invalid line and continue reading the file

            // Could use this commented out block to produce a log file that records invalid lines
            // ofstream logFile("invalid_lines.log", ios::app);
            // logFile << "Invalid line: " << line << endl;
            // logFile.close();
        }
    }

    runTests();

    inputFile.close();

    // Display menu options for the user as the project required
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Display average temperature for a month" << endl;
        cout << "2. Display average relative humidity for a month" << endl;
        cout << "3. Display average absolute humidity for a month" << endl;
        cout << "4. Display data for a specific date and time" << endl;
        cout << "5. Display highest temperature for a month" << endl;
        cout << "6. Display highest relative humidity for a month" << endl;
        cout << "7. Display highest absolute humidity for a month" << endl;
        cout << "8. Display dates and times when temperature is above average for a month" << endl;
        cout << "9. Display dates and times when relative humidity is above average for a month" << endl;
        cout << "10. Display dates and times when absolute humidity is above average for a month" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Additional prompts to produce and fulfill project required match
        switch (choice) {
            case 1: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayAverageTemperature(airData, month);
                break;
            }
            case 2: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayAverageRelativeHumidity(airData, month);
                break;
            }
            case 3: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayAverageAbsoluteHumidity(airData, month);
                break;
            }
            case 4: {
                int day, month, year, hours, minutes, seconds;
                cout << "Enter the date (DD MM YYYY): ";
                cin >> day >> month >> year;
                cout << "Enter the time (HH MM SS): ";
                cin >> hours >> minutes >> seconds;
                Date date(day, month, year);
                Time time(hours, minutes, seconds);
                displayDataByDateTime(airData, date, time);
                break;
            }
            case 5: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayHighestTemperature(airData, month);
                break;
            }
            case 6: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayHighestRelativeHumidity(airData, month);
                break;
            }
            case 7: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayHighestAbsoluteHumidity(airData, month);
                break;
            }
            case 8: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayTemperatureAboveAverage(airData, month);
                break;
            }
            case 9: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayRelativeHumidityAboveAverage(airData, month);
                break;
            }
            case 10: {
                int month;
                cout << "Enter the month (1-12): ";
                cin >> month;
                displayAbsoluteHumidityAboveAverage(airData, month);
                break;
            }
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}

// Function implementations
void displayAverageTemperature(const vector<airQuality>& data, int month) {
    double sum = 0.0;
    int count = 0;

    for (const auto& obj : data) {
        if (obj.date.month == month) {
            sum += obj.Temp;
            count++;
        }
    }

    if (count > 0) {
        double average = sum / count;
        cout << "Average temperature for month " << month << ": " << average << endl;
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayAverageRelativeHumidity(const vector<airQuality>& data, int month) {
    double sum = 0.0;
    int count = 0;

    for (const auto& obj : data) {
        if (obj.date.month == month) {
            sum += obj.RelativeHumidity;
            count++;
        }
    }

    if (count > 0) {
        double average = sum / count;
        cout << "Average relative humidity for month " << month << ": " << average << endl;
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayAverageAbsoluteHumidity(const vector<airQuality>& data, int month) {
    double sum = 0.0;
    int count = 0;

    for (const auto& obj : data) {
        if (obj.date.month == month) {
            sum += obj.AbsoluteHumidity;
            count++;
        }
    }

    if (count > 0) {
        double average = sum / count;
        cout << "Average absolute humidity for month " << month << ": " << average << endl;
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayDataByDateTime(const vector<airQuality>& data, const Date& date, const Time& time) {
    bool found = false;

    for (const auto& obj : data) {
        if (obj.date.Day == date.Day && obj.date.month == date.month && obj.date.year == date.year &&
            obj.time.hours == time.hours && obj.time.minutes == time.minutes && obj.time.seconds == time.seconds) {
            cout << "Data for " << date.month << "/" << date.Day << "/" << date.year
                 << " " << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
            cout << "Temperature: " << obj.Temp << endl;
            cout << "Relative Humidity: " << obj.RelativeHumidity << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No data found for the specified date and time." << endl;
    }
}

void displayHighestTemperature(const vector<airQuality>& data, int month) {
    double highestTemp = -1.0;
    Date highestDate(0, 0, 0);
    Time highestTime(0, 0, 0);

    for (const auto& obj : data) {
        if (obj.date.month == month && obj.Temp > highestTemp) {
            highestTemp = obj.Temp;
            highestDate = obj.date;
            highestTime = obj.time;
        }
    }

    if (highestTemp != -1.0) {
        cout << "Highest temperature for month " << month << ": " << highestTemp << endl;
        cout << "Date: " << highestDate.month << "/" << highestDate.Day << "/" << highestDate.year << endl;
        cout << "Time: " << highestTime.hours << ":" << highestTime.minutes << ":" << highestTime.seconds << endl;
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayHighestRelativeHumidity(const vector<airQuality>& data, int month) {
    double highestRH = -1.0;
    Date highestDate(0, 0, 0);
    Time highestTime(0, 0, 0);

    for (const auto& obj : data) {
        if (obj.date.month == month && obj.RelativeHumidity > highestRH) {
            highestRH = obj.RelativeHumidity;
            highestDate = obj.date;
            highestTime = obj.time;
        }
    }

    if (highestRH != -1.0) {
        cout << "Highest relative humidity for month " << month << ": " << highestRH << endl;
        cout << "Date: " << highestDate.month << "/" << highestDate.Day << "/" << highestDate.year << endl;
        cout << "Time: " << highestTime.hours << ":" << highestTime.minutes << ":" << highestTime.seconds << endl;
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayHighestAbsoluteHumidity(const vector<airQuality>& data, int month) {
    double highestAH = -1.0;
    Date highestDate(0, 0, 0);
    Time highestTime(0, 0, 0);

    for (const auto& obj : data) {
        if (obj.date.month == month && obj.AbsoluteHumidity > highestAH) {
            highestAH = obj.AbsoluteHumidity;
            highestDate = obj.date;
            highestTime = obj.time;
        }
    }

    if (highestAH != -1.0) {
        cout << "Highest absolute humidity for month " << month << ": " << highestAH << endl;
        cout << "Date: " << highestDate.month << "/" << highestDate.Day << "/" << highestDate.year << endl;
        cout << "Time: " << highestTime.hours << ":" << highestTime.minutes << ":" << highestTime.seconds << endl;
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayTemperatureAboveAverage(const vector<airQuality>& data, int month) {
    double sumTemp = 0.0;
    int countTemp = 0;

    for (const auto& obj : data) {
        if (obj.date.month == month) {
            sumTemp += obj.Temp;
            countTemp++;
        }
    }

    if (countTemp > 0) {
        double avgTemp = sumTemp / countTemp;
        cout << "Dates and times when temperature is above average for month " << month << ":" << endl;

        for (const auto& obj : data) {
            if (obj.date.month == month && obj.Temp > avgTemp) {
                cout << "Date: " << obj.date.month << "/" << obj.date.Day << "/" << obj.date.year
                     << ", Time: " << obj.time.hours << ":" << obj.time.minutes << ":" << obj.time.seconds
                     << ", Temperature: " << obj.Temp << endl;
            }
        }
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayRelativeHumidityAboveAverage(const vector<airQuality>& data, int month) {
    double sumRH = 0.0;
    int countRH = 0;

    for (const auto& obj : data) {
        if (obj.date.month == month) {
            sumRH += obj.RelativeHumidity;
            countRH++;
        }
    }

    if (countRH > 0) {
        double avgRH = sumRH / countRH;
        cout << "Dates and times when relative humidity is above average for month " << month << ":" << endl;

        for (const auto& obj : data) {
            if (obj.date.month == month && obj.RelativeHumidity > avgRH) {
                cout << "Date: " << obj.date.month << "/" << obj.date.Day << "/" << obj.date.year
                     << ", Time: " << obj.time.hours << ":" << obj.time.minutes << ":" << obj.time.seconds
                     << ", Relative Humidity: " << obj.RelativeHumidity << endl;
            }
        }
    } else {
        cout << "No data found for month " << month << endl;
    }
}

void displayAbsoluteHumidityAboveAverage(const vector<airQuality>& data, int month) {
    double sumAH = 0.0;
    int countAH = 0;

    for (const auto& obj : data) {
        if (obj.date.month == month) {
            sumAH += obj.AbsoluteHumidity;
            countAH++;
        }
    }

    if (countAH > 0) {
        double avgAH = sumAH / countAH;
        cout << "Dates and times when absolute humidity is above average for month " << month << ":" << endl;

        for (const auto& obj : data) {
            if (obj.date.month == month && obj.AbsoluteHumidity > avgAH) {
                cout << "Date: " << obj.date.month << "/" << obj.date.Day << "/" << obj.date.year
                     << ", Time: " << obj.time.hours << ":" << obj.time.minutes << ":" << obj.time.seconds
                     << ", Absolute Humidity: " << obj.AbsoluteHumidity << endl;
            }
        }
    } else {
        cout << "No data found for month " << month << endl;
    }
}