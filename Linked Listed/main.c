#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*nada mohammed hassan          sec 4   bn 36
nermeen mohammed abd elaleem    sec 4   bn 37
nessma gaber ibrahim            sec 4   bn 38*/


typedef struct student {
  char name [50];  // 50bytes
  int id; // 4bytes
  int birthday[3]; //12bytes
  int score; // 4bytes
}Student;

//---------------------------DYNAMIC ARRAY-----------------------------------

Student *addTOArray(Student *stdPtr){
    printf("\nThe name of the student: ");
    fflush(stdin);
    scanf("/n%*c");
    fgets(stdPtr->name,sizeof(stdPtr->name),stdin);
    printf("\nEnter id: ");
    scanf("%d",  &stdPtr->id);
    printf("\nThe date of birth of the student: \n");
    printf("the day : ");
    scanf("%d",&stdPtr->birthday[0]);
    printf("\nthe month : ");
    scanf("%d",&stdPtr->birthday[1]);
    printf("\nthe year : ");
    scanf("%d",&stdPtr->birthday[2]);
    printf("\nEnter score: ");
    scanf("%d",&stdPtr->score);
    return stdPtr;
    }

void displayArray(Student *stdPtr, int length){
    for(int i = 0; i < length; i++){
            printf("\n\nThe information of student #%d:\n",i+1);
            printf("the name: %sthe id: %d\nthe birth date: %d/%d/%d\nthe score: %d\n", (stdPtr+i)->name, (stdPtr+i)->id , (stdPtr+i)->birthday[0] , (stdPtr+i)->birthday[1], (stdPtr+i)->birthday[2] , (stdPtr+i)->score);
            }
    }

Student *insert(int position, int newLength, Student *stdPtr){
    int tempLength = newLength-position -1;
    Student *stdTemp = (Student*)malloc(tempLength* sizeof(Student));
    for(int i = position,j = 0; i < newLength-1, j < tempLength ; i++, j++){
            *(stdTemp+j) = *(stdPtr+i);
            }
    stdPtr = (Student*)realloc(stdPtr,newLength*sizeof(Student));
    addTOArray((stdPtr+position));
    for(int i = position+1, j =0; i < newLength, j < tempLength; i++,j++){
            *(stdPtr+i) = *(stdTemp+j);
            }
    return stdPtr;
    }

//------------------------------------------ Linked list-----------------------------

struct Node {
    struct student data;
    struct Node* next;
};

void add (struct Node* ptr){
    printf("\nThe name of the student: ");
    fflush(stdin);
    scanf("/n%*c");
    fgets(ptr->data.name,sizeof(ptr->data.name),stdin);
    printf("\nThe id of the student: ");
    scanf("%d",&ptr->data.id);
    printf("\nThe date of birth of the student: \n");
    printf("the day : ");
    scanf("%d",&ptr->data.birthday[0]);
    printf("\nthe month : ");
    scanf("%d",&ptr->data.birthday[1]);
    printf("\nthe year : ");
    scanf("%d",&ptr->data.birthday[2]);
    printf("\nThe score of student: ");
    scanf("%d",&ptr->data.score);
    printf("\n");
    }

void display (struct Node* ptr,int num){
    for (int i=1;i<=num;i++){
            printf("\n\nThe information of student #%d:\n",i);
            printf("The name: ");
            printf("%s",ptr->data.name);
            printf("The id: ");
            printf("%d\n",ptr->data.id);
            printf("The date of birth: %d/%d/%d \n",ptr->data.birthday[0],ptr->data.birthday[1],ptr->data.birthday[2]);
            printf("The score of student: ");
            printf("%d\n",ptr->data.score);
            ptr=ptr->next;
            }
    }

struct Node* make_list( struct Node* ptr,int num){
    struct Node* p;
    printf("\nPlease enter the information of the student #1\n");
    add(ptr);
    for (int i=2;i<=num;i++){
            p=ptr;
            ptr = (struct Node*)malloc(sizeof(struct Node));
            printf("\nPlease enter the information of the student #%d\n",i);
            add(ptr);
            p->next=ptr;
            }
    printf("-------------------------------------------------------------\n");
    return ptr;
    }

