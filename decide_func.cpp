// Lawrence Scroggs--CS163--Program5--03/10/19
// This will store the implementation of my function prototypes


#include "decide.h"


// connects to better decision outcome
int table::better_decision(){

  char * better = new char[100];

  cout << "Does this outcome result in better decision? ";
  cin.get(better,100);
  cin.ignore(100,'\n');

  int p = find_index(better);


  return p;
}
// displays certain vertex and its outcomes
int table::display_vertex(char * to_find){

  int p = find_index(to_find);

  if(!table_list[p].decision)
    return -1;

  else
  {
    cout << "Decision: " << table_list[p].decision << endl;
    edge * current = table_list[p].head;
    while(current)
    {
      cout << "Outcome: " << current->outcome << endl;
      current = current->next;
    }
  }

 return -1;
}
// display all
int table::display_all(){

  count = 0;

  if(!table_list[count].decision)
    return -1;  
  
  while(count <= (list_size -1) && table_list[count].decision)
  {
    cout << "Decision: " << table_list[count].decision << endl;
    edge * current = table_list[count].head;
    while(current)
    {
      cout << "Outcome: " << current->outcome << endl;
      current = current->next;

    }
    ++count;
  }
  ++count;
}
// finds the decision in which we want to connect the outcome
int table::find_index(char * temp2){

  count = 0;
      //return the location of this particular key value
  while(count < list_size){

    if(!table_list[count].decision)
      ++count;


    if(strcmp(table_list[count].decision,temp2) == 0){
        return count;
    }
    else
      ++count;
        
    }
  if(count >= list_size -1)
    return -1;
}
// connects edge to vertex
bool table::connect_edge(char * temp, char * temp2){

  int i = find_index(temp2);

  if(table_list[i].head == NULL)
  {
    edge * newHead = new edge;
    newHead->adjacent = &table_list[i];
    newHead->outcome = new char[strlen(temp)+1];
    strcpy(newHead->outcome,temp);
    table_list[i].head = newHead;
    
    table_list[i].head->next = NULL;
  }
  else
  {
    edge * newHead = new edge;
    newHead->adjacent = &table_list[i];
    newHead->outcome = new char[strlen(temp)+1];
    strcpy(newHead->outcome,temp);
    newHead->next = table_list[i].head;

    table_list[i].head = newHead;
    } 
}
// gets edge info
bool table::getEdge(char * temp,char * temp2){


  connect_edge(temp,temp2);
 
  char yn = ' ';

  cout << "Would you like to add another outcome? ";
  cin >> yn;
  cin.ignore(100,'\n');
  if(yn != 'n')
    return true;
  else
    return false;

  delete [] temp;
  delete [] temp2;


}
// grabs info for client to redo
bool table::insert_decision(getInfo * to_add){

  bool check = true;
  char yn = ' ';

  check = insert_decision_p(to_add);

  if(check == true)
  {
    cout << "Would you like to add another decision? ";
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
// inserts the deciion into table
bool table::insert_decision_p(getInfo * to_add){

  count = 0;

  while(count < list_size)
  {
    if(!table_list[count].decision)
    {

      table_list[count].decision = new char[strlen(to_add->vertex_info)];
      strcpy(table_list[count].decision,to_add->vertex_info);
    
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
// grabs info for vertex
int getInfo::getVertex_p(char * temp){

 
  vertex_info = new char[strlen(temp)+1];
  strcpy(vertex_info,temp);

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

  delete table_list;

}
getInfo::getInfo(){

  vertex_info = NULL;
}
getInfo::~getInfo(){

  delete vertex_info;
}
