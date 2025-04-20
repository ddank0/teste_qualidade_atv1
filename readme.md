# Documentação de Casos de Teste

## 1. Função verifyEntry (quantidade de bilhetes)

| Classe | Descrição | Valores | Casos de Teste | Status Esperado |
|--------|-----------|---------|----------------|-----------------|
| Válida | Quantidade dentro do limite | 1-5 | 1, 3, 5 | Válido (1) |
| Inválida | Quantidade acima do limite | >5 | 6, 10 | Inválido (0) |
| Inválida | Quantidade zero ou negativa | <=0 | 0, -1 | Inválido (0) |

## 2. Função getPrice (idade do visitante)

| Classe | Descrição | Valores | Casos de Teste | Status Esperado |
|--------|-----------|---------|----------------|-----------------|
| Criança | Até 12 anos | 0-12 | 0, 6, 12 | R$10.00 |
| Adulto | 13 a 59 anos | 13-59 | 13, 30, 59 | R$30.00 |
| Idoso | 60 anos ou mais | >=60 | 60, 65, 100 | R$15.00 |
| Inválida | Idade negativa | <0 | -1, -10 | Inválido |

## 3. Função calcTotalPrice (cálculo do total)

| Classe | Descrição | Valores | Casos de Teste | Status Esperado |
|--------|-----------|---------|----------------|-----------------|
| Válida | Um bilhete | 1 bilhete | Criança (10) | R$10.00 |
| Válida | Múltiplos bilhetes | 2-5 bilhetes | 2 bilhetes (criança + adulto) | R$40.00 |
| Válida | Múltiplos bilhetes | 2-5 bilhetes | 3 bilhetes (criança + adulto + idoso) | R$55.00 |
| Inválida | Quantidade inválida | >5 bilhetes | 6 bilhetes | Inválido |

## Casos de Teste Detalhados

### 1. Teste de Quantidade de Bilhetes
- Entrada: 1 bilhete → Saída: Válido
- Entrada: 3 bilhetes → Saída: Válido
- Entrada: 5 bilhetes → Saída: Válido
- Entrada: 6 bilhetes → Saída: Inválido
- Entrada: 0 bilhetes → Saída: Inválido
- Entrada: -1 bilhete → Saída: Inválido

### 2. Teste de Preços por Idade
- Idade: 0 anos → Preço: R$10.00
- Idade: 12 anos → Preço: R$10.00
- Idade: 13 anos → Preço: R$30.00
- Idade: 30 anos → Preço: R$30.00
- Idade: 59 anos → Preço: R$30.00
- Idade: 60 anos → Preço: R$15.00
- Idade: 65 anos → Preço: R$15.00
- Idade: -1 ano → Preço: Inválido

### 3. Teste de Cálculo de Total
- 1 bilhete (criança) → Total: R$10.00
- 2 bilhetes (criança + adulto) → Total: R$40.00
- 3 bilhetes (criança + adulto + idoso) → Total: R$55.00
- 5 bilhetes (2 crianças + 2 adultos + 1 idoso) → Total: R$95.00
- 6 bilhetes → Total: Inválido

## Valores Limite

### 1. Quantidade de bilhetes
- Limite inferior: 1
- Limite superior: 5
- Valores próximos: 0, 1, 5, 6

### 2. Idade
- Limite criança: 0, 12, 13
- Limite adulto: 12, 13, 59, 60
- Limite idoso: 59, 60, 100

## Execução dos testes
    gcc -DTESTING -I. -o test test/test.c src/ticketFunctions.h test/minunit/minunit.h && .\test.exe
