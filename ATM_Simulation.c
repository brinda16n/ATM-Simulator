#include<stdio.h>
typedef struct account
{
int acc_no;
float balance;
int pin;
char name[50];
}account_t;
int count = 0;
void create_acc(account_t *s)
{
printf("Enter the account number : ");
scanf("%d",&(s+count)->acc_no);
printf("Enter the name of the customer : ");
scanf("%s",(s+count)->name);
printf("Enter the pin : ");
scanf("%d",&(s+count)->pin);
(s+count)->balance = 0;
count++;
printf("ACCOUNT CREATED SUCCESSFULLY\n");
}
void deposit_acc(account_t *s)
{
int a_no,flag = 0;
float amt;
int pin;
printf("Enter the account number : ");
scanf("%d",&a_no);
for(int i=0;i<count;i++)
{
if(a_no == (s+i)->acc_no)
{
printf("Enter the pin : ");
scanf("%d",&pin);
flag = 1;
if(pin == (s+i)->pin)
{
printf("Enter the amount to deposit : ");
scanf("%f",&amt);
(s+i)->balance+=amt;
printf("Your balance is Rs. %.3f\n",s[i].balance);
}
else
printf("INCORRECT PIN\n");
}
}
if(flag==0)
printf("ACCOUNT DOES NOT EXIST\n");
}
void withdraw_acc(account_t *s)
{
int a_no,flag = 0;
int pin;
float amt;
printf("Enter the account number : ");
scanf("%d",&a_no);
for(int i=0;i<count;i++)
{
if(a_no == (s+i)->acc_no)
{
printf("Enter the pin : ");
scanf("%d",&pin);
flag = 1;
if(pin == (s+i)->pin)
{
printf("Enter the amount to withdraw : ");
scanf("%f",&amt);
if((s+i)->balance-amt > 0)
{
(s+i)-> balance-=amt;
printf("You have withdrawn Rs. %.3f\n",amt);
printf("Your balance is Rs. %.3f\n",s[i].balance);
}
else
printf("INSUFFICIENT AMOUNT TO WITHDRAW\n");
}
else
printf("INCORRECT PIN\n");
}
if(flag==0)
printf("ACCOUNT DOES NOT EXIST\n");
}
}
void changePin(account_t *s)
{
int a_no,amt,flag = 0;
int pin;
printf("Enter the account number : ");
scanf("%d",&a_no);
for(int i=0;i<count;i++)
{
if(a_no == (s+i)->acc_no)
{
printf("Enter the current pin : ");
scanf("%d",&pin);
flag = 1;
if(pin == (s+i)->pin)
{
printf("Enter the new pin: ");
scanf("%d",&(s+i)->pin);
printf("PIN CHANGED SUCCESSFULLY\n");
}
else
printf("INCORRECT PIN\n");
}
}
if(flag==0)
printf("ACCOUNT DOES NOT EXIST\n");
}
void display(account_t *s)
{
printf("\n------------------------\n");
printf("NAME\tACC NO\tBALANCE\n");
for(int i=0;i<count;i++)
{
printf("%s\t%d\t%.3f\n",s[i].name,s[i].acc_no,s[i].balance);
}
}
int main()
{
account_t s[100];
int ch;
do
{
printf("------------------------\n");
printf("Enter 1 for account creation\n");
printf("Enter 2 to deposit\n");
printf("Enter 3 to withdraw\n");
printf("Enter 4 to change pin\n");
printf("Enter 5 to display records\n");
printf("Enter 6 to quit\n");
printf("------------------------\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: create_acc(s);
break;
case 2: deposit_acc(s);
break;
case 3: withdraw_acc(s);
break;
case 4: changePin(s);
break;
case 5: display(s);
break;
case 6: return 0;
}
}while(ch!=6);
return 0;
}
