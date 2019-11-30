#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

int espacioVaciosValidarEscitalaEspartana(char a[30] );
void menu();//Menu principal
void escitalaEspartana();
void cifradoCesar();
void cesarCifrar(char arrCesar[2][26]);
void cesarDecifrar(char arrCesar[2][26]);
char buscarCesarCifrar(char buscado,char arrCesar[2][26]);
char buscarCesarDeCifrar(char buscado,char arrCesar[2][26]);

// void tratamientoMatematico(); 
// void metodoAtbash();
// void dobleCifrado();
int main(){
    
    int n;
        menu();
        scanf("%d",&n);
        switch (n)        {
        case 1:escitalaEspartana();
            break;
        case 2:cifradoCesar();
            break;
        case 3:printf("123");
            break;
        case 4:printf("123");
            break;
        case 5:printf("123");
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
    system("cls");
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
    printf("Ingresa Cadena\n");
    scanf("%s",escitalaEspartana1);
    fflush(stdin);
   // if(espacioVaciosValidarEscitalaEspartana(escitalaEspartana1)==0){
    printf("Ingresa Tama De Cadena\n");
    scanf("%d",&tamCad);
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
                if(escitalaEspartana [i][j]!='*'){
                    printf("%c",escitalaEspartana [i][j]);
                }
             }
        }
        printf("\n");


    // }else{
    //             printf("Tienes espacios\n");
    // }
}
//verifica espacioes si es 1 hay espacios
int espacioVaciosValidarEscitalaEspartana(char a[] ){
    int i=0;
    for(i=0;i<30;i++){
            if(a[i]==' '){
                i= 1;
            }
    }
    return i;
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
    printf("\n\n--Texto Introducido--");
    printf("\n> %s",arr);
    printf("\n\n--Texto Cifrado--");
    printf("\n> ");

    for(int k=0;k<tam;k++){//CONSTRU CIFRADO 
        printf("%c",buscarCesarDeCifrar(toupper(arr[k]),arrCesar));
    }
    printf("\n");
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
    printf("\n\n--Texto Introducido--");
    printf("\n> %s",arr);
    printf("\n\n--Texto decifrado--");
    printf("\n> ");

    for(int k=0;k<tam;k++){//CONSTRU CIFRADO 
        printf("%c",buscarCesarCifrar(toupper(arr[k]),arrCesar));
    }
    printf("\n");
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
// void dobleCifrado(){
    
// }
