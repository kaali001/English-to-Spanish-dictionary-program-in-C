
//program to add, search and find meaning of a word in a dictionary
/*
// English to Spanish dictionary
The menu contains
   a)to add data
   b)to search data
   c)to read and display data
   d)to update existing record
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>//for string handling functions
#include<stdlib.h>//for exit() function
#include<windows.h>//for sleep() function
void welcome_menu();            //welcome module
void main_menu();              //displays main menu
void add_record();            //function to add records
void search_record();          //function to search record
void search_menu();             //search module
void search_by_name();          //search by name module
void display_record();         //function to display records
void timesleep();              //time delay function
void update_record();
struct detail
{
char wname[100];
char wmeaning[100];
             //members
}var;
/* main function */
void main()
{
    system("cls");
     main_menu();                  //call of main menu
    getch();
}
/* main menu module*/
void main_menu()
{
     char choice;
     welcome_menu();
     printf("\n-------------------------------------------------------------\n");
     printf("*************  ENGLISH to SPANISH Dictionary  ******************\n");
     printf("enter your choice for following operations......\n");

      printf("-----------------------------------------------------------\n");
      printf("|[1] to store data;                                      |\n");
      printf("|[2] to search data                                      |\n");
      printf("|[3] to display records                                  |\n");
      printf("|[4] to update /modify the record                        |\n");
      printf("---------------------------------------------------------|\n");
      printf("\nenter your choice : ");
     scanf("%d",&choice);            //gets a character as choice
 switch(choice)
 {
  case 1:
	   system("cls");
	   printf("\nwe are going to add/store data\n");
	   add_record();         //call of function if the condition is true
	   break;
  case 2:
	   system("cls");
	   printf("we are going to search data\n");
	   search_menu();      //call of function if the condition is true
	   break;
  case 3:
	   system("cls");
	   printf("we are going to display records\n");
	   display_record();         //call of function to print the records
	   break;
  case 4:
	   system("cls");
	   printf("we are going to modify records\n");
	   update_record();         //call of function to print the records
	   break;
  default:
	   system("cls");
	   printf("sorry, this choice is not available.\n");

	   printf("so terminating the program ....\n");

	   printf("thank u for using this program..\n");

	   Sleep(2000);             //sleeps the exit of execution for 2 secs.
	   exit (0);                 //exits the process. It exits in stdlib.h

 }
 }
 /*self typing welcome message*/
 void welcome_menu()
 {
     char welcome[100]="Dictionary Management program";
     int i;
     printf("welcome to ");
     for(i=0;welcome[i]!='\0';i++)
     {
     printf("%c",welcome[i]);//printing character with 100/1000 second.
     Sleep(100);             //delay time
     }
 }
 /* add data/word module*/
 void add_record()
 {
     system("cls");
     printf("----------------------------------------------------------------\n");
     char ch='y';
     FILE *p;
     p=fopen("dict.txt","a"); //file opened in apend mode
 while(ch!='n') //testing of condition
 {

      printf("\n");
      fflush(stdin);//flushes the input buffer
               //data input
      printf("enter word\n");
      gets(var.wname);
      fflush(stdin);
      printf("enter its meaning\n");
      gets(var.wmeaning);
      fflush(stdin);//flushes the buffer
      
      fwrite(&var,sizeof(var),1,p);//writes data
       system("cls");

      printf("you want to continue?\n");
      system("cls");

      printf("press y/Y to continue and 'n'  to discontinue..\n");

      ch=getch();                   //gets a character to continue the process
      fflush(stdin);                //flushes the buffer
      system("cls");
  }

     fclose(p);                     //closes the file
    printf("press enter to goto main menu\n");
    getch();
    fflush(stdin);
    Sleep(1000);                 //sleeps for 1 secs
    system("cls");
    main_menu();                //calling of main menu with some delay
 }
 /*data display module*/
 void display_record()
 {
    system("cls");
    FILE *p;
    p=fopen("dict.txt","r");  // opening of file in read mode
    int i=0;
    printf("English word\t\t\tSpanish Meaning\n\n");
 while((fread(&var,sizeof(var),1,p))==1)
 {                           //reading of record till the last reaches.
	  i++;
      
	  printf("%s",var.wname);
	  printf("\t\t\t\t%s\n",var.wmeaning);

 }
    fclose(p);                   //closes the file

    printf("\npress enter to goto main menu\n");
    getch();
    fflush(stdin);
    Sleep(1000);                 //sleeps for 1 secs
    system("cls");
    main_menu();                 //calls the main menu
 }
 /*search module starts here*/
