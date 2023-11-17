#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class User;

// ABSTRACT PARENT ROOM

class Rooms
{

	friend class User;

protected:
	char Status;
	double Rent;
	string AcType;
	string Heater;
	string BedSize;
	string RoomSize;
	string FreeWifi;
	string View;
	string RoomUserID;

	void Display()
	{

		cout << "\n\nRoom Size		  \t" << RoomSize << endl;
		cout << "AC/Non Ac	 	  \t" << AcType << endl;
		cout << "Heated/Non Heated 	 \t" << Heater << endl;
		cout << "Bed Size		 \t" << BedSize << endl;
		cout << "Free Wifi		  \t" << FreeWifi << endl;
		cout << "View               	\t" << View << endl;
		cout << "\nRoom Rent  		  \t" << Rent << " PKR per day" << endl;
	}
	virtual void RoomFeatures() = 0;
};

// ROOM TYPE A
class RoomCategoryA : public Rooms
{

public:
	~RoomCategoryA(){}
	RoomCategoryA()
	{
		Rent = 15000;
		AcType = "Air Conditioned";
		Heater = "Electrically Heated";
		BedSize = "King Size Bed";
		RoomSize = "324 sq-ft";
		FreeWifi = "Yes";
		View = "Exotic View of Arabian Sea";
		Status = 'A';
	}

	void RoomFeatures()
	{

		cout << "\n\nThese our the Executive Deluxe Suites harnessed with our best services, " << endl;
		cout << "For this pakcage We offer following FREE services;\n"
			 << endl;
		cout << "- Airport Pick and Drop" << endl;
		cout << "- Executive Lounge Access" << endl;
		cout << "- Health Club Facality Access" << endl;
		cout << "- Butler Service" << endl;
		cout << "- Fitness Faciclity Service" << endl;
		cout << "- Laundary Service" << endl;
	}
	void Display()
	{

		cout << "________________________________________________________________________________________" << endl;
		cout << "Deluxe Suites (CAT-A)" << endl;
		Rooms::Display();
		RoomFeatures();
		cout << "________________________________________________________________________________________" << endl;
	}
};
RoomCategoryA Rooms_A[30];

// Room Cat B
class RoomCategoryB : public Rooms
{

public:
	~RoomCategoryB(){}
	RoomCategoryB()
	{
		Rent = 10000;
		AcType = "Air Conditioned";
		Heater = "Not Heated";
		BedSize = "Dual Bed";
		RoomSize = "164 sq-ft";
		FreeWifi = "Yes";
		View = "City View | Karachi Skyline";
		Status = 'B';
	}

	void RoomFeatures()
	{

		cout << "\n\nThese are the best worth to money rooms offering touch of executive features in relative low price" << endl;
		cout << "For this pakcage We offer following FREE services;\n"
			 << endl;
		cout << "- Health Club Facality Access" << endl;
		cout << "- Butler Service" << endl;
		cout << "- Fitness Faciclity Service" << endl;
	}
	void Display()
	{
		cout << "________________________________________________________________________________________" << endl;
		cout << "Junior Pearl Suite (CAT-B)" << endl;
		Rooms::Display();
		RoomFeatures();
		cout << "________________________________________________________________________________________" << endl;
	}
};
RoomCategoryB Rooms_B[30];

// Room Cat C
class RoomCategoryC : public Rooms
{

public:
	~RoomCategoryC(){}
	RoomCategoryC()
	{
		Rent = 6000;
		AcType = "Non Air Conditioned";
		Heater = "Not Heated";
		BedSize = "Single Bed";
		RoomSize = "162 sq-ft";
		FreeWifi = "No";
		View = "Beach View | Facing the Beach of Karachi";
		Status = 'A';
	}

	void RoomFeatures()
	{

		cout << "\n\nThese are the best budget friendly rooms providing economical facility for budget clients" << endl;
		cout << "For this pakcage We offer following FREE services;\n"
			 << endl;
		cout << "- Fitness Faciclity Service" << endl;
	}
	void Display()
	{
		cout << "________________________________________________________________________________________" << endl;
		cout << "Basic Economy Suite (CAT-C)" << endl;
		Rooms::Display();
		RoomFeatures();
		cout << "________________________________________________________________________________________" << endl;
	}
};
RoomCategoryC Rooms_C[30];

