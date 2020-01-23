#include<bits/stdc++.h>

using namespace std;

class Flight{

	public:
		bool eclass[61][7];
		bool bclass[61][7];
		string flight_name;
		string flight_time;
		string flight_date;
		string depart_city;
		string arriv_city;
		
		void set_basic_data(string array_f[]){
			this->flight_name = array_f[0];			
			this->depart_city = array_f[2];
			this->arriv_city = array_f[3];
			
			string temp = array_f[1];   
			istringstream ss(temp); 
			while(ss){
				string sub_array[2];
			   	for(int u=0; u<3; u++){
			   		ss >> sub_array[u]; 
				}
				   this->flight_date = sub_array[0];
				   this->flight_time = sub_array[1];
			}
		}
		
		void set_seats(string array_f[], int count){
			int j;
			string single_line[3];
			int row_number;
			
			for(int i=4; i<count; i++){

				istringstream ss(array_f[i]);
				j = 0;
                do { 
        			ss >> single_line[j];
        			j++;
   			    } while (ss);
   			    
   			    stringstream rr(single_line[0]);
   			    rr >> row_number ;
   			    
   			    if(single_line[1] == "E"){
   			      if (single_line[2].find("A") != string::npos) {
 					this->eclass[row_number][1] = true ;
                  }
                  if (single_line[2].find("B") != string::npos) {
 					this->eclass[row_number][2] = true ;
                  }
                  if (single_line[2].find("C") != string::npos) {
 					this->eclass[row_number][3] = true ;
                  }
                  if (single_line[2].find("D") != string::npos) {
 					this->eclass[row_number][4] = true ;
                  }
                  if (single_line[2].find("E") != string::npos) {
 					this->eclass[row_number][5] = true ;
                  }
                  if (single_line[2].find("F") != string::npos) {
 					this->eclass[row_number][6] = true ;
                  }
				}
				
				else if(single_line[1] == "B"){
   			      if (single_line[2].find("A") != string::npos) {
 					this->bclass[row_number][1] = true ;
                  }
                  if (single_line[2].find("B") != string::npos) {
 					this->bclass[row_number][2] = true ;
                  }
                  if (single_line[2].find("C") != string::npos) {
 					this->bclass[row_number][3] = true ;
                  }
                  if (single_line[2].find("D") != string::npos) {
 					this->bclass[row_number][4] = true ;
                  }
                  if (single_line[2].find("E") != string::npos) {
 					this->bclass[row_number][5] = true ;
                  }
                  if (single_line[2].find("F") != string::npos) {
 					this->bclass[row_number][6] = true ;
                  }
				}
   			    
			}
			
		}
		
		Flight(){
			for(int i=0;i<61;i++){
				for(int j=0;j<7;j++){
					this->bclass[i][j]= false;
					this->eclass[i][j]= false;
				}
			}
		}
		
};



