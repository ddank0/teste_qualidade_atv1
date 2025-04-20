#include "minunit/minunit.h"
#include "ticketFunctions.h"

// Variáveis globais para o mock (definidas aqui)
int mock_ages[100];
int mock_index = 0;

// Mock da função getAge()
#ifdef TEST
int getAge(int index) {
    return mock_ages[mock_index++];
}
#endif

MU_TEST(test_checkTicketQuantity_valid) {
    mu_check(verifyEntry(3) == 1); // Quantidade válida
}

MU_TEST(test_checkTicketQuantity_invalid) {
    mu_check(verifyEntry(6) == 0); // Quantidade inválida
}

MU_TEST(test_determinePrice_child) {
    mu_check(getPrice(10) == 10); // Preço para crianças
}

MU_TEST(test_determinePrice_adult) {
    mu_check(getPrice(30) == 30); // Preço para adultos
}

MU_TEST(test_determinePrice_senior) {
    mu_check(getPrice(65) == 15); // Preço para idosos
}

MU_TEST(test_calculateTotalPrice) {
    mu_check(calcTotalPrice(2) == 60); // Preço total
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_checkTicketQuantity_valid);
    MU_RUN_TEST(test_checkTicketQuantity_invalid);
    MU_RUN_TEST(test_determinePrice_child);
    MU_RUN_TEST(test_determinePrice_adult);
    MU_RUN_TEST(test_determinePrice_senior);
    // MU_RUN_TEST(test_calculateTotalPrice);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}

