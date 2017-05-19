#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


using namespace std;


class SymbolInfo {
private:
    string Name;
    string Type;
    SymbolInfo* next;

public:
    int ival;
    float fval;
    string var_type;
    bool isFunc;

    vector<string> param_list;
    vector<string> param_name;

    SymbolInfo* arr;
    int a_size;
    string code = "";
    string symbol = "";

    SymbolInfo(){
        setName("");
        setType("");
        setPoint(NULL);
        ival = -999999;
        fval = -999999.0;
        var_type = "DEFAULT";
        a_size = -1;
    }
    SymbolInfo(string s, string t){
        setName(s);
        setType(t);
        setPoint(NULL);
        ival = -999999;
        fval = -999999.0;
        a_size = -1;
    }
    void AddParam(string s){
        param_list.push_back(s);
    }
    void AddName(string s){
        param_name.push_back(s);
    }
    void setName(string n){
        Name = n;
    }
    void setType(string t){
        Type = t;
    }
    void setPoint(SymbolInfo* p){
        next = p;
    }
    string getName(){
        return Name;
    }
    string getType(){
        return Type;
    }
    SymbolInfo* getPoint(){
        return next;
    }
};

class ScopeTable {
public:
    SymbolInfo** table;
    ScopeTable* parentScope;
    int len;
    int id;
    ScopeTable(int size){
        table = new SymbolInfo*[size];
        for (int i = 0; i < size; i++)
        table[i] = new SymbolInfo();
        len = size;
        parentScope = NULL;
    }
    bool Insert(string name,string type,string var,int &asize){
        int i = hash(name),j = 0;
        SymbolInfo* sp = table[i];

        while(sp->getPoint() != NULL) {
            if (sp->getPoint()->getName() == name) {
                //cout<<"<"<<name<<","<<type<<"> already exists in current ScopeTable"<<endl;
                return false;
            }
            sp = sp->getPoint();
            j++;
        }
        sp->setPoint(new SymbolInfo(name,type));
        sp->getPoint()->var_type = var;
        sp->getPoint()->a_size = asize;
        if (sp->getPoint()) {
            //cout<<"Inserted in ScopeTable# "<<id<<" at position "<<i<<", "<<j<<endl;
            return true;
        }
        return false;
    }
    SymbolInfo* Lookup(string s){
        int i = hash(s), j = 0;
        SymbolInfo* sp = table[i];
        while (sp->getPoint() != NULL) {
            if (sp->getPoint()->getName() == s)
            return sp->getPoint();
            sp = sp->getPoint();
            j++;
        }
        sp = NULL;
        return sp;
    }
    bool Delete(string s){
        int i = hash(s), j = 0;
        SymbolInfo* sp = table[i];
        while (sp->getPoint() != NULL) {
            if (sp->getPoint()->getName() == s) {
                cout<<"Found in ScopeTable# "<<id<<" at position "<<i<<", "<<j<<endl;
                cout<<"Deleted entry at "<<i<<", "<<j<<" from current ScopeTable"<<endl;
                SymbolInfo* temp = sp->getPoint();
                sp->setPoint(temp->getPoint());
                delete temp;
                return true;
            }
            sp = sp->getPoint();
            j++;
        }
        cout<<s<<" Not found"<<endl;
        return false;
    }
    void Print(){
        cout<<"\n ScopeTable # "<<id<<endl;
        for (int i = 0; i < len; i++) {
            SymbolInfo* sp = table[i];
            while (sp->getPoint() != NULL) {
                if (sp->getPoint()->var_type == "INT" && sp->getPoint()->a_size == -1)
                cout<<" "<<i<<" --> <"<<sp->getPoint()->getName()<<" ,"<<sp->getPoint()->getType()<<" ,"<<sp->getPoint()->ival<<">"<<endl;
                else if (sp->getPoint()->var_type == "FLOAT" && sp->getPoint()->a_size == -1) {
                    cout<<" "<<i<<" --> <"<<sp->getPoint()->getName()<<" ,"<<sp->getPoint()->getType()<<" ,"; printf("%f",sp->getPoint()->fval); cout<<">"<<endl;
                }
                else if (sp->getPoint()->a_size > 0) {
                    cout<<" "<<i<<" --> <"<<sp->getPoint()->getName()<<" ,"<<sp->getPoint()->getType()<<" ,"; PrintAr(sp->getPoint()); cout<<">"<<endl;
                }
                else {
                    if (sp->getPoint()->var_type == "INT") cout<<" "<<i<<" --> <"<<sp->getPoint()->getName()<<" ,"<<sp->getPoint()->getType()<<" ,"<<sp->getPoint()->ival<<">"<<endl;
                    else if (sp->getPoint()->var_type == "FLOAT") {
                        cout<<" "<<i<<" --> <"<<sp->getPoint()->getName()<<" ,"<<sp->getPoint()->getType()<<" ,"; printf("%f",sp->getPoint()->fval); cout<<">"<<endl;
                    }
                    else cout<<" "<<i<<" --> <"<<sp->getPoint()->getName()<<" ,"<<sp->getPoint()->getType()<<" ,"<<sp->getPoint()->ival<<">"<<endl;
                }
                sp = sp->getPoint();
            }
        }
        cout<<endl;
    }
    void PrintAr(SymbolInfo* sp){
        cout<<"{ ";
        int i;
        for (i = 0; i < sp->a_size - 1; i++) {
            if (sp->var_type == "INT") cout<<sp->arr[i].ival<<", ";
            else cout<<sp->arr[i].fval<<", ";
        }
        if (sp->var_type == "INT") cout<<sp->arr[i].ival<<"}";
        else cout<<sp->arr[i].fval<<"}";
    }
    ~ScopeTable(){
        for (int i = 0; i < len; i++) {
            SymbolInfo* temp = table[i];
            while(temp->getPoint() != NULL) {
                SymbolInfo* temp2 = temp->getPoint();
                temp->setPoint(temp2->getPoint());
                delete temp2;
            }
            delete table[i];
        }
        delete []table;
    }
    int hash(string s){
        int index = 3;
        for (int i = 0; i < s.length(); i++)
        index = index + 29*((int)s[i] % len) + 59;
        index = index % len;
        return index;
    }
};


class SymbolTable {
public:
    ScopeTable* head;
    ScopeTable* curr;
    int idno = 0;
    int len;
    SymbolTable(int length){
        head = new ScopeTable(length);
        curr = head;
        len = length;
        curr->id = idno++;
    }
    void EnterScope(int length){
        ScopeTable* temp = new ScopeTable(length);
        temp->parentScope = curr;
        curr = temp;
        curr->id = idno++;
        // cout<<"New ScopeTable with id "<<curr->id<<" created"<<endl;
    }
    void ExitScope(){
        //cout<<"ScopeTable with id "<<curr->id<<" removed"<<endl;
        ScopeTable* temp = curr;
        curr = curr->parentScope;
        delete temp;
    }
    bool Insert(SymbolInfo *s){
        return curr->Insert(s->getName(),s->getType(),s->var_type,s->a_size);
    }
    bool Remove(string name){
        return curr->Delete(name);
    }
    void PrintCurrentScopeTable(){
        curr->Print();
    }
    void PrintAllScopeTable(){
        ScopeTable* temp = curr;
        while(temp != NULL) {
            temp->Print();
            temp = temp->parentScope;
        }
    }
    SymbolInfo* Lookup(string s){
        ScopeTable* temp = curr;
        do {
            SymbolInfo* sp = temp->Lookup(s);
            if (sp != NULL)
            return sp;
            temp = temp->parentScope;
        } while(temp != NULL);
        if (temp == NULL)
        return NULL;
    }
    SymbolInfo* LookupCurr(string s){
        return curr->Lookup(s);
    }
    ~SymbolTable(){
        while (curr != head) {
            ScopeTable* temp = curr;
            curr = curr->parentScope;
            delete temp;
        }
        delete curr;
    }
};
