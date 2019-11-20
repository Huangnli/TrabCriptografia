#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int mdc(int num1, int num2) {
    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}

void fabio(char tarefa){
	int n, s, v;
	int verificar;
	char saida;
	int r;
	char tar;
	int r2;
	

	if(tarefa == 'I'){ //identificar
		scanf("%d %d %d", &n, &s, &v); //receber n, s, v
		
		verificar = (((s * s) % n)* v)% n;
		
		if(verificar == 1){  //saida C ou E
			saida = 'C';
			printf("%c\n", saida);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(saida == 'C' && tarefa == 'X'){ //iniciar
		srand ((unsigned)time(NULL));
		r = rand();//geral um r aleatorio
		int y;
		int x;
		
		y = mdc (r, n);
		while(y != 1){
			r = rand();//geral outro r
			y = mdc (n, r);

		}
		r = r * r;
		x = r % n;
		if(verificar == 1){  //saida C ou E
			saida = 'C';
			printf("%c ", saida);
			printf("%d\n", x);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(saida == 'C' && tarefa == 'P'){
		int y;
		int x1;
		int r1;
		scanf("%d", &r1);
		r2 = r1;
		y = mdc (r1, n);
		if(y == 1){
			verificar = 1;
		}
		else{
			verificar = 0;
		}
		if(verificar == 1){
			r1 = r1 * r1;
			x1 = r1 % n;
			saida = 'C';
			printf("%c ", saida);
			printf("%d\n", x1);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(saida == 'C' && tarefa == 'R'){ //responder
		int b;
		int xb;
		scanf("%d", &b);
		//printf("%d  ", b);
		if(b == 1 || b == 0){
			verificar = 1;
		}
		else{
			verificar = 0;
		}
		if(b == 0){
			xb = r2;
		}
		else if(b == 1){
				xb = (r2 * s)% n;

		}
		r2 = 0;
		if(verificar == 1){  //saida C ou E
			saida = 'C';
			printf("%c ", saida);
			printf("%d\n", xb);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}
	if(tarefa == 'T'){ //identificar
		saida = 'C';
		printf("%c\n", saida);
	}
}

void teodoro (char tarefa){
	int p = -1;
	int q = -1;
	int n;
	char saida;
	int v;
	int s;

	if(tarefa == 'I'){
		scanf("%d %d", &p, &q); //receber p, q
		n = p * q;
		if(p == -1 || q == -1){
			saida = 'E';
			printf("%c\n", saida);
		}
		else{
			tarefa = 'A';
		}
	}

	if(tarefa == 'A'){
		int num;
		int a;
		int resto;
		int q;

		num = mdc(a, n);
		if(num == 1){
			while(resto > 0){
				q = a / n;
				resto = a % n;
				
			}
		}
		else{
			saida = 'E';
		}
	}

}

int main(int argc, char *argv[]){
	char tarefa;

	if(*argv[1] == 'T'){
		scanf("%c", &tarefa);
		teodoro(tarefa);
	}
	else if(*argv[1] == 'F'){

			while(tarefa != 'T'){
				scanf("%c", &tarefa);
				fabio(tarefa);
			}	
	}
	else if(*argv[1] == 'P'){

	}
	else if(*argv[1] == 'E'){

	}

	return 0;
}
