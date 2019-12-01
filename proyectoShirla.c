#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

int espacioVaciosValidar(char a[100],int tam );
void menu();//Menu principal
void escitalaEspartana();
void cifradoCesar();
void cesarCifrar(char arrCesar[2][26]);
void cesarDecifrar(char arrCesar[2][26]);
char buscarCesarCifrar(char buscado,char arrCesar[2][26]);
char buscarCesarDeCifrar(char buscado,char arrCesar[2][26]);

// void tratamientoMatematico(); 
// void metodoAtbash();
void dobleCifrado();
char regresaSifradoUno(char buscado,char arr[3][26]);
char regresaSifradoDos(char buscado,char arr[3][26]);

int main(){
    
    int n;
        menu();
        scanf("%d",&n);
        fflush(stdin);
        switch (n)        {
        case 1:escitalaEspartana();
            break;
        case 2:cifradoCesar();
            break;
        case 3:printf("123");
            break;
        case 4:printf("123");
            break;
        case 5:dobleCifrado();
            break;

        default:printf("Error\n");
            break;
        }
return 0;
}

void menu(){
    printf("---MENU---\n\n1. Escitala Espartana \n2. Cifrado Cesar \n3. Tratamiento matematico \n4. Método Atbash\n5. Doble cifrado");
    printf("\n\nOPCION: ");
}
void escitalaEspartana(){
    int i,j;
    int cont=0;
    int limit=0;
    int tamCad=0;
    char escitalaEspartana1 [30];
    char escitalaEspartana [3][9];
    char decifradoEscitalaEspartana [3][9];

    //system("cls");
    for(i=0;i<30;i++){
        escitalaEspartana1[i]='*';
    }
        for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                escitalaEspartana [i][j]=escitalaEspartana1[cont];
                cont++;
            }
        }
        cont=0;
    
    printf("Ingresa Tama De Cadena\n");
    scanf("%d",&tamCad);
    fflush(stdin);
    printf("Ingresa Cadena\n");
    scanf("%s",escitalaEspartana1);
    if(espacioVaciosValidar(escitalaEspartana1,30)==0){
        for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                if(cont<tamCad){
                    escitalaEspartana [i][j]=escitalaEspartana1[cont];
                    cont++;
                }
            }
        }
        printf("\nEntrada:\n");
        cont=0;
        for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                if(cont<tamCad){
                    printf("%c",escitalaEspartana [i][j]);
                cont++;

                }
            }
        }

        printf("\n\n---Matriz:---\n");
        for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                    printf("%c",escitalaEspartana [i][j]);
                }
                 printf("\n");
        }
        
        printf("\n---Cifrado:---\n");
        for(j=0;j<9;j++){
            for(i=0;i<3;i++){
                decifradoEscitalaEspartana[i][j]=escitalaEspartana [i][j];
                if(escitalaEspartana [i][j]!='*'){
                    printf("%c",escitalaEspartana [i][j]);
                }
             }
        }

        printf("\n---De cifrado:---\n");
        for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                if(decifradoEscitalaEspartana[i][j]!='*'){
                    printf("%c",decifradoEscitalaEspartana[i][j]);
                }
             }
        }

        printf("\n");


    }else{
                printf("Tienes espacios\n");
    }
}

//verifica espacioes si es 1 hay espacios
int espacioVaciosValidar(char a[],int tam ){
    int i,j=0;
    for(i=0;i<tam;i++){
            if(a[i]==' '){
                j= 1;
            }
    }
    return j;
}

void cifradoCesar (){
    int n,j,i;
    char arrCesar[2][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
                          {'X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'}};
    system("cls");
    printf("---CESAR---\n\n");
    printf("--Caesar cipher table--\n");
    //imprime tabla cesar 
    for(i=0;i<2;i++){
        for(j=0;j<26;j++){
            printf("%c",arrCesar[i][j]);
        }
            printf("\n");
    }
    printf("\n");
    printf("1) cifrar\n2) descifrar\n");
    scanf("%d",&n);//selecciona opcion
    fflush(stdin);
    switch (n){
    case 1:cesarCifrar(arrCesar); //llama a la funcion que cifra
        break;
    case 2:cesarDecifrar(arrCesar); //llama a la funcion que decifra
        break;
    default:printf("\nInvalido...");
        break;
    }
}

