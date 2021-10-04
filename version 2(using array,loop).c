#include<stdio.h>
void main(){

char user[30];
int pass;
char name[30], post[20];
int id[10] ,salary[10], monthlysalary1, monthlysalary2, i;
printf(" give the username \n");
scanf("%s",user);
printf("enter the user pass \n");
fflush(stdin);
scanf("%d",&pass);
for(i=0; i<2; i++){
    printf("Name for department %d: ", i+1);
    fflush(stdin);
    scanf("%s", &name[i]);
}
for(i=0;i<2;i++){
    printf("Id of %s is: ", name[i]);
    fflush(stdin);
    scanf("%s", &id[i]);
}
for(i=0;i<2;i++){
    printf("Post of %s is: ", name[i]);
    fflush(stdin);
    scanf("%s",&post[i]);
}
for(i=0;i<2;i++){
    printf("Salary of %s is: ", name[i]);
    fflush(stdin);
    scanf("%d",&salary[i]);
}
int c;
    printf("Select department\n");
    printf("1. Department 1\n");
    printf("2. Department 2\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    if(c==1){
        printf("Employee is %s\n", name[0]);
        printf("\nEmployee ID: %d\n", id[0]);
        printf("Post: %s\n", post[0]);
        printf("Yearly Salary: %d\n", salary[0]);
        printf("Salary have been taken by you: ");
        fflush(stdin);
        scanf("%d", &monthlysalary1);
        printf("Salary that you will get in this year: %d", salary[0]-monthlysalary1);
    }
    else if(c==2){
        printf("Employee is %s\n", name[1]);
        printf("\nEmployee ID: %d\n", id[1]);
        printf("Enter your post: %s\n", post[1]);
        printf("Yearly Salary: %d\n", salary[1]);
        printf("Salary have been taken by you: ");
        fflush(stdin);
        scanf("%d", &monthlysalary2);
        printf("Salary that you will get in this year: %d", salary[1]-monthlysalary2);
    }
    else{
        printf("Wrong option. Department not found.\n");
    }



}
