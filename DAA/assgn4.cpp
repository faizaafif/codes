#include<iostream>
#include<string.h>

using namespace std;
 
class avlNode{
	string word, meaning;
	avlNode *left;
	avlNode *right;
 
	public:
		avlNode(){
			word = "";
			meaning = "";
			left = nullptr;
			right = nullptr;
		}
		friend class avlTree;
};
 
class avlTree{
	public:
		avlNode *root;
		avlTree(){
			root=NULL;
		}
 
		int height(avlNode* temp){
			int h=0;
			if(temp!=NULL){
				int l_height = height(temp->left);
				int r_height = height(temp->right);
				int max_height = max(l_height,r_height);
				h = max_height+1;
			}
			return h;
		}
 
		int diff(avlNode* temp){
			int l_height = height(temp->left);
			int r_height = height(temp->right);
			int difference = l_height-r_height;
			return difference;
		}
 
		avlNode* balance(avlNode* temp){
			int bal_factor = diff(temp);
			if(bal_factor>1){
				if(diff(temp->left) >0){
					temp = ll_rotation(temp);
				}
				else{
					temp = lr_rotation(temp);
				}
			}
			else if(bal_factor < -1){
				if(diff(temp->right) > 0){
					temp = rl_rotation(temp);
				}
				else{
					temp=rr_rotation(temp);
				}
			}
			return temp;
		}
 
		void insert(){
			char ch;
			do{
				avlNode *temp = new avlNode();				
				cout<<"Enter the word : ";
				cin>>temp->word;
				cout<<endl;
				cout<<"Enter the meaning : ";
				cin>>temp->meaning;
				cout<<endl;
				root = insert(root,temp);
				cout<<"Enter choice y/n :";
				cin>>ch;
			}while(ch=='y' || ch=='Y');
		}
 
		avlNode* insert(avlNode* root, avlNode* temp){
			if(root == NULL){
				root = new avlNode;
				root->word = temp->word;
				root->meaning = temp->meaning;
				root->left = NULL;
				root->right = NULL;
				return root;
			}
			else if(temp->word < root->word){
				root->left = insert(root->left,temp);
				root = balance(root);
			}
			else if(temp->word >= root->word){
				root->right = insert(root->right,temp);
				root = balance(root);
			}
			return root;
		}
 
		avlNode* ll_rotation(avlNode* parent){
			avlNode *temp = parent->left;
			parent->left = temp->right;
			temp->right = parent;
			return temp;
		}
		avlNode* rr_rotation(avlNode* parent){
			avlNode *temp = parent->right;
			parent->right = temp->left;
			temp->left = parent;
			return temp;
		}
		avlNode* lr_rotation(avlNode* parent){
			avlNode *temp = parent->left;
			parent->left = rr_rotation(temp);
			return ll_rotation(parent);
		}
		avlNode* rl_rotation(avlNode* parent){
			avlNode *temp = parent->right;
			parent->right = ll_rotation(temp);
			return rr_rotation(parent);
		}
		void display(avlNode* ptr, int level = 1){
            if (ptr != nullptr){
                display(ptr->right, level + 1);
                cout << endl;
                if (ptr == root) {
					cout << "Root -> ";
				}
                for (int i = 0; i < level && ptr != root; i++) {
					cout << "        ";
				}
                cout << ptr->word;
                display(ptr->left, level + 1);
                cout << endl;
            }
        }
		void preorder(avlNode* root){
			if(root !=NULL){
				cout << root->word << " : " << root->meaning << endl;
				preorder(root->left);
				preorder(root->right);
			}
		}
		void inorder(avlNode* root){
			if(root != NULL){
				inorder(root->left);
				cout << root->word << " : " << root->meaning << endl;
				inorder(root->right);
			}
		}
		void postorder(avlNode* root){
			if(root != NULL){
				postorder(root->left);
				postorder(root->right);
				cout << root->word << " : " << root->meaning << endl;
			}
		}
};

int main(){
    avlTree dict;
    int ch;
    while(1){
        cout << "1. Insert data\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. Level order traversal\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                dict.insert();
                break;
            case 2:
                cout << "Preorder traversal is:\n";
                dict.preorder(dict.root);
                break;
            case 3:
                cout << "Inorder traversal is:\n";
                dict.inorder(dict.root);
                break;
            case 4:
                cout << "Postorder traversal is:\n";
                dict.postorder(dict.root);
                break;
            case 5:
                cout << "Level order traversal is:\n";
                dict.display(dict.root);
                break;
            case 6:
                cout << "Thank You!";
                return 0;
        }
    }
}
