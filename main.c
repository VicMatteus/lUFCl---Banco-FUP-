#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//o programa tem interface
//havera menu e chat

int main()
{

    int ncriadas, nmax, n1, n2, n3, op, contaaux, contaaux2, tipoaux, achou, achou2;
    printf("Declare o numero de contas geridas\n");
    scanf("%d", &nmax);

    int conta[nmax];
    double saldo[nmax], cashaux;
    char tipo[35];
    ncriadas=0;

    do
    {
        printf("Escolha uma opcao\n");
        printf("1-credito\n");
        printf("2-debito\n");
        printf("3-transferencia\n");
        printf("4-consultar saldo\n");
        printf("5-criar conta\n");
        printf("0-sair\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1://credito
            {
                contaaux=0;
                cashaux=0;
                printf("Digite o numero da conta que recebera credito:\n");
                scanf("%d", &contaaux);
                achou=0;
                for(int i=0; i<ncriadas; i++)
                {
                    if(contaaux==conta[i])
                    {
                        printf("Digite o valor a ser creditado:\n");
                        scanf("%lf", &cashaux);
                        saldo[i] = saldo[i] + cashaux;
                        cashaux=0;
                        achou++;
                        printf("saldo atual: %.2lf\n", saldo[i]);
                    }
                }
                if(achou==0)
                {
                    printf("A conta informada nao existe!\n");
                }
            }
            break;

            case 2://debito
            {
                printf("Digite o numero da conta debitada:\n");
                scanf("%d", &contaaux);
                achou=0;
                for(int i=0; i<ncriadas; i++)
                {
                    if(contaaux==conta[i])
                    {
                        printf("Digite o valor a ser debitado:\n");
                        scanf("%lf", &cashaux);
                        saldo[i] = saldo[i] - cashaux;
                        cashaux=0;
                        achou++;
                    }
                }
                if(achou==0)
                {
                    printf("A conta informada nao existe!\n");
                }
            }
            break;

            case 3: //transferência
                achou=0;
                cashaux = 0;
                printf("Digite o numero da conta de origem:\n");
                scanf("%d", &contaaux);
                for(int i=0; i<ncriadas; i++)
                {
                    if(contaaux==conta[i])
                    {
                        achou++;
                        printf("Digite o valor a ser enviado:\n");
                        scanf("%lf", &cashaux);
                        if(saldo[i]>=cashaux);
                        {
                            printf("Digite o numero da conta de destino:\n");
                            scanf("%d", &contaaux2);
                            for(int k=0; k<ncriadas; k++)
                            {
                                if(conta[k]==contaaux2)
                                {
                                    saldo[k]=saldo[k]+cashaux;
                                    saldo[i]=saldo[i]-cashaux;
                                    achou2++;
                                }
                            }
                            if(achou2==0)
                            {
                                printf("A conta informada nao existe!\n");
                            }
                        }
                        if(saldo[i]<cashaux)
                        {
                            printf("Saldo insuficiente para transferencia");
                        }
                    }
                    if(i==ncriadas-1 && conta[i]!=contaaux && achou==0)
                    {
                        printf("Saldo insuficiente!");
                    }
                }
                if(achou==0)
                {
                    printf("A conta informada nao existe!\n");
                }
            break;

            case 4: //saldo
            {
                achou = 0;
                contaaux = 0;
                printf("Digite o numero da conta a ser consultada:\n");
                scanf("%d", &contaaux);
                for(int i=0; i<ncriadas; i++)
                {
                    if(contaaux==conta[i])
                    {
                        printf("%.2lf\n", saldo[i]);
                        achou++;
                    }
                }
                if(achou==0)
                {
                    printf("A conta informada nao existe!\n");
                }
            }
            break;

            case 5://criação de conta
            {
                contaaux=0;
                printf("Digite o numero da conta:\n");
                scanf("%d", &contaaux);
                achou=0;
                /*saldo[ncriadas] = 0;
                ncriadas++;*/
                for(int i = 0; i<ncriadas; i++)
                {
                    if(contaaux==conta[i])
                    {
                        achou=1;
                        break;
                    }
                }
                if(achou!=1)
                {
                    conta[ncriadas] = contaaux;
                    saldo[ncriadas] = 0;
                    ncriadas++;
                }
                else
                {
                    printf("O numero de conta informado ja existe!\n");
                }
            }
            break;
        }
    }while(op!=0);

    return 0;
}
