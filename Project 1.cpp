//Emily Etherington
//Project 1 
#include <iostream>
#include <ctime>

class Clock {
private:
    int hours; // variable to store the hours
    int minutes; // variable to store the minutes
    int seconds; // variable to store the seconds
    bool is12HourClock; // variable to check if the clock is in 12 hour format
    bool isAM; // variable to check if the time is AM or PM
    bool is24HourFormat; // variable to check if the clock is in 24 hour format
    int timeZone; // variable to store the time zone
public:
    Clock() {
        time_t currentTime = time(0); // get the current time
        tm* localTime = localtime(&currentTime); // convert the time to local time
        hours = localTime->tm_hour; // set the hours
        minutes = localTime->tm_min; // set the minutes
        seconds = localTime->tm_sec; // set the seconds
        is12HourClock = true; // set the clock to 12 hour format
        isAM = true; // set the time to AM
        is24HourFormat = true; // set the clock to 24 hour format
        timeZone = 0; // set the time zone to 0 (UTC)
    }
    void addHour() {
        hours = (hours + 1) % 24; // increment the hours, but keep it within 0-23 range
        if (hours == 0)
        {
            if (isAM)
            {
                isAM = false; // if the hour is 0 and time is AM, set it to PM
            }
            else
            {
                isAM = true; // if the hour is 0 and time is PM, set it to AM
            }
        }
    }

    void addMinute() {
        minutes = (minutes + 1) % 60; // increment the minutes, but keep it within 0-59 range
        if (minutes == 0) {
            addHour(); // if minutes is 0, increment the hour
        }
    }

    void addSecond() {
        seconds = (seconds + 1) % 60; // increment the seconds, but keep it within 0-59 range
        if (seconds == 0) {
            addMinute(); // if seconds is 0, increment the minutes
        }
    }

    void toggleClockFormat() {
        is12HourClock = !is12HourClock; // toggle the clock format between 12 hour and 24 hour
    }

    void toggle24HourFormat() {
        is24HourFormat = !is24HourFormat; // toggle the clock format between 24 hour and 12 hour
    }

    void setTimeZone(int timeZone) {
        this->timeZone = timeZone; // set the time zone
    }

    void displayClock() {
        if (is24HourFormat) {
            std::cout << hours << ":" << minutes << ":" << seconds;
        }
        else {
            int hour = (hours % 12 == 0) ? 12 : hours % 12; // convert the hour to 12 hour format
            std::cout << hour << ":" << minutes << ":" << seconds;
            if (isAM)
            {
                std::cout << " AM";
            }
            else
            {
                std::cout << " PM";
            }
        }
        if (timeZone != 0) {
            std::cout << " (UTC " << ((timeZone > 0) ? "+" : "") << timeZone << ")";
        }
    }
};

int main() {
    Clock clock;

    while (true) {
        std::cout << "Clock: ";
        clock.displayClock();

        std::cout << "\n\nMenu: \n1. Add Hour \n2. Add Minute \n3. Add Second \n4. Toggle Clock Format \n5. Toggle 24 Hour Format \n6. Set Time Zone \n7. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            clock.addHour();
            break;
        case 2:
            clock.addMinute();
            break;
        case 3:
            clock.addSecond();
            break;
        case 4:
            clock.toggleClockFormat();
            break;
        case 5:
            clock.toggle24HourFormat();
            break;
        case 6:
            int timeZone;
            std::cout << "Enter time zone (in hours): ";
            std::cin >> timeZone;
            clock.setTimeZone(timeZone);
            break;
        case 7:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
