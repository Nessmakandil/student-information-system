/*
nada mohammed hassan sec4 bn36
nermeen mohammed abedelaleem sec4 bn37
nessma gaber ibrahim sec 4 bn38*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAME 50
#define DELETED_NODE (struct student*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct student {
    char name [MAX_NAME];
    int id;
    int birthday[3];
    int score;
    };

struct Node {
	struct student data;
	struct Node* next;
    };

//------------------------------- CHANINING -------------------------------

unsigned int hash (int TABLE1_SIZE, char *name){
    int name_length = strnlen(name,MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0;i < name_length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i])% TABLE1_SIZE;
        }
    return hash_value%TABLE1_SIZE;
    }

void init_hash_table1(int TABLE1_SIZE, struct Node *hash_table1[TABLE1_SIZE]){
     for (int i = 0; i < TABLE1_SIZE; i++){
        hash_table1[i] = NULL;
        }
    }

struct Node *addTOTable(struct Node *std){
    printf("\nThe name of the student: ");
    fflush(stdin);
    printf("\n");
    scanf("%*c");
    fgets(std->data.name,sizeof(std->data.name),stdin);
    printf("\nEnter id: ");
    scanf("%d",  &std->data.id);
    printf("\nThe date of birth of the student: \n");
    printf("the day : ");
    scanf("%d",&std->data.birthday[0]);
    printf("\nthe month : ");
    scanf("%d",&std->data.birthday[1]);
    printf("\nthe year : ");
    scanf("%d",&std->data.birthday[2]);
    printf("\nEnter score: ");
    scanf("%d",&std->data.score);
    return std;
    }

void print_table(int TABLE1_SIZE, struct Node *hash_table1[TABLE1_SIZE]){
    for (int i = 0; i < TABLE1_SIZE; i++){
        if(hash_table1[i] == NULL){
            printf("\t%i\t--\n", i);
            }
        else{
            struct Node *tmp = hash_table1[i];
            while(tmp != NULL){
                printf("\t%i\t%s\t\t%d\n\t\t%d/%d/%d\n\t\t%d\n",i,tmp->data.name, tmp->data.id, tmp->data.birthday[0],tmp->data.birthday[1],tmp->data.birthday[2], tmp->data.score );
                tmp = tmp->next;
                }
        }
    }
}
void insert_hash_table1(int TABLE1_SIZE, struct Node  *hash_table1[TABLE1_SIZE],struct Node * std){
    int index = hash(TABLE1_SIZE,std->data.name);
    //check if chain[key] is empty
    if(hash_table1[index]== NULL)
        hash_table1[index] = std;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct Node  *temp = hash_table1[index];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = std;
    }
}


struct Node  *delete_hash_table1(int TABLE1_SIZE, struct Node *hash_table1[TABLE1_SIZE], char name[MAX_NAME]){
    int index = hash(TABLE1_SIZE,name);
    struct Node  *tmp = hash_table1[index];
    struct Node  *prv = NULL;
    while (tmp != NULL && strncmp(tmp->data.name,name,TABLE1_SIZE)!=0){
        prv = tmp;
        tmp = tmp->next;
        }
    if (tmp == NULL) return NULL;
    if (prv == NULL) hash_table1[index] = tmp->next;
    else prv->next = tmp->next;
    return tmp;
    }

struct Node  *lookUP_hash_table1(int TABLE1_SIZE, struct Node  *hash_table1[TABLE1_SIZE], char name[MAX_NAME]){
    int index = hash(TABLE1_SIZE, name);
    struct Node  *tmp = hash_table1[index];
    while (tmp != NULL && strncmp(tmp->data.name,name,TABLE1_SIZE)!=0){
        tmp = tmp->next;
        }
    return tmp;
    }


//------------------------------------ PROBING------------------------------------------------
int hashing (int birth[3],int n)
{
  int keyy=birth[0]+ 100*birth[1]+10000*birth[2];
  int index =keyy%n;
  return index;}


void insertstd( int n,struct student *ptr[n],int m){
    int date[3];
     printf("\n\nEnter details of the new student:\n");
    printf("enter the the birth date :\n");
    printf("the day: ");
    scanf("%d",&date[0]);
     printf("\nthe month: ");
    scanf("%d",&date[1]);
     printf("\nthe year: ");
    scanf("%d",&date[2]);
    int index=hashing(date,n);
    int i;
          int t;
  for ( i=0;i<n;i++){
        if (m==1)
         t=(index+i)%n;
        else  t=(index+i*i)%n;
  if (ptr[t] == NULL||ptr[t] == DELETED_NODE){
    ptr[t]=(struct student*)malloc(sizeof(struct student));
    printf("\nThe name of the student: ");
    fflush(stdin);
    printf("\n");
    scanf("%*c");
    fgets(ptr[t]->name,sizeof(ptr[t]->name),stdin);
    printf("\nEnter id: ");
    scanf("%i", &(ptr[t])->id);
    printf("\nEnter score: ");
    scanf("%i", &(ptr[t])->score);
   (ptr[t])->birthday[0]=date[0];
   (ptr[t])->birthday[1]=date[1];
   (ptr[t])->birthday[2]=date[2];
      break;
  }}
}

void searchstd( int n,struct student *ptr[n], int date[3],int m)
{
  int index=hashing(date,n);
  int i;
  int t;
  for ( i=0;i<n;i++){
        if (m==1)
         t=(index+i)%n;
        else  t=(index+i*i)%n;
        if(ptr[t]==NULL){
                printf("not found\n");
            break;
        }
        if(ptr[t]==DELETED_NODE){
            continue;
        }
  if(ptr[t]->birthday[0]==date[0]&&ptr[t]->birthday[1]==date[1]&& ptr[t]->birthday[2]==date[2])
   {
       printf("found\n%s%d\n%d/%d/%d\n%d\n",ptr[t]->name, ptr[t]->id, ptr[t]->birthday[0],ptr[t]->birthday[1],ptr[t]->birthday[2], ptr[t]->score );
       printf("-------------------------------------------------------------\n");
       break;}}
  }


  void deletestd(int n,struct student *ptr[n], int date[3],int m){
   int index=hashing(date,n);
  int i;
    int t;
  for ( i=0;i<n;i++){
        if (m==1)
         t=(index+i)%n;
        else  t=(index+i*i)%n;
        if(ptr[t]==NULL){
                printf("not found\n");
            break;
        }
   if(ptr[t]==DELETED_NODE){
            continue;
        }
  if(ptr[t]->birthday[0]==date[0]&&ptr[t]->birthday[1]==date[1]&& ptr[t]->birthday[2]==date[2])
   {
       printf("found %s",ptr[t]->name);
       ptr[t]=DELETED_NODE;
       break;}}
}
  void printTable(int n,struct student *ptr[n]){
  for (int i=0;i<n;i++){
   if(ptr[i]==NULL) {
    printf("\t%i\t----\n",i);
   }else if(ptr[i]==DELETED_NODE){
   printf("\t%i\t---->DELETED\n",i);}
   else printf("\t%i\t%s\t\t%d\n\t\t%d/%d/%d\n\t\t%d\n",i,ptr[i]->name, ptr[i]->id, ptr[i]->birthday[0],ptr[i]->birthday[1],ptr[i]->birthday[2], ptr[i]->score );
  }
  }
//------------------------------------------- MAIN -------------------------------------


int main(){
    int N;
    struct student *stdptr[N];
    printf("please complete the following informations.\n\n");
    while (1){
        printf("\nchoose :\n 1-using chaining \n 2-using probing \n");
        int ch;
        scanf("%d",&ch);
        switch (ch){
            case 1:;
            printf("Enter the size of the table (positive integer): ");
            int TABLE1_SIZE;
            scanf (" %d", & TABLE1_SIZE);
            if (TABLE1_SIZE<=0) printf("\ninvalid input\n");

            else {
                struct Node  *hash_table1[TABLE1_SIZE];
                printf("-------------------------------------------------------------\n");
                printf("the table you entered:\n");
                init_hash_table1(TABLE1_SIZE, hash_table1);
                print_table(TABLE1_SIZE, hash_table1);
                printf("-------------------------------------------------------------\n");
                printf("Enter the number of students you want to enter (positive integer): ");
                int n;
                scanf (" %d", & n);
                int count1 = n;
                if (n <= 0) printf("\ninvalid input\n");

                else {
                    struct Node  *dummy = (struct Node*)malloc(n*sizeof(struct Node));
                    for (int i=0;i < n;i++){
                        printf("\nPlease enter the information of the student #%d\n",i+1);
                        addTOTable((dummy+i));
                        insert_hash_table1(TABLE1_SIZE, hash_table1,(dummy+i));
                    }

                    printf("-------------------------------------------------------------\n");
                    printf("the table you entered:\n");
                    print_table(TABLE1_SIZE, hash_table1);
                    printf("-------------------------------------------------------------\n");

                    printf("\nThe size of struct: %d \n ",  sizeof(struct Node));
                    printf("\nThe size of the table: %d\n ",  sizeof(hash_table1)+ n*sizeof(struct Node));
                    printf("-------------------------------------------------------------\n");

                }
                while(1){

                    printf("-------------------------------------------------------------\n");
                    printf("\nchoose :\n 1-to insert \n 2-to search \n 3-to delete \n 4-if you don't want to do any modifications \n");
                    int d;
                    scanf("%d",&d);
                    switch (d){
                        case 1:;
                        printf("\nPlease enter the information of the student \n");
                        struct Node  *dummy = (struct Node*)malloc(sizeof(struct Node));
                        addTOTable(dummy);
                        insert_hash_table1(TABLE1_SIZE, hash_table1,dummy);
                        printf("-------------------------------------------------------------\n");
                        printf("the table after insertion:\n");
                        print_table(TABLE1_SIZE, hash_table1);
                        printf("-------------------------------------------------------------\n");
                        count1=count1+1;

                        printf("\nThe size of the table after insertion: %d\n ", sizeof(hash_table1)+ count1 * sizeof(struct Node));
                        printf("-------------------------------------------------------------\n");

                        break;
                        case 2:;
                        char name1[50];
                        printf("\nThe name you want to search for: ");
                        fflush(stdin);
                        printf("\n");
                        scanf("%*c");
                        fgets(name1,sizeof(name1),stdin);

                        clock_t begin1 = clock();
                        struct Node  *lookUP = lookUP_hash_table1(TABLE1_SIZE,hash_table1,name1);
                        clock_t end1 = clock();
                        double time_spent1 = (double)(end1 - begin1)/ CLOCKS_PER_SEC;
                        printf("\n\nTime consumed by the search: %.50f\n", time_spent1);

                        if (lookUP == NULL) printf("\n\n\nNot Found\n");
                        else{
                            printf("\n\n\nFound\n");
                            printf("\t\t%s\n\t\t%d\n\t\t%d\n\t\t%d\n\t\t%d\n\t\t%d\n\n\n",lookUP->data.name, lookUP->data.id, lookUP->data.birthday[0], lookUP->data.birthday[1], lookUP->data.birthday[2], lookUP->data.score );
                        }
                        printf("-------------------------------------------------------------\n");
                        break;
                        case 3:;
                        char name2[50];
                        printf("\nThe name you want to delete: ");
                        fflush(stdin);
                        printf("\n");
                        scanf("%*c");
                        fgets(name2,sizeof(name2),stdin);

                        clock_t begin2 = clock();
                        delete_hash_table1(TABLE1_SIZE,hash_table1,name2);
                        clock_t end2 = clock();
                        double time_spent2 = (double)(end2 - begin2)/ CLOCKS_PER_SEC;
                        printf("\n\nTime consumed by the delete: %lf\n", time_spent2);
                        printf("-------------------------------------------------------------\n");
                        printf("the table after deletion:\n");
                        print_table(TABLE1_SIZE, hash_table1);
                        printf("-------------------------------------------------------------\n");

                        count1=count1-1;
                        printf("\nThe size of the table after insertion: %d\n ", sizeof(hash_table1)+ count1 * sizeof(struct Node));

                        break;
                    default: break;
                            }
                     printf("do you want to do any other modification (y or n)?");
                     char s='n';
                     scanf("%s",&s);
                     if (s!='y')break;
                     }
               }
            break;
            case 2:;
            printf("Enter the size of the hash table):\n");

            scanf ("%d", &N);

            for (int i=0;i<N;i++){
                stdptr[i]=NULL;
                }
            printf("do you want to use:\n1-linear probing\n2-quadratic probing \n ");
            int m;
            scanf (" %d", &m);
            printf("\nEnter the number of students you want to add to the table: ");
            int y;
            scanf (" %d", &y);
            int count2 =y;
            for (int i=0;i<y;i++){
                insertstd(N,stdptr,m);
                }
            printTable(N,stdptr);

            printf("-------------------------------------------------------------\n");
            printf("\nThe size of the struct: %d\n ", sizeof(struct student));
            printf("\nThe size of the table after insertion: %d\n ", N*8+ y*sizeof(struct student));

            printf("-------------------------------------------------------------\n");

            while(1){

                  printf("-------------------------------------------------------------\n");
                  printf("\nchoose :\n 1-to insert \n 2-to search \n 3-to delete \n 4-if you don't want to do any modifications \n");
                  int x;
                  scanf("%d",&x);
                  switch(x){
                      case 1:;
                            insertstd(N,stdptr,m);
                            printTable(N,stdptr);

                            count2 = count2 +1;
                            printf("-------------------------------------------------------------\n");
                            printf("\nThe size of the table: %d \n",  N*8+ count2 *sizeof(struct student));
                            printf("-------------------------------------------------------------\n");

                          break;
                      case 2:;
                            printf("Enter the birth date of the student you want to search for: \n");
                            int b[3];
                            printf("the day: ");
                            scanf("%d",&b[0]);
                            printf("\nthe month: ");
                            scanf("%d",&b[1]);
                            printf("\nthe year: ");
                            scanf("%d",&b[2]);

                            clock_t begin3 = clock();
                            searchstd(N,stdptr,b,m);
                            clock_t end3 = clock();
                            double time_spent3 = (double)(end3 - begin3)/ CLOCKS_PER_SEC;
                            printf("\n\nTime consumed by the search: %f\n", time_spent3);

                          break;
                      case 3:;
                            printf("Enter the birth date of the student you want to delete: \n");
                            int bd[3];
                            printf("the day: ");
                            scanf("%d",&bd[0]);
                            printf("\nthe month: ");
                            scanf("%d",&bd[1]);
                            printf("\nthe year: ");
                            scanf("%d",&bd[2]);

                            clock_t begin4 = clock();
                            deletestd(N,stdptr, bd,m);
                            clock_t end4 = clock();
                            double time_spent4 = (double)(end4 - begin4)/ CLOCKS_PER_SEC;
                            printf("\n\nTime consumed by the delete: %f\n", time_spent4);

                            printTable(N,stdptr);
                            count2 = count2 -1;
                            printf("-------------------------------------------------------------\n");
                            printf("\nThe size of the table: %d \n",  N*8+ count2*sizeof(struct student));
                            printf("-------------------------------------------------------------\n");
                          break;
                    default: break;
                    }
             printf("do you want to do any other modification (y or n)?");
             char s='n';
             scanf("%s",&s);
             if (s!='y')break;
             }
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
