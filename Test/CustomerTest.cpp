#include "../src/Customer.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

// Test pour Customer statement

/**
* Test d'un customer sans nom
*/
TEST(customer_tests, statementNoName) {
    Customer customer;

    std::string resultat = customer.statement();
    std::string attendu = "Rental Record for \nAmount owed is 0\nYou earned 0 frequent renter points";

    EXPECT_EQ(resultat, attendu);
}

/**
* Test d'un customer avec nom
*/
TEST(customer_tests, statementWithName){

    Customer customer("CustomerName");

    std::string resultat = customer.statement();
    std::string attendu = "Rental Record for CustomerName\nAmount owed is 0\nYou earned 0 frequent renter points";

    EXPECT_EQ(resultat, attendu);
}



/**
 * Test d'un customer avec nom et rental, suivant ce qui est donné dans le main
 */
TEST(customer_tests, statementRentalFromMain) {

    Customer customer("Olivier");

    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    std::string resultat = customer.statement();
    std::string attendu = "Rental Record for Olivier\n\tKarate Kid\t9.5\n"
                           "\tAvengers: Endgame\t15\n"
                           "\tSnow White\t1.5\n"
                           "Amount owed is 26\n"
                           "You earned 4 frequent renter points";

    EXPECT_EQ(resultat, attendu);
}