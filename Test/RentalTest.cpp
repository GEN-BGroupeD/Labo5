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


/*
 *Test que les nouveau film sorti avec au maximum un jour d'emprunt ne donne pas de bonus
 */

TEST(rental_test,newReleaseMovieWithLessThanTwoDayDonTGiveBonus){
    Movie newMovie("new",1);
    Rental rental(newMovie, 1);

    double bonus = rental.getBonus();
    double attendu = 0;

    EXPECT_EQ(bonus, attendu);
}


/*
 *Test que les nouveau film sorti avec plus d'un jour d'emprunt donne un bonus
 */

TEST(rental_test,newReleaseMovieWithLessMoreThanOneDayDonTGiveBonus){
    Movie newMovie("new",1);
    Rental rental(newMovie, 2);

    double bonus = rental.getBonus();
    double attendu = 1;

    EXPECT_EQ(bonus, attendu);
}

/*
 *Test que les film pour enfant n'ait pas de bonus
 */

TEST(rental_test,NoBonusOnChildrenMovie){
    Movie child("child",2);
    Rental rental(child, 10);

    double bonus = rental.getBonus();
    double attendu = 0;

    EXPECT_EQ(bonus, attendu);
}

/*
 *Test que les film régulier n'ait pas de bonus
 */

TEST(rental_test,NoBonusOnRegularMovie){
    Movie regular("regular",0);
    Rental rental(regular, 10);

    double bonus = rental.getBonus();
    double attendu = 0;

    EXPECT_EQ(bonus, attendu);
}