// USER
class User
{
	// attributes
	string Name;
	string ID;
	double Balance;
	string RoomCat;
	int RoomNumber;
	int BookedRooms = 0;
	int Stay;

public:
	~User(){}
	User() {}
	User(string n, string id)
	{
		Name = n;
		ID = id;
	}
	int getStay()
	{
		char s[10];
	askstay:
		cout << "Enter No of days of Stay: ";
		cin >> s;
		Stay = atoi(s);

		if (Stay == 0)
		{
			cout << "Invalid Input!" << endl;
			sleep(1);
			goto askstay;
		}
		else
		{
			return Stay;
		}
	}

	// methods
	void Booking()
	{

	booking:
		string ch;
		system("cls");
		sleep(1);
		Rooms_A[0].Display();
		sleep(1);
		Rooms_B[0].Display();
		sleep(1);
		Rooms_C[0].Display();
		sleep(1);
		cout << "\n\n\n\t\t\t\t\tEnter Category of Room you wish to book: " << endl;
		cin >> ch;
		sleep(1);
		system("cls");

		if (ch == "A")
		{
			Rooms_A[0].Display();

			for (int i = 0; i < 30; i++)
			{
				if (Rooms_A[i].Status == 'A')
				{
					getStay();
					RoomCat = "Category A";
					RoomNumber = i + 1;
					Rooms_A[i].Status = 'B';
					Balance = Rooms_A[i].Rent * Stay;
					Rooms_A[i].RoomUserID = ID;
					break;
				}
			}
			if (Rooms_A[29].Status == 'B')
			{
				cout << "We are Sorry All Deluxe Suite (A) Rooms are booked, You can book from other catogery" << endl;
				sleep(4);
				goto booking;
			};
		}
		else if (ch == "B")
		{
			Rooms_B[0].Display();
			for (int i = 0; i < 30; i++)
			{
				if (Rooms_B[i].Status == 'A')
				{
					getStay();
					RoomCat = "Category B";
					RoomNumber = i + 31;
					Rooms_B[i].Status = 'B';
					Balance = Rooms_B[i].Rent * Stay;
					Rooms_B[i].RoomUserID = ID;
					break;
				}
			}
			if (Rooms_B[29].Status == 'B')
			{
				cout << "We are Sorry All Jr Pearl (B) Rooms are booked, You can book from other catogery" << endl;
				sleep(4);
				goto booking;
			};
		}
		else if (ch == "C")
		{
			Rooms_C[0].Display();
			for (int i = 0; i < 30; i++)
			{
				if (Rooms_C[i].Status == 'A')
				{
					getStay();
					RoomCat = "Category C";
					RoomNumber = i + 61;
					Rooms_C[i].Status = 'B';
					Balance = Rooms_C[i].Rent * Stay;
					Rooms_C[i].RoomUserID = ID;
					break;
				}
			}
			if (Rooms_C[29].Status == 'B')
			{
				cout << "We are Sorry All Jr Pearl (B) Rooms are booked, You can book from other catogery" << endl;
				sleep(4);
				goto booking;
			};
		}
		else
		{
			cout << "Invalid Input" << endl;
			sleep(1);
			goto booking;
		}

		system("cls");
		BookedRooms++;
		ofstream out;
		out.open(ID + ".txt", ios::app);
		out << "________________________________________________" << endl;
		out << "Name:		\t" << Name << endl;
		out << "ID:		\t" << ID << endl;
		out << "________________________________________________" << endl;
		out << "\n*******************************************\n"
			<< endl;

		out << "Booked Room #  " << BookedRooms + 1 << endl;
		out << "Room Category:	\t" << RoomCat << endl;
		out << "Room No:	\t" << RoomNumber << endl;
		out << "Days Of Stay:\t\t" << Stay << endl;
		out << "\nDue for this Booking: \t" << Balance << endl;
		out << "\n*******************************************" << endl
			<< endl;

		out.close();

		string ch2;
		cout << "Do you wish to book anoather room (Y/y)" << endl;
		cin >> ch2;
		if (ch2 == "Y" || ch2 == "y")
		{
			goto booking;
		}
		else cout<<"YOUR BOOKINGS: "<<endl;
	}

	void UserDisplay()
	{

		ifstream in;
		in.open(ID + ".txt");
		string str;
		getline(in, str);

		while (in.eof() == 0)
		{
			getline(in, str);
			cout << str << endl;
		};
		in.close();
	}
};

