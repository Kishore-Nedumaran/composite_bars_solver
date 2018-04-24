#include<iostream.h>
#include<conio.h>
#define sqr(x) ((x)*(x))
float pi= 3.1415926535897932384626433832795;

int i,j,b,lcase,acase;
float P,cb[10][7];

inline float areaDia(int d)                                                     //Area convertion
{ return (pi/4)*sqr(d);}
inline float areaRad(int r)
{ return pi*sqr(r); }

class compbar
{public:
    void input()                                                                //Input loop
      {cout<<"\nEnter total Load :";cin>>P;
        for(j=0;j<3;j++)
            { if(j==0){cout<<"\nEnter  E:";}
        if(j==1)
             { cout<<"\nEnter your choice..\n1.Constant length\t2.Variable length\t";
	             cin>>lcase;                                                //to notify other functions where value is stored
	             if(lcase==1)
                 { for(i=0;i<b;i++)
                   { cb[i][j]=1;
                   }continue;
                 }
             }
        if(j==2)
             { cout<<"\nEnter your choice..\n1.Area Given\t2.Diameter\t3.Radius\t";
               cin>>acase;
               if(acase==2) {j=3;}
               if(acase==3) {j=4;}
              }
        for(i=0;i<b;i++)
            {cin>>cb[i][j];}
      }
    
    void output()                                                               //Displays O/P
      {int m,n;
         for(n=5;n<7;n++)
	          { if(n==6){cout<<"\nLoads   :";}
	      if(n==5)  {cout<<"\nStresses:";}
	       for(m=0;m<b;m++)
	         {cout<<m+1<<".\t";
            cout<<cb[m][n]<<"\t";
           }
	    }

    void calc()                                                                 //Calculates With I/P
      { input();
        float u,Kratio;
        if(acase==2)
          {for(u=0;u<b;u++)
               {cb[u][2]=areaDia(cb[u][3]);}
          }
        if(acase==3)
          {for(u=0;u<b;u++)
               {cb[u][2]=areaRad(cb[u][4]);}
          }
       for(u=0;u<b;u++)                                                         //Formula Stuff
          {Kratio+=((cb[u][0]/cb[0][0])*(cb[0][1]/cb[u][1])*cb[u][2]);
           // Kratio=(E(x)/E1)*(L1/L(x))*A(x)  cb[0][5]
          }
       cb[0][5]=P/Kratio;                // S1=P/k_ratio;
       for(u=0;u<b;u++)
          { if(u!=0){cb[u][5]=(cb[u][0]/cb[0][0])*cb[0][5];}
              // S(x)=(E(x)/E1)*S1;
            cb[u][6]=cb[u][5]*cb[u][2];
              // P(x)=S(x)*A(x);
          }
        output();
      }
};

void main()
{ clrscr();
  cout<<"\nEnter number of materials used:";
  cin>>b;
  compbar cbr; 
  cbr.calc();
  getch(); 
}
