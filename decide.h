// this file will hold the prototypes for the graph 
// and the class implementation

#include <iostream>
#include <cctype>
#include <cstring>


using namespace std;

class edge{

  public:
    edge();
    ~edge();
    char * outcome;
    edge * next;
    class vertex * connect;
};
class vertex{

  public:
    vertex();
    ~vertex();
    char * decision;
    edge * head;

};
class table{

  public:

    table();
    ~table();
    vertex get_decision(vertex * add_v);
    int insert_decision(vertex * add_v);
    int display_connections(vertex * add_v, edge * add_e);
    int display_all(vertex * add_v,edge * add_e);

  private:

    int insert_decision_p(vertex *& to_add,edge *& add_e);
    int insert_outcome(vertex *& add_v,edge *& add_e);

    vertex * table_list;

    int list_size;

    int table_count = 0;

};

