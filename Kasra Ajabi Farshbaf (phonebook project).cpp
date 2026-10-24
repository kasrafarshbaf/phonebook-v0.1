#include <iostream>
#include <string>
#include <vector>
#include <limits> 
using namespace std;

struct Contact { 
    string First_name;
    string Last_name;
    int phone;
    string email_address;
    string social_media;
};

vector<Contact> phonebook; 
//Contact adding
void Add() 
{
    Contact new_contact; 
    system("cls"); 
    cout << "==================\n";
    cout << "Please enter the First name :\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, new_contact.First_name);
    cout << "Please enter the Last name :\n";
    getline(cin, new_contact.Last_name);
    cout << "Please enter the phone number :\n";
    while (!(cin >> new_contact.phone)) { 
        cout << "Please enter the numeric phone number :\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cout << "Please enter the email address :\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, new_contact.email_address);
    cout << "Please enter the social media username :\n";
    getline(cin, new_contact.social_media);
    phonebook.push_back(new_contact);
    cout << "The new contact is added to your phonebook!\n\n";
    system("pause");
}
//Contact searching
void Searchcontact() 
{
    string key;
    cout << "Enter the name to search:";
    cin >> key;

    bool found = false;
    for (const auto& contact : phonebook) 
	{ 
           if (contact.First_name == key || contact.Last_name == key) 
		   {
            cout << "The contact is found: " << contact.First_name << " " << contact.Last_name << endl;
            cout << " Phone number: " << contact.phone << endl;
            cout << " Email: " << contact.email_address << endl;
            cout << " Social media: " << contact.social_media << endl;
            found = true;
			}
    }
    if (!found) 
	{
        cout << "No such a contact found.\n";
    }
    cout << endl;
    system("pause");
}
//Contact showing
void Displayall() 
{ 
    if (phonebook.empty()) 
	{
        cout << "The phonebook is empty.\n\n";
        return;
    }
    cout << "==================\n";
    cout << " The list of contacts\n";
    cout << "==================\n";
    for (size_t i = 0; i < phonebook.size(); ++i) 
	{ 
        cout << i + 1 << ". " << phonebook[i].First_name << " " << phonebook[i].Last_name
             << " - " << phonebook[i].phone << endl;
    }
    cout << endl;
    system("pause");
}
//Contact deleting
void Deletecontact() 
{
    string key;
    cout << "Enter name to delete:";
    cin >> key;
    bool deleted = false;
    for (int i = phonebook.size() - 1; i >= 0; --i) 
	{
        if (phonebook[i].First_name == key || phonebook[i].Last_name == key) 
		{
            phonebook.erase(phonebook.begin() + i);
            cout << "Contact '" << key << "' is deleted.\n";
            deleted = true;
        }
    }
    if (!deleted) 
	{
        cout << "The contact with this name '" << key << "' is not found.\n\n";
    }
    system("pause");
}
//Contact editing
void Editcontact() 
{
    string key;
    cout << "??? ?????? ?? ?? ?? ?????? ?????? ???? ???? ????:";
    cin >> key;
    bool found_and_edited = false;
    for (auto& contact : phonebook) 
	{ 
        if (contact.First_name == key || contact.Last_name == key) 
		{
            cout << "Old information: " << contact.First_name << " " << contact.Last_name << ", phone: " << contact.phone << endl;
            
            cout << "Enter the new First name (If you do not change,please enter the enter button):";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            string new_first_name;
            getline(cin, new_first_name);
            if (!new_first_name.empty()) 
			{
                contact.First_name = new_first_name;
            }

            cout << "Please enter new Last name(If you do not change,please enter the enter button):";
            string new_last_name;
            getline(cin, new_last_name);
            if (!new_last_name.empty()) 
			{
                contact.Last_name = new_last_name;
            }

            cout << "Please enter new phone number(If you do not change,please enter 0):";
            int new_phone;
            while (!(cin >> new_phone)) 
			{
                cout << "The input is invalid,Please enter the numeric phone number or 0:\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (new_phone != 0) {
                contact.phone = new_phone;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            cout << "Please enter new email address(If you do not change,please enter the enter button):";
            string new_email;
            getline(cin, new_email);
            if (!new_email.empty()) 
			{
                contact.email_address = new_email;
            }

            cout << "Please enter new username(If you do not change,please enter the enter button):";
            string new_social;
            getline(cin, new_social);
            if (!new_social.empty()) 
			{
                contact.social_media = new_social;
            }

            cout << "The contact information '" << key << "' is updated!\n\n";
            found_and_edited = true;
            return; 
        }
    }
    if (!found_and_edited) 
	{
        cout << "Contact with this name '" << key << "' is not found.\n\n";
    }
   system("pause");
}

int menu() {
    int choice;
   system("cls"); 
    cout << "==========================\n";
    cout << "\t Phonebook \t\n"; 
    cout << "==========================\n";
    cout << "1.Add Contact..." << endl;
    cout << "2.Search contact..." << endl;
    cout << "3.Display all contact..." << endl;
    cout << "4.Delete contact..." << endl;
    cout << "5.Edit contact..." << endl;
    cout << "6.Exit..." << endl;
    cout << "----------------------------\n";
    cout << "Your choice: ";

    while (!(cin >> choice)) { 
        cout << "????? ??????? ???. ???? ?? ??? ??? 1 ?? 6 ???? ????:\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    return choice;
}

int main() {
    int z;

    while (true) {
        z = menu();
        switch (z) {
            case 1:
                Add();
                break;
            case 2:
                Searchcontact(); 
                break;
            case 3:
                Displayall(); 
                break;
            case 4:
                Deletecontact(); 
                break;
            case 5:
                Editcontact(); 
                break;
            case 6:
                cout << "?? ??? ???? ...\n";
                return 0;
            default:
                cout << "Invalid choice!\n\n";
                system("pause"); 
                break;
        }
    }
}
