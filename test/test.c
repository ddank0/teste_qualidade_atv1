#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/ticketFunctions.h"
#include "minunit/minunit.h"

// Mock da função getAge para testes
int mock_ages[] = {10, 30, 65}; // Idades para teste: criança, adulto, idoso
int mock_index 	= 0;

// Função wrapper que substitui a getAge original
int getAge(int index) {
    return mock_ages[mock_index++];
}

MU_TEST(test_verify_entry_valida) {
    mu_assert_int_eq(1, verifyEntry(3));
}

MU_TEST(test_verify_entry_invalida) {
    mu_assert_int_eq(0, verifyEntry(6));
}

MU_TEST(test_get_price_crianca) {
    mu_assert_int_eq(10, getPrice(10));
}

MU_TEST(test_get_price_adulto) {
    mu_assert_int_eq(30, getPrice(30));
}

MU_TEST(test_get_price_idoso) {
    mu_assert_int_eq(15, getPrice(65));
}

MU_TEST(test_calc_total_price_um_bilhete) {
    mock_index = 0;
    mu_assert_double_eq(10.0, calcTotalPrice(1));
}

MU_TEST(test_calc_total_price_dois_bilhetes) {
    mock_index = 0;
    mu_assert_double_eq(40.0, calcTotalPrice(2));
}

MU_TEST(test_calc_total_price_tres_bilhetes) {
    mock_index = 0;
    mu_assert_double_eq(55.0, calcTotalPrice(3));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_verify_entry_valida);
    MU_RUN_TEST(test_verify_entry_invalida);
    MU_RUN_TEST(test_get_price_crianca);
    MU_RUN_TEST(test_get_price_adulto);
    MU_RUN_TEST(test_get_price_idoso);
    MU_RUN_TEST(test_calc_total_price_um_bilhete);
    MU_RUN_TEST(test_calc_total_price_dois_bilhetes);
    MU_RUN_TEST(test_calc_total_price_tres_bilhetes);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
} 