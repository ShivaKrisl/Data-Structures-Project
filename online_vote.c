									//  Online Voting System
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int admin();
void voters();
void voter_register();
void voterlogin();
void voterslist();
void addcandidates();
void winnerslist();

struct Voters{
	char voter_id[50];
	char name[50];
	int age;
	int voted;
	struct Voters *next_voter;
	struct Voters *prev_voter;
};
struct Voters *head = NULL;

struct Candidates{
	char name[50];
	char party[50];
	int Votecounts;
	struct Candidates *next_candidate;
};
struct Candidates *start = NULL;

char EC_Name[50] = "EC@SRU";
char EC_Password[50] = "SRU@123";

void main()
{
	int ch;
	system("cls");
/*	printf("\n Hello Voter");
	printf("\n %s",EC_name);
	printf("\n %s",EC_Password);*/
	printf("\n\t\t\t\t*******************************\t\t");
	printf("\n\t\t\t\tWelcome to ONLINE VOTING SYSTEM\t\t");
	printf("\n\t\t\t\tPress 1. to Goto Admin Login panel");	
	printf("\n\t\t\t\tPress 2. to Goto Voter panel");
	printf("\n\t\t\t\tPress 3. to See Winners List");
	printf("\n\t\t\t\tPress 4. to EXIT");
	printf("\n\t\t\t\t*******************************\t\t");
	printf("\n\t\t\t\tPlease select an Option from above => ");
	while(1)
	{
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			admin();
			break;
		case 2:
			voters();
			break;
		case 3:
			winnerslist();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\n Invalid Choice Please select from above options");
			Sleep(1000);
			main();
			break;
			
	}	
	}
}

int admin()
{
	int a_ch;
	system("cls");
	Sleep(100);
	char id[50],password[50];
	printf("\n Enter User Id = ");
	scanf("%s",id);
	printf("\n Enter Password = ");
	scanf("%s",password);
	if(strcmp(id,EC_Name)==0 && strcmp(password,EC_Password)==0)
	{
		system("cls");
	    Sleep(100);
		printf("\n\t\t\t\tWelcome Officer");
		printf("\n\t\t\t\t*********************************");
		printf("\n\t\t\t\tPress 1. to See Voters List");
		printf("\n\t\t\t\tPress 2. to add Candidates");
		printf("\n\t\t\t\t*********************************");
		printf("\n\t\t\t\tPlease Select an Option =>");
		scanf("%d",&a_ch);
		switch(a_ch)
		{
			case 1:
				voterslist();
				break;
			case 2:
				addcandidates();
				break;
			case 3:
				exit(0);
				break;
		}
	}
	else
	{
		printf("\n Invalid ID or PASSWORD");
		Sleep(1000);
		main();
	}
	return 0;
}
void voters()
{
	int v_ch;
	system("cls");
	Sleep(100);
	printf("\n\t\t\t\tWELCOME TO VOTER'S PANEL");
	printf("\n\t\t\t\t*********************************");
	printf("\n\t\t\t\tNEW USER Press 1. to Register");
	printf("\n\t\t\t\tALREADY REGISTERED Press 2. to Login");
	printf("\n\t\t\t\tPress 3. to Go Back");
//	printf("\n\t\t\t\tPress 4. to Goto Voting Page");
	printf("\n\t\t\t\t*********************************");
	printf("\n\t\t\t\tPlease Select an Option =>");
	scanf("%d",&v_ch);
	switch(v_ch)
	{
		case 1:
			voter_register();
			break;
		case 2:
			voterlogin();
			break;
		case 3:
			main();
			break;
		default:
			printf("\n Invalid Option Choosen");
			break;
	}
}

