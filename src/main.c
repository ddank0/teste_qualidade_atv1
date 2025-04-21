#include <stdio.h>
#include <stdlib.h>
#include "ticketFunctions.h"

// Dados de Entrada:
// ▪ idade: Idade do visitante.
// ▪ quantidade: Número de bilhetes a serem comprados.
// Processamento:
// ▪ Verificar se a quantidade de bilhetes solicitada está dentro do limite permitido
// (máximo 5 por pessoa)
// ▪ Determinar o preço do bilhete com base na idade:
// ▪ Crianças (até 12 anos) pagam um preço reduzido (preço com desconto: R$10).
// ▪ Adultos (13 a 59 anos) pagam o preço completo (inteira: R$ 30).
// ▪ Idosos (60 anos ou mais) pagam um preço com desconto (meia R$ 15)
// ▪ Se a quantidade de bilhetes for aceitável, calcular o preço total.
// Saída:
// ▪ Exibir o preço total se a quantidade for permitida, ou uma mensagem de erro se não for.


int main() {

	int totalTickets;

	float totalPrice;

	totalTickets = getTotalTickets();

	if (!verifyEntry(totalTickets)) {
		printf("Erro: A quantidade de bilhetes solicitada nao e valida.\n");
		return 0; 
	}

	totalPrice = calcTotalPrice(totalTickets);
	printf("O preco total e: R$%.2f\n", totalPrice);

	return 0;

}
