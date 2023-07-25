#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/*Estrutura do tipo cliente*/
typedef struct {
	int telefone;
	char nome[50];
	char endereco[200];
}Cli;

/*Estrutura do tipo entregador*/
typedef struct {
char nome[20];
	int codigo;
	int situacao;
	int entregas;
}Entr;

/*Estrutura do tipo pizzas*/
typedef struct {
	int codigo;
	char nome [20];
	float preco;
	char descricao[200];
}Pizza;

/*Estrutura do tipo pedido*/
typedef struct {
	int numero;
	int telefone;
	int codigo_pizza;
	int codigo_entregador;
	int situacao;
	int nota;
	float valor;
}Ped;

/*Variaveis globais*/
Pizza pizzas[100];
int quantidadePizzas = 0;
int PizzasVendidas = 0;
Cli clientes[100];
int quantidadeClientes = 0;

Ped pedidos[100];
int quantidadePedidos = 1;

Entr entregadores[5] = {
	"João", 1, 0, 0,
	"Pedro", 2, 0, 0,
	"Marcos", 3, 0, 0,
	"Luiz", 4, 0, 0,
	"Gabriel", 5, 0, 0,
};
int quantidadeEntregadores = 5;


/*Funcao para realizar cadastro de nova pizza*/
void CadastraPizza () {
	Pizza novaPizza;

	/*Insere codigo da pizza*/
	printf("Digite o código da pizza: ");
	scanf("%d", &novaPizza.codigo);

	/*verifica se ja existe alguma pizza cadastrada com o mesmo codigo
 	- caso exista, retorna ao menu pizzaria*/
	for (int i = 0; i < quantidadePizzas; i++) {
		if (pizzas[i].codigo == novaPizza.codigo) {
			system("clear");
			printf("Já existe uma pizza cadastrada com esse código.\n");
			sleep(2);
			return;
		}
	}

	/*- caso nao exista, prossegue com a logica para novo cadastro*/
	printf("Digite o nome da pizza: ");
	scanf(" %[^\n]s", novaPizza.nome);

	printf("Digite o preço da pizza: ");
	scanf("%f", &novaPizza.preco);

	printf("Digite a descrição da pizza: ");
	scanf(" %[^\n]s", novaPizza.descricao);

	pizzas[quantidadePizzas] = novaPizza;
	quantidadePizzas++;

	printf("Pizza cadastrada com sucesso!\n");
	sleep(1);
}

/*Funcao para alterar as informacoes de certa pizza - pesquisa pelo código*/
void AlteraPizza () {
	int codigo;
	/*Usuario digita o codigo da pizza que deseja alterar*/
	printf("Digite o codigo da pizza que deseja alterar: ");
	scanf("%d", &codigo);

	/*Sistema de loop que verifica se há alguma pizza cadastrada com o codigo inserido*/
	for (int i = 0; i < quantidadePizzas; i++) {
		if (pizzas[i].codigo == codigo) {
			/*Caso haja alguma pizza com o codigo inserido
   			- prossegue com a logica para alterar*/
			printf("Digite o novo nome da pizza: ");
			scanf(" %[^\n]s", pizzas[i].nome);

			printf("Digite o novo preço da pizza: ");
			scanf("%f", &pizzas[i].preco);

			printf("Digite a nova descrição para a pizza: ");
			scanf(" %[^\n]s", pizzas[i].descricao);

			system("clear");
			printf("Dados da pizza alterados com sucesso!\n");
			sleep(1);
			return;
		}
	}

	/*caso nao haja pizza cadastrda com o codigo inserido
 	- imprime mensagem de erro na tela e retorna ao menu pizzaria*/
	system("clear");
	printf("Pizza não encontrada.\n");
	sleep(2);
}

/*Funcao para remover uma pizza cadastrada*/
void RemovePizza () {
	int codigo;

	/*usuário digita o codigo da pizza que deseja remover*/
	printf("Digite o codigo da pizza que deseja remover: ");
	scanf("%d", &codigo);

	/*Loop verifica se há alguma pizza com o codigo inserido
 	  - caso haja: altera o codigo da pizza para 0*/
	for (int i = 0; i < quantidadePizzas; i++) {
		if (pizzas[i].codigo == codigo) {
			pizzas[i].codigo = 0;
			system("clear");
            sleep(2);
			printf("Pizza removida com suceso!\n");
			return;
		}
	}

	/*Caso não haja, printa mensagem de erro na tela*/
	system("clear");
	printf("Pizza não econtrada!\n");
	sleep(2);
}

