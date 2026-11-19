#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//função que apague a tela anterior
#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

#define T 25

//prototipos
int menu_inicio();

int menu_jogo();

void limpa_buffer();

void limpa();

void imprime_plano(int pontos_x[], int pontos_y[], int qtd_pontos);

void correcao(int op2,char resposta[],int *score_pontos);

//main, corpo do código
int main(){
    int op1,op2,score_pontos=0;
    char resposta[30]={'\0'};
    
    setlocale(LC_ALL, "Portuguese"); //tradução para os textos aceitarem os acentos da lingua portuguesa 
    
//loop do jogo
    do{
        op1=menu_inicio();
        
        switch(op1){
//o jogo acontece dentro do caso 1 do main
		    case 1:
            	do{
					op2=menu_jogo();
                	
                	correcao(op2,resposta,&score_pontos);
                    limpa();
                }while(op2!=0);
            break;
            case 2:
               	//função do score ou seu calculo aqui no main
            break;
            case 0:
                printf("\nJogo encerrado!\n"); //encerramento do programa 
            break;
            default:
                printf("\nAlternativa invalida.\n"); //segurança obrigatória para não quebrar o código 
                printf("\n\tPrecione ENTER para continuar.\n ");
                
				getchar();

				limpa();
    	}
	}while(op1!=0);
	
    return 0;
}
//função para remover informações desnecessárias na tela, fazendo a divisão de telas pelo escape "presse ENTER"
void limpa(){
	system(CLEAR);
}
//função para limpar o buffer dos scanfs
void limpa_buffer(){
	int aux;
	
	while ((aux = getchar()) != '\n' && aux != EOF); 
}

//menu para iniciar o jogo e ver score
int menu_inicio(){
    int alternativa,aux;
    
    printf("\n\n\n");
    printf("%115s\n","MATHGUESSER"); //nome do jogo
    printf("%190s\n","Neste jogo, o objetivo é observar um plano cartesiano e identificar a qual tipo de função aquela distribuição de pares ordenados corresponde entre uma função linear e uma função quadráticas.\n"); //descrição do jogo
    printf("\n\tPrecione ENTER para continuar.\n "); //tempo do usuário ler a descrição
    
	getchar();
    
    limpa();
    
    printf("\t\tMATHGUESSER\n"); //tela inicial do jogo
    printf("\n1 - INICIAR");
    printf("\n2 - SCORE");
    printf("\n0 - SAIR");
    printf("\nAlternativa: ");
    
	scanf("%d",&alternativa);
    
	limpa_buffer();
    limpa();
    
	return alternativa;
}

void correcao(int op2, char resposta[],int *score_pontos){
    switch(op2){
        //verifivação de respostas do usuário 
        case 1:
            if(strcmp("Linear crescente",resposta)==0){
                printf("\nCorreto!\n");
                
                score_pontos++;
            }else{
                printf("\nIncorreto!\n");
        	}
                        
			printf("\n\tPrecione ENTER para continuar.\n "); 
                        
			getchar();
                        	
        break;
        case 2:
            if(strcmp("Linear decrescente",resposta)==0){
                printf("\nCorreto!\n");
                
                score_pontos++;
            }else{ 
            	printf("\nIncorreto!\n");
            }
                           
		    printf("\n\tPrecione ENTER para continuar.\n "); 
                           
		    getchar();
                            
        break;
        case 3:
            if(strcmp("Quadratica crescente",resposta)==0){
                printf("\nCorreto!\n");
                
                score_pontos++;
            }else{ 
            	printf("\nIncorreto!\n");
            }
                          
            printf("\n\tPrecione ENTER para continuar.\n");
                           
		    getchar();
                        	
        break;
        case 4:
            if(strcmp("Quadratica decrescente",resposta)==0){
                printf("\nCorreto!\n");
                
                score_pontos++;
            }else{ 
            	printf("\nIncorreto!\n");
            }
                           
            printf("\n\tPrecione ENTER para continuar.\n ");
                           
            getchar();
                        	
        break;
		case 0:
	        limpa();
            
        	printf("\n\tSaindo...\n"); //Volta para a função menu_inicio
        	printf("\n\tPrecione ENTER para continuar.\n ");
                       
        	getchar();
                            
        break;
        default:
            printf("\nResposta invalida.\n"); //Nao aceita respostas sem sentido 
            printf("\n\tPrecione ENTER para continuar.\n "); 
                         
            getchar();
    }
}

//menu de intereção do usuário com o jogo e impressão dos planos
int menu_jogo(){
    int opcao;
    int x[] = {-3,-2,-1,0,1};
    int y[] = {3,2,0,2,3};
    int qtd = 5;
    
    //fazer um if aqui ou na função de impressão para só imprimir ou receber novos valores para o gráfico após o usuário acertar 
    imprime_plano(x,y,qtd);
    
	printf("\n");
    printf("\nQual das alternativas abaixo representa o plano ilustrado?");
    printf("\n1 - Linear crescente");
    printf("\n2 - Linear decrescente");
    printf("\n3 - Quadratica crescente");
    printf("\n4 - Quadratica decrescente");
    printf("\n0 - SAIR");
    printf("\nResposta: ");
	
	scanf("%d",&opcao);
	
	limpa_buffer();
    
	return opcao;
}

//funcao do plano cartesiano
//recebe como parametro um vetor para valores de x e um para valores de y, no qual x[i] e y[i] formará um dos pontos no plano.
void imprime_plano(int pontos_x[], int pontos_y[], int qtd_pontos){ //assinatura da funcao com 3 parametros, vetores de x e y com tamanho n
    int l, c, i, x = 0, y = 0, eh_igual_ponto;

    for (l = 0; l < T; l++){
        for (c = 0; c < T; c++){
            x = c - (T-1)/2;       //centralizacao da matriz tornando o centro dela em (0,0)
            y = (T-1)/2 - l;              

            eh_igual_ponto = 0;     // inicializa variavel, neste caso é falso
            
            for (i = 0; i < qtd_pontos; i++){
                if (pontos_x[i] == x && pontos_y[i] == y){
                    eh_igual_ponto = 1;     // altera o valor para 1
                    i = qtd_pontos;        // encerra o loop, pois o ponto ja foi encontrado
                }
            }
            if (eh_igual_ponto){    // valor é igual a um, entao condicao eh verdadeira
                printf(" * ");   // teste prioridade, caso nao for este testa os outros
            }
            else if (l == (T-1)/2 && c == (T-1)/2){
                printf(" + ");
            }
            else if (l == (T-1)/2 && c == 0){
                printf("<--");
            }
            else if (l == (T-1)/2 && c == T-1){
                printf("-->");
            }
            else if (l == 0 && c == (T-1)/2){
                printf(" ^ ");
            }
            else if (l == T-1 && c == (T-1)/2){
                printf(" v ");
            }
            else if (l == (T-1)/2){
                printf("---");
            }
            else if (c == (T-1)/2){
                printf(" | ");
            }
            else{
                printf(" . ");
            }
        }
        printf("\n");
    }
}
