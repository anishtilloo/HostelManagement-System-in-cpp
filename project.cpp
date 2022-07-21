#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

class LoginSystem
{
private:
    string userName, password, un, pw;

public:
    bool IsLoggedIn()
    {
        cout << "\nEnter Username: ";
        cin >> userName;

        cout << "\nEnter Password: ";
        cin >> password;

        ifstream read(userName + ".txt");
        getline(read, un);
        getline(read, pw);

        if (un == userName && pw == password)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Block : public LoginSystem
{
public:
    int block;
    void Get_Block()
    {
        cout << "\n\n*************";
        cout << "ROOMS AVAILABLE FOR BOOKING   ";
        cout << "*************";
        cout << "\n\nPlease select your preferable Block :";
        cout << "\n\n1: Block A \n\n2: Block B \n";
        cout << "\nPlease enter your choice : ";

        cin >> block;
    }
    int Get_Blocknum()
    {

        if (block == 1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};
class Floor : public Block
{
public:
    int floornum;
    int wingnum;
    void Get_Floor()
    {
        if (Get_Blocknum() == 1)
        {
            cout << "\nAvailable Floors for Block A are : \n\n1: GROUND FLOOR \n\n2: FIRST FLOOR \n\n3: SECOND FLOOR\n ";
        }
        else
        {
            cout << "\nAvailable Floors for Block B are : \n\n1: GROUND FLOOR \n\n2: FIRST FLOOR\n ";
        }
        cout << "Please enter your choice : ";
        cin >> floornum;
    }
    int Get_floornum()
    {
        if (floornum == 1)
        {
            return 1;
        }
        else if (floornum == 2)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
    void Get_Wing()
    {
        cout << "\n\n*************";
        cout << "Enter Suitable Wing ";
        cout << "*************";
        cout << "\n\n1: EAST WING\n\n2: WEST WING\n";
        cout << "\nPlease enter your choice : ";
        cin >> wingnum;
    }
    int Get_Wingnum()
    {
        if (wingnum == 1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};
class Room : public Floor
{
public:
    int roomsize;
    int roomnum;
    int messnum;
    int r1 = 40000, r2 = 35000, r3 = 32000;
    int m1 = 18000, m2 = 22000;
    void Get_Room()
    {
        cout << "\n\n*************";
        cout << "Following rooms sizes are available ";
        cout << "*************";
        cout << "\n1: SINGLE BED ROOM COST Rs-40000 per annum\n";
        cout << "\n2: DOUBLE BED ROOM COST Rs-35000 per annum\n";
        cout << "\n3: TRIPLE BED ROOM COST Rs-32000 per annum\n";
        cout << "\n(note - Above amount is excluding Caution money charge Rs-5000)\n";
        cout << "\nPlease enter your preference : ";
        cin >> roomsize;
    }
    void Get_Mess()
    {
        cout << "\n\n*************";
        cout << "PLEASE SELECT SUITABLE MESS";
        cout << "*************";
        cout << "\n1: VEGITERIAN MESS COST Rs-18000 per annum\n";
        cout << "\n2: NON-VEGITERIAN MESS COST Rs-22000 per annum\n";
        cout << "\n (note - Timing for breakfast, lunch and dinner may differ depending on weekdays.)\n";
        cout << "\nPlease enter your preference : ";
        cin >> messnum;
    }
    void Print_Details()
    {
        cout << "\n\n*************";
        cout << "PLEASE REVIEW YOUR ENTERED DETAILS";
        cout << "*************\n\n";

        if (Get_Blocknum() == 1)
        {
            cout << "SELECTED BLOCK  :  BLOCK A\n ";
        }
        else
        {
            cout << "SELECTED BLOCK  :  BLOCK B\n";
        }

        if (Get_Wingnum() == 1)
        {
            cout << "\nWING SELECTED : EAST WING\n";
        }
        else
        {
            cout << "\nWING SELECTED : WEST WING\n";
        }

        if (Get_floornum() == 1)
        {
            cout << "\nFLOOR SELECTED : FIRST FLOOR\n";
        }
        else if (Get_floornum() == 2)
        {
            cout << "\nFLOOR SELECTED : SECOND FLOOR\n";
        }
        else
        {
            cout << "\nFLOOR SELECTED : THIRD FLOOR\n";
        }

        if (roomsize == 1)
        {
            cout << "\nSINGLE BED ROOM COST  :  Rs-40000 per annum\n";
        }
        else if (roomsize == 2)
        {
            cout << "\nDOUBLE BED ROOM COST :  Rs-35000 per annum\n";
        }
        else
        {
            cout << "\nTRIPLE BED ROOM COST  :  Rs-32000 per annum\n";
        }

        if (messnum == 1)
        {
            cout << "\nVEGITERIAN MESS COST  :  Rs-18000 per annum\n";
        }
        else
        {
            cout << "\nNON-VEGITERIAN MESS COST :  Rs-22000 per annum\n";
        }
    }
    void calulator()

    {
        cout << "\n\n********************";
        cout << "\nTOTAL COST = ";

        if (roomsize == 1)
        {
            if (messnum == 1)
            {
                cout << r1 + m1;
            }
            else
            {
                cout << r1 + m2;
            }
        }
        else if (roomsize == 2)
        {
            if (messnum == 1)
            {
                cout << r2 + m1;
            }
            else
            {
                cout << r2 + m2;
            }
        }
        else
        {
            if (messnum == 1)
            {
                cout << r3 + m1;
            }
            else
            {
                cout << r3 + m2;
            }
        }
    }
};
class Register : public Room
{
public:
    int choice;
    void Choice()
    {
        cout << "\n\n1: Register \n\n2: Login:\n\nPlease your choice : ";
        cin >> choice;

        if (choice == 1)
        {
            string userName, password;

            cout << "Select a Username: ";
            cin >> userName;

            cout << "Select a Password: ";
            cin >> password;

            ofstream file;
            file.open(userName + ".txt");

            file << userName << endl
                 << password;
            file.close();

            Choice();
        }
        else if (choice == 2)
        {
            bool status = IsLoggedIn();

            if (status != true)
            {
                cout << "\nFalse Login Credentials" << endl;
            }
            else
            {
                cout << "\nSuccessfully Logged In" << endl;
                Get_Block();
                Get_Wing();
                Get_Floor();
                Get_Room();
                Get_Mess();
                Print_Details();
                calulator();
            }
        }
        exit(true);
    }
};

int main()
{
    cout << "\n\n*****WELOCOME TO TNPS HOSTEL PORTAL****** \n";
    Register P1;
    P1.Choice();
    P1.IsLoggedIn();

    return 0;
}