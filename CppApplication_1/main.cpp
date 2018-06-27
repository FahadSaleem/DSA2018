/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Fahad Saleem
 *
 * Created on June 27, 2018, 10:33 AM
 */

#include <cstdlib>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * 
 */
enum gender {F, M};
enum color {White, Brown, Black, Spotted};
struct bunny{
        char * bunnyGender;
        char * bunnyColor;
        int bunnyAge;
        bool bunnyRadioactive;
        char * bunnyName;
        bunny * next;
    } * start= NULL;
    
    
    void traverseBunnyData(bunny * starter){
        if (starter==NULL)
            return;
     bunny * b = starter;
      while (b->next!=NULL){
       printf("bunny name: %s\n",b->bunnyName);
       printf("Bunny age: %d\n",b->bunnyAge);
       printf("Bunny color: %s\n",b->bunnyColor);
       printf("Bunny gender: %s\n",b->bunnyGender);
       printf("Bunny radioactivity: %s\n",b->bunnyRadioactive? "yes" : "no");
       b = b->next;
       }

}
int main(int argc, char** argv) {
    struct bunny bunnies[5];
    FILE * fPtr;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fPtr = fopen("F:\\bunnyInput.txt","r");
    
    
    int i;
    int x;
    while ((read = getline(&line, &len, fPtr)) != -1) {
        if (x==2)
             traverseBunnyData(start);
   printf("Run = %d\n", x);
    srand(time(NULL));
    char * token;
    if (atoi(line)==1){
        i=0;
        continue;
    }
    else if (atoi(line)==2){
        printf("run value = %d, breaking loop now\n",x);
        break;
    }
    bunny * b = new bunny();

    if (start==NULL){
        start = b;
    }
    else{
        bunny * temp = start;
      while (temp->next!=NULL){
          temp = temp->next;
       }

        temp->next=b;
    }

        token = strtok (line," ,.-");
        b->bunnyName=token;
    token = strtok (NULL," ,.-");
     b->bunnyGender=token;

    token = strtok (NULL," ,.-");

        b->bunnyColor=token;

    token = strtok (NULL," ,.-");

        b->bunnyAge=atoi(token);
        b->next=NULL;
        int randomNum = rand()%100 +1;
        if (randomNum==1 || randomNum==2){
            b->bunnyRadioactive=true;
        }
    i++;
    x++;
       printf("bunny name: %s\n",b->bunnyName);
       printf("Bunny age: %d\n",b->bunnyAge);
       printf("Bunny color: %s\n",b->bunnyColor);
       printf("Bunny gender: %s\n",b->bunnyGender);
       printf("Bunny radioactivity: %s\n",b->bunnyRadioactive? "yes" : "no");
    } 
    
   
   
  
    
}

