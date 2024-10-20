#include <iostream>
using namespace std;
    enum menuItems {
        ADD = 1,
        DELETE = 2,
        EDIT = 3,
        SEARCH = 4,
        SHOW = 5,
        QUIT = 0
    };

    struct todolist {
        char name[15];
        char description[30];
        int priority;
        float date;
    };

    //прототипы
    todolist* AddStruct(todolist* Obj, const int amount);
    void setdata(todolist* Obj, const int amount);
    void editdata(todolist* Obj, const int amount);
    void showdata(const todolist* Obj, const int amount);
    void deldata(const todolist* Obj, const int amount);
    
    void SortName(todolist* Things, int n);
    void SortDescription(todolist* Things, int n);
    void SortPriority(todolist* Things, int n);
    void SortDate(todolist* Things, int n);

    void SearchName(todolist* Things, int n);
    void SearchDescription(todolist* Things, int n);
    void SearchPriority(todolist* Things, int n);
    void SearchDate(todolist* Things, int n);

    todolist* Things = 0;
    int thingsamount = 0;

    int option;
    int confirm;

    
    int main() {


        cout << "Welcome to your To-Do list!\n" << endl;
        cout << "Choose an option by entering the number: \n 1- Add a new note;\n 2- Delete a note;\n 3- Edit a note;\n 4- Search for a note;\n 5- Show to-do list;\n 0 - quit." << endl;
        cin >> option;

        switch (option) {


        case QUIT:
            cout << "Are you sure you want to quit?(0-no!stay; 1-yes!quit) ";
            cin >> confirm;
            if (confirm != 1) {
                system("cls");
                return main();
            }
            else {
                cout << "Thanks for coming over!";
               
                return 1;
            }



        case ADD:
            do {

                Things = AddStruct(Things, thingsamount);

                setdata(Things, thingsamount);
                thingsamount++;

                cout << "Continue? 1-yes, 0- stop : ";
                cin >> confirm;
                cin.get();

            } while (confirm != 0);
            system("cls");
            return main();

        case DELETE:
                showdata(Things, thingsamount);
                
                cout << "Are you sure you want to delete all your notes?\n The data will be lost forever!(1-delete;0-back)";
                cin >> confirm;
                if(confirm==1)
                    delete[] Things;
                system("cls");
                return main();

        case EDIT:
                  cout << "Enter the number of note you want to modify: (not more than " << thingsamount << ") ";
                  int modify;
                  cin >> modify;
                  modify--;
                  if (modify >= 0 && modify < thingsamount) {
                      editdata(Things, modify);
                      system("cls");
                      return main();
                  }
                  else {
                      system("cls");
                      cout << "Wrong input!";
                      cout << endl;
                      return main();
                  }



        case SEARCH:
                cout << "Do you want to search for: 1-name; 2-description; 3-priority; 4-data?";
                cin >> confirm;
                switch (confirm) {
                case 1:
                    system("cls");
                    SearchName(Things, thingsamount);
                    
                    return main();
                case 2:
                    system("cls");
                    
                    SearchDescription(Things, thingsamount);
                    return main();
                case 3:
                    system("cls");
                    
                    SearchPriority(Things, thingsamount);
                    return main();
                case 4:
                    system("cls");
                    
                    SearchDate(Things, thingsamount);
                    return main();
                default:
                    system("cls");
                    cout << "Wrong input!";
                    cout << endl;
                    return main();
                }
            
        case SHOW:
                cout << "Do you want to sort data?(1-yes;0-no)";
                cin >> confirm;
                if (confirm == 1) {
                    cout << "Sort by (1-name,2-description,3-priority,4-date)";
                    cin >> confirm;
                switch (confirm) {
                    case 1:
                            system("cls");

                            SortName(Things, thingsamount);
                            showdata(Things, thingsamount);
                            cout << endl;
                            return main();
                    
                    case 2:
                            system("cls");
                            SortDescription(Things, thingsamount);
                            showdata(Things, thingsamount);
                            cout << endl;
                            return main();
                    
                    case 3:
                            system("cls");
                            SortPriority(Things, thingsamount);
                            showdata(Things, thingsamount);
                            cout << endl;
                            return main();
                    
                     case 4:
                            system("cls");
                            SortDate(Things, thingsamount);
                            showdata(Things, thingsamount);
                            cout << endl;
                            return main();
                     default:
                         system("cls");
                         cout << "Wrong input!";
                         cout << endl;
                         return main();
                    }

            }
                else {
                        cout << "Show data for: 1-day, 2-month, 3-all?";
                        cin >> confirm;
                        if (confirm == 3) {
                            system("cls");
                            
                            showdata(Things, thingsamount);
                            return main(); 
                        }
                        else if (confirm == 1) {
                            system("cls");
                            SearchDate(Things, thingsamount);
                            return main();
                        }
                        else {
                            system("cls");
                           
                            int monthsearch;
                            cout << "Enter the month: ";
                            cin >> monthsearch;
                            for (int i = 0; i < thingsamount; i++) {
                                if (Things[i].date == monthsearch) {
                                    cout << i + 1<< "). " << Things[i].name << "\n" << Things[i].description << "\n" << Things[i].priority << "\n" << Things[i].date << endl;
                                }
                            } 
                            return main();
                        }
                }
            
                  
        } 

    delete[] Things;
    return 1;
    }

