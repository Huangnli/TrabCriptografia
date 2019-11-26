#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

long int mdc(long int num1, long int num2) {
    long int resto;

    do {
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}

long int verifica(long int s, long int n, long int v){
	long int verificar;
	verificar = ((((__uint128_t)s * s) % n)* v)% n;
	return verificar;
}

long int prepararX(long int r, long int r1, long int n){
	long int x;
	x = (((__uint128_t)r * r1) % n);
	return x;
}

long int gerarRS(long int n){
	long int r;
	unsigned long int nn =  n;
	unsigned long int r1[2];
	int aux;

	r1[0] = 2;
	r1[1] = n;

	srand ((unsigned)time(NULL));
	r = rand();//geral um r aleatorio
	while(r1[0] + 1 != r1[1]){
		aux = r % 2;
		//printf("%d\n", aux);
		if(aux == 0){
			r1[0] = (r1[0] + r1[1]) / 2;
		//	printf("%li\n", r1[0]);
		}
		else{
			r1[1] = (r1[0] + r1[1]) / 2;
		//	printf("%li\n", r1[1]);
		}
		//srand((unsigned)time(NULL));
		r = rand();//geral um r aleatorio
	}
	r = rand();
	aux = r % 2;
	if(aux == 1){
		r = r1[1];
	}
	else{
		r = r1[0];
	}
	//printf("%li\n", r );
	return r;
}

void fabio(char tarefa){
	long int n, s, v;
	long int verificar;
	char saida;
	long int r;
	char tar;
	long int r2;
	int PR, RP = 1;

	if(tarefa == 'I'){ //identificar
		//__uint128_t S;
		scanf("%li %li %li", &n, &s, &v); //receber n, s, v
		
		verificar = verifica(s, n, v);

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
		//srand ((unsigned)time(NULL));
		//r = rand();//geral um r aleatorio
		long int y;
		long int x;

		r = gerarRS(n);
		y = mdc (r, n);
		while(y != 1){
			r = gerarRS(n);//geral outro r
			y = mdc (n, r);
		}
		//r = r * r;
		//x = r % n;
		x = prepararX(r, r, n);
		if(verificar == 1 ){  //saida C ou E
			saida = 'C';
			printf("%c ", saida);
			printf("%li\n", x);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(tarefa == 'P'){
		long int y;
		long int x1;
		long int r1;
		scanf("%li", &r1);
		r2 = r1;
		y = mdc (r1, n);
	
		if(y == 1 && r1 < n){
			//r1 = r1 * r1;
			//x1 = r1 % n;
			x1 = prepararX(r1, r1, n);
			saida = 'C';
			printf("%c ", saida);
			saida = 'R';
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
			//xb = (r2 * s)% n;
			xb = prepararX(r2, s, n);
		}
		r2 = 0;
		if(verificar == 1 && saida == 'R'){  //saida C ou E
			saida = 'C';
			printf("%c ", saida);
			saida = 'P';
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

long int euclide(long int s, long int n){
	long int euclides[100][4];
	long int v;
	int i = 1;

	euclides[0][0] = s;
	euclides[1][0] = n;
	euclides[0][2] = 1;
	euclides[1][2] = 0;
	euclides[0][3] = 0;
	euclides[1][3] = 1;
	while(euclides[i][0] > 1){
		i++;
		euclides[i][0] = euclides[i-2][0] % euclides[i-1][0];  
	}
	i = 1;
	while(euclides[i][0] > 1){
		i++;
		euclides[i][1] = euclides[i-2][0] / euclides[i-1][0];  
	}
	i = 2;
	while(euclides[i-1][0] > 1){
		euclides[i][2] = euclides[i-2][2] - (euclides[i][1] * euclides[i-1][2]);
		euclides[i][3] = euclides[i-2][3] - (euclides[i][1] * euclides[i-1][3]);
		i++;
	}
	//for(int k = 0; k < i; k++){
		//printf("%li\n", euclides[k][0]);
		//printf("%li\n", euclides[i-1][2]);
		//printf("%li\n", euclides[k][3]);
	//}
	if(euclides[i-1][3] >= 0){
		v = euclides[i-1][3];
	}
	else{
		v = euclides[i-1][3] + s; 
	}
	return v;
}

void teodoro (char tarefa){
	long int p = -1;
	long int q = -1;
	long int n;
	char saida;
	long int euclides[100][4];

	if(tarefa == 'I'){
		scanf("%li %li", &p, &q); //receber p, q
		n = p * q;
		if(p == -1 || q == -1){
			saida = 'E';
			printf("%c ", saida);
		}
		else{
			saida = 'C';
			printf("%c ", saida);
			printf("%li\n", n);
		}
	}

	if(tarefa == 'F'){
		long int s;
		long int v;
		long int ss;
		long int verificar;
		scanf("%li", &s);
		ss = s * s;
		v = euclide(n, ss);
		//verificar = (((s * s) % n)* v)% n;
		//printf("%li %li %li\n", s, n, v);
		verificar = verifica(s, n, v);
		if(verificar == 1 && s < n){
			saida = 'C';
			printf("%c ", saida);
			printf("%li\n", v);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(tarefa == 'A'){
		long int gs;
		long int v;
		long int gss;
		long int verificar;

		gs = gerarRS(n);
		gss = gs * gs;
		v = euclide(n, gss);
		//verificar = (((s * s) % n)* v)% n;
		verificar = verifica(gs, n, v);
		if(verificar == 1){
			saida = 'C';
			printf("%c ", saida);
			printf("%li %li\n", v, gs);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}
	if(tarefa == 'T'){
		saida = 'C';
		printf("%c\n", saida);
	}
}

void patricia(char tarefa){
	long int n, v;
	int t;
	int verificar = 0;
	char saida;
	long int X;
	int bit;
	int Ifeito;
	int i;
	
	if(tarefa == 'I'){
		scanf("%li %li %d", &n, &v, &t); //receber n, v, t
		i = t;
		if(3 <= t && t <= 50){
			verificar = 1;
		}
		if(verificar == 1){
			Ifeito = 1;
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
		if(t == 0){
			saida = 'E';
			printf("%c ", saida);
			printf("%d\n", t);
		}else{

			if(b == 0){
				//x1 = (xb * xb) % n;
				x1 = prepararX(xb, xb, n);
				if(x1 == x){
					saida = 'C';
					printf("%c ", saida);
					printf("%d\n", --t);
				}
				else{
					saida = 'E';
					printf("%c ", saida);
					printf("%d\n", t);
					t = i;
				}
			}
			else if(b == 1){
				//x1 = (xb * xb) % n;
				//x1 = (x1 * v) % n;
				x1 = prepararX(xb, xb, n);
				x1 = prepararX(x1, v, n);
				if(x1 == x){
					saida = 'C';
					printf("%c ", saida);
					printf("%d\n", --t);
				}
				else{
					saida = 'E';
					printf("%c ", saida);
					printf("%d\n", t);
					t = i;
				}
			}
		}
	}

	if(tarefa == 'Q'){
		long int aleatorio;  
		if(Ifeito == 1){
			scanf("%li", &X);
			aleatorio = gerarRS(n);
			aleatorio = aleatorio % 2; //bit aleatorio
			bit = aleatorio;
			saida = 'C';
			printf("%c ", saida);
			printf("%li\n", aleatorio);
			Ifeito = 0;
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(tarefa == 'V'){
		long int xb;
		long int x1;
		scanf("%li", &xb);
		Ifeito = 1;
		if(t == 0){
			saida = 'E';
			printf("%c ", saida);
			printf("%d\n", t);
		}else{
			
			if(bit == 0){
				x1 = prepararX(xb, xb, n);
				if(x1 == X){
					saida = 'C';
					printf("%c ", saida);
					printf("%d\n", --t);
				}
				else{
					saida = 'E';
					printf("%c ", saida);
					printf("%d\n", t);
					t = i;
				}
			}
			else if(bit == 1){
				x1 = prepararX(xb, xb, n);
				x1 = prepararX(x1, v, n);
				if(x1 == X){
					saida = 'C';
					printf("%c ", saida);
					printf("%d\n", --t);
				}
				else{
					saida = 'E';
					printf("%c ", saida);
					printf("%d\n", t);
					t = i;
				}
			}
		}
	}

	if(tarefa == 'T'){ //identificar
		saida = 'C';
		printf("%c\n", saida);
	}
}

void ester(char tarefa){
	long int n;
	long int v;
	char saida;

	if(tarefa == 'I'){
		scanf("%li %li", &n, &v);
		saida = 'C';
		printf("%c ", saida);

	}

	if(tarefa == 'P'){
		long int y;
		long int x;
		long int r;
		int b;
		long int xb;

		r = gerarRS(n);
		y = mdc (r, n);
		while(y != 1){
			r = gerarRS(n);//geral outro r
			y = mdc (n, r);
		}
		//r = r * r;
		//x = r % n;
		x = prepararX(r, r, n);

		scanf("%d", b);
		if(b == 0){
			xb = r;
		}
		else if(b == 1){
			//xb = (r2 * s)% n;
			//xb = prepararX(r, s, n);
		}
		r = 0;
		if(r == 0){  //saida C ou E
			saida = 'C';
			printf("%c ", saida);
			printf("%li\n", x);
		}
		else{
			saida = 'E';
			printf("%c\n", saida);
		}
	}

	if(tarefa == 'S'){
		long int x0;
		long int x1;
		scanf("%li %li", &x0, &x1);
	}

	if(tarefa == 'T'){ 
		saida = 'C';
		printf("%c\n", saida);
	}
}

int main(int argc, char *argv[]){
	char tarefa;

	if(*argv[1] == 'T'){
		while(tarefa != 'T'){
			scanf("%c", &tarefa);
			teodoro(tarefa);
		}
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

		while(tarefa != 'T'){
			scanf("%c", &tarefa);
			ester(tarefa);
		}
	}

	return 0;
}
