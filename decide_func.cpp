// This will store the implementation of my function prototypes


#include "decide.h"



char * getInfo::getter(){


  return vertex_info;
  

}
int getInfo::copy_vertex(const getInfo & to_add){


  char * temp = new char[strlen(to_add.vertex_info)+1];
  strcpy(temp,to_add.vertex_info);

  cout << "temp: " << temp << endl;

  int p = getVertex(temp);

  


  return p;


} 
int getInfo::getEdge(){

  int check = getEdge_p();

  if(check != 0)
  {
    cout << "ERROR" << endl;
    return 0;
  }

  else
    return 0;
}
int getInfo::getEdge_p(){

  cout << "Please enter possible outcome: ";
  char * temp = new char[200];
  cin.get(temp,200);
  cin.ignore(200,'\n');
  edge_info = new char[strlen(temp)+1];
  strcpy(edge_info,temp);
 
  delete [] temp;

  return 0;

}
bool table::insert_decision(getInfo & to_add){

  bool check = true;
  char yn = ' ';

  check = insert_decision_p(to_add);

  if(check == true)
  {
    cout << "Would you like to add another? ";
    cin >> yn;
    cin.ignore(100,'\n');
    if(yn != 'n')
      return true;
    else
      return false;
  }
  else
    return false;

}  
bool table::insert_decision_p(const getInfo & to_add){

  count = 0;

  while(count < list_size)
  {
    if(!table_list[count].decision)
    {
     getInfo * data = new getInfo;
     data->copy_vertex(to_add);

      table_list[count].decision = data;
      cout << "Table at count: " << count << " Decision: " << table_list[count].decision->getter() << endl;
    
      return true;
    }
    else if(table_list[count].decision)
      ++count;
    else if(count >= list_size -1)
    {
      cout << "Full List" << endl << endl;
      return false;
    }
  }
}
int getInfo::getVertex(char * temp){

  int check = getVertex_p(temp);

  if(check != 0)
  {
    cout << "ERROR" << endl;
    return 0;
  }

  else
    return 0;
}
int getInfo::getVertex_p(char * temp){

 
  vertex_info = new char[strlen(temp)+1];
  strcpy(vertex_info,temp);

  cout << "vertex info" << vertex_info << endl;

  return 0;

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
/*edge::edge(){

  next = NULL;
}
edge::~edge(){

  delete next;

}*/
getInfo::getInfo(){

  vertex_info = NULL;
  edge_info = NULL;
}
getInfo::~getInfo(){

}
/*vertex::vertex(){

  decision = NULL;
  head = NULL;
}
vertex::~vertex(){

  delete head;

}*/
