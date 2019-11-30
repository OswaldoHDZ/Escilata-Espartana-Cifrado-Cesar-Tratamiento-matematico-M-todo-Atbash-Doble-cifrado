#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h> 

int  validaEspaciosVaciosEnCadena(char a[100] );
void menu();//Menu principal
void escitalaEspartana();
void cifradoCesar();
void cesarCifrar(char arrCesar[2][26]);
char buscarCesarCifrar(char buscado,char arrCesar[2][26]);
void tratamientoMatematico();
char* convierteCadenaMayusculas(char cadena[],int longitudCadena);
int regresaValorLetra(char letra);
int realizaOperacioIndicada(int valorLetra);
void imprimeDecodificacionOperaMetetico(int arreglo[],int longitud);

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
    case 3:
        tratamientoMatematico();
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
    printf("---MENU---\n1. Escitala Espartana \n2. Cifrado Cesar \n3. Tratamiento matematico \n4. Método Atbash\n5. Doble cifrado\n Opcion ");
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
    if(validaEspaciosVaciosEnCadena(escitalaEspartana1)==0){
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


    }else{
                printf("Tienes espacios\n");
    }
}
//verifica espacioes si es 1 hay espacios
int validaEspaciosVaciosEnCadena(char a[] ){
    int i=0;
    int espacios = 0;
    for(i=0;i<30;i++){
            if(a[i]==' '){
                espacios = 1;
            }
    }
    return 0;
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
    case 2:printf("2");
        break;
    default:printf("\nInvalido...");
        break;
    }
}

void cesarCifrar(char arrCesar[2][26]){

    int tam=0;
    printf("Introduce tam arreglo\n");
    scanf("%d",&tam);
    fflush(stdin);//limpia el buffer si no marca error
    char arr[tam];
    printf("Introduce texto a cifrar:\n");
    scanf("%s",arr);
    fflush(stdin);
    printf("\n\n--Texto Introducido--");
    printf("\n%s",arr);
    printf("\n\n--Texto Cifrado--");
    for(int k;k<tam;k++){
    printf("%c",buscarCesarCifrar(arr[k],arrCesar));

    }
    printf("---------->%c",buscarCesarCifrar('B',arrCesar));
    for (int i = 0; i < tam; i++){
        printf("%d",i);
    }

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

//Esta funcion regresa una cadena en mayusculas, le ponemos al princio char* para que regrese la cadena completa y no solo u carater
//toupper funciona para hacer que cada cacter se convierta a mayuscula
char* convierteCadenaMayusculas(char cadena[],int longitudCadena){ 
    int i;
    for (i=0;i<longitudCadena;i++){
		cadena[i] = toupper(cadena[i]);
	}
    return cadena;
}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
void tratamientoMatematico(){
    char cadena[100];
    int i=0, longitudCadena;
    char letraBuscar;
    int valorLetra;
    int nuevoValor;
    int valoresDeCadenaCodificados[100];
    int logitudDEArreglo_valoresDeCadenaCodificados;
    printf("\n Estas en tratamiento matematico\n");
    printf("Ingresa Cadena ");
    scanf("%s",cadena);
    fflush(stdin);
    longitudCadena = strlen(cadena);
    printf("La longitud es: %d",longitudCadena);
    printf("\nVoy a imprimir nuevamente \n");
    char *cadenaMayusculas; //Declaramos *cadenaMayusculas como para que pueda resivir la cadena convertida a mayusculas
    cadenaMayusculas = convierteCadenaMayusculas(cadena,longitudCadena);
    for(i=0;i<longitudCadena;i++){
        printf("%c",cadenaMayusculas[i]);
    }
    printf("\n");
    for(i=0; i<longitudCadena;i++){
        letraBuscar = cadenaMayusculas[i];
        valorLetra  = regresaValorLetra(letraBuscar);
        printf("%d ",valorLetra); 
    }
    printf("\n");
    //El siguiente for imprime los valores convertidos con la operción
    for(i=0; i<longitudCadena;i++){
        letraBuscar = cadenaMayusculas[i];
        valorLetra  = regresaValorLetra(letraBuscar);
        nuevoValor  = realizaOperacioIndicada(valorLetra);
        valoresDeCadenaCodificados[i]= nuevoValor;
        printf("%d ",nuevoValor); //Si no quieres que imprima los valores, solo quita este printf
    }
    printf("\n");
    imprimeDecodificacionOperaMetetico(valoresDeCadenaCodificados,longitudCadena);
    //Imprimimos el valor de los elementos
    
}
//Esta funcion dada una letra regresa el valor de la letra deacuerdo a la tabla que es ta en el PDF en el punto Tratamiento matemático
int regresaValorLetra(char letra){
    char alfabeto[] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
    for (i=0;i<26;i++){
        if(letra == alfabeto[i]){ //Regresamos el valor de i porque es la posición correspondiente al valor de la letra
            return i;
        }
    }
    return 0;
}
//Realizar la operación indicada: C = (15 + 3) (mód 26) = 18.
//Deacuerdo al valor de la letra seralizamos la operación
int realizaOperacioIndicada(int valorLetra){
    int nuevoValor;
    nuevoValor = (valorLetra + 3) % 26;
    return nuevoValor;
}
//Decodifica el valor de cada letra
void imprimeDecodificacionOperaMetetico(int arreglo[],int longitud){
    int i = 0;
    int j = 0;
    char alfabeto[] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    printf("La cadena codificada es: ");
    for(i=0; i< longitud; i++){
        for (j = 0; j<26;j++){
            if(arreglo[i] == j){
                printf("%c",alfabeto[j]);
            }
        } 
    }
    printf("\n");
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
// void metodoAtbash(){

// }
// void dobleCifrado(){
    
// }
