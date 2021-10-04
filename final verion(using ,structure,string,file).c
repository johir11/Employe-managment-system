#include<conio.h>
#include <stdio.h>
#include<string.h>
//taking file for storing employe data
FILE *employeeLIst;
char username[20]="Atifxxxx", password[20]="123ABCabc";
struct employee{
    char n[20], post[10];
    int x, salary;    		//here is global variable x is for id and n is for name 
}e;
dep1()
{
    int id, temp=0;
    printf("Enter id: ");
    scanf("%d", &id);
    while(fread(&e, sizeof(e), 1, employeeLIst)==1){
        if(id==e.x){
            temp++;
            printf("Employee is %s\n", e.n);
            printf("\nEmployee ID: %d\n", e.x);
            printf("Enter your post: %s\n", e.post);
            printf("Enter salary: %d\n", e.salary);
        }
    }
    if(temp==0) printf("employee not found\n");
}
dep2()
{
    int id, temp=0;
    printf("Enter id: ");
    scanf("%d", &id);
    while(fread(&e, sizeof(e), 1, employeeLIst)==1){
        if(id==e.x){
            temp++;
            printf("Employee is %s\n", e.n);
            printf("\nEmployee ID: %d\n", e.x);
            printf("Enter your post: %s\n", e.post);
            printf("Enter salary: %d\n", e.salary);
        }
    }
    if(temp==0) printf("employee not found\n");
}
void main(){
//here is taking information and codition where to go user or admin
    printf("1. User\n");
    printf("2. Admin\n");
    int x;
    printf("Enter your choice: ");
    scanf("%d", &x);
    if(x==1) choice_list();
    else if(x==2) admin();
    else {
        printf("Wrong option. Choice the correct one\n");
        main();
    }
}
void admin()
{
//taking  infromation for emlpoye records  
    char user[20], pass[20];
    printf("Log in your account\n");
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", &pass);
//checking condition for user name account wheater account is correct or wrong if correct he can see information

    if(strcmp(user, username)==0 && strcmp(pass, password)==0){
        printf("1. Add Employee Record\n");
        printf("2. See All Employee Record\n");
        printf("3. Exit\n");
        int choice;
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        if(choice==1){

//here is opening a file for storing  employee records and insert data 

            employeeLIst=fopen("Information of employee.bin", "wb+");
            printf("How many record do you want to add?\n");
            int i, count;
            scanf("%d", &choice);
            for(i=1; i<=count; i++)
            {
                printf("\nEmployee Name: ");
                scanf("%s", &e.n);
                printf("\nEmployee ID: ");
                fflush(stdin);
                scanf("%d", &e.x);
                printf("Information for %s\n", e.n);
                printf("Enter post: ");
                fflush(stdin);
                scanf("%s", &e.post);
                printf("Enter salary: ");
                fflush(stdin);
                scanf("%d", &e.salary);
                fwrite(&e, sizeof(e), 1, employeeLIst);
                fclose(employeeLIst);
                printf("Do you want to continue? 'y'/'n'\n");
                char a;
                fflush(stdin);
                scanf("%c", &a);
                if(a=='y'){
                    continue;
                }
                else if(a=='n'){
                    main();
                }
            }
        }
        if(choice==2){
            printf("How Many Record Do You Want to Cheek?\n");
            int q, temp=0; ///q for quantity of record to cheek
            scanf("%d", &q);
            employeeLIst=fopen("Information of employee.bin", "rb+");
            printf("List of First %d Record Is Given Below\n\n\n", q);
            while(fread(&e, sizeof(e), 1, employeeLIst)==1){
                temp++;
                printf("Employee is %s\n", e.n);
                printf("\nEmployee ID: %d\n", e.x);
                printf("nEmployee post: %s\n", e.post);
                printf("nEmployee salary: %d\n", e.salary);
                printf("\n\n");
                if(temp==q) break;
                else continue;
            }
        }
        if(choice==3){
            exit(0);
        }
    }
    else printf("Wrong Username or Password\n");

}

void choice_list ()
{

//here is taking choice if user have a account thn log in and can see information or can sign up
  int x;
  printf ("\n\n\t1. Sign up you here!!!");
  printf ("\n\n\t2. Log in your account!!!");
  printf ("\n\n\tYour Choice Please: ");

  scanf ("%d", &x);

  switch (x)
    {
    case 1:
      sign_up();
      break;
    case 2:
      log_in ();
      break;

    default:
      main ();

    }

}
//here is taking file for storing information

FILE *information; ///member information
//here is taking structure for signup
struct info{
    char username[30], password[20];
};
struct info i;
sign_up()
{
    information=fopen("data.bin", "ab+");
    printf(" Fill all the information below\n");
    char test[30], test2[20], retypepassword[20];
    int temp=0;
    printf("\nUsername: ");
    scanf("%s", test);
    while(fread(&i.username, sizeof(i.username), 1, information)==1)
    {
        if(test==i.username) {
                printf("Username taken\n");
                sign_up();
                temp++;
        }
    }
    if(temp==0) strcpy(i.username, test);
    printf("\nPassword: ");
    scanf("%s", &test2);
    printf("\nRe-type Password: ");
    scanf("%s", &retypepassword);
    if(strcmp(test2, retypepassword)==0) {
        strcpy(i.password, retypepassword);
        fwrite(&i, sizeof(i), 1, information);
        fclose(information);
        welcome(test);
    }
    else {
        printf("Password does not match\n");
  printf ("\n\n\t\t\t\t1. Sign up you here!!!");
        sign_up();
    }
}
log_in()
{
//here is opening data for read username and pass 
    information=fopen("data.txt", "rb+");
    char user[30], pass[20];
    int temp=0;
    printf("\nUsername: ");
    scanf("%s", &user);
    printf("\nPassword: ");
    scanf("%s", &pass);
    while(fread(&i, sizeof(i), 1, information)==1) {
        if(strcmp(user,i.username)==0 && strcmp(pass, i.password)==0) {
                temp++;
                fclose(information);
                welcome(user);
        }
    }
    if(temp==0) {
        printf("Invalid try\n");
        log_in();
    }
}
welcome()
{
//here is showing option for department which you want to select

    int c;
printf("Select department\n");
printf("Department 1\n");
printf("Department 2\n");
printf("Enter your choice: ");
scanf("%d", &c);
if(c==1){
    dep1();
}
else if(c==2){
    dep2();
}
else{
    printf("Wrong option. choice the correct one.\n");
    welcome();
}
}
