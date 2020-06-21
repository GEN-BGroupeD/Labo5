// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "MoviePriceType.h"
#include "RegularePrice.h"

class Movie {
public:

    Movie( const std::string& title, MoviePriceType& priceType = RegularPrice::getInstance());

    MoviePriceType* getPriceType() const;
    void setPriceType( MoviePriceType& moviePriceType);
    std::string getTitle() const;

private:
    std::string _title;
    MoviePriceType* _priceType;
};

inline Movie::Movie( const std::string& title, MoviePriceType& priceCode )
        : _title( title )
        , _priceType( &priceCode )
{}

inline MoviePriceType* Movie::getPriceType() const { return _priceType; }

inline void Movie::setPriceType( MoviePriceType& moviePriceType ) { _priceType = &moviePriceType; }

inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H