#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

class EventDetails
{
private:
    string date;
    string time;
    string name;

public:
    // Default constructor
    EventDetails()
    {
        date = "";
        time = "";
        name = "";
    }

    // Copy constructor
    EventDetails(const EventDetails& other)
    {
        date = other.date;
        time = other.time;
        name = other.name;
    }

    // Destructor
    ~EventDetails() {}

    // Input operator
    friend istream& operator>> (istream& in, EventDetails& e)
    {
        cout << "Date (DD/MM/YYYY): ";
        in >> e.date;
        cout << "Time (HH:MM): ";
        in >> e.time;
        cout << "Name: ";
        in >> e.name;
        return in;
    }

    // Output operator
    friend ostream& operator<< (ostream& out, EventDetails& e)
    {
        out << "Date: " << e.date << endl;
        out << "Time: " << e.time << endl;
        out << "Name: " << e.name << endl;
        return out;
    }

    // Increment operator
    EventDetails& operator++ ()
    {
        int day = stoi(date.substr(0, 2));
        int month = stoi(date.substr(3, 2));
        int year = stoi(date.substr(6, 4));
        if (++day > 31)
        {
            day = 1;
            if (++month > 12)
            {
                month = 1;
                ++year;
            }
        }
        date = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
        return *this;
    }

    // Cast operator
    operator string()
    {
        return date + " " + time + " " + name;
    }

    // Setters and getters for date, time and name
    void setDate(string d) { date = d; }
    string getDate() { return date; }
    void setTime(string t) { time = t; }
    string getTime() { return time; }
    void setName(string n) { name = n; }
    string getName() { return name; }
};
