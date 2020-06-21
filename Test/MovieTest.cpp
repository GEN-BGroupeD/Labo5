#include "gtest/gtest.h"
#include "gmock/gmock.h"


#include "../src/Movie.h"

TEST(movie_test, TestMovieName){

    Movie movie("Karate Kid");

    std::string resultat = movie.getTitle();
    std::string attendu = "Karate Kid";

    EXPECT_EQ(resultat, attendu);
}

TEST(movie_test, TestDefaultMovieType){

    Movie movie("Karate Kid");

    MoviePriceType* resultat = movie.getPriceType();
    MoviePriceType* attendu = &RegularPrice::getInstance();

    EXPECT_EQ(resultat, attendu);
}

TEST(movie_test, TestRefularMovieType){

    Movie movie("Karate Kid",RegularPrice::getInstance());

    MoviePriceType* resultat = movie.getPriceType();
    MoviePriceType* attendu = &RegularPrice::getInstance();

    EXPECT_EQ(resultat, attendu);
}