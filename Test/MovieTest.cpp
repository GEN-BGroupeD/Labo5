#include "gtest/gtest.h"
#include "gmock/gmock.h"


#include "../src/Movie.h"

TEST(movie_test, TestMovieName){

    Movie movie("Karate Kid");

    std::string resultat = movie.getTitle();
    std::string attendu = "Karate Kid";

    EXPECT_EQ(resultat, attendu);
}