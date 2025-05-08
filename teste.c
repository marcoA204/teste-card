#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Item
{
    char nome[30];
    float preco;
};


int main() {

    setlocale(LC_ALL, "portuguese");

   struct Item cardapio[] = 
   {
    {"Pao frances", 0.50},
    {"Pao de queijo", 1.00},
    {"Pao  de coco", 0.50},
    {"cafe pequeno", 3.00},
    {"Suco natural", 3.50},
    {"Bolo de fuba", 5.00},
   };
   
   int numItens = sizeof(cardapio)/sizeof(cardapio[0]);
   int continuarAtendimento = 1;

   while (continuarAtendimento){
    int opcao, quantidade;
    int quantidades[6] = {0};
    float total = 0.0;

   printf("================\n");
   printf("     BEM-VINDO A PADARIA DO SEU ZE      \n");
   printf("   aqui esta o nosso carpadio:\n ");

   for (int i = 0; i < numItens; i++)
   {
        printf("%d - %-20s - R$ %.2f\n", i + 1, cardapio[i].nome, cardapio[i].preco);
   }
   printf("0 - Finalizar pedido\n");

   do
   {
    printf("\nEscolha um item do cardapio (0 para finalizar): ");
    scanf("%d", &opcao);

    if(opcao >= 1 && opcao <= numItens){
        printf("Quantidade de %s: ", cardapio[opcao - 1]. nome);
        scanf("%d", &quantidade);

        if (quantidade < 0)
        {
            printf("Quantidade Invalida! Tente novamente.\n");
            continue;
        }
        quantidades[opcao - 1] += quantidade;
        total += quantidade * cardapio[opcao - 1].preco;
        
    }else if (opcao != 0)
    {
       printf("Opcao invalida! Tente novamente.\n");
    }
    
   } while (opcao != 0);
   
   printf("\n======= RESUMO DO PEDIDO =======\n");
   for (int i = 0; i < numItens; i++)
   {
    if (quantidades[i] > 0)
    {
        printf("%dx %-20s - R$ %.2f\n", quantidades[i], cardapio[i].nome, quantidades[i] * cardapio[i].preco);
    }
    
    
   }
   printf("-----------------------\n");
   printf("Total a pagar: R$ %.2f\n", total);

   float desconto = 0.0;
   if (total >= 100)
   {
    desconto = total * 0.10;
    printf(" Desconto de 10%% aplicado!\n");
   }else if (total >= 50)
   {
    desconto = total * 0.05;
    printf("Desconto de 5%% aplicado!\n");
   }
   total -= desconto;

   int forma;
   printf("\n Formas de pagamento: \n");
   printf("1 - Dinheiro\n");
   printf("2 - Cartao\n");
   printf("3 - PIX (5%% de desconto extra)\n");
   printf("Escolha a forma de pagamento: ");
   scanf("%d", &forma);

   if (forma == 3)
   {
    float descontoPIX = total * 0.05;
    total -= descontoPIX;
    printf ("Desconto adicional de 5%% para pagamento via PIX: R$ %.2f\n", descontoPIX);
   }
   

   float pago;
   printf("Informe o valor a pago: R$ ");
   scanf("%f", &pago);

   if (pago < total)
   {
    printf("Valor insuficiente. Faltam R$ %.2f\n", pago - total);
   }else{
    printf("troco: R$ %.2f\n", pago - total);
    printf("\n obrigado pela preferencia! Volte sempre!\n");
   }

   printf ("\n deseja atender um novo cliente? (1 - sim / 0 - nao):");
   scanf("%d", &continuarAtendimento);

   printf("\nEncerrando sistema da padaria. ate logo!\n");
   }
   return 0;
}