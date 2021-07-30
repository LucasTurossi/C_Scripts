#include<stdio.h>

 
    int main(void)
    {
      int contador;
      int produto;
      int soma;
      char nome[61];
    do 
    {
      printf("Você deseja reiniciar o programa? (Se não, digite NÃO)");
      scanf ("%i", &contador );

      if(contador != 3){
        contador = 1;
      }

      printf("Digite seu nome: ");
      scanf("%s",nome);
      
      printf("Nome do cliente: %s \n", nome);
      
    printf ("Digite o código do produto, de 1 a 10:");
    scanf ("%i", &produto);

    switch ( produto )
    {

      case 1:
        printf ("Arroz\nValor:R$ 5,50");
        break;
      case 2:
        printf ("Feijãão\nValor:R$ 7,25");
        break;
      case 3:
        printf ("Açúcar\nValor:R$ 4,99");
        break;
      case 4:
        printf ("Sal\nValor:R$ 2,15");
        break;
      case 5:
        printf ("Leite\nValor:R$ 3,20");
        break;
      case 6:
        printf ("Macarrão\nValor:R$ 6,45");
        break;
      case 7:
        printf ("Erva-mate\nValor:R$ 13,50");
        break;
      case 8:
        printf ("Café\nValor:R$ 12,10");
        break;
      case 9:
        printf ("Farinha de Trigo\nValor:R$ 2,89");
        break;
      case 10:
        printf ("Ervilha\nValor:R$ 6,45");
        break;
      default:
        printf ("Valor inválido");
    }    
    }while (contador == 1);
      main();
    }