#include <stdio.h>
#include <stdlib.h>

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

int verifyEntry(int quantidade) {
    if (quantidade > 5) {
        printf("Quantidade de bilhetes excede o limite permitido.\n");
        return 0; // Quantidade inválida
    }
    return 1; // Quantidade válida
}

int getPrice(int idade) {
    if (idade <= 12) {
        return 10; // Preço com desconto para crianças
    } else if (idade >= 60) {
        return 15; // Preço com desconto para idosos
    } else {
        return 30; // Preço normal para adultos
    }
}

int calcTotalPrice(int preco, int quantidade) {
    return preco * quantidade;
}

int getAge() {
	int age;
	printf("Digite a idade do visitante: ");
	scanf("%d", &age);
	return age;
}

int getTotalTickets() {
	int totalTickets;
	printf("Digite a quantidade de bilhetes a serem comprados: ");
	scanf("%d", &totalTickets);
	return totalTickets;
}

int main() {

    int age, totalTickets, price;

	float totalPrice;

    age 			= getAge();
	totalTickets 	= getTotalTickets();

    if (!verifyEntry(totalTickets)) {
		printf("Erro: A quantidade de bilhetes solicitada não é válida.\n");
		return 0; 
    }

    price = getPrice(age);

    totalPrice = (float) calcTotalPrice(price, totalTickets);

    printf("O preco total e: R$%.2f\n", totalPrice);

	return 0;

}