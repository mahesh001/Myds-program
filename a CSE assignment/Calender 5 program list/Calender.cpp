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
	int sp,temp,DayinMonth;
	string Month_name[]={" ","Jan","Feb","Mar","Apl","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	Date FristDate;
	getDate(FristDate);
	sp=FristDate.day;
	for(int i=1;i<=12;i++){
		temp=1;
		DayinMonth=DaysinMonth(i,FristDate.year);
		cout<<"       "<<Month_name[i]<<" "<<FristDate.year<<"      "<<endl;
		cout<<"Mon Tue Wed Thu Fri Sat Sun "<<endl;
		for(int j=1;j<sp;j++){
			cout<<"    ";
		}
		do{
			if(temp<10){
			cout<<" "<<temp<<"  ";
		    }else{
		    	cout<<" "<<temp<<" ";
		    }
			temp++;
			if(sp%7==0){
				sp=0;
				cout<<endl;
			}
			sp++;
		}while(temp<=DayinMonth);
		cout<<endl;
	}
	return 0;
}
