/*
Dictionary using linkedlists
Project for data structures lab
*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct node{
char word[50];
char mean[200];
struct node *prev;
struct node *next;
};

void menu();

int main()
{
struct node *A[26];
char sent[250];
int epil,k;

for(int i=0;i<26;i++){//initialize the table
    A[i]=NULL;
}

do{
menu();
cin>>epil;//menu choice


switch(epil){

case 1:{
ifstream file;
file.open("text.txt");//open of file

if (file.is_open()) {//check if the file is open

    cout<<"File Checked."<<endl;}


while(file.getline(sent,249)!=NULL){
//till finds the end,reads every time 250 chars

char *tmp1;

tmp1=strtok(sent,":");//find the spot about ":"
struct node *newno=new struct node; //create object struct node
strcpy(newno->word,tmp1); //copy the string from the first char till right before ":"
tmp1= strtok (NULL, ":");//from ":" till the end of line
strcpy(newno->mean,tmp1);//copy of tmp1 to mean

newno->next=NULL;//initialize next and previous nodes
newno->prev=NULL;

cout<<newno->word<<endl;
cout<<newno->mean<<endl;


if(A [sent[0]-65]==NULL){//in case there isn't nodes on the table

A[newno->word[0]-65]=newno;
newno->next=NULL;
newno->prev=NULL;}

else{
//in other case
   struct node *tail;//end of the list
   struct node *tmp2;
   tmp2=A[newno->word[0]-65];//belongs to the letter,show the first object of the list
             while(tmp2!=NULL)
            {

                if(tmp2->prev!=NULL && strcmp(newno->word,tmp2->word)<0)// the case where we create a node before an other
                {
                    newno->next=tmp2;
                    tmp2=tmp2->prev;
                    tmp2->next=newno;
                    newno->prev=tmp2;
                    tmp2=newno->next;
                    tmp2->prev=newno;


                }

               else if(tmp2->prev==NULL && strcmp(newno->word,tmp2->word)<0)//the case where we create a node before the 1st node of the table
                {
                    newno->next=tmp2;
                    A[newno->word[0]-65]=newno;
                    tmp2->prev=newno;}

                tail=tmp2;
                tmp2=tmp2->next;

}
tail->next=newno;
newno->prev=tail;
}

}
break;}

case 2:{

struct node *tmp1;

char w[50];
int x=0,k=0,epil1;

cout<<"Give a word to search: "<<endl;
cin>>w;

tmp1=A[w[0]-65];


     while(tmp1!=NULL)
     {

        if(strcmp(w,tmp1->word)==0){//search for the existance of the words in list.
        cout<<"We found the : '"<<w<<"'' word"<<endl;
        k=1;
        break;}

    tmp1=tmp1->next;
    }
    if(k==1)
        break;



if(k==0){ //in case we can't find the word
    cout<<"word not found."<<endl;
    cout<<"would you like to import the word in the dictionary? (Press 1 for Yes,Press 0 for No)?"<<endl;
    cin>>epil1;

  if(epil1==1){

      char meaning1[200];

      cout<<"Give me the Meaning:"<<endl;
      cin>>meaning1;


    struct  node *newno1=new struct node;
     newno1->mean[200]=meaning1[200];
     newno1->word[50]=w[50];


          if(A[w[0]-65]==NULL){//in case the table haven't any node

             A[w[0]-65]=newno1;
             newno1->next=NULL;
             newno1->prev=NULL;}

          else{//in other case
             struct node *tmp2=A[w[0]-65];
             struct node *tail2;

             while(tmp2!=NULL)
            {

                if(tmp2->prev!=NULL && strcmp(newno1->word,tmp2->word)<0)// the case where we create a node right before another.
                {
                    newno1->next=tmp2;
                    tmp2=tmp2->prev;
                    tmp2->next=newno1;
                    newno1->prev=tmp2;
                    tmp2=newno1->next;
                    tmp2->prev=newno1;

                }

                else if(tmp2->prev==NULL && strcmp(newno1->word,w)<0)//the case where we create a node right before the 1st node.
                {
                    newno1->next=tmp2;
                    A[w[0]-65]=newno1;
                    tmp2->prev=newno1;



                }

                tail2=tmp2;
                tmp2=tmp2->next;


                }

            tail2->next=newno1;
            newno1->prev=tail2;}


}
}
break;}




case 3: {
struct node *tmp1;
char w1[50];
int x,k=0,epil2;

cout<<"Give a word to import"<<endl;
cin>>w1;


tmp1=A[w1[0]-65];

while(tmp1!=NULL){

  if(strcmp(w1,tmp1->word)==0){//search for the word in the dictionary
        cout<<"Word: "<<w1<<" found in the dictionary, we can't import it."<<endl;
        k=1;
        break;}

    tmp1=tmp1->next;}

  if(k==1){//if the program find the word , it will stop.
          break;
          }

  else{ //if the word don't exist in the dictionary, we can import it.
    char meaning1[200];

    cout<<"Meaning for the word: "<<w1<<endl;
    cin>>meaning1;

    struct node *newno1=new struct node;

     newno1->mean[200]=meaning1[200];
     newno1->word[50]=w1[50];

          if(A[w1[0]-65]==NULL){//in there isn't any node

             A[w1[0]-65]=newno1;
             newno1->next=NULL;
             newno1->prev=NULL;

        }

          else
            {//in other case

             struct node *tmp2=A[w1[0]-65];
             struct node *tail3;

             while(tmp2!=NULL){

                if(tmp2->prev!=NULL && strcmp(newno1->word,tmp2->word)<0)// the case where we create a node right before another.
                {
                    tmp2=tmp2->prev;
                    tmp2->next=newno1;
                    newno1->prev=tmp2;
                    tmp2=newno1->next;
                    tmp2->prev=newno1;
                }
                else if(tmp2->prev==NULL && strcmp(newno1->word,w1)<0)// the case where we create a node right before the 1st node.
                {
                    newno1->next=tmp2;
                    A[w1[0]-65]=newno1;
                    tmp2->prev=newno1;
                }


                tail3=tmp2;
                tmp2=tmp2->next;
                }

            tail3->next=newno1;
            newno1->prev=tail3;}

cout<<"Word imported: Checked!"<<endl;

  }
break;}





case 4:{
struct node *tmp1;
char word1[50];
int x,i=0;

cout<<"Word for delete: "<<endl;
cin>>word1;

tmp1=A[word1[0]-65];

    while(tmp1!=NULL){//searching the spot in the table for the word
    if(strcmp(word1,tmp1->word)==0){
        k=1;
        break;
    }
    i=i+1;//pointer of the words I passed by while I am searching for the word
    tmp1=tmp1->next;}


if(k==1){
    struct node *curr;//current node
    struct node *pre;//previous node
    curr=A[word1[0]-65];
    pre=NULL;

    if(i==0){//if the word is the head of the list
        delete curr;
        A[word1[0]-65]=NULL;
        cout<<"Word deleted: Checked"<<endl;
    }
    else{// if the word is belongs to any node in the list
    for(int j=0;j<i;j++){

        pre=curr;
        curr=curr->next;
    }
    pre->next=curr->next;
    delete curr;

cout<<("Word deleted: Checked")<<endl;

}}
break;}


case 5:{
    char x[1];
    struct node *tmp;
    struct node *l;

    cout<<"Give me a Char to delete: "<<endl;
    cin>>x;

    tmp=A[x[0]-65];

    if(tmp==NULL){// if tmp shows on the head, we have no objects to delete
    cout<<"DEN YPARXOUN STOIXEIA GIA DIAGRAFH"<<endl;}

    else{ //in other case we delete the word one by one.
    while(tmp!=NULL){
    l=tmp;
    tmp=tmp->next;

    delete l;}
    cout<<"Delete of words: Checked"<<endl;}

    A[x[0]-65]=NULL; //in the end we set the head equal to null
    break;}


case 6:{
    char word1[1];
    struct node *tmp;

    cout<<"Give a letter for printing every word starts with this letter: "<<endl;
    cin>>word1;

    tmp=A[word1[0]-65];

        while(tmp!=NULL){
        cout<<tmp->word<<": "<<tmp->mean<<endl;
        tmp=tmp->next;
        }
break;}


case 7:{

struct node *tmp;//create a file with the table and the lists
ofstream file1;
file1.open("Dictionary.txt");

tmp=A[0];

for(int i=0;i<26;i++){
    while(tmp!=NULL){
    file1<<tmp->word<<':'<<tmp->mean;
    tmp=tmp->next;}

    tmp=A[i+1];}

file1.close();
cout<<"Dictionary is Ready!"<<endl;
break;}



}//SWITCH

}while(epil!=0&&epil!=8);}



void menu(){
cout<<endl;
cout<<"1. Read file,insert it to the program."<<endl;
cout<<"2. Search for a word's meaning.If the word is out of the dictionary import it."<<endl;
cout<<"3. Import a new word in the dictionary."<<endl;
cout<<"4. Delete a word."<<endl;
cout<<"5. Delete a letter's list."<<endl;
cout<<"6. Show every words and meanings for a letter."<<endl;
cout<<"7. Create a new file with the dictionary."<<endl;
cout<<"8. Exit."<<endl;
cout<<" Choice: "<<endl;
}
