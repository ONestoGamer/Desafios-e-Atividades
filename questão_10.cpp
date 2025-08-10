#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>

char op, nomeHospital[50];
int nroLeitos, nroDias, nroHabitantes, nroDiarias;
float nroInfectados, txOcupacao, nroContaminados;

   #define NRO_DIAS_INT 14
main(){
	setlocale(LC_ALL,"PORTUGUESE");  

     printf("Informe o nome do Hospital: ");
     gets(nomeHospital); 
     printf("Informe o Nro de leitos: ");
     scanf("%i", &nroLeitos);
     printf("Informe Nro de Dias: ");
     scanf("%i", &nroDias);
     printf("Informe Nro Habitantes: ");
     scanf("%i", &nroHabitantes);
     nroDiarias = (nroLeitos*nroDias)/NRO_DIAS_INT;    //sempre um nro inteiro
     printf("\nNro de Diarias: %i", nroDiarias);
     printf("\n\nEscolha abaixo o cenário em termo de taxa de infecção (%%)\npara o calculo da Taxa de Ocupação\n\n");
     printf("1-0,01%% | 2-0,10%% | 3-1%% | 4-10%% | 5-20%% | 6-40%%\n\nOpção: ");
     op=getche();
     
     switch(op){
           case '1':
                nroInfectados=(float) nroHabitantes*0.0001;
                break;
           case '2':
                nroInfectados=(float)nroHabitantes*0.001;
                break;
           case '3':
                nroInfectados=(float)nroHabitantes*0.01;
                break;
           case '4':
                nroInfectados=(float)nroHabitantes*0.1;
                break;
           case '5':
                nroInfectados=(float)nroHabitantes*0.2;
                break;
           case '6':
                nroInfectados=(float)nroHabitantes*0.4;
                break;
           default:
                printf("\n Operação Inválida!\n");

        }

    if (nroInfectados!=0)
        txOcupacao = (float) ((nroInfectados/nroDiarias)*100);
     else
        txOcupacao = 0;
        
 printf("\nNro de Infectados ==> %.1f \nTaxa de Ocupação ==> %.2f%%\n", nroInfectados, txOcupacao);    
     if (txOcupacao <= 50)
           printf("\nOcupação Normal");

       if (txOcupacao > 50 && txOcupacao <= 75)
           printf("\nOcupação Média (Alerta Amarelo)");

     if (txOcupacao > 75)
           printf("\nOcupação Alta (Alerta Vermelho)");

     if (txOcupacao > 100)
           printf("\nAtenção: Eminente Colapso no sistema de saúde, Emergência!");
}