void voter_register()
{
	struct Voters *newvoter, *temp,*ptr;
	char Voter_ID[50];
	char name[50];
	int age,voted=0;
	system("cls");
	printf("\n\t\t\t\tWELCOME TO REGISTRATION PAGE");
	printf("\n\t\t\t\t*********************************");
	newvoter = (struct Voters *)malloc(sizeof(struct Voters));
	printf("\n Enter Your Name =>");
	scanf("%s",name);
	printf("\n Enter Your Age =>");
	scanf("%d",&age);
	if(age<18)
	{
	printf("\n Sorry You are not eligible to vote as Your Age is less than 18");
    }
	else
	{
		printf("\n Enter Your Voter ID =>");
	    scanf("%s",Voter_ID);	
	    strcpy(newvoter->name,name);
	    newvoter->age = age;
	    strcpy(newvoter->voter_id,Voter_ID);
	    newvoter->voted = 0;
	    newvoter->next_voter = newvoter;
	    newvoter->prev_voter = newvoter;
	    if(head == NULL)
	    {
	    	head = newvoter;
	    	printf("\n Registered Successfully.....");
		}
	    else
	    {
	    	temp = head;
	    	do
	    	{
	    		ptr = head;
	    		do
	    		{
	    			if(strcmp(head->voter_id,newvoter->voter_id)==0||strcmp(ptr->voter_id,newvoter->voter_id)==0)
	    			{
	    			printf("\n Voter Is already Registered......\n Please Move to Login page");
	    			printf("\n Press any key to Continue....");
	    			getch();
	    			voters();
					}
					else
					ptr = ptr->next_voter;
				}while(ptr->next_voter!=head);
	    		temp = temp->next_voter;
			}while(temp->next_voter!=head);
		 
			temp->next_voter = newvoter;
			newvoter->prev_voter = temp;
			head->prev_voter = newvoter;
			newvoter->next_voter = head;
            printf("\n Registered Successfully.....");
		}
	}
	printf("\n Press any Key to Continue");
	getch();
	main();
}

void voterslist()
{
	struct Voters *temp;
	system("cls");
	if(head == NULL)
	{
		printf("\n Voters List is Empty");
		//printf("\n Press any key to continue....");
		//getch();
		//admin();
	}
	else
	{
		temp = head;
		printf("\n\t\t\t\t***************VOTERS LIST******************");
		printf("\n\t\t\t\t====================================================================================");
		printf("\n\t\t\t\t|NAME\t\t\t|AGE\t\t\t|VOTERID\t\t|WHETHERVOTED\n");
		printf("\t\t\t\t______________________________________________________________________________________\n");
		do
		{
			printf("\t\t\t\t%s",temp->name);
			printf("\t\t\t%d",temp->age);
			printf("\t\t\t%s",temp->voter_id);
			printf("\t\t\t\t%d\t\t\t\t\t",temp->voted);
			printf("\n");
			temp = temp->next_voter;
		}while(temp!=head);
		printf("\n\t\t\t\t======================================================================================");
	}
	printf("\n\n Press any Key to Continue.......");
	getch();
	main();
}

void voterlogin()
{
	struct Voters *temp;
	struct Candidates *disp;
	int count=0,i,vch;
	char Voterid[50];
	system("cls");
	printf("\n Enter your Voter ID =>");
	scanf("%s",Voterid);
	if(head == NULL)
	printf("\n Invalid VoterID");
	else
	{
		temp = head;
		system("cls");
		do
		{
			if(strcmp(Voterid,temp->voter_id)==0)
			{
				printf("\n\t\t\t\t********************************************");
				printf("\n\t\t\t\tLogin Successful Welcome %s",temp->name);
				Sleep(1000);
				if(start == NULL)
				{
					printf("\n Currently there are no candidates...\n Please Come back after canidates are added");
					Sleep(3000);
					main();
				}
				else
				{
				disp = start;
				printf("\n\n\t\t\t\t****************CANDIDATES ARE*******************");
				printf("\n\t\t\t\t==========================================================================");
				printf("\n\t\t\t\tNAME\t\t\t\tPARTY\t\t\t\tVOTECOUNTS\n");
				printf("\t\t\t\t==========================================================================\n");
	            while(disp!=NULL)
				{
				 count++;
				 printf("\t\t\t\t%s",disp->name);
				 printf("\t\t\t\t%s",disp->party);
				 printf("\t\t\t\t%d",disp->Votecounts);
				 printf("\n");
				 disp = disp->next_candidate;
			    }
			    printf("\t\t\t\t==========================================================================\n");
				disp = start;
				for(i=1;i<=count&&disp!=NULL;i++)
				{
				printf("\n Press %d to Vote for %s\n",i,disp->name);
				disp  = disp->next_candidate;
				}
		
				printf("\n Please Enter your Choice =>");
				scanf("%d",&vch);
				disp = start;
				for(i=1;i<=count&&disp!=NULL;i++)
					{
					  if(vch == i)
			  		  {
			  		  	if(temp->voted == 0)
			  		  	{
			  		  		disp->Votecounts++;
			  		  		temp->voted = 1;
			  		  		printf("\n Your Vote has been Successfully Casted for %s party",disp->party);
						}
						else
						{
						   printf("\n You have been already Voted. You Cannot vote for twice....");
						}
				      }
				      disp = disp->next_candidate;
			        }
				printf("\n Press Any key to Go Back.... ");
				getch();
				main();
	           }
				
		    }
			else
			{
				temp = temp->next_voter;
			}
		}while(temp!=head);
	}
	printf("\n Press any Key to go back...");
	getch();
	main();
}





void addcandidates()
{
	struct Candidates *cads,*temp,*ptr;
	char C_name[50],C_party[50];
	system("cls");
	printf("\n\t\t\t\t**************************************");
	printf("\n\t\t\t\t Welcome %s You can add Candidates Here",EC_Name);
	cads = (struct Candidates *)malloc(sizeof(struct Candidates));
	printf("\n Enter Candidate Name =>");
	scanf("%s",C_name);
	printf("\n Enter Candidates Party =>");
	scanf("%s",C_party);
	strcpy(cads->name,C_name);
	strcpy(cads->party,C_party);
	cads->Votecounts = 0;
	cads->next_candidate = NULL;
	if(start == NULL)
	{
		start = cads;
	}
	else
	{
		temp = start;
  while(temp->next_candidate!=NULL)
	    	{
	    		ptr = start;
	    		do
	    		{
	    			if(strcmp(ptr->party,cads->party)==0||strcmp(start->party,cads->party)==0)
	    			{
	    			printf("\n Only One Candidate from %s Party is Allowed..",ptr->party);
	    			printf("\n Press any Key to Continue...");
	    			getch();
	    			main();
					}
					else
					ptr = ptr->next_candidate;
				}while(ptr->next_candidate!=NULL);	
			temp = temp->next_candidate;	
			}
			temp->next_candidate = cads;
	}
	printf("\n Candidate Has been Added Successfully......");
	printf("\n Press any Key to Continue...");
	getch();
	main();
}

void winnerslist()
{
	struct Candidates *list,*win;
	int max=0;
	system("cls");
	if(start == NULL)
	printf("\n There are no candidates. Candidates are Yet to be Added...");
	else
	{
		list = start;
		win = list;
		max = list->Votecounts;
		printf("\n\n\t\t\t\t****************CANDIDATES ARE*******************");
		printf("\n\t\t\t\t==========================================================================");
		printf("\n\t\t\t\tNAME\t\t\t\tPARTY\t\t\t\tVOTECOUNTS\n");
		printf("\t\t\t\t==========================================================================\n");
		while(list!=NULL)
		{
			printf("\t\t\t\t%s",list->name);
			printf("\t\t\t\t%s",list->party);
			printf("\t\t\t\t%d",list->Votecounts);
			if(max<=list->Votecounts)
			{
				max = list->Votecounts;
				win = list;
			}
			else
			{
				max = max;
			}
			printf("\n");
			list = list->next_candidate;
		}
		printf("\t\t\t\t==========================================================================\n");
		printf("\n\n Currently The Winner is = %s from %s party  with %d votes",win->name,win->party,max);
	}
	Sleep(1000);
	printf("\n\n Enter any Key to Continue...");
	getch();
	main();
}
