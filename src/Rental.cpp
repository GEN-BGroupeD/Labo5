//
// Created by HDubuis on 21.06.2020.
//

#include <sstream>
#include <vector>
#include "Customer.h"
#include "Rental.h"

double Rental::getAmount() const {
    double thisAmount = 0;
    switch (getMovie().getPriceCode()) {
        case Movie::REGULAR:
            thisAmount += 2;
            if (getDaysRented() > 2)
                thisAmount += (getDaysRented() - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            thisAmount += 1.5;
            if (getDaysRented() > 3)
                thisAmount += (getDaysRented() - 3) * 1.5;
            break;
    }
    return thisAmount;
}