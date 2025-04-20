#include <stdio.h>
#include <stdlib.h>

int verifyEntry(int quantidade) {
    if (quantidade > 5) {
        printf("Quantidade de bilhetes excede o limite permitido.\n");
        return 0;
    }
    return 1;
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

int getAge(int index) {
	int age;
	printf("Digite a idade do visitante %d: ", index+1);
	scanf("%d", &age);
	return age;
}

// int calcTotalPrice(int totalTickets) {
	
// 	int age, price;
// 	float totalPrice;

// 	for (int i = 0; i < totalTickets; i++)
// 	{
// 		age 		= getAge(i);
// 		price 		= getPrice(age);
// 		totalPrice += (float) price;
// 	}

// 	return totalPrice;
// }

float calcTotalPrice(int totalTickets) {
    float totalPrice = 0.0f; // Inicializa corretamente
    for (int i = 0; i < totalTickets; i++) {
        int age = getAge(i);
        int price = getPrice(age);
        totalPrice += (float)price;
    }
    return totalPrice;
}

int getTotalTickets() {
	int totalTickets;
	printf("Digite a quantidade de bilhetes a serem comprados: ");
	scanf("%d", &totalTickets);
	return totalTickets;
}