todolist* AddStruct(todolist * Obj, const int amount) {
    todolist* tempObj = new todolist[amount + 1];
    for (int i = 0; i < amount; i++) {
    tempObj[i] = Obj[i];
    }

    delete[]Obj;

    return tempObj;
    }

void setdata(todolist* Obj, const int amount) {
    cout << "Start entering data.\n";
       
    cout << "Name: ";
    // cin.getline(Obj[amount].name, 15);
    cin >> Obj[amount].name;
    cout << "Description: ";
    //cin.getline(Obj[amount].description, 30);
    cin >> Obj[amount].description;
    cout << "Priority: ";
    cin >> (Obj[amount].priority);
    cout << "Due date(month.day): ";
    cin >> (Obj[amount].date);
    //cin.get();
    cout << endl;
    }


void editdata(todolist* Obj, const int amount) {     
    cout << "Start editing data.\n";

    cout << "Name: ";
    // cin.getline(Obj[amount].name, 15);
    cin >> Obj[amount].name;
    cout << "Description: ";
    //cin.getline(Obj[amount].description, 30);
    cin >> Obj[amount].description;
    cout << "Priority: ";
    cin >> (Obj[amount].priority);
    cout << "Due date(month.day): ";
    cin >> (Obj[amount].date);
    //cin.get();
    cout << endl;
    }


void showdata(const todolist* Obj, const int amount) {
    for (int i = 0; i < amount; i++) {
        cout << i + 1 << ". Name: " << Obj[i].name <<
            ";\n Description: " << Obj[i].description <<
            ";\n Priority: " << Obj[i].priority <<
            ";\n Date/deadline: " << Obj[i].date << endl;
    }
}


void SortPriority(todolist* Things, int n) {
    todolist temp;
    int top, seek;
    for (top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (Things[top].priority, Things[seek].priority > 0) {
                temp = Things[top];
                Things[top] = Things[seek];
                Things[seek] = temp;
            }
        }
    }
}
void SortDate(todolist* Things, int n) {
    todolist temp;
    int top, seek;
    for (top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (Things[top].date, Things[seek].date > 0) {
                temp = Things[top];
                Things[top] = Things[seek];
                Things[seek] = temp;
            }
        }
    }
}

void SortName(todolist* Things, int n) {
    todolist temp;
    int top, seek;
    for (top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (strcmp(Things[top].name, Things[seek].name) > 0) {
                temp = Things[top];
                Things[top] = Things[seek];
                Things[seek] = temp;
            }
        }
    }
}

void SortDescription(todolist* Things, int n) {
    todolist temp;
    int top, seek;
    for (top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (strcmp(Things[top].description, Things[seek].description) > 0) {
                temp = Things[top];
                Things[top] = Things[seek];
                Things[seek] = temp;
            }
        }
    }
}





void SearchName(todolist* Things, int n) {
    char searchname[15];
    cout << "Enter the name you're looking for: ";
    cin >> searchname;
    
    for (int i = -1; i < n; i++) {
        //cout << Things[i].name;
        if (Things[i].name == searchname) {
            cout << i + 1 << "). " << Things[i].name << "\n" << Things[i].description << "\n" << Things[i].priority << "\n" << Things[i].date << endl;
        }
    }
}

void SearchDescription(todolist* Things, int n) {
    char searchdescription[35];
    cout << "Enter the description you're looking for: ";
    cin >> searchdescription;
    for (int i = 0; i < n; i++) {
        if (Things[i].description == searchdescription) {
            cout << i + 1 << "). " << Things[i].name << "\n" << Things[i].description << "\n" << Things[i].priority << "\n" << Things[i].date << endl;
        }
    }
}

void SearchPriority(todolist* Things, int n) {
    int searchpriority;
    cout << "Enter the priority you're looking for: ";
    cin >> searchpriority;
    for (int i = 0; i < n; i++) {
        if (Things[i].priority == searchpriority) {
            cout << i + 1 << "). " << Things[i].name << "\n" << Things[i].description << "\n" << Things[i].priority << "\n" << Things[i].date << endl;
        }
    }
}

void SearchDate(todolist* Things, int n) {
    float daysearch;
    cout << "Enter the date you're looking for(month.day): ";
    cin >> daysearch;
    for (int i = 0; i < n; i++) {
        if (Things[i].date == daysearch) {
            cout << i + 1 << "). " << Things[i].name << "\n" << Things[i].description << "\n" << Things[i].priority << "\n" << Things[i].date << endl;
        }
    }
}