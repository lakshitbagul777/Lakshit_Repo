#include <iostream>
#include <cstring>
using namespace std;
struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
} * root;
class book
{
public:
    book()
    {
        root == NULL;
    }
    void create()
    {
        int se_count;
        root = new node();
        cout << "Enter the name of the book: " << endl;
        cin >> root->label;
        cout << "ENter the total number of chapters in book: " << endl;
        cin >> root->ch_count;
        for (int i = 0; i < root->ch_count; i++)
        {
            root->child[i] = new node();
            cout << "Enter thhe name of chapters: " << endl;
            cin >> root->child[i]->label;
            cout << "Enter the number of sections: " << endl;
            cin >> root->child[i]->ch_count;
            for (int j = 0; j < root->child[i]->ch_count; j++)
            {
                root->child[i]->child[j] = new node();
                cout << "Enter the name of the section: " << endl;
                cin >> root->child[i]->child[j]->label;
                cout << "Enter the number of subsections: " << endl;
                cin >> root->child[i]->child[j]->ch_count;
                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
                {
                    root->child[i]->child[j]->child[k] = new node();
                    cout << "Enter the name of subsections: " << endl;
                    cin >> root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
    void display()
    {
        if (root != NULL)
        {
            cout << "-----Hierarchy of book-----" << endl;
            cout << "Book name is " << root->label << endl;
            for (int i = 0; i < root->ch_count; i++)
            {
                cout << " " << root->child[i]->label << endl;
                for (int j = 0; i < root->child[i]->ch_count; j++)
                {
                    cout << " " << root->child[i]->child[j]->label << endl;
                    for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
                        cout << " " << root->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    }
};
int main()
{
    book b1;
    b1.create();
    b1.display();
}