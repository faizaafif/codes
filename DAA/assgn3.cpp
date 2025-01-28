#include <iostream>
using namespace std;

class graph{
    int cost[10][10];
    int tcities;
    public:
        graph();
        void create();
        void display();
        void prims();

        graph(){
        tcities = 0;
        cout<<"\nEnter no. of cities:";
        cin>>tcities;
        for(int i=0; i<tcities; i++){
            for(int j=0; j<tcities; j++){
                cost[i][j]=999;
                }
            }
        }

        void create(){
            char ch;
            //for(int i=0; i <)
        }

        void display(){}

        void prims(){
            
        }
};


