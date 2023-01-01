/*Group Members: 19K-0368, 19K-1310, 19K-0359*/
/*Compile and run this file only*/

#include "classes.cpp"

using namespace std;

class Interface {

public:
	
	virtual void pV() = 0; //pure virtual/
		
	static void firstLogin()
	{
		ifstream fin;
		
		Administrator firstAdmin;
		
		fin.open("admin.bin");
		
		bool dataPresent = false;
		
		if(fin)
		{
			while(fin.read((char*)&firstAdmin, sizeof(Administrator)))
			{
				fin.close();
				return;
			}
			
			fin.close();
			remove("admin.bin");
		}
		
		cout<<"\t\t\t\xB0 W  E  L  C  O  M  E \xB0 \n\n\t\xB0 First time login, you'll be required to register an admin user. \xB0\n\n\t\xB1 Press any key to continue.....";
		getch();
		
		system("cls");	
		
		ofstream fout;
		
		fout.open("admin.bin",ios::app);
		
		cin>>firstAdmin;
		
		fout.write((char*)&firstAdmin, sizeof(Administrator));
		fout.close();
		
		return;
	}
	
	static int loginCheck()
	{	
		char username[array_size_thirty];
		char password[array_size_thirty];
		
		while(1)
		{
			system("cls");
			cout<<"--> User Login\n---------------\n";
			cout<<"Username: ";	
			cin.getline(username,array_size_thirty);
			do {
				cout<<"Password: ";
				int passInputCheck = Person::securePasswordInput(password);
				if(passInputCheck == 1)
				{
					break;
				}
				else
				{
					cout<<endl;
				}
			} while(1);
			
			ifstream emp;
			ifstream admin;
			
			Employee employee;
			Administrator administrator;
			
			emp.open("employee.bin");
			admin.open("admin.bin");
			
			int lineCount = 0;
			
			while(emp.read((char*)&employee,sizeof(Employee)))//employee key file say read karo
			{
				lineCount++;
				if(strcmpi(employee.getUsername(),username) == 1)
				{
					if(strcmp(employee.getPassword(),password) == 0)
					{
						emp.close();
						return -1*lineCount;
					}
				}
			}
			
			lineCount = 0;
			
			while(admin.read((char*)&administrator,sizeof(Administrator)))//admin key file say read karo
			{
				lineCount++; 
				if(strcmpi(administrator.getUsername(),username) == 1)
				{
					if(strcmp(administrator.getPassword(),password) == 0)
					{
						admin.close();
						return lineCount;
					}
				}
			}
		
			cout<<"\n\nUsername or Password is wrong press any key to try again!";
			getch();
		}
	}
	
	static void selectUI()
	{
		while(1)
		{
			int loginVal;
			
			loginVal = loginCheck();
		
			ifstream fin;
		
			if(loginVal<0)
			{	
				Employee employee;
				fin.open("employee.bin");
				fin.seekg((-1*(loginVal)-1)*sizeof(Employee),ios::beg);
				fin.read((char*)&employee,sizeof(Employee));
				fin.close();
			
				employeeUI(employee);
		
			}
			else
			{
				Administrator administrator;
				fin.open("admin.bin");
				fin.seekg((loginVal-1)*sizeof(Administrator),ios::beg);
				fin.read((char*)&administrator,sizeof(Administrator));
				fin.close();
				
				adminUI(administrator);
						
			}	
		}
	}
		
