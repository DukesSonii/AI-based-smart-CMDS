#include<iostream.h>
#include<fstream.h>
#include<conio.h>
//using namespace std;
int main()
{
	clrscr();
	int ch;
	cout<<"Enter the operation";
	cout<<"\n 1. Press 1 for IR ";
	cout<<"\n 2. Press 2 for Radar\n";
	cin>>ch;

       switch(ch)
	{	case 1:
		{	int m ;
			cout<<"\n NAG MISSILE \n";
			cout<<"launch"<<m;
			break;
		}
		case 2:
		{	char n;
			float f;
			int loc;
			cout<<"\n ***   Missile Names  ***\n";
			cout<<"\n 1. Nirbhay Missile  \n";
			cout<<"\n 2. Akash  Missile\n";
			cout<<"\n 3. Trishul Missile\n";
			cout<<"\n enter the missile Number \n";
			cin>>n;
			while(1)
			{

					cout<<"\n Enter the frequency to be set: \n ";
					cin>>f;
					//if(f>=18)
					//break;
					cout<<"\n Enter the location of missile (1 or 2):\n";
					cin>>loc;
					//if(loc>=3)
					//break;
				ofstream fout;
				fout.open("file1.txt",ios::out);
				fout<<f;
				fout<<" "<<loc;
				fout.close();
				if(f<18 && loc<3)
				{

				cout<<" launch! \n";
				}
				else
				{
					cout<<"\n frequency doesn't match. Hence missile would not launch! \n";
					break;
				}

			}
			break;
		}
		default:
			cout<<"wrong choice!";
	}

	return 0;
	getch();
}


