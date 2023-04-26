//starter
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define null 0
int size=0;
void insert();void del();int search(char lab[]); void modify();void display();
struct symbtab{
	char label[10];
	int addr;
	char ltype[20];
	struct symtab *next;
};

struct symbtab *first,*last;

void main(){
     int op;
     int y;
     char la[10];
     do{
          printf("\nSYMBOL TABLE IMPLEMENTATION\n");
          printf("\t1.INSERT\n");
          printf("\t2.DISPLAY\n");
          printf("\t3.MODIFY\n");
          printf("\t4. SEARCH");
          printf("\nYour input--> ");
          scanf("%d",&op);
          switch(op){
               case 1:
                    insert();
                    display();
                    break;
               case 2:
                    display();
                   
                    break;
               case 3:
                    modify();
                    // display();
               default:
                    printf("Invalid input!");
          }
          
     }
     while(op<2);
}

//functions
bool isValidDelimeter(char ch){
    if(ch==' '||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch==','||ch==';'||ch=='>'||ch=='<'||ch=='('||
    ch==')'||ch=='['||ch==']'||ch=='{'||ch=='}')
    return(true);
    return(false);
}
bool isvalidIdentifer(char* l){
    if(l[0]=='0'|| l[0]=='1'||l[0]=='2'||l[0]=='3'||l[0]=='4'||l[0]=='5'||l[0]=='6'||l[0]=='7'||
    l[0]=='8'||l[0]=='9')
    return (false);
    return(true);
}
bool isValidOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='>'||ch=='<'||ch=='='){
        return(true);
    }
    return(false);
}
int search(char lab[]){
     int i,flag=0;
     struct symbtab *p;
     p=first;
     for(i=0;i<size;i++){
     	if(strcmp(p->label,lab)==0){
     		flag=1;
     	}
     return flag;
}
}

void insert(){
	int n;
	char l[10]="x=a+b";
    
	printf("Enter the label: ");
	scanf("%s",l);

    
	
    // int left=0,right=0;
    // int length=strlen(l);
    // while(right<=length && left<=right)
    // {
    //     if(isValidDelimeter(l[right])==false){
    //         right++;
    //     }
    //     if(isValidDelimeter(l[right])==true){
    //         if(isValidOperator(l[right]==true)){
    //             printf("Enter that it is an operator");
    //             printf("Enter the type:");
    //             struct symbtab *p;
	//             p=malloc(sizeof(struct symbtab));
    //             scanf("%s",&p->ltype);
    //             right++;
    //             left=right;
    //         }
    //     }
    //     return;
    // }
	n=search(l);
	if(n==1){

	printf("The label already exists");
	}
else{
	struct symbtab *p;
	p=malloc(sizeof(struct symbtab));
	strcpy(p->label,l);
    // printf("Enter the address: ");
	// scanf("%d",&p->addr);
    
    p->addr=rand();
    
     printf("\nNOTE: If label is '+','/','*','-' then enter Operator \n If '&','=',';' then special symbol \nelse Identifier");
     printf("\nEnter the type: ");
    // *p->ltype="operator";
    scanf("%s",p->ltype);
     
     
     //identifer,operator,constant , special character


     // char listype[10]="operator";
     // if(l=="+"||"/"||"*"||"-"){
     //      p->ltype=listype;
     // }
     // else{
     //      p->ltype="identifier";
     // }
	p->next=null;
	if(size==0){
		first=p;
		last=p;
	}
	else{
	last->next=p;
	last=p;
}	
size++;
}
}

void display(){
    int i;
    struct symbtab *p;
    p=first;
    printf("\nLabel\tAddress\tType\n");
    for(int i=0;i<size;i++){
         printf("%s\t%d\t%s\n",p->label,p->addr,p->ltype);
         p=p->next;
    }
     //search(p);
}

void modify(){
     char l[10],newl[10];
    int add,choice,i,s;
    struct symbtab *p;
    p=first;
    printf("Enter what you wish to modify? \n");
    printf("Enter 1. Only SYMBOL\n");
    printf("Enter 2 for address of a particular label\n");
    printf("Enter 3 Both Symbol + Address");
    printf("Enter youe choice below: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Enter the old symbol\n");
            scanf("%s",l);
            printf("Enter the new symbol: ");
            scanf("%s",newl);
            s=search(l);
            if(s==0){printf("No such label");}
            else{
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->label,l)==0){
                        strcpy(p->label,newl);
                    }
                    p=p->next;
                }
            }
            break;
        case 2:
        printf("Enter the symbol whose address is to be modified\n");
        scanf("%s",l);
        printf("Enter the new address:");
        scanf("%d",&add);
        s=search(l);
        if(s==0){
            printf("No such symbol");
        }
        else{
            for(i=0;i<size;i++){
                if(strcmp(p->label,l)==0){
                    p->addr=add;
                }
                p=p->next;
            }
        }
        break;
        case 3:
            printf("Enter the old symbol");
            scanf("%s",l);
            s=search(l);
            printf("Enter the new label: ");
            scanf("%s",newl);
            printf("Enter the new address: ");
            scanf("%d",&add);
            
            printf("%d",s);
            if(s==0){printf("No such symbol found in our table");}

            else{
                for(i=0;i<size;i++){
                    if(strcmp(p->label,l)==0){
                        strcpy(p->label,newl);
                        p->addr=add;
                    }
                    p=p->next;
                }
            }
            break;
        default:
            printf("You entered an invalid symbol");
    }

}

