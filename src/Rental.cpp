//
// Created by HDubuis on 21.06.2020.
//

#include <sstream>
#include <vector>
#include "Customer.h"
#include "Rental.h"

double Rental::getAmount() const {
    return _movie.getPriceType()->getPrice(getDaysRented());
}

int Rental::getBonus() const {
    if (getDaysRented() > 1)
        return _movie.getPriceType()->getBonus();
    return 0;
}

std::ostream& operator<< (std::ostream& ostream, const Rental& rental) {
    ostream << "\t" << rental.getMovie().getTitle() << "\t"
            << rental.getAmount();
    return ostream;
}