#include <stdio.h>

void moverTorre (int casas, char direcao[80]){
    if (casas > 0){
        printf("%s\n", direcao);
        moverTorre(casas - 1, direcao);
    }
}
void moverBispo (int casas, char direcao1[80], char direcao2[80]){
    if (casas > 0){
        printf("%s %s\n", direcao1, direcao2);
        moverBispo(casas - 1, direcao1, direcao2);
    }
}
void moverRainha (int casas, char direcao1[80], char direcao2[80]){
    if (casas > 0){
        printf("%s %s\n", direcao1, direcao2);
        moverRainha(casas - 1, direcao1, direcao2);
    }
}

int main()
{
    int contaTorre = 0;
    int contaBispo = 0;
    int contaRainha = 0;
    int contaCavalo = 0;
    char peca[20];
    int pecaValor = 0;
    int casas = 0;
    char direcao[80];
    char direcao1[80];
    char direcao2[80];
    int isValid = 0;

    // Selecionar a peça e as casas
    printf("Selecione a peça\n");

    while (isValid < 1){
        scanf("%20s", peca);

        if (strcmp(peca, "Torre") == 0)
        {
            pecaValor = 1;
            isValid = 1;
        }
        else if (strcmp(peca, "Bispo") == 0)
        {
            pecaValor = 2;
            isValid = 1;
        }
        else if (strcmp(peca, "Rainha") == 0)
        {
            pecaValor = 3;
            isValid = 1;
        }
        else if (strcmp(peca, "Cavalo") == 0)
        {
            pecaValor = 4;
            isValid = 1;
        }
        else
        {
            printf("Digite uma peça válida\n");
            isValid = 0;
        }
    }

    if (strcmp(peca, "Cavalo") != 0)
    {
        printf("Selecione a quantidade de casas\n");
        scanf("%d", &casas);
        while (casas < 1 || casas > 8)
        {
            printf("Número de casas inválido, digite um número entre 1 e 8\n");
            scanf("%d", &casas);
        }
    }

    printf("Selecione a direção\n");

    if (strcmp(peca, "Torre") == 0)
    {
        scanf("%80s", direcao);
        while ((strcmp(direcao, "Esquerda") != 0) && (strcmp(direcao, "Direita") != 0) && (strcmp(direcao, "Cima") != 0) && (strcmp(direcao, "Baixo") != 0))
        {
            printf("Direção inválida, digite Direita ou Esquerda\n");
            scanf("%80s", direcao);
        }
    }
    else if (strcmp(peca, "Bispo") == 0)
    {
        scanf("%80s", direcao1);
        printf("O bispo se move em diagonal. Selecione a segunda direção\n");
        scanf("%80s", direcao2);

        while (
            !(
                (strcmp(direcao1, "Esquerda") == 0 && strcmp(direcao2, "Cima") == 0) ||
                (strcmp(direcao1, "Direita") == 0 && strcmp(direcao2, "Cima") == 0) ||
                (strcmp(direcao1, "Esquerda") == 0 && strcmp(direcao2, "Baixo") == 0) ||
                (strcmp(direcao1, "Direita") == 0 && strcmp(direcao2, "Baixo") == 0)))
        {
            printf("Direção inválida, digite Direita ou Esquerda e Cima ou Baixo\n");
            scanf("%80s", direcao1);
            scanf("%80s", direcao2);
        }
    }
    else if (strcmp(peca, "Rainha") == 0)
    {
        scanf("%80s", direcao1);
        printf("Caso a rainha esteja se movendo na diagonal, selecione a próxima direção. Se não, indique -\n");
        scanf("%80s", direcao2);

        while (
            !(
                // movimentos retos
                (strcmp(direcao1, "Direita") == 0 && strcmp(direcao2, "-") == 0) ||
                (strcmp(direcao1, "Esquerda") == 0 && strcmp(direcao2, "-") == 0) ||
                (strcmp(direcao1, "Cima") == 0 && strcmp(direcao2, "-") == 0) ||
                (strcmp(direcao1, "Baixo") == 0 && strcmp(direcao2, "-") == 0) ||

                // movimentos diagonais
                (strcmp(direcao1, "Direita") == 0 && strcmp(direcao2, "Cima") == 0) ||
                (strcmp(direcao1, "Direita") == 0 && strcmp(direcao2, "Baixo") == 0) ||
                (strcmp(direcao1, "Esquerda") == 0 && strcmp(direcao2, "Cima") == 0) ||
                (strcmp(direcao1, "Esquerda") == 0 && strcmp(direcao2, "Baixo") == 0)))
        {
            printf("Direção inválida, digite: Direita, Esquerda, Cima, Baixo ou uma combinação diagonal (ex: Direita Cima)\n");
            scanf("%80s", direcao1);
            scanf("%80s", direcao2);
        }
    }
    else if (strcmp(peca, "Cavalo") == 0)
    {
        scanf("%80s", direcao1);
        printf("O cavalo se move em L. Selecione a próxima direção\n");
        scanf("%80s", direcao2);

        while (
            // Direções inválidas
            ((strcmp(direcao1, "Esquerda") != 0) &&
             (strcmp(direcao1, "Direita") != 0) &&
             (strcmp(direcao1, "Cima") != 0) &&
             (strcmp(direcao1, "Baixo") != 0))

            ||
            // Direções inválidas
            ((strcmp(direcao2, "Esquerda") != 0) &&
             (strcmp(direcao2, "Direita") != 0) &&
             (strcmp(direcao2, "Cima") != 0) &&
             (strcmp(direcao2, "Baixo") != 0))

            ||
            // direções iguais
            (strcmp(direcao1, direcao2) == 0)

            ||
            // combinações opostas
            ((strcmp(direcao1, "Esquerda") == 0 && strcmp(direcao2, "Direita") == 0) ||
             (strcmp(direcao1, "Direita") == 0 && strcmp(direcao2, "Esquerda") == 0) ||
             (strcmp(direcao1, "Cima") == 0 && strcmp(direcao2, "Baixo") == 0) ||
             (strcmp(direcao1, "Baixo") == 0 && strcmp(direcao2, "Cima") == 0)))
        {
            printf("Direção inválida, digite Direita ou Esquerda e Cima ou Baixo, na ordem correta\n");
            scanf("%80s", direcao1);
            scanf("%80s", direcao2);
        }
    }

    switch (pecaValor)
    {
    // Mover a Torre
    case 1:
        moverTorre(casas, direcao);
        break;

    // Mover o Bispo
    case 2:
        moverBispo(casas, direcao1, direcao2);
        break;

    // Mover a Rainha
    case 3:
        moverRainha(casas, direcao1, direcao2);
        break;

    case 4:
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 2; j++)
            {
            printf("%s\n", direcao1);
            }
            printf("%s\n", direcao2);
        }
        break;
    }
    return 0;
}