void search_menu()
{
    char choice;
               //prints the menu
     printf(" search by word ........................\n");

     printf("|--------------------------------------------------------------  |\n");
     printf("|'n' or 'N' to search by name;                                   |\n");

     printf("|----------------------------------------------------------------|\n");

     choice=getch();            //gets a character
     fflush(stdin);             //flushes the buffer
     switch(choice)
    {
        case 'n':
        case 'N':
           system("cls");
           printf("\nwe are going to search by name\n");
           search_by_name();         //call of function if the condition is true
           break;
       
        default:
           system("cls");

           printf("sorry, this choice is not available.\n");

           printf("so terminating the searching........\n");
        }
     printf("press enter to return to main menu  \n");
     getch();			  //sleeps the exit of execution for 3 secs.
     system("cls");
     timesleep();
 }
 /*search by name module*/
 void search_by_name()         //data search function
 {
     char word_search[100],ch;    //variable for name and
    system("cls");
     FILE *p;
     int flag=0;
     system("cls");
     p=fopen("dict.txt","r");   //opening of file in read mode

     printf("we can search record here only using word\n");

     printf("enter word to be searched\n");
     fflush(stdin);//flushes the input buffer
     gets(word_search);
                //input of data to be searched
     system("cls");

     printf("data are\n");
     fflush(stdin);
     printf("----------------------------------------------------------------\n");

 while((fread(&var,sizeof(var),1,p))==1)
    {                            //reading till the last record
        if((strcmp(word_search,var.wname)==0))
            {                          //data testing
                flag=1;
                break;              //breaks the searching process
            }
    }
 if(flag==1)
 {
     printf("word=%s, meaning=%s\n",var.wname,var.wmeaning);//printing of data
     printf("--------------------------------------------------------\n");
 }
 else //if(flag==0)
 {
   system("cls");
   printf("sorry, no data found!!!!\n");//printing no data found
 }
 fclose(p);


    printf("press any key  to load main menu\n");
    getch();
    fflush(stdin);
    Sleep(1000);
    search_menu();                           //sleep of 1 secs before search  menu
 }
 
 
 void update_record()
 {
 	system("cls");
    FILE *p,*p1;
    char word_update[100];
    p=fopen("dict.txt","r");  // opening of file in read mode
    p1=fopen("updateddata.txt","a");
    printf("enter word to update\n");
    fflush(stdin);
    gets(word_update);
    
 while((fread(&var,sizeof(var),1,p))==1)
 {                           //reading of record till the last reaches.
	  if((strcmp(var.wname,word_update))==0)
	 {
	 
	  printf("word   =%20s\n",var.wname);
	  printf("meaning=%20s\n",var.wmeaning);
	  
      printf("-------------------------------------------------------------------------\n");
      printf("Enter new informations about %s word\n",word_update);
      printf("enter word\n");
      gets(var.wname);
      printf("enter its meaning\n");
      gets(var.wmeaning);
      
      fwrite(&var,sizeof(var),1,p1);//writes data
  }
  else
  {
  	fwrite(&var,sizeof(var),1,p1);//writes data

  }

 }
    fclose(p);                   //closes the file
	fclose(p1);
	remove("dict.txt");
	rename("updateddata.txt","dict.txt");
	printf("data updated successfully\n");
    printf("press enter to goto main menu\n");
    getch();
    fflush(stdin);
    Sleep(1000);                 //sleeps for 1 secs
    system("cls");
    main_menu();                 //calls the main menu
 }
 
 /*-------------------------*/
 /* time delay module starts here*/
 void timesleep()
 {
     system("cls");
     printf("loading main menu....\n");
     Sleep(1000);
     system("cls");
     fflush(stdin);//flushes input buffer(if any)
     main_menu();//loads main menu
 }
