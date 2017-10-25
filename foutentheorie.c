#include <stdio.h>
#include <math.h>


double convertToTwoBC(double, int);
void printDoubleWithBC(double, int);
int findAmountOfNumbersAfterKomma(double);
typedef struct{
    double waarde;
    double af;
    int bc;

} record;
void print_record(const record*);

int main(){
double waarde = 100.2333;
double af = 0.003344;
int bc = findAmountOfNumbersAfterKomma(af);
record rec = {100.2,0.0067,3};
print_record(&rec);
/*int numbersAfterKomma;
numbersAfterKomma = findAmountOfNumbersAfterKomma(0.0020);
printf("%f", convertToTwoBC(100.00196456,numbersAfterKomma));*/
}


double convertToTwoBC(double af, int numbersAfterKomma){
    int i;
    int j;
    j= numbersAfterKomma; 
    for(i=0; i < j; i++)
      {  
        af *= 10;
        
    }
     af = round(af);
    
    af = af / pow(10, j);
   
return af;
}

int findAmountOfNumbersAfterKomma(double af){
    int i=0;
   
    while(round(af)==0){
        i++;
        af *= 10;
        
    }

    i++;
    return i;

}
/* PRINT FUNCTIES */
void print_record(const record* rec){
     printDoubleWithBC(rec->waarde, rec->bc);
     printf(" ± ");
     printDoubleWithBC(rec->af, rec->bc);
     printf("\n");
 }
 void printDoubleWithBC(double a, int bc){
     int i;
     printf("%d.",(int)a);/*print cijfers voor de komma*/
     a -= (int)a;
     for(i = 0; i < bc; i++){
         a *= 10;
         printf("%d",(int)a);
         a -= (int)a;
 }
 }

 