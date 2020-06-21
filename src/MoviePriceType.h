#ifndef MOVIEPRICETYPE_H
#define MOVIEPRICETYPE_H

class MoviePriceType {
public:

    explicit MoviePriceType(double price) : price(price) {}

    virtual double getPrice(double daysRented) = 0;

    virtual int getBonus(){
        return 0;
    }

    virtual ~MoviePriceType() = default;

protected:
    const double price;
};

#endif //MOVIEPRICETYPE_H
