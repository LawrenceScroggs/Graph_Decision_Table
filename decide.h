// this file will hold the prototypes for the graph 
// and the class implementation

#include <iostream>
#include <cctype>
#include <cstring>


using namespace std;



class getInfo{

  public:
    getInfo(void);
    ~getInfo();
    int getVertex(char * temp_vertex);
    int getEdge();

    int copy_vertex(const getInfo & to_add);
    char * getter();

  private:
    int getVertex_p(char * temp_vertex); 
    int getEdge_p();

    char * vertex_info;
    char * edge_info;


};
struct edge{
   

    vertex * key_value;
    getInfo * outcome;
    edge * next;
};
struct vertex{

 // friend class table;
 // public:
  //  vertex();
   // ~vertex();

    getInfo * decision;
    edge * head;

};
class table{

  public:

    table();
    ~table();
    bool insert_decision(getInfo & to_add);
    int display_connections(vertex * add_v, edge * add_e);
    int display_all(vertex * add_v,edge * add_e);

  private:

    bool insert_decision_p(const getInfo & to_add);
    int insert_outcome(vertex *& add_v,edge *& add_e);

    vertex * table_list;

    int list_size;

    int count = 0;

};

