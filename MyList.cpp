#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
private:
    Node *head;
public:
    List() {head = NULL;}
    int length = 0;
    void add_tail(int new_data)
    {
        Node *new_node = new Node;
        new_node->data = new_data;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *current = head;

            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next  = new_node;
        }
        length ++;
    }

    void add_head(int new_data)
    {
        Node *new_node = new Node;
        new_node->data = new_data;
        new_node->next = head;
        head = new_node;
        length ++;
    }

    void print_list()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void print_length()
    {
        cout << length << endl;
    }

    void delete_tail()
    {
        if (!head)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            Node* current = head;
            int i = 1;
            while (i < length - 1)
            {
                current = current->next;
                i += 1;
            }
            delete current->next;
            current->next = NULL;
            length --;
        }
    }


    void delete_head()
    {
        if (!head)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            Node *bufer = head->next;
            delete head;
            head = bufer;
        }
        length --;
    }

    void insertByIndex(int index,int new_data)
    {
        if (index > length)
        {
         cout << "index > length" << endl;
        }
        else
        {
            Node *current = head;
            int i  = 0;
            while (i < (index-2) )
            {
                current = current->next;
                i ++;
            }
            Node *new_node = new Node;
            new_node->data = new_data;
            new_node->next = current->next->next;
            current->next  = new_node;
        }
        length ++;
    }
    void is_list_looped()
    {
        int flag = 0;
        int i = 1;
        Node *current1 = head;
        Node *current2 = head->next;
        while (i < length)
        {
            if(current1->data = current2->data)
            {
                flag = 1;
                i += 2;
            }
            else
            {
                current1 = current1->next;
                current2 = current2->next->next;
                i += 2;
            }
        }
        if (flag == 1)
        {
            cout << "list is looped" << endl;
        }
        else
        {
            cout << "list isn't looped" << endl;
        }
    }






};
int main()
{
    List myList;
    myList.add_head(1);
    myList.add_head(13);
    myList.add_head(48);
    myList.add_head(25);
    myList.add_head(17);
    myList.add_head(6);
    myList.add_head(7);
    myList.add_tail(9);
    myList.add_tail(3);
    myList.add_tail(5);
    myList.add_tail(4);
    myList.add_tail(3);
    myList.add_tail(2);
    myList.add_tail(8);
    myList.delete_tail();
    myList.delete_head();
    myList.insertByIndex(100, 100);
    myList.print_length();
    myList.print_list();
    myList.is_list_looped();



    return 0;
}


