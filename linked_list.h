#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
  struct node* next;
  char *name;
  char *number;
  char *birthday;
}node;

node* head;
int cnt;
void Registration();
void Delete();
node* initialize(char* name, char* number, char* birthday);
void traversal(int num);
void traversal_4(char* birth);
void ShowAll();
void FindByBirth();
#endif
