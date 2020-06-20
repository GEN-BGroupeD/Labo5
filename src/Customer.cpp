// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Rental.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( const Rental &rental : _rentals ) {
        double thisAmount = 0;
        thisAmount += rental.getAmount();

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        frequentRenterPoints += rental.getBonus();

        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

