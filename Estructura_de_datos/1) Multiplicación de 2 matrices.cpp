#include <iostream>

using namespace std;

int main() {
  int a[3][3][3];
  int b;
  int (*p)[3][3] = a;
  int (*q)[3] = *p;
  int *r = *q;
  int (*k)[3] = *(a+2);
  for (; p < a+2; p++)
  {
    for(; q < *(p+1); q++)
    {
      for(; r < *(q+1); r++)
        {
          cout <<"Escribir terminos: ";
          cin >> b;
          *r = b;
        }
    }
  }
  for(int *x = **(a+2); x < *(*(a+2)+3); x++){
    *x = 0;
  }

  for (int (*s)[3] = *(a+1), *v = *s; s < *(a+2); s++, k++){
    for(int (*m)[3] = *(a), *t = *m; m < *(a+1);m++,v++){
      for(int *z = *k; z < *(k+1); z++,t++){
        *z = *z + (*v)*(*t);
      }
    }
  }

  cout << "Matriz Multiplicativa:" <<endl;
  for(int (*x)[3] = *(a+2); x < *(a+3); x++){
    for(int *y = *x; y < *(x+1); y++){
      cout << *y << " ";
    }
    cout<<endl;
  }

  
  
  return 0;
}