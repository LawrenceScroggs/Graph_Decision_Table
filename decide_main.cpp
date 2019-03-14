// This program will implement a graph for decisions made
// we will make a table of head pointers that make an LLL
// of possible decisions and their then outcomes
// Lawrence Scroggs CS163 03/10/19 Program 5



#include "decide.h"


int main(){

  getInfo to_add;
  table list;
  edge add_e;

  bool again = true;

  

 do{


  to_add.getVertex();
  

  again = list.insert_decision(to_add);


 }
  while(again != false);

 //add_e.get_outcome();

  return 0;
}
