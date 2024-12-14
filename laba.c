#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laba.h"
int main(){
  FILE* f;
  puts("Hello\nProgram Sport ready to use");
  for(;;){
    puts("Choose what to do:\n1.Display 2.Search 3.Add 4.Delete 5.Edit 6.Exit");
    int a;
    scanf("%i", &a);
    switch (a){
    case 1://display     
      display(f);
      break;
    case 2://search  
      search(f);
      break;
    case 3://add
      add(f);
      break;
      
    case 4://delete
      del(f); 
      break;
      
    case 5://edit
      edit(f);
      break;
      
    default:
      return 404;
    }
  }
}
