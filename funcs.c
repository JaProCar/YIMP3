#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laba.h"

void display(){
  sp e; //editable
  FILE* f = fopen("sport", "r");
  if(!f)
    return;
  puts("Name Tickets_sold Peoples_came");
  while(!feof(f)){
    fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
    printf("%s %i %i\n", e.name, e.amount, e.used);
    }
  fclose(f);
}
void search(){
  sp e; //editable
  int chose;
  FILE* f = fopen("sport", "r");
  if(!f)
    return;
  puts("Choose what to search\n1. Name 2. Solds 3. Peoples");
  scanf("%i", &chose);
  switch(chose){
    case 1:
      puts("type full name of sport match");
      char fname[20];
      scanf("%s", fname);
      while(!feof(f)){
        fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
        if(strcmp(fname, e.name) == 0){
          printf("%s %i %i\n", e.name, e.amount, e.used);
        }
      }
      break;
    case 2:
      puts("type solds");
      int solds;
      scanf("%i", &solds);
      while(!feof(f)){
        fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
        if(solds == e.amount){
          printf("%s %i %i\n", e.name, e.amount, e.used);
        }
      }
      break;
    case 3:
      puts("how many peoples come");
      int peple;
      scanf("%i", &peple);
      while(!feof(f)){
        fscanf(f, "%s %i %i\n", e.name, &e.amount, &e.used);
        if(peple == e.used){
          printf("%s %i %i\n", e.name, e.amount, e.used);
        }
      }
      break;
    default:
      return;        
  }
  fclose(f);
}
void add(){
  FILE* f = fopen("sport","a");
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
void del(){
  sp e; //editable
  FILE* f = fopen("sport", "r");
  if(!f)
    return;
  int solds, usedd;
  char names[20];
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
    scanf("%s", names);
    puts("type solds");
    scanf("%i", &solds);
    puts("type how mutch people come");
    scanf("%i", &usedd);
    f = fopen("sport", "w");
    if(!f)
      return;
    for(int i = 0; i < n; i++){
      if(((strcmp(names, arr[i].name)) == 0) && (solds == arr[i].amount) && (usedd == arr[i].used)){
      }else{
        fprintf(f, "%s %i %i\n", arr[i].name, arr[i].amount, arr[i].used);
      }
    }
    fclose(f);
    free(arr);
}
void edit(){
  sp e;
  int solds, usedd;
  char names[20];
  int n = 0;
  FILE* f = fopen("sport", "r");
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
  scanf("%s", names);
  puts("type solds");
  scanf("%i", &solds);
  puts("type peoples come");
  scanf("%i", &usedd);
  f = fopen("sport", "w");
  if(!f)
    return;
  for(int i = 0; i < n; i++){
    if(((strcmp(names, aaar[i].name)) == 0) && (solds == aaar[i].amount) && (usedd == aaar[i].used)){
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
