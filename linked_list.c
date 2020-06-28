#include "linked_list.h"
node* head;
int cnt;

void ShowAll(){
  if(head != NULL){
    traversal(2);
  }
}

void FindByBirth(){
  char birth[3] = " ";
  printf("Birth:");
  scanf("%s",birth);
  if(head!=NULL){
    if(!birth[1]){
      char tmp = birth[0];
      birth[0] = '0';
      birth[1] = tmp;
    }
    traversal_4(birth);
  }
}

node* initialize(char* name, char* number, char* birthday){
  node* body = (node*)malloc(sizeof(node));
  
  body -> name = (char*)malloc(strlen(name)+1);
  body -> number = (char*)malloc(strlen(number)+1);
  body -> birthday = (char*)malloc(strlen(birthday)+1);
  strcpy(body->name,name);
  strcpy(body->number,number);
  strcpy(body->birthday,birthday);
  body -> next = NULL;
  return body;
}

void traversal(int num){
  int no_name = 0;
  node* tmp = head;
  if(num==1) cnt++;
  if(num==2) printf("%s %s %s\n",tmp->name,tmp->number,tmp->birthday);
  while(tmp -> next != NULL){
    tmp = tmp -> next;
    if(num==2) printf("%s %s %s\n",tmp->name,tmp->number,tmp->birthday);
    if(num==1) cnt++;
  }
}

void Registration(){
  char name[21] = " ";
  char number[16] = " ";
  char birthday[9] = " ";
  char tmp_name[21] = " ";
  char tmp_number[16] = " ";
  char tmp_birthday[9] = " ";
  int is_dupl = 0;
 
  printf("Name:");
  scanf("%s",name);
  printf("Phone number:");
  scanf("%s",number);
  printf("Birth:");
  scanf("%s",birthday);
  if(head == NULL){
    head = initialize(name, number, birthday); //first commit!
  }
  else{
    node *tmp = (node*)malloc(sizeof(node));
    tmp = head;
    if(strcmp(tmp->name, name) == 0) is_dupl = 1; //same name check
    else if(strcmp(tmp->name,name) >= 1){ //strcmp add-on
      strcpy(tmp_name, name);
      strcpy(tmp_number, number);
      strcpy(tmp_birthday, birthday);
      strcpy(name, tmp->name);
      strcpy(number, tmp->number);
      strcpy(birthday, tmp->birthday);
      strcpy(tmp->name, tmp_name);
      strcpy(tmp->number, tmp_number);
      strcpy(tmp->birthday, tmp_birthday);
    }//end add-on
    while(tmp->next != NULL){ //next node, excepting first connection
      tmp = tmp -> next;
      if(strcmp(tmp->name, name) == 0){
        is_dupl = 1;
        break;
      }
      else if(strcmp(tmp->name,name) >= 1){ //strcmp add-on
        strcpy(tmp_name, name);
        strcpy(tmp_number, number);
        strcpy(tmp_birthday, birthday);
        strcpy(name, tmp->name);
        strcpy(number, tmp->number);
        strcpy(birthday, tmp->birthday);
        strcpy(tmp->name, tmp_name);
        strcpy(tmp->number, tmp_number);
        strcpy(tmp->birthday, tmp_birthday);
      }//end add-on
    }
    if(!is_dupl && (node*)malloc(sizeof(node)) != NULL) tmp -> next = initialize(name, number, birthday); //not duplicated and not overflow
    else if((node*)malloc(sizeof(node))==NULL) printf("Overflow.\n");
  }
  traversal(1); //traversal for count
  printf("count: %d\n",cnt);
  cnt = 0;
}


void Delete(){
  if(head != NULL){
    char del_name[20] = " ";
    printf("Name:");
    scanf("%s",del_name);
    if(!strcmp(head->name,del_name)){
      if(head->next == NULL) head = NULL;
      else{
        head = head -> next;
        //free(head->next);
      }
    }
    else{
      int no_name = 1;
      if(head->next != NULL){
        if(head->next->next == NULL && !strcmp(head->next->name,del_name)){
          head -> next = NULL;
          no_name = 0;
        }
        else if(head->next->next != NULL){
          node* tmp = head;
          while(tmp->next->next != NULL){
            if(!strcmp(tmp->next->name, del_name)){
              tmp->next = tmp->next->next;
              //free(tmp->next->next);
              no_name = 0;
              break;
            }
            tmp = tmp -> next;
          }
          if(!strcmp(tmp->next->name, del_name)){
            //free(tmp->next);
            tmp -> next = NULL;
            no_name = 0;
          }
        }
      }
      
      
      if(no_name) printf("No record founded.\n");
    }
  }
  else{
    printf("No record founded.\n");
  }
}

void traversal_4(char* birth){
  node* tmp = head;
  if(birth[0] == tmp->birthday[4] && birth[1] == tmp->birthday[5]){
    printf("%s %s %s\n",tmp->name,tmp->number,tmp->birthday);
  }
  
  
  while(tmp -> next != NULL){
    tmp = tmp -> next;
    if(birth[0] == tmp->birthday[4] && birth[1] == tmp->birthday[5]){
      printf("%s %s %s\n",tmp->name,tmp->number,tmp->birthday);
    }
  }
}
