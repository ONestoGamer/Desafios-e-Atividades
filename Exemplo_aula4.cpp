#include <stdio.h>
#include <locale.h> 		//biblioteca de linguagem padr�o

int num, ult_dig;

main(){
	setlocale(LC_ALL,"PORTUGUESE");
	
	printf("Digite o n�mero: ");
	scanf("%i", &num);
	ult_dig = num%10;
	printf("O �ltimo digito do n�mero � %i", ult_dig);
								
}
	
