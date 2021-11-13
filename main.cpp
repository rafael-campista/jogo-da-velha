#include <iostream>
using namespace std;

#define NLIN 3
#define NCOL 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void inicializarTabuleiro(char tabuleiro [NLIN][NCOL]){
	for(int i = 0; i < NLIN; i++){
		for(int j = 0; j < NCOL; j++){
			tabuleiro[i][j] = ' ';
		}
	}
}

void desenharTabuleiro(char tabuleiro [NLIN][NCOL]){
	int separadorColuna = 1;
	int separadorLinha = 1;
	printf("\n");
	for(int i = 0; i < NLIN ; i++){
		for(int j = 0; j < NCOL; j++){
			printf("%c", tabuleiro[i][j]);
			if(separadorColuna < NCOL){
				printf("|");
				separadorColuna++;
			} else {				
				separadorColuna = 1;
			}			
		}
		if(separadorLinha < NLIN){
			printf("\n-----\n");
			separadorLinha++;
		}
	}	
	printf("\n");
}

void mock(char tabuleiro [NLIN][NCOL]){
	tabuleiro[0][0] = 'X';
	tabuleiro[1][1] = 'O';
	tabuleiro[2][2] = 'X';
	tabuleiro[2][1] = 'O';
	tabuleiro[2][0] = 'X';
}

bool fazerJogada(char tabuleiro[NLIN][NCOL], int linha, int coluna, char simbolo/*X ou O*/){
	if(0 <= linha && linha > NLIN){
		return false;
	}
	if(0 <= coluna && coluna > NCOL){
		return false;
	}
	if(tabuleiro[linha - 1][coluna - 1] == ' '){
		tabuleiro[linha - 1][coluna - 1] = simbolo;
		return true;
	}
	return false;
}

char trocarJogador(char jogador){
	if(jogador == 'X')
		return 'O';
	return 'X';
}

bool jogadorAtualGanhou(char tabuleiro[NLIN][NCOL], char simboloJogadorAtual){
	//Verifica linhas
	if(tabuleiro[0][0] == simboloJogadorAtual && tabuleiro[0][1] == simboloJogadorAtual && tabuleiro[0][2] == simboloJogadorAtual) {
		return true;
	}
	if(tabuleiro[1][0] == simboloJogadorAtual && tabuleiro[1][1] == simboloJogadorAtual && tabuleiro[1][2] == simboloJogadorAtual) {
		return true;
	}
	if(tabuleiro[2][0] == simboloJogadorAtual && tabuleiro[2][1] == simboloJogadorAtual && tabuleiro[2][2] == simboloJogadorAtual) {
		return true;
	}
	
	//Verifica Colunas
	if(tabuleiro[0][0] == simboloJogadorAtual && tabuleiro[1][0] == simboloJogadorAtual && tabuleiro[2][0] == simboloJogadorAtual){
		return true;
	}
	
	if(tabuleiro[0][1] == simboloJogadorAtual && tabuleiro[1][1] == simboloJogadorAtual && tabuleiro[2][1] == simboloJogadorAtual){
		return true;
	}
	
	if(tabuleiro[0][2] == simboloJogadorAtual && tabuleiro[1][2] == simboloJogadorAtual && tabuleiro[2][2] == simboloJogadorAtual){
		return true;
	}
	
	//Verifica Diagonais
	if(tabuleiro[0][0] == simboloJogadorAtual && tabuleiro[1][1] == simboloJogadorAtual && tabuleiro[2][2] == simboloJogadorAtual) {
		return true;
	}
	
	if(tabuleiro[0][2] == simboloJogadorAtual && tabuleiro[1][1] == simboloJogadorAtual && tabuleiro[2][0] == simboloJogadorAtual) {
		return true;
	}
	
	return false;
}

bool deuVelha(char tabuleiro[NLIN][NCOL]){
	for(int i = 0; i < NLIN; i++){
		for(int j = 0; j < NCOL; j++){
			if(tabuleiro[i][j] == ' '){
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char** argv) {	
	char tabuleiro [NLIN][NCOL];
	
	inicializarTabuleiro(tabuleiro);	
	desenharTabuleiro(tabuleiro);	
	
	char simboloJogadorAtual = 'X';
	char simboloJogadorGanhador = ' ';
	bool jogoGanho = false;
	bool velha = false;	
	int linha;
	int coluna;
	
	while(!jogoGanho && !velha){
		cout << "Jogador Atual(" << simboloJogadorAtual << "):" << endl;
		cout << "Insira a linha(1-3):";
		cin >> linha;
		cout << endl;
		cout << "Insira a coluna(1-3):";
		cin >> coluna;
		cout << endl;
		if(fazerJogada(tabuleiro, linha, coluna, simboloJogadorAtual)){
			jogoGanho = jogadorAtualGanhou(tabuleiro, simboloJogadorAtual);
			if(jogoGanho){
				simboloJogadorGanhador = simboloJogadorAtual;
			} else {
				velha = deuVelha(tabuleiro);
				if(!velha){
					simboloJogadorAtual = trocarJogador(simboloJogadorAtual);
				}
			}
		} else {
			cout << "Jogada Invalida, tente novamente" << endl;
		}
		desenharTabuleiro(tabuleiro);
	}
	
	if(jogoGanho){
		cout << "Jogador " << simboloJogadorGanhador << " ganhou!";
	} else {
		cout << "### Deu Velha ###";
	}
	
			
}
