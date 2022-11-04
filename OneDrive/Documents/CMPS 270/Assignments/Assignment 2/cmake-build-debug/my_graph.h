/*
my_graph(const vector<int> &starts,const vector<int> &ends)
Requires: two integer vectors of the same length.
Effects: A graph containing the connections between a vertex at "starts" and a destination at "ends".
Testing strategy:
If we pass vectors of different lengths: throw an exception.

_______________________________________________________________________________________________________

int numOutgoing(const int nodeID)
Requires: an integer representing the nodeID to be checked.
Effects: returns the number of outgoing edges from nodeID, if any.
testing strategy:
passing a nodeID that doesn't exist in the graph. Returns: a statement showing that the vertex doesn't exist, and -1.
passing a nodeID that exists: Returns the intended output.

_________________________________________________________________________________________________________

const vector<int> &adjacent(const int nodeID)
Requires: an integer nodeID representing the vertex to be checked.
Effects: returns a vector consisting of the adjacent vertices.
Testing strategy:
passing a nodeID that doesn't exist in the graph. Returns: a statement showing that the vertex doesn't exist.
passing a nodeID that exists: Returns the intended output.
*/

#ifndef ASSIGNMENT_2_MY_GRAPH_H
#define ASSIGNMENT_2_MY_GRAPH_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class my_graph {
protected:
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
    const vector<int> hasCycle(){
        return checkCycle(Graph);
    }
private:
    const vector<int> checkCycle(map<int,vector<int>> Graph){
         vector<int> current_Destinations;
         vector<int> current_Destinations2;
         vector<int> resultingCycle;
         int NumCommonDestinations=0;
        for(auto itr=Graph.begin();itr!=Graph.end();itr++){
            current_Destinations=itr->second;
            int a=itr->first;
            resultingCycle.push_back(itr->first);
            for(auto itr2=Graph.begin();itr2!=Graph.end();itr2++){
            int b=itr2->first;
            if(a!=b){
            current_Destinations2=itr2->second;
            resultingCycle.push_back(itr2->first);
                for(int i=0;i<current_Destinations.size();i++){
                    for(int j=0;j<current_Destinations2.size();j++){
                        if (current_Destinations[i]==current_Destinations2[j]){
                            NumCommonDestinations++;
                            resultingCycle.push_back(current_Destinations2[j]);
                        }
                    }
                }
            if(resultingCycle.size()>=4)
                return resultingCycle;
            NumCommonDestinations=0;
            current_Destinations2.clear();
            resultingCycle.clear();
            }
            }
            current_Destinations.clear();
            resultingCycle.clear();
        }
        vector <int> failed;
        failed.push_back(-99999);
        return failed;
    }

};


#endif //ASSIGNMENT_2_MY_GRAPH_H
