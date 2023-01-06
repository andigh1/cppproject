#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <map>



using namespace std;



class Stadium
{
private:
    int rows;
    int seatsPerRow;
    int totalSeats;
    static int nextTicketId;
    map<int, bool> tickets;
    
    

public:
    
    // Default constructor
    
    Stadium()
    {
        rows = 0;
        seatsPerRow = 0;
        totalSeats = 0;
    }

    // Copy constructor
    Stadium(const Stadium& other)
    {
        rows = other.rows;
        seatsPerRow = other.seatsPerRow;
        totalSeats = other.totalSeats;
        tickets = other.tickets;
    }

    // Destructor
    ~Stadium() {}



    // Cast operator
    operator bool()
    {
        for (const auto& ticket : tickets)
        {
            if (!ticket.second)
            {
                return true;
            }
        }
        return false;
    }



    // Indexing operator
    bool operator[] (int ticketId)
    {
        return tickets[ticketId];
    }

    // Input operator
    friend istream& operator>> (istream& in, Stadium& s)
    {
        cout << "Rows: ";
        in >> s.rows;
        cout << "Seats per row: ";
        in >> s.seatsPerRow;
        s.totalSeats = s.rows * s.seatsPerRow;
        return in;
    }

    // Output operator
    friend ostream& operator<< (ostream& out, Stadium& s)
    {
        out << "Rows: " << s.rows << endl;
        out << "Seats per row: " << s.seatsPerRow << endl;
        out << "Total seats: " << s.totalSeats << endl;
        return out;
    }

    // Other operator
    int operator+ (int numSeats)
    {
        int ticketId = nextTicketId++;
        tickets[ticketId] = true;
        return ticketId;
    }

    // Setters and getters for rows, seatsPerRow and totalSeats
    void setRows(int r) { rows = r; }
    int getRows() { return rows; }
    void setSeatsPerRow(int spr) { seatsPerRow = spr; }
    int getSeatsPerRow() { return seatsPerRow; }
    void setTotalSeats(int ts) { totalSeats = ts; }
    int getTotalSeats() { return totalSeats; }
};


