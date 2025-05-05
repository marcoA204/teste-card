#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "portuguese");

    int card;
    int opcao;
    int ola;
    int quantidade;
    float total = 0;

    printf("Bem vindo! a padaria do seu Ze\n");
    printf("O que gostaria do nosso carpadio");
    scanf("%d %d", &ola, &card);

    printf("====PADARIA DO SEU ZE ====\n");
    printf("1 - Pão frances         - R$ 0.50\n");
    printf("2 - Pão de queijo       - R$ 2.00\n");
    printf("3 - Pão de coco         - R$ 0.50\n");
    printf("4 - Café pequeno        - R$ 3.00\n");
    printf("5 - Suco Natural        - R$ 4.50\n");
    printf("6 - Bolo de fuba        - R$ 4.00\n");

    printf("0 - Finalizar pedido\n");

    do
    {
        printf("\nEscolha um item do cardápio (0 para sair):");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Quantidade de Pão frances: ");
            scanf("%d", &quantidade);
            total += quantidade * 0.50;
            break;
        case 2:
            printf("Quantidade de Pão de queijo: ");
            scanf("%d", &quantidade);
            total += quantidade * 2.00;
            break;
        case 3:
            printf("Quantidade de Pão de coco: ");
            scanf("%d", &quantidade);
            total += quantidade * 0.50;
            break;
        case 4:
            printf("Unidade Café pequeno: ");
            scanf("%d", &quantidade);
            total += quantidade * 3.00;
            break;
        case 5:
            printf("Unidades de Suco natural: ");
            scanf("%d", &quantidade);
            total += quantidade * 4.50;
            break;
        case 6: 
            printf("Unidade de Bolo de fuba: ");
            scanf("%d", &quantidade);
            total += quantidade * 4.00;
            break;
        case 0:
            printf("\nPedido finalizado.\n");
            break;
        default:
            printf("Opçao inválida! Tente novamente.\n");    
            break;
        }

    } while (opcao != 0);

    printf("Total a pagar: R$ %.2f\n", total);
    printf("Obrigado pela preferencia!\n");
    

    return 0;
}
