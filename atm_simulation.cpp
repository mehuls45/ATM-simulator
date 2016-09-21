#include<iostream>
#include<ctime>
using namespace std;

class atm{

	public:
    string account[10],pin[10];
    string account_number,pin_number,pin_num;
    int balance[10],checker,c,wit,bal;
    int i,j,flag,index,counter;


    atm(){
        flag = 0;
        counter = 0;
        index = 0;
        checker = 0;
    }

    void account_generator(){

        account[0] = "150AC3X00";
        account[1] = "150AC3X01";
        account[2] = "150AC3X02";
        account[3] = "150AC3X03";
        account[4] = "150AC3X04";
        account[5] = "150AC3X05";

    }

    void pin_generator(){

        pin[0] = "0000";
        pin[1] = "0101";
        pin[2] = "0202";
        pin[3] = "0303";
        pin[4] = "0404";
        pin[5] = "0505";

    }

    void initialize_balance()
	{

        for(i=0;i<6;i++){
            balance[i] = 50000;  //Initial balance is 50000
        }
    }

    void display_time()
	{
        time_t now = time(0);
        char* dateandtime = ctime(&now); //displays current time and date on calling as per the system
        cout<<dateandtime<<"\n";
    }

    void account_verifier(){

    	cout<<"Enter account number:  ";
    	cin>>account_number;

    	for(i=0;i<6;i++){

    		if(account[i]==account_number){
    			flag = 1;
    			index = i;
    			break;
    		}
    	}

    		if(flag==1){
    			pin_verifier();
    		}
    	else{
    		cout<<"\nInvalid account number ! Please enter a valid account number\n\n";
    		}
    	}

    void pin_verifier(){

    	do{
    	cout<<"\nEnter PIN: ";
    	counter++;
    	cin>>pin_number;

    	if(pin[index]==pin_number){

    		checker = 1;
    		menu();
    	}
    	else{
    		cout<<"\nWRONG PIN ! The entered pin did not match.\n";
    	}

    	}while(counter!=3 && checker!=1);

    	if(counter==3 && checker!=1)
    	cout<<"\nThe account is temporarily blocked for security reasons !\n\n";

    }

    void menu()
    {
    	int cho;
    	cout<<"\nPlease follow the instructions displayed on the screen: \n\n";

    	cout<<"Press 1 to withdraw money"<<endl;
    	cout<<"Press 2 to deposit money"<<endl;
    	cout<<"Press 3 for balance enquiry"<<endl;
    	cout<<"Press 4 to change pin"<<endl;
    	cout<<"Choice: ";
    	cin>>c;

    	switch(c)
    	{
    	case 1:
    		cout<<"Enter the amount for withdrawal :  ";
    		cin>>wit;
    		if(wit>=100 && wit<=25000){

                bal=balance[index]-wit;
                balance[index]=bal;
                cout<<"\n\nWithdrawal of Rs."<<wit<<" was successfully carried out from your account number 150****** \n";
                cout<<"Your current account balance is Rs."<<balance[index]<<" at ";
                display_time();
    		}
    		else
    		{
    			cout<<"\nPlease enter an amount in the range of Rs.100 to Rs.25000\n";
    		}
    		break;

    	case 2:
    		cout<<"\nEnter the amount for deposition :  ";
    		cin>>wit;
    		if(wit<=25000)
    		{
    			bal=balance[index]+wit;
    			balance[index]=bal;
                cout<<"\n\nAmount of Rs."<<wit<<" was successfully deposited to your account number 150XXXXXX \n";
                cout<<"Your current account balance is Rs."<<balance[index]<<" at ";
                display_time();

    		}
    		else
    		{
    			cout<<"\nThe amount to be deposited cannot be greater then Rs.25000\n";
    		}
    		break;

    	case 3:
    		cout<<"\n\nYour current account balance is Rs."<<balance[index]<<" at ";
    		display_time();
    		break;

    	case 4:
    		cout<<"\nEnter the old pin for confirmation :  ";
    		cin>>pin_num;

    		if(pin[index]==pin_num)
    		{
    			cout<<"\nEnter the new pin carefully :  ";
    			cin>>pin[index];
    			cout<<"\nPin changed successfully at time ";
    			display_time();
    		}
    		else
    		{
    			cout<<"\nThe entered pin did not match ! "<<endl;

    		}
		break;
		}

    }
};

int main(){

    atm obj;
    obj.account_generator();
    obj.pin_generator();
    obj.initialize_balance();
    obj.account_verifier();
}


