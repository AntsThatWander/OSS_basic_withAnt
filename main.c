#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "fun.h"
extern node* head;


int main(){
  head = NULL;
  FILE* fp;
  char name[20];
  char number[15];
  char birthday[8];
  node* tmp = (node*)malloc(sizeof(node));
  node* ttmp = (node*)malloc(sizeof(node));
  char tmp_name[20];
  char tmp_number[15];
  char tmp_birthday[8];
  int cnt = 0;
  int i, j;
  

  fp = fopen("people.txt","r");
  funcall(fp);
  fclose(fp);

  while(1){
    printf("*****Menu*****\n");
    printf("1. Registration, 2. ShowAll, 3. Delete, 4. FindByBirth, 5. Exit\n");
    printf("Enter the menu number:");
    int n; scanf("%d",&n);
    
  
    switch(n){
      case 1 : 
        Registration();
        continue;
      case 2 :
        ShowAll();
        continue;
      case 3 :
        Delete();
        continue;
      case 4 :
        FindByBirth();
        continue;
      case 5 :
        fp = fopen("people.txt","w");
        funcarr(fp);
        fclose(fp);
        exit(0);
      }
    }
  
    return 0;
}
