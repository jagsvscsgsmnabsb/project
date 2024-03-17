#include <iostream>
#include <fstream>
using namespace std;
class cattle {
public:
   
    string name;
    int price;
    int quantity;
     cattle() {
         name = "";
         price = 0;
         quantity = 0;
    }
     void Add_Animal()
	  {
         cout << "Enter Name of Animals" << endl;
         cin >> name;
         cout << "Enter Price of Animals" << endl;
         cin >> price;
         cout << "Enter number(Quantity) of  Animals:" << endl;
         cin >> quantity;
         ofstream MyFile("Cattle.txt",  ios::app);

         // Write to the file
         MyFile <<  name<<endl;
         MyFile <<   price<<endl;
         MyFile <<  quantity<<endl;


         // Close the file
         MyFile.close();

     }
     void Display_Animalrecord() {
         string myText;

         ifstream MyReadFile("Cattle.txt");

         // Use a while loop together with the getline() function to read the file line by line
         while (getline(MyReadFile, myText)) {
             // Output the text from the file
             cout <<" Name of Animals : " + myText<<endl;
             getline(MyReadFile, myText);
             cout << "Price of Animals  : " + myText << endl;
             getline(MyReadFile, myText);
             cout << "Quantity  of  Animals : " + myText<<endl;
             cout << endl;
         }

         // Close the file
         MyReadFile.close();
     }

     void Delete_Record() {
         string name;
         string temp;
         string myText;
         cout << " selled  Animals name:" << endl;
         cin >> name;

         ifstream MyReadFile("Cattle.txt");

         // Use a while loop together with the getline() function to read the file line by line
         while (getline(MyReadFile, myText)) {
             // Output the text from the file
             if (myText == name) {
                 getline(MyReadFile, myText);
                 getline(MyReadFile, myText);
                 getline(MyReadFile, myText);
             }
             else {
                 temp += myText + "\n";
             }
         }

         // Close the file
         MyReadFile.close();


         ofstream MyFile;
         MyFile.open("Cattle.txt",ios::trunc);

         // Write to the file
         MyFile << temp;
         


         // Close the file
         MyFile.close();

     }
     void Modify_record() {
         string name;
         string temp;
         string myText;
         cout << "Correct the Record of Animals:" << endl;
         cin >> name;

         ifstream MyReadFile("Cattle.txt");

         // Use a while loop together with the getline() function to read the file line by line
         while (getline(MyReadFile, myText)) {
             // Output the text from the file
             if (myText == name) {
                 temp += myText + "\n";
                 getline(MyReadFile, myText);
                 getline(MyReadFile, myText);
                 getline(MyReadFile, myText);
                 cout << "Enter Price  of Animals :" << endl;
                 cin >> price;
                 temp += price + "\n";
                 cout << "Enter number(Quantity) of Animals :" << endl;
                 cin >> quantity;
                 temp += quantity + "\n";
                 temp += quantity*price;
                 cout<<temp;
             }
             else {
                 temp += myText + "\n";
             }
         }

         // Close the file
         MyReadFile.close();


         ofstream MyFile;
         MyFile.open("Cattle.txt", ios::trunc);

         // Write to the file
         MyFile << temp;



         // Close the file
         MyFile.close();

     }

     void Search_Animal() {
         string name;
         string myText;
         cout << "Enter name of  Animals ::you want to Search: " << endl;
         cin >> name;

         ifstream MyReadFile("Cattle.txt");

         // Use a while loop together with the getline() function to read the file line by line
         while (getline(MyReadFile, myText)) {
             // Output the text from the file
             if (myText == name) {
                 cout << " Name Of Animal : " + myText << endl;
                 getline(MyReadFile, myText);
                 
                 cout << "Price of Animal : " + myText << endl;
                 getline(MyReadFile, myText);
                 cout << "Quantity of Animals  : " + myText << endl;
                 cout << endl;
             }
             else{
             	cout<<"No Animal Found:"<<endl;
             	break;
			 }
         }

         // Close the file
         MyReadFile.close();

     }
     
};
int main()
{   
    int option;
    char choice='y';
    cattle caller;
    do {
        system("cls");
        cout << "===========E-Cattle System===========" << endl;
        cout << endl;
        cout << "Options" << endl;
        cout << endl;
        cout << "1. Enter the New  Animals Information" << endl;
        cout << "2. Show the Animals Information" << endl;
        cout << "3. Enter the selled Animals  " << endl;
        cout << "4. Correct the Information of Animals " << endl;
        cout << "5. Search the Animals By Name  " << endl;
        cout << "6. Close the  E-Cattle System" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            caller.Add_Animal();
            break;
        case 2:
            system("cls");
            caller.Display_Animalrecord();
            break;
        case 3:
            system("cls");
            caller.Delete_Record();
            break;
        case 4:
            system("cls");
            caller.Modify_record();
            break;
        case 5:
            system("cls");
            caller.Search_Animal();
            
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid Option"<<endl;
            break;
        }
        cout << "Do you want to Continue (y/n)" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

