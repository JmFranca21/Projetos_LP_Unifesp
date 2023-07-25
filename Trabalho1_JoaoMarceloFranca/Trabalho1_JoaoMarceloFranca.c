#include <stdio.h>

int main() 
{
  int menu, MD, MV, PD, PV, FD, FV, QD, QV, CD, CV, i, j, k, compras, x1, x2, x3, x4, x5, confirm, desc, l;
  MD = 10;
  MV = 0;
  PD = 10;
  PV = 0;
  FD = 10;
  FV = 0;
  QD = 10;
  QV = 0;
  CD = 10;
  CV = 0;
  i = 0;
  
  while (i < 1)
    { 
      j = 0;
      
    system ("clear");  
    printf ("O que você deseja fazer?\n");
    printf ("1) Mostrar total de unidades e valor de cada categoria.\n");
    printf ("2) Mostrar descrição da categoria.\n");
    printf ("3) Comprar livros.\n");
    printf ("4) Total vendido e montante em caixa.\n");
    printf ("5) Encerrar.\n\n");
    scanf ("%d", &menu);
    
    switch (menu)
      {
        
        case 1 :
          while (j < 1)
          {
            system("clear");
            printf("                                Disponível    Vendido    Código    Valor\n");
            printf("Matemática                          %d          %d          1      R$ 150,00\n", MD, MV);
            printf("Probabilidade e Estatística         %d          %d          2      R$ 100,00\n", PD, PV);
            printf("Física                              %d          %d          3      R$ 160,00\n", FD, FV);
            printf("Química                             %d          %d          4      R$ 160,00\n", QD, QV);
            printf("Computação                          %d          %d          5      R$ 200,00\n\n", CD, CV);
            printf("Para voltar ao menu principal, pressione 1.\n");
            scanf("%d", &j);
            if (j == 1)
              j++;
          }          
        break;
        
        case 2 :
          while (j < 1)
          {
            l = 0;
            system("clear");
            printf("ESCOLHA A CATEGORIA DESEJADA:\n\n");
            printf("1) Matemática.\n");
            printf("2) Probabilidade e Estatística.\n");
            printf("3) Física.\n");
            printf("4) Química.\n");
            printf("5) Computação.\n");
            printf("6) Voltar ao menu principal.\n");
            scanf("%d", &desc);
            switch (desc)
              {
                case 1 :
                  while (l < 1)
                    {
                      system("clear");
                      {
                        FILE *fp;
                        char ch[5];
              
                        fp = fopen("matematica.txt", "r");
              
                        while (fgets(ch, 5, fp) != NULL)
                        printf("%s", ch);
              
                        fclose(fp);
                      }
                      printf("\n\n");
                      printf("Digite 1 para voltar ao menu de descrições.");
                      scanf("%d", &l);
                      if ( l == 1);
                      l++;
                    }
                break;

                case 2 :
                  while (l < 1)
                    {
                      system("clear");
                      {
                        FILE *fp;
                        char ch[5];
              
                        fp = fopen("probabilidade.txt", "r");
              
                        while (fgets(ch, 5, fp) != NULL)
                        printf("%s", ch);
              
                        fclose(fp);
                      }
                      printf("\n\n");
                      printf("Digite 1 para voltar ao menu de descrições.");
                      scanf("%d", &l);
                      if ( l == 1);
                      l++;
                    }
                break;

                case 3 :
                  while (l < 1)
                    {
                      system("clear");
                      {
                        FILE *fp;
                        char ch[5];
              
                        fp = fopen("fisica.txt", "r");
              
                        while (fgets(ch, 5, fp) != NULL)
                        printf("%s", ch);
              
                        fclose(fp);
                      }
                      printf("\n\n");
                      printf("Digite 1 para voltar ao menu de descrições.");
                      scanf("%d", &l);
                      if ( l == 1);
                      l++;
                    }
                break;

                case 4 :
                  while (l < 1)
                    {
                      system("clear");
                      {
                        FILE *fp;
                        char ch[5];
              
                        fp = fopen("quimica.txt", "r");
              
                        while (fgets(ch, 5, fp) != NULL)
                        printf("%s", ch);
              
                        fclose(fp);
                      }
                      printf("\n\n");
                      printf("Digite 1 para voltar ao menu de descrições.");
                      scanf("%d", &l);
                      if ( l == 1);
                      l++;
                    }
                break;

                case 5 :
                  while (l < 1)
                    {
                      system("clear");
                      {
                        FILE *fp;
                        char ch[5];
              
                        fp = fopen("computacao.txt", "r");
              
                        while (fgets(ch, 5, fp) != NULL)
                        printf("%s", ch);
              
                        fclose(fp);
                      }
                      printf("\n\n");
                      printf("Digite 1 para voltar ao menu de descrições.");
                      scanf("%d", &l);
                      if ( l == 1);
                      l++;
                    }
                break;
                
                case 6 :
                j++;
                break;
              }
          } 
        break;
        
        case 3 :
          while(j < 1)
            {
              k = 0;
              system("clear");
              printf("SELECIONE A CATEGORIA DE LIVRO QUE DESEJA COMPRAR:\n");
              printf("1) Matemática.\n");
              printf("2) Probabilidade e Estatística.\n");
              printf("3) Física.\n");
              printf("4) Química.\n");
              printf("5) Computação.\n");
              printf("6) Voltar ao menu principal.\n");
              scanf("%d", &compras);
              switch (compras)
                {
                  case 1 :
                    while (k == 0)
                      {
                        system("clear");
                        printf("Quantos livros você deseja comprar?\n");
                        scanf("%d", &x1);
                        if ((x1 <= MD) && (x1 > 0)) //MD = matematica disponivel e MV = Matematica vendido
                        {
                          printf("Valor a ser pago = R$%d,00.\n\n", x1 * 150);
                          printf("Para CONFIRMAR a compra digite 1;\n");
                          printf("Para CANCELAR a compra digite 2;\n");
                          scanf("%d", &confirm);
                            switch (confirm)
                            {
                              case 1 :
                                MD = MD - x1;
                                MV = MV + x1;
                                printf("VENDA EFETIVADA!\n\n");
                              break;
                              
                              case 2 :
                                printf("VENDA NÃO EFETIVADA!\n\n");                          
                              break;
                            }
                        }
                        else if (x1 <= 0)
                        {
                          printf("VALOR INVÁLIDO!\n\n");
                          printf("VENDA NÃO EFETIVADA!\n\n");
                        }
                        else
                        {
                          if (MD == 0)
                          {
                            printf("Não há mais unidades disponíveis na categoria selecionada.\n\n");
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                          else
                          {
                            printf("Há apenas %d unidade(s) disponíveis na categoria selecionada.\n\n", MD);
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                        }
                        printf("Digite 1 para voltar ao menu de compras.\n");
                        scanf("%d", &k);
                        if (k == 1);
                        k++;
                      }
                  break;
                  
                  case 2 :
                    while (k == 0)
                      {
                        system("clear");
                        printf("Quantos livros você deseja comprar?\n");
                        scanf("%d", &x2);
                        if ((x2 <= PD) && (x2 > 0))
                        {
                          printf("Valor a ser pago = R$%d,00.\n\n", x2 * 100);
                          printf("Para CONFIRMAR a compra digite 1;\n");
                          printf("Para CANCELAR a compra digite 2;\n");
                          scanf("%d", &confirm);
                            switch (confirm)
                            {
                              case 1 :
                                PD = PD - x2;
                                PV = PV + x2;
                                printf("VENDA EFETIVADA!\n\n");
                              break;
                              
                              case 2 :
                                printf("VENDA NÃO EFETIVADA!\n\n");                          
                              break;
                            }
                        }
                        else if (x2 <= 0)
                        {
                          printf("VALOR INVÁLIDO!\n\n");
                          printf("VENDA NÃO EFETIVADA!\n\n");
                        }
                        else
                        {
                          if (PD == 0)
                          {
                            printf("Não há mais unidades disponíveis na categoria selecionada.\n\n");
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                          else
                          {
                            printf("Há apenas %d unidade disponíveis na categoria selecionada.\n\n", PD);
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                        }
                        printf("Digite 1 para voltar ao menu de compras.\n");
                        scanf("%d", &k);
                        if (k == 1)
                        k++;
                      }
                  break;
                  
                  case 3 :
                     while (k == 0)
                      {
                        system("clear");
                        printf("Quantos livros você deseja comprar?\n");
                        scanf("%d", &x3);
                        if ((x3 <= FD) && (x3 > 0))
                        {
                          printf("Valor a ser pago = R$%d,00.\n\n", x3 * 160);
                          printf("Para CONFIRMAR a compra digite 1;\n");
                          printf("Para CANCELAR a compra digite 2;\n");
                          scanf("%d", &confirm);
                            switch (confirm)
                            {
                              case 1 :
                                FD = FD - x3;
                                FV = FV + x3;
                                printf("VENDA EFETIVADA!\n\n");
                              break;
                              
                              case 2 :
                                printf("VENDA NÃO EFETIVADA!\n\n");                          
                              break;
                            }
                        }
                          else if (x3 <= 0)
                        {
                          printf("VALOR INVÁLIDO!\n\n");
                          printf("VENDA NÃO EFETIVADA!\n\n");
                        }
                        else
                        {
                          if (FD == 0)
                          {
                            printf("Não há mais unidades disponíveis na categoria selecionada.\n\n");
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                          else
                          {
                            printf("Há apenas %d unidade disponíveis na categoria selecionada.\n\n", FD);
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                        }
                        printf("Digite 1 para voltar ao menu de compras.\n");
                        scanf("%d", &k);
                        if (k == 1)
                        k++;
                      }
                  break;
                  
                  case 4 :
                   while (k == 0)
                      {
                        system("clear");
                        printf("Quantos livros você deseja comprar?\n");
                        scanf("%d", &x4);
                        if ((x4 <= QD) && (x4 > 0))
                        {
                          printf("Valor a ser pago = R$%d,00.\n\n", x4 * 160);
                          printf("Para CONFIRMAR a compra digite 1;\n");
                          printf("Para CANCELAR a compra digite 2;\n");
                          scanf("%d", &confirm);
                            switch (confirm)
                            {
                              case 1 :
                                QD = QD - x4;
                                QV = QV + x4;
                                printf("VENDA EFETIVADA!\n\n");
                              break;
                              
                              case 2 :
                                printf("VENDA NÃO EFETIVADA!\n\n");                          
                              break;
                            }
                        }
                        else if (x4 <= 0)
                        {
                          printf("VALOR INVÁLIDO!\n\n");
                          printf("VENDA NÃO EFETIVADA!\n\n");
                        }
                        else
                        {
                          if (QD == 0)
                          {
                            printf("Não há mais unidades disponíveis na categoria selecionada.\n\n");
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                          else
                          {
                            printf("Há apenas %d unidade disponíveis na categoria selecionada.\n\n", QD);
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                        }
                        printf("Digite 1 para voltar ao menu de compras.\n");
                        scanf("%d", &k);
                        if (k == 1);
                        k++;
                      }
                  break;
                  
                  case 5 :
                    while (k == 0)
                      {
                        system("clear");
                        printf("Quantos livros você deseja comprar?\n");
                        scanf("%d", &x5);
                        if ((x5 <= CD) && (x5 > 0))
                        {
                          printf("Valor a ser pago = R$%d,00.\n\n", x5 * 200);
                          printf("Para CONFIRMAR a compra digite 1;\n");
                          printf("Para CANCELAR a compra digite 2;\n");
                          scanf("%d", &confirm);
                            switch (confirm)
                            {
                              case 1 :
                                CD = CD - x5;
                                CV = CV + x5;
                                printf("VENDA EFETIVADA!\n\n");
                              break;
                              
                              case 2 :
                                printf("VENDA NÃO EFETIVADA!\n\n");                          
                              break;
                            }
                        }
                        else if (x5 <= 0)
                        {
                          printf("VALOR INVÁLIDO!\n\n");
                          printf("VENDA NÃO EFETIVADA!\n\n");
                        }
                        else
                        {
                          if (CD == 0)
                          {
                            printf("Não há mais unidades disponíveis na categoria selecionada.\n\n");                            
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }
                          else
                          {
                            printf("Há apenas %d unidade disponíveis na categoria selecionada.\n\n", CD);
                            printf("VENDA NÃO EFETIVADA\n\n");
                          }                          
                            
                        }
                        printf("Digite 1 para voltar ao menu de compras.\n");
                        scanf("%d", &k);
                        if (k == 1);
                        k++;
                      }
                  break;
                  case 6 :
                    j++;
                  break;
                  
                  default :
                    system ("clear");
                    printf("Valor inválido! Por favor, digite 1 para voltar ao menu de compras.\n\n");
                    scanf("%d", &k);
                    if (k == 1)
                    k++;
                  break;
                }                           
            }
        break;
        case 4 :
          while (j < 1)
          {
            system("clear");
            printf("Total de livros vendidos = %d.\n\n", (MV + PV + FV + QV + CV));
            printf("Montante em caixa = R$%d,00.\n\n", ((MV * 150) + (PV * 100) + (FV * 160) + (QV * 160) + (CV * 200)));
            printf("Para voltar ao menu principal digite 1.\n");
            scanf("%d", &j);
            if (j == 1)
            j++;
          }
        break;
        
        case 5 :
          i++;
        break;

        default :
          system ("clear");
          printf("Valor inválido! Por favor digite 1 para voltar ao menu principal.");
          scanf("%d", &j);
          if (j == 1)
            j++;
      }
    }
  return 0;
}