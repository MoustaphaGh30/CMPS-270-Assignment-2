//
// Created by mosta on 11/1/2022.
//

#ifndef ASSIGNMENT_2_MY_GRAPH_H
#define ASSIGNMENT_2_MY_GRAPH_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class my_graph {
private:
    map<int, vector<int>> Graph;
public:    
    my_graph(const vector<int> &starts,const vector<int> &ends){
        if(starts.size()!=ends.size())
            throw invalid_argument("Starts and Ends are of Different lengths\n");
        int i=0;
        vector<int> Endpoints;
        for (i=0;i<starts.size();i++){
            Endpoints.push_back(ends[i]);
            for (int j = i+1; j < starts.size(); ++j) {
                if (starts.at(i)==starts.at(j)){
                    Endpoints.push_back(ends[j]);
                }
                else {
                i=j-1;
                break;
                }
            }
            Graph.insert({starts[i],Endpoints});
            Endpoints.clear();
        }
    }
    int numOutgoing(const int nodeID){
        if (Graph.count(nodeID)>0)
        return Graph.at(nodeID).size();
        else 
        {
            cout<<"Vertex not found";
            return -1;
        }
    }
    const vector<int> &adjacent(const int nodeID){
        if (Graph.count(nodeID)>0)
        {
            return Graph.at(nodeID);

        }
        else {
            cout<<"Vertex not found";
        }
    }

};


#endif //ASSIGNMENT_2_MY_GRAPH_H
