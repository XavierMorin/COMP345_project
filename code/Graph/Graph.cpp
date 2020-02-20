//
// Created by Kunming Yang on 2020-02-14.
//

#include "Graph.h"
#include<iostream>
#include<cstdlib>

using namespace std;

//struct for an adjacency list node
struct AdjListNode{
    int data;
    AdjListNode *next;
};

//struct for an adjacency list
struct AdjList{
    AdjListNode *head;  //pointer to head node of list
};

//struct for a graph. A graph as an array of adjacency lists
//Size of array will be V (total vertices)
struct Graph{
    int V;
    AdjList *arr;
};

AdjListNode *newAdjListNode(int);
Graph *createGraph(int);
void addEdge(Graph*,int,int);
void printGraph(Graph*);

//create a new node
AdjListNode* newAdjListNode(int data){
    AdjListNode *nptr=new AdjListNode;
    nptr->data=data;
    nptr->next=NULL;
    return nptr;
}

//function to create a graph of V - vertices
Graph* createGraph(int V)
{
    Graph *graph = new Graph;
    graph -> V = V;
    //create an array of adjacency list. size of array - V
    graph -> arr = new AdjList[V];
    //initialize with NULL (e.g root=NULL)
    for(int i=0;i<V;i++){
        graph -> arr[i].head = NULL;
    }
    return graph;
}

//add an edge to an undirected Graph
void addEdge(Graph *graph,int src,int dest){
    //Add an edge from src to dest. A new node added to the adjacency list of src
    //node added at beginning
    AdjListNode *nptr=newAdjListNode(dest);
    nptr->next=graph->arr[src].head;
    graph->arr[src].head=nptr;
    //connect from dest to src (since undirected)
    nptr=newAdjListNode(src);
    nptr->next=graph->arr[dest].head;
    graph->arr[dest].head=nptr;
}