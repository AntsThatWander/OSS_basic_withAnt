#include "fun.h"
node* head;



void funcall(FILE* fp){
  char name[21];
  char number[16];
  char birthday[9];
  node* tmp = (node*)malloc(sizeof(node));
  char tmp_name[21];
  char tmp_number[16];
  char tmp_birthday[9];
  int cnt = 0;
  int i, j;

  while(fscanf(fp, "%s%s%s", name, number, birthday) != EOF){
    if(head == NULL){
      head = initialize(name, number, birthday);
      tmp = head;
    }
    else{
      tmp -> next = initialize(name, number, birthday);
      tmp = tmp -> next;
    }
    cnt++;
  }
  tmp = head;
  for(i=0; i<cnt; i++){
    for(j=0; j<cnt-i-1; j++){
      if(strcmp(tmp->name, tmp->next->name)>=1){
        strcpy(tmp_name,tmp->name);
        strcpy(tmp_number,tmp->number);
        strcpy(tmp_birthday,tmp->birthday);
        strcpy(tmp->name,tmp->next->name);
        strcpy(tmp->number,tmp->next->number);
        strcpy(tmp->birthday,tmp->next->birthday);
        strcpy(tmp->next->name,tmp_name);
        strcpy(tmp->next->number,tmp_number);
        strcpy(tmp->next->birthday,tmp_birthday);
      }
      if(j<cnt-i-2) tmp = tmp->next;
      else tmp = head;
    }
  }
}

void funcarr(FILE* fp){
  node* tmp = (node*)malloc(sizeof(node));
  node* ttmp = (node*)malloc(sizeof(node));
  tmp = head;
  while(tmp != NULL){
    fprintf(fp,"%s %s %s",tmp->name,tmp->number,tmp->birthday);
    if(tmp->next != NULL) fprintf(fp,"\n");
    ttmp = tmp->next;
    free(tmp);
    tmp = ttmp;
  }
}
