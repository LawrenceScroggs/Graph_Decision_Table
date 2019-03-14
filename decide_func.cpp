// This will store the implementation of my function prototypes


#include "decide.h"


vertex table::get_decision(vertex * add_v){


  cout << "Please enter a possible decision: ";
  char * dec = new char[100];
  cin.get(dec,100);
  cin.ignore(100,'\n');
  add_v->decision = new char[strlen(dec)+1];
  strcpy(add_v->decision,dec);

  delete [] dec;
  
  return *add_v;

}
table::table(){

  list_size = 13;

  table_list = new vertex[list_size];

  for(int i=0;i<list_size;++i)
  {
    table_list[i].decision = NULL;
    table_list[i].head = NULL;
  }
}
table::~table(){


}
edge::edge(){

  next = NULL;
}
edge::~edge(){

  delete next;

}
vertex::vertex(){

  head = NULL;
}
vertex::~vertex(){

  delete head;

}
