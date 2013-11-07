#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#define NKEYS (sizeof x/sizeof x[0])
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

struct node{
  int data;
  struct node *next;
  node* getNext(){return next;}
  int getData(){return data;}
};
struct node *get_node(int n){
  node *z =(node *) malloc(sizeof *z);
  if(z != NULL){
    z->data = n;
    z->next = NULL;
    return z;
  }
  return NULL;
}

void print(node *x){
  node* next=x;
  next=next->getNext();
  while(next!=NULL){
    cout<<next->getData()<<"->";
    next=next->getNext();
  }
  cout<<"null";

}

void radixsort(int *x,int n){
  int j = 0;
  int digit = 0;
  node *z;
  node *p;
  node **old ;
  node *hashtable[10];
  node *hashend[10];

  for( digit = 1; digit <=5; digit++)
    {
      cout << "Sorted list based on digit(Right to Left): " << digit << endl;

      /*Initialise the hash tables*/
      for(int i = 0; i < 10; i++)
    {
      hashtable[i] = (z = get_node(i));
      hashend[i] = (z = get_node(i));
    }

      /*Parse through the array*/
      for(int i = 0; i < n; i++)
    {
      j = (x[i]/(int)pow(10,digit-1)) % 10;/*Get Individual digts*/
      z = get_node(x[i]); /*Create a node with parsed value*/


      /*No hashing as yet*/
      if( hashtable[j]->next == NULL ) {
        hashtable[j]->next = z;
        hashend[j]->next = z;
      }
      /*Hashed value present*/
      else {
        hashend[j]->next->next = z;
        hashend[j]->next = z;
      }
    }

      j=0;/*j was used earlier so fix it up again*/
      for(int i = 0; i < 10 ; i++)
    {
      /*For each index in hashtable,parse thorugh the nodes */
      for(p = hashtable[i]->next; p != NULL ; p = p->next)
        {
          if(p == NULL)
        break;
          x[j++] = p->data;/*Use the passed array to store new values*/
        } /*after each pass*/
    }
      for(int i=0;i<10;i++){
    cout<<"table["<<i<<"] : ";
    print(hashtable[i]);
    cout<<endl;   
      }
      if(digit==5){
    cout<<"After Radix Sort, the List is: "<<endl;
    print(hashtable[0]);
    cout<<endl;
      }

      /*Free up the nodes before the next pass*/
      for(int i = 0; i < 10 ; i++)
    {
      old = &hashtable[i]->next;
      if(old != NULL && *old != NULL) {
        free(*old);
        *old = NULL;
      }
    }

    }
  return ;
}

int main(){
  int i, size = 0;
  ifstream myfile;
  myfile.open("Project4.txt");
  // find the numbers of integers in the file
  while(myfile >> i) {
    size++;
  }
  myfile.close();
  int x[size];         
  int j=0;    
  // read the file again and put the inegers to the array
  myfile.open("list.txt");
  while(myfile >> i) {
    x[j]=i;
    j++;
  }
  radixsort(x,size);
  myfile.close();
}
