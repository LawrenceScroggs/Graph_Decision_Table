// Lawrence Scroggs--CS163--03/10/19--Program 5
// This program will implement a graph for decisions made
// we will make a table of head pointers that make an LLL
// of possible outcomes that in return can lead to making
// a different decision



#include "decide.h"


int main(){

  getInfo to_add;
  table list;

  char * temp_vertex = new char[100];
  char * temp_edge = new char[200];
  char * connection = new char[100];
  char * to_find = new char[100];


  bool again = true;

  

  do{

    cout << "Please enter a possible decision: ";
    cin.get(temp_vertex,100);
    cin.ignore(100,'\n');

    to_add.getVertex(temp_vertex);
  

    again = list.insert_decision(&to_add);


  }while(again != false);

  again = false;
  do{
    cout << "Please enter an outcome: ";
    cin.get(temp_edge,200);
    cin.ignore(200,'\n');
    cout << "Please enter the decision it is connected with: ";
    cin.get(connection,100);
    cin.ignore(100,'\n');

    again = list.getEdge(temp_edge,connection);

    //list.better_decision();


  }while(again != false);
  list.display_all();
  cout << "Please enter the vertex you are looking to display: ";
  cin.get(to_find,100);
  cin.ignore(100,'\n');
  list.display_vertex(to_find);



  



  return 0;
}