	static void adminUI(Administrator administrator)
	{
		while(1)
		{
			system("cls");
			
			int option;

			cout<<"1 - Item Management\n"; 
			cout<<"2 - Employee Management\n";
			cout<<"3 - Admin Management\n";
			cout<<"4 - Deal Customer\n";
			cout<<"5 - View Logs\n";
			cout<<"6 - View Sale\n";
			cout<<"7 - Exit\n";
			cout<<"0 - Logout\n\n";
			
			do {
				cout<<"Enter Option: ";
				cin>>option;
			} while(option<0 || option>7);

			fflush(stdin);
			system("cls");
			
			switch(option)
			{
				case 0: return;
					break;
				case 1: 
				{
					while(1)
					{
						system("cls");
						
						int option;
						bool toReturn = false;
						
						cout<<"1 - Add Item to Stock\n"; 
						cout<<"2 - Modify Item Data\n";
						cout<<"3 - View Stock\n";
						cout<<"4 - View Item by Code\n";
						cout<<"5 - Item(s) to Re-Stock\n";
						cout<<"0 - Return\n\n";
			
						do {
							cout<<"Enter Option: ";
							cin>>option;
						} while(option<0 || option>5);
					
						fflush(stdin);
						system("cls");
						
						switch(option)
						{
							case 1: administrator.addToStock();
								break;
							case 2: administrator.modifyFromStock();
								break;
							case 3: administrator.viewStock();
								break;
							case 4: administrator.viewItemByCode();
								break;
							case 5:	administrator.viewItemNeed();
								break;
							case 0: toReturn = true;
								break;
						}
						
						if(toReturn == true)
						{
							break;
						}
					}
				}
					break;
				case 2: 
				{
					while(1)
					{
						system("cls");
						
						int option;
						bool toReturn = false;
						
						cout<<"1 - Add Employee\n"; 
						cout<<"2 - Remove Employee\n";
						cout<<"3 - Modify Employee Data\n";
						cout<<"4 - Show Employee Data\n";
						cout<<"0 - Return\n\n";
			
						do {
							cout<<"Enter Option: ";
							cin>>option;
						} while(option<0 || option>4);
					
						fflush(stdin);
						system("cls");
						
						switch(option)
						{
							case 1: administrator.addEmployee();
								break;
							case 2: administrator.removeEmployee();
								break;
							case 3: administrator.modifyEmployeeData();
								break;
							case 4: administrator.showEmployees();
								break;
							case 0: toReturn = true;
								break;
						}
						
						if(toReturn == true)
						{
							break;
						}
					}
				}
					break;
				case 3:
				{
					while(1)
					{
						system("cls");
						
						int option;
						bool toReturn = false;
						
						cout<<"1 - Add Admin\n"; 
						cout<<"2 - Remove Admin\n";
						cout<<"3 - Modify Admin Data\n";
						cout<<"4 - View Personal Information\n";
						cout<<"0 - Return\n\n";
			
						do {
							cout<<"Enter Option: ";
							cin>>option;
						} while(option<0 || option>4);
					
						fflush(stdin);
						system("cls");
						
						switch(option)
						{
							case 1: administrator.addAdmin();
								break;
							case 2: administrator.removeAdmin();
								break;
							case 3: administrator.modifyAdminData();
								break;
							case 4: administrator.show();
								break;
							case 0: toReturn = true;
								break;
						}
						
						if(toReturn == true)
						{
							break;
						}
					}
				}
					break;	
				case 4: administrator.dealCustomer();
					break;
				case 5: administrator.viewLogs();
					break;
				case 6: administrator.viewSales();
					break;
				case 7: system("cls"); cout<<"By 19K-0368, 19K-1310, 19K-0359."; Sleep(3000); exit(1);
					break;
			}
		}
	}
	
	static void employeeUI(Employee employee)
	{
		while(1)
		{
			system("cls");
			int option;
			cout<<"1 - Deal Customer\n";
			cout<<"2 - View Item by Barcode\n";
			cout<<"3 - View Personal Information\n";
			cout<<"4 - Exit\n";
			cout<<"0 - Logout\n\n";
		
			do {
				cout<<"Enter Option: ";
				cin>>option;
			} while(option<0 || option>4);
			
			fflush(stdin);
			system("cls");
			switch(option)
			{
				case 0: return;
					break;
				case 1: employee.dealCustomer();
					break;
				case 2: employee.viewItemByCode();
					break;
				case 3: employee.show(); 
					break;
				case 4: system("cls"); cout<<"By 19K-0368, 19K-1310, 19K-0359."; Sleep(3000); exit(1);
					break;
			}
		}
	}

};

int main() {

	Interface::firstLogin();		
	Interface::selectUI();
}


