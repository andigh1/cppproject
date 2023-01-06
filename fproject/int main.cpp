#include <iostream>
#include "Bool.cpp"
#include "Stadium.cpp"
#include "EventDetails.cpp"


using namespace std;

int main()
{

    Bool b;
    Stadium s;
    EventDetails e;

    string eventName;
    cout << "Enter event name: ";
    getline(cin, eventName);

    cout << "Do you want to buy a ticket for the '" << eventName; //<< "' event? (y/n) ";
    cin >> b;
    if (!b)
    {
        cout << "Thank you for considering our event." << endl;
        return 0;
    }  

    cout << "Do you want a VIP ticket? (y/n) ";
    cin >> b;
    int price = b ? 100 : 50;

    cout << "Enter seat number: ";
    int seat;
    cin >> seat;

    cout << "Enter event details:" << endl;
    cin >> e;

    //int ticketId = s + 1;
    //s.tickets[ticketId] = true;

    cout << "Ticket details:" << endl;
    cout << "Event: " << eventName << endl;
    cout << "Type: " << (b ? "VIP" : "Regular") << endl;
    cout << "Price: " << price << "$" << endl;
    cout << "Seat: " << seat << endl;
    cout << "Event details: " << e << endl;

    return 0;
}