class Car
{
	string carn, eng, num, t;
	int crent, a;

public:
	void setcar(string ctype, string car)
	{
		if (ctype == "S" || ctype == "s")
		{
			t = "Sedan";
			if (car == "1")
			{
				carn = "Corolla GLI";
				eng = "1300 cc";
				num = "ABC 123";
			}
			else if (car == "2")
			{
				carn = "Corolla Altis";
				eng = "1600 cc";
				num = "ABC 124";
			}
			else if (car == "3")
			{
				carn = "Corolla Grande";
				eng = "1800 cc";
				num = "ABC 125";
			}
		}
		else if (ctype == "H" || ctype == "h")
		{
			t = "Hatchback";
			if (car == "1")
			{
				carn = "Swift GL";
				eng = "1200 cc";
				num = "DEF 134";
			}
			else if (car == "2")
			{
				carn = "Swift GL CVT";
				eng = "1200 cc";
				num = "DEF 135";
			}
			else if (car == "3")
			{
				carn = "Swift GLX CVT";
				eng = "1200 cc";
				num = "DEF 136";
			}
		}
	}
	string gettype()
	{
		return t;
	}
	string getcar()
	{
		return carn;
	}
	string geteng()
	{
		return eng;
	}
	// string num(){
	//	return num;
	// }
	void rent(int day, string id)
	{
		a = day;
		if (t == "Sedan")
		{
			if (carn == "Corolla GLI")
			{
				crent = day * 3500;
			}
			else if (carn == "Corolla Altis")
			{
				crent = day * 4000;
			}
			else if (carn == "Corolla Grande")
			{
				crent = day * 4500;
			}
		}
		else if (t == "Hatchback")
		{
			if (carn == "Swift GL")
			{
				crent = day * 2000;
			}
			else if (carn == "Swift GL CVT")
			{
				crent = day * 2500;
			}
			else if (carn == "Swift GLX CVT")
			{
				crent = day * 3000;
			}
		}
		ofstream out;
		out.open(id + ".txt", ios::app);

		out << "\n______________________________________________________" << endl;
		out << "\nCAR RENT SERVICE" << endl;
		out << "****************\n"
			<< endl;
		out << " Body type: 	\t" << t << endl;
		out << " Car:		\t" << carn << endl;
		out << " Engine capacity:  \t" << eng << endl;
		out << " Number plate:	\t " << num << endl;
		out << " Number of days: \t" << a << endl;
		out << " Total rent: 	\t" << crent << endl;
		out << "______________________________________________________" << endl;
		out.close();
	}
	int getrent()
	{
		return crent;
	}
};

