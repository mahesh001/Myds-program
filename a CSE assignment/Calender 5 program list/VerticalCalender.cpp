#include<iostream>
#include<string>
using namespace std;
struct Date{
	int day;
	int month;
	int year;
};
int DaysinMonth(int month,int year){
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		return 31;
	}
	else if(month==2){
		if(year%4==0){
			if(year%100==0){
			   if(year%400==0){
			   	return 29;
			   }
			   else
			   return 28;
		    }
		    return 29;
		}
		else
		return 28;
	}
	else{
		return 30;
	}
}
void getDate(Date & FristDate){
	cout<<"Enter day month and year of Frist day of year\n";
	cin>>FristDate.day>>FristDate.month>>FristDate.year;
}
int main(){
	Date FristDate;
	getDate(FristDate);
	int spcurr=FristDate.day-1,spnext,line_no,temp,Days_in_month;
	int i;
	string day[]={" ","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    string Month_name[]={" ","Jan","Feb","Mar","Apl","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
    for(i=1;i<=12;i++){
    	line_no=1;
		Days_in_month=DaysinMonth(i,FristDate.year);
    	temp=1;
    	cout<<"     "<<Month_name[i]<<" "<<FristDate.year<<endl;
    	cout<<day[line_no];
        do{
        	if(spcurr>=line_no){
    		cout<<"    ";
    	    temp=(7-spcurr+line_no);
    	    while(temp<=Days_in_month){
    	    	if(temp<10){
        	      cout<<" "<<temp<<"  ";
        	  }else{
        	  	cout<<" "<<temp<<" ";
        	  }
        	  temp+=7;
        	  if(temp==Days_in_month){
        		  if(line_no==7)
        		    spnext=0;
        		    else
        		    spnext=line_no;
        	  }
            }
        	 if(temp>Days_in_month){
        	 	cout<<endl;
        	 	line_no++;
        	 	cout<<day[line_no];
        	 }
            }
            else{
            	temp=line_no-spcurr;
            	while(temp<=Days_in_month){
        	   if(temp<10){
        	      cout<<" "<<temp<<"  ";
        	    }else{
        	  	cout<<" "<<temp<<" ";
        	    }
        	    temp+=7;
        	     if(temp==Days_in_month){
        		  if(line_no==7)
        		    spnext=0;
        		    else
        		    spnext=line_no;
        	    }
        	    if(temp>Days_in_month){
        	 	cout<<endl;
        	 	line_no++;
        	 	cout<<day[line_no];
        	    }
              }
            }
        }while(line_no<=7);
        spcurr=spnext;
        cout<<endl;
    }
}
