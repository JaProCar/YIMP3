typedef struct sport{
  char name[20];
  int amount;
  int used;
}sp;
void display(FILE*  f);
void search(FILE* f);
void add(FILE* f);
void del(FILE* f);
void edit(FILE* f);

