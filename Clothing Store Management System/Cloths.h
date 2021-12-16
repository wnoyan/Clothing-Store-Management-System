#include <bits/stdc++.h>

using namespace std;

/// Cloths Class - Base Class
class Cloths {
    private:
        string Filename = "Products.txt";
    protected:
        string dressname;
        int dressid;
        float price;
    public:
        void getinfo();
};
void Cloths :: getinfo(){
    ///cout<<"Filename: "<<Filename<<endl;
    cout<<"Dress Name: "<<dressname<<endl;
    cout<<"Dress ID: "<<dressid<<endl;
    cout<<"Price: "<<price<<endl;
}


