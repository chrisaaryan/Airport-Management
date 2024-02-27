#include <iostream>
#include <string>
#include <fstream>      //maincode
#include <iomanip>
#include <sstream>
#include <conio.h>   ///to use _getche
#include <Windows.h> ///to  use  gotoxy and  setcolor
using namespace std;



class FLIGHT
{
public:
    void control_panel();
    void add_flight();
    void show_flight();
    void check_flight();
    void update_flight();
    void del_flight();
    void search_flight_by_dest();
    void check_flightforticket();
};


class VISITORS : public FLIGHT
{
public :
    void visitor_panel();
    void check_flights();
    void book_flights();
    void update_flight();
    void complaints();
    void view_complaints();
    void check_flightforticket();
};
void FLIGHTSRECORD();
void Mainmenu();
void STAFFRECORD();
void Mainmenu1();
void gotoxy(short int x, short int y);
void setColor(int c);
void draw_board();
void COMPLAINTSRECORDFORVIS();
int tobecalledmain();
void FLIGHT::control_panel()
{
    system("cls");
    setColor(9);
    gotoxy(45, 1);
    cout << "*************** CONTROL PANEL ***************";
gotoxy(45, 3);
cout << "****** Main Menu ******";
draw_board();
setColor(2);
gotoxy(45, 8);
cout << "\n\t\t\t\t\t\t1. ADD FLIGHTS";
gotoxy(45, 10);
cout << "\n\t\t\t\t\t\t2. DISPLAY FLIGHTS";
gotoxy(45,12);
cout << "\n\t\t\t\t\t\t3. CHECK PARTICULAR FLIGHT";
gotoxy(45, 14);
cout << "\n\t\t\t\t\t\t4. UPDATE FLIGHT";
gotoxy(45, 16);
cout << "\n\t\t\t\t\t\t5. DELETE FLIGHT";
gotoxy(45, 18);
cout << "\n\t\t\t\t\t\t6. EXIT";
gotoxy(45, 20);

}

void FLIGHT::add_flight()
{
    system("cls");
    fstream file;
    int no_copy;
    string flightname, from, flight_id;
    cout << "\n\n\t\t\t\tADD FLIGHTS";
    cout << "\n\nFLIGHT ID : ";
    cin >> flight_id;
    cout << "\nFLIGHT NAME : ";
    cin >> flightname;
    cout << "\nDESTINATION : ";
    cin >> from;
    cout << "\nNo. of FLIGHTS : ";
    cin >> no_copy;

    file.open("flights.txt",
              ios::out | ios::app);
    file << " " << flight_id << " "
         << flightname << " " << from
         << " " << no_copy << "\n";
    file.close();
}

void FLIGHT::show_flight()
{
    system("cls");
    fstream file;
    int no_copy;
    string flightname, flight_id, from;
    cout << "\n\n\t\t\t\t\tAll FLIGHTS";

    file.open("flights.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nFLIGHT ID\t\tFLIGHTNAME"
             << "\t\tDESTINATION(FROM CHENNAI)\t\tNo. of "
                "FLIGHTS\n\n";
        file >> flight_id >> flightname;
        file >> from >> no_copy;

        while (!file.eof()) {

            cout << "  " << flight_id
                 << "\t\t" << flightname
                 << "\t\t\t\t" << from
                 << "\t\t\t\t\t" << no_copy
                 << "\n\n";
            file >> flight_id >> flightname;
            file >> from >> no_copy;
        }

        system("pause");
         file.close();
    }
}

void FLIGHT::check_flight()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string flight_id, flightname, from, flight_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular flight";

    file.open("flights.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nflight ID : ";
        cin >> flight_idd;
        file >> flight_id >> flightname;
        file >> from >> no_copy;

        while (!file.eof()) {

            if (flight_idd == flight_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular flight";
                cout << "\n\nflight ID : "
                     << flight_id;
                cout << "\nName : "
                     << flightname;
                cout << "\nDESTINATION : "
                     << from;
                cout << "\nNo. of FLIGHTS : "
                     << no_copy;
                cout << endl
                     << endl;
                count++;
                break;

            }
            file >> flight_id >> flightname;
            file >> from >> no_copy;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nFlight ID not Found !";
    }
}

