#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {

	int start, principal = 0, jogador_1 = 0, menu_p1 = 0, jogador_2 = 0, menu_p2 = 0, orientacao;
	int p1[10][10], p2[10][10], g1[10][10], g2[10][10];
	int i, j, cont1 = 20, cont2 = 20, verific1 = 0, verific2 = 0, c, aux, next, game = 0, ataque1 = 0, ataque2= 0;
	int cont_pa1 = 0, cont_nt1 = 0, cont_ct1 = 0, cont_sub1 = 0;
	int cont_pa2 = 0, cont_nt2 = 0, cont_ct2 = 0, cont_sub2 = 0;

	for(i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			p1[i][j] = 0;
			p2[i][j] = 0;
			g1[i][j] = 0;
			g2[i][j] = 0;
		}
	}

	while (principal == 0) {
		printf("===== BATALHA NAVAL =====\n\n");
		printf("1 - Alocar navios; \n");
		printf("2 - Jogar; \n");
		printf("3 - Sair; \n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &start);

		switch (start) {

			case 1 :
				//alocar barcos player1
				while(jogador_1 == 0) {
					system("clear");
					printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
					c = 0;
					for (i = 0; i < 10; i++) {
						for (j = 0; j < 10; j++) {
							if (j == 0) {
								printf("%d   %d ", c, p1[i][j]);
								c++;
							}
							if (j != 9 && j != 0)
								printf("%d ", p1[i][j]);

							if (j == 9)
								printf("%d\n", p1[i][j]);
						}	
					}
					
					printf("\n======= JOGADOR 1 =======\n");
					printf("===== ALOCAR NAVIOS =====\n\n");
					printf("1 - Porta Avioes (4 posicoes); \n");
					printf("2 - Navios Tanque (3 posicoes); \n");
					printf("3 - Contratorpedeiros (2 posicoes); \n");
					printf("4 - Submarinos (1 posicao); \n");
					printf("5 - Finalizar alocacao; \n");
					printf("Digite a opcao desejada: ");
					scanf("%d", &menu_p1);
					switch (menu_p1) {

						case 1 :
							//alocar porta avioes
							if (cont_pa1 == 0) { 
								printf("===== ALOCAR PORTA AVIOES =====\n\n");
								printf("Digite a orientacao do navio: \n");
								printf("1 - Vertical; \n");
								printf("2 - Horizontal; \n");
								scanf("%d", &orientacao);
								switch (orientacao) {

									case 1 :
										//codigo para inserir porta avioes na vertical
										printf("Digite a posicao inicial do navio ex: coordenada 1 enter coordenada 2: ");
										scanf("%d %d", &i, &j);

										if (p1[i][j] == 1 || p1[i+1][j] == 1 || p1[i+2][j] == 1 || p1[i+3][j] == 1) {
											printf("\nOPCAO INVALIDA!\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}

										else if (i >= 0 && j >= 0 && i < 10 && j < 10 && i + 3 < 10) {
											aux = i;
											for (i = aux; i < aux + 4; i++) {
												p1[i][j] = 1;
											}
											cont_pa1++;
										}

										else {
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}
									break;
									case 2 :
										//codigo para inserir porta avioes na horizontal
										printf("Digite a posicao inicial do navio: ");
										scanf("%d %d", &i, &j);

										if (p1[i][j] == 1 || p1[i][j+1] == 1 || p1[i][j+2] == 1 || p1[i][j+3] == 1) {
											printf("\nOPCAO INVALIDA!\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}

										else if (i >= 0 && j >= 0 && i < 10 && j < 10 && j + 3 < 10) {
											aux = j;
											for (j = aux; j < aux + 4; j++) {
												p1[i][j] = 1;
											}
											cont_pa1++;
										}

										else {
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}
									break;

									default :
										//erro (opcao invalida)
										printf("\nOPCAO INVALIDA!\n\n");
										printf("Digite algum numero para continuar: ");
										scanf("%d", &next);
									break;
								}
							}

							else if (cont_pa1 != 0) {
								system("clear");
								printf ("\nO PORTA AVIOES JA FOI ALOCADO!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						case 2 :
							//alocar navios tanque
							if (cont_nt1 < 2) {
								while (cont_nt1 < 2) {
									printf("===== ALOCAR NAVIO TANQUE %d =====\n\n", cont_nt1 + 1);
									printf("Digite a orientacao do navio: \n");
									printf("1 - Vertical; \n");
									printf("2 - Horizontal; \n");
									scanf("%d", &orientacao);
									switch (orientacao) {
										case 1 :
											//codigo para alocar navio tanque na vertical
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p1[i][j] == 1 || p1[i+1][j] == 1 || p1[i+2][j] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && i + 2 < 10) {
												aux = i;
												for (i = aux; i < aux + 3; i++) {
													p1[i][j] = 1;
												}
												
											cont_nt1++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										case 2 :
											//codigo para alocar navio tanque na horizontal
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p1[i][j] == 1 || p1[i][j+1] == 1 || p1[i][j+2] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && j + 2 < 10) {
												aux = j;
												for (j = aux; j < aux + 3; j++) {
													p1[i][j] = 1;
												}
												
													cont_nt1++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										default :
											//erro (opcao invalida)
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										break;
									}
								}
							}
							else if (cont_nt1 == 2) {
								system("clear");
								printf ("\nOS NAVIOS TANQUE JA FORAM ALOCADOS!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						case 3 :
							//alocar contratorpedeiros
							if (cont_ct1 < 3) {
								while (cont_ct1 < 3) {
									printf("===== ALOCAR CONTRATORPEDEIRO %d =====\n\n", cont_ct1 + 1);
									printf("Digite a orientacao do navio: \n");
									printf("1 - Vertical; \n");
									printf("2 - Horizontal; \n");
									scanf("%d", &orientacao);
									switch (orientacao) {
										case 1 :
											//codigo para alocar contratorpedeiros na vertical
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p1[i][j] == 1 || p1[i+1][j] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && i + 1 < 10) {
												aux = i;
												for (i = aux; i < aux + 2; i++) {
													p1[i][j] = 1;
												}
												
												cont_ct1++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										case 2 :
											//codigo para alocar contratorpedeiros na horizontal
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p1[i][j] == 1 || p1[i][j+1] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}	

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && j + 1 < 10) {
												aux = j;
												for (j = aux; j < aux + 2; j++) {
													p1[i][j] = 1;
												}
												
												cont_ct1++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										default :
											//erro (opcao invalida)
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										break;
									}
								}
							}
							else if (cont_ct1 == 3) {
								system("clear");
								printf ("\nTODOS OS CONTRATORPEDEIROS JA FORAM ALOCADOS!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						case 4 :
							//alocar submarinos
							if (cont_sub1 == 0) {
								while (cont_sub1 < 4) {
									printf("===== ALOCAR SUBMARINO %d =====\n\n", cont_sub1 + 1);
									printf("Digite a posicao inicial do navio: ");
									scanf("%d %d", &i, &j);
									
									if (p1[i][j] == 1) {
										printf("\nOPCAO INVALIDA!\n");
										printf("Digite algum numero para continuar: ");
										scanf("%d", &next);
									}
									else if (i >= 0 && j >= 0 && i < 10 && j < 10) {
										p1[i][j] = 1;
										
										cont_sub1++;
									}
									else {
										printf("\nOPCAO INVALIDA!\n\n");
										printf("Digite algum numero para continuar: ");
										scanf("%d", &next);
									}
								}				
							}
							else if (cont_sub1 == 4) {
								system("clear");
								printf ("\nTODOS OS SUBMARINOS JA FORAM ALOCADOS!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
								
							}
						break;

						case 5 :
							//encerrar alocacao (passar para o p2 somente quando ja tiver alocado tudo)
							if (cont_pa1 == 1 && cont_nt1 == 2 && cont_ct1 == 3 && cont_sub1 == 4) {
								jogador_1++;
							}

							else {
								printf("\nANTES DE CONTINUAR TERMINE DE ALOCAR TODOS OS NAVIOS!\n\n");
								printf("Digite qualquer numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						default :
							//erro (opcao invalida)
							system("clear");
							printf("\nOPCAO INVALIDA!\n\n");
							printf("Digite qualquer numero para continuar: ");
							scanf("%d", &next);
						break;
					}
				}
				
				//alocar barcos player2
				while(jogador_2 == 0) {
					system("clear");
					printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
					c = 0;
					for (i = 0; i < 10; i++) {
						for (j = 0; j < 10; j++) {
							if (j == 0) {
								printf("%d   %d ", c, p2[i][j]);
								c++;
							}
							if (j != 9 && j != 0)
								printf("%d ", p2[i][j]);

							if (j == 9)
								printf("%d\n", p2[i][j]);
						}	
					}
					
					printf("\n======= JOGADOR 2 =======\n");
					printf("===== ALOCAR NAVIOS =====\n\n");
					printf("1 - Porta Avioes (4 posicoes); \n");
					printf("2 - Navios Tanque (3 posicoes); \n");
					printf("3 - Contratorpedeiros (2 posicoes); \n");
					printf("4 - Submarinos (1 posicao); \n");
					printf("5 - Finalizar alocacao; \n");
					printf("Digite a opcao desejada: ");
					scanf("%d", &menu_p2);
					switch (menu_p2) {

						case 1 :
							//alocar porta avioes
							if (cont_pa2 == 0) { 
								printf("===== ALOCAR PORTA AVIOES =====\n\n");
								printf("Digite a orientacao do navio: \n");
								printf("1 - Vertical; \n");
								printf("2 - Horizontal; \n");
								scanf("%d", &orientacao);
								switch (orientacao) {

									case 1 :
										//codigo para inserir porta avioes na vertical
										printf("Digite a posicao inicial do navio: ");
										scanf("%d %d", &i, &j);

										if (p2[i][j] == 1 || p2[i+1][j] == 1 || p2[i+2][j] == 1 || p2[i+3][j] == 1) {
											printf("\nOPCAO INVALIDA!\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}

										else if (i >= 0 && j >= 0 && i < 10 && j < 10 && i + 3 < 10) {
											aux = i;
											for (i = aux; i < aux + 4; i++) {
												p2[i][j] = 1;
											}
											cont_pa2++;
										}

										else {
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}
									break;
									case 2 :
										//codigo para inserir porta avioes na horizontal
										printf("Digite a posicao inicial do navio: ");
										scanf("%d %d", &i, &j);

										if (p2[i][j] == 1 || p2[i][j+1] == 1 || p2[i][j+2] == 1 || p2[i][j+3] == 1) {
											printf("\nOPCAO INVALIDA!\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}

										else if (i >= 0 && j >= 0 && i < 10 && j < 10 && j + 3 < 10) {
											aux = j;
											for (j = aux; j < aux + 4; j++) {
												p2[i][j] = 1;
											}
											cont_pa2++;
										}

										else {
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										}
									break;

									default :
										//erro (opcao invalida)
										printf("\nOPCAO INVALIDA!\n\n");
										printf("Digite algum numero para continuar: ");
										scanf("%d", &next);
									break;
								}
							}

							else if (cont_pa2 != 0) {
								system("clear");
								printf ("\nO PORTA AVIOES JA FOI ALOCADO!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						case 2 :
							//alocar navios tanque
							if (cont_nt2 < 2) {
								while (cont_nt2 < 2) {
									printf("===== ALOCAR NAVIO TANQUE %d =====\n\n", cont_nt2 + 1);
									printf("Digite a orientacao do navio: \n");
									printf("1 - Vertical; \n");
									printf("2 - Horizontal; \n");
									scanf("%d", &orientacao);
									switch (orientacao) {
										case 1 :
											//codigo para alocar navio tanque na vertical
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p2[i][j] == 1 || p2[i+1][j] == 1 || p2[i+2][j] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && i + 2 < 10) {
												aux = i;
												for (i = aux; i < aux + 3; i++) {
													p2[i][j] = 1;
												}
												
											cont_nt2++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										case 2 :
											//codigo para alocar navio tanque na horizontal
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p2[i][j] == 1 || p2[i][j+1] == 1 || p2[i][j+2] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && j + 2 < 10) {
												aux = j;
												for (j = aux; j < aux + 3; j++) {
													p2[i][j] = 1;
												}
												
													cont_nt2++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										default :
											//erro (opcao invalida)
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										break;
									}
								}
							}
							else if (cont_nt2 == 2) {
								system("clear");
								printf ("\nOS NAVIOS TANQUE JA FORAM ALOCADOS!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						case 3 :
							//alocar contratorpedeiros
							if (cont_ct2 < 3) {
								while (cont_ct2 < 3) {
									printf("===== ALOCAR CONTRATORPEDEIRO %d =====\n\n", cont_ct2 + 1);
									printf("Digite a orientacao do navio: \n");
									printf("1 - Vertical; \n");
									printf("2 - Horizontal; \n");
									scanf("%d", &orientacao);
									switch (orientacao) {
										case 1 :
											//codigo para alocar contratorpedeiros na vertical
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p2[i][j] == 1 || p2[i+1][j] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && i + 1 < 10) {
												aux = i;
												for (i = aux; i < aux + 2; i++) {
													p2[i][j] = 1;
												}
												
												cont_ct2++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										case 2 :
											//codigo para alocar contratorpedeiros na horizontal
											printf("Digite a posicao inicial do navio: ");
											scanf("%d %d", &i, &j);

											if (p2[i][j] == 1 || p2[i][j+1] == 1) {
												printf("\nOPCAO INVALIDA!\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}	

											else if (i >= 0 && j >= 0 && i < 10 && j < 10 && j + 1 < 10) {
												aux = j;
												for (j = aux; j < aux + 2; j++) {
													p2[i][j] = 1;
												}
												
												cont_ct2++;
											}

											else {
												printf("\nOPCAO INVALIDA!\n\n");
												printf("Digite algum numero para continuar: ");
												scanf("%d", &next);
											}
										break;

										default :
											//erro (opcao invalida)
											printf("\nOPCAO INVALIDA!\n\n");
											printf("Digite algum numero para continuar: ");
											scanf("%d", &next);
										break;
									}
								}
							}
							else if (cont_ct2 == 3) {
								system("clear");
								printf ("\nTODOS OS CONTRATORPEDEIROS JA FORAM ALOCADOS!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						case 4 :
							//alocar submarinos
							if (cont_sub2 == 0) {
								while (cont_sub2 < 4) {
									printf("===== ALOCAR SUBMARINO %d =====\n\n", cont_sub2 + 1);
									printf("Digite a posicao inicial do navio: ");
									scanf("%d %d", &i, &j);
									
									if (p2[i][j] == 1) {
										printf("\nOPCAO INVALIDA!\n");
										printf("Digite algum numero para continuar: ");
										scanf("%d", &next);
									}
									else if (i >= 0 && j >= 0 && i < 10 && j < 10) {
										p2[i][j] = 1;
										
										cont_sub2++;
									}
									else {
										printf("\nOPCAO INVALIDA!\n\n");
										printf("Digite algum numero para continuar: ");
										scanf("%d", &next);
									}
								}				
							}
							else if (cont_sub2 == 4) {
								system("clear");
								printf ("\nTODOS OS SUBMARINOS JA FORAM ALOCADOS!\n\n");
								printf("Digite algum numero para continuar: ");
								scanf("%d", &next);
								
							}
						break;

						case 5 :
							//encerrar alocacao (passar para o p2 somente quando ja tiver alocado tudo)
							if (cont_pa2 == 1 && cont_nt2 == 2 && cont_ct2 == 3 && cont_sub2 == 4) {
								jogador_2++;
							}

							else {
								printf("\nANTES DE CONTINUAR TERMINE DE ALOCAR TODOS OS NAVIOS!\n\n");
								printf("Digite qualquer numero para continuar: ");
								scanf("%d", &next);
							}
						break;

						default :
							//erro (opcao invalida)
							system("clear");
							printf("\nOPCAO INVALIDA!\n\n");
							printf("Digite qualquer numero para continuar: ");
							scanf("%d", &next);
						break;
					}
				}
			break;

			case 2 :
				//programacao para fazer o jogo funcionar
				while(game == 0) {
					while (ataque1 < 2) {
						if (ataque1 == 0 ) {
							system("clear");
							printf("\n\n\n\n\n============== JOGADOR 1 ==============\nPara continuar digite qualquer numero: \n\n\n\n");
							scanf("%d", &next);
							ataque1++;
						}

						if (ataque1 == 1) {
							system("clear");
							printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
							c = 0;
							for (i = 0; i < 10; i++) {
								for (j = 0; j < 10; j++) {
									if (j == 0) {
										printf("%d   %d ", c, g1[i][j]);
										c++;
									}
									if (j != 9 && j != 0)
										printf("%d ", g1[i][j]);

									if (j == 9)
										printf("%d\n", g1[i][j]);
								}	
							}
							printf("\nESCOLHA QUAL COORDENADA DESEJA ATACAR : ");
							scanf("%d %d", &i, &j);

							if (g1[i][j] != 0) {
								system("clear");
								printf("\nVOCE JA ATACOU ESSA POSICAO, ESCOLHA OUTRA: \n\n");
								printf("Digite qualquer numero para continuar");
								scanf("%d", &next);
							}

							if (p2[i][j] == 0) {
								system("clear");
								g1[i][j] = 1;

								printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
								c = 0;
								for (i = 0; i < 10; i++) {
									for (j = 0; j < 10; j++) {
										if (j == 0) {
											printf("%d   %d ", c, g1[i][j]);
											c++;
										}
										if (j != 9 && j != 0)
											printf("%d ", g1[i][j]);

										if (j == 9)
											printf("%d\n", g1[i][j]);
									}	
								}
								printf("\nVOCÊ ACERTOU A ÁGUA.\n");
								printf("Digite qualquer numero para continuar: ");
								scanf("%d", &next);
								ataque1 = 2;
								ataque2 = 0;
								verific1 = 0;
							}
							else if (p2[i][j] == 1) {
								system("clear");
								g1[i][j] = 2;

								printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
								c = 0;
								for (i = 0; i < 10; i++) {
									for (j = 0; j < 10; j++) {
										if (j == 0) {
											printf("%d   %d ", c, g1[i][j]);
											c++;
										}
										if (j != 9 && j != 0)
											printf("%d ", g1[i][j]);

										if (j == 9)
											printf("%d\n", g1[i][j]);
									}	
								}
								printf("\nVOCÊ ACERTOU UM NAVIO INIMIGO!\n Jogue novamente.\n");
								printf("Digite qualquer numero para jogar novamente: ");
								scanf("%d", &next);
							}
							
						}
					}
					while (verific1 == 0) {
						cont1 = 20;
						for (i = 0; i < 10; i++) {
							for (j = 0; j < 10; j++) {
								if (g1[i][j] == 2) {
									cont1--;
									if (cont1 == 0) {
										system("clear");
										printf("\nFIM DE JOGO. O VENCEDOR FOI O JOGADOR 1\n");
										printf("Digite qualquer numero para continuar: ");
										scanf("%d", &next);
										game++;
									}
									else
										verific1++;
								}
							}
						}
					}
					
					while (ataque2 < 2) {
						if (ataque2 == 0 ) {
							system("clear");
							printf("\n\n\n\n\n============== JOGADOR 2 ==============\nPara continuar digite qualquer numero: \n\n\n\n");
							scanf("%d", &next);
							ataque2++;
						}

						if (ataque2 == 1) {
							system("clear");
							printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
							c = 0;
							for (i = 0; i < 10; i++) {
								for (j = 0; j < 10; j++) {
									if (j == 0) {
										printf("%d   %d ", c, g2[i][j]);
										c++;
									}
									if (j != 9 && j != 0)
										printf("%d ", g2[i][j]);

									if (j == 9)
										printf("%d\n", g2[i][j]);
								}	
							}
							printf("\nESCOLHA QUAL COORDENADA DESEJA ATACAR : ");
							scanf("%d %d", &i, &j);
							if (g2[i][j] != 0) {
								system("clear");
								printf("\nVOCE JA ATACOU ESSA POSICAO, ESCOLHA OUTRA: \n\n");
								printf("Digite qualquer numero para continuar");
								scanf("%d", &next);
							}

							if (p1[i][j] == 0) {
								system("clear");
								g2[i][j] = 1;

								printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
								c = 0;
								for (i = 0; i < 10; i++) {
									for (j = 0; j < 10; j++) {
										if (j == 0) {
											printf("%d   %d ", c, g2[i][j]);
											c++;
										}
										if (j != 9 && j != 0)
											printf("%d ", g2[i][j]);

										if (j == 9)
											printf("%d\n", g2[i][j]);
									}	
								}
								printf("\nVOCÊ ACERTOU A ÁGUA.\n");
								printf("Digite qualquer numero para continuar: ");
								scanf("%d", &next);
								ataque2 = 2;
								ataque1 = 0;
								verific2 = 0;
							}
							else if (p1[i][j] == 1) {
								system("clear");
								g2[i][j] = 2;

								printf("\n    0 1 2 3 4 5 6 7 8 9\n\n");
								c = 0;
								for (i = 0; i < 10; i++) {
									for (j = 0; j < 10; j++) {
										if (j == 0) {
											printf("%d   %d ", c, g2[i][j]);
											c++;
										}
										if (j != 9 && j != 0)
											printf("%d ", g2[i][j]);

										if (j == 9)
											printf("%d\n", g2[i][j]);
									}	
								}
								printf("\nVOCÊ ACERTOU UM NAVIO INIMIGO!\n Jogue novamente.\n");
								printf("Digite qualquer numero para jogar novamente: ");
								scanf("%d", &next);
							}
						}
					}
					while (verific2 == 0) {
						cont2 = 20;
						for (i = 0; i < 10; i++) {
							for (j = 0; j < 10; j++) {
								if (g2[i][j] == 2) {
									cont2--;
									if (cont2 == 0) {
										system("clear");
										printf("\nFIM DE JOGO. O VENCEDOR FOI O JOGADOR 1\n");
										printf("Digite qualquer numero para continuar: ");
										scanf("%d", &next);
										game++;
									}
									else
										verific2++;
								}
							}
						}
					}
				}
				
			break;

			case 3 :
				//encerrar o codigo
				principal++;
			break;

			default :
				//anunciar erro : opcao invalida
				printf("\nOPCAO INVALIDA!\n");
				printf("Digite algum numero para continuar: ");
				scanf("%d", &next);
			break;
		}
	}
}