void DespachaPizza () {
	int opcao, nome;
	system("clear");
	printf("------ Pedidos 'em preparo' ------\n\n");
	for (int i = 1; i <= quantidadePedidos; i++) {
		if (pedidos[i].situacao == 1 && pedidos[i].numero != 0) {
			printf("%d - ", pedidos[i].numero);
			nome = pedidos[i].codigo_pizza;
			printf("%s.\n\n", pizzas[nome + 1].nome);
		}
	}

	printf("Digite qual pedido deseja despachar: ");
	scanf("%d", &opcao);
	for (int i = 1; i < quantidadePedidos; i++) {
		if (pedidos[i].numero == opcao) {
			
			pedidos[i].situacao = 2;

			for (int j = 0; j < quantidadeEntregadores; j++) {
				if (entregadores[j].situacao == 0) {
					entregadores[j].situacao++;
					pedidos[i].codigo_entregador = entregadores[j].codigo;
					break;
				}
			}
			
			system("clear");
			printf("Pedido despachado com sucesso!\n");
			sleep(2);
			return;

		}
	}

	system("clear");
	printf("Nao há nenhum pedido ativo com o codigo inserido!\n");
	sleep(2);
	system("clear");
}

void ExibeEntregadores () {
	int next;
	system("clear");
	printf("------ Lista de entregadores ------\n\n");
	for (int i = 0; i < quantidadeEntregadores; i++) {
		printf("%d) %s. Número de entregas: %d.\n\n", entregadores[i].codigo, entregadores[i].nome, entregadores[i].entregas);
	}
	printf("Digite qualquer numero para continuar: ");
	scanf("%d", &next);
}

void ExibeMontante () {
	float montante = 0;
	int next = 0;
	float aux = 0;
	system("clear");
	printf("Quantidade de pizzas vendidas = %d.\n\n", PizzasVendidas);
	printf("Montante total recebido: \n\n");
	for (int i = 0; i < quantidadePedidos; i++) {
		if(pedidos[i].situacao == 3) {
			aux = pedidos[i].valor;
			montante = montante + aux;
		}
	}
	printf("R$ %.2f\n", montante);
	printf("\nDigite qualquer numero para continuar: ");
	scanf("%d", &next);
}

/*Funcao para cadastro de novo cliente*/
void CadastraCliente () {
	Cli novoCliente;

	printf("Digite o número de telefone: ");
	scanf("%d", &novoCliente.telefone);

	/*Loop verifica se ja existe algum cliente com esse numero de telefone*/
	for (int i = 0; i < quantidadeClientes; i++) {
		if (clientes[i].telefone == novoCliente.telefone) {
			system("clear");
			printf("Já existe um cliente cadastrado com esse número de telefone!\n");
			sleep(2);
			return;
		}
	}

	printf("Digite seu nome: ");
	scanf(" %[^\n]s", novoCliente.nome);

	printf("Digite seu endereço: (Ex: logradouro, numero - bairro. cidade)\n");
	scanf(" %[^\n]s", novoCliente.endereco);

	clientes[quantidadeClientes] = novoCliente;
	quantidadeClientes++;
	
	system("clear");
	printf("Cliente cadastrado com sucesso!\n");
	sleep(1);
}

/*Funcao para alterar as informacoes de cadastro de determinado cliente*/
void AlteraCliente () {
	char nome[20];
	int opcao, numero;

	/*menu switch-case para o usuario decidir se deseja buscar a conta pelo numero ou nome cadastrados*/
	printf("Digite o numero de telefone cadastrado na conta que deseja alterar: ");
	scanf("%d", &numero);

	/*Caso esclha a busca pelo numero, vai digitar o numero de telefone cadastrado
   	  - loop para verificar se há alguma conta registrada com o numero digitado*/
	for (int i = 0; i < quantidadeClientes; i++) {
		
		/*Caso haja: segue a logica para mudanca das informacoes de cadastro*/
		if (clientes[i].telefone == numero) {

			system("clear");
					
			printf("Digite o novo nome da conta: ");
			scanf(" %[^\n]s", clientes[i].nome);

			printf("\nDigite o novo numero de telefone da conta: ");
			scanf("%d", &clientes[i].telefone);

			printf("Digite seu endereço: (Ex: logradouro, numero - bairro. cidade)\n");
			scanf(" %[^\n]s", clientes[i].endereco);

			system("clear");
			printf("Dados alterados com sucesso!\n");
			sleep(1);
			return;
		}
	}

	/*Caso nao haja, mensagem de erro é printada na tela*/
	system("clear");
	printf("Usuário nao encontrado!\n");
	sleep(2);
	
}

