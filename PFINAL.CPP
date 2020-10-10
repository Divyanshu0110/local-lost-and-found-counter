#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
ifstream fin_admin,fin_drop,fin_fory,fin_add,fin_claim;
ofstream fout_admin,fout_drop,fout_fory,fout_add,fout_claim;
int z=0,a=0,y,i;
//graphics upto first structure
void loading()
{  clrscr();
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "\\TC\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   int c=150;
   for(int q=0;q<15;q++)
    { for(int w=50;w<100;w++)
     { setcolor(14);
       settextstyle(SMALL_FONT,HORIZ_DIR,10);
       outtextxy(midx,midy,"Loading...");
       settextstyle(SMALL_FONT,HORIZ_DIR,5);
       outtextxy(midx+5,midy+5,"Please Wait");
       /* set fill style and draw a pie slice */
       setfillstyle(4, 3);
       pieslice(midx,midy,0,270,w);
       pieslice(midx,midy,0,270,c);
       c--;
       cleardevice();
     }
    }
   /* clean up */
   closegraph();
}
void intro()
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "\\TC\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = 80 / 2;
   midy = getmaxy() / 2;

   settextstyle(SMALL_FONT,HORIZ_DIR,30);
     outtextxy(midx+180,midy-50,"WELCOME!");
     delay(800);
     outtextxy(midx-18,midy,"T");
     delay(100);
     outtextxy(midx-18+20,midy,"H");
     delay(100);
     outtextxy(midx-18+20+20,midy,"E");
     delay(150);
     outtextxy(midx-18+90,midy,"L");
     delay(100);
     outtextxy(midx-18+90+20,midy,"O");
     delay(100);
     outtextxy(midx-18+90+20+20,midy,"S");
     delay(100);
     outtextxy(midx-18+90+20+20+20,midy,"T");
     delay(150);
     outtextxy(midx-18+90+110,midy,"A");
     delay(100);
     outtextxy(midx-18+90+110+20,midy,"N");
     delay(100);
     outtextxy(midx-18+90+110+20+20,midy,"D");
     delay(150);
     outtextxy(midx-18+90+110+90,midy,"F");
     delay(100);
     outtextxy(midx-18+90+110+90+20,midy,"O");
     delay(100);
     outtextxy(midx-18+90+110+90+20+20,midy,"U");
     delay(100);
     outtextxy(midx-18+90+110+90+20+20+20,midy,"N");
     delay(100);
     outtextxy(midx-18+90+110+90+20+20+20+20,midy,"D");
     delay(150);
     outtextxy(midx-18+90+110+90+130,midy,"C");
     delay(100);
     outtextxy(midx-18+90+110+90+130+20,midy,"O");
     delay(100);
     outtextxy(midx-18+90+110+90+130+20+20,midy,"U");
     delay(100);
     outtextxy(midx-18+90+110+90+130+20+20+20,midy,"N");
     delay(100);
     outtextxy(midx-18+90+110+90+130+20+20+20+20,midy,"T");
     delay(100);
     outtextxy(midx-18+90+110+90+130+20+20+20+20+20,midy,"E");
     delay(100);
     outtextxy(midx-18+90+110+90+130+20+20+20+20+20+20,midy,"R");
     delay(800);
     closegraph();
}
void border()
{  gotoxy(1,1);  //top left
   putch(char(201));

   for(i=2;i<79;i++)
      { gotoxy(i,1);
	putch(char(205));
      }
     gotoxy(79,1);  //top right
     putch(char(187));
   for(i=2;i<25;i++)
      { gotoxy(79,i);
	putch(char(186));
      }
   gotoxy(79,25); //bottom right
   putch(char(188));
   for(i=2;i<79;i++)
      { gotoxy(i,25);
	putch(char(205));
      }
   gotoxy(1,25); //bottom left
   putch(char(200));
   for(i=2;i<25;i++)
      { gotoxy(1,i);
	putch(char(186));
      }
}
//structures
struct H //time
{ int hour,min,sec,hour1,min1,sec1;
};
struct G //date
{ int day,mon,year,day1,mon1,year1;
};
struct Y //add
{ char des1[15],des2[15],name1[15],model[15],name2[15],class_section[15];
  H TIME1;
  G DATE;
};
struct Z //claim
{ char des1[20],name[20],des2[20],name1[20],class_section[20];
  H TIME1;
  G DATE;
};
void TIME()
{  gotoxy(60,23);
   struct time t;

   gettime(&t);
   printf("Time- %2d:%02d:%02d\n",t.ti_hour, t.ti_min, t.ti_sec);
   struct date d;
   gotoxy(60,24);
   getdate(&d);
   printf("Date- %2d:%02d:%02d\n",d.da_day, d.da_mon, d.da_year);
}
void check_drop()
{ fout_drop.open("pro_drop.dat",ios::out | ios::binary);
  fout_drop.close();
}
void check_add()
{ fout_add.open("pro_add.dat",ios::out | ios::binary);
  fout_add.close();
}
void check_claim()
{ fout_claim.open("pro_claim.dat",ios::out | ios::binary);
  fout_claim.close();
}
//index value y
void input_y()
{ int NEW;
  fin_fory.open("Y.txt",ios::in);
  if(!fin_fory)
  { fout_fory.open("Y.txt",ios::out);
    fout_fory<<0;
    fout_fory.close();
  }
  fin_fory.seekg(0);
  fin_fory>>NEW;
  y=NEW;
  fin_fory.close();
}
void output_y()
{ fout_fory.open("Y.txt",ios::out);
  fout_fory<<y;
  fout_fory.close();
}
class pro
{ private:
	   void admin();
	   void add();
	   void user();
  public:  void main_menu();
	   void password();
	   void current();
	   void drop_record();
	   void claim_record();
	   void claim();
	   void datetime_add();
	   void datetime_claim();
	   int j;
	   Z iclaim;
	   Y item,NEW,idrop;
}A;
//individual date and time
void pro::datetime_add()
{
   struct  time t;
   gettime(&t);
     idrop.TIME1.hour=idrop.TIME1.hour1=t.ti_hour;
     idrop.TIME1.min=idrop.TIME1.min1=t.ti_min;
     idrop.TIME1.sec=idrop.TIME1.sec1=t.ti_sec;

   struct date d;
   getdate(&d);
     idrop.DATE.day=idrop.DATE.day1=d.da_day;
     idrop.DATE.mon=idrop.DATE.mon1=d.da_mon;
     idrop.DATE.year=idrop.DATE.year1=d.da_year;
}
void pro::datetime_claim()
{
   struct  time t;
   gettime(&t);
     iclaim.TIME1.hour=idrop.TIME1.hour1=t.ti_hour;
     iclaim.TIME1.min=idrop.TIME1.min1=t.ti_min;
     iclaim.TIME1.sec=idrop.TIME1.sec1=t.ti_sec;

   struct date d;
     getdate(&d);
     iclaim.DATE.day=idrop.DATE.day1=d.da_day;
     iclaim.DATE.mon=idrop.DATE.mon1=d.da_mon;
     iclaim.DATE.year=idrop.DATE.year1=d.da_year;
}
//admin profile
void create_admin()
{ clrscr();
  border();
  TIME();
  char username[20],pass[20];
  fout_admin.open("proadmin.txt",ios::out);
  gotoxy(3,3);
  cout<<"Enter username:";
  gets(username);
  fout_admin<<username<<endl;
  gotoxy(3,4);
  cout<<"Enter password:";
  gets(pass);
  fout_admin<<pass<<endl;
  fout_admin.close();
  gotoxy(3,6);
  cout<<"Admin account created. Please log-in again to continue.";
  getch();
  A.main_menu();
}
void main()
{// intro();
 // loading();
  clrscr();
  border();
  A.main_menu();
  getch();
}
void pro::main_menu()
{ int choice;
  for(a=0;a!=1;)
  {
  clrscr();
  border();
  gotoxy(30,2);
  cout<<"LOST AND FOUND COUNTER:"<<endl;
  TIME();
  gotoxy(3,3);
  cout<<"Here as?";
  gotoxy(3,4);
  cout<<"1. Admin";
  gotoxy(3,5);
  cout<<"2. Teacher";
  gotoxy(3,6);
  cout<<"3. Student";
  gotoxy(3,7);
  cout<<"4. Exit";
  gotoxy(3,8);
  cin>>choice;
  if(choice==1 || choice==2 || choice==3 || choice==4)
  { a=1; }
  else {
   gotoxy(3,9);
   cout<<"Wrong choice.Please enter again.";
   getch(); }
 }
  switch(choice)
  { case 1: int temp=0;
	    fin_admin.open("proadmin.txt",ios::in);
	    if(!fin_admin)
	     { temp=1;
	       gotoxy(3,11);
	       cout<<"Admin account does not exist. Please create an account first."<<endl;
	       getch();
	     }
	     while(temp!=0)
	     { create_admin();
		if(!fin_admin)
		 { temp=1;
		   cout<<"Admin account not created. Please try again."<<endl;
		   getch();
		 }
		else
		{ temp=0; }
	     }
	    fin_admin.close();
	    password();
	    break;
    case 2:
    case 3: user();
	    break;
    case 4: gotoxy(3,10);
	    cout<<"Thank you for coming.";
	    getch();
	    exit(0);
  }
}
//admin password
void pro::password()
{ char P[20],U[20],U1[20],P1[20],temp[20];
  int k=3,j=0;
  fin_admin.open("proadmin.txt",ios::in);
  fin_admin.seekg(0);
   while(!fin_admin.eof())
    {
     fin_admin>>temp;
     if(temp[0]=='@')
     { strcpy(U1,temp); }
     else if(temp[0]=='!')
     { strcpy(P1,temp);
     }
     else;
    }
  fin_admin.close();
  clrscr();
  border();
  gotoxy(3,3);
  cout<<"Login with admin details:";
 do
  { gotoxy(3,4);
    cout<<"Enter username:";
    gets(U);
    gotoxy(3,5);
    cout<<"Enter password:";
   do
   { P[j]=getch();
     if(P[j]!=13)
    { cout<<"*"; }
    j++;
   }while(P[j-1]!=13);
   P[j-1]='\0';
   j=0;

   if(strcmp(P,P1)==0 && strcmpi(U,U1)==0)
     { admin();
       break;
     }
   else {
   clrscr();
   border();
   gotoxy(3,3);
   cout<<"Incorrect username or password. Enter again.(Chances left:"<<k-1<<")"<<endl;
   k--; }
 }while(k!=0);
 main_menu();
}
void pro::admin()
{  int l;
  for(a=0;a!=1;)
  {
  clrscr();
  border();
  TIME();
  gotoxy(40,2);
  cout<<"Welcome!";
  gotoxy(3,3);
  cout<<"Tasks:";
  gotoxy(3,4);
  cout<<"1. View current item list";
  gotoxy(3,5);
  cout<<"2. View drop record";
  gotoxy(3,6);
  cout<<"3. View claimed record";
  gotoxy(3,7);
  cout<<"4. Add item";
  gotoxy(3,8);
  cout<<"5. Claim item";
  gotoxy(3,9);
  cout<<"6. Exit to main menu";
  gotoxy(3,10);
  cin>>l;
  if(l==1 || l==2 || l==3 || l==4 || l==5 || l==6)
  { a=1; }
  else {
   gotoxy(3,11);
   cout<<"Wrong choice.Please enter again.";
   getch();
       }
 }
    switch(l)
    { case 1: current();
	      break;
      case 2: drop_record();
	      break;
      case 3: claim_record();
	      break;
      case 4: add();
	      admin();
	      break;
      case 5: claim();
	      admin();
	      break;
      case 6: main_menu();
	      break;

    }

}
void pro::user()
{ int choice;
  for(a=0;a!=1;)
  {
  clrscr();
  border();
  TIME();
  gotoxy(40,2);
  cout<<"Welcome, User!";
  gotoxy(3,3);
  cout<<"1.Add item";
  gotoxy(3,4);
  cout<<"2.Claim item";
  gotoxy(3,5);
  cout<<"3.Exit to main menu";
  gotoxy(3,6);
  cin>>choice;
  if(choice==1 || choice==2 || choice==3)
  { a=1; }
  else {
   gotoxy(3,7);
   cout<<"Wrong choice.Please enter again.";
   getch(); }
 }
  switch(choice)
  { case 1: add();
	    user();
	    break;
    case 2: claim();
	    user();
	    break;
    case 3: main_menu();
	    break;
  }
}
void pro::add()
{ input_y();
  char ch;
  fout_drop.open("pro_drop.dat",ios::app | ios::binary);
  if(!fout_drop)
  { check_drop(); }
  fout_add.open("pro_add.dat",ios::app | ios::binary);
  if(!fout_add)
  { check_add(); }
 do
 {
   clrscr();
   border();

   gotoxy(40,2);
   cout<<"Add menu:";
     gotoxy(3,3);
     cout<<"Item number:"<<y+1;
     gotoxy(3,4);
     cout<<"Enter name/type of the item you want to add:";
     gotoxy(3,5);
     gets(item.name1);
     gotoxy(3,6);
     cout<<"Enter model,if any(enter null if no model):";
     gotoxy(3,7);
     gets(item.model);
     gotoxy(3,8);
     cout<<"Enter description 1:";
     gotoxy(3,9);
     gets(item.des1);
     gotoxy(3,10);
     cout<<"Enter description 2:";
     gotoxy(3,11);
     gets(item.des2);
     clrscr();
     border();
     gotoxy(3,3);
     cout<<"Enter your full name:";
     gotoxy(3,4);
     gets(item.name2);
     gotoxy(3,5);
     cout<<"Enter class and section:";
     gotoxy(3,6);
     gets(item.class_section);
     datetime_add();
     fout_drop.write((char*)&item,sizeof(item));
     fout_add.write((char*)&item,sizeof(item));
     gotoxy(3,8);
     cout<<"Do you wish to add more items?(Y/N)";
     gotoxy(3,9);
     cin>>ch;
     y++;
   }while(ch=='Y'|| ch=='y');
   output_y();

  fout_drop.close();
  fout_add.close();
}
void pro::current()
{ char ch;
  fin_add.open("pro_add.dat",ios::in | ios::binary);
  if(!fin_add)
  { cout<<"File not found. Breaking operation..."<<endl;
    getch();
    exit(0);
  }
  clrscr();
  border();
  gotoxy(30,2);
  fin_add.seekg(0);
  cout<<"Current items on list:";
  i=0;
  while(fin_add.read((char*)&item,sizeof(item)))
  { gotoxy(3,3+i);
    cout<<i+1<<"."<<item.name1;
    i++;
  }
  gotoxy(3,3+i+1);
  cout<<"Exit to main menu?(Y/N)";
  gotoxy(3,3+i+2);
  cin>>ch;
   if(ch=='Y' || ch=='y')
    { admin();
    }
fin_add.close();
}
void pro::drop_record()
{ char ch;
  int k=0,i=0;
  fin_drop.open("pro_drop.dat",ios::in | ios::binary);
  if(!fin_drop)
  { cout<<"File not found. Breaking operation..."<<endl;
    getch();
    exit(0);
  }
  clrscr();
  border();
  gotoxy(29,2);
  cout<<"Complete drop record:";
  fin_drop.seekg(0);
  while(fin_drop.read((char*)&idrop,sizeof(idrop)))
  { gotoxy(3,3+k);
    cout<<i+1<<"."<<idrop.name2<<"-"<<idrop.class_section<<";Item-"<<idrop.name1;
    gotoxy(5,3+1+k);
    printf("Date the item was added: %2d:%02d:%02d\n",idrop.DATE.day,idrop.DATE.mon,idrop.DATE.year);
    gotoxy(5,3+2+k);
    printf("Corresponding Time:      %2d:%02d:%02d\n",idrop.TIME1.hour,idrop.TIME1.min,idrop.TIME1.sec);
    k+=3;
    i++;
  }
  gotoxy(3,3+i+k-2);
  cout<<"Exit to main menu?(Y/N)";
  gotoxy(3,4+i+k);
  cin>>ch;
   if(ch=='Y' || ch=='y')
    { admin();
    }
    fin_drop.close();
}
void pro::claim()
{ int tempo=0,indicator=0,temp=0;
  char ch;
  ofstream fout;
  fin_add.open("pro_add.dat",ios::in | ios::binary);
  if(!fin_drop)
  { cout<<"Required files not found. Breaking operation...";
    getch();
    exit(0);
  }
  fout_claim.open("pro_claim.dat",ios::app | ios::binary);
  if(!fout_claim)
  { check_claim(); }
  fout.open("temp.dat",ios::out | ios::binary);
  do
  {
  clrscr();
  border();
  gotoxy(40,2);
  cout<<"Claim Menu:";
  gotoxy(3,3);
  cout<<"Enter name of item you're looking for:";
  gotoxy(3,4);
  gets(iclaim.name);
  gotoxy(3,5);
  cout<<"Enter description 1:";
  gotoxy(3,6);
  gets(iclaim.des1);
  gotoxy(3,7);
  cout<<"Enter description 2 for verification:";
  gotoxy(3,8);
  gets(iclaim.des2);
  while(fin_add.read((char*)&NEW,sizeof(NEW)))
  { if(strcmpi(iclaim.name,NEW.name1)==0 || strcmpi(iclaim.name,NEW.model)==0)
    { if(strcmpi(iclaim.des1,NEW.des1)==0 || strcmpi(iclaim.des2,NEW.des1)==0)
     { if(strcmpi(iclaim.des1,NEW.des2)==0 || strcmpi(iclaim.des2,NEW.des2)==0)
      { indicator=1;  }
     }
    }
    else { fout.write((char*)&NEW,sizeof(NEW)); tempo=1; }
  }
  if(temp==1)
  { remove("pro_add.dat");
    rename("temp.dat","pro_add.dat");
    tempo++;
  }
  if(indicator==1)
  { clrscr();
    border();
    gotoxy(3,3);
    cout<<"Match found.Item claimed.";
    gotoxy(3,4);
    cout<<"Enter your name:";
    gotoxy(3,5);
    gets(iclaim.name1);
    gotoxy(3,6);
    cout<<"Enter your class and section:";
    gotoxy(3,7);
    gets(iclaim.class_section);
    datetime_claim();
    fout_claim.write((char*)&iclaim,sizeof(iclaim));
    temp=2;
  }
  if(indicator!=1)
  { gotoxy(3,10);
    cout<<"Description doesn't match any available records.";
    temp=0;
  }
  gotoxy(3,11-temp);
  cout<<"Do you wish to search for another item?(Y/N)";
  gotoxy(3,12-temp);
  cin>>ch;
  }while(ch=='Y' || ch=='y');
  fout_claim.close();
  fin_add.close();
  fout.close();
}
void pro::claim_record()
{  char ch;
   int k=0,o=1;
   fin_claim.open("pro_claim.dat",ios::in | ios::binary);
   if(!fin_claim)
   { cout<<"File not found. Breaking operation..."<<endl;
     getch();
     exit(0);
   }
   clrscr();
   border();
   gotoxy(20,2);
   cout<<"Current list of claimed items:";
   fin_claim.seekg(0);
      while(fin_claim.read((char*)&iclaim,sizeof(iclaim)))
      {  gotoxy(3,3+k);
	 cout<<o<<"."<<iclaim.name<<"; Claimed by:"<<iclaim.name1<<"-"<<iclaim.class_section;
	 gotoxy(5,3+1+k);
	 printf("Date the item was claimed: %2d:%02d:%02d\n",iclaim.DATE.day,iclaim.DATE.mon,iclaim.DATE.year);
	 gotoxy(5,3+2+k);
	 printf("Corresponding Time:        %2d:%02d:%02d\n",iclaim.TIME1.hour,iclaim.TIME1.min,iclaim.TIME1.sec);
	 k=k+3;
	 o++;
      }
    gotoxy(3,3+k);
    cout<<"Exit to main menu?(Y/N)";
    gotoxy(3,4+k);
    cin>>ch;
     if(ch=='y' || ch=='Y')
      { admin();
      }
  fin_claim.close();
}