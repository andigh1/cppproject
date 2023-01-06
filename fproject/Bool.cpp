#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

class Bool
{
private:
    bool isVIP=0;
    float price;

public:
    // Default constructor
    Bool()
    {
        isVIP = false;
        price = 0.0;
    }

    // Copy constructor
    Bool(const Bool& other)
    {
        isVIP = other.isVIP;
        price = other.price;
    }

    // Destructor
    ~Bool() {}


    //Cast operator

    operator bool() const
    {
        return isVIP;
    }

    // Negation operator
    bool operator! ()
    {
        return !isVIP;
    }

    // Relational operator
    bool operator< (const Bool& other)
    {
        return price < other.price;
    }

    // Setters and getters for isVIP and price
    void setIsVIP(bool v) { isVIP = v; }
    bool getIsVIP() { return isVIP; }
    void setPrice(float p) { price = p; }
    float getPrice() { return price; }

    // Input operator
    friend istream& operator>> (istream& in, Bool& t)
    {
        cout << "Is VIP (0/1): ";
        in >> t.isVIP;
        cout << "Price: ";
        in >> t.price;
        return in;
    }

    // Output operator
    friend ostream& operator<< (ostream& out, Bool& t)
    {
        out << "Is VIP: " << t.isVIP << endl;
        out << "Price: " << t.price << endl;
        return out;
    }
};
