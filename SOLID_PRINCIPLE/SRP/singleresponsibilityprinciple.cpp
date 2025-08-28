//a class should have only one reason to be changed
#include<iostream>
using namespace std;
// #include<bits/stdc++.h>
//without SRP
// class Invoice{
//     private:
//     string item;
//     int quantity;
//     double price;
//     public:
//     Invoice(string i,int q,double p):item(i),quantity(q),price(p){}
//     double calTotal(){
//         return quantity*price;
//     }
//     void printInvoice(){
//         cout<<"item: "<<item<<", quantity: "<<quantity<<", price for 1 product: "<<price<<endl;
//     }
//     void saveToDatabase(){}
// };

// int main(){
//     Invoice user1("soap",2,100);
//     user1.printInvoice();
//     cout<<user1.calTotal()<<endl;
//     return 0;
// }
//issue invoice class is doing bussiness logic, ouutput logic, persistence logic

//with srp
class Invoice{
    private:
    string item;
    int quantity;
    double price;
    public:
    Invoice(string i,int q,double p):item(i),quantity(q),price(p){}
    double calTotal(){
        return price*quantity;
    }
    string getItem() const{return item;}
    int getQuantity() const{return quantity;}
    double getPrice() const{return price;}
};

class InvoicePrinter{
    public:
    void printInvoice(Invoice &invoice){
        cout<<"item: "<<invoice.getItem()<<", quantity: "<<invoice.getQuantity()<<", price: "<<invoice.getPrice()<<", total:"<<invoice.calTotal()<<endl;
    }
};

class InvoiceRepository{
    public:
    void saveToDatabase(){
        cout<<"data was saved"<<endl;
    }
};

int main(){
    Invoice user1("maggi",2,30);
    InvoicePrinter printer;
    printer.printInvoice(user1);
    return 0;
}