/*Funcao para remover a conta de determinado cliente*/
void RemoveCliente () {
	int numero;

	/*Usuário digita o numero cadastrado na conta*/
	printf("Digite o numero de telefone cadastrado na conta que deseja excluir: ");
	scanf("%d", &numero);

	/*Loop verifica se há conta cadastrada com o numero digitado
 	  - caso haja: altera o numero para 0*/
	for (int i = 0; i < quantidadeClientes; i++) {
		if (clientes[i].telefone == numero) {
			clientes[i].telefone = 0;
			system("clear");
			printf("Cliente removida com suceso!\n");
			sleep(2);
			return;
		}
	}

	/*Caso nao haja: printa mensagem de erro na tela*/
	system("clear");
	printf("Usuário não encontrado!\n");
	sleep(2);
}

/*Funcao para ver o menu completo com as pizzas ordenadas por codigo*/
void VerMenu () {
	system("clear");
	int menu = 0;
	while (menu == 0) {
		printf("--------Menu PizzaDelivery--------\n\n");
		for (int i = 0; i < quantidadePizzas; i++) {
			printf("%d) ", pizzas[i].codigo);
			printf("%s ", pizzas[i].nome);
			printf("- R$ %.2f\n", pizzas[i].preco);
			printf("%s\n\n", pizzas[i].descricao);
		
		}

		printf("\n\nDigite qualquer numero para continuar: ");
		scanf("%d", &menu);
	}
}

/*Funcao para fazer pedido*/
void FazPedido () {
	int telefone, codigo;

	system("clear");
	printf("Digite o numero cadastrado na conta: ");
	scanf("%d", &telefone);
	for (int i = 0; i < quantidadeClientes; i++) {
		if (clientes[i].telefone == telefone) {
			pedidos[quantidadePedidos].telefone = clientes[i].telefone;
			system("clear");
			printf("%s, vamos prosseguir com seu pedido.\n", clientes[i].nome);
			sleep(2);
			system("clear");
			
			printf("Digite o código da pizza que deseja: ");
			scanf("%d", &codigo);
			for (int j = 0; j < quantidadePizzas; j++) {
				if (pizzas[j].codigo == codigo) {
					pedidos[quantidadePedidos].codigo_pizza = pizzas[j].codigo;
					pedidos[quantidadePedidos].numero = quantidadePedidos;
					pedidos[quantidadePedidos].situacao = 1;
					pedidos[quantidadePedidos].codigo_entregador = 0;
					pedidos[quantidadePedidos].nota = 0;
					pedidos[quantidadePedidos].valor = pizzas[j].preco;
					quantidadePedidos++;
					
					system("clear");
					printf("Seu pedido foi realizado com sucesso!\n");
					sleep(2);
					system("clear");
					return;
				}
		
			}
		}
		
	}

	system("clear");
	printf("Houve algum erro enquanto realizávamos seu pedido! Tente novamente...\n");
	sleep(2);
	system("clear");

}

