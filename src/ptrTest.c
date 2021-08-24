#include <stdio.h>
#include <unistd.h>

typedef struct node {
    int * x;
} node;


typedef struct nodeCollection {
    node * nodes;
} nodeCollection;


nodeCollection * createCollection() {
    int myInt = 2;
    
    node myNode = {&myInt};
    node * myNodeptr = &myNode;
    nodeCollection nodeCollection = {myNodeptr};
    // nodeCollection* something = &nodeCollection;
    int x =2;
    return &nodeCollection;
}

node * createNode() {
    int myX = 55;
    node myNode = {&myX};
    node * nodePtr = &myNode;
    return nodePtr;
}


int * myFunction() {
    int y=0;
    int * x;
    x = &y;
    * x = 2;
    // printf("%d",*x);
    return x;
    
}

int main()
{
    
    int * result = myFunction();
    // printf("%d",*result);
    node * myResult = createNode();
    
    // myResult->x;
    int * xResult = myResult->x;
    printf("HERE\n");
    sleep(1);
    printf("%d",*xResult);
    nodeCollection * nodeColl = createCollection();
    
    printf("%d",*nodeColl->nodes->x);
    
    
    return 0;
}