int main()
{

	while (1)
	{

		system("cls");
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t********************************************************************" << endl;

		cout << "\t\t\t\t\t\t********************************************************************" << endl;
		cout << "\t\t\t\t\t\t********************************************************************" << endl;
		cout << "\t\t\t\t\t\t************************** THE OASIS HOTEL *************************" << endl;
		cout << "\t\t\t\t\t\t********************************************************************" << endl;
		cout << "\t\t\t\t\t\t********************************************************************" << endl;
		cout << "\t\t\t\t\t\t********************************************************************" << endl
			 << endl
			 << endl
			 << endl
			 << endl;
		cout << "\t\t\t\t\t\t           ~~~~~~~~ Where the luxury awaits you! ~~~~~~~~" << endl;

		cout << "\t\t\t\t\t\t_____________________________________________________________________\n"
			 << endl;
		cout << "\t\t\t\t\t\tWe provide you the prime luxury experience of majestic life at Oasis" << endl;
		cout << "\t\t\t\t\t\t Taking you to a breath taking journey filled with exotic views and " << endl;
		cout << "\t\t\t\t\t\t     executive service, join us now, The luxury awaits you !" << endl
			 << endl
			 << endl;
		cout << "\t\t\t\t\t\t_____________________________________________________________________" << endl
			 << endl;
		;
		cout << "\t\t\t\t\t\t      			       BOOK NOW                      " << endl;
		system("pause");

		string name, id, ch;
		cout << "\n\n\n\t\t\t\t\t\tEnter your Name: ";
		fflush(stdin);
		getline(cin, name);
		cout << "\t\t\t\t\t\tEnter your ID: ";
		fflush(stdin);
		cin >> id;
		User u(name, id);

	// GOTO LABEL
	choose:
		string ch1;
		system("cls");
		cout << "\n\n\n"<<endl;
		cout << "1) View your Bookings " << endl;
		cout << "2) Book a Package" << endl;
		cout << "3) Rent a car" << endl;
		cout << "5) Log Out" << endl;
		cout << "5) Exit" << endl;
		fflush(stdin);

		cin >> ch;

		if (ch == "1")
		{
			ifstream in;
			string str;
			in.open(id + ".txt");
			getline(in, str);

			if (str == "\0")
			{
				cout << "No Bookings" << endl;
				in.close();
				cout << "Proceed to Bookings (1 | 0)" << endl;
				fflush(stdin);

				cin >> ch1;
				if (ch1 == "1"){
				
					u.Booking();
					u.UserDisplay();
					system("pause");
					goto choose;
				}
				else
					cout << "Invalid Input" << endl;
				system("pause");
				goto choose;
			}
			else
			{
				u.UserDisplay();
				sleep(1);
				system("pause");
				cout << "Proceed to Bookings (1 | 0)" << endl;
				fflush(stdin);

				cin >> ch1;
				if (ch1 == "1")
				{
					u.Booking();
					u.UserDisplay();
					system("pause");
				}
				else if (ch1 == "0")
					goto choose;
				else{
					cout << "Invalid Input" << endl;
				system("pause");
				goto choose;
				}
			}
		}
		else if (ch == "2")
		{
			u.Booking();
			u.UserDisplay();
			system("pause");
			cout << "Logout \t(1)" << endl;
			cout << "Menu   \t(0)" << endl;
			fflush(stdin);
			cin >> ch1;
			if (ch1 == "0")
				goto choose;
			else if (ch1 != "1")
			{

				cout << "Invalid Input" << endl;
				system("pause");
				goto choose;
			}
		}
		else if (ch == "3")
		{
			system("cls");
			string ctype, car;
			char days[5];
			int day;
			Car cobj;
			cout << "______________________________________________________" << endl;
			cout << "Type S for Sedan" << endl;
			cout << " Car\t\t\tRent[1 day]" << endl;
			cout << "1) Corolla GLI\t\t3500" << endl;
			cout << "2) Corolla Altis\t4000" << endl;
			cout << "3) Corolla Grande\t4500" << endl;
			cout << "______________________________________________________" << endl;
			cout << "\n******************************************************" << endl;
			cout << "______________________________________________________" << endl;
			cout << "Type H for Hatchback" << endl;
			cout << " Car\t\t\tRent[1 day]" << endl;
			cout << "1) Swift GL\t\t2000" << endl;
			cout << "2) Swift GL CVT\t\t2500" << endl;
			cout << "3) Swift GLX CVT\t3000" << endl;
			cout << "______________________________________________________" << endl;
		bookCar:
			cin >> ctype;
			if (ctype == "S" || ctype == "s" || ctype == "H" || ctype == "h")
			{
			cartype:
				cout << "Select car:" << endl;
				cin >> car;
				if (car == "1" || car == "2" || car == "3")
				{
					cobj.setcar(ctype, car);
				}
				else
				{
					cout << "Invalid Input!" << endl;
					goto cartype;
				}
			}
			else
			{
				cout << "Invalid Input!" << endl;
				goto bookCar;
			}
		askdays:
			cout << "Enter number of days:" << endl;
			fflush(stdin);
			cin >> days;
			fflush(stdin);
			day = atoi(days);
			if (day == 0)
			{
				cout << "Invalid Input!" << endl;
				goto askdays;
			}
			else
			{
				cout << "DAYSS " << day << endl;
				sleep(1);
				cobj.rent(day, id);
				u.UserDisplay();
				system("pause");
				cout << "Proceed to Bookings (1 | 0)" << endl;
				fflush(stdin);

				cin >> ch1;
				if (ch1 == "1")
				{
					u.Booking();
					u.UserDisplay();
					system("pause");
				}
				else if (ch1 == "0")
					goto choose;
				else
					cout << "Invalid Input" << endl;
				system("pause");
				goto choose;
			}
		}
		else if (ch == "4")
		{
			system("cls");
			cout << "LOGGED OUT" << endl;
			sleep(1);		
		}
		else if (ch == "5")
		{
			cout << "Exited Successfully" << endl;
			exit(1);
		}
		else
		{
			cout << "Invalid Input" << endl;
			sleep(1);
			goto choose;
		}
	};
}