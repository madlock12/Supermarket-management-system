/*Group Members: 19K-0368, 19K-1310, 19K-0359*/
/*DO NOT COMPILE (main not present)! Compile "main.cpp" only*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

#define array_size_fifty 50
#define array_size_twenty 20
#define array_size_thirty 30
#define array_size_hundred 100
#define array_size_twelve 12
#define item_quantity_reminder_limit 0


int strcmpi(const  char* str1 , const char* str2)
{
    int areEqual = 1;

    while(*str1!='\0' || *str2!='\0')
    {
        if(toupper(*str1) != toupper(*str2))
        {
            areEqual = 0;
        }

        str1++;
        str2++;
    }

    return areEqual;
}

class Item {

    char barVal[array_size_thirty]; //barcode value
    char brandName[array_size_thirty];
    char name[array_size_thirty];
    int stockQuantity;
    float price;

public:

    Item(const char (&barVal)[array_size_thirty], const char (&brandName)[array_size_thirty], const char (&name)[array_size_thirty], const int stockQuantity, const float price)
    {
        strcpy(this->barVal,barVal);
        strcpy(this->brandName,brandName);
        strcpy(this->name,name);
        this->stockQuantity = stockQuantity;
        this->price = price;
    }

    Item(){}

    void setBarVal(const char (&barVal)[array_size_thirty])
    {
        strcpy(this->barVal,barVal);
    }

    void setBrandName(const char (&brandName)[array_size_thirty])
    {
        strcpy(this->brandName,brandName);
    }

    void setName(const char (&name)[array_size_thirty])
    {
        strcpy(this->name,name);
    }

    void setStockQuantity(const int stockQuantity)
    {
        this->stockQuantity = stockQuantity;
    }

    void setPrice(const float price)
    {
        this->price = price;
    }

    const char* const getBarVal()
    {
        return barVal;
    }

    const char* const getBrandName()
    {
        return brandName;
    }

    const char* const getName()
    {
        return name;
    }

    int getStockQuantity() const
    {
        return stockQuantity;
    }

    float getPrice() const
    {
        return price;
    }

    void print()
    {
        cout<<"Name= "<<name;
        cout<<"\nBarcode Value: "<<barVal;
        cout<<"\nBrand Name: "<<brandName;
        cout<<"\nStock Quantity: "<<stockQuantity;
        cout<<"\nprice= "<<price;
    }

	friend ostream& operator << (ostream &os, Item &item);

    void operator = (const Item &item)
    {
        strcpy(this->barVal,barVal);
        strcpy(this->brandName,brandName);
        strcpy(this->name, name);
        this->stockQuantity = stockQuantity;
        this->price = price;
    }
};
//--------------------------------------------------------------------------------------------------
class Person
{
	protected:
		
		char username[array_size_thirty];
    	char name[array_size_fifty];
    	char password[array_size_thirty];
    	char gender;
    	char phoneNumber[array_size_twelve];
    	char address[array_size_hundred];
    	bool adminCheck;

		struct cartItem {//this is used for coustomers input
    		
			char barVal[array_size_thirty];
    		char name[array_size_thirty];
    		int quantity;
    		float price;
    		
		};
		
		struct actionLog {
			
			char username1[array_size_thirty];
			int action;
			char username2[array_size_thirty];
			
		};
		
		struct sale {
			
			char seller[array_size_thirty];
			cartItem item;
		};
	
public:
	
	Person(const char (&username)[array_size_thirty], const char (&password)[array_size_thirty], const char (&name)[array_size_fifty], const char gender, const char (&phoneNumber)[array_size_twelve], const char (&address)[array_size_hundred], const bool adminCheck)
    {
        strcpy(this->username,username);
        strcpy(this->password,password);
        strcpy(this->name,name);
        this->gender = gender;
        strcpy(this->phoneNumber,phoneNumber);
        strcpy(this->address, address);
        this->adminCheck = adminCheck;
    }
	    
    Person() {}
    
    const char* const getUsername()
	{
		return username;
	}
	
	virtual void show()=0;//pure virtual

    void setUsername(const char (&username)[array_size_thirty])
    {
        strcpy(this->username,username);
    }

    void setPassword(const char (&password)[array_size_thirty])
    {
        strcpy(this->password,password);
    }

    void setName(const char (&name)[array_size_fifty])
    {
        strcpy(this->name,name);
    }

    void setGender(const char gender)
    {
        this->gender = gender;
    }

    void setPhoneNumber(const char (&phoneNumber)[array_size_twelve])
    {
        strcpy(this->phoneNumber,phoneNumber);
    }

    void setAddress(const char (&address)[array_size_hundred])
    {
        strcpy(this->address,address);
    }

    void setAdminCheck(const bool adminCheck)
    {
        this->adminCheck = adminCheck;
    }

    const char* const getPassword()
    {
        return password;
    }

    const char* const getName()
    {
        return name;
    }

    char getGender() const
    {
        return gender;
    }

    const char* const getPhoneNumber()
    {
        return phoneNumber;
    }

    const char* const getAddress()
    {
        return address;
    }

    bool getAdminCheck()
    {
        return adminCheck;
    }
    
	static int securePasswordInput(char (&password)[array_size_thirty])
	{
		fflush(stdin);
		
		for(int i = 0 ; i < array_size_thirty ; i++) //to reset the array/
		{
			password[i] = '\0';
		}
		
		char ch;
		
		vector<char>passwordInput;
		
		int chCount = 0;
		
		while(1)
		{	
			ch = getch();
					
			if(ch == 0 || ch == -32)
			{
				ch = getch();
				continue;
			}
			
			if((chCount == array_size_thirty-1 && ch!=8 && ch!=13) || ch == 9)
			{
				continue;
			}		
				
			if(ch==8 && chCount>0)
			{
				cout<<"\b";
				cout<<" ";
				cout<<"\b";
				chCount--;
				passwordInput.pop_back();
			}
			else if(ch==13)
			{
				break;
			}	
			else if(ch!=8)
			{
				passwordInput.push_back(ch);
				cout<<"*";
				chCount++;
			}
		}
	
		if(passwordInput.size() == 0)
		{
			return -1;
		}
	
		for(int  i = 0 ; i < passwordInput.size() ; i++)
		{
			password[i] = passwordInput[i];
		}
		
		return 1;
	}
    
    void addToSales(vector <cartItem> &itemList)
    {
    	ofstream fout;
    	fout.open("sales.bin",ios::app);
    	
    	if(!fout)
    	{
    		cout<<"Error adding sales";
			return;
		}
		
		int listSize = itemList.size();
		
		sale sales;
		
		strcpy(sales.seller,getUsername());
		
		for(int i = 0; i < listSize ; i++)
		{
			strcpy(sales.item.barVal, itemList[i].barVal);
			strcpy(sales.item.name, itemList[i].name);
			sales.item.quantity = itemList[i].quantity;
			sales.item.price = itemList[i].price;	
			
			fout.write((char*)&sales,sizeof(sale));
		}
		
		fout.close();		
	}
    
    void addToNeed(Item &item)
    {
    	if(item.getStockQuantity() > item_quantity_reminder_limit)
    	{
    		cout<<"\nItem minimum quantity present already.";
    		return;
		}
		
		ofstream fout;
		fout.open("need.bin",ios::app);
				
		if(!fout)
		{
			cout<<"\nError performing action";
			exit(-1);
		}
		
		fout<<item.getBarVal()<<endl<<item.getBrandName()<<endl<<item.getName()<<endl;
		fout.close();
			
		return;			
	}
	
	void viewItemByCode()
	{
		system("cls");
		
		char barVal[array_size_thirty];
		cout<<"Enter Barcode: ";
		cin.getline(barVal,array_size_thirty);
		
		ifstream fin;
		
		fin.open("stock.bin");
		
		if(!fin)
		{
			cout<<"\nError reading stock";
			cout<<"\nPress any key to return...";
    		getch();
			return;
		}
		
		Item forRead;
		bool isPresent = false;
		
		while(fin.read((char*)&forRead,sizeof(Item)))
		{
			if(strcmp(barVal,forRead.getBarVal()) == 0)
			{
				cout<<endl<<forRead;
				isPresent = true;
			}
		}
		
		if(isPresent == false)
		{
			cout<<"\nItem not found!";
		}
		
		cout<<"\nPress any key to return";
		getch();
		Sleep(1);
		return;
		
	}

	void addItemToCart(vector <cartItem> &itemList)
    {
    	ifstream fin;
    	fin.open("stock.bin");

    	if(!fin)
    	{
    		cout<<"\nError obtaining stock! Please contact administrator.";
    		exit(-1);
		}

		cartItem item;
		fflush(stdin);
    	cout<<"\nEnter Barcode Value: ";
    	cin.getline(item.barVal,array_size_thirty);

		bool isPresent = false;

		Item forRead;
		while(fin.read((char*)&forRead,sizeof(Item)))
		{
			if(strcmpi(item.barVal,forRead.getBarVal())==1)
			{
				isPresent = true;
				break;
			}
		}

		fin.close();

		if(isPresent == false)
		{
			system("cls");
			cout<<"\nItem not found!";
			cout<<"\nPress any key to return...";
			getch();				
			return;
		}

		system("cls");

		forRead.print();
		cout<<"\n";

		do {
			cout<<"\nEnter Quantity: ";
			cin>>item.quantity;
		} while(item.quantity<0 || item.quantity>forRead.getStockQuantity());

		if(item.quantity == 0)
		{
			return;
		}

		int listSize = itemList.size();
		int indexHolder;
		isPresent = false;

		for(int i = 0 ; i < listSize ; i++)
		{
			if(strcmp(itemList[i].barVal,item.barVal)==0)
			{
				if(itemList[i].quantity == forRead.getStockQuantity() || itemList[i].quantity+item.quantity > forRead.getStockQuantity())
				{
					cout<<"\nExceeding stock quantity!";
					cout<<"\nPress any key to return...";
					getch();					
					return;
				}

				item.quantity += itemList[i].quantity;
				isPresent = true;
				indexHolder = i;
			}
		}

		strcpy(item.name,forRead.getName());
		item.price = forRead.getPrice();

		if(isPresent == true)
		{
			itemList[indexHolder] = item;
		}
		else
		{
			itemList.push_back(item);
		}

		cout<<"\nItem added successfully!";
		Sleep(2000);

		return;
	}

	void showItemList(vector <cartItem> &itemList)
	{
		system("cls");
		
		int listSize = itemList.size();

		if(listSize == 0)
		{
			cout<<"\nCart is empty!";
			return;
		}

		float totalBill = 0;
		
		cout<<endl;
		
		for(int i = 0 ; i < listSize ; i++)
		{
			cout<<i+1<<". "<<itemList[i].name<<"---"<<itemList[i].quantity<<"---"<<itemList[i].price<<"$"<<" = "<<itemList[i].quantity*itemList[i].price<<"$\n";
			totalBill += itemList[i].price*itemList[i].quantity;
		}

		cout<<"\n----------------------------------------\n\t\t\tTotal: "<<totalBill<<"$";

		return;
	}


	void removeFromCart(vector <cartItem> &itemList)
	{
		int listSize = itemList.size();

		if(listSize == 0)
		{
			cout<<"\nCart is empty!";
			return;
		}

		showItemList(itemList);
		cout<<endl<<endl<<endl;

		int itemSelect;

		do {
			cout<<"Enter Item No. to remove: ";
			cin>>itemSelect;
		} while(itemSelect<1 || itemSelect>listSize);

		--itemSelect;

		int quantity;

		do{
			cout<<"Enter quantity to remove: ";
			cin>>quantity;
		} while(quantity<0 || quantity>itemList[itemSelect].quantity);
		
		if(quantity==0)
		{
			return;
		}

		if(quantity == itemList[itemSelect].quantity)
		{
			itemList.erase(itemList.begin()+itemSelect);
		}
		else
		{
			itemList[itemSelect].quantity -= quantity;
		}	
		
		cout<<endl<<quantity<<" "<<itemList[itemSelect].name<<" removed!";
		cout<<"\nPress any key to return...";
		getch();				
		return;
	}

	void printBill(vector <cartItem> &itemList)
	{
		int listSize = itemList.size();

		if(listSize  == 0)
		{
			cout<<"\nCart is empty!";
			return;
		}

		showItemList(itemList);

		char confirmPrint;

		do {
			cout<<"\nPrint Bill? (Y/N): ";
			cin>>confirmPrint;
		} while((!(confirmPrint == 'Y' || confirmPrint == 'y' || confirmPrint == 'N' || confirmPrint == 'n')));

		if(confirmPrint == 'N' || confirmPrint == 'n')
		{
			return;
		}

		Item forRead;

		for(int i = 0 ; i < listSize ; i++)
		{
			ofstream fout;
			fstream fio;

			fio.open("stock.bin");

			if(!fio)
			{
				cout<<"\nError updating stock!";
				return;
			}

			fout.open("temp.bin",ios::app);

			while(fio.read((char*)&forRead,sizeof(Item)))
			{
				if(strcmp(itemList[i].barVal,forRead.getBarVal()) == 0)
				{
					forRead.setStockQuantity(forRead.getStockQuantity() - itemList[i].quantity);

					if(forRead.getStockQuantity() == 0)
					{
						addToNeed(forRead);
						continue;
					}
				}

				fout.write((char*)&forRead,sizeof(Item));
			}

			fout.close();
			fio.close();
			remove("stock.bin");
			rename("temp.bin","stock.bin");
		}
		
		system("cls");
		
		showItemList(itemList);
		
		addToSales(itemList);
		
		cout<<"\n\nPress any key to get return...";
		getch();
		
		itemList.clear();
	}


    void dealCustomer()
    {
    	vector <cartItem> itemList;

    	while(1)
    	{
    		system("cls");
    		cout<<"1. Add Item to Cart"
				<<"\n2. Remove Item from Cart"
				<<"\n3. Show Item(s)"
				<<"\n4. Print Bill"
				<<"\n0. Return\n";
    		int menuSelect;

    		do{
    			cout<<"\nOption: ";
				cin>>menuSelect;
			} while(menuSelect<0 || menuSelect>4);

			switch(menuSelect)
			{
				case 1: addItemToCart(itemList); 
					break;
				case 2: removeFromCart(itemList);
					break;
				case 3: { showItemList(itemList); cout<<"\n\nPress any key to return..."; getch(); }
					break;
				case 4: printBill(itemList);
					break;
				case 0: return;
					break;
			}

		}
	}
	
	void viewStock()
	{
		ifstream fin;
		
		Item forRead;
		
		fin.open("stock.bin");
		
		if(!fin)
		{
			cout<<"\nNo stocks found!";
			cout<<"\nPress any key to return...";
			getch();
			return;
		}
		
		int itemCount = 1;
		
		bool isPresent = false;
		
		while((fin.read((char*)&forRead,sizeof(Item))))
		{
			isPresent = true;
			cout<<"\xB0"<<itemCount<<"\xB0"<<endl;
			cout<<forRead<<endl;
			++itemCount;
		}
		
		if(isPresent == false)
		{
			cout<<"\nStock is empty";
		}
		
		cout<<"\nPress any key to return...";
    	getch();
		
		return;		
	}

};

class Employee : public Person {

public:
 	
	void show()
	{
		cout<<"Username: "<<username
			<<"\nGender: "<<gender
			<<"\nAddress: "<<address
			<<"\nName: "<<name
			<<"\nDesignation: Employee"
			<<"\nPhone Number: "<<phoneNumber;
		cout<<"\n\nPress any key to continue..."; 
		getch();
	}

    friend istream &operator >> (istream &is, Employee &employee);
    friend ostream &operator << (ostream &os, Employee &employee);

};

class Administrator: public Person {

public:
    
    Administrator(const char (&username)[array_size_thirty], const char (&password)[array_size_thirty], const char (&name)[array_size_fifty], const char gender, const char (&phoneNumber)[array_size_twelve], const char (&address)[array_size_hundred], const bool adminCheck):Person(username,password,name,gender,phoneNumber,address,adminCheck)
    {}
    
    Administrator() {}
    
	void show()
	{
		cout<<"Username: "<<username
			<<"\nGender: "<<gender
			<<"\nAddress: "<<address
			<<"\nName: "<<name
			<<"\nDesignation: Admininstrator"
			<<"\nPhone Number: "<<phoneNumber;
		cout<<"\n\nPress any key to continue..."; 
		getch();
	}
	
	void logAction(const actionLog &toWrite)
	{
		ofstream fout;
		fout.open("logs.bin",ios::app);
		if(!fout)
		{
			cout<<"\nError writing log";
			return;
		}
		
		fout.write((char*)&toWrite,sizeof(actionLog));
		fout.close();
	}
	
	void viewSales()
	{
		ifstream fin;
		
		fin.open("sales.bin");
		
		if(!fin)
		{
			cout<<"No sales found";
			cout<<"\nPress any key to return...";
			getch();
			return;
		}
	
		sale sales;
		
		char username[array_size_thirty];
		
		int saleCount = 0;
		
		while(fin.read((char*)&sales,sizeof(sale)))
		{
			saleCount++;
			
			cout<<sales.seller<<" sold "<<sales.item.quantity<<" ["<<sales.item.barVal<<"]"<<" "<<sales.item.name<<" @ "<<sales.item.price<<"$."<<endl;
		}
		
		cout<<"\nPress any key to return...";
		getch();
		return;
	}
	
	void viewLogs()
	{
		ifstream fin;
		fin.open("logs.bin");
		
		if(!fin)
		{
			cout<<"Error obtaining logs!";
			cout<<"\nPress any key to continue...";
			getch();
			return;
		}
		
		actionLog toRead;
		
		while(fin.read((char*)&toRead,sizeof(actionLog)))
		{	
			cout<<"[Admin] "<<toRead.username1;
			
			if(toRead.action == 1)  //1 is for addition of employee, -1 is for removal, similarly 2 is for addition of admin, while -2 is for removal/
			{
				cout<<" added [Employee] ";
			}
			else if(toRead.action == 2)
			{
				cout<<" added [Admin] ";
			}
			else if(toRead.action == -1)
			{
				cout<<" removed [Employee] ";
			}
			else if(toRead.action == -2)
			{
				cout<<" removed [Admin] ";
			}
			
			cout<<toRead.username2<<endl;
		}
		
		fin.close();
		
		cout<<"\n\nPress any key to return...";
		getch();
		
		return;
	}
	
	
	static int checkUsernameAvailability(const char (&username)[array_size_thirty])
    {
    	ifstream fin;
    	fin.open("employee.bin");
    	
    	int isAvailable = 1;

    	if(!fin)
    	{
			return isAvailable;
		}
		
		Employee forRead;

		while(fin.read((char*)&forRead,sizeof(Employee)))
		{
			if(strcmpi(username,forRead.getUsername()) == 1)
			{
				isAvailable = 0;
			}
		}
		
		fin.close();
		
		fin.open("admin.bin");
		
		if(!fin)
    	{
    		return isAvailable;
		}
		
		Administrator forRead1;
		
		while((fin.read((char*)&forRead1,sizeof(Administrator))))
		{
			if(strcmpi(username,forRead1.username) == 1)
			{
				isAvailable = 0;
			}
		}
		
		return isAvailable;
	}
    
    friend istream &operator >> (istream &is, Administrator &administrator);
    friend ostream &operator << (ostream &os, Administrator &administrator);

    void addToStock()//godaam
    {
		char barVal[array_size_thirty];
		cout<<"Enter Barcode Value: ";
		cin.getline(barVal,array_size_thirty);
		
		Item item;
		item.setBarVal(barVal);
		
		ifstream fin;
		ofstream fout;
		
		char brandName[array_size_thirty];
		char name[array_size_thirty];
		int stockQuantity;
		float price;
		
		fin.open("stock.bin");
		
		if(!fin)
		{
			fout.open("stock.bin",ios::app);
			
			if(!fout)
			{
				cout<<"\nError reading stock";
				cout<<"\nPress any key to return...";
    			getch();
				return;
			}
			else
			{
				cout<<"Enter Brand Name: ";
				cin.getline(brandName,array_size_thirty);
				cout<<"Enter Item Name: ";
				cin.getline(name,array_size_thirty);
				fflush(stdin);
				do{
					cout<<"Enter Stock Quantity: ";
					cin>>stockQuantity;
				}while (stockQuantity<0);
				do{
					cout<<"Enter Price: ";
					cin>>price;
				} while (price<0);
				item.setBrandName(brandName);
				item.setName(name);
				item.setStockQuantity(stockQuantity);
				item.setPrice(price);
				
				fout.write((char*)&item,sizeof(Item));
				fout.close();
				cout<<"\nStock updated successfully!";
				cout<<"\nPress any key to return...";
    			getch();
				return;
			}
		}
		
		fout.open("temp.bin",ios::app);
		
		bool isPresent = false;
		Item forRead;
		
		while(fin.read((char*)&forRead,sizeof(Item)))
		{
			if(strcmp(forRead.getBarVal(),item.getBarVal()) == 0)
			{
				isPresent = true;
				do{
					cout<<"\nEnter Quantity to add: ";
					cin>>stockQuantity;
				}while (stockQuantity<0);
		
				forRead.setStockQuantity(forRead.getStockQuantity()+stockQuantity);
			}
			
			fout.write((char*)&forRead,sizeof(Item));
		}
		
		if(isPresent == false)
		{
			cout<<"Enter Brand Name: ";
			cin.getline(brandName,array_size_thirty);
			cout<<"Enter Item Name: ";
			cin.getline(name,array_size_thirty);
			fflush(stdin);
			do{
				cout<<"Enter Stock Quantity: ";
				cin>>stockQuantity;
			}while (stockQuantity<0);
			
			do{
				cout<<"Enter Price: ";
				cin>>price;
			}while (price<0);
			item.setBrandName(brandName);
			item.setName(name);
			item.setStockQuantity(stockQuantity);
			item.setPrice(price);
			
			fout.write((char*)&item,sizeof(Item));
			
			removeFromNeed(item);	
		}
		
		fout.close();
		fin.close();
		remove("stock.bin");
		rename("temp.bin","stock.bin");
		cout<<"\nStock updated successfully!";
		cout<<"\nPress any key to return...";
    	getch();
		return;
    }
    
    void viewItemNeed()
    {
    	ifstream fin;
    	
    	fin.open("need.bin");
    	
    	if(!fin)
    	{
    		cout<<"Error performing action!";
    		cout<<"\nPress any key to continue...";
    		getch();
    		return;
		}
		
		char barVal[array_size_thirty];
		char brandName[array_size_thirty];
		char name[array_size_thirty];
		
		int i = 0;
		
		bool isPresent = false;
		
		while(fin>>barVal>>brandName>>name)
		{
			isPresent = true;
			i++;
			cout<<"\xB0"<<i<<"\xB0"<<endl;
			cout<<"Barcode Value: "<<barVal
			<<"\nBrand Name: "<<brandName
			<<"\nName: "<<name<<endl<<endl;
		}
		
		fin.close();
		
		if(isPresent == false)
		{
			cout<<"\nNo item needed!";
		}
		
		cout<<"\nPress any key to continue...";
		getch();
		
		return;
	}
	
	void removeFromNeed(Item &item)
	{
		ifstream fin;
		fin.open("need.bin");
		
		if(!fin)
		{
			return;
		}
		
		if(item.getStockQuantity()<item_quantity_reminder_limit)
		{
			fin.close();
			return;
		}
		
		char barVal[array_size_thirty];
		char brandName[array_size_thirty];
		char name[array_size_thirty];
		
		ofstream fout;
		
		fout.open("tempNeed.bin");
		
		if(!fout)
		{
			cout<<"\nError performing action!";
			exit(-1);
		}
		
		while(fin>>barVal>>brandName>>name)
		{
			if(strcmp(barVal,item.getBarVal()) == 0)
			{
				continue;
			}
			
			fout<<barVal<<brandName<<name<<endl;
		}
		
		fout.close();
		fin.close();
		
		remove("need.bin");
		rename("tempNeed.bin","need.bin");
		
		return;
	}
    
    void modifyEmployeeData()
    {
    	char username[array_size_thirty];
    	cout<<"Enter Username: ";
    	cin.getline(username,array_size_thirty);
    	while(1)
		{	
    		ifstream fin;
    		fin.open("employee.bin");
    	
    		if(!fin)
    		{
    			cout<<"\nError obtaining Employee record(s).";
    			cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			Employee toModify;
			char usernameHolder[array_size_thirty];
		
			bool isPresent = false;
			bool dataCheck = false;
		
			while((fin.read((char*)&toModify,sizeof(Employee))))
			{
				dataCheck = true;
			
				if(strcmpi(username,toModify.getUsername()) == 1)
				{
					isPresent = true;
					strcpy(usernameHolder,toModify.getUsername());
					break;
				}
			}
		
			fin.seekg(ios::beg);
		
			if(dataCheck == false)
			{
				cout<<"\nNo record Employee record found!";
    			cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			if(isPresent == false)
			{
				cout<<"\nNo record with Username \""<<username<<"\" found!";
				cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			system("cls");
		
			cout<<toModify<<endl;
		
			cout<<"\n1- Change Password\n";
			cout<<"2- Change Name\n";
			cout<<"3- Change Gender\n";
			cout<<"4- Change Phone Number\n";
			cout<<"5- Change Address\n";
			cout<<"0- Return to menu\n";
		
			int modifySelect;
			
			fflush(stdin);
			do{
				cout<<"\nEnter Option: ";
				cin>>modifySelect;
			} while(modifySelect<0 || modifySelect>5);
			
			fflush(stdin);
			
			switch(modifySelect)
			{
				case 0: return;
					break;
				case 1: {char password[array_size_thirty]; do { cout<<"Enter New Password: "; int passInputCheck = toModify.securePasswordInput(password); if(passInputCheck == 1) { break; } else { cout<<endl; }} while(1); toModify.setPassword(password); cout<<endl;}
					break;
				case 2: {char name[array_size_fifty]; cout<<"\nEnter Name: "; cin.getline(name,array_size_fifty); toModify.setName(name);}
					break;
				case 3: {char gender; do { cout<<"\nEnter Gender [M/F]: "; cin>>gender; } while(!(gender=='F' || gender=='f' || gender=='M' || gender=='m')); if(gender=='f' || gender=='m') {gender = toupper(gender);} toModify.setGender(gender);}
					break;
				case 4: {char phoneNumber[array_size_twelve]; cout<<"\nEnter Phone Number: "; cin.getline(phoneNumber,array_size_twelve); toModify.setPhoneNumber(phoneNumber);}
					break;
				case 5: {char address[array_size_hundred]; cout<<"\nEnter Address: "; cin.getline(address,array_size_hundred); toModify.setAddress(address);}
					break;
			}
			
			ofstream fout;
			
			fout.open("tempEmp.bin",ios::app);
		
			if(!fout)
			{
				cout<<"\nError performing action!";
				cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			Employee toReadWrite;
		
			while((fin.read((char*)&toReadWrite,sizeof(Employee))))
			{
				if(strcmpi(toReadWrite.getUsername(),usernameHolder)==1)
				{	
					fout.write((char*)&toModify,sizeof(Employee));
					continue;
				}		
			
				fout.write((char*)&toReadWrite,sizeof(Employee));
			}
		
			fout.close();
			fin.close();
		
			remove("employee.bin");
			rename("tempEmp.bin","employee.bin");
		
			cout<<"\nEmployee data modified successfully!";
			Sleep(2000);
		}
	}
	
	void modifyAdminData()
    {
    	char username[array_size_thirty];
    	cout<<"Enter Username: ";
    	cin.getline(username,array_size_thirty);
    	while(1)
		{	
    		ifstream fin;
    		fin.open("admin.bin");
    	
    		if(!fin)
    		{
    			cout<<"\nError obtaining Admin record(s).";
    			cout<<"\nPress any key to return...";
    			getch();
			}
		
			Administrator toModify;
			char usernameHolder[array_size_thirty];
		
			bool isPresent = false;
			bool dataCheck = false;
		
			while((fin.read((char*)&toModify,sizeof(Administrator))))
			{
				dataCheck = true;
			
				if(strcmpi(username,toModify.getUsername()) == 1)
				{
					isPresent = true;
					strcpy(usernameHolder,toModify.getUsername());
					break;
				}
			}
		
			fin.seekg(ios::beg);
		
			if(dataCheck == false)
			{
				cout<<"\nNo record Admin record found!";
    			cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			if(isPresent == false)
			{
				cout<<"\nNo record with Username \""<<username<<"\" found!";
				cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			system("cls");
		
			cout<<toModify<<endl;
		
			cout<<"\n1- Change Password\n";
			cout<<"2- Change Name\n";
			cout<<"3- Change Gender\n";
			cout<<"4- Change Phone Number\n";
			cout<<"5- Change Address\n";
			cout<<"0- Return to menu\n";
		
			int modifySelect;
			
			fflush(stdin);
			do{
				cout<<"\nEnter Option: ";
				cin>>modifySelect;
			} while(modifySelect<0 || modifySelect>5);
			
			fflush(stdin);
			
			switch(modifySelect)
			{
				case 0: return;
					break; 
				case 1: {char password[array_size_thirty]; do { cout<<"Enter New Password: "; int passInputCheck = toModify.securePasswordInput(password); if(passInputCheck == 1) { break; } else { cout<<endl; }} while(1); toModify.setPassword(password); cout<<endl;}
					break;
				case 2: {char name[array_size_fifty]; cout<<"\nEnter Name: "; cin.getline(name,array_size_fifty); toModify.setName(name);}
					break;
				case 3: {char gender; do { cout<<"\nEnter Gender [M/F]: "; cin>>gender; } while(!(gender=='F' || gender=='f' || gender=='M' || gender=='m')); if(gender=='f' || gender=='m') {gender = toupper(gender);} toModify.setGender(gender);}
					break;
				case 4: {char phoneNumber[array_size_twelve]; cout<<"\nEnter Phone Number: "; cin.getline(phoneNumber,array_size_twelve); toModify.setPhoneNumber(phoneNumber);}
					break;
				case 5: {char address[array_size_hundred]; cout<<"\nEnter Address: "; cin.getline(address,array_size_hundred); toModify.setAddress(address);}
					break;
			}
			
					
			ofstream fout;
			
			fout.open("tempAdmin.bin",ios::app);
		
			if(!fout)
			{
				cout<<"\nError performing action!";
				cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			Employee toReadWrite;
		
			while((fin.read((char*)&toReadWrite,sizeof(Administrator))))
			{
				if(strcmpi(toReadWrite.getUsername(),usernameHolder)==1)
				{	
					fout.write((char*)&toModify,sizeof(Administrator));
					continue;
				}		
			
				fout.write((char*)&toReadWrite,sizeof(Administrator));
			}
		
			fout.close();
			fin.close();
		
			remove("admin.bin");
			rename("tempAdmin.bin","admin.bin");
		
			cout<<"\nAdmin data modified successfully!";
			Sleep(2000);
		}
	}
    
    void modifyFromStock()
    {
		char barVal[array_size_thirty];
    	cout<<"Enter Barcode Value: ";
    	cin.getline(barVal,array_size_thirty);
    	
    	while(1)
		{
    		ifstream fin;
    	
    		fin.open("stock.bin");
    	
    		Item toUpdate;
    	
    		if(!fin)
    		{
    			cout<<"\nError obtaining data from stock.";
    			cout<<"\nPress any key to return...";
    			getch();
    			return;
			}
		
			bool emptyFile = true;
			bool isPresent = false;
		
			while(fin.read((char*)&toUpdate,sizeof(Item)))
			{
				emptyFile = false;
			
				if(strcmp(barVal,toUpdate.getBarVal()) == 0)
				{
					isPresent = true;
					break;
				}
			}			
		
			fin.close();
		
			if(emptyFile == true)
			{
				cout<<"\nStock is empty!";
				cout<<"\nPress any key to return...";
    			getch();
				return;
			}
		
			if(isPresent == false)
			{
				cout<<"\nItem "<<toUpdate.getBarVal()<<" not found!";
				cout<<"\nPress any key to return...";
    			getch();
				return;
			}
		
			system("cls");
			cout<<toUpdate;
		
			cout<<"\n1- Change Brand Name\n";
			cout<<"2- Change Item Name\n";
			cout<<"3- Modify Stock Quantity\n";
			cout<<"4- Update Price\n";
			cout<<"0- Return to menu\n";
		
			int updateMenuSelect;
		
			do {
				cout<<"\nEnter Option: ";
				cin>>updateMenuSelect;
			} while(updateMenuSelect<0 || updateMenuSelect>4);
	
			fflush(stdin);
			switch(updateMenuSelect)
			{
				case 0: return;
					break;
				case 1: { char brandName[array_size_thirty]; cout<<"Enter Brand Name: "; cin.getline(brandName,array_size_thirty); toUpdate.setBrandName(brandName); }
					break;
				case 2: { char name[array_size_thirty]; cout<<"Enter Item Name: "; cin.getline(name,array_size_thirty); toUpdate.setName(name); }
					break;
				case 3: { int stockQuantity; do{ cout<<"Enter Stock Quantity: "; cin>>stockQuantity;} while(stockQuantity<0); toUpdate.setStockQuantity(stockQuantity); }
					break;
				case 4: { float price; do{cout<<"Enter Updated Price: "; cin>>price;}while(price<0); toUpdate.setPrice(price); }
					break;
			}
		
			ofstream fout;
		
			fout.open("temp.bin",ios::app);
		
			if(!fout)
			{
				cout<<"\nError performing action (File Permission)!";
				cout<<"\nPress any key to return...";
    			getch();
				return;
			}
		
			fin.open("stock.bin");
		
			if(!fin)
			{
				fout.close();
				remove("temp.bin");
				cout<<"\nError obtaining stock!";
				cout<<"\nPress any key to return...";
    			getch();
				return;
			}
	
			Item toReadWrite;
		
			while(fin.read((char*)&toReadWrite,sizeof(Item)))
			{
				if(strcmp(toReadWrite.getBarVal(),toUpdate.getBarVal()) == 0)
				{
					if(toUpdate.getStockQuantity() == 0)
					{
						continue;
					}
				
					fout.write((char*)&toUpdate,sizeof(Item));
					continue;	
				}
			
				fout.write((char*)&toReadWrite,sizeof(Item));
			}
		
			fout.close();
			fin.close();
		
			remove("stock.bin");
			rename("temp.bin","stock.bin");
		
			cout<<"\nItem data modified successfully!";
			Sleep(2000);
			
		}
	}
	
	void addAdmin()
	{
		ofstream fout;
		
		fout.open("admin.bin",ios::app);
		
		if(!fout)
		{
			cout<<"\nFile Permission Error!";
			return;
		}
		
		Administrator toAdd;
		cin>>toAdd;
		
		fout.write((char*)&toAdd,sizeof(Administrator));
		fout.close();
		
		actionLog toWrite;
        strcpy(toWrite.username1,getUsername());
        strcpy(toWrite.username2,toAdd.getUsername());
        toWrite.action = 2;
        
        logAction(toWrite);
        
		cout<<"\nAdministrator Added Successfully!";
		cout<<"\nPress any key to return...";
		getch();
		
		return;
	}

    void addEmployee()
    {
        ofstream fout;

        fout.open("employee.bin", ios::app);

        if(!fout)
        {
        	cout<<"\nFile Permission Error!";
        	return;
		}

        Employee toAdd;
        cin>>toAdd;

        fout.write((char*)&toAdd,sizeof(Employee));
        fout.close();
        
        actionLog toWrite;
        strcpy(toWrite.username1,getUsername());
        strcpy(toWrite.username2,toAdd.getUsername());
        toWrite.action = 1;
        
        logAction(toWrite);
        
        cout<<"\nEmployee Added Successfully!";
        cout<<"\nPress any key to return...";
        getch();

        return;
    }
    
    void removeAdmin()
    {
    	char username[array_size_thirty];
    	
    	ifstream fin;
    	
    	ofstream fout;
    	
    	fin.open("admin.bin");
    	
    	if(!fin)
    	{
    		cout<<"\nError Obtaining Admin Record(s).";
    		return;
		}
		
		fout.open("tempAdmin.bin",ios::app);
		
		if(!fout)
		{
			cout<<"\nError performing action.";	
			
			return;
		}
		
		cout<<"Enter username of Administrator: ";
		cin.getline(username,array_size_thirty);
		
		Administrator forReadWrite;
		
		char delConfirmation;
		
		bool isPresent = false;
		
    	while(fin.read((char*)&forReadWrite,sizeof(Administrator)))
    	{
    		if(strcmpi(forReadWrite.getUsername(),username)==1)
    		{
    			isPresent = true;
    			
    			cout<<endl<<forReadWrite<<endl;
				    			
    			do {
    				cout<<"\nComfirm Removal (Y/N): ";
    				cin>>delConfirmation;
				} while(!(delConfirmation =='Y' || delConfirmation =='y' || delConfirmation == 'N' || delConfirmation == 'n'));
    			
    			if(delConfirmation == 'Y' || delConfirmation == 'y')
    			{
    				actionLog toWrite;
        			strcpy(toWrite.username1,getUsername());
        			strcpy(toWrite.username2,forReadWrite.getUsername());
        			toWrite.action = -2;
        
        			logAction(toWrite);
    				continue;
				}
			}
			
			fout.write((char*)&forReadWrite,sizeof(Administrator));
		}
		
		fout.close();
		fin.close();
		
		remove("admin.bin");
		rename("tempAdmin.bin","admin.bin");
		
		if(isPresent == false)
		{
			cout<<"\nNo record with Username: "<<username<<" found!";
			cout<<"\nPress any key to continue...";
			getch();
			return;
		}    
    	
    	cout<<"\nAdmin removed successfully!";
	}
    
    void removeEmployee()
    {
    	char username[array_size_thirty];
    	
    	ifstream fin;
    	
    	ofstream fout;
    	
    	fin.open("employee.bin");
    	
    	if(!fin)
    	{
    		cout<<"\nError Obtaining Employee Record(s).";
    		cout<<"\nPress any key to return...";
			getch();
    		return;
		}
		
		fout.open("tempEmp.bin",ios::app);
		
		if(!fout)
		{
			cout<<"\nError performing action.";
			cout<<"\nPress any key to return...";
			getch();
			return;
		}
		
		cout<<"Enter username of Employee: ";
		cin.getline(username,array_size_thirty);
		
		Employee forReadWrite;
		
		char delConfirmation;
		
		bool isPresent = false;
		
    	while(fin.read((char*)&forReadWrite,sizeof(Employee)))
    	{
    		if(strcmpi(forReadWrite.getUsername(),username)==1)
    		{
    			isPresent = true;
    			
    			cout<<endl<<forReadWrite<<endl;
				    			
    			do {
    				cout<<"\nComfirm Removal (Y/N): ";
    				cin>>delConfirmation;
				} while(!(delConfirmation =='Y' || delConfirmation =='y' || delConfirmation == 'N' || delConfirmation == 'n'));
    			
    			if(delConfirmation == 'Y' || delConfirmation == 'y')
    			{
    				actionLog toWrite;
                    strcpy(toWrite.username1,getUsername());
                    strcpy(toWrite.username2,forReadWrite.getUsername());
                    toWrite.action = -1;
                    logAction(toWrite);
                    
    				continue;
				}
			}
			
			fout.write((char*)&forReadWrite,sizeof(Employee));
		}
		
		fout.close();
		fin.close();
		
		remove("employee.bin");
		rename("tempEmp.bin","employee.bin");
		
		if(isPresent == false)
		{
			cout<<"\nNo record with Username: "<<username<<" found!";
			cout<<"\nPress any key to continue...";
			getch();
			return;
		}    
			
    	cout<<"\nEmployee removed successfully!";
    	cout<<"\nPress any key to return...";
		getch();
    	return;
	}
	
	void showEmployees()
	{
		ifstream fin;
		
		Employee forRead;
		
		fin.open("employee.bin");
		
		if(!fin)
		{
			cout<<"\nError Obtaining Employee Record(s).";
			cout<<"\nPress any key to return...";
			getch();
			return;
		}
		
		int itemCount = 0;
		
		bool dataCheck = false;
		
		while((fin.read((char*)&forRead,sizeof(Employee))))
		{
			itemCount++;
			dataCheck = true;
			cout<<"\xB0"<<itemCount<<"\xB0"<<endl;
			cout<<forRead<<endl<<endl;
		}
		
		if(dataCheck == false)
		{
			cout<<"\nNo record(s) present!";
		}
		
		cout<<"\nPress any key to return...";
		getch();
		
		return;
	}
    
    
};

istream &operator >> (istream &is, Administrator &administrator) {
    
	cout<<"Enter Full Name: ";
    cin.getline(administrator.name,array_size_fifty);

    do {
    	cout<<"Enter Username: ";
    	cin.getline(administrator.username,array_size_thirty);
		int availabilityCheck = -1;
		availabilityCheck = Administrator::checkUsernameAvailability(administrator.username);
    	if(availabilityCheck == 0)
    	{
    		cout<<"-->Username Taken\n";
		}
		else
		{
			break;
		}
	} while(1);
	
	do {
		cout<<"Enter Password: ";
		int passInputCheck = administrator.securePasswordInput(administrator.password);
		if(passInputCheck == 1)
		{
			break;
		}
		else
		{
			cout<<endl;
		}
	} while(1);
	
	do{
		cout<<"\nEnter Gender [M/F]: ";
    	cin>>administrator.gender;	
	} while(!(administrator.gender == 'M' || administrator.gender == 'm' || administrator.gender == 'F' || administrator.gender == 'f'));
	
	if(administrator.gender>96)
	{
		administrator.gender = toupper(administrator.gender);
	}
    
	fflush(stdin);
    cout<<"Enter Phone Number: ";
    cin.getline(administrator.phoneNumber,array_size_twelve);
    cout<<"Enter Address: ";
    cin.getline(administrator.address,array_size_hundred);
    administrator.adminCheck = 1;

    return is;
}

istream &operator >> (istream &is, Employee &employee)
{
    cout<<"Enter Full Name: ";
    cin.getline(employee.name,array_size_fifty);

    do {
    	cout<<"Enter Username: ";
    	cin.getline(employee.username,array_size_thirty);
		int availabilityCheck = -1;
		availabilityCheck = Administrator::checkUsernameAvailability(employee.username);
    	if(availabilityCheck == 0)
    	{
    		cout<<"Username Taken\n";
		}
		else
		{
			break;
		}
	} while(1);

	do {
		cout<<"Enter Password: ";
		int passInputCheck = employee.securePasswordInput(employee.password);
		if(passInputCheck == 1)
		{
			break;
		}
		else
		{
			cout<<endl;
		}
	} while(1);
	
	do{
		cout<<"\nEnter Gender [M/F]: ";
    	cin>>employee.gender;	
	} while(!(employee.gender == 'M' || employee.gender == 'm' || employee.gender == 'F' || employee.gender == 'f'));
	
	if(employee.gender>96)
	{
		employee.gender = toupper(employee.gender);
	}
	
    fflush(stdin);
    cout<<"Enter Phone Number: ";
    cin.getline(employee.phoneNumber,array_size_twelve);
    cout<<"Enter Address: ";
    cin.getline(employee.address,array_size_hundred);
    employee.adminCheck = 0;

    return is;
}

ostream& operator << (ostream &os, Employee &employee)
{
	cout<<"Name: "<<employee.getName();
	cout<<"\nUsername: "<<employee.getUsername();
	cout<<"\nGender: "<<employee.getGender();
	cout<<"\nPhone Number: "<<employee.getPhoneNumber();
	cout<<"\nAddress: "<<employee.getAddress();	
	
	return os;
}

ostream& operator << (ostream &os, Administrator &administrator)
{
	cout<<"Name: "<<administrator.getName();
	cout<<"\nUsername: "<<administrator.getUsername();
	cout<<"\nGender: "<<administrator.getGender();
	cout<<"\nPhone Number: "<<administrator.getPhoneNumber();
	cout<<"\nAddress: "<<administrator.getAddress();	
	
	return os;
}



ostream& operator << (ostream &os, Item &item)
{
	cout<<"Barcode Value: "<<item.getBarVal();
	cout<<"\nBrand Name: "<<item.getBrandName();
	cout<<"\nItem Name: "<<item.getName();
	cout<<"\nStock Quantity: "<<item.getStockQuantity();
	cout<<"\nPrice: "<<item.getPrice()<<"$"<<endl;
	
	return os;
}
