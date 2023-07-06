//CASO NãO RODE EM SEU COMPILADOR, RECOMENDO UTILIZAR O COMPILADOR ONLINE DESSE SITE: https://www.onlinegdb.com/
// UM ARQUIVO EM BLOCO DE NOTAS INGRESSO.TXT É GERADO NO DIRETORIO ONDA ESTÁ ESSE PROJETO. (LÁ ESTARÁ AS INFORMAÇÕES CADASTRADAS DE TODOS OS CLIENTES DO CINEMA EM ORDEM)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char filme[50];
    int horario;
    
    char dimensao[20];
    char forma_pagamento[20];
    int idade;
    int preco_ingresso;
    int estudante;
    char pipoca[20];
    char bebida[20];
    char complemento[20];
    int avaliacao_filme;
    int sala;
    int avaliacao_atendimento;
    int avaliacao_preco;
    
} Ingresso;

void salvarIngresso(Ingresso* ingresso, int numero_cliente) {
    FILE* arquivo = fopen("ingresso.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    fprintf(arquivo, "\n");
    fprintf(arquivo, "------------- CLIENTE %02d ------------\n", numero_cliente);
    fprintf(arquivo, "Nome: %s\n", ingresso->nome);
    fprintf(arquivo, "Filme: %s\n", ingresso->filme);
    fprintf(arquivo, "Horário: %dh\n", ingresso->horario);
    fprintf(arquivo, "DimensÃo: %s\n", ingresso->dimensao);
    fprintf(arquivo, "Forma de pagamento: %s\n", ingresso->forma_pagamento);
    fprintf(arquivo, "Valor do ingresso: R$ %d,00 R$\n", ingresso->preco_ingresso);
    fprintf(arquivo, "Pipoca: %s\n", ingresso->pipoca);
    fprintf(arquivo, "Bebida: %s\n", ingresso->bebida);
    fprintf(arquivo, "Complemento: %s\n", ingresso->complemento);
    fprintf(arquivo, "Sala: %d\n", ingresso->sala);
    fprintf(arquivo, "AvaliaçÃo do atendimento: %d\n", ingresso->avaliacao_atendimento);
    fprintf(arquivo, "AvaliaçÃo dos preços: %d\n", ingresso->avaliacao_preco);
    fprintf(arquivo, "--------------- BOM FILME :D ----------------\n");
    fprintf(arquivo, "\n");

    fclose(arquivo);
}

int main() {
    Ingresso* ingresso = (Ingresso*)malloc(sizeof(Ingresso));
    if (ingresso == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    char proximo_cliente = 's';
    int numero_cliente = 1;
    int opcao_pipoca;
    int opcao_bebida;
    int opcao_complemento;


    while (proximo_cliente == 's' || proximo_cliente == 'S') {
        printf("Olá, seja muito bem-vindo(a) ao cinema! Como se chama?\n");
        scanf("%s", ingresso->nome);
        system("clear");
        int opcao_filme;
        printf("Olá, %s! Qual filme está afim de assistir hoje?\n", ingresso->nome);
        do {
            
            printf("[ 1 ]- Avatar, o caminho da água\n");
            printf("[ 2 ]- Homem-Aranha: Através do Aranhaverso\n");
            printf("[ 3 ]- Vingadores: Ultimato\n");
            scanf("%d", &opcao_filme);

            switch (opcao_filme) {
                case 1:
                    strcpy(ingresso->filme, "Avatar, o caminho da água");
                    system("clear");
                    break;
                case 2:
                    strcpy(ingresso->filme, "Homem-Aranha: Através do Aranhaverso");
                    system("clear");
                    break;
                case 3:
                    strcpy(ingresso->filme, "Vingadores: Ultimato");
                    system("clear");
                    break;
                default:
                    
                    printf("Opção inválida! Tente novamente.\n");
                    break;
                    
            }
            
        }
        
        while (opcao_filme < 1 || opcao_filme > 3);

        int opcao_horario;
        printf("Bela escolha! Horários disponíveis para %s:\n", ingresso->filme);
        do {
            
            printf("[ 1 ] - 14h - Dublado\n");
            printf("[ 2 ]- 16h - Dublado\n");
            printf("[ 3 ]- 18h - Dublado\n");
            printf("[ 4 ]- 20h - Legendado\n");
            printf("[ 5 ]- 22h - Legendado\n");
            scanf("%d", &opcao_horario);

            switch (opcao_horario) {
                case 1:
                    ingresso->horario = 14;
                    system("clear");
                    break;
                case 2:
                    ingresso->horario = 16;
                    system("clear");
                    break;
                case 3:
                    ingresso->horario = 18;
                    system("clear");
                    break;
                case 4:
                    ingresso->horario = 20;
                    system("clear");
                    break;
                case 5:
                    ingresso->horario = 22;
                    system("clear");
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
                  
                    break;
            }
            
        } 
        
        while (opcao_horario < 1 || opcao_horario > 5);
        
    
        int opcao_dimensao;
        printf("Escolha a dimensão do filme:\n");
        do {
            printf("[ 1 ] - 2D\n");
            printf("[ 2 ]- 3D\n");
            scanf("%d", &opcao_dimensao);

            switch (opcao_dimensao) {
                case 1:
                    strcpy(ingresso->dimensao, "2D");
                    system("clear");
                    break;
                case 2:
                    strcpy(ingresso->dimensao, "3D");
                    system("clear");
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
                    break;
            }
            
        } while (opcao_dimensao < 1 || opcao_dimensao > 2);

        int opcao_pagamento;
        
            printf("Forma de pagamento:\n");
        do {
            
            printf("[ 1 ]- Pix\n");
            printf("[ 2 ]- CartÃo (Débito)\n");
            printf("[ 3 ]- CartÃo (Crédito)\n");
            printf("[ 4 ]- Dinheiro\n");
            scanf("%d", &opcao_pagamento);

            switch (opcao_pagamento) {
                case 1:
                    strcpy(ingresso->forma_pagamento, "Pix");
                    system("clear");
                    break;
                case 2:
                    strcpy(ingresso->forma_pagamento, "CartÃo (Débito)");
                    system("clear");
                    break;
                case 3:
                    strcpy(ingresso->forma_pagamento, "CartÃo (Crédito)");
                    system("clear");
                    break;
                case 4:
                    strcpy(ingresso->forma_pagamento, "Dinheiro");
                    system("clear");
                    break;
                default:
                    printf("OpçÃo inválida! Tente novamente.\n");
                    break;
            }
            
        } while (opcao_pagamento < 1 || opcao_pagamento > 4);

        printf("Vocãª tem carteira de estudante?\n");
        printf("[ 1 ] - Sim\n");
        printf("[ 0 ] - NÃo\n");
        scanf("%d", &ingresso->estudante);

        if (ingresso->estudante == 1) {
            ingresso->idade = 0;  // Valor nulo, pois a idade não será usada
        } else {
            printf("Digite a sua idade:\n");
            scanf("%d", &ingresso->idade);
        }
            system("clear");
        if (ingresso->idade < 18 || ingresso->estudante == 1) {
            printf("Ingresso de meia-entrada: R$ 10,00\n");
            ingresso->preco_ingresso = 10;
        } else {
            printf("Ingresso inteira: R$ 20,00\n");
            ingresso->preco_ingresso = 20;
        }
        
        printf("Deseja adicionar pipoca?\n");
        printf("[ 1 ] - Sim\n");
        printf("[ 2 ] - Não\n");
        scanf("%d", &opcao_pipoca);

        if (opcao_pipoca == 1) {
            printf("Qual tipo de pipoca vocãª deseja?\n");
            printf("[ 1 ]- Salgada R$ 3,99\n");
            printf("[ 2 ]- Doce R$ 2,99\n");
            scanf("%d", &opcao_pipoca);

            switch (opcao_pipoca) {
                case 1:
                    strcpy(ingresso->pipoca, "Salgada R$ 3,99");
                    
                    break;
                case 2:
                    strcpy(ingresso->pipoca, "Doce R$ 2,99");
                    
                    break;
                default:
                    printf("OpçÃo inválida! A pipoca não será adicionada.\n");
                    break;
            }
        } else {
            strcpy(ingresso->pipoca, "Nenhuma");
        }

        printf("Deseja adicionar bebida? \n");
        printf(" [ 1 ] - Sim\n");
        printf(" [ 2 ] - NÃo\n");
        scanf("%d", &opcao_bebida);

        if (opcao_bebida == 1) {
            printf("Qual tipo de bebida vocãª deseja?\n");
            printf("[ 1 ]- Refrigerante R$ 5,99\n");
            printf("[ 2 ]- Suco R$ 3,99\n");
            scanf("%d", &opcao_bebida);

            switch (opcao_bebida) {
                case 1:
                    strcpy(ingresso->bebida, "Refrigerante R$ 5,99");
                    system("clear");
                    break;
                case 2:
                    strcpy(ingresso->bebida, "Suco R$ 3,99");
                    system("clear");
                    break;
                default:
                    printf("OpçÃo inválida! A bebida não será adicionada.\n");
                    break;
            }
        } else {
            strcpy(ingresso->bebida, "Nenhuma");
        }
        
        printf("Deseja adicionar algum complemento\n");
        printf("[ 1 ] - Sim\n");
        printf(" [ 2 ] - NÃo\n");
        scanf("%d", &opcao_complemento);

        if (opcao_complemento == 1) {
            printf("Qual complemento vocãª deseja?\n");
            printf("[ 1 ]- Nutela R$ 19,99\n");
            printf("[ 2 ]- Bala Fini R$ 9,99\n");
            scanf("%d", &opcao_complemento);

            switch (opcao_complemento) {
                case 1:
                    strcpy(ingresso->complemento, "Nutela R$ 19,99");
                    system("clear");
                    break;
                case 2:
                    strcpy(ingresso->complemento, "Bala Fini R$ 79,99");
                    system("clear");
                    break;
                default:
                    printf("OpçÃo inválida! O complemento não será adicionado.\n");
                    system("clear");
                    break;
            }
        }
            else {
            strcpy(ingresso->complemento, "Nenhum");
        }
        
        printf("Salas disponíveis\n" );
        printf("[ 1 ] - Sala 1\n");
        printf("[ 2 ] - Sala 2\n");
        printf("[ 3 ] - Sala 3\n");
        scanf("%d", &ingresso->sala);
        system("clear");

        printf("Digite sua avaliação para esse atendimento (0-10):\n");
        scanf("%d", &ingresso->avaliacao_atendimento);
        system("clear");

        printf("Digite sua avaliação para o preço (0-10):\n");
        scanf("%d", &ingresso->avaliacao_preco);
        system("clear");


        salvarIngresso(ingresso, numero_cliente);

        printf("Deseja registrar um novo cliente? (s/n)\n");
        scanf(" %c", &proximo_cliente);
        numero_cliente++;
    }
    system("clear");

    free(ingresso);

    return 0;
}
