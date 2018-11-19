#include <stdio.h>
#include <string.h>
#include <math.h>

float evaluateExpression(char command []);
float evaluateTerm(char command []);
float evaluateFactor(char command []);

int main() {
	char masukan [100], c;
	
	fgets(masukan, sizeof masukan, stdin);
	masukan[strcspn(masukan, "\n")] = 0;
	printf("%f\n", evaluateExpression(masukan));
	
	return 0;
}

float evaluateExpression(char command []){
	char first;
	float termValue;
	
	termValue = evaluateTerm(command);
	first = command[0];
	if(first == '+'){
		memmove(&command[0], &command[1], strlen(command) - 0);
		if(command[0] == '-' || command[0] == '^' || command[0] == '+' || command[0] == '^' || command[0] == '-' || command[0] == '*' || command[0] == '/'){
			printf("Syntax error!\n");
			return 0;
		}
		return termValue + evaluateExpression(command); /* E -> E + T */
	} else if(first == '-'){
		memmove(&command[0], &command[1], strlen(command) - 0);
		if(command[0] == '-' || command[0] == '^' || command[0] == '+' || command[0] == '^' || command[0] == '-' || command[0] == '*' || command[0] == '/'){
			printf("Syntax error!\n");
			return 0;
		}
		return termValue - evaluateExpression(command); /* E -> E - T */
	} else if(first == '^'){
		memmove(&command[0], &command[1], strlen(command) - 0);
		if(command[0] == '-' || command[0] == '^' || command[0] == '+' || command[0] == '^' || command[0] == '-' || command[0] == '*' || command[0] == '/'){
			printf("Syntax error!\n");
			return 0;
		}
		return pow(termValue, evaluateExpression(command)); /* E -> E ^ T */
	} else {
		return termValue; /* E -> T */
	}
}

float evaluateTerm(char command []){
	char first;
	float factorValue;
	
	factorValue = evaluateFactor(command);
	first = command[0];
	if(first == '*'){
		memmove(&command[0], &command[1], strlen(command) - 0);
		if(command[0] == '-' || command[0] == '^' || command[0] == '+' || command[0] == '^' || command[0] == '-' || command[0] == '*' || command[0] == '/'){
			printf("Syntax error!\n");
			return 0;
		}
		return factorValue * evaluateTerm(command); /* T -> T * F */
	} else if(first == '/'){
		memmove(&command[0], &command[1], strlen(command) - 0);
		if(command[0] == '-' || command[0] == '^' || command[0] == '+' || command[0] == '^' || command[0] == '-' || command[0] == '*' || command[0] == '/'){
			printf("Syntax error!\n");
			return 0;
		}
		return factorValue / evaluateTerm(command); /* T -> T - F */
	} else {
		return factorValue; /* T -> F */
	}
}

float evaluateFactor(char command []){
	char first;
	float number, numberV;
	
	first = command[0];
	if(first == '('){
		memmove(&command[0], &command[1], strlen(command) - 0);
		if(command[0] == '-' || command[0] == '^' || command[0] == '+' || command[0] == '^' || command[0] == '-' || command[0] == '*' || command[0] == '/'){
			printf("Syntax error!\n");
			return 0;
		}
		numberV = evaluateExpression(command);
		first = command[0];
		if(first == ')'){
			memmove(&command[0], &command[1], strlen(command) - 0);
			return numberV;  /* F -> (E) */
		} else {
			printf("Syntax error!\n");
		}
	} else if(first >= '0' && first <= '9'){
		number = 0;
		while(first >= '0' && first <= '9'){
			switch(first){
				case '0' : number = (number*10) + 0;
						break;
				case '1' : number = (number*10) + 1;
						break;
				case '2' : number = (number*10) + 2;
						break;
				case '3' : number = (number*10) + 3;
						break;
				case '4' : number = (number*10) + 4;
						break;
				case '5' : number = (number*10) + 5;
						break;
				case '6' : number = (number*10) + 6;
						break;
				case '7' : number = (number*10) + 7;
						break;
				case '8' : number = (number*10) + 8;
						break;
				case '9' : number = (number*10) + 9;
						break;
			}
			memmove(&command[0], &command[1], strlen(command) - 0);
			first = command[0];
		}
		return number;  /* F -> n */
	} else if(command[0] == '-' || command[0] == '^' || command[0] == '+' || command[0] == '^' || command[0] == '-' || command[0] == '*' || command[0] == '/'){
		printf("Syntax error!\n");
		return 0;
	}
}
