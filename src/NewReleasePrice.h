//
// Created by HDubuis on 21.06.2020.
//

#ifndef NEWRELEASEPRICE_H
#define NEWRELEASEPRICE_H

#include "MoviePriceType.h"

class NewReleasePrice : public MoviePriceType {
public:

    static NewReleasePrice& getInstance() {
        static NewReleasePrice instance;

        return instance;
    }

    double getPrice(double days) override {
        return price*days;
    }

    int getBonus() override {
        return 1;
    }

private:
    explicit NewReleasePrice() : MoviePriceType(3){}
};

#endif //NEWRELEASEPRICE_H