void VISITORS::check_flightforticket()
{   string name,id;
    cout << "\n\nEnter ID of the flight you want to book : ";
    cin>>id;
    cout<<"ENTER YOUR NAME : ";
    cin>>name;
    int age;
    cout<<"ENTER YOUR AGE : ";
    cin>>age;
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string flight_id, flightname, from, flight_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular flight";

    file.open("flights.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        file >> flight_id >> flightname;
        file >> from >> no_copy;

        while (!file.eof()) {

            if (id == flight_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "YOUR TICKET"<<endl;
                cout<<"*****************************************************"<<endl;
                cout<<"\n\nNAME:"
                    <<name;
                cout<<"\nAGE:"
                    <<age;
                cout << "\nflight ID : "
                     << flight_id;
                cout << "\nName : "
                     << flightname;
                cout << "\nDESTINATION : "
                     << from;
                cout << "\nNo. of FLIGHTS : "
                     << no_copy;
                cout << endl
                     << endl;
                cout<<"*****************************************************"<<endl;
                count++;
                break;

            }
            file >> flight_id >> flightname;
            file >> from >> no_copy;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nFlight ID not Found !";
    }
}


// Function for flight shop record
void FLIGHTSRECORD()
{
    int choice;
    char x;
    FLIGHT b;

    while (1) {

        b.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_flight();
                cout << "\n\nWant to add"
                     << " another flight? "
                        "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_flight();
            break;

        case 3:
            b.check_flight();
            break;
        case 4:
            b.update_flight();
            break;

        case 5:
            b.del_flight();
            break;

        case 6:
            tobecalledmain();
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}



void VISITORS::visitor_panel()
{
    system("cls");

    draw_board();
    setColor(2);
    gotoxy(35, 8);
    cout << "\n\t\t\t\t\t\t1. VIEW ALL FLIGHTS";
    gotoxy(35, 10);
    cout << "\n\t\t\t\t\t\t2. BOOK FLIGHTS";
    gotoxy(35,12);
    cout << "\n\t\t\t\t\t\t3. COMPLAINTS";
    gotoxy(35, 14);
    cout << "\n\t\t\t\t\t\t4. EXIT";
    gotoxy(35, 16);

}

void VISITORS :: complaints()
{
    system("cls");
    char data[100];
    fstream file;
    cout << "\n\n\t\t\t\tENTER COMPLAINTS HERE !\n\n";
    file.open("comp.txt",ios::out | ios::app);
    cin >> data;
    file << data<< "\n";
    file.close();
}

void VISITORS :: view_complaints()
{
    system("cls");
    fstream file("comp.txt");
    if (file.is_open()) {
    string line;
    while (getline(file, line)) {
        // using printf() in all tests for consistency
        printf("%s", line.c_str());
    }
    file.close();
}
}
void VISITORSRECORD()
{
    int choice;
    char x;
    VISITORS v;
    while (1) {

        v.visitor_panel();
        cout << "\n\n\t\t\t\t\t\tEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            {
                v.show_flight();
                break;
            }

        case 2:
            {
            v.search_flight_by_dest();
            cout<<endl;
            v.check_flightforticket();
            break;
            }

        case 3:
            {
                COMPLAINTSRECORDFORVIS();
              break;
            }
        case 4:
            {
                tobecalledmain();
            }

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}


bool loading()
{
    char ch;
    gotoxy(33, 23);   /// Loading
    setColor(8);
    cout << "wait...  ";
    gotoxy(5, 24);
    for (int i = 5; i <= 105; i++)
    {
        cout << "|";
        Sleep(1);
        gotoxy(37, 23);
        cout << i - 5 << " %";
        Sleep(1);
        gotoxy(i, 24);
    }
    gotoxy(30, 26);
    cout << "Press any key to continue ....";
    gotoxy(30, 27);
    cout << "Press Esc to Exit";
    bool flag = true;
    int num = 9;
    while (flag)
    {

        if (_kbhit())
        {
            ch = _getch();
            flag = false;
        }
    }
    if (ch == 27)
        return false;
    else
        return true;
}

void loading1()
{

    gotoxy(33, 23);   /// Loading
    setColor(8);
    cout << "wait...  ";
    gotoxy(5, 24);
    for (int i = 5; i <= 105; i++)
    {
        cout << "|";
        Sleep(30);
        gotoxy(37, 23);
        cout << i - 5 << " %";
        Sleep(30);
        gotoxy(i, 24);
    }
    gotoxy(30, 26);
    cout << "DISPLAYING ....";
}

void setColor(int c)
{           ///if (c < 15&& c> 0) font  color  else  background color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c);/// For ground colors take up the least significant byte
}
void draw_board()
{
    int i = 30, j;
    gotoxy(i, 5);
    setColor(15);
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *";  /// above line of asterics
    cout << endl;

    for (j = 5; j <= 20; j++)   /// vertical  lines   of  asterics
    {
        gotoxy(i, j);
        cout << "*";
        gotoxy(84, j);
        cout << "*";
    }
    gotoxy(i, j - 1);
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *"; /// lower line of asterics
}

void gotoxy(short int x, short int y)
{
    COORD cur = { x, y }; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}
bool Access()
{
    system("CLS");
    string user, pass;
    draw_board();
    gotoxy(32, 8);
    setColor(9);
    cout << "LOG IN";
    gotoxy(32, 10);
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *";
    gotoxy(32, 13);
    setColor(9);
    cout << "User Name : "; // hint: admin
    cin >> user;
    gotoxy(32, 15);
    cout << "Password : ";    // hint: 123
    cin >> pass;
    if (user == "admin" && pass == "123")
    {
        return true;
    }
    else
    {
        return false;
    }
}





// Function to update the flight
void FLIGHT::update_flight()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string flightname, b_na, from;
    string a_na, flight_idd, flight_id;


    cout << "\n\n\t\t\t\tUpdate flight Record";
    file1.open("flights1.txt",
               ios::app | ios::out);
    file.open("flights.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nflight ID : ";
        cin >> flight_id;
        file >> flight_idd >> flightname;
        file >> from >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {
            if (flight_id == flight_idd) {
                system("cls");
                cout << "\t\t\t\t"
                     << "Update flight Record";
                cout << "\n\nNew flight Name : ";
                cin >> b_na;
                cout << "\nFlight   Name : ";
                cin >> a_na;
                cout << "\nNo. of FLIGHTS : ";
                cin >> no_co;
                file1 << " " << flight_id << " "
                      << b_na << " "
                      << a_na << " " << no_co
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << flight_idd
                      << " " << flightname
                      << " " << from
                      << " " << no_copy
                      << "\n\n";
            file >> flight_idd >> flightname;
            file >> from >> no_copy;
        }
        if (count == 0)
            cout << "\n\nflight ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("flights.txt");
    rename("flights1.txt",
           "flights.txt");
}

// Function to delete flight
void FLIGHT::del_flight()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string flight_id, flight_idd, flightname, from;
    cout << "\n\n\t\t\t\tDelete a flight";

    // Append file in output mode
    file1.open("flights1.txt",
               ios::app | ios::out);
    file.open("flights.txt",
              ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nflight ID : ";
        cin >> flight_id;
        file >> flight_idd >> flightname;
        file >> from >> no_copy;
        while (!file.eof()) {

            if (flight_id == flight_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a flight";
                cout << "\n\nflight is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << flight_idd
                      << " " << flightname
                      << " " << from
                      << " " << no_copy
                      << "\n\n";
            file >> flight_idd >> flightname;
            file >> from >> no_copy;
        }
        if (count == 0)
            cout << "\n\nflight ID "
                 << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("flights.txt");
    rename("flights1.txt",
           "flights.txt");
}
void FLIGHT :: search_flight_by_dest()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string flight_id, flightname, from, flight_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular flight";

    file.open("flights.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nflight DEST : ";
        cin >> flight_idd;
        file >> flight_id >> flightname;
        file >> from >> no_copy;

        while (!file.eof()) {

            if(flight_idd == from) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular flight";
                cout << "\n\nFlight ID : "
                     << flight_id;
                cout << "\nName : "
                     << flightname;
                cout << "\nDESTINATION : "
                     << from;
                cout << "\nNo. of FLIGHTS : "
                     << no_copy;
                cout << endl
                     << endl;
                count++;

               // break;
            }
             file >> flight_id >> flightname;
             file >> from >> no_copy;

        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nFlight ID not Found !";
    }
}

class STAFF {
public:
    void control_panel();
    void add_STAFF();
    void show_STAFF();
    void check_STAFF();
    void update_STAFF();
    void del_STAFF();
    void checkanySTAFFbyname();     //add this to visitor's tab
};

void STAFF::control_panel()
{
    system("cls");
    draw_board();
    gotoxy(45,3);
    cout << "\n\n\t\t\t\tCONTROL  PANEL";
    gotoxy(45,8);
    cout << "\n\t\t\t\t\t\t1. ADD STAFF";
    gotoxy(45,10);
    cout << "\n\t\t\t\t\t\t2. DISPLAY STAFF";
    gotoxy(45,12);
    cout << "\n\t\t\t\t\t\t3. CHECK PARTICULAR STAFF";
    gotoxy(45,14);
    cout << "\n\t\t\t\t\t\t4. UPDATE STAFF";
    gotoxy(45,16);
    cout << "\n\t\t\t\t\t\t5. DELETE STAFF";
    gotoxy(45,18);
    cout << "\n\t\t\t\t\t\t6. EXIT";
    gotoxy(45,20);
}

void STAFF::add_STAFF()
{
    system("cls");
    fstream file;
    int rms;
    string STAFFname, STAFF_DEPARTMENT, STAFF_id;
    cout << "\n\n\t\t\t\tADD STAFF";
    cout << "\n\nSTAFF ID : ";
    cin >> STAFF_id;
    cout << "\nSTAFF NAME : ";
    cin >> STAFFname;
    cout << "\nSTAFF_DEPARTMENT : ";
    cin >> STAFF_DEPARTMENT;
    cout << "\nStaff Salary : ";
    cin >> rms;

    file.open("SSSS.txt",
              ios::out | ios::app);
    file << " " << STAFF_id << " "
         << STAFFname << " " << STAFF_DEPARTMENT
         << " " << rms << "\n";
    file.close();
}

void STAFF::show_STAFF()
{
    system("cls");
    fstream file;
    int rms;
    string STAFFname, STAFF_id, STAFF_DEPARTMENT;
    cout << "\n\n\t\t\t\t\tAll STAFF";

    file.open("SSSS.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nSTAFF ID\tSTAFF NAME"
             << "\tSTAFF_DEPARTMENT\tSTAFF "
                "SALARY\n\n";
        file >> STAFF_id >> STAFFname;
        file >> STAFF_DEPARTMENT >> rms;

        while (!file.eof()) {

            cout << "  " << STAFF_id
                 << "\t\t" << STAFFname
                 << "\t\t" << STAFF_DEPARTMENT
                 << "\t\t" << rms
                 << "\n\n";
            file >> STAFF_id >> STAFFname;
            file >> STAFF_DEPARTMENT >> rms;
        }

        system("pause");
         file.close();
    }
}

void STAFF::check_STAFF()
{
    system("cls");
    fstream file;
    int rms, count = 0;
    string STAFF_id, STAFFname, STAFF_DEPARTMENT, STAFF_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular STAFF";

    file.open("SSSS.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nSTAFF ID : ";
        cin >> STAFF_idd;
        file >> STAFF_id >> STAFFname;
        file >> STAFF_DEPARTMENT >> rms;

        while (!file.eof()) {

            if (STAFF_idd == STAFF_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular STAFF";
                cout << "\n\nSTAFF ID : "
                     << STAFF_id;
                cout << "\nName : "
                     << STAFFname;
                cout << "\nLocation : "
                     << STAFF_DEPARTMENT;
                cout << "\nStaff Salary : "
                     << rms;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> STAFF_id >> STAFFname;
            file >> STAFF_DEPARTMENT >> rms;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nSTAFF ID Not"
                 << " Found...";
    }
}

void STAFF::checkanySTAFFbyname()
{
    system("cls");
    fstream file;
    int rms, count = 0;
    string STAFF_id, STAFFname, STAFF_DEPARTMENT, STAFF_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular STAFF";

    file.open("SSSS.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nSTAFF ID : ";
        cin >> STAFF_idd;
        file >> STAFF_id >> STAFFname;
        file >> STAFF_DEPARTMENT >> rms;

        while (!file.eof()) {

            if (STAFF_idd == STAFFname) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular STAFF";
                cout << "\n\nSTAFF NAME : "
                     << STAFF_id;
                cout << "\nSTAFF ID : "
                     << STAFFname;
                cout << "\nLocation : "
                     << STAFF_DEPARTMENT;
                cout << "\nStaff Salary : "
                     << rms;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> STAFF_id >> STAFFname;
            file >> STAFF_DEPARTMENT >> rms;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nSTAFF Not"
                 << " Found...";
    }
}

// Function to update the STAFF
void STAFF::update_STAFF()
{
    system("cls");
    fstream file, file1;
    int rms, no_co, count = 0;
    string STAFFname, b_na, STAFF_DEPARTMENT;
    string a_na, STAFF_idd, STAFF_id;

    cout << "\n\n\t\t\t\tUpdate STAFF Record";
    file1.open("SS1.txt",
               ios::app | ios::out);
    file.open("SSSS.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nSTAFF ID : ";
        cin >> STAFF_id;
        file >> STAFF_idd >> STAFFname;
        file >> STAFF_DEPARTMENT >> rms;

        // Till end of file is reached
        while (!file.eof()) {
            if (STAFF_id == STAFF_idd) {
                system("cls");
                cout << "\t\t\t\t"
                     << "Update STAFF Record";
                cout << "\n\nNew STAFF Name : ";
                cin >> b_na;
                cout << "\nSTAFF ID : ";
                cin >> a_na;
                cout << "\nStaff Salary : ";
                cin >> no_co;
                file1 << " " << STAFF_id << " "
                      << b_na << " "
                      << a_na << " " << no_co
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << STAFF_idd
                      << " " << STAFFname
                      << " " << STAFF_DEPARTMENT
                      << " " << rms
                      << "\n\n";
            file >> STAFF_idd >> STAFFname;
            file >> STAFF_DEPARTMENT >> rms;
        }
        if (count == 0)
            cout << "\n\nSTAFF ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("SSSS.txt");
    rename("SS1.txt",
           "SSSS.txt");
}

// Function to delete STAFF
void STAFF::del_STAFF()
{
    system("cls");
    fstream file, file1;
    int rms, count = 0;
    string STAFF_id, STAFF_idd, STAFFname, STAFF_DEPARTMENT;
    cout << "\n\n\t\t\t\tDelete a STAFF";

    // Append file in output mode
    file1.open("SS1.txt",
               ios::app | ios::out);
    file.open("SSSS.txt",
              ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nSTAFF NAME : ";
        cin >> STAFF_id;
        file >> STAFF_idd >> STAFFname;
        file >> STAFF_DEPARTMENT >> rms;
        while (!file.eof()) {

            if (STAFF_id == STAFF_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a STAFF";
                cout << "\n\nSTAFF is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << STAFF_idd
                      << " " << STAFFname
                      << " " << STAFF_DEPARTMENT
                      << " " << rms
                      << "\n\n";
            file >> STAFF_idd >> STAFFname;
            file >> STAFF_DEPARTMENT >> rms;
        }
        if (count == 0)
            cout << "\n\nSTAFF ID "
                 << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("SSSS.txt");
    rename("SS1.txt",
           "SSSS.txt");
}

// Function for STAFF shop record
void STAFFRECORD()
{
    int choice;
    char x;
    STAFF b;

    while (1) {

        b.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_STAFF();
                cout << "\n\n\t\t\t\t\t\tWant to add"
                     << " another STAFF? "
                        "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_STAFF();
            break;

        case 3:
            b.check_STAFF();
            break;
        case 4:
            b.update_STAFF();
            break;

        case 5:
            b.del_STAFF();
            break;

        case 6:
            tobecalledmain();
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}
class COMPLAINTS {
public:
    void ctrpanelcompl();
    void add_COMPLAINTS();
    void show_COMPLAINTS();
    void check_COMPLAINTS();
    void update_COMPLAINTS();
    void del_COMPLAINTS();
    void checkanyCOMPLAINTSbyname();
    void ctrpanelcomplforadmin();    //add this to visitor's tab
};

void COMPLAINTS::ctrpanelcompl()
{
    system("cls");
    draw_board();
    gotoxy(40,8);
    cout << "\n\n\t\t\t\tCONTROL  PANEL";
    gotoxy(40,10);
    cout << "\n\n\t\t\t\t1. ENTER COMPLAINT";
    gotoxy(40,12);
    cout << "\n\t\t\tt2. EXIT";
    gotoxy(40,14);
}

void COMPLAINTS::ctrpanelcomplforadmin()
{
    system("cls");
    draw_board();
    gotoxy(40,3);
    cout << "\n\n\t\t\t\t\tCONTROL  PANEL";
    gotoxy(40,10);
    cout << "\n\n\t\t\t\t1. SHOW COMPLAINTS";
    gotoxy(40,12);
    cout << "\n\n\t\t\t\t2. SEARCH FOR COMPLAINTS";
    gotoxy(40,14);
    cout << "\n\n\t\t\t\t3. EXIT";
    gotoxy(40,16);
}

void COMPLAINTS::add_COMPLAINTS()
{
    system("cls");
    fstream file;
    long phnum;
    string COMPLAINTSname, COMPLAINTS_Location, COMPLAINTS_id;
    cout << "\n\n\t\t\t\tADD COMPLAINTS";
    cout << "\n\nUSER CITY : ";
    cin >> COMPLAINTS_id;
    cout << "\n\n\t\t\t\tSELECT";
    cout << "\n\nTICKET RELATED ISSUE";
    cout << "\nHOTEL RELATED ISSUE";
    cout << "\nFOOD/SERVICE RELATED ISSUE";
    cout << "\nTRAVEL RELATED ISSUE";
    cout << "\nHYGIENE REALTED ISSUE";
    cout << "\nEXIT"<<endl;
    cin >> COMPLAINTSname;
    cout << "\nAIRLINE YOU HAVE A COMPLAINT ON : ";
    cin >> COMPLAINTS_Location;
    cout << "\nPHONE NUMBER : ";
    cin >> phnum;

    file.open("iaodv.txt",
              ios::out | ios::app);
    file << " " << COMPLAINTS_id << " "
         << COMPLAINTSname << " " << COMPLAINTS_Location
         << " " << phnum << "\n";
    file.close();
}

void COMPLAINTS::show_COMPLAINTS()
{
    system("cls");
    fstream file;
    long phnum;
    string COMPLAINTSname, COMPLAINTS_id, COMPLAINTS_Location;
    cout << "\n\n\t\t\t\t\tAll COMPLAINTS";

    file.open("iaodv.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nUSER CITY\tCOMPLAINT TYPE"
             << "\tAIRLINE\t       PHONE NUMBER  "
                "OF THE USER\n\n";
        file >> COMPLAINTS_id >> COMPLAINTSname;
        file >> COMPLAINTS_Location >> phnum;

        while (!file.eof()) {

            cout << "  " << COMPLAINTS_id
                 << "\t\t" << COMPLAINTSname
                 << "\t\t" << COMPLAINTS_Location
                 << "\t\t" << phnum
                 << "\n\n";
            file >> COMPLAINTS_id >> COMPLAINTSname;
            file >> COMPLAINTS_Location >> phnum;
        }

        system("pause");
         file.close();
    }
    int x;
    cin>>x;
    if(x==2){
        Mainmenu();
    }

}

void COMPLAINTS::check_COMPLAINTS()
{
    system("cls");
    fstream file;
    long phnum, count = 0;
    string COMPLAINTS_id, COMPLAINTSname, COMPLAINTS_Location, COMPLAINTS_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular COMPLAINTS";

    file.open("iaodv.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nCOMPLAINTS ID : ";
        cin >> COMPLAINTS_idd;
        file >> COMPLAINTS_id >> COMPLAINTSname;
        file >> COMPLAINTS_Location >> phnum;

        while (!file.eof()) {

            if (COMPLAINTS_idd == COMPLAINTS_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular COMPLAINTS";
                cout << "\n\nUSER CITY : "
                     << COMPLAINTS_id;
                cout << "\nCOMPLAINT : "
                     << COMPLAINTSname;
                cout << "\nAIRLINE : "
                     << COMPLAINTS_Location;
                cout << "\nPHONE NUMBER : "
                     << phnum;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> COMPLAINTS_id >> COMPLAINTSname;
            file >> COMPLAINTS_Location >> phnum;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nCOMPLAINTS ID Not"
                 << " Found...";
    }
}

void COMPLAINTS::checkanyCOMPLAINTSbyname()
{
    system("cls");
    fstream file;
    long phnum, count = 0;
    string COMPLAINTS_id, COMPLAINTSname, COMPLAINTS_Location, COMPLAINTS_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular COMPLAINTS";

    file.open("iaodv.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nCOMPLAINTS Name : ";
        cin >> COMPLAINTS_idd;
        file >> COMPLAINTS_id >> COMPLAINTSname;
        file >> COMPLAINTS_Location >> phnum;

        while (!file.eof()) {

            if (COMPLAINTS_idd == COMPLAINTSname) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular COMPLAINTS";
                cout << "\n\nUSER CITY : "
                     << COMPLAINTS_id;
                cout << "\nCOMPLAINT : "
                     << COMPLAINTSname;
                cout << "\nAIRLINE : "
                     << COMPLAINTS_Location;
                cout << "\nPHONE NUMBER : "
                     << phnum;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> COMPLAINTS_id >> COMPLAINTSname;
            file >> COMPLAINTS_Location >> phnum;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nCOMPLAINTS Not"
                 << " Found...";
    }
}

// Function to update the COMPLAINTS
void COMPLAINTS::update_COMPLAINTS()
{
    system("cls");
    fstream file, file1;
    long phnum, no_co, count = 0;
    string COMPLAINTSname, b_na, COMPLAINTS_Location;
    string a_na, COMPLAINTS_idd, COMPLAINTS_id;

    cout << "\n\n\t\t\t\tUpdate COMPLAINTS Record";
    file1.open("cmpcmp.txt",
               ios::app | ios::out);
    file.open("iaodv.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nCOMPLAINTS ID : ";
        cin >> COMPLAINTS_id;
        file >> COMPLAINTS_idd >> COMPLAINTSname;
        file >> COMPLAINTS_Location >> phnum;

        // Till end of file is reached
        while (!file.eof()) {
            if (COMPLAINTS_id == COMPLAINTS_idd) {
                system("cls");
                cout << "\t\t\t\t"
                     << "Update COMPLAINTS Record";
                cout << "\n\nNew COMPLAINTS Name : ";
                cin >> b_na;
                cout << "\nCOMPLAINTS Name : ";
                cin >> a_na;
                cout << "\nphone : ";
                cin >> no_co;
                file1 << " " << COMPLAINTS_id << " "
                      << b_na << " "
                      << a_na << " " << no_co
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << COMPLAINTS_idd
                      << " " << COMPLAINTSname
                      << " " << COMPLAINTS_Location
                      << " " << phnum
                      << "\n\n";
            file >> COMPLAINTS_idd >> COMPLAINTSname;
            file >> COMPLAINTS_Location >> phnum;
        }
        if (count == 0)
            cout << "\n\nCOMPLAINTS ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("iaodv.txt");
    rename("cmpcmp.txt",
           "iaodv.txt");
}

// Function to delete COMPLAINTS
void COMPLAINTS::del_COMPLAINTS()
{
    system("cls");
    fstream file, file1;
    long phnum, count = 0;
    string COMPLAINTS_id, COMPLAINTS_idd, COMPLAINTSname, COMPLAINTS_Location;
    cout << "\n\n\t\t\t\tDelete a COMPLAINT";

    // Append file in output mode
    file1.open("cmpcmp.txt",
               ios::app | ios::out);
    file.open("iaodv.txt",
              ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nCOMPLAINTS ID : ";
        cin >> COMPLAINTS_id;
        file >> COMPLAINTS_idd >> COMPLAINTSname;
        file >> COMPLAINTS_Location >> phnum;
        while (!file.eof()) {

            if (COMPLAINTS_id == COMPLAINTS_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a COMPLAINTS";
                cout << "\n\nCOMPLAINTS is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << COMPLAINTS_idd
                      << " " << COMPLAINTSname
                      << " " << COMPLAINTS_Location
                      << " " << phnum
                      << "\n\n";
            file >> COMPLAINTS_idd >> COMPLAINTSname;
            file >> COMPLAINTS_Location >> phnum;
        }
        if (count == 0)
            cout << "\n\nCOMPLAINTS ID "
                 << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("iaodv.txt");
    rename("cmpcmp.txt",
           "iaodv.txt");
}

// Function for COMPLAINTS shop record
void COMPLAINTSRECORDFORVIS()
{
    int choice;
    char x;
    COMPLAINTS b;

    while (1) {

        b.ctrpanelcompl();
        cout << "\n\n\t\t\t\tEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_COMPLAINTS();
                 //ADD LOADING HERE
                cout<<endl;
                cout << "\n\nWE WILL CALL "
                     << " YOU SOON"<<endl;
                cout << "\n\nTHANK YOU FOR NOTIFYING US "<<endl;
                cout << "\n\nWant to add"
                     << " another COMPLAINT? "
                        "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;
        case 2:
            tobecalledmain();
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}

void COMPLAINTSRECORDFORADM()
{
    int choice;
    char x;
    COMPLAINTS b;

    while (1) {

        b.ctrpanelcomplforadmin();
        cout << "\n\n\t\t\t\tEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.show_COMPLAINTS();
                 //ADD LOADING HERE

                cin >> x;
            } while (x == 'y');
            break;
        case 2:
            b.checkanyCOMPLAINTSbyname();
            break;
        case 3:
            tobecalledmain();
            break;
        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}

class HOTEL {
public:
    void control_panel();
    void add_HOTEL();
    void show_HOTEL();
    void check_HOTEL();
    void update_HOTEL();
    void del_HOTEL();
    void checkanyhotelbyname();
};

void HOTEL::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tCONTROL  PANEL";
    cout << "\n\n1. ADD HOTEL";
    cout << "\n2. DISPLAY HOTEL";
    cout << "\n3. CHECK PARTICULAR HOTEL";
    cout << "\n4. UPDATE HOTEL";
    cout << "\n5. DELETE HOTEL";
    cout << "\n6. EXIT";
}

void HOTEL::add_HOTEL()
{
    system("cls");
    fstream file;
    int rms;
    string HOTELname, Hotel_Location, HOTEL_id;
    cout << "\n\n\t\t\t\tADD HOTEL";
    cout << "\n\nHOTEL ID : ";
    cin >> HOTEL_id;
    cout << "\nHOTEL NAME : ";
    cin >> HOTELname;
    cout << "\nHotel_Location : ";
    cin >> Hotel_Location;
    cout << "\nPrice per room(double bed only) : ";
    cin >> rms;

    file.open("HOTEL.txt",
              ios::out | ios::app);
    file << " " << HOTEL_id << " "
         << HOTELname << " " << Hotel_Location
         << " " << rms << "\n";
    file.close();
}

void HOTEL::show_HOTEL()
{
    system("cls");
    fstream file;
    int rms;
    string HOTELname, HOTEL_id, Hotel_Location;
    cout << "\n\n\t\t\t\t\tAll HOTEL";

    file.open("HOTEL.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nHOTEL ID\tHOTELNAME"
             << "\tHotel_Location\tPrice per room in the "
                "HOTEL\n\n";
        file >> HOTEL_id >> HOTELname;
        file >> Hotel_Location >> rms;

        while (!file.eof()) {

            cout << "  " << HOTEL_id
                 << "\t\t" << HOTELname
                 << "\t\t" << Hotel_Location
                 << "\t\t" << rms
                 << "\n\n";
            file >> HOTEL_id >> HOTELname;
            file >> Hotel_Location >> rms;
        }

        system("pause");
         file.close();
    }
}

void HOTEL::check_HOTEL()
{
    system("cls");
    fstream file;
    int rms, count = 0;
    string HOTEL_id, HOTELname, Hotel_Location, HOTEL_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular HOTEL";

    file.open("HOTEL.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nHOTEL ID : ";
        cin >> HOTEL_idd;
        file >> HOTEL_id >> HOTELname;
        file >> Hotel_Location >> rms;

        while (!file.eof()) {

            if (HOTEL_idd == HOTEL_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular HOTEL";
                cout << "\n\nHOTEL ID : "
                     << HOTEL_id;
                cout << "\nName : "
                     << HOTELname;
                cout << "\nLocation : "
                     << Hotel_Location;
                cout << "\nprice per room(double bed only) : "
                     << rms;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> HOTEL_id >> HOTELname;
            file >> Hotel_Location >> rms;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nHOTEL ID Not"
                 << " Found...";
    }
}

void HOTEL::checkanyhotelbyname()
{
    system("cls");
    fstream file;
    int rms, count = 0;
    string HOTEL_id, HOTELname, Hotel_Location, HOTEL_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular HOTEL";

    file.open("HOTEL.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nHotel Name : ";
        cin >> HOTEL_idd;
        file >> HOTEL_id >> HOTELname;
        file >> Hotel_Location >> rms;

        while (!file.eof()) {

            if (HOTEL_idd == HOTELname) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular HOTEL";
                cout << "\n\nHOTEL ID : "
                     << HOTEL_id;
                cout << "\nName : "
                     << HOTELname;
                cout << "\nLocation : "
                     << Hotel_Location;
                cout << "\nprice per room(double bed only) : "
                     << rms;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> HOTEL_id >> HOTELname;
            file >> Hotel_Location >> rms;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nHOTEL Not"
                 << " Found...";
    }
}

// Function to update the HOTEL
void HOTEL::update_HOTEL()
{
    system("cls");
    fstream file, file1;
    int rms, no_co, count = 0;
    string HOTELname, b_na, Hotel_Location;
    string a_na, HOTEL_idd, HOTEL_id;

    cout << "\n\n\t\t\t\tUpdate HOTEL Record";
    file1.open("HOTEL1.txt",
               ios::app | ios::out);
    file.open("HOTEL.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nHOTEL ID : ";
        cin >> HOTEL_id;
        file >> HOTEL_idd >> HOTELname;
        file >> Hotel_Location >> rms;

        // Till end of file is reached
        while (!file.eof()) {
            if (HOTEL_id == HOTEL_idd) {
                system("cls");
                cout << "\t\t\t\t"
                     << "Update HOTEL Record";
                cout << "\n\nNew HOTEL Name : ";
                cin >> b_na;
                cout << "\nHOTEL Name : ";
                cin >> a_na;
                cout << "\nprice per room(double bed only) : ";
                cin >> no_co;
                file1 << " " << HOTEL_id << " "
                      << b_na << " "
                      << a_na << " " << no_co
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << HOTEL_idd
                      << " " << HOTELname
                      << " " << Hotel_Location
                      << " " << rms
                      << "\n\n";
            file >> HOTEL_idd >> HOTELname;
            file >> Hotel_Location >> rms;
        }
        if (count == 0)
            cout << "\n\nHOTEL ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("HOTEL.txt");
    rename("HOTEL1.txt",
           "HOTEL.txt");
}

// Function to delete HOTEL
void HOTEL::del_HOTEL()
{
    system("cls");
    fstream file, file1;
    int rms, count = 0;
    string HOTEL_id, HOTEL_idd, HOTELname, Hotel_Location;
    cout << "\n\n\t\t\t\tDelete a HOTEL";

    // Append file in output mode
    file1.open("HOTEL1.txt",
               ios::app | ios::out);
    file.open("HOTEL.txt",
              ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nHOTEL ID : ";
        cin >> HOTEL_id;
        file >> HOTEL_idd >> HOTELname;
        file >> Hotel_Location >> rms;
        while (!file.eof()) {

            if (HOTEL_id == HOTEL_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a HOTEL";
                cout << "\n\nHOTEL is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << HOTEL_idd
                      << " " << HOTELname
                      << " " << Hotel_Location
                      << " " << rms
                      << "\n\n";
            file >> HOTEL_idd >> HOTELname;
            file >> Hotel_Location >> rms;
        }
        if (count == 0)
            cout << "\n\nHOTEL ID "
                 << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("HOTEL.txt");
    rename("HOTEL1.txt",
           "HOTEL.txt");
}

// Function for HOTEL shop record
void HOTELRECORD()
{
    int choice;
    char x;
    HOTEL b;

    while (1) {

        b.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_HOTEL();
                cout << "\n\nWant to add"
                     << " another HOTEL? "
                        "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_HOTEL();
            break;

        case 3:
            b.check_HOTEL();
            break;
        case 4:
            b.update_HOTEL();
            break;

        case 5:
            b.del_HOTEL();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}

void name_and_rol_no()
{
///system("color fc");
gotoxy(30, 16);
setColor(11);
cout << "PROJECT BY...";
gotoxy(30, 18);
setColor(14);
string name = "CHRIS ARYAN";
for (int i = 0; i<name.length(); i++)
{
Sleep(80);
cout << name[i];
}
setColor(14);
gotoxy(30, 19);
}

int tobecalledmain(){
    system("cls");
    loading();
    char x;
    draw_board();
    setColor(2);
    gotoxy(35, 10);
    cout << "Press [1] If you are a customer";
    gotoxy(35, 12);
    cout << "Press [2] If you are an admin";
    bool flag = true;
    while (flag)
    {
            if (_kbhit())
            {
                x = _getch();
                flag = false;
            }
    }
    switch(x)
    {
        case '1':
            {

                 break; }
        case '2':
            {
            label:if(Access())
                        Mainmenu();
                  else
                            goto label;
                            break;
            }

    }
    return 0;
}

void Mainmenu()
{

    system("CLS");
    char n;
hell:
    setColor(9);
    gotoxy(20, 1);
    cout << "*************** Welcome to Chennai International Airport ***************";
    gotoxy(45, 3);
    cout << "****** Main Menu ******";
    draw_board();
    setColor(2);
    gotoxy(35, 8);
    cout << "Press [1] For Flights .";
    gotoxy(35, 10);
    cout << "Press [2] For Staffs .";
    gotoxy(35, 12);
    cout << "Press [3] For Complaints .";
    gotoxy(35, 14);
    cout << "Press [4] Go to Hotels.";
    gotoxy(35, 16);
    cout << "Press [5] To Exit From The Program.";
    gotoxy(35, 18);
    bool flag = true;
    setColor(10);
    while (flag)
    {
            if (_kbhit())
            {
                n = _getch();
                flag = false;
            }
    }
    switch (n)
    {
    case '1':
        {
            FLIGHTSRECORD();
            break;
        }
    case '2':
        {
            STAFFRECORD();
            break;
        }
    case '3' :
        {
            COMPLAINTSRECORDFORADM();
        }
        case '4' :
        {
            HOTELRECORD();
        }
        case '5' :
        {
            tobecalledmain();
        }
    default:
        {
        setColor(12);
        cout << endl << "\aPlease Press Correct Button" << endl;
        goto hell;
        }
    }
}



int main()
{
    name_and_rol_no();
    loading();
    char x;
    system("cls");
    draw_board();
    setColor(2);
    gotoxy(35, 10);
    cout << "Press [1] If you are a customer";
    gotoxy(35, 12);
    cout << "Press [2] If you are an admin";
    bool flag = true;
    while (flag)
    {
            if (_kbhit())
            {
                x = _getch();
                flag = false;
            }
    }
    switch(x)
    {
        case '1':
            {
                VISITORSRECORD();

                 break; }
        case '2':
            {
            label:if(Access())
                        Mainmenu();
                  else
                            goto label;
                            break;
            }

    }
    return 0;
}
