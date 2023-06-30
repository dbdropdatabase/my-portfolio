#include <stdio.h>
#include <math.h>

int N = 20;

double sub(int N){
  double X = 10.0;
  double c = 2 * N - 1;

 //(-1)N+1乗
  double a = pow((-1.0), (N + 1));
  printf("a=%f\n", a);

//xの2n-1乗
  double b = pow(X,(2 * N - 1));
  printf("b=%f\n", b);
  printf("N=%d\n", N);

//(2n-1)!
  double w =  c - 1;
  double fact = c;
  for (;;){
    if (w<=0){
      break;
    }
    fact = fact * w;
    w=w-1;
  }
  printf("c=%f\n", fact);

  double d = a * b / fact; 
  printf("d=%f\n", d);
  return d;
}

int main(){
    double lastans = 0.0;
    double X = 10.0;
    for (double j=1.0; j<21.0; j++) {
        lastans += sub(j);
        printf("lastanswer=%f\n",lastans);
        printf("sin-lastans=%f\n",sin(X)-lastans);
    }
    return 0;
  }