struct Node *insert2(struct Node* ptr_h,int num,int x){
    struct Node* ptr_e=ptr_h->next;
    int n;
    if (x==1){
        n=0;
    }else if(x==2){
        n=num;
    }
    else if(x==3){
    printf("After which node do you want to insert the new student:\nEnter valid inputs from 1 to %d\n",num-1);
    scanf("%d",&n);}
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    if ((n<=num)&(n>0)){
        add(new_node);
        for (int i=2;i<=n;i++){
            ptr_h=ptr_h->next;
            ptr_e=ptr_e->next;
            }
        new_node->next=ptr_e;
        ptr_h->next=new_node;
        return new_node;
        } else if(n==0){
            add(new_node);
            new_node->next=ptr_h;
            return new_node;
        }
    else
        printf("invalid input");
    }

int main(){
    printf("Welcome to our repo\n");
    printf("please complete the following informations.\n\n");

    while (1){
    printf("\nchoose :\n 1-using dynamic arrays \n 2-using linked lists \n");
    int dyn_ll;
    scanf("%d",&dyn_ll);

    switch (dyn_ll){
        case 1://DYNAMIC ARRAY
            printf("Enter the number of elements of the dynamic array (positive integer): ");
            int n;
            scanf (" %d", &n);

            printf("-------------------------------------------------------------\n");
            printf("\nThe size of the struct: %d ",  sizeof(Student));
            printf("\nThe size of the dynamic array: %d\n",  n* sizeof(Student));
            printf("-------------------------------------------------------------\n");

            if (n<=0){
                printf("\ninvalid input\n");
                }

            else {
                Student *stdArr = (Student*)malloc(n*sizeof(Student));
                for (int i=0;i < n;i++){
                        printf("\nPlease enter the information of the student #%d\n",i+1);
                        stdArr = insert(i, n , stdArr);
                        }
                printf("-------------------------------------------------------------\n");
                printf("the list you entered:\n");
                displayArray(stdArr, n);

                while(1){
                    printf("-------------------------------------------------------------\n");
                    printf("\nchoose :\n 1-to insert at the beginning \n 2-to insert at the end \n 3-to insert at any position \n 4-if you don't want to do any modifications \n");
                    int d;
                    scanf("%d",&d);
                    switch (d){
                    case 1:
                        n=n+1;
                        clock_t begin1 = clock();
                        stdArr= insert(0, n , stdArr);
                        clock_t end1 = clock();
                        double time_spent1 = (double)(end1 - begin1)/ CLOCKS_PER_SEC;
                        printf("-------------------------------------------------------------\n");
                        printf("\n\nTime consumed by the insert to insert one element at the beginning: %f\n", time_spent1);
                        printf("-------------------------------------------------------------\n");
                        printf("the array after modification\n");
                        printf("-------------------------------------------------------------\n");
                        printf("\nThe size of the dynamic array: %d\n",  n* sizeof(Student));
                        printf("-------------------------------------------------------------\n");
                        displayArray(stdArr,n);
                        printf("-------------------------------------------------------------\n");
                        break;
                    case 2:
                        n=n+1;
                        clock_t begin2 = clock();
                        stdArr= insert(n-1, n , stdArr);
                        clock_t end2 = clock();
                        double time_spent2 = (double)(end2 - begin2)/ CLOCKS_PER_SEC;
                        printf("-------------------------------------------------------------\n");
                        printf("\n\nTime consumed by the insert to insert one element at the end: %f\n", time_spent2);
                        printf("-------------------------------------------------------------\n");
                        printf("the array after modification\n");
                        printf("-------------------------------------------------------------\n");
                        printf("\nThe size of the dynamic array: %d\n",  n* sizeof(Student));
                        printf("-------------------------------------------------------------\n");
                        displayArray(stdArr,n);
                        printf("-------------------------------------------------------------\n");
                        break;
                    case 3:
                        printf("\nEnter the position of the new element (positive integer): ");
                        int p;
                        scanf (" %d", &p);
                        if (p > 0  && p < n-1){
                            n=n+1;
                            clock_t begin3 = clock();
                            stdArr= insert(p, n , stdArr);
                            clock_t end3 = clock();
                            double time_spent3 = (double)(end3 - begin3)/ CLOCKS_PER_SEC;
                            printf("-------------------------------------------------------------\n");
                            printf("\n\nTime consumed by the insert to insert one element at position %i: %f\n",p, time_spent3);
                            printf("-------------------------------------------------------------\n");
                            printf("the array after modification\n");
                            printf("-------------------------------------------------------------\n");
                            printf("\nThe size of the dynamic array: %d\n",  n* sizeof(Student));
                            printf("-------------------------------------------------------------\n");
                            displayArray(stdArr,n);
                            printf("-------------------------------------------------------------\n");
                            }
                        break;
                    default: break;
                    }
             printf("do you want to do any other modification (y or n)?");
             char s='n';
             scanf("%s",&s);
             if (s!='y')break;
             }
             free(stdArr);

                }

            break;
            case 2:; //LINKED LISTS
            struct Node* head = NULL;
            struct Node* tail = NULL;
            head = (struct Node*)malloc(sizeof(struct Node));
            int N;
            printf("Enter the number of students of the linked list: ");
            scanf("%d",&N);

            printf("-------------------------------------------------------------\n");
            printf("\nThe size of the struct: %d ",  sizeof(struct Node));
            printf("\nThe size of the linked list: %d\n",  N* sizeof(struct Node));
            printf("-------------------------------------------------------------\n");

            tail=make_list(head,N);
            printf("the list you entered:\n");
            display(head,N);
            struct node *dummy;
            while(1){
                printf("-------------------------------------------------------------\n");
                printf("\nchoose :\n 1-to insert at the beginning \n 2-to insert at the end \n 3-to insert at any position \n 4-if you don't want to do any modifications \n");
                int d;
                scanf("%d",&d);
                switch (d){
                    case 1:;
                        clock_t begin4 = clock();
                        head= insert2(head,N,1);
                        clock_t end4 = clock();
                        double time_spent4 = (double)(end4 - begin4)/ CLOCKS_PER_SEC;
                        printf("-------------------------------------------------------------\n");
                        printf("\n\nTime consumed by the insert to insert one element at the beginning: %f\n", time_spent4);
                        N=N+1;
                        printf("-------------------------------------------------------------\n");
                        printf("the list after modification\n");
                        printf("-------------------------------------------------------------\n");
                        printf("\nThe size of the linked list: %d\n",  N* sizeof(struct Node));
                        printf("-------------------------------------------------------------\n");
                        display(head,N);
                        printf("-------------------------------------------------------------\n");
                        break;
                    case 2:;
                        clock_t begin5 = clock();
                        tail=insert2(head,N,2);
                        clock_t end5 = clock();
                        double time_spent5 = (double)(end5 - begin5)/ CLOCKS_PER_SEC;
                        printf("-------------------------------------------------------------\n");
                        printf("\n\nTime consumed by the insert to insert one element at the end: %f\n", time_spent5);
                        N=N+1;
                        printf("-------------------------------------------------------------\n");
                        printf("the list after modification\n");
                        printf("-------------------------------------------------------------\n");
                        printf("\nThe size of the linked list: %d\n",  N* sizeof(struct Node));
                        printf("-------------------------------------------------------------\n");
                        display(head,N);
                        printf("-------------------------------------------------------------\n");
                        break;
                    case 3:;
                        clock_t begin6 = clock();
                        dummy= insert2(head,N,3);
                        clock_t end6 = clock();
                        double time_spent6 = (double)(end6 - begin6)/ CLOCKS_PER_SEC;
                        printf("-------------------------------------------------------------\n");
                        printf("\n\nTime consumed by the insert to insert one element at the middle: %f\n", time_spent6);
                        N=N+1;
                        printf("-------------------------------------------------------------\n");
                        printf("the list after modification\n");
                        printf("-------------------------------------------------------------\n");
                        printf("\nThe size of the linked list: %d\n",  N* sizeof(struct Node));
                        printf("-------------------------------------------------------------\n");
                        display(head,N);
                        printf("-------------------------------------------------------------\n");
                        break;
                    default: break;
                    }
             printf("do you want to do any other modification (y or n)?");
             char s='n';
             scanf("%s",&s);
             if (s!='y')break;
             }
    free(head);
    printf("-------------------------------------------------------------\n");
    break;
    default: break;
    }
    printf("do you want to return to the main page(y or n)?");
    char s='n';
    scanf("%s",&s);
    if (s!='y')break;
    }
  return 0;
  }
