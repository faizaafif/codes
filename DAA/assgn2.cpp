#include <iostream>
using namespace std;
 
class gnode{
	int id;
	string name;
	gnode *next;
	friend class graph;
};

//STACK
class stack{
	int st[20];
	int top=-1;
	friend class graph;
	public:
		void push(int temp){
			top++;
			st[top]=temp;
		}
		int pop(){
			int t=st[top];
			top--;
			return t;
		}
		bool empty(){
			return top==-1;
		}
};

//QUEUE
class queue{
	int qu[20];
	int f=-1;
	int r=-1;
	friend class graph;
	public:
		void enq(int v){
			qu[++r]=v;
		}
		int dq(){
			return qu[++f];
		}
		bool empty(){
			return f == r;
		}
};
 
//GRAPH
class graph{
	gnode *head[20];
	bool visited[20];
	bool visited_bfs[20];
	int n;
 
	public:
		graph(){
			cout<<"Enter the number of vertices :\n";
			cin>>n;
			for(int i=0; i<n; i++){
				head[i]= new gnode;
				cout<<"Enter the name of the user :\n";
				cin>>head[i]->name;
				head[i]->id=i;
				head[i]->next= NULL;
			}
		}
		void create(){
			char choice;
			int addv =0;
			for(int i=0; i<n; i++){
				gnode *temp=head[i];
				do{	
					cout<<"Enter the adjacent vertex "<<i<<endl;
					cin>>addv;
					if(addv==i){
						cout<<"Self loop not allowed :\n";
					}
					else{
						gnode *curr = new gnode;
						curr->name=head[addv]->name;
						curr->id=addv;
						curr->next=NULL;
						temp->next= curr;
						temp= temp->next;
					}
					cout<<"Enter user's choice (y/n): \n";
					cin>>choice;
				}while(choice=='y' || choice=='Y');
			}
		}
 
		void display(){
			for(int i=0; i<n; i++){
				gnode *temp=head[i];
				cout<<"User's name :"<<head[i]->name<<endl;
				cout<<"User's ID :"<<head[i]->id<<endl;
				temp=temp->next;
				while(temp!=NULL){	
 
					cout<<"Friend's name :"<<temp->name<<endl;
					cout<<"Friend's id :"<<temp->id<<endl;
					temp=temp->next;
				}
			}
		}	
 
		void DFS(){
			int start;
			for (int i=0; i< n; i++){
				visited[i]=false;
			}
			cout<<"enter starting vertex"<<endl;
			cin>>start;
			DFS(start);
		}
 
		void DFS(int v){
			cout<<head[v]->name<<endl;
			visited[v]=true;
			gnode *temp=head[v];
			while(temp!=NULL){
				int w=temp->id;
				if(!visited[w]){
					DFS(w);
				}
				temp=temp->next;
			}
		}
 
		void DFS_nr(){
			for(int i=0; i<n; i++){
				visited[i]=false;
			}
			int start;
			cout<<"Enter starting index :"<<endl;
			cin>>start;
			
			stack s;
			s.push(start);
			visited[start]=true;
			while (!s.empty()) {
        		int v = s.pop();
        		cout << head[v]->name << endl; 
				gnode* temp= head[v]->next;
        		while (temp){
					int w= temp->id;
					if(!visited[w]){
						s.push(w);
						visited[w]=true;
					}
					temp= temp->next;
				}
				
			}
		}
 
		void BFS_nr(){
			for(int i=0; i<n; i++){
				visited[i]=false;
			}

			int start;
			cout<<"Enter starting index :"<<endl;
			cin>>start;

			queue q;
			q.enq(start);
			visited[start]= true;
			while(!q.empty()){
				int v=q.dq();
				cout<<head[v]->name<<endl;
				gnode* temp=head[v]->next;
				while(temp){
					int w = temp->id;
					if(!visited[w]){
						q.enq(w);
						visited[w] = true;
					}
					temp = temp->next;
				}
			}
		}
};

 
int main(){
	graph vertex;
	int ch;
	do{
		cout<<"Enter choice"<<endl;
		cout<<"1.Create\n2.DFS\n3.DFS_nr\n4.BFS_nr\n5.Display\n6.Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
			vertex.create();
			break;

			case 2:
			vertex.DFS();
			break;

			case 3:
			vertex.DFS_nr();
			break;

			case 4:
			vertex.BFS_nr();
			break;

			case 5:
			vertex.display();
			break;

			case 6:
			cout<<"Thank you!!!";
			return 0;
		}
	}while(ch<6);
	return 0;
}
