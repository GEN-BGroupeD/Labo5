//
// Created by HDubuis on 21.06.2020.
//

#ifndef REGULAREPRICE_H
#define REGULAREPRICE_H

#include "MoviePriceType.h"

class RegularPrice : public MoviePriceType {
public:

    static RegularPrice& getInstance() {
        static RegularPrice instance;

        return instance;
    }

    double getPrice(double days) override {
        return price + ((days > 2) ? (days - 2) * 1.5 : 0);
    }

private:
    explicit RegularPrice() : MoviePriceType(2){}
};


#endif //REGULAREPRICE_H
