#include <stdio.h>   // Inclui a biblioteca padrão de entrada e saída para usar funções como printf e scanf.
#include <string.h>  // Inclui a biblioteca para manipulação de strings, permitindo o uso de strlen e fgets.
#include <ctype.h>   // Inclui a biblioteca para funções de caracteres, como toupper.

#define max_caracter 100

void deixar_maiuscula(char *pal) {
    // Função para converter todos os caracteres da string para maiúsculas.
    for(int numero = 0; numero < strlen(pal); numero++) {  // Loop para percorrer cada caractere da string.
        pal[numero] = toupper(pal[numero]);  // Converte o caractere atual para maiúscula e o atribui de volta à string.
    }
}

int main () {
    int var = 0;         // Declara uma variável inteira para armazenar o nível de criptografia.
    char frase[max_caracter];      // Declara um array de caracteres para armazenar a frase de até 29 caracteres mais o caractere nulo.

    printf("Nivel da criptografia (1 a 3): ");  // Solicita ao usuário o nível de criptografia.
    scanf("%d", &var);   // Lê o nível de criptografia fornecido pelo usuário e armazena na variável 'var'.
    getchar();           // Consome o caractere de nova linha deixado no buffer pelo scanf.

    printf("Frase para criptografar: ");  // Solicita ao usuário a frase que será criptografada.
    fgets(frase, 30, stdin);  // Lê a frase do usuário, permitindo um máximo de 29 caracteres mais o caractere nulo.

    deixar_maiuscula(frase);  // Converte todos os caracteres da frase para maiúsculas usando a função deixar_maiuscula.

    printf("\nFrase Criptografada: ");  // Exibe uma mensagem indicando que a frase criptografada será mostrada.

    // Loop para percorrer cada caractere da string e aplicar a criptografia simples.
    for(int i = 0; i <= strlen(frase); i++) {
        // Verifica se o caractere atual, após a criptografia, ultrapassará o caractere 'Z'.
        if(frase[i] + var >= 'Z') { 
            // Se ultrapassar, ajusta o caractere para se manter dentro do intervalo das letras maiúsculas.
            printf("%c", frase[i] - 26 + var);
        } else {
            // Caso contrário, apenas adiciona o valor do nível de criptografia ao caractere.
            printf("%c", frase[i] + var);
        }
    }

    printf("\n");  // Imprime uma nova linha após a frase criptografada.

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso.
}
