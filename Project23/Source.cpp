#include<iostream>
using namespace std;
class Patient
{
protected:
	int first_1,first_2,rear, rear_1,rear_2;

	int queue[40], patient_A[20], patient_B[20];
public:
	Patient()
	{
		first_1 = -1;
		rear = 0;
		rear_1 = -1;
		first_2 = -1;
		rear_2 = -1;
		for (int i = 0; i < 40; i++)
		{
			queue[i] = 0;
		}
		for (int i = 0; i < 20; i++)
		{
			patient_A[i] = 0;
			patient_B[i] = 0;
		}
	}
	bool empty_patA()
	{
		if (first_1 == -1 && rear_1 == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool empty_patB()
	{
		if (first_2 == -1 && rear_2 == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool full_patA()
	{
		if (rear_1 == 19)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool full_patB()
	{
		if (rear_2 == 19)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ad_patA(int val)
	{
		if (full_patA())
		{
			cout << "Achieved maximum number of patients please vist tommorow" << endl;
		}
		else if (empty_patB())
		{
			rear_1 == first_1 == 0;
		}
		else
		{
			rear_1++;
		}
		patient_A[rear_1] = val;
	}
	void ad_patB(int val)
	{
		if (full_patA())
		{
			cout << "Achieved maximum number of patients please vist tommorow" << endl;
		}
		else if (empty_patB())
		{
			rear_2 = first_2 = 0;
		}
		else
		{
			rear_2++;
		}
		patient_B[rear_2] = val;
	}
	void display()
	{
		int cho;
		cout << "Which type of patients you want to see" << endl;
		cout << "Press 1 for Physiction dealing with old age group" << endl;
		cout << "Press 2 for Physiction dealing with young age group" << endl;
		cout << "Enter choice:";
		cin >> cho;
		cout << endl;
		switch (cho)
		{
		case 1:
		{
			if (empty_patA()) 
			{
				cout << endl << "No Patients Visited" << endl;
			}
			else 
			{
				cout << endl << "Queue of Old Patients" << endl;
				for (int i = first_1; i <= rear_1; i++)
					cout << patient_A[i] << endl;
			}
			break;
		}
		case 2:
		{
			if (empty_patB()) 
			{
				cout << endl << "No Patients Visited" << endl;
			}
			else
			{
				cout << endl << "Queue of young Patients"<<endl;
				for (int i = first_2; i <= rear_2; i++)
					cout << patient_B[i] << endl;
			}
			break;
		}
		default:
			break;
		}
	}
	void display_total()
	{
		rear = (rear_1+1) + (rear_2+1);
		cout << "Total Number of Patient who got checked from Physisian A and  Physisian B:" << rear << endl;
		cout << "Remaining patients that can get check up are:" << 40-rear << endl;
		cout << "Remaining young patients that can get check up are:" << 19 - rear_2 << endl;
		cout << "Remaining old patients that can get check up are:" << 19 - rear_1 << endl;
	}
};
void menu()
{
	cout <<"\t\tMenu" << endl;
	cout <<"\t1.ADD Patients" << endl;
	cout <<"\t2.Display Patients" << endl;
	cout << "\t3.Display Total Patients" << endl;
}
int main()
{
	Patient p;
	int val, op=0;
	char choi,ch;
	do
	{		
		system("CLS");
		menu();
		cout << "Select any option:";
		cin >> op;
		cout << endl;
		switch (op)
		{
		case 1:
		{
			do {
				system("CLS");
				cout << "Enter age of patient:";
				cin >> val;
				cout << endl;
				if (val >= 50)
				{
					p.ad_patA(val);
				}
				else
				{
					p.ad_patB(val);
				}
				system("CLS");
				cout << "Do you want to enter more Patients(Y/N)";
				cin >> choi;
				cout << endl;
			} while (choi == 'Y' || choi == 'y');
			break;
		}
		case 2:
		{
			p.display();
			system("pause");
			break;
		}
		case 3:
		{

			p.display_total();
			system("pause");
			break;
		}
		default:
			cout << "Invalid Option Selected" << endl;
			cin.ignore();
			break;
		}
		system("CLS");
		cout << "Do you want to continue and apply more Operations(Y/N)";
		cin >> ch;
		cout << endl;
	}while (ch == 'Y' || ch == 'y');
	return 0;
}