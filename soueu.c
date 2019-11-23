#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

long int mdc(long int num1, long int num2) {
    int resto;

    do {
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}

void fabio(char tarefa){
	long int n, s, v;
	long int verificar;
	char saida;
	long int r;
	char tar;
	long int r2;
	

	if(tarefa == 'I'){ //identificar
		//__uint128_t S;
		scanf("%li %li %li", &n, &s, &v); //receber n, s, v
		
		verificar = (((s * s) % n)* v)% n;
		/*S = s * s;
		S = S % n;
		S = S * v;
		verificar = S % n;
		*/
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
		long int y;
		long int x;
		
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
			printf("%li\n", x);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(/*saida == 'C' &&*/ tarefa == 'P'){
		long int y;
		long int x1;
		long int r1;
		scanf("%li", &r1);
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
			printf("%li\n", x1);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(/*saida == 'C' && */tarefa == 'R'){ //responder
		int b;
		long int xb;
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
			printf("%li\n", xb);
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

void patricia(char tarefa){
	long int n, v;
	int t;
	int verificar = 0;
	char saida;

	if(tarefa == 'I'){
		scanf("%li %li %d", &n, &v, &t); //receber n, v, t
		if(3 <= t && t <= 50){
			verificar = 1;
		}
		if(verificar == 1){
			saida = 'C';
			printf("%c\n", saida);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(tarefa == 'C'){
		long int x, xb;
		int b;
		long int x1;
		char saida;
		scanf("%li %d %li", &x, &b, &xb);
		if(b == 0){
			x1 = (xb * xb) % n;
			if(x1 == x){
				saida = 'C';
				printf("%c ", saida);
				printf("%d\n", --t);
			}
			else{
				saida = 'E';
				printf("%c ", saida);
				printf("%d\n", t);
			}
		}
		else if(b == 1){
			x1 = (xb * xb) % n;
			x1 = (x1 * v) % n;
			if(x1 == x){
				saida = 'C';
				printf("%c ", saida);
				printf("%d\n", --t);
			}
			else{
				saida = 'E';
				printf("%c ", saida);
				printf("%d\n", t);
			}
		}
	}

	if(tarefa == 'Q'){

	}

	if(tarefa == 'T'){ //identificar
		saida = 'C';
		printf("%c\n", saida);
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

			while(tarefa != 'T'){
				scanf("%c", &tarefa);
				patricia(tarefa);
			}
	}
	else if(*argv[1] == 'E'){

	}

	return 0;
}