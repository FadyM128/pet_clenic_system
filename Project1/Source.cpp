#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<sstream>
using namespace std;
struct data1 {
	int num;
	string name;
	string type;
	string birth;
	string treat;
	string datatreat;
	string upcoming_treatment;
}pet[20];
bool login()
{
	int b = 0, c = 1;
	bool x = true;
	string UserName = "pet", log;
	char ps[] = "pet1", pa;
	do {
		if ((x == false || UserName != log) && c != 1)
			cout << "\nwrong password or username\n";
		x = true;

		cout << "username\n";
		cin >> log;
		cout << "enter password\n";
		while (true)
		{
			pa = _getch();
			if (pa == '\r') {//To stop when hitting Enter Key \r
				b = 0;
				break;
			}
			cout << "*";
			if (pa != ps[b++])
				x = false;
		}
		c = c + 1;
	} while (x != true || UserName != log);
	if (x == true && UserName == log) {
		cout << "\nsuccesfully logged\n ";
		return true;
	}
}
/*void openfile()
{
	string line; int y = 0;
	ifstream dataofpet;
	istringstream iss;
	dataofpet.open("C:\\Users\\Sigma\\source\\repos\\final\\final\\data.txt");
	if (dataofpet.is_open())
	{
		while (!dataofpet.eof())
		{
			for (int i = 0; i <= 5; i++)
			{
				getline(dataofpet, line, ',');
				if (i == 0)
					pet[y].type = line;
				else if (i == 1)
					pet[y].name = line;
				else if (i == 2)
					pet[y].birth = line;
				else if (i == 3)
					pet[y].treat = line;
				else if (i == 4)
					pet[y].datatreat = line;
				else if (i == 5)
					pet[y].upcoming_treatment = line;
			}y++;
		}
	}
	else { cout << "error"; }
}*/
void openfile() {
	string line; int y = 0;
	ifstream dataofpet;
	istringstream iss;
	dataofpet.open("C:\\Users\\pc\\OneDrive\\Desktop\Project1\Project1data.txt");
	if (dataofpet.is_open()) {
		while (!dataofpet.eof()) {
			iss.clear();
			getline(dataofpet, line);//take line
			iss.str(line);//take word from line 
			iss >> pet[y].type >> pet[y].name >> pet[y].birth >> pet[y].treat >> pet[y].datatreat >> pet[y].upcoming_treatment;
			y++;
		}
	}
	else { cout << "error"; }
}
void add() {
	cin.ignore();
	for (int i = 0; i < 20; i++) {
		if (pet[i].type == "\0") {//check array is empty
			cout << "Enter type your pet : "; getline(cin, pet[i].type);
			cout << "Enter name : "; getline(cin, pet[i].name);
			cout << "Enter date of birth : "; getline(cin, pet[i].birth);
			cout << "Enter treatment : "; getline(cin, pet[i].treat);
			cout << "Enter data of treatment : "; getline(cin, pet[i].datatreat);
			cout << "Enter date of the upcoming treatment : "; getline(cin, pet[i].upcoming_treatment);
			break;
		}
	}
}
void display() {
	int countr = 0;
	for (int i = 0; i < 20; i++) {
		if (pet[i].type != "") {
			if (countr == 0)
			{
				cout << "no.  |    type    |   name     |       birth       |     treatment        |        treatment date          |           upcoming_treatment    \n";
				cout << "==============================================================================================================================================================\n";
			}
			countr++;
			cout << " " << countr << "    |    " << pet[i].type << "    |     " << pet[i].name << "   |    " << pet[i].birth << "      |     " << pet[i].treat << "           |      " << pet[i].datatreat << "                     |           " << pet[i].upcoming_treatment << "\n";
			pet[i].num = countr;
		}
		else { break; }
	}
	if (countr == 0) {
		cout << "NO data found\n";
	}
}
void update(int n) {
	if (pet[n - 1].num == n)
	{
		int choice;
		do {
			cout << "which data you want change\n";
			cout << "1) type\n";
			cout << "2) name\n";
			cout << "3) birth\n";
			cout << "4) treatment\n";
			cout << "5) data of treatment\n";
			cout << "6) upcoming treatment\n";
			cout << "7) you finish\n";
			cout << "Enter your choice : \n ";
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1:cout << "Update type : ";
				getline(cin, pet[n - 1].type);
				break;
			case 2:cout << "Update name : ";
				getline(cin, pet[n - 1].name);
				break;
			case 3:cout << "Update birth : ";
				getline(cin, pet[n - 1].birth);
				break;
			case 4:cout << "Update treatment : ";
				getline(cin, pet[n - 1].treat);
				break;
			case 5:cout << "Update data of treatment : ";
				getline(cin, pet[n - 1].datatreat);
				break;
			case 6:cout << "Update upcoming treatment : ";
				getline(cin, pet[n - 1].upcoming_treatment);
				break;
			}
		} while (choice != 7);
	}
	cout << "Updated successfully\n";
}
void Delete(int s)
{
	if (pet[s - 1].num == s) {
		pet[s - 1].type.clear();
		pet[s - 1].name.clear();
		pet[s - 1].birth.clear();
		pet[s - 1].treat.clear();
		pet[s - 1].datatreat.clear();
		pet[s - 1].upcoming_treatment.clear();
		cout << "delete Successfully\n";
	}
	else
		cout << "worng pet number";
}
void search(string search) {//bool check = true;
	int countr = 0, show = 0;
	for (int i = 0; i < 20; i++) {
		countr++;
		if (search == pet[i].upcoming_treatment) {
			if (show == 0)
			{
				show++;
				cout << "no.  |    type    |   name   |    birth    |   treatment    |    traetmentdate     |        upcoming_treatment    \n";
				cout << "====================================================================================================================================\n";
			}
			cout << " " << countr << "    |    " << pet[i].type << "    |     " << pet[i].name << "   |    " << pet[i].birth << "      |     " << pet[i].treat << "      |   " << pet[i].datatreat << "       |     " << pet[i].upcoming_treatment << "\n";
		}
	}
	if (show == 0)
		cout << "no data found";
}
void save_to_file() {
	ofstream dataofpet("data.txt");
	for (int i = 0; i < 20; i++)
	{
		if (pet[i].type != "") {
			dataofpet << pet[i].type << pet[i].name << pet[i].birth << pet[i].treat << pet[i].datatreat << pet[i].upcoming_treatment << endl;
		}
		else {
			break;
		}
	}
	dataofpet.close();
}
int main()
{
	cout << "Welcome our program\n";
	cout << "-----------------------\n";
	bool check = login();
	int chooce, number;
	string upcoming;
	openfile();
	if (check) {
		do
		{
			cout << "1) Add a new pet\n";
			cout << "2) Update any data of an existing pet\n";
			cout << "3) Delete a pet\n";
			cout << "4) Display all the pets \n";
			cout << "5) Search for pets by the date of the upcoming treatment\n";
			cout << "6) Exit form program and save data\n ";
			cout << "Enter your choice : \n";
			cin >> chooce;
			switch (chooce)
			{
			case 1:add(); break;
			case 2:
				display();
				cout << "Enter number pet\n";
				cin >> number;
				update(number);
				break;
			case 3:
				display();
				cout << "Enter number pet\n";
				cin >> number;
				Delete(number);
				break;
			case 4:
				display();
				break;
			case 5:
				cout << "Enter Upcoming Treatment date " << endl;
				cin >> upcoming;
				search(upcoming);
				break;
			case 6: break;
			default:
				cout << "Enter a valid number";
				break;
			}
		} while (chooce != 6);
		save_to_file();
	}
	system("pause");
	return 0;
}