main(){

bool temp = false;
char seat_col,flight_class;
int  seat_row,b_seat_count=0,e_seat_count=0,i=0,v,j,k;
string array_file[1000];
string temp_array_file[65];
ifstream file("Flights.txt");

int flightCount = 0;

while(std::getline(file, array_file[i])) {
	i++;
}


for(j=0;j<i;j++){
  getline(file, array_file[i]);
  if(array_file[j] == ""){
  	if(array_file[j-1] == ""){
	} else {
	  flightCount++;
	}
  }
}

if(array_file[i-1] == ""){
} else {
	flightCount++;
}

Flight A[flightCount];

int position = 0;

for(j=0;j<flightCount;j++){
	k = 0;
    while(array_file[position] != "" ){
		temp_array_file[k] = array_file[position];
		position++;
		k++;
	}
	position++;
	
	A[j].set_basic_data(temp_array_file);
	A[j].set_seats(temp_array_file, k);
}

///////////////////////////////////////////////////////////////////////

while (1)
{
	int choice,k, v=0;
	cout<< "///////////////////////////" << endl;
	cout<< "---Flight Booking System---" << endl;
	cout<< "///////////////////////////" << endl;
	cout<<"1). Display Available Flights"<< endl;
	cout<<"2). View Flight" <<endl;
	cout<< "3). Seat Availability " <<endl;
	cout<<"4). Seat Booking" << endl;
	cout<<"5). Exit"<< endl;
	cout<< "Select Your Option :- ";
	cin >> choice;
	cout<< "///////////////////////////" << endl;


	string flight_name;
	bool at_least_single_sheet;
	int num_of_seats, row, i, uniq_flight;
	char col, clz;


	switch (choice)
	{
		case 1:
			for(int k=0;k<flightCount;k++){
				at_least_single_sheet = false;
				for(int i=0;i<61;i++){
					for(int j=0;j<7;j++){
						if( A[k].bclass[i][j] == true || A[k].eclass[i][j] ==true){
							at_least_single_sheet = true;
							break;
						}
					}
					if(at_least_single_sheet){
						break;
					}
				}
				if(at_least_single_sheet){
					cout<< "Flight Name : " <<A[k].flight_name<<endl;
					cout<<"Date : " << A[k].flight_date<<endl;
					cout<<"Time : " << A[k].flight_time<<endl;
					cout<< "Arrival city : "<<A[k].arriv_city<<endl;
					cout<< "Departure city : "<< A[k].depart_city <<endl;
					cout<< "............" <<endl;
				}
			}
		break;

		case 2:
			cout<< "Enter flight Name :";
			cin >> flight_name;
			temp = false;
			for(int i=0; i< flightCount; i++){
				if(flight_name == A[i].flight_name){
					temp = true;
					v=i;
					break;
					
				}
			}
			if(!temp){
				cout<<"Invalid Flight Number"<<endl<<endl;
				break;
			}
			cout<<"Business Class :-"<<endl;
			for(int i=1; i<61; i++){
				temp = false;
				for(int j=1; j<7; j++){
					if(A[v].bclass[i][j]){
						temp = true ;
						if( j == 1 ){ cout<<"A"; }
						if( j == 2 ){ cout<<"B"; }
						if( j == 3 ){ cout<<"C"; }
						if( j == 4 ){ cout<<"D"; }
						if( j == 5 ){ cout<<"E"; }
						if( j == 6 ){ cout<<"F"; }
						b_seat_count++;
					}
				}
				if(temp){
					cout<<"   seats available in   "<< i << "  th Row" <<endl; 
				}		
			}
			cout <<"Toatal number of B class seats :: "<< b_seat_count<< endl<<endl<<endl;




			cout<<"Economic Class :-"<<endl;
			cout<<"Seats  ||   Row "<<endl;
			e_seat_count=0;
			for(int i=1; i<61; i++){
				temp = false;
				for(int j=1; j<7; j++){
					if(A[v].eclass[i][j]){
						temp = true ;
						if( j == 1 ){ cout<<"A"; }
						if( j == 2 ){ cout<<"B"; }
						if( j == 3 ){ cout<<"C"; }
						if( j == 4 ){ cout<<"D"; }
						if( j == 5 ){ cout<<"E"; }
						if( j == 6 ){ cout<<"F"; }
						e_seat_count++;
					}
				}
				if(temp){
					cout<<" seats available in    "<< i << "    th Row" <<endl; 
				}
				
			}
			cout<<"Total Number of E class seats :: "<< e_seat_count<< endl<<endl<<endl;
			break;

			case 3:
				cout<< "Flight Number :"<<endl;
				cin>> flight_name;
				temp = false;
				for(int i=0; i< flightCount; i++){
					if(flight_name == A[i].flight_name){
						temp = true;
						v=i;
						break;
						
					}
				}
				if(!temp){
					cout<<"Invalid Flight Number"<<endl<<endl;
					break;
				}
				cout<< "How many seats :"<<endl;
				cin>> num_of_seats;
				e_seat_count =0;
				for(int i=1; i<61; i++){
					for(int j=1; j<7; j++){
						if(A[v].eclass[i][j]){
							e_seat_count++;
						}
					}
				}
				b_seat_count=0;
				for(int i=1; i<61; i++){
					for(int j=1; j<7; j++){
						if(A[v].bclass[i][j]){
							b_seat_count++;
						}
					}
				}

				if (e_seat_count >= num_of_seats || b_seat_count >= num_of_seats || (e_seat_count+b_seat_count) >= num_of_seats )
				{
					cout<< "seats are available" <<endl;
					cout<< "E seats :" << e_seat_count << endl<<"B seats : "<<b_seat_count<<endl<<endl;
				}
				else{
					cout<< "Not available" <<endl<<endl<<endl;
				}

				break;
			
			case 4:
				cout<<"Enter Flight Number : "<<endl;
				cin>> flight_name;
				temp = false;
				for(int i=0; i< flightCount; i++){
					if(flight_name == A[i].flight_name){
						temp = true;
						v=i;
						break;
						
					}
				}
				if(!temp){
					cout<<"Invalid Flight Number"<<endl<<endl;
					break;
				}else{
					cout<<"Enter your class :";
					cin>> flight_class;
					if(flight_class != 'E' && flight_class != 'B'){
						cout<< "Invalid class"<<endl;
						break;
					}else{	
						cout<<"Enter Row number : ";
						cin>>seat_row;
						if(seat_row >= 61 || seat_row <= 0){
							cout<<"Invalid Input!"<<endl;
							break;
						}else{
							cout<<"Enter column Alphabet";
							cin>> seat_col;
							if(seat_col !='A' && seat_col !='B' && seat_col !='C' && seat_col !='D' && seat_col !='E' && seat_col !='F'){
								cout<<"Invalid input"<<endl;
								break;
							}else{
								cout<<"v :"<<v<<endl<<"row: "<<seat_row<<endl<<"col :"<<seat_col<<endl;
								cout<<"lol :"<<A[v].eclass[seat_row+1][seat_col]<<endl;
								
//								for(int i=1;i<61;i++) {
//	 								cout<< i << " - " ;
//								 	for(int j=1;j<7;j++) {
//								 		cout << A[v].eclass[i][j] << " " ;
//							         }
//								 	cout << endl;
//							     }
								
								
//								if(flight_class == 'E'){
//									if(A[v].eclass[seat_row][seat_col]){
//										cout<<"Seat is Allocated!!"<<endl;
//									}
//									else{
//										cout<<"Seat is not available!! Try another one"<<endl;
//									}	
//								}
//				
//								if(flight_class == 'B'){
//									if(A[v].bclass[seat_row][seat_col]){
//										cout<<"Seat is Allocated!!"<<endl;
//									}
//									else{
//										cout<<"Seat is not available!! Try another one"<<endl;
//									}	
//								}
							}
						}
					}	
				}


				break;



		default:
			cout<<"shit" <<endl;
			break;			


	}


}



////////////////////////////////////////////////////////////////////////



     for(int i=1;i<61;i++) {
	 	cout<< i << " - " ;
	 	for(int j=1;j<7;j++) {
	 		cout << A[0].eclass[i][j] << " " ;
         }
	 	cout << endl;
     }


return 0;
}


