#include <stdio.h>

int main (void)

{

    int cont = 0;

    while (cont < 10)

    {   

        printf("%d ", cont);

   if (cont == 5) continue;       

   cont++;

  

    }

    printf("fim\n");

    return 0;

}