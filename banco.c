#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados{
    char nome[25];
    char numConta[25];
    double saldo;
};
void exibirMenu(void);
void entrada(struct Dados contas[], int *numPessoas);
int verificar(struct Dados contas[], int *numPessoas);
int deposito(struct Dados contas[], int conta);
int saque(struct Dados contas[], int conta);
int transferir(struct Dados contas[], int *numPessoas);

int main(void) {   
    struct Dados contas[100];
    int numPessoas = 0;
    int escolha;
    int indice;

    printf("\tBem vindo ao banco Maravilha\t\n");
    do { 
        exibirMenu();
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            entrada(contas, &numPessoas);
            break;
        case 2:
            indice = verificar(contas, &numPessoas);
                if (indice != -1) {
                    deposito(contas, indice);
                }
            break;
        case 3:
            indice = verificar(contas, &numPessoas);
                if (indice != -1) {
                    saque(contas, indice);
                }
            break;
        case 4:
            transferir(contas, &numPessoas);
            break;
        case 5:
            indice = verificar(contas, &numPessoas);
                if (indice != -1){
                    printf("Saldo atual: R$ %.2lf\n", contas[indice].saldo);
                }
            break;
        case 6:
        printf("Fechando o sistema...\n");
        break;
        default:
        printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    } while (escolha != 6);

    return 0;
}

int verificar(struct Dados contas[], int *numPessoas) {
    char entrada[25];
    printf("Digite o numero da conta que deseja fazer a operacao: ");
    scanf("%s", entrada);
    for (int i = 0; i < *numPessoas; i++) {
        if (strcmp(entrada, contas[i].numConta) == 0)
            return i; // Conta encontrada, retorna o indice 
    }  
    printf("\nConta nao encontrada!\n");
    printf("------------------------------------\n");
    return -1; // Conta não encontrada
}

void entrada(struct Dados contas[], int *numPessoas) {
    printf("Digite o nome do titular da conta: ");
    scanf("%s", contas[*numPessoas].nome);
    printf("Digite o numero da conta: ");
    scanf("%s", contas[*numPessoas].numConta);
    printf("Digite o valor inicial a ser inserido: ");
    scanf("%lf", &contas[*numPessoas].saldo);

    printf("\nConta registrada com sucesso!\n");
    printf("------------------------------------\n");
    (*numPessoas)++;
}

int deposito(struct Dados contas[], int conta) {
    double valor = 0;
    do {
        printf("Qual valor deseja depositar? ");
        scanf("%lf", &valor);
        if (valor <= 0)
            printf("\nPor favor, apenas depositos acima de R$0.00!\n");
        else {
            contas[conta].saldo += valor;
            printf("\nDeposito Realizado com sucesso! Saldo atual: R$ %.2lf\n", contas[conta].saldo);
            return 0; // Deposito Realizado
        }
    } while (valor <= 0);
    printf("------------------------------------\n");
    return -1; //Deposito falhou
}

int saque(struct Dados contas[], int conta) {
    double valor;

    printf("Qual valor deseja sacar? ");
    scanf("%lf", &valor);
    if (valor > contas[conta].saldo) {
        printf("Valor indisponivel para saque!\n");
        return -1;
    } else if (valor <= 0) {
        printf("Por favor insira um valor acima de R$0 para sacar\n");
    } else {
        contas[conta].saldo -= valor;
        printf("\nSaque no valor de R$ %.2lf realizado com sucesso!\n", valor);
        printf("\nSaldo atual: %.2lf\n", contas[conta].saldo);
        return 0;
    }
    printf("------------------------------------\n");
}

int transferir(struct Dados contas[], int *numPessoas) {
    char origem[25];
    char destino[25];
    double valor;
    int indiceOrigem, indiceDestino;

    // Solicitar número da conta de origem
    printf("Digite a conta 'origem' da transferencia: ");
    scanf("%s", origem);
    indiceOrigem = verificar(contas, numPessoas);
    if (indiceOrigem == -1) return -1;

    // Solicitar número da conta de destino
    printf("Digite a conta 'destino' da transferencia: ");
    scanf("%s", destino);
    indiceDestino = verificar(contas, numPessoas);
    if (indiceDestino == -1) return -1;

    // Solicitar valor da transferência
    printf("Qual valor deseja transferir? ");
    scanf("%lf", &valor);
    if (valor <= 0 || valor > contas[indiceOrigem].saldo) {
        printf("Transferencia invalida! Saldo insuficiente.\n");
        return -1;
    }

    // Realizar transferência
    contas[indiceOrigem].saldo -= valor;
    contas[indiceDestino].saldo += valor;
    printf("Transferencia realizada com sucesso!\n");

    return 0;
}



void exibirMenu() {
        printf("\n\t--- Menu Principal ---\t\n");
        printf("1. Criar conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Transferir\n");
        printf("5. Consultar saldo\n");
        printf("6. Sair\n");
        printf("O que gostaria de fazer hoje: \n"); 
}
