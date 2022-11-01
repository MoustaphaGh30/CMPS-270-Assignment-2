//
// Created by mosta on 11/1/2022.
//

#include "my_graph.h"
#include <iostream>
#include <map>

int main(){
    vector<int> starts={0,0,0,4,4,3};
    vector<int> ends=  {1,2,3,3,1,1};
    my_graph *Graph=new my_graph(starts,ends);
    vector<int> testAdj=Graph->adjacent(0);
    for (int i:testAdj){
        cout<<"  "<<i;
    }
}