#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

int espacioVaciosValidar(char a[100],int tam );
void menu();//Menu principal
int verificaCadenaSinNumero(char cadena[],int longitudCadena);
//--------------------------------------------------------------
void escitalaEspartana();
void cifradoCesar();
void cesarCifrar(char arrCesar[2][26]);
void cesarDecifrar(char arrCesar[2][26]);
char buscarCesarCifrar(char buscado,char arrCesar[2][26]);
char buscarCesarDeCifrar(char buscado,char arrCesar[2][26]);
//--------------------------------------------------------------
void tratamientoMatematico();
char* convierteCadenaMayusculas(char cadena[],int longitudCadena); //Se pone char* asterisco porque regresa un arreglo | Con char[] pero no se puede : https://foro.elhacker.net/programacion_cc/c_funcion_que_retorne_arrays-t84925.0.html
int regresaValorLetra(char letra);
int realizaOperacioIndicada(int valorLetra);
char* imprimeCodificacionOperaMetetico(int arreglo[],int longitud, char cadenaCodificada[]);
int realizaOperacioIndicadaDepeje(int valorLetra);
//-------------------------------------------------------------- 
void metodoAtbash();
char* codificaBash(int arreglo[], int longitud,char cadenaCodificada[]); //Se pone char* asterisco porque regresa un arreglo | Con char[] pero no se puede : https://foro.elhacker.net/programacion_cc/c_funcion_que_retorne_arrays-t84925.0.html
void dobleCifrado();
//--------------------------------------------------------------
char regresaSifradoUno(char buscado,char arr[3][26]);
char regresaSifradoDos(char buscado,char arr[3][26]);
char regresaDecifradoDos(char buscado,char arr[3][26]);
char regresaDecifradoUno(char buscado,char arr[3][26]);
char* convierteCadenaMayusculas(char cadena[],int longitudCadena);

int main(){
    
    int n;
        menu();
        scanf("%d",&n);
        fflush(stdin);
        switch (n)        {
        case 1:
            escitalaEspartana();
            break;
        case 2:
            cifradoCesar();
            break;
        case 3:
            tratamientoMatematico();
        break;
        case 4:
            metodoAtbash();
        break;
        case 5:dobleCifrado();
            break;

        default:printf("Error\n");
            break;
        }
return 0;
}

void menu(){
    printf("---MENU---\n\n1. Escilata Espartana \n2. Cifrado Cesar \n3. Tratamiento matematico \n4. Método Atbash\n5. Doble cifrado");
    printf("\n\nOPCION: ");
}
//comienza Escilata Espartana
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
//Esta función realiza el cifrado con escitalaEspartana
void escitalaEspartana(){
    int i,j; //Contadores 
    int cont=0; //Contador para recorrer la escitalaEspartana
    int tamCad=0; //Tamaño de la cadea que lo vamos a obtener con strlen : http://www.forosdelweb.com/f96/obtener-tamano-array-dinamico-568584/
    char escitalaEspartana1 [30];  //Esta es la escitala
    char escitalaEspartana [3][9]; //Aqui vamos a meter los valores de la cadena uno por uno
    char decifradoEscitalaEspartana [3][9]; //Aqui vamos a meter los valores cifrados

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
    fflush(stdin);
    printf("Ingresa Cadena\n");
    gets(escitalaEspartana1);
    tamCad = strlen(escitalaEspartana1);
    if(espacioVaciosValidar(escitalaEspartana1,tamCad)==0||verificaCadenaSinNumero==0) {
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
        printf("\n");
        printf("La cadena tiene espacios o numeros");
    }
    printf("\n");
}
//Termina Escilata Espartana
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
//Comienza Cifrado Cesar
//La siguiente función realiza el cifrado y decifrado Cesar | Contiene un menu para saber si quieres cifrar o decifrar un mensaje
void cifradoCesar (){
    system("cls");
    int n,j,i; //contadoes
    //La siguiente matriz contiene la metriz del cifrado
    char arrCesar[2][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
                          {'X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'}};
    
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
//La siguiente función Decifra un mensaje
void cesarDecifrar(char arrCesar[2][26]){

    int tam=0; //contiene el tamaño de la cadena
    int k;     //Es un contedor para recorrer la cadena
    fflush(stdin);//limpia el buffer si no marca error
    char arr[tam]; //contiene la cadena
    printf("Introduce texto a cifrar:\n");
    gets(arr);
    fflush(stdin);

    tam = strlen(arr);
   if(espacioVaciosValidar(arr,tam)==0  || verificaCadenaSinNumero==0){
    printf("\n\n--Texto Introducido--");
    printf("\n> %s",arr);
    printf("\n\n--Texto Cifrado--");
    printf("\n> ");

    for(k=0;k<tam;k++){//CONSTRU CIFRADO 
        printf("%c",buscarCesarDeCifrar(toupper(arr[k]),arrCesar));
    }
    printf("\n");
    }else{
                printf("Tienes espacios o números\n");
    }

}

//La siguiente función cifra un mensaje con el metodo cesar
void cesarCifrar(char arrCesar[2][26]){

    int tam=0; //contiene el tamaño del arreglo
    int k;    //Recorre el arreglo
    
    fflush(stdin);//limpia el buffer si no marca error
    char arr[tam];
    printf("Introduce texto a decifrar:\n");
    gets(arr);
    fflush(stdin);

    tam = strlen(arr);
    if(espacioVaciosValidar(arr,tam)==0){
    printf("\n\n--Texto Introducido--");
    printf("\n> %s",arr);
    printf("\n\n--Texto Cifrado--");
    printf("\n> ");

    for(k=0;k<tam;k++){//CONSTRU CIFRADO 
        printf("%c",buscarCesarCifrar(toupper(arr[k]),arrCesar));
    }
    printf("\n");
    }else{
                printf("Tienes espacios\n");
    }
}
//Dea cuerdo a una letra la busca en la matriz de cesar, en cuanto encuetra la letra regresa la posición (letra) pero la que esta arriba de la matriz, una posición arriba
char buscarCesarDeCifrar(char buscado,char arrCesar[2][26]){
int i; //Para recorrer las filas de la matriz
char a='*'; //Regresa la letra de la metriz
    for(i=0;i<26;i++){
      if( buscado==arrCesar[1][i]){
          a=arrCesar[0][i];
      } 
    }
return a;
}
//Dea cuerdo a una letra la busca en la matriz de cesar, en cuanto encuetra la letra regresa la posición (letra) pero la que esta abajo de la matriz, una posición abajo
char buscarCesarCifrar(char buscado,char arrCesar[2][26]){
int i; //Para recorrer las filas
char a='*'; //Regresa la letra de la metriz
    for(i=0;i<26;i++){
      if( buscado==arrCesar[0][i]){
          a= arrCesar[1][i];
      } 
    }
return a;
}
//Termina Cifrado cesar
//comienza Tratamiento matemático
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
//Esta funcuín lee una cadena y la cifra deacurdo al tratamiento matematicp
void tratamientoMatematico(){
    char cadena[100]; //Aqui guardamos la cadena a cifrar
    int i=0, longitudCadena; //i : contador, longitudCadena: guardamos la logitud de la cadena
    char letraBuscar;       //La utilizaremos para saber que letra vamos sar su valor deacurdo a la tabla 
    int valorLetra;         //Guardamos el valor de la letra
    int nuevoValor;         //Realizamos la operación y tendra un nuevo valor para buscarlo en la tabla
    int valoresDeCadenaCodificados[100]; //Aqui vamos a guardar los valores codificados
    int logitudDEArreglo_valoresDeCadenaCodificados; //Vamos a calcular la logitud del arreglo que tiene los valores de las letras ya calculados
    printf("\n Estas en tratamiento matematico\n");
    printf("Ingresa Cadena ");
    gets(cadena);
    fflush(stdin);
    longitudCadena = strlen(cadena);
    if(espacioVaciosValidar(cadena,longitudCadena)==0 || verificaCadenaSinNumero==0 ) {
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
        char cadenaCodificada[longitudCadena]; //La utilizaremos para decodificar la cadena
        char *cadenaCodi;                      //La cadena en mayusculas, lo ponemos con char* porque sí lo reciviremos en la cunnción de realiza esto 
        cadenaCodi = imprimeCodificacionOperaMetetico(valoresDeCadenaCodificados,longitudCadena,cadenaCodificada);
        printf("Apartir de aqui camos adecodificar la cadena\n");
        for(i=0; i<longitudCadena;i++){
            printf("%c",cadenaCodi[i]);
        }

        printf("\n");
        //Imprimimos el valor de los elementos
        //Vamos a decodificar
        for(i=0; i<longitudCadena;i++){
            letraBuscar = cadenaCodi[i];
            valorLetra  = regresaValorLetra(letraBuscar);
            nuevoValor  = realizaOperacioIndicadaDepeje(valorLetra);
            valoresDeCadenaCodificados[i]= nuevoValor;
            printf("%d ",nuevoValor); //Si no quieres que imprima los valores, solo quita este printf
        }
        printf("\n");
        imprimeCodificacionOperaMetetico(valoresDeCadenaCodificados,longitudCadena,cadenaCodificada);
    }else {
        printf("Tienes espacios\n");
    }
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
    int nuevoValor; //Guardara el nuevo valor de la letra con operación
    nuevoValor = (valorLetra + 3) % 26; 
    return nuevoValor;
}
//Calcula el valor inicial antes de que se realizara el tratamiento matematico
int realizaOperacioIndicadaDepeje(int valorLetra){
    int nuevoValor; //Es la operación pero despejada para calcular el valor inicial
    nuevoValor = (valorLetra /  (1 % 26 )) -3;
    if(nuevoValor == -3)
        nuevoValor = 23;
    if(nuevoValor == -2)
        nuevoValor = 24;
    if(nuevoValor == -1)
        nuevoValor = 25;
    return nuevoValor;
}
//Decodifica el valor de cada letra
char* imprimeCodificacionOperaMetetico(int arreglo[],int longitud, char cadenaCodificada[]){
    int i = 0; //recorre el arrelgo
    int j = 0; //recorre el arrelgo
    char alfabeto[] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    printf("La cadena codificada es: ");
    for(i=0; i< longitud; i++){
        for (j = 0; j<26;j++){
            if(arreglo[i] == j){
                printf("%c",alfabeto[j]);
                cadenaCodificada[i] = alfabeto[j];
            }
        } 
    }
    printf("\n");
    return cadenaCodificada;
}
//Termina Tratamiento matemático
//-----------------------------------------------------------------------------------------------------------------------------------------------
//Comienza Tratamiento Atbash
void metodoAtbash(){
    char cadena[100];
    int i=0, longitudCadena;
    char letraBuscar;
    int valorLetra;
    int nuevoValor;
    int valoresDePosicion[100];
    int logitudDEArreglo_valoresDeCadenaCodificados;
    printf("\n Estas en tratamiento matematico\n");
    printf("Ingresa Cadena ");
    gets(cadena);
    fflush(stdin);
    longitudCadena = strlen(cadena);
    if(espacioVaciosValidar(cadena,longitudCadena)==0  || verificaCadenaSinNumero==0) {
        printf("La longitud es: %d",longitudCadena);
        printf("\nVoy a imprimir nuevamente \n");
        char *cadenaMayusculas; //Declaramos *cadenaMayusculas como para que pueda resivir la cadena convertida a mayusculas
        cadenaMayusculas = convierteCadenaMayusculas(cadena,longitudCadena);
        for(i=0;i<longitudCadena;i++){
            printf("%c",cadenaMayusculas[i]);
        }
        printf("\n");
        printf("Impresión de los valores de la tabla \n");
        for(i=0; i<longitudCadena;i++){
            letraBuscar = cadenaMayusculas[i];
            valorLetra  = regresaValorLetra(letraBuscar);
            valoresDePosicion[i]= valorLetra;
            printf("%d ",valorLetra); 
        }
        printf("\n");
        char cadenaCodificada[longitudCadena];
        char *cadenaCodi;
        printf("La cadena codificada es: \n");
        cadenaCodi = codificaBash(valoresDePosicion,longitudCadena,cadenaCodificada);
        printf("Apartir de aquí vamos a decodificar la cadena\n");
        for(i=0; i<longitudCadena;i++){
            printf("%c",cadenaCodi[i]);
        }
        printf("\n");
        for(i=0; i<longitudCadena;i++){
            letraBuscar = cadenaCodi[i];
            valorLetra  = regresaValorLetra(letraBuscar);
            valoresDePosicion[i]= valorLetra;
            printf("%d ",valorLetra); //Si no quieres que imprima los valores, solo quita este printf
        }
        printf("\n");
        printf("La cadena decodificada es: \n");
        codificaBash(valoresDePosicion,longitudCadena,cadenaCodificada);
        printf("\n");
    }else {
        printf("Tienes espacios\n");
    }
}
//Regresa la codena codificada deacuerdo al metodo bash
char* codificaBash(int arreglo[], int longitud,char cadenaCodificada[]){
    int i = 0; //Recorre el vector
    int j = 0; //Recorre el vector
    char alfabeto[] ={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
    
    for(i=0; i< longitud; i++){
        for (j = 0; j<26;j++){
            if(arreglo[i] == j){
                printf("%c",alfabeto[j]);
                cadenaCodificada[i] = alfabeto[j];
            }
        } 
    }
    printf("\n");
    return cadenaCodificada;
}
//Termina Tratamiento Atbash
//-----------------------------------------------------------------------------------------------------------------------------------------------
//Realiza el doble cifrado de una cadena
void dobleCifrado(){
    int tam=0,i; //i : recorre el vetor, tam: obitiene el tamaño del vector introducido
    int p;      //Para recorrer la matriz 
    int q;      //Para recorrer la matriz 
    char arrDobleCifrado[3][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
                                {'F','R','J','O','Y','D','I','Q','T','Z','S','L','M','E','U','N','B','K','W','A','H','P','C','X','G','V'},
                                {'H','T','R','V','Z','D','I','Q','J','Y','P','E','L','M','U','B','N','K','A','W','F','S','X','C','G','O'}};
    printf("--DOBLE CIFRADO--\n\n");

    printf("\n--TABLA DOBLE CIFRADO--\n");

    for (p = 0; p < 3; p++)
    {
        for (q = 0; q < 26; q++)
        {
          printf("%c",arrDobleCifrado[p][q]);

        }
         printf("\n");
    }
         printf("\n");
    

    char cifrado[tam];
    char cifradoTem[tam];

    printf("Introduce texto:\n");
    gets(cifrado);
    tam = strlen(cifrado);
    if(espacioVaciosValidar(cifrado,tam)==0  || verificaCadenaSinNumero==0){

 
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
    printf("\nApartir de aqui vamos a decifrar el mensaje\n >");
    for(i=0; i < tam; i++){
        printf("%c",cifrado[i]); 
    }
    printf("\n");
    for (i = 0; i < tam; i++){
       cifrado[i]= regresaDecifradoDos(toupper(cifrado[i]),arrDobleCifrado);
    }
    printf("\nDecifrado dos al uno\n >");
    for(i=0; i < tam; i++){
        printf("%c",cifrado[i]); 
    }
    printf("\nDecifrado del uno a texto normal\n >");
    for(i=0; i < tam; i++){
        cifrado[i]= regresaDecifradoUno(toupper(cifrado[i]),arrDobleCifrado);
    }
    for(i=0; i < tam; i++){
        printf("%c",cifrado[i]); 
    }
   }else{
            printf("Tienes espacios\n");
   }
}
//Obiene el valor de la letra, deacuerdo a su valor de abajo
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
//Obiene el valor de la letra, deacuerdo a su valor de abajo
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
//Obiene el valor de la letra, deacuerdo a su valor de arriba
char regresaDecifradoDos(char buscado,char arr[3][26]){
    int i;
	char a='*';
	    for(i=0;i<26;i++){
	      if( buscado==arr[2][i]){
	          a=arr[1][i];
	      } 
	    }
	return a;
}
//Obiene el valor de la letra, deacuerdo a su valor de arriba
char regresaDecifradoUno(char buscado,char arr[3][26]){
    int i;
	char a='*';
	    for(i=0;i<26;i++){
	      if( buscado==arr[1][i]){
	          a=arr[0][i];
	      } 
	    }
	return a;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//funcion que valida que la cadena no tenga espacios
int espacioVaciosValidar(char a[],int tam ){
    int i,j=0;
    for(i=0;i<tam;i++){
            if(a[i]==' '){
                j= 1;
            }
    }
    return j;
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
//Verifica que la cadena no tenga numeros
int verificaCadenaSinNumero(char cadena[],int longitudCadena){
	int i,j=0;
    for(i=0;i<longitudCadena;i++){
            if(cadena[i]==0||cadena[i]==1||cadena[i]==2||cadena[i]==3||cadena[i]==4||cadena[i]==5||cadena[i]==6||cadena[i]==7||cadena[i]==8||cadena[i]==9||cadena[i]==10){
                j= 1;
            }
    }
    return j;
}
