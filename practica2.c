#include <stdio.h>     //input, output, printf
#include <stdlib.h>    //generar nombres 
#include <math.h>

// PAS 0
#define N 512
float Mat[N][N], MatDD[N][N], V1[N], V2[N], V3[N], V4[N];

void InitData(){
  int i,j;
  srand(8824553);
  for( i = 0; i < N; i++ )
   for( j = 0; j < N; j++ ){
   Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
   if ( (abs(i - j) <= 3) && (i != j))
   MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
   else if ( i == j )
   MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
   else MatDD[i][j] = 0.0;
   }
  for( i = 0; i < N; i++ ){
   V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
   V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
   V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
  }
}

// PAS 1
void PrintVect(float vect[N], int from, int numel){
  int i;
  for (i=from; i<from+numel; i++){
    printf("%f ", vect[i]);
  }
}  


// PAS 2
void PrintRow(float mat[N][N], int row, int from, int numel){
  int i, j;
  for (i=0; i<N; i++){
    if (i==row){
      for (j=from; j<from+numel; j++){
        printf("%f ", mat[row][j]);
      }
    }
  }
  printf("\n");
}


// PAS 3
void MultEscalar( float vect[N], float vectres[N], float alfa){
  int i;
  for (i=0; i<N; i++){
    vectres[i] = vect[i]*alfa;
  }
  printf("\n");
}


// PAS 4
float Scalar( float vect1[N], float vect2[N] ){
  int i;
  float suma=0;
  for (i=0; i<N; i++){
    suma += (vect1[i]*vect2[i]);
  }
  return suma;
  printf("\n");
}


// PAS 5
float Magnitude( float vect[N] ){
  int i;
  float suma=0;
  for (i=0; i<N; i++){
    suma += vect[i]*vect[i];
  }
  return sqrt(suma);
  printf("\n");
}


// PAS 6
int Ortogonal( float vect[N], float vect1[N] ){
  float angle;
  angle = Scalar(vect, vect1);
  if (angle==0){return 1;}
  else {return 0;}
}


// PAS 7
void Projection( float vect1[N], float vect2[N], float vectres[N]){
  float num, den;
  den = Magnitude(vect2);
  if (den == 0) {printf("La operacio no es pot realitzar: divisio entre 0.\n");}
  else {
    num = (Scalar(vect1, vect2)) / den;
    MultEscalar(vect2, vectres, num);
    }
}


// PAS 8
float Infininorm(float M[N][N]){
 int i, j;
 float suma_max=0, suma=0;
 
 for (j=0; j<N; j++){
   suma_max += fabs(M[0][j]);
 }
 
 for (i=1; i<N; i++){
   for (j=0; j<N; j++){
     suma += fabs(M[i][j]);
   }
   if (suma > suma_max){suma_max=suma;}
 }
 return suma_max;
} 
 


// PAS 9
float Onenorm( float M[N][N] ){
  int i, j;
  float suma_max=0, suma=0;
 
  for (i=0; i<N; i++){
    suma_max += fabs(M[i][0]);
 }
 
  for (j=1; j<N; j++){
    for (i=0; i<N; i++){
      suma += fabs(M[i][j]);
   }
    if (suma > suma_max){suma_max=suma;}
 }
 return suma_max;
}


// PAS 10
float NormFrobenius( float M[N][N] ){
  int i,j;
  float quadrat=0, arrel=0;
  for (j=0; j<N; j++){
    for (i=0; i<N; i++){
      quadrat += (pow((M[i][j]), 2));
      arrel = sqrt(quadrat);
    }
  }
  return arrel;
}


// PAS 11
int DiagonalDom( float M[N][N] ){
  int i, j;
  int suma=0;
  for (i=0; i<N; i++){      
    for (j=0; j<N; j++){            
      suma += fabs(M[i][j]);      
      suma -= fabs(M[i][i]);
      if (fabs(M[i][i]) < suma)
        return 0;
     }
  }
    return 1;
}


