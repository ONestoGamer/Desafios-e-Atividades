#include <stdio.h>      //bibliotecas
#include <locale.h>
#include <stdlib.h>
#include <time.h>
/* instruções para o desafio
- Crie um programa em C++ que:
- Gera um número aleatório entre 1 e 20 (inclusive);
- Imprime esse número na tela;
- Se o número for maior que 15, imprime "Acertou!", caso contrário imprime "Errou!";
- Toda a lógica principal deve estar dentro de uma função chamada verificarSorteio();
- O programa deve ser bem organizado e conter comentários explicativos.*/

	//função
		int verificarsorteio(){
		//semente
		srand(time(NULL));			
		int numero = ((rand()) % 21);		 
		return numero;
	}	

int main(){
	setlocale(LC_ALL,"PORTUGUESE");
	
int num1;
num1 = verificarsorteio();

//inicio
srand(time(NULL));		//semente

printf("%i\n ", num1);		//gera um número aleatório entre 1 e 20
if (num1 > 15)
    printf("Acertou miseravi!");	//mensagem caso o número seja maior que 15
else 
    printf("Não foi dessa vez!");	//mensagem caso o número não seja maior que 15

return 0;

}
