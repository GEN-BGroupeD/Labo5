#include <iostream>

#include "Customer.h"
#include "NewReleasePrice.h"
#include "ChildrenPrice.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", NewReleasePrice::getInstance() ), 5));
    customer.addRental( Rental( Movie("Snow White", ChildrenPrice::getInstance()), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}