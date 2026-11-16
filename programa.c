#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//tentando fazer uma função que apague a tela anterior, do linux e macOS é isso, mas to vendo pro windows ainda 
#define ESC "\033["
#define CLEAR ESC "H" ESC "J"

//prototipos
int menu_inicio();
int menu_jogo();
void limpa_buffer();
void imprime_plano(int pontos_x[], int pontos_y[], int qtd_pontos);

//main
int main(){
    int op1,op2,score_pontos=0;
    char resposta[30]={'\0'};
    //variaveis para plano
    
//loop do jogo
    do{
        op1=menu_inicio();
        switch(op1){
//o jogo aconteceria dentro do caso 1 do main
        	case 1:
            	do{
                	//chamada de funções de calculo ou formação dos pares ordenados
                	//corpo_do_jogo(...);
                	op2=menu_jogo();
                	switch(op2){
                    	//verifivação de respostas do usuário
                    	case 1:
                        	if(strcmp("Linear",resposta)==0){
                            	printf("\nCorreto!\n");
                            	score_pontos++;
                        	}else{
                            	printf("\nIncorreto!\n");
                        	}
                        	printf("\n\tPrecione ENTER para continuar.\n "); 
                        	getchar();
                        	printf(CLEAR);
                        break;
                        case 2:
                            if(strcmp("Quadratica",resposta)==0){
                                printf("\nCorreto!\n");
                                score_pontos++;
                            }else{ 
                            	printf("\nIncorreto!\n");
                            }
                            printf("\n\tPrecione ENTER para continuar.\n "); 
                            getchar();
                            printf(CLEAR);
                        break;
                        case 3:
                            if(strcmp("Exponencial",resposta)==0){
                                printf("\nCorreto!\n");
                                score_pontos++;
                            }else{ 
                               	printf("\nIncorreto!\n");
                            }
                            printf("\n\tPrecione ENTER para continuar.\n ");
                            getchar();
                        	printf(CLEAR);
                        break;
              			case 0:
              				printf(CLEAR);
                        	printf("\n\tSaindo...\n");
                        	printf("\n\tPrecione ENTER para continuar.\n ");
                        	getchar();
                            printf(CLEAR);
                        break;
                        default:
                            printf("\nResposta invalida.\n");
                            printf("\n\tPrecione ENTER para continuar.\n "); 
                            getchar();
                            printf(CLEAR);
                    }
                }while(op2!=0);
            break;
            case 2:
               	//função do score ou seu calculo aqui no main
            break;
            case 0:
                printf("\nJogo encerrado!\n");
            break;
            default:
                printf("\nAlternativa invalida.\n");
               	printf("\n\tPrecione ENTER para continuar.\n ");
                getchar();
                printf(CLEAR);
    	}
	}while(op1!=0);
    return 0;
}

void limpa_buffer(){
	int aux;
	while ((aux = getchar()) != '\n' && aux != EOF); //limpa o buffer
}

//menu para iniciar o jogo e ver score
int menu_inicio(){
    int alternativa,aux;
    printf("\t\tJOGO DO NOME LONGO\n"); //nome do jogo
    printf("Neste jogo, o objetivo é observar um plano cartesiano e identificar a qual tipo de função aquela distribuição de pares ordenados corresponde.\n"); //descrição do jogo
    printf("\n\tPrecione ENTER para continuar.\n "); //gambiarra pra dar tempo do usuário ler a descrição
    getchar();
    printf(CLEAR);
    printf("\t\tJOGO DO NOME LONGO"); //tela inicial do jogo
    printf("\n1 - INICIAR");
    printf("\n2 - SCORE");
    printf("\n0 - SAIR");
    printf("\nAlternativa: ");
    scanf("%d",&alternativa);
    limpa_buffer();
    printf(CLEAR);
    return alternativa;
}

//menu de intereção do usuário com o jogo
int menu_jogo(){
    int opcao;
    int x[] = {-4,-3,-2,-1,0};
    int y[] = {-4,-3,-2,-1,0};
    int qtd = 5;

    //fazer um if aqui ou na função de impressão para só imprimir ou receber novos valores para o gráfico após o usuário acertar 
    //impressao_plano_carteciano(...); chamada das funções de formação e impressão do plano cartesiano

    printf("\nPrint da reta\n");
    imprime_plano(x,y,qtd);
    printf("\n");

    printf("\nQual das alternativas abaixo representa o plano ilustrado?");
    printf("\n1 - Linear");
    printf("\n2 - Quadratica");
    printf("\n3 - Exponencial");
    printf("\n0 - SAIR");
    printf("\nResposta: ");
	scanf("%d",&opcao);
	limpa_buffer();
    return opcao;
}

//funcao do plano cartesiano
    
//recebe como parametro um vetor para valores de x e um para valores de y, no qual x[i] e y[i] formará um dos pontos no plano.

void imprime_plano(int pontos_x[], int pontos_y[], int qtd_pontos) //assinatura da funcao com 3 parametros, vetores de x e y com tamanho n
{
    int l, c, i, x = 0, y = 0, eh_igual_ponto;

    for (l = 0; l < 15; l++)
    {
        for (c = 0; c < 15; c++)
        {
            x = c - 7;          //centralizacao da matriz tornando o centro dela em (0,0)
            y = 7 - l;              

            eh_igual_ponto = 0;     // inicializa variavel, neste caso é falso
            for (i = 0; i < qtd_pontos; i++)
            {
                if (pontos_x[i] == x && pontos_y[i] == y)
                {
                    eh_igual_ponto = 1;     // altera o valor para 1
                    i = qtd_pontos;                  // encerra o loop, pois o ponto ja foi encontrado
                }
            }
            if (eh_igual_ponto)             // valor é igual a um, entao condicao eh verdadeira
            {
                printf(" * ");              // teste prioridade, caso nao for este testa os outros
            }
            else if (l == 7 && c == 7)
            {
                printf(" + ");
            }
            else if (l == 7 && c == 0)
            {
                printf("<--");
            }
            else if (l == 7 && c == 14)
            {
                printf("-->");
            }
            else if (l == 0 && c == 7)
            {
                printf(" ^ ");
            }
            else if (l == 14 && c == 7)
            {
                printf(" v ");
            }
            else if (l == 7)
            {
                printf("---");
            }
            else if (c == 7)
            {
                printf(" | ");
            }
            else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }
}