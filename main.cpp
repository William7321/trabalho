#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
	char reserva[10][6] = {
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '}
	};
	
	 int fileira = -1, assento = -1;
    char poltrona = ' ';
    char continuar;

    do {
        char tipo_passagem[20];
        printf("\nDigite o tipo de passagem (Econômica ou Executiva): ");
        scanf("%s", tipo_passagem);
        
        for (int i = 0; tipo_passagem[i]; i++) {
            tipo_passagem[i] = tolower(tipo_passagem[i]);
        }
	
	while (true){	
		printf("\nDigite a fileira (1-10): ");
		scanf("%d", &fileira);
		printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
		scanf(" %c", &poltrona);
		poltrona = toupper(poltrona);
		
		switch(poltrona){
			case 'A':
				assento = 0;
				break;
			case 'B':
				assento = 1;
				break;
			case 'C':
				assento = 2;
				break;
			case 'D':
				assento = 3;
				break;
			case 'E':
				assento = 4;
				break;
			case 'F':
			    assento = 5;
				break;
			default:
				printf("\nPoltrona invalida");
				break;
		}
	 if (reserva[fileira - 1][assento] == 'x') {
                printf("Esse assento já está reservado. Por favor, escolha outro.\n");
                continue;
            }

            if (strcmp(tipo_passagem, "econômica") == 0 && (poltrona == 'A' || poltrona == 'F')) {
                printf("Poltronas A e F são exclusivas para a classe Executiva.\n");
                continue;
            } else if (strcmp(tipo_passagem, "executiva") == 0 && (poltrona != 'A' && poltrona != 'F')) {
                printf("Recomendamos as poltronas A e F para a classe Executiva.\n");
            }
            
            reserva[fileira - 1][assento] = 'x';

            printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
            for (int x = 0; x < 10; x++) {
                if (x < 9) printf("\n\t0%d\t", x + 1);
                else printf("\n\t%d\t", x + 1);

                for (int y = 0; y < 6; y++) {
                    printf("[%c] ", reserva[x][y]);
                    if (y == 2) {
                        printf("\t");
                    }
                }
            }
            printf("\n");
            break;
        }

        printf("Deseja realizar outra reserva? (s/n): ");
        scanf(" %c", &continuar);
        continuar = tolower(continuar);

    } while (continuar == 's');

    printf("Encerrando o sistema de reservas...\n");
    return 0;
}