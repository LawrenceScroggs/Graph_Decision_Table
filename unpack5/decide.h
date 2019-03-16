// Lawrence Scroggs--CS163--Program5--03/10/19
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
    int getVertex(char * temp); // Gets the info to add to vertex list

    char * v_info();

    int getVertex_p(char * temp); 

    char * vertex_info;


};
struct edge{

    struct vertex * adjacent;
    struct vertex * newDecision;
    char * outcome;
    edge * next = NULL;
    
};
struct vertex{

    getInfo * grabInfo;
    edge * head;
    char * decision;

};
class table{

  public:

    table();
    ~table();
    bool insert_decision(getInfo * to_add);
    int display_vertex(char * to_find);
    int display_all();
    int find_index(char * key_value);
    int better_decision();

    bool getEdge(char * temp,char * temp2);
  private:

    bool insert_decision_p(getInfo * to_add);

    bool connect_edge(char * temp, char * temp2);

    vertex * table_list;

    int list_size;

    int count = 0;

};