void RecebePedido () {
	system("clear");
	int telefone, avaliacao, loop_avaliacao = 0;
	printf("Digite o numero de telefone cadastrado na sua conta: ");
	scanf("%d", &telefone);

	for (int i = 0; i < quantidadePedidos; i++) {
		if (pedidos[i].telefone == telefone) {

			pedidos[i].situacao = 3;

			while(loop_avaliacao == 0) {
				avaliacao = 0;
				printf("Codigo do pedido: %d.\n Digite sua avaliação 1 - 5; ", pedidos[i].numero);
				scanf("%d", &avaliacao);

				if (avaliacao > 0 && avaliacao < 6) {
					pedidos[i].nota = avaliacao;

					system("clear");
					printf("Obrigado pela sua avaliação!\n");
					sleep(2);
					loop_avaliacao++;

					for (int j = 0; j < quantidadeEntregadores; j++) {
						if (pedidos[i].codigo_entregador == entregadores[j].codigo) {
							entregadores[j].situacao = 0;
							entregadores[j].entregas++;
						}
					}
					PizzasVendidas++;
					return;
				}
					
				else {
					system("clear");
					printf("Valor inválido! Digite uma avaliacao entre 1 e 5.\n");
					sleep(2);
					loop_avaliacao = 0;
				}
			}
		}
	}

	system("clear");
	printf("Houve algum erro tentando registrar o recebimento do pedido!\n");
	printf("              		    Tente novamente...		       		  \n");
	sleep(2);
	system("clear");
}

int main(void) {
	
	/*variaveis para controle de telas, menus e manter o codigo funcionando*/
	int loop_entrada, loop_pizzaria, loop_cliente, entrada, pizzaria, cliente;

	loop_entrada = 0;

	/*Loop de entrada do sistema, primeiro menu que o cliente irá acessar*/
	while(loop_entrada == 0) {
		
		loop_pizzaria = 0;
		loop_cliente = 0;
		
		system("clear");
		printf("Bem vindo ao PizzaDelivery!\n");
		printf("Selecione uma categoria: \n");
		printf("\n1) Pizzaria;\n");
		printf("2) Cliente;\n");
		printf("3) Sair;\n");
		scanf("%d", &entrada);
		switch (entrada) {
			case 1 :
				while (loop_pizzaria == 0) {
					system("clear");
					printf("SELECIONE UMA CATEGORIA\n\n");
					printf("1) Cadastrar pizzas; \n");
					printf("2) Alterar dados das pizzas; \n");
					printf("3) Remover uma pizza; \n");
					printf("4) Despacho da pizza; \n");
					printf("5) Exibir entregador; \n");
					printf("6) Exibir montante; \n");
					printf("7) Sair; \n");
					scanf("%d", &pizzaria);
					switch (pizzaria) {
						case 1 :
							CadastraPizza();
						break;

						case 2 :
							AlteraPizza();
						break;

						case 3 :
							RemovePizza();
						break;

						case 4 :
							DespachaPizza();
						break;

						case 5 :
							ExibeEntregadores();
						break;

						case 6 :
							ExibeMontante();
						break;

						case 7 :
							loop_pizzaria++;
						break;

						default :
							system("clear");
							printf(" !!COMANDO INVÁLIDO!! \nInsira um valor válido;\n\n  Aguarde um segundo...\n");
							sleep(2);
							system("clear");
						break;
					}
				}
			break;

			case 2 :
				while (loop_cliente == 0) {
					
					system("clear");
					printf("SELECIONE UMA CATEGORIA\n\n");
					printf("1) Cadastrar cliente; \n");
					printf("2) Alterar dados do cliente; \n");
					printf("3) Remover conta; \n");
					printf("4) Menu com todas as pizzas; \n");
					printf("5) Fazer pedido; \n");
					printf("6) Recebimento do pedido; \n");
					printf("7) Sair; \n");
					scanf("%d", &cliente);
					switch (cliente) {
						case 1 :
							CadastraCliente();
						break;

						case 2 :
							AlteraCliente ();
						break;

						case 3 :
							RemoveCliente();
						break;

						case 4 :
							VerMenu();
						break;

						case 5 :
							FazPedido();
						break;

						case 6 :
							RecebePedido();
						break;

						case 7 :
							loop_cliente++;
						break;

						default :
							system("clear");
							printf(" !!COMANDO INVÁLIDO!! \nInsira um valor válido;\n\n  Aguarde um segundo...\n");
							sleep(2);
							system("clear");
						break;
					}
				}
			break;

			case 3 :
				system("clear");
				printf("Obrigado por utilizar o PizzaDelivery!\n");
				sleep(2);
				loop_entrada++;
			break;

			default :
				system("clear");
				printf(" !!COMANDO INVÁLIDO!! \nInsira um valor válido;\n\n  Aguarde um segundo...\n");
				sleep(2);
				system("clear");
			break;
		}
	}
  		
  	return 0;
}