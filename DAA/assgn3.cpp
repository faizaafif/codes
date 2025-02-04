#include<iostream>
using namespace std;

class graph{
	int cost[10][10];
	int cities;
	public:
		graph(){
			cout<<"Enter number of cities :"<<endl;
			cin>>cities;
			for(int i=0; i<cities; i++){
            			for(int j=0; j<cities; j++){
                			cost[i][j]=999;
                		}
            		}
		}
		
		void create(){
			char ch;
			for(int i=0; i<cities; i++){
				for(int j=0; j<cities; j++){
					if(i != j && cost[i][j] == 99){
						cout<<"Is there a connection between"<< i<< "&"<< j<<"?"<<endl;
						cin>>ch;
						if(ch =='y' || ch == 'Y'){
							cout<<"Enter cost of edge\n";
							cin>>cost[i][j];
							cost[j][i]=cost[i][j];
						}
					}	
				}
			}
		}
		
		void display(){
			for(int i=0; i<cities; i++){
				for(int j=0; j<cities; j++){
					cout<<cost[i][j]<<endl;
				}	
				cout<<endl;
			}
		}
		
		int prims(int start_v){
			int nearest[cities];
			int n=cities;
			int t[cities][3];
			int r=0;
			int min =999;
			int mincost =0;
			int index;
			nearest[start_v]= -1;
			for(int i=0; i<=n; i++){
				if(i != start_v){
					nearest[i]= start_v;
				}
			}
			for(int i=1; i< n-1; i++){
				min = 999;
				for(int k=0; k<n-1; k++){
					if(nearest[k]= -1 && (cost[k][nearest[k]] < min)){
						index = k;
						min = cost[k][nearest[k]] ;
					}
				}
				t[r][0] = nearest[index];
				t[r][1] = index;
				t[r][2] = min;
				r++;
				mincost +=cost[index][nearest[index]];
				nearest[index] =-1;
				for(int k=0; k<n-1; k++){
					if(nearest[k]= -1 && (cost[k][nearest[k]] > cost[k][index])){
						nearest[k] = index;
					}
				}
			}
			return mincost;
		}
};

int main(){
	graph city;
	int  ch;
	do{
		cout<<"Enter user's choice :"<<endl;
		cout<<"1.Create\n2.Display\n3.Prims\n4.Exit";
		cin>>ch;
		switch(ch){
			case 1:
			city.create();
			break;
			
			case 2:
			city.display();
			break;
			
			case 3:
			city.prims(0);
			break;
			
			case 4:
			cout<<"Thank you!!!";
			return 0;

		}
	}while(ch<4);
}
