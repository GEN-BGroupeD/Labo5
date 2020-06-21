//
// Created by HDubuis on 21.06.2020.
//

#ifndef CHILDRENPRICE_H
#define CHILDRENPRICE_H

#include "MoviePriceType.h"

class ChildrenPrice : public MoviePriceType {
public:

    static ChildrenPrice& getInstance() {
        static ChildrenPrice instance;

        return instance;
    }

    double getPrice(double days) override {
        return price + ((days > 3) ? (days - 3) * 1.5 : 0);
    }

private:
    explicit ChildrenPrice() : MoviePriceType(1.5){}
};

#endif //CHILDRENPRICE_H
