
#include <iostream>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructors
    Time() : hour(0), minute(0), second(0) {}
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Getter methods
    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    int getSecond() const {
        return second;
    }

    // Setter methods
    void setHour(int h) {
        hour = h;
    }

    void setMinute(int m) {
        minute = m;
    }

    void setSecond(int s) {
        second = s;
    }

    // Print the time
    void printTime() const {
        cout<< hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int numObjects;
    cout<< "Enter the number of Time objects: ";
    cin >> numObjects;

    
    Time* timeArray = new Time[numObjects];

    for (int i = 0; i < numObjects; ++i) {
        int h, m, s;
        cout<< "Enter time for object " << i + 1 << " (hh mm ss): ";
        cin >> h >> m >> s;
        timeArray[i] = Time(h, m, s);
    }

    for (int i = 0; i < numObjects; ++i) {
        cout<< "Time for object " << i + 1 << ": ";
        timeArray[i].printTime();
    }

    delete[] timeArray;

    return 0;
}
