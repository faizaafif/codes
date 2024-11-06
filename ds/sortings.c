#include<stdio.h>
#include<string.h>
struct student{
	int prn;
	char name[30];
	};

int main(){
	int n, ch;
	printf("Enter the no of students: ");
	scanf("%d",&n);
	
	struct student students[n];
	
	for(int i = 0; i < n; i++){
	printf("Enter details of student %d\n", i+ 1);
	printf("PRN: ");
	scanf("%d", &students[i].prn);
	printf("Name: ");
	scanf("%s", students[i].name);
	}
	printf("Unsorted: \n");
	for(int i = 0; i < n; i++){
	printf("%d\t%s\n",students[i].prn,students[i].name);
	}
    printf("Enter the sorting method: \n");
	printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    scanf("%d",&ch);
	switch(ch){
        case 1:
            for(int i = 0; i < n; i++){
		        for(int j = 0; j < n - 1;j++){
			        if(students[j].prn > students[j + 1].prn){
				        int temp = students[j].prn;
				        students[j].prn = students[j + 1].prn;
				        students[j + 1].prn = temp;
				        char temp2[30];
				        strcpy(temp2,students[j].name);
				        strcpy(students[j].name,students[j + 1].name);
				        strcpy(students[j + 1].name,temp2);
				        }
		        }
	        }
			printf("Sorted : \n");
			for(int i = 0; i < n; i++){
				printf("%d\t%s\n",students[i].prn,students[i].name);
			}

            break;

        case 2:
            for(int i = 0; i < (n - 1); i++){
                int pos = i;
                for(int j = i + 1; j < n; j++){
                    if(students[j].prn < students[pos].prn){
                        pos = j;
                    }
                }
                if(pos != i){
                    int temp = students[i].prn;
				    students[i].prn = students[pos].prn;
				    students[pos].prn = temp;
					char temp2[30];
                    strcpy(temp2,students[i].name);
				    strcpy(students[i].name,students[pos].name);
				    strcpy(students[pos].name,temp2);
                }
            }
			printf("Sorted : \n");
			for(int i = 0; i < n; i++){
				printf("%d\t%s\n",students[i].prn,students[i].name);
			}
            break;

        case 3:
			for(int i = 1; i < n; i++){
        		int key = students[i].prn;
        		int j = i - 1;
        		while(j >= 0 && students[j].prn > key){
           			students[j + 1].prn = students[j].prn;
					char temp2[30];
                	strcpy(temp2,students[j + 1].name);
					strcpy(students[j + 1].name,students[j].name);
					strcpy(students[j].name,temp2);
            		j--;
        		}
        		students[j + 1].prn = key;				
    		}
			printf("Sorted : \n");
			for(int i = 0; i < n; i++){
				printf("%d\t%s\n",students[i].prn,students[i].name);
			}
			
            break;
    }

	return 0;
	}