# Simulador de Banco Maravilha

Este projeto implementa um simulador de banco, permitindo criar contas, fazer depósitos, saques, transferências e consultar saldo. É um ótimo exemplo de como usar a linguagem C para gerenciar dados e realizar operações básicas de um sistema bancário.

## Funcionalidades

- **Criar Conta**: Permite criar uma nova conta bancária.
- **Depositar**: Permite adicionar dinheiro a uma conta existente.
- **Sacar**: Permite retirar dinheiro de uma conta existente.
- **Transferir**: Permite transferir dinheiro entre duas contas.
- **Consultar Saldo**: Permite verificar o saldo atual de uma conta.

## Como Usar

1. Clone o repositório:
    ```bash
    git clone https://github.com/seu_usuario/simulador-banco.git
    ```
2. Abra o projeto em sua IDE preferida. Certifique-se de que todos os arquivos necessários estejam na mesma pasta.

3. Compile o código:
    ```bash
    gcc -o simulador-banco banco.c
    ```
4. Execute o programa:
    ```bash
    ./simulador-banco
    ```

## Estrutura do Projeto

- **main.c**: Contém a implementação principal do simulador de banco.
- **Funções**:
  - `void exibirMenu(void)`: Exibe o menu principal para o usuário.
  - `void entrada(struct Dados contas[], int *numPessoas)`: Adiciona uma nova conta bancária.
  - `int verificar(struct Dados contas[], int *numPessoas)`: Verifica se uma conta existe.
  - `int deposito(struct Dados contas[], int conta)`: Realiza um depósito em uma conta.
  - `int saque(struct Dados contas[], int conta)`: Realiza um saque de uma conta.
  - `int transferir(struct Dados contas[], int *numPessoas)`: Realiza uma transferência entre contas.

## Exemplo de Uso

Ao executar o programa, será apresentada a seguinte interface de menu:

### Criar Conta

O usuário será solicitado a inserir o nome do titular, o número da conta e o saldo inicial.

### Depositar

O usuário será solicitado a inserir o número da conta e o valor a ser depositado.

### Sacar

O usuário será solicitado a inserir o número da conta e o valor a ser sacado.

### Transferir

O usuário será solicitado a inserir o número das contas de origem e destino, e o valor a ser transferido.

### Consultar Saldo

O usuário será solicitado a inserir o número da conta para verificar o saldo atual.

## Contribuindo

Se você quiser contribuir com este projeto, sinta-se à vontade para abrir pull requests e issues. Toda ajuda é bem-vinda!


## Contato

Para mais informações, entre em contato via [mb685212@gmail.com](mailto:mb685212@gmail.com).


