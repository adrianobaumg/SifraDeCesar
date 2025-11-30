#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_caracter 100

void deixar_maiuscula(char *pal) {
    for (int i = 0; pal[i] != '\0'; i++) {
        pal[i] = toupper(pal[i]);
    }
}

void criptografar(char *frase, int nivel) {
    printf("\nFrase Criptografada: ");

    for (int i = 0; frase[i] != '\0'; i++) {

        if (frase[i] >= 'A' && frase[i] <= 'Z') {
            char letra = frase[i] + nivel;

            if (letra > 'Z') {
                letra = letra - 26;
            }
            printf("%c", letra);
        } else {
            // Mantém espaços, vírgulas, números etc.
            printf("%c", frase[i]);
        }
    }
}

int main() {
    int nivel = 0;
    char frase[max_caracter];

    printf("Nivel da criptografia (1 a 3): ");
    scanf("%d", &nivel);
    getchar();

    printf("Frase para criptografar: ");
    fgets(frase, max_caracter, stdin);

    deixar_maiuscula(frase);
    criptografar(frase, nivel);

    printf("\n");
    return 0;
}
