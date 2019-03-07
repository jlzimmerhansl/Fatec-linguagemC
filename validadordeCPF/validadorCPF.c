#include <stdio.h>
#include <stdlib.h>

int VerificarDigito(int cpf[11], int multiplicador[11]){

	int resto = 0, soma = 0, i;

	for(i = 0; i < 10; i++){
		soma += cpf[i] * multiplicador[i];
		resto = (soma * 10)%11;
	}

	if(resto == 10){
		printf("Cpf nao valido");
	}
	else{
		return resto;
	}
}

int main(){
	int cpf[11];
	int multipicadorPrimeiroDigito[9] = {10,9,8,7,6,5,4,3,2};
	int multiplicadorSegundoDigito[10] = {11,10,9,8,7,6,5,4,3,2};
	long long numeroCpf;

	printf("Digite o número do CPF: ");

	scanf("%lli", &numeroCpf);

	if(numeroCpf == ""){
		printf("Numero nao valido");
	}
	else{
		cpf[0] = numeroCpf / 10000000000;
		cpf[1] = (numeroCpf/ 1000000000) %10;
		cpf[2] = (numeroCpf/ 100000000) %10;
		cpf[3] = (numeroCpf/ 10000000) %10;
		cpf[4] = (numeroCpf/ 1000000) %10;
		cpf[5] = (numeroCpf/ 100000) %10;
		cpf[6] = (numeroCpf/ 10000) %10;
		cpf[7] = (numeroCpf/ 1000) %10;
		cpf[8] = (numeroCpf/ 100) %10;
		cpf[9] = (numeroCpf/ 10) %10;
		cpf[10] = numeroCpf%10;
	}


	if(cpf[0] == cpf[1] && cpf[1] == cpf[2] && cpf[2] == cpf[3] &&
	   cpf[3] == cpf[4] && cpf[4] == cpf[5] && cpf[5] == cpf[6] &&
	   cpf[6] == cpf[7] && cpf[7] == cpf[8] && cpf[8] == cpf[9] &&
	   cpf[9] == cpf[10]){
		printf("não valido", cpf);
	}
	else{
		int digito1 = VerificarDigito(cpf, multipicadorPrimeiroDigito);
		int digito2 = VerificarDigito(cpf, multiplicadorSegundoDigito);

		if(digito1 == cpf[9] && digito2 == cpf[10]){
			printf("Cpf valido");
		}
		else{
			printf("Cpf nao valido ");
		}
	}


}
