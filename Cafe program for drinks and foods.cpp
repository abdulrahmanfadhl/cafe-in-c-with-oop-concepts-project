/*
 Welcome to my project that is a implement all concepts of OOPS in C++
 This program is a delivery service to order some of driks and foods
           SO GOOD LUCK WITH IT ^_^  
*/

#include <iostream>
#include <string.h>
using namespace std;
int Up_glass[6]={6,9,7,3,10,5};           //Unite price of drinks
int Up_plate[6]={30,20,25,15,10,18};      //Unite price of foods

///////// Class Main ( The parent class) ////////
class Boss {
	 string name;          // Name of customer  
	 string addr;         // Address of customer
     long int  phon;      // Number phone of customer
    	                    
 	public:
		int order;        // 	Number of order
		int sentinel;    //   To check from the condation of orders
		Boss()   //Default Constructor
		{
		 order=1;
	     sentinel=0;
		}
		friend void beginning(Boss &M)    // To input information of customer
		{    
		 cout<<"======================================================================\n";
         cout<<"::::: WELCOME TO MY PROGRAM TO ORDER MANY OF DRINKS AND FOODS :::::\n";
         cout<<"======================================================================\n";
         cout<<"This Progran is to order some glasses of drinks and plates of foods with delivery services\n";

         cout<<"\nplease enter your name :-  \n";
     	 cin>>M.name;
     	 cout<<"\nplease enter your address :- \n";
     	 cin>>M.addr;
         cout<<"\nplease enter your phone :- \n";
	     cin>>M.phon; 
		}
	void display();

};

		inline void Boss::display()     // Inline function Print Receipt of order  
		{   
		 cout<<"..........................................\n";
         cout<<"..          RECEIPT                     ..\n";
         cout<<"..........................................\n";
         cout<<"..........................................\n";
         cout<<"..... Name        :-  "<< name<<endl;
         cout<<"..... Address     :-  "<< addr<<endl;
         cout<<"..... phone       :- ( +967 "<<phon<<endl;
		}
		
		
//            Class of drinks (Child class for Boss class< parent class> )
class Drinks: public Boss {
	private :
	int a;
	int num_glasses[6];          // number of glasses that is ordered 
	public: 
	 int mou_drinks[6];          // mou_drinks is a mount of sales of drinks
	 Drinks()         //Default Constructor to initialize the data members
	    {            
		 for(int j=0;j<6;j++)
	 	    {  
		     num_glasses[j]=0;
	 	     mou_drinks[j]=0;
		   }
		}
        		
	void set_mount_drinks(int);      //To compute the mount of glasses which is order 
   
    void list_drinks()
    {  
 	 system("cls");
     cout<<"====================================================================\n";
     cout<<"  :::::::::::::::::::::: MENU OF DRINKS ::::::::::::::::::::::::::\n ";
     cout<<"====================================================================\n";
     cout <<" [1] Orange juice		       $6  <===\n"
          <<" [2] Mango juice		       $9  <===\n"
	      <<" [3] Strawberry juice	               $7  <===\n"
	      <<" [4] Apple juice 		       $3  <===\n"
	      <<" [5] grape juice		       $10 <===\n"
	      <<" [6] blue berry juice                  $5  <===\n";
	             
	         
   	while (order != sentinel)
	   {
         cout<<"\nFrom The List , What Would You Like ? : \n";
         cin>>order;
	     set_mount_drinks(order-1);
         cout<<"\n Would you want anything else ?  ( yes = 1 ) , ( no = 0 )  :  ";
         cin>>a;
         if (a==0) 
             break;
       }
   } 	 
   
   int get_totle()     // To find the totle sales of drinks
   {  
     int totd=0; 
   	 for(int i=0;i<6;i++)
   	    totd=totd+mou_drinks[i];
   	 return totd;
   }
    ~Drinks() { }      //   Destructor
};
 void Drinks::set_mount_drinks(int i)       //To compute the mount of glasses which is order 
	{
     cout<<"\nHow Many glasses Would You Like To Order:\n";
     cin>>num_glasses[i];
     mou_drinks[i] = Up_glass[i] * num_glasses[i];
    }
    
    
    
//            Class of foods (Child class for Boss class< parent class> )

class Foods : public Boss {
	private :
    int b;
	int num_plates[6];    // number of plates 
	public: 
	 int mou_foods[6];        //mou_foods is a mount of sales of foods
	 Foods()            //Default Constructor to initialize the data members
	    {              
	 	for(int j=0;j<6;j++)
	 	 { num_plates[j]=0;
	 	   mou_foods[j]=0;}
		}
	 void set_mount_foods(int );
     void list_foods()
	   { 
	     order=1;sentinel=0;
 	     system("cls");
         cout<<"====================================================================\n";
         cout<<"  :::::::::::::::::::::: MENU OF FOODS ::::::::::::::::::::::::::\n ";
         cout<<"====================================================================\n";
         cout <<" [1] Shawarma Sandwech 		           $30 <===\n"
              <<" [2] Sandwech Saaj		           $20 <===\n"
	          <<" [3] Sandwech Jampo	                   $25 <===\n"
	          <<" [4] Falafel Sandwech 		           $15 <===\n"
	          <<" [5] Fool Sandwech		           $10 <===\n"
	          <<" [6] Humos Sandwech                        $18 <===\n";
	      
   	    while (order != sentinel)
	       {
             cout<<"\nFrom The List , What Would You Like ? : \n";
             cin>>order;
             set_mount_foods(order-1);
             cout<<"\n Would you want anything else ?  ( yes = 1 ) , ( no = 0 )  :  ";
             cin>>b;
             if (b==0)
                 break;
           }    	 
       }

        
     int get_totle()    // To find the totle sales of foods
	   {  
         int totf=0; 
   	     for(int i=0;i<6;i++)
   	         totf=totf+mou_foods[i];
   	     return totf;
       }
    ~Foods() { }   //   Destructor
};

inline void Foods::set_mount_foods(int i)    //To compute the mount of glasses which is order 
    {  
     cout<<"\nHow Many plates Would You Like To Order:\n";
     cin>>num_plates[i];
     mou_foods[i] = Up_plate[i] * num_plates[i];
   }

int main (){
	 Boss m;  
	 beginning(m); 
	
	 int choice=1;int x=0;
	 Drinks d;Foods f;
	 
     while (choice!=x)
	   {
         cout<<"\n\n------------------------------------------------\n";
         cout<<"         What do you want to order ?  \n";
         cout<<"------------------------------------------------\n\n";
         cout<<" Press [0] : IF you don't want anything else\n";
         cout<<" Press [1] : DRINKS\n";
         cout<<" Press [2] : FOODS\n"; 
         cout<<"\nENTER YOUR CHOICE : ";
         cin>>choice;
	     switch(choice)
	       {
	         case 1:d.list_drinks();break;
	    
	         case 2:f.list_foods();break;
	   
	         default:cout<<"\n\n ERROR !!! Please Choose A Valid Item From The List\n";break;	
	       } 
       } 
     system("cls");
     m.display();
     cout<<"..... Total sales :-   "<<d.get_totle()+f.get_totle()<<"$"<<endl;
     cout<<"..........................................\n\n";
     cout<<"^_^ THANK YOU TO USE MY SERVICES ^_^";
	  	    
	 return 0;
}
