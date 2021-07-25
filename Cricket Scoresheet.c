#include<stdio.h>
#include<malloc.h>
#include<time.h>
void loading();
void row();
void bat();
void t();
void bowl();
struct bowlers
{
	char name[30];
	int wickets;
	int overs;
};
struct batsmen
{
	char name[30];
	int runs;
	float sr;
};
int g=0,h=0,x;
int n,i,m;
typedef struct batsmen sbat;
typedef struct bowlers sbowl;

void main()
{
    FILE *F;
	sbat *B;
	sbowl *C;
	printf("\t\t\t\tHello...You Can Write And Save Your Score Sheet\n\t\t\t\tBy Filling Up The Given Sheet And Saving It\n\n");
	printf("Press Any Key To Continue....");
	getch();
	system("cls");
    while(1==1)
    {
	printf("How Many Batsmen?: ");
	scanf("%d",&n);
	if(n>11)
	{
		printf("Team Has 11 Players");
		loading();
	}
	else
	{
		break;
	}
	}
	B=(sbat*)malloc(n*sizeof(sbat));
	printf("\t\t\tBATSMEN\n");
	for(i=1;i<=n;i++)
	{
	printf("Enter Name Of Batsman %d: ",i);
	fseek(stdin,0,SEEK_END);
	gets(B[i-1].name);
	printf("Enter Runs Of Batsman %d: ",i);
	scanf("%d",&B[i-1].runs);
	printf("Enter Strike Rate Of Batsman %d: ",i);
	scanf("%f",&B[i-1].sr);
	}
	loading();
	
	while(1==1)
    {
	printf("How Many Bowlers?: ");
	scanf("%d",&m);
	if(m>11)
	{
		printf("Team Has 11 Players");
		loading();
	}
	else
	{
		break;
	}
	}
	C=(sbowl*)malloc(m*sizeof(sbowl));
	printf("\t\t\tBowlers\n");
	for(i=1;i<=m;i++)
	{
	printf("Enter Name Of Bowler %d: ",i);
	fseek(stdin,0,SEEK_END);
	gets(C[i-1].name);
	printf("Enter Overs Of Bowler %d: ",i);
	scanf("%d",&C[i-1].overs);
	printf("Enter Wickets Taken By Bowler %d: ",i);
	scanf("%d",&C[i-1].wickets);	
    }
    loading();
    printf("Your Scoresheet Is Created by The Name \"Untitled_Sheet.txt\"!!" );
    F=fopen("Untitled_Sheet.txt","w");
    
    t(F);
    fprintf(F,"\t\t\tBATSMEN\n");
	row(F);
	bat(B,n,F);
	fprintf(F,"\t\t\tBOWLERS\n");
	row(F);
	bowl(C,m,F);
	fclose(F);
	printf("!!Make Sure To Rename The Sheet If You Want To Save It!!\n\nPress Any Key To Exit:)");
	printf("IT IS SAVED IN THE SAME LOCATION AS THIS PROGRAM :)");
}
void loading()
{
	int i;
	for(i=0;i<3;i++)
	{
	printf(".");
	sleep(1);
    }
    system("cls");
}
void row(FILE *F)
{
	int i;
	fprintf(F,"\n");
	for(i=0;i<75;i++)
	{
		fprintf(F,"-");
	}
	fprintf(F,"\n");
}
void bat(sbat *B,int n,FILE *F)
{
	fprintf(F,"\tBATSMAN NAMES\t\tRUNS\t\tSTRIKE RATE");
	do
	{
	row(F);
    fprintf(F,"\t%s\t\t\t",B[g].name);
    fprintf(F,"%d\t\t\t",B[g].runs);
    fprintf(F,"%f",B[g].sr);
	g++;
	}
	while(g<n);
	row(F);
}
void t(FILE *F)
{
	time_t tm;
    time(&tm);
    fprintf(F,"Date/Time = %s", ctime(&tm));
}
void bowl(sbowl *C,int m,FILE *F)
{
	fprintf(F,"\tBOWLER NAMES\t\tOVERS\t\tWICKETS");
	do
	{
	row(F);
    fprintf(F,"\t%s\t\t\t",C[h].name);
    fprintf(F,"%d\t\t\t",C[h].overs);
    fprintf(F,"%d",C[h].wickets);
	h++;
	}
	while(h<m);
	row(F);
}
