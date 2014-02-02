//Shimeng Cui
//This program is a binary search tree based database that will store website URLs
//Tree functions such as add, delete, remove, find, etc. are included

#include <iostream> //standard header files to allow for use of strings, stringstreams, etc.
#include <string>
#include <sstream>
#include <iomanip>

#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"

using namespace std;

int main(){
    TreeDB tree;

    cout.setf (ios::fixed); //make sure everything prints as decimals and not scientific notation

    string userInputOriginal;
    int intArg; //used temporarily to store any integer user inputs

    while (!cin.eof()){
        string command, stringArg1, stringArg2; //variables for string arguments. Inside loop because I need to reinitate to null string every loop through

        cout << "> ";

        if (cin.eof()) //if end of file, exit loop
            break;

        getline(cin, userInputOriginal); //gets user input.
        stringstream userInput (userInputOriginal);

        userInput >> command;

        if (command == "insert"){
            bool inserted;
            userInput >> stringArg1 >> intArg >> stringArg2;
            if (stringArg2 == "active"){
                DBentry* tmp = new DBentry(stringArg1, intArg, true); //creates new DBentry object and inserts
                inserted = tree.insert(tmp); //insert returns bool of whether insert was successful or not
            }
            else{
                DBentry* tmp = new DBentry(stringArg1, intArg, false);
                inserted = tree.insert(tmp);
            }
            if (inserted == true) //if inserted
                cout << "Success" << endl;
            else if (inserted == false) //if not inserted
                cout << "Error: entry already exists" << endl;
        }

        else if (command == "remove"){
            userInput >> stringArg1;
            bool removed = tree.remove(stringArg1); //remove returns bool for whether remove was successful or not
            if (removed == true)
                cout << "Success" << endl;
            else
                cout << "Error: entry does not exist" << endl;
        }

        else if (command == "find"){
            userInput >> stringArg1;
            DBentry* tmp;
            tmp = tree.find(stringArg1);
            if (tmp == NULL) //the requested name is not found
                cout << "Error: entry does not exist" << endl;
            else{ //it is found what gets printed depends on if it's active or not
                if (tmp->getActive() == true)
                    cout << tmp->getName() << " : " << tmp->getIPaddress() << " : active" << endl;
                else
                    cout << tmp->getName() << " : " << tmp->getIPaddress() << " : inactive" << endl;
            }
        }

        else if (command == "printall"){
            tree.printAll();
        }

        else if (command == "printprobes"){
            userInput >> stringArg1;
            DBentry* tmp = tree.find(stringArg1); //this is needed because the find function also sets number of probes needed to find an entry
            if (tmp != NULL){
                tree.printProbes();
            }
            else
                cout << "Error: entry does not exist" << endl;
        }

        else if (command == "removeall"){
            tree.clear();
            cout << "Success" << endl;

        }

        else if (command == "countactive"){
            tree.countActive();
        }

        else if (command == "updatestatus"){
            userInput >> stringArg1 >> stringArg2;
            DBentry* tmp;
            tmp = tree.find(stringArg1);
            if (stringArg2 == "active" && tmp != NULL){
                tmp->setActive(true); //sets to active
            }
            else if (stringArg2 == "inactive" && tmp != NULL)
                tmp->setActive(false); //sets to inactive
            if (tmp == NULL) //if entry not found it will return NULL
                cout << "Error: entry does not exist" << endl;
            else
                cout << "Success" << endl;
        }
        userInput.clear(); //clears and ignores rest of stringstream
        userInput.ignore(1000,'\n');
    }
    return 0;
}
