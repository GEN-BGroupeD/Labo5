#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../src/Rental.h"

//Test pour Rental

/*
 *Test pour les film regular pour moins de deux jours
 */

TEST(rental_test,RegularHaveTheRightPriceWithMoreThanTwoDays){
    Movie regularMovie("regular",0);
    Rental rental(regularMovie, 9);

    double montant = rental.getAmount();
    double attendu = 12.5;

    EXPECT_EQ(montant, attendu);
}

/*
 *Test pour les film regular pour plus de deux jours
 */

TEST(rental_test,RegularHaveTheRightPriceWithLessThanTwoDays){
    Movie regularMovie("regular",0);
    Rental rental(regularMovie, 1);

    double montant = rental.getAmount();
    double attendu = 2;

    EXPECT_EQ(montant, attendu);
}

/*
 *Test pour les film nouvellement sorti
 */
TEST(rental_test, newReleaseMovieHaveTheRightPrice){
    Movie newRelease("new",1);
    Rental rental(newRelease, 5);

    double montant = rental.getAmount();
    double attendu = 15;

    EXPECT_EQ(montant, attendu);
}

/*
 *Test pour les films pour enfants pour moins de trois jours
 */

TEST(rental_test,ChildrenMovieHaveTheRightPriceWithLessThanThreeDays){
    Movie children("child",2);
    Rental rental(children, 1);

    double montant = rental.getAmount();
    double attendu = 1.5;

    EXPECT_EQ(montant, attendu);
}

/*
 *Test pour les films pour enfants pour plus de trois jours
 */

TEST(rental_test,ChildrenMovieHaveTheRightPriceWithMoreThanThreeDays){
    Movie children("child",2);
    Rental rental(children, 5);

    double montant = rental.getAmount();
    double attendu = 4.5;

    EXPECT_EQ(montant, attendu);
}