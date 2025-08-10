#include <stdio.h>
#include <locale.h> 		//biblioteca de linguagem padrão

int num, ult_dig;

main(){
	setlocale(LC_ALL,"PORTUGUESE");
	
	printf("Digite o número: ");
	scanf("%i", &num);
	ult_dig = num%10;
	printf("O último digito do número é %i", ult_dig);
								
}
	
