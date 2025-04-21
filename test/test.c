#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/ticketFunctions.h"
#include "minunit/minunit.h"

// Mock da função getAge para testes
int mock_ages[] = {10, 30, 65, 0, 12, 13, 59, 60, -1, 10, 8, 30, 20, 70}; // Idades para teste
int mock_index 	= 0;

// Função wrapper que substitui a getAge original
int getAge(int index) {
    (void)index; 
    return mock_ages[mock_index++];
}

MU_TEST(test_verify_entry_valida_1) {
    mu_assert_int_eq(1, verifyEntry(1));
}

MU_TEST(test_verify_entry_valida_3) {
    mu_assert_int_eq(1, verifyEntry(3));
}

MU_TEST(test_verify_entry_valida_5) {
    mu_assert_int_eq(1, verifyEntry(5));
}

MU_TEST(test_verify_entry_invalida_6) {
    mu_assert_int_eq(0, verifyEntry(6));
}

MU_TEST(test_verify_entry_invalida_0) {
    mu_assert_int_eq(0, verifyEntry(0));
}

MU_TEST(test_verify_entry_invalida_negativo) {
    mu_assert_int_eq(0, verifyEntry(-1));
}

MU_TEST(test_get_price_0_anos) {
    mu_assert_int_eq(10, getPrice(0));
}

MU_TEST(test_get_price_12_anos) {
    mu_assert_int_eq(10, getPrice(12));
}

MU_TEST(test_get_price_13_anos) {
    mu_assert_int_eq(30, getPrice(13));
}

MU_TEST(test_get_price_30_anos) {
    mu_assert_int_eq(30, getPrice(30));
}

MU_TEST(test_get_price_59_anos) {
    mu_assert_int_eq(30, getPrice(59));
}

MU_TEST(test_get_price_60_anos) {
    mu_assert_int_eq(15, getPrice(60));
}

MU_TEST(test_get_price_65_anos) {
    mu_assert_int_eq(15, getPrice(65));
}

MU_TEST(test_get_price_negativo) {
    mu_assert_int_eq(0, getPrice(-1));
}

MU_TEST(test_calc_total_price_um_bilhete_crianca) {
    mock_index = 0;
    mu_assert_double_eq(10.0, calcTotalPrice(1));
}

MU_TEST(test_calc_total_price_dois_bilhetes_misto) {
    mock_index = 0;
    mu_assert_double_eq(40.0, calcTotalPrice(2));
}

MU_TEST(test_calc_total_price_tres_bilhetes_misto) {
    mock_index = 0;
    mu_assert_double_eq(55.0, calcTotalPrice(3));
}

MU_TEST(test_calc_total_price_cinco_bilhetes_misto) {
    mock_index = 9; // Começa do índice 9 onde temos 2 crianças, 2 adultos e 1 idoso
    mu_assert_double_eq(95.0, calcTotalPrice(5));
}

MU_TEST_SUITE(test_suite) {
    // Testes de verificação de entrada
    MU_RUN_TEST(test_verify_entry_valida_1);
    MU_RUN_TEST(test_verify_entry_valida_3);
    MU_RUN_TEST(test_verify_entry_valida_5);
    MU_RUN_TEST(test_verify_entry_invalida_6);
    MU_RUN_TEST(test_verify_entry_invalida_0);
    MU_RUN_TEST(test_verify_entry_invalida_negativo);

    // Testes de preços por idade
    MU_RUN_TEST(test_get_price_0_anos);
    MU_RUN_TEST(test_get_price_12_anos);
    MU_RUN_TEST(test_get_price_13_anos);
    MU_RUN_TEST(test_get_price_30_anos);
    MU_RUN_TEST(test_get_price_59_anos);
    MU_RUN_TEST(test_get_price_60_anos);
    MU_RUN_TEST(test_get_price_65_anos);
    MU_RUN_TEST(test_get_price_negativo);

    // Testes de cálculo de total
    MU_RUN_TEST(test_calc_total_price_um_bilhete_crianca);
    MU_RUN_TEST(test_calc_total_price_dois_bilhetes_misto);
    MU_RUN_TEST(test_calc_total_price_tres_bilhetes_misto);
    MU_RUN_TEST(test_calc_total_price_cinco_bilhetes_misto);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
} 