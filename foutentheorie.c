#include <stdio.h>
#include <math.h>

typedef struct
{
    double waarde;
    double af;
    double rf;
    int bc;

} record;

double convertToTwoBC(double, int);
void printDoubleWithBC(double, int);
int findAmountOfNumbersAfterKomma(double);
record sumUp(record, record);
record createRecord(double, double);
double calculateRF(double, double);

void print_record(const record *);

int main()
{   
    double waarde1, waarde2, af1, af2;
    char operator;
    printf("waarde 1: ");
    scanf("%lf",&waarde1);  
    printf("af 1: ");
    scanf("%lf",&af1);
    printf("operator (+)");
    scanf("%s",&operator);  
    printf("waarde 2: ");
    scanf("%lf",&waarde2);  
    printf("af 2: ");
    scanf("%lf",&af2);  
    printf("________\n\n");

    record a = {waarde1, af1};
    record b = {waarde2, af2};
    record res;
   

    switch(operator)
        case '+': res = sumUp(a,b);
        
   
    print_record(&res);
    return 0;
}

/* calculation formulas */
 record sumUp(record a, record b){
     double af = sqrt(pow(a.af,2) + pow(b.af,2));
     double waarde = a.waarde + b.waarde;
     record r =  createRecord(waarde, af);
     return r;
 }


/** formating and converting furnctions */

record createRecord(double waarde, double af){
    record b = {waarde, af, calculateRF(waarde,af) ,findAmountOfNumbersAfterKomma(af)};
    return b;
    };


double convertToTwoBC(double af, int numbersAfterKomma)
{
    int i;
    int j;
    j = numbersAfterKomma;
    for (i = 0; i < j; i++)
    {
        af *= 10;
    }
    af = round(af);

    af = af / pow(10, j);

    return af;
}

int findAmountOfNumbersAfterKomma(double af)
{
    int i = 0;

    while (round(af) == 0)
    {
        i++;
        af *= 10;
    }

    i++;
    return i;
}

double calculateRF(double waarde, double af){
    return af/waarde;
}


/* PRINT FUNCTIES */
void print_record(const record *rec)
{
    printDoubleWithBC(rec->waarde, rec->bc);
    printf(" ± ");
    printDoubleWithBC(rec->af, rec->bc);
    printf("\n");
}
void printDoubleWithBC(double a, int bc)
{
    int i;
    printf("%d.", (int)a); /*print cijfers voor de komma*/
    a -= (int)a;
    for (i = 0; i < bc; i++)
    {
        a *= 10;
        printf("%d", (int)a);
        a -= (int)a;
    }
}

