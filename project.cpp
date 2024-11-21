#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<sstream>
using namespace std;
/*iss.clear();
					iss.str(line);
					iss >> pet[y].type >> pet[y].name >> pet[y].brith >> pet[y].treat >>pet[y].datatreat>>pet[y].upcoming_treatment;*/
struct data1 {
	int num;
	string name;
	string type;
	string brith;
	string treat;
	string datatreat;
	string upcoming_treatment;
}pet[20];
bool login() {
	int b = 0, c = 1;
	bool x = true;
	string lo = "pet", log;
	char ps[] = "pet1", pa;
	do {
		if ((x != true || lo != log) && c != 1)
			cout << "\nwrong password or username\n";
		x = true;

		cout << "username\n";
		cin >> log;
		cout << "enter password\n";
		while (true)
		{
			pa = _getch();
			if (pa == '\r') {
				b = 0;
				break;
			}
			cout << "*";
			if (pa != ps[b++])
				x = false;
		}
		c = c + 1;
	} while (x != true || lo != log);

	if (x == true && lo == log) {
		cout << "\nsuccesfully logged ";
		return true;
	}
}
void openfile() {
	{
		string line; int y = 0;
		ifstream dataofpet;
		//istringstream iss;
		dataofpet.open("C:\\Users\\w\\source\\repos\\Project mypetshedule\\Project mypetshedule\\data.txt");
		if (dataofpet.is_open()) {
			while (!dataofpet.eof()) {
				int i; int n = 0;
				for (i = 0; i <= 5; i++) {
					getline(dataofpet, line, ',');
					if (i == 0) { pet[y].type = line; }
					else if (i == 1) {
						pet[y].name = line;
					}
					else if (i == 2) {
						//pet[y].brith = line;
					}
					else if (i == 3) {
						pet[y].treat = line;
					}
					else if (i == 4) {
						pet[y].datatreat = line;
					}
					else if (i == 5) {
						pet[y].upcoming_treatment = line;
					}
				}
				y++; 
			}
		}
		else { cout << "error"; }
	}
}
void add() {
	//cin.ignore();
	for (int i = 0; i < 20; i++) {
		int v = 0; string b;
		if (pet[i].type == "\0") {//check array is empty
			cout << "Enter type your pet : "; getline(cin, pet[i].type);
			cout << "Enter name : "; getline(cin, pet[i].name);
			cout << "Enter date of brith : "; getline(cin, pet[i].brith);
			cout << "Enter treatment : "; getline(cin, pet[i].treat);
			cout << "Enter data of treatment : "; getline(cin, pet[i].datatreat);
			cout << "Enter date of the upcoming treatment : "; getline(cin, pet[i].upcoming_treatment);
		}
		break;
	}
}
void display() {
	int countr = 0;
	cout << "no.  |    type    |   name     |       brith       |     treatment        |        treatment date          |           upcoming_treatment    \n";
	cout << "==============================================================================================================================================================\n";
	for (int i = 0; i < 20; i++) {
		if (pet[i].type != "\0") {
			countr++;
			cout << " " << countr << "    |    " << pet[i].type << "    |     " << pet[i].name << "   |    " << pet[i].brith << "      |     " << pet[i].treat << "           |      " << pet[i].datatreat << "                     |           " << pet[i].upcoming_treatment << "\n";
			pet[i].num = countr;
		}
		else { break; }
	}
	if (countr = 0) {
		cout << "NO data found\n";
	}
}
void update(int n) {
		for (int i = 0; i < 20; i++) {
			if (pet[i].num == n) {
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
						getline(cin, pet[i].type);
						break;
					case 2:cout << "Update name : ";
						getline(cin, pet[i].name);
						break;
					case 3:cout << "Update brith : ";
						getline(cin, pet[i].brith);
						break;
					case 4:cout << "Update treatment : ";
						getline(cin, pet[i].treat);
						break;
					case 5:cout << "Update data of treatment : ";
						getline(cin, pet[i].datatreat);
						break;
					case 6:cout << "Update upcoming treatment : ";
						getline(cin, pet[i].upcoming_treatment);
						break;
					}
				} while (choice != 7);
			}
		}
			cout << "Updated successfully\n";
		
}
void delet(int s) {
	int step = 0;
	for (int i = 0; i < 20; i++) {
		if (pet[i].num == s) {
			step++;
			pet[i].type.clear();
			pet[i].name.clear();
			pet[i].brith.clear();
			pet[i].treat.clear();
			pet[i].datatreat.clear();
			pet[i].upcoming_treatment.clear();
			cout << "delete Successfully\n";
		}
	}
	if (step == 0) { cout << "Delete Failed"; }

}
void search(string search) {//bool check = true;
	int countr = 0;
	cout << "no.  |    type    |   name   |    brith    |   treatment    |    traetmentdate     |        upcoming_treatment    \n";
	cout << "====================================================================================================================================\n";
	for (int i = 0; i < 20; i++) {
		countr++;
		if (search == pet[i].upcoming_treatment) {
			cout << " " << countr << "    |    " << pet[i].type << "    |     " << pet[i].name << "   |    " << pet[i].brith << "      |     " << pet[i].treat << "      |   " << pet[i].datatreat << "       |     " << pet[i].upcoming_treatment << "\n";
		}
	}

	/*for (int i = 0; i < 5; i++) {
		if (search== pet[i].upcoming_treatment) {
			//cout << "Pet is found and its name is : " << name[i] << "\t" << "and its age is : " << age[i] << "\t" << "and its disease : " << disease[i] << endl;
			dis(i);
		}
		else {

			check = false;
		}
	}
	if (check == false) {
		cout << "Pet Not Found" << endl;
	}*/
}
void save_to_file() {
	ofstream dataofpet("data.txt");
	for (int i = 0; i < 20; i++) {
		if (pet[i].type != "\0") {
			dataofpet << pet[i].type << " , " << pet[i].name << " , " << pet[i].brith << " , " << pet[i].treat << " , " << pet[i].datatreat << " ," << pet[i].upcoming_treatment<<" ," << endl;
		}
		else {
			break;
		}
	}
	dataofpet.close();
}
int main() {
	cout << "Welcome our program\n";
	cout << "-----------------------\n";
	bool check = login();
	int chooce;
	openfile();
	if (check) {
		do {
			cout << "1) Add a new pet\n";
			cout << "2) Update any data of an existing pet\n";
			cout << "3) Delete a pet\n";
			cout << "4) Display all the pets \n";
			cout << "5) Search for pets by the date of the upcoming treatment\n";
			cout << "6) Exit form program and save data\n ";
			cout << "Enter your choice : \n";
			cin >> chooce;
			if (chooce == 1) {
				add();
			}
			else if (chooce == 2) {
				int n;
				display();
				cout << "Enter number pet\n";
				cin >> n;
				update(n);
			}
			else if (chooce == 3) {
				int number;
				display();
				cout << "Enter number pet\n";
				cin >> number;
				delet(number);
			}
			else if (chooce == 4) {
				display();
			}
			else if (chooce == 5) {
				string upcoming;
				cout << "Enter Upcoming Treatment date " << endl;
				cin >> upcoming;
				search(upcoming);
			}
		} while (chooce != 6);

		save_to_file();
	}
	return 0;
}

	
	
	
	
	
	