#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laba.h"

void display(FILE*  f){
  sp e; //editable
  f = fopen("sport", "r");
  if(!f)
    return;
  puts("Name Tickets_sold Peoples_came");
  while(!feof(f)){
    fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
    printf("%s %i %i\n", e.name, e.amount, e.used);
    }
  fclose(f);
}
void search(FILE* f){
  sp e; //editable
  int ch;
  f = fopen("sport", "r");
  if(!f)
    return;
  puts("Choose what to search\n1. Name 2. Solds 3. Peoples");
  scanf("%i", &ch);
  switch(ch){
    case 1:
      puts("type full name of sport match");
      char fuck[20];
      scanf("%s", fuck);
      while(!feof(f)){
        fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
        if(strcmp(fuck, e.name) == 0){
          printf("%s %i %i\n", e.name, e.amount, e.used);
        }
      }
      break;
    case 2:
      puts("type solds");
      int cha;
      scanf("%i", &cha);
      while(!feof(f)){
        fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
        if(cha == e.amount){
          printf("%s %i %i\n", e.name, e.amount, e.used);
        }
      }
      break;
    case 3:
      puts("how many peoples come");
      int chu;
      scanf("%i", &chu);
      while(!feof(f)){
        fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
        if(chu == e.used){
          printf("%s %i %i\n", e.name, e.amount, e.used);
        }
      }
      break;
    default:
      return;        
  }
  fclose(f);
}
void add(FILE *f){
  f = fopen("sport","a");
      if(!f) 
        return;
  sp e; //editable
  puts("name of the match");
  scanf("%s", e.name);
  puts("amount");
  scanf("%i", &e.amount);
  puts("how much used in games");
  scanf("%i", &e.used);
  fprintf(f, "%s %i %i\n", e.name, e.amount, e.used);
  fclose(f);
}
void del(FILE*f){
  sp e; //editable
  f = fopen("sport", "r");
  if(!f)
    return;
  int am, u;
  char na[20];
  int n = 0;
  while(!feof(f)){    //костыльно считаю строки
    fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
    n++;
    }
    rewind(f);
    struct sport *arr = calloc(n, sizeof(struct sport));
    for(int i = 0; i < n; i++){
      fscanf(f, "%s %i %i\n", arr[i].name, &arr[i].amount, &arr[i].used);
    }
    fclose(f);
    puts("type full name of sport match");
    scanf("%s", na);
    puts("type solds");
    scanf("%i", &am);
    puts("type how mutch people come");
    scanf("%i", &u);
    f = fopen("sport", "w");
    if(!f)
      return;
    for(int i = 0; i < n; i++){
      if(((strcmp(na, arr[i].name)) == 0) && (am == arr[i].amount) && (u == arr[i].used)){
      }else{
        fprintf(f, "%s %i %i\n", arr[i].name, arr[i].amount, arr[i].used);
      }
    }
    fclose(f);
    free(arr);
}
void edit(FILE* f){
  sp e;
  int am, u;
  char na[20];
  int n = 0;
  f = fopen("sport", "r");
  if(!f)
  return;
  while(!feof(f)){    //костыльно считаю строки
    fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
    n++;
  }
  rewind(f);
  struct sport *aaar = calloc(n, sizeof(struct sport));
  for(int i = 0; i < n; i++){
    fscanf(f, "%s %i %i\n", aaar[i].name, &aaar[i].amount, &aaar[i].used);
  }
  fclose(f);
  puts("type full name of sport match");
  scanf("%s", na);
  puts("type solds");
  scanf("%i", &am);
  puts("type peoples come");
  scanf("%i", &u);
  f = fopen("sport", "w");
  if(!f)
    return;
  for(int i = 0; i < n; i++){
    if(((strcmp(na, aaar[i].name)) == 0) && (am == aaar[i].amount) && (u == aaar[i].used)){
      puts("new name of match");
      scanf("%s", e.name);
      puts("new solds");
      scanf("%i", &e.amount);
      puts("new peoples come");
      scanf("%i", &e.used);
      fprintf(f, "%s %i %i\n", e.name, e.amount, e.used);
      }else{
      fprintf(f, "%s %i %i\n", aaar[i].name, aaar[i].amount, aaar[i].used);
    }
  }
  fclose(f);
  free(aaar);
}
