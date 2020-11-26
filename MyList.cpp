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
};
int main()
{
    List myList;
    myList.add_head(1);
    myList.add_head(2);
    myList.add_head(3);
    myList.add_head(4);
    myList.add_head(5);
    myList.add_head(6);
    myList.add_head(7);
    myList.add_tail(7);
    myList.add_tail(6);
    myList.add_tail(5);
    myList.add_tail(4);
    myList.add_tail(3);
    myList.add_tail(2);
    myList.add_tail(1);
    myList.print_length();
    myList.print_list();
    myList.delete_tail();
    myList.print_list();




    return 0;
}


