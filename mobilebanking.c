 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct user{
char phone[50];
char ac[50];
char password[50];
float balance;
};

int main(){
struct user usr,usr1;
FILE *fp;
char filename[50],phone[50],pword[50];
int opt,choice;
char cont='y';
float amount;

printf("\n What do you want to do?");
printf("\n\n 1. Register an account");
printf("\n 2. Login to an account");

printf("\n\n Your choice: \t");
scanf("%d",&opt);

if(opt==1){
    system("cls");
    printf("Enter your account numner: \t");
    scanf("%s",&usr.ac);
    printf("Enter your phone number: \t");
    scanf("%s",&usr.phone);
    printf("Enter your new password: \t");
    scanf("%s",&usr.password);
    usr.balance=0;
    strcpy (filename,usr.phone);
    fp=fopen(strcat(filename,".dat"),"w");
    fwrite(&usr,sizeof(struct user),1,fp);
    if(fwrite!=0){
        printf("\n\n Account successfully registered");

    }else{
    printf("\n\n Something went wrong, Please try again");
    }
fclose(fp);
}
if(opt==2){
    system("cls");
    printf("\n Phone Number: \t");
    scanf("%s",&phone);
    printf("Password: \t");
    scanf("%s",&pword);
    strcpy(filename,phone);
    fp=fopen(strcat(filename,".dat"),"r");
    if(fp==NULL){
        printf("\n Account number not registered");
    }else{

    fread(&usr,sizeof(struct user),1,fp);
    fclose(fp);
    if(!strcmp(pword,usr.password)){
            printf("\n\t Welcome %s",usr.phone);
         while(cont=='y'){
            //system("clear");
            printf("\n\n Press 1 for Balance Inquiry");
            printf("\n Press 2 for Cash Deposite");
            printf("\n press 3 to Cash Witndrawl");
            printf("\n press 4 for Online Transfer");
            printf("\n press 5 for Password Change");
            printf("\n\n Your choice: ");
            scanf("%d",&choice);
            switch(choice){
            case 1:
            printf("\n Your current balance is Rs%.2f",usr.balance);
            break;
            case 2:
                printf("\nEnter your amount: \t");
    scanf("%f",&amount);
            usr.balance+=amount;
            fp=fopen(filename,"w");
            fwrite(&usr,sizeof(struct user),1,fp);
            if(fwrite!=NULL){
                printf("\nSuccessfully Deposited");
            }
            fclose(fp);
            break;
            case 3:
printf("\nEnter your amount: \t");
    scanf("%f",&amount);
            usr.balance-=amount;
            fp=fopen(filename,"w");
            fwrite(&usr,sizeof(struct user),1,fp);
            if(fwrite!=NULL){
                printf("\n You have withdrawl Rs%.2f",amount);
            }
            fclose(fp);
            break;
        case 4:
                printf("\n Enter the phone number to transfer the balance: \t");
                scanf("%s",phone);
                printf("Enter amount to transfer: ");
                scanf("%f",&amount);
                strcpy(filename,phone);
                 fp=fopen(strcat(filename,".dat"),"r");
                 if(fp==NULL){
                    printf("\n Account number not registered");
                 }else{

                fread(&usr1,sizeof(struct user),1,fp);
                fclose(fp);

                if(amount>usr.balance){
                    printf("\n Insufficient balance");
                }else{


                fp=fopen(filename,"w");
                usr1.balance+=amount;
                fwrite(&usr1,sizeof(struct user),1,fp);
                fclose(fp);
                if(fwrite!= NULL){
                    printf("\n You have successfully transferred Rs%.2f to %s",amount,phone);
                    strcpy(filename,usr.phone);
                    fp=fopen(strcat(filename,".dat"),"w");
                    usr.balance-=amount;
                     fwrite(&usr,sizeof(struct user),1,fp);
                     fclose(fp);
                }

                }
break;
        case 5:
            printf("\nPlease enter your new password: \t");
            scanf("%s",&pword);
            fp=fopen(filename,"w");
            strcpy(usr.password,pword);
            fwrite(&usr,sizeof(struct user),1,fp);
            if(fwrite!=NULL)

            printf("\n Password changed successfully");

            }
            break;
        default:
            printf("\n Invalid Option");


            }

            printf("\n Do you want to continue the transaction? [Y/N]:  ");
            scanf("%s",&cont);;
         }

    }else{
    printf("\n Invalid Password");
    }
    }

}




return 0;
}
