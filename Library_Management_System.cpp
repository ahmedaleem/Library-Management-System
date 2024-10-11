#include <iostream>
#include <conio.h>
using namespace std;
class library
{
private:
    struct Node
    {
        int id;
        string name, author, publisher;
        Node *next_add;
    };

public:
    Node *head = NULL;
    void menu();
    void insert();
    void search();
    void update();
    void del();
    void sort();
    void show();
};
void library::menu()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\t=================================================";
    cout << "\n\n\t\t\t=========== LIBRARY MANAGEMENT SYSTEM ===========";
    cout << "\n\n\t\t\t=================================================" << endl;
    cout << "1) Insert new record" << endl;
    cout << "2) Search Record" << endl;
    cout << "3) Update Record" << endl;
    cout << "4) Delete Record" << endl;
    cout << "5) Show Record" << endl;
    cout << "6) Exit" << endl;
    cout << "ENTER YOUR CHOICE: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        search();
        break;
    case 3:
        update();
        break;
    case 4:
        del();
        break;
    case 5:
        sort();
        show();
        break;
    case 6:
        exit(0);
    default:
        cout << "Choose a valid choice" << endl;
    }
    system("pause");
    goto p;
}
void library::insert()
{
    system("cls");
    cout << "\n\n\t\t\t=================================================";
    cout << "\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM============";
    cout << "\n\n\t\t\t=================================================" << endl;
    Node *new_node = new Node;
    cout << "BOOK ID: ";
    cin >> new_node->id;
    cout << "NAME: ";
    cin >> new_node->name;
    cout << "AUTHOR NAME: ";
    cin >> new_node->author;
    cout << "PUBLISHER NAME: ";
    cin >> new_node->publisher;
    new_node->next_add = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next_add != NULL)
        {
            ptr = ptr->next_add;
        }
        ptr->next_add = new_node;
    }
    cout << "\n\n\t\t\tNew Book Inserted Successfully....." << endl;
    cout << "Press Enter" << endl;
}
void library::search()
{
    system("cls");
    int t_id, found = 0;
    cout << "\n\n\t\t\t=================================================";
    cout << "\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM============";
    cout << "\n\n\t\t\t=================================================" << endl;
    if (head == NULL)
    {
        cout << "\n\nLinked List is Empty.....";
    }
    else
    {
        cout << "BOOK ID: ";
        cin >> t_id;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                system("cls");
                cout << "\n\n\t\t\t=================================================";
                cout << "\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM============";
                cout << "\n\n\t\t\t=================================================" << endl;
                cout << " BOOK ID: " << ptr->id;
                cout << " BOOK NAME: " << ptr->name;
                cout << " AUTHOR NAME: " << ptr->author;
                cout << " PUBLISHER NAME: " << ptr->publisher << endl;
                found++;
            }
            ptr = ptr->next_add;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\tBook ID is Invalid.....";
        }
    }
}
void library::update()
{
    system("cls");
    int t_id, found = 0;
    cout << "\n\n\t\t\t=================================================";
    cout << "\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM============";
    cout << "\n\n\t\t\t=================================================" << endl;
    if (head == NULL)
    {
        cout << "\n\nLinked List is Empty.....";
    }
    else
    {
        cout << "Enter the ID of book you want to update:" << endl;
        cout << "BOOK ID: ";
        cin >> t_id;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                system("cls");
                cout << "\n\n\t\t\t=================================================";
                cout << "\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM============";
                cout << "\n\n\t\t\t=================================================" << endl;
                cout << "Enter Information:" << endl;
                cout << "BOOK ID: " << endl;
                cin >> ptr->id;
                cout << "BOOK NAME: " << endl;
                cin >> ptr->name;
                cout << "AUTHOR NAME: " << endl;
                cin >> ptr->author;
                cout << "PUBLISHER NAME: " << endl;
                cin >> ptr->publisher;
                found++;
                cout << "\n\n\t\t\tUpdated the book successfully";
                cout << "Press Enter" << endl;
            }
            ptr = ptr->next_add;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\tBook ID is Invalid.....";
        }
    }
}
void library::del()
{
    system("cls");
    int t_id, found = 0;
    cout << "\n\n\t\t\t=================================================";
    cout << "\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM============";
    cout << "\n\n\t\t\t=================================================" << endl;
    if (head == NULL)
    {
        cout << "\n\nLinked List is Empty.....";
    }
    else
    {
        cout << "BOOK ID: ";
        cin >> t_id;
        if (t_id == head->id)
        {
            Node *ptr = head;
            head = head->next_add;
            delete ptr;
            cout << "\n\n Delete book successfully." << endl;
            cout << "Press Enter" << endl;
            found++;
        }
        else
        {
            Node *pre = head;
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    pre->next_add = ptr->next_add;
                    delete ptr;
                    cout << "\n\n Delete Book Successfully." << endl;
                    cout << "Press Enter" << endl;
                    found++;
                    break;
                }
                pre = ptr;
                ptr = ptr->next_add;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Book ID is invalid.";
        }
    }
}
void library::sort()
{
    if (head == NULL)
    {
        system("cls");
        cout << "\n\nlinked list is empty";
        system("pause");
        menu();
    }
    int count = 0, t_id;
    string t_name, t_author, t_publisher;
    Node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next_add;
    }
    for (int i = 1; i <= count; i++)
    {
        Node *ptr = head;
        for (int j = 1; j < count; j++)
        {
            if (ptr->id > ptr->next_add->id)
            {
                // saving data into temporary node
                t_id = ptr->id;
                t_name = ptr->name;
                t_author = ptr->author;
                t_publisher = ptr->publisher;
                // save data into current node
                ptr->id = ptr->next_add->id;
                ptr->name = ptr->next_add->name;
                ptr->author = ptr->next_add->author;
                ptr->publisher = ptr->next_add->publisher;
                // saving data into next node
                ptr->next_add->id = t_id;
                ptr->next_add->name = t_name;
                ptr->next_add->author = t_author;
                ptr->next_add->publisher = t_publisher;
            }
            ptr = ptr->next_add;
        }
    }
}
void library::show()
{
    system("cls");
    cout << "\n\n\t\t\t=================================================";
    cout << "\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM============";
    cout << "\n\n\t\t\t=================================================" << endl;
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout << "BOOK ID: " << ptr->id;
        cout << "\nBOOK NAME: " << ptr->name;
        cout << "\nAUTHOR NAME: " << ptr->author;
        cout << "\nPUBLISHER NAME: " << ptr->publisher;
        cout << "\n\n\n========================================================" << endl;
        ptr = ptr->next_add;
    }
    cout << "\n\n\n========================================================";
    cout << "Press Enter" << endl;
}
int main()
{
    library obj;
    obj.menu();
    return 0;
}