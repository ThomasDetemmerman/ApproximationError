#include <stdio.h>
#include <math.h>

typedef struct
{
    double waarde;
    double af;
    int bc;

} record;

double convertToTwoBC(double, int);
void printDoubleWithBC(double, int);
int findAmountOfNumbersAfterKomma(double);
record sumUp(record, record);


void print_record(const record *);

int main()
{
    
    int bca = findAmountOfNumbersAfterKomma(0.0067);
    int bcb = findAmountOfNumbersAfterKomma(0.0067);
    record a = {100.2, 0.0067, bca};
    record b = {100.23, 0.01, bcb};
    record res = sumUp(a,b);
    print_record(&res);
}

/* calculation formulas */
 record sumUp(record a, record b){
     double af = sqrt(pow(a.af,2) + pow(b.af,2));
     double waarde = a.waarde + b.waarde;
     int bc = findAmountOfNumbersAfterKomma(af);
     record res = {waarde , af, bc};
     return res;
 }

/** formating and converting furnctions */
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