void cesarDecifrar(char arrCesar[2][26]){

    int tam=0;
    printf("Introduce tam arreglo\n");
    scanf("%d",&tam);
    fflush(stdin);//limpia el buffer si no marca error
    char arr[tam];
    printf("Introduce texto a cifrar:\n");
    scanf("%s",arr);
    fflush(stdin);


   if(espacioVaciosValidar(arr,tam)==0){
    printf("\n\n--Texto Introducido--");
    printf("\n> %s",arr);
    printf("\n\n--Texto Cifrado--");
    printf("\n> ");

    for(int k=0;k<tam;k++){//CONSTRU CIFRADO 
        printf("%c",buscarCesarDeCifrar(toupper(arr[k]),arrCesar));
    }
    printf("\n");
    }else{
                printf("Tienes espacios\n");
    }

}


void cesarCifrar(char arrCesar[2][26]){

    int tam=0;
    printf("Introduce tam arreglo\n");
    scanf("%d",&tam);
    fflush(stdin);//limpia el buffer si no marca error
    char arr[tam];
    printf("Introduce texto a decifrar:\n");
    scanf("%s",arr);
    fflush(stdin);


    if(espacioVaciosValidar(arr,tam)==0){
    printf("\n\n--Texto Introducido--");
    printf("\n> %s",arr);
    printf("\n\n--Texto Decifrado--");
    printf("\n> ");

    for(int k=0;k<tam;k++){//CONSTRU CIFRADO 
        printf("%c",buscarCesarCifrar(toupper(arr[k]),arrCesar));
    }
    printf("\n");
    }else{
                printf("Tienes espacios\n");
    }
}

char buscarCesarDeCifrar(char buscado,char arrCesar[2][26]){
int i;
char a='*';
    for(i=0;i<26;i++){
      if( buscado==arrCesar[1][i]){
          a=arrCesar[0][i];
      } 
    }
return a;
}

char buscarCesarCifrar(char buscado,char arrCesar[2][26]){
int i;
char a='*';
    for(i=0;i<26;i++){
      if( buscado==arrCesar[0][i]){
          a= arrCesar[1][i];
      } 
    }
return a;
}

// void tratamientoMatematico(){

// } 
// void metodoAtbash(){

// }

void dobleCifrado(){
    int tam=0,i;
    char arrDobleCifrado[3][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
                                {'F','R','J','O','Y','D','I','Q','T','Z','S','L','M','E','U','N','B','K','W','A','H','P','C','X','G','V'},
                                {'H','T','R','V','Z','D','I','Q','J','Y','P','E','L','M','U','B','N','K','A','W','F','S','X','C','G','O'}};
    printf("--DOBLE CIFRADO--\n\n");

    printf("\n--TABLA DOBLE CIFRADO--\n");

    for (int p = 0; p < 3; p++)
    {
        for (int q = 0; q < 26; q++)
        {
          printf("%c",arrDobleCifrado[p][q]);

        }
         printf("\n");
    }
         printf("\n");
    

    printf("Tamanio de texto:\n");
    scanf("%d",&tam);

    char cifrado[tam];
    char cifradoTem[tam];

    printf("Introduce texto:\n");
    scanf("%s",cifrado);

    if(espacioVaciosValidar(cifrado,tam)==0){

 
    fflush(stdin);
    printf("\n\n--Texto Introducido--");
    printf("\n> %s",cifrado);
//sifrado uno
printf("\n\n--Sifrado uno--");
    for (i = 0; i < tam; i++){
        cifradoTem[i]=regresaSifradoUno(toupper(cifrado[i]),arrDobleCifrado);
    }
    printf("\n> %s",cifradoTem);
//sifrado dos
    printf("\n\n--Sifrado dos--");
    for (i = 0; i < tam; i++){
       cifrado[i]= regresaSifradoDos(toupper(cifradoTem[i]),arrDobleCifrado);
       
    }
    printf("\n> %s",cifrado);
    printf("\n");
   }else{
            printf("Tienes espacios\n");
   }
}

char regresaSifradoUno(char buscado,char arr[3][26]){
int i;
char a='*';
    for(i=0;i<26;i++){
      if( buscado==arr[0][i]){
          a= arr[1][i];
      } 
    }
return a;
}

char regresaSifradoDos(char buscado,char arr[3][26]){
int i;
char a='*';
    for(i=0;i<26;i++){
      if( buscado==arr[1][i]){
          a= arr[2][i];
      } 
    }
return a;
}