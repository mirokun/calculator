#include <stdio.h>
#include <stdlib.h>

char getOperator();
float getNumber();
float getResult(float number, char operator);

int main() {

    float number;
    char operator;

    printf("Bitte Zahl eingeben:\n");
    number = getNumber();
    operator = getOperator();

    printf("Ergebnis: %f", getResult(number, operator));
    return 0;
}

char getOperator() {
    char operator;
    printf("Operator eingeben:\n");
    scanf(" %c", &operator);
    return operator;
}

float getNumber() {
    float number;
    printf("Zahl eingeben:\n");
    scanf("%f", &number);
    return number;
}

float getResult(float number, char operator) {
    if(operator == '=') {
        return number;
    }
    else {
        switch(operator)
        {
            case '+':
                number = number + getNumber();
                break;
            case '-':
                number = number - getNumber();
                break;
            case '/':
                number = number / getNumber();
                break;
            case '*':
                number = number * getNumber();
                break;
            default:
                printf("Kein Operator eingegeben!");
                exit(0);
        }
        operator = getOperator();
        number = getResult(number, operator);
    }
    return number;
}