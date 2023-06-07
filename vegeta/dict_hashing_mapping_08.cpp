#include<iostream>
#include<string.h>

using namespace std;

class Node{
    public:
        int chain;
        string word, mean;
}obj[10];

int hash_fun(string wd){
    int key = 0;
    for(int i=0; i<wd.size(); i++){
        key = key+wd[i];
    }
    return key%10;
}

void collision(int key, string wd, string mn){
    int i=1;
    while(((key+i)%10) <10){
        if(obj[(key+i) % 10].word == "-"){
            obj[(key+i) % 10].word = wd;
            obj[(key+i) % 10].mean = mn;
            obj[(key+i-1) % 10].chain = (key+i)%10;
        }
        else
            i++;
    }
}

void hash_ini(){
    for(int i=0; i<10; i++){
        obj[i].word = "-";
        obj[i].mean = "-";
        obj[i].chain = -1;
    }
}

void hash_table(){
    string wd, mn;
    cout<<"\nEnter a word = ";
    cin>>wd;
    cout<<"\nEnter meaning of above word = ";
    cin>>mn;
    cout<<endl;

    int hash_key = hash_fun(wd);

    if(obj[hash_key].word == "-"){
        obj[hash_key].word = wd;
        obj[hash_key].mean = mn;
    }
    else{
        collision(hash_key, wd, mn);
    }
}

void display(){
    cout<<"Index \t Word \t Meaning \t Chain \n";
    for(int i=0; i<10; i++){
        cout<<i<<" \t "<<obj[i].word<<" \t "<<obj[i].mean<<" \t \t"<<obj[i].chain <<"\n";
    }
}

void del_key(string word){
    int key = hash_fun(word);
    if(obj[key].word == word){
        obj[key].word = "-";
        obj[key].mean = "-";
        obj[key].chain = -1;
    }
    else if(obj[key].word != word){
        int tar = obj[key].chain;
        while(true){
            if(obj[tar].word == word){
                obj[tar-1].chain = obj[tar].chain;
                obj[tar].word = "-";
                obj[tar].mean = "-";
                obj[tar].chain = -1;
                cout<<"\nDeletion is successfull!!\n";
                break;
            }
            tar = obj[tar].chain;
        }
    }
    else
        cout<<"\nWord not found!!!";
}

void find(string word){
    int key = hash_fun(word);
    if(obj[key].word == word){
        cout<<"Found the word!!! == ";
        cout<<obj[key].word<<"--->"<<obj[key].mean<<endl;
    }
    else if(obj[key].chain != -1){
        int tar = obj[key].chain;
        while(true){
            if(obj[tar].word == word){
                cout<<"Found the Word!!! == ";
                cout<<obj[tar].word<<"--->"<<obj[tar].mean<<endl;
                break;
            }
            tar = obj[tar].chain;
        }
    }
    else
        cout<<"\nWord Not Found!!! \n";
}

int main(){
    int ch;
    string delwd, src;
    hash_ini();
    do{
        cout<<"\n1. Insert in hash table";
        cout<<"\n2. Display hash table";
        cout<<"\n3. Delete a word";
        cout<<"\n4. Find a word";
        cout<<"\n5. Exit";
        cout<<"\n Enter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                int n;
                cout<<"\nEnter no. of entries you want = ";
                cin>>n;
                for(int j=0; j<n; j++){
                    hash_table();
                }
                break;
            case 2:
                display();
                break;
            case 3:
                cout<<"\nEnter word you want to delete = ";
                cin>>delwd;
                del_key(delwd);
                break;
            case 4:
                cout<<"\nEnter word you want to find = ";            
                cin>>src;
                find(src);
                break;
            case 5:
                exit(0);
                break;
        }
    }while(ch <= 5);
    return 0;
}