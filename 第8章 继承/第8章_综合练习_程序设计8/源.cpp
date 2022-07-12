#include<iostream>
#include<String.h>
using namespace std;
class RMB {
    int yuan, jiao, fen;
public:
    RMB(int y = 0, int j = 0, int f = 0) {
        yuan = y;
        jiao = j;
        fen = f;
    }
    RMB(double x)
    {
        int n = int((x + 0.005) * 100);
        yuan = n / 100;
        jiao = (n - yuan * 100) / 10;
        fen = n % 10;
    }
    operator double()
    {
        return (yuan + jiao * 0.1 + fen * 0.01);
    }
    ~RMB() {}
    friend ostream& operator<<(ostream& output, const RMB& m) {
        output << m.yuan << "Ôª" << m.jiao << "½Ç" << m.fen << "·Ö" << endl;
        return output;
    }
    friend istream& operator>>(istream& input, RMB& m) {
        cout << "Ôª£º";
        input >> m.yuan;
        cout << "½Ç£º";
        input >> m.jiao;
        cout << "·Ö£º";
        input >> m.fen;
        return input;
    }
};
class member {
public:
    static int number;
    char name[20], code[10], phoneNumber[12];
    static int bianhao() { number++; return number; }
    member(char* a, char* c, char* p) {
        strcpy_s(name, a);
        strcpy_s(code, c);
        strcpy_s(phoneNumber, p);
    }
    ~member() {}
    friend istream& operator>>(istream& input, member& A)
    {
        cout << "please input name: " << endl;
        input >> A.name;
        cout << "please input code: " << endl;
        input >> A.code;
        cout << "please input phone number : " << endl;
        input >> A.phoneNumber;
        return input;
    }
    friend ostream& operator<<(ostream& output, member& A)
    {
        output << "the information of member:" << endl;
        output << "number" << '\t' << "name" << '\t' << "phone" << endl;
        output << A.bianhao() << '\t' << A.name << '\t' << A.phoneNumber << endl;
        return output;
    }
};
int member::number = 0;
class memberCar :public RMB, public member {
public:
    RMB income, outcome, balance;
    memberCar* next;
    memberCar(char* a, char* c, char* p) :member(a, c, p) {
        balance = 0;
        income = 0;
        outcome = 0;
    }
    ~memberCar() {}
    friend ostream& operator<<(ostream& output, const memberCar& A)
    {
        output << "the information of member:" << endl;
        output << "number" << '\t' << "name" << '\t' << "phone" << '\t' << '\t' << "balance" << endl;
        output << A.bianhao() << '\t' << A.name << '\t' << A.phoneNumber << '\t' << A.balance << endl;
        return output;
    }
    void recharge()
    {
        cout << "How much do you want to recharge?" << '\n' << "please input the money : " << endl;
        cin >> income;
        balance = balance + income;
        cout << "your balance : " << balance << endl;
    }
    void cost()
    {
        char y[10];
        cout << "please input your code : " << endl;
        cin >> y;
        if (strncmp(code, y, 10) == 0)
        {
            cout << "please input the money you cost : " << endl;
            cin >> outcome;
            if (outcome > balance)
            {
                cout << "your balance is not enough ! " << endl;
            }
            else
            {
                balance = balance - outcome;
                cout << "your balance : " << balance;
            }
        }
        else
        {
            cout << "your code is wrong ! " << endl;
        }
    }
    void query() { cout << "your balance : " << balance; }
};
void AddFront(memberCar*& h, memberCar*& t)
{
    t->next = h;
    h = t;
}
void FindList(memberCar* head, int n = 2)
{
    char s[20];
    cout << "please input your name : " << endl;
    cin >> s;
    while (head)
    {
        if (strncmp(head->name, s, 20) == 0) {
            switch (n)
            {
            case 2:
                (*head).recharge();
                break;
            case 3:
                (*head).cost();
                break;
            }
        }
        head = head->next;
    }
}
void ShowList(memberCar* head)
{
    int count = 0;
    RMB I = 0, O = 0;
    while (head)
    {
        count++;
        I = I + head->income;
        O = O + head->outcome;
        head = head->next;
    }
    cout << "the number of member :   " << count << endl;
    cout << "the income of the store : " << I << endl;
    cout << "the outcome of the store : " << O << endl;
    cout << "turn-over of the store :   " << (I - O) << endl;
}

int main()
{
    int choice;
    memberCar* head = NULL, * p;
    do
    {
        cout << "please choice:\n";
        cout << "1 : new member, 2 : recharge, 3 : purchase , 4 :output the number of member and turn-over,other number is over! " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "input information of new member : " << endl;
            char a[20], c[10], h[12];
            cout << "please input name: " << endl;
            cin >> a;
            cout << "please input code: " << endl;
            cin >> c;
            cout << "please input phone number : " << endl;
            cin >> h;
            p = new memberCar(a, c, h);
            AddFront(head, p);
            cout << *p << endl;
            break;
        }
        case 2:
        {
            FindList(head, 2);
            break;
        }
        case 3:
        {
            FindList(head, 3);
            break;
        }
        case 4:
        {
            ShowList(head);
            break;
        }
        }
    } while (choice);
    return 0;
}
//哈哈哈



