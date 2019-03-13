// this file will hold the prototypes for the graph 
// and the class implementation

#include <iostream>
#include <cctype>
#include <cstring>


using namespace std;

class edge{

  public:
  char * outcome;
  edge * next;
};
class vertex{

  public:
  char * decision;
  class edge * head;
};
class table{



};