// PROGRAMA
int main(){
  // PROVES A L'HORA DE CREAR LES FUNCIONS
  //float V5[N], V6[N], pas4, pas5, infininorma, normau;
  //int ortogonal1, ortogonal2, res, res1;
  //InitData();
  //printf("Pas 1:\n");
  //PrintVect( V1, 2, 4 );    //el 2 i el 4 poden ser qualsevol número
   
  //printf("\nPas 2:\n");
  //PrintRow(Mat, 3, 2, 4);   //el 3, 2 i el 4 poden ser qualsevol número
  
  //printf("\nPas3:\n");
  //MultEscalar(V1, V5, 6);   //l'V5 i el 6 poden ser qualsevol vector i número
  
  //printf("\nPas 4:\n");
  //pas4 = Scalar( V1, V4 );  //V1 i V2 poden ser qualssevol vectors
  //printf("%f", pas4);
  
  //printf("\n\nPas 5:\n");
  //pas5 = Magnitude(V4);     //V4 pot ser qualsevol vector
  //printf("%f", pas5);
  
  //printf("\n\nPas 6:\n");   //Els vectors poden ser qualsevols
  //ortogonal1 = Ortogonal(V1); 
  //printf("%d --> V1 no es ortogonal\n", ortogonal1);
  //ortogonal2 = Ortogonal(V4);
  //printf("%d --> V4 es ortogonal\n", ortogonal2);
  
  //printf("\nPas 7:\n");
  //Projection(V1, V4, V5);   //Els vectors poden ser qualsevols
  
  //printf("\nPas 8:\n");
  //infininorma = Infininorm(Mat); //La matriu pot ser qualsevol
  //printf("Infini-norma: %f\n", infininorma);
 
  //printf("\nPas 9:\n");
  //normau = Onenorm(Mat);     //La matriu pot ser qualsevol
  //printf("Norma-u: %f\n", normau);

  //printf("\nPas 10:\n");
  //res = NormFrobenius(Mat);     //La matriu pot ser qualsevol
  //printf("%d\n", res);          
  
  //printf("\nPas 11:\n");
  //res1 = DiagonalDom(Mat);     //La matriu pot ser qualsevol
  //printf("%d\n", res1);
  
  
  // PROVES DE VALIDACIÓ
  // VARIABLES
  float pe1, pe2, pe3, mag1, mag2, mag3, ort1_2, ort1_3, ort2_3, V6[N], V7[N];
  float b1, b2, b3, b4, b5, b6, V5[N];
  int b7, b8;
  // A
  printf("\nInicialitzant els vectors i matrius...\n");
  InitData();
  
  printf("\nEls primers 10 elements de V1:\n");
  PrintVect(V1, 0, 10);
  printf("\nAltres 10 elements des de la posicio 256:\n");
  PrintVect(V1, 256, 10);
  
  printf("\n\nEls primers 10 elements de V2:\n");
  PrintVect(V2, 0, 10);
  printf("\nAltres 10 elements des de la posicio 256:\n");
  PrintVect(V2, 256, 10);
  
  printf("\n\nEls primers 10 elements de V3:\n");
  PrintVect(V3, 0, 10);
  printf("\nAltres 10 elements des de la posicio 256:\n");
  PrintVect(V3, 256, 10);
  
  printf("\n\nEls primers 10 elements de les files 0 i 100 de la matriu Mat:\n");
  PrintRow(Mat, 0, 0, 10);
  PrintRow(Mat, 100, 0, 10);
  
  printf("\nEls primers 10 elements de la fila 0 de la matriu MatDD:\n");
  PrintRow(MatDD, 0, 0, 10);
  printf("Elements 90-99 de la fila 100 de la matriu MatDD:\n");
  PrintRow(MatDD, 100, 90, 10);
  
  // B
  b1 = Infininorm(Mat);
  b2 = Infininorm(MatDD);
  printf("\nLa Infininorm de Mat es: %f\nLa Infininorm de MatDD es: %f\n", b1, b2);
  
  b3 = Onenorm(Mat);
  b4 = Onenorm(MatDD);
  printf("\nLa norma-u de Mat es: %f\nLa norma-u de MatDD es: %f\n", b3, b4);
  
  b5 = NormFrobenius(Mat);
  b6 = NormFrobenius(MatDD);
  printf("\nLa norma de Frobenius de Mat es: %f\nLa norma de Frobenius de MatDD es: %f\n", b5, b6);
  
  b7 = DiagonalDom(Mat);
  if (b7==0){printf("\nLa matriu Mat NO es diagonal dominant");}
  else {printf("\nLa matriu Mat es diagonal dominant");}
  b8 = DiagonalDom(MatDD);
  if (b8==0){printf("\nLa matriu MatDD NO es diagonal dominant");}
  else {printf("\nLa matriu MatDD es diagonal dominant");}
  
  // C
  pe1 = Scalar( V1, V2);
  printf("\n\nEl producte escalar dels vectors V1 i V2 es %f\n", pe1);
  
  pe2 = Scalar( V1, V3);
  printf("El producte escalar dels vectors V1 i V3 es %f\n", pe2);
  
  pe3 = Scalar( V2, V3);
  printf("El producte escalar dels vectors V2 i V3 es %f\n", pe3);
  
  // D
  mag1 = Magnitude(V1);
  printf("\nLa magnitud de V1 es %f\n", mag1);
  
  mag2 = Magnitude(V2);
  printf("La magnitud de V2 es %f\n", mag2);
  
  mag3 = Magnitude(V3);
  printf("La magnitud de V3 es %f\n", mag3);
  
  // E
  ort1_2 = Ortogonal(V1, V2);
  if (ort1_2==1){printf("\nEls vectors V1 i V2 son ortogonals\n");}
  else {printf("\nEls vectors V1 i V2 NO son ortogonals\n");}

  ort1_3 = Ortogonal(V1, V3);
  if (ort1_3==1){printf("Els vectors V1 i V3 són ortogonals\n");}
  else {printf("Els vectors V1 i V3 NO son ortogonals\n");}
  
  ort2_3 = Ortogonal(V2, V3);
  if (ort2_3==1){printf("Els vectors V2 i V3 són ortogonals\n");}
  else {printf("Els vectors V2 i V3 NO son ortogonals\n");}
  
  // F
  MultEscalar(V3, V5, 2.0);
  printf("Els primers 10 elements de la multiplicacio escalar del vector V3 amb 2.0:\n");
  PrintVect(V5, 0, 10);
  printf("\nAltres 10 elements des de la posicio 256:\n");
  PrintVect(V5, 256, 10);
  
  // G
  Projection(V2, V3, V6);
  printf("\n10 primers elements de la projeccio del vector V2 sobre el vector V3:\n");
  PrintVect(V6, 0, 10);
  
  Projection(V1, V2, V7);
  printf("10 primers elements de la projeccio del vector V1 sobre l vector V2:\n");
  PrintVect(V7, 0, 10);
  printf("\n\n");
}