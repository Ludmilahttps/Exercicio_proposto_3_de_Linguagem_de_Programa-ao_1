#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[30];

struct dados {
	string nome;
	string endereco;
	int idade;
	struct dados *prox;
};

typedef struct dados dados;

// Protótipos das funções auxiliares
int menu();
dados* insere_item();
void mostrar_lista(dados* lista);
dados* localiza_por_nome(string nome, dados* lista);
void mostra_dados_pessoa(dados* p);
dados* exclui_ultima_pessoa(dados* p, dados* lista);
dados* exclui_primeira_pessoa(dados* p, dados* lista);

int main()
{
	dados *lista = NULL; 
  dados *aux;
	int opcao;
	string nome;
	
	do {
		opcao = menu();
		
		switch (opcao) {
			
			case 1: // Verifica se a lista está vazia
							// Inserindo os elementos no início da lista
							if (lista == NULL) {
								aux = insere_item();
								if (aux != NULL)
									lista = aux;
							}
							// Caso não esteja vazia
							else {
								aux = lista;
								lista = insere_item();
								lista->prox = aux;
							}
							break;
			
			case 2: mostrar_lista(lista);
							break;
							
			case 3: getchar();
							printf("Qual o nome da pessoa? ");
			        fgets(nome, 30, stdin);
			        aux = localiza_por_nome(nome, lista);
			        if (aux != NULL) {
			        	mostra_dados_pessoa(aux);
							}
							else {
								printf("%s nao encontrado!\n", nome);
							}
							break;
							
			case 4: getchar();
							printf("Qual o nome da pessoa que deseja excluir? ");
			        fgets(nome, 30, stdin);
			        aux = localiza_por_nome(nome, lista);
			        if (aux != NULL) {
              //verifica se o item a ser excluido é o ultimo da lista
                  if(aux->prox == lista->prox)
                  {
			        	  lista = exclui_ultima_pessoa(aux, lista);
                  }
              //verifica se o item a ser excluido é o primeiro da lista
                  if(aux->prox == NULL)
                  {
                  aux = exclui_primeira_pessoa(aux, lista);
                  }
              printf("excluido!\n");
                  
							}
							else {
								printf("%s nao encontrado!\n", nome);
							}
							break;
      
      case 5: free(lista);
			
		}
		
	} while (opcao != 5);
	
	return 0;
}

// Implementação das rotinas auxiliares
int menu()
{
	int opcao;
	
	printf("1.Inserir dados na lista\n");
	printf("2.Mostrar lista\n");
	printf("3.Localizar pessoa por nome\n");
	printf("4.Excluir pessoa da lista\n");
  printf("5.Sair do programa\n");
	printf("Opcao? ");
	scanf("%d", &opcao);
	
	return opcao;
}

dados* exclui_ultima_pessoa(dados* p, dados* lista)
{
    dados* aux = lista->prox;
    lista = aux;
    return lista;
}

dados* exclui_primeira_pessoa(dados* p, dados* lista)
{
    dados* aux1=lista->prox;
    dados* aux2=lista;
    
    while(aux1!=NULL)
    {
      aux2 = aux1;
      aux1 = aux1->prox;
      printf("\nwhile");
    }
  
    aux2->prox = NULL;
    return aux1; 
}
dados* insere_item()
{
	dados* item;
	
	// Aloca item dinamicamente
	item = (dados*)malloc(sizeof(dados));
	// Captura o enter que sobrou do menu
	getchar();
	printf("Qual o nome da pessoa? ");
	fgets(item->nome, 30, stdin);
	printf("Qual o endereco? ");
	fgets(item->endereco, 30, stdin);
	printf("Qual a idade? ");
	scanf("%d", &item->idade);
	item->prox = NULL;
	
	return item;
}

void mostrar_lista(dados* lista)
{
	dados* aux = lista;
	
	while (aux != NULL) {
		mostra_dados_pessoa(aux);
		aux = aux->prox;
	}
}

dados* localiza_por_nome(string nome, dados* lista)
{
	dados* aux = lista;
	
	while (aux != NULL) {
		if (strcmp(nome, aux->nome) == 0) {
			return aux;
		}
		aux = aux->prox;
	}
	
	return NULL;
}

void mostra_dados_pessoa(dados* p)
{
	printf("Nome da pessoa......: %s\n", p->nome);
	printf("Endereco da pessoa..: %s\n", p->endereco);
	printf("Idade da pessoa.....: %d\n", p->idade);
	printf("---------------------\n");	
}