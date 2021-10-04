#include <stdio.h>
void main (){
//taking insformation of employee

    char user[30], pass[20], name1[30], name2[30], post1[20], post2[20];
    int id1, id2, salary1, salary2, monthlysalary1, monthlysalary2;
    printf("\nUsername: ");
    scanf("%s", &user);
    printf("\nPassword: ");
    scanf("%s", &pass);
    printf("Enter the information for Department 1\n\n");
    printf("Name: ");
    scanf("%s", name1);
    printf("Id: ");
    fflush(stdin);
    scanf("%d",&id1);
    printf("Post: ");
    fflush(stdin);
    scanf("%s", post1);
    printf("Yearly Salary: ");
    fflush(stdin);
    scanf("%d",&salary1);
    printf("Enter the information for Department 2\n\n");
    printf("Name: ");
    fflush(stdin);
    scanf("%s", name2);
    printf("Id: ");
    fflush(stdin);
    scanf("%d",&id2);
    printf("Post: ");
    fflush(stdin);
    scanf("%s", post2);
    printf("Yearly Salary: ");
    fflush(stdin);
    scanf("%d",&salary2);

    int c;
    printf("Select department\n");
    printf("1. Department 1\n");
    printf("2. Department 2\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
// here is taking condition for define which department information want to show
    if(c==1){
//showing employee information of department 1
        printf("Employee is %s\n", name1);
        printf("\nEmployee ID: %d\n", id1);
        printf("Post: %s\n", post1);
        printf("Yearly Salary: %d\n", salary1);
        printf("Salary have been taken by you: ");
        fflush(stdin);
        scanf("%d", &monthlysalary1);
        printf("Salary that you will get in this year: %d", salary1-monthlysalary1);
    }
    else if(c==2){
//showing employe information of department 2

        printf("Employee is %s\n", name2);
        printf("\nEmployee ID: %d\n", id2);
        printf("Enter your post: %s\n", post2);
        printf("Yearly Salary: %d\n", salary2);
        printf("Salary have been taken by you: ");
        fflush(stdin);
        scanf("%d", &monthlysalary2);
        printf("Salary that you will get in this year: %d", salary2-monthlysalary2);
    }
    else{
        printf("Wrong option. Department not found.\n");
    }
}

