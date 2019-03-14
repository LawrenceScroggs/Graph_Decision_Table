// this file will hold the prototypes for the graph 
// and the class implementation

#include <iostream>
#include <cctype>
#include <cstring>


using namespace std;



class getInfo{

  public:
    int getVertex();
    int getEdge();

    int copy_vertex(const getInfo & to_add);

  private:
    int getVertex_p(); 
    int getEdge_p();

    char * vertex_info;
    char * edge_info;


};
class edge{

  friend class table;
  public:
    edge();
    ~edge();
    class vertex * connect;
    int get_outcome(getInfo & to_add);
    

  private:
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

    vertex add_v;
    vertex * table_list;
    vertex * temp;

    int list_size;

    int count = 0;

};

