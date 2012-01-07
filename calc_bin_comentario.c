#include <stdio.h>
#include <string.h>

#define BIT 8

void str_to_bin(int bin[], char str[]);

int soma_bin(int bin1[], int bin2[], int result[]);
void comp2(int bin[]);

int main(int argc, char* args[])
{ 
  int i, bin1[BIT], bin2[BIT], result[BIT],overf=0;
  
  str_to_bin(bin1,args[1]);//Converter primeiro numero binario para vector de inteiros
  str_to_bin(bin2,args[3]);//Mesmo para segundo numero binario
  
  if(!strcmp(args[2],"-")) //Se operando for "-", passar segundo numero a complemento para 2
    comp2(bin2);

  overf=soma_bin(bin1,bin2,result); //Fazer soma binaria guardando o resultado de overflow

  if(overf && (!strcmp(args[2],"+"))) //Se overflow==1 e o operando=="+", escrever Overflow
    {
      printf("Overflow\n");
      return 1;
    }

  for(i=0;i<BIT;i++) printf("%d", result[i]); printf("\n"); //Imprimir resultado
  
  return 0;
}

void str_to_bin(int bin[], char str[])
{  
  int i;
  for(i=0;i<BIT;i++) bin[i]=(int) (str[i]-'0');
}

int soma_bin(int bin1[], int bin2[], int result[])
{
  int aux, i, carry=0;
  for(i=BIT-1;i>=0;i--) //Algoritmo de soma binaria
    {
      aux=bin1[i]+bin2[i]+carry;
      carry=aux/2;
      result[i]=aux%2;
    }
  if(carry) return 1; //overflow
  else return 0;
}

void comp2(int bin[]) //Complemento para 2
{
  int aux[BIT], i;
  for(i=0;i<BIT;i++) if(bin[i]==0) bin[i]=1; else bin[i]=0; //Inverter binario
  for(i=0;i<BIT;i++) if(i==BIT-1) aux[i]=1; else aux[i]=0; //Criar binaro com valor 1
  soma_bin(bin,aux,bin); //Somar binario invertido e 1
}
