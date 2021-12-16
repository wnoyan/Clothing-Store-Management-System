#include "header.h"
#include <bits/stdc++.h>

using namespace std;

/// Forward Definition of Functions
void mainMenu();

/// Forward Definition of Friend Functions
class Add;

/// Derived Male Class
class Male : public Cloths {
    private:
        friend class Add;
    public:
        Male(){
            cout<<"Please, Enter Male Dress ID, Name and Price.\n";
            cout<<"\t Male Dress ID: ";
            cin>>dressid;
            cout<<"\t Male Dress Name: ";
            cin>>dressname;
            cout<<"\t Male Dress Price: ";
            cin>>price; system("cls");

            /// Building a file entry combining all infos
            string maleProduct, strDressId, strPrice, dressType = "Male";
            ostringstream ostrDressId, ostrPrice;

            ostrDressId << dressid;
            strDressId = ostrDressId.str();

            ostrPrice << price;
            strPrice = ostrPrice.str();

            maleProduct = strDressId + " " + dressType + " " + dressname + " " + strPrice + "\n";

            /// Writing to file
            fstream productFile;
            productFile.open("Products.txt", ios::app);

            if(!productFile) cout<<"File not Created!";
            else{
                productFile << maleProduct;
                productFile.close();
            }

            /// Going back to main menu after successful inserting male product
            mainMenu();
        }
};

/// Derived Female Class
class Female : public Cloths {
    private:
        friend class Add;
    public:
        Female(){
            cout<<"Please, Enter Female Dress ID, Name and Price.\n";
            cout<<"\t Female Dress ID: ";
            cin>>dressid;
            cout<<"\t Female Dress Name: ";
            cin>>dressname;
            cout<<"\t Female Dress Price: ";
            cin>>price; system("cls");

            /// Building a file entry combining all infos
            string femaleProduct, strDressId, strPrice, dressType = "Female";
            ostringstream ostrDressId, ostrPrice;

            ostrDressId << dressid;
            strDressId = ostrDressId.str();

            ostrPrice << price;
            strPrice = ostrPrice.str();

            femaleProduct = strDressId + " " + dressType + " " + dressname + " " + strPrice + "\n";

            /// Writing to file
            fstream productFile;
            productFile.open("Products.txt", ios::app);

            if(!productFile) cout<<"File not Created!";
            else{
                productFile << femaleProduct;
                productFile.close();
            }

            /// Going back to main menu after successful inserting male product
            mainMenu();
        }
};

/// Derived Children Class
class Children : public Cloths {
    private:
        friend class Add;
    public:
        Children(){
            cout<<"Please, Enter Children Dress ID, Name and Price.\n";
            cout<<"\t Children Dress ID: ";
            cin>>dressid;
            cout<<"\t Children Dress Name: ";
            cin>>dressname;
            cout<<"\t Children Dress Price: ";
            cin>>price; system("cls");

            /// Building a file entry combining all infos
            string childrenProduct, strDressId, strPrice, dressType = "Children";
            ostringstream ostrDressId, ostrPrice;

            ostrDressId << dressid;
            strDressId = ostrDressId.str();

            ostrPrice << price;
            strPrice = ostrPrice.str();

            childrenProduct = strDressId + " " + dressType + " " + dressname + " " + strPrice + "\n";

            /// Writing to file
            fstream productFile;
            productFile.open("Products.txt", ios::app);

            if(!productFile) cout<<"File not Created!";
            else{
                productFile << childrenProduct;
                productFile.close();
            }

            /// Going back to main menu after successful inserting male product
            mainMenu();
        }
};

/// Add Class
class Add {
    private:
        int option;
    public:
        void add();
};

void Add :: add(){
    cout<<"Please, Follow the Instructions."<<endl;
    cout<<"\t1 Add Male Dress"<<endl;
    cout<<"\t2 Add Female Dress"<<endl;
    cout<<"\t3 Add Children Dress"<<endl;
    cout<<"\t4 Back Main Menu"<<endl;

    cout<<"\n\tPlease, Choose an Operation: ";
    cin>>option; system("cls");

    if(option==1){
        Male objMale;
    }
    else if(option==2){
        Female objFemale;
    }
    else if(option==3){
        Children objChildren;
    }
    else if(option == 4){
        /// Going back to main menu
        mainMenu();
    }
}

/// Search Class
class Search {
    private:
        int option;
        char ch;
    public:
        void _search();
};

void Search :: _search(){
    cout<<"Please, Enter the Dress ID to Search: ";
    cin>>option;

    /// Converting integer dress id to string
    string strDressId, dressType;
    ostringstream ostrDressId;

    ostrDressId << option;
    strDressId = ostrDressId.str();

    /// Reading from file
    fstream productFile;
    productFile.open("Products.txt", ios::in);

    /// Flag for found product or not
    ch = 'n';

    if(!productFile){
        cout<<"No Such File!";
    }
    else{
        string line, word, srcDressName, srcPrice;

        while(1){
            if(productFile.eof()) break;

            getline(productFile, line);
            istringstream ss(line);
            ss >> word;

            if(strDressId == word)  ch = 'y';

            if(ch == 'y'){
                cout<<"Dress Found!"<<endl;
                ss >> dressType;
                ss >> srcDressName;
                ss >> srcPrice;
                cout<<"Dress ID: "<<word<<" - Dress Type: "<<dressType<<" - Dress Name: "<<srcDressName<<" - Price: "<<srcPrice<<endl;
                break;
            }
        }

        if(ch == 'n'){
            cout<<"No Such Dress Found!"<<endl;
        }
    }
    productFile.close();

    mainMenu();
}

/// Remove Class
class Remove {
    private:
        int id;
        char ch;
        string filename = "Products.txt";
    public:
        void _remove();
};

void Remove :: _remove(){
    cout<<"Please, Enter the Dress ID to Remove: ";
    cin>>id;

    /// Converting integer dress id to string
    string strDressId;
    ostringstream ostrDressId;

    ostrDressId << id;
    strDressId = ostrDressId.str();

    /// Dress found flag
    bool isDressFound = false;

    /// Reading from file
    ifstream productFile;
    productFile.open("Products.txt", ios::in);

    /// Creating new temporary file to store dresses' infos
    ofstream newProductFile;
    newProductFile.open("temp.txt", ofstream::out);

    if(!productFile){
        cout<<"No Such File!";
    }
    else{
        string line, word, dressType, srcDressName, srcPrice;

        while(1){
            if(productFile.eof()) break;

            getline(productFile, line);
            istringstream ss(line);
            ss >> word;

            if(strDressId == word){
                cout<<"Dress Found to Delete!"<<endl;
                ss >> dressType;
                ss >> srcDressName;
                ss >> srcPrice;
                cout<<"Dress ID: "<<word<<" - Dress Type: "<<dressType<<" - Dress Name: "<<srcDressName<<" - Price: "<<srcPrice<<endl;
                isDressFound = true;
            }
            else{
                newProductFile << line;
                newProductFile << "\n";
            }
        }

        if(isDressFound != true) cout<<"Dress Not Found to Delete!"<<endl;
    }

    newProductFile.close();
    productFile.close();

    remove("Products.txt");
    rename("temp.txt", "Products.txt");

    mainMenu();
}

/// Employee Class
class Employee {
    private:
        int id;
        string name;
        string section;
        int age;
    public:
        void employee();
};

void Employee :: employee(){
    cout<<"Please, Follow the Instructions."<<endl;
    cout<<"\t1 Insert Employee"<<endl;
    cout<<"\t2 Search Employee"<<endl;
    cout<<"\n\tPlease, Choose an Operation: ";

    int employeeOption;
    cin>>employeeOption; system("cls");

    switch(employeeOption){
        case 1:{
            cout<<"Please, Enter Employee's Information."<<endl;
            cout<<"\tEmployee's ID: ";
            cin>>id;
            cout<<"\tEmployee's Name: ";
            cin>>name;
            cout<<"\tEmployee's Section: ";
            cin>>section;
            cout<<"\tEmployee's Age: ";
            cin>>age; system("cls");

            /// Building a file entry combining all infos
            string empID, empAge, empInfo;
            ostringstream ostrEmpID, ostrEmpAge;

            ostrEmpID << id;
            empID = ostrEmpID.str();

            ostrEmpAge << age;
            empAge = ostrEmpAge.str();

            empInfo = empID + " " + name + " " + section + " " + empAge + "\n";

            /// Writing to file
            fstream employeeFile;
            employeeFile.open("Employees.txt", ios::app);

            if(!employeeFile) cout<<"File not Created!";
            else{
                employeeFile << empInfo;
                employeeFile.close();
            }

            /// Going back to main menu after successful inserting employee info
            mainMenu();
            break;
        }

        case 2:{
            char ch;
            int employeeID;

            cout<<"Please, Enter the Employee ID to Search: ";
            cin>>employeeID;

            /// Converting integer employee id to string
            string strEmpId;
            ostringstream ostrEmpId;

            ostrEmpId << employeeID;
            strEmpId = ostrEmpId.str();

            /// Reading from file
            fstream employeeFile;
            employeeFile.open("Employees.txt", ios::in);

            /// Flag for found product or not
            ch = 'n';

            if(!employeeFile){
                cout<<"No Such File!";
            }
            else{
                string line, word, empName, empSection, empAge;

                while(1){
                    if(employeeFile.eof()) break;

                    getline(employeeFile, line);
                    istringstream ss(line);
                    ss >> word;

                    if(strEmpId == word)  ch = 'y';

                    if(ch == 'y'){
                        cout<<"Employee Found!"<<endl;
                        ss >> empName;
                        ss >> empSection;
                        ss >> empAge;
                        cout<<"Emp. ID: "<<word<<" - Emp. Name: "<<empName<<" - Emp. Section: "<<empSection<<" - Emp. Age: "<<empAge<<endl;
                        break;
                    }
                }

                if(ch == 'n'){
                    cout<<"No Such Employee Found!"<<endl;
                }
            }
            employeeFile.close();

            mainMenu();
            break;
        }

        default:
            cout<<"Please, Enter a Valid Number."<<endl;
            employee();
            break;
    }
}

/// Customer Class
class Customer {
    private:
        string name;
        //char *name;
        int id;
    public:
        void buy();
        //~Customer(){ delete[] name;}
        /// Destructor
        ~Customer(){}
};

void Customer :: buy(){
    cout<<"Please, Follow the Instructions."<<endl;
    cout<<"\t1 Insert Customer"<<endl;
    cout<<"\t2 Search Customer"<<endl;
    cout<<"\n\tPlease, Choose an Operation: ";

    string dummy;
    int customerOption;
    cin>>customerOption; system("cls");

    switch(customerOption){
        case 1:{
            cout<<"Please, Enter Customer's Information."<<endl;
            cout<<"\tCustomer's Name: ";
            cin>>name;
            //cin>>dummy;
            //name = strcpy(new char[strlen(dummy)+1], dummy);
            cout<<"\tDress ID: ";
            cin>>id; system("cls");

            /// Building a file entry combining all infos
            string dressID, cusInfo;
            ostringstream ostrDressID;

            ostrDressID << id;
            dressID = ostrDressID.str();

            cusInfo = name + " " + dressID + "\n";

            /// Writing to file
            fstream customerFile;
            customerFile.open("Customers.txt", ios::app);

            if(!customerFile) cout<<"File not Created!";
            else{
                customerFile << cusInfo;
                customerFile.close();
            }

            /// Going back to main menu after successful inserting employee info
            mainMenu();
            break;
        }

        case 2:{
            char ch;
            string customerName;

            cout<<"Please, Enter the Customer Name to Search: ";
            cin>>customerName;

            /// Reading from file
            fstream customerFile;
            customerFile.open("Customers.txt", ios::in);

            /// Flag for found product or not
            ch = 'n';

            if(!customerFile){
                cout<<"No Such File!";
            }
            else{
                string line, word, dressID;

                while(1){
                    if(customerFile.eof()) break;

                    getline(customerFile, line);
                    istringstream ss(line);
                    ss >> word;

                    if(customerName == word)  ch = 'y';

                    if(ch == 'y'){
                        cout<<"Customer Found!"<<endl;
                        ss >> dressID;
                        cout<<"Customer Name: "<<word<<" - Dress ID: "<<dressID<<endl;
                        break;
                    }
                }

                if(ch == 'n'){
                    cout<<"No Such Customer Found!"<<endl;
                }
            }
            customerFile.close();

            mainMenu();
            break;
        }

        default:
            cout<<"Please, Enter a Valid Number."<<endl;
            buy();
            break;
    }
}

/// Report Generation
class ReportGeneration
{
    public:
        int totalDress;
        vector<string> dressIDs;

        virtual void report(){};
};

class MReportGeneration : public ReportGeneration
{
    public:
        void report();
};

void MReportGeneration :: report()
{
    totalDress = 0;
    dressIDs.clear();

    /// Reading from file
    fstream productFile;
    productFile.open("Products.txt", ios::in);

    if(!productFile){
        cout<<"No Such File!";
    }
    else{
        string line, dressID, maleDress;

        while(1){
            if(productFile.eof()) break;

            getline(productFile, line);
            istringstream ss(line);

            ss >> dressID; ss >> maleDress;

            if(maleDress == "Male")
            {
                totalDress++;
                dressIDs.push_back(dressID);
                maleDress = " ";
            }
        }
    }
    productFile.close();

    cout<<"Total Male Dress: "<<totalDress<<endl;

    if(totalDress > 0)
    {
        cout<<"Male Dress IDs are: ";

        for(int i=0; i<dressIDs.size(); i++)
            cout<<dressIDs[i]<<" ";

        cout<<endl<<endl;
    }
    else
        cout<<endl;
}

class FReportGeneration : public ReportGeneration
{
    public:
        void report();
};

void FReportGeneration :: report()
{
    totalDress = 0;
    dressIDs.clear();

    /// Reading from file
    fstream productFile;
    productFile.open("Products.txt", ios::in);

    if(!productFile){
        cout<<"No Such File!";
    }
    else{
        string line, dressID, femaleDress;

        while(1){
            if(productFile.eof()) break;

            getline(productFile, line);
            istringstream ss(line);

            ss >> dressID; ss >> femaleDress;

            if(femaleDress == "Female")
            {
                totalDress++;
                dressIDs.push_back(dressID);
                femaleDress = " ";
            }
        }
    }
    productFile.close();

    cout<<"Total Female Dress: "<<totalDress<<endl;

    if(totalDress > 0)
    {
        cout<<"Female Dress IDs are: ";

        for(int i=0; i<dressIDs.size(); i++)
            cout<<dressIDs[i]<<" ";

        cout<<endl<<endl;
    }
    else
        cout<<endl;
}

class CReportGeneration : public ReportGeneration
{
    public:
        void report();
};

void CReportGeneration :: report()
{
    totalDress = 0;
    dressIDs.clear();

    /// Reading from file
    fstream productFile;
    productFile.open("Products.txt", ios::in);

    if(!productFile){
        cout<<"No Such File!";
    }
    else{
        string line, dressID, childrenDress;

        while(1){
            if(productFile.eof()) break;

            getline(productFile, line);
            istringstream ss(line);

            ss >> dressID; ss >> childrenDress;

            if(childrenDress == "Children")
            {
                totalDress++;
                dressIDs.push_back(dressID);
                childrenDress = " ";
            }
        }
    }
    productFile.close();

    cout<<"Total Children Dress: "<<totalDress<<endl;

    if(totalDress > 0)
    {
        cout<<"Children Dress IDs are: ";

        for(int i=0; i<dressIDs.size(); i++)
            cout<<dressIDs[i]<<" ";

        cout<<endl<<endl;
    }
    else
        cout<<endl;

    mainMenu();
}

void mainMenu(){
    cout<<"Please, Follow the Instructions."<<endl;
    cout<<"\t1 Add Dress"<<endl;
    cout<<"\t2 Search Dress"<<endl;
    cout<<"\t3 Remove Dress"<<endl;
    cout<<"\t4 Employees' Info"<<endl;
    cout<<"\t5 Customers' Info"<<endl;
    cout<<"\t6 Generate Report"<<endl;
    cout<<"\t7 Exit"<<endl;

    cout<<"\n\tPlease, Choose an Operation: ";
    int operation;
    cin>>operation; system("cls");

    switch(operation){
        case 1:{
            Add objAdd;
            objAdd.add();
            break;
        }

        case 2:{
            Search objSearch;
            objSearch._search();
            break;
        }

        case 3:{
            Remove objRemove;
            objRemove._remove();
            break;
        }

        case 4:{
            Employee objEmployee;
            objEmployee.employee();
            break;
        }

        case 5:{
            Customer objCustomer;
            objCustomer.buy();
            break;
        }

        case 6:{
            ReportGeneration* objReportGeneration;

            MReportGeneration objMReportGeneration;
            FReportGeneration objFReportGeneration;
            CReportGeneration objCReportGeneration;

            objReportGeneration = &objMReportGeneration;
            objReportGeneration->report();

            objReportGeneration = &objFReportGeneration;
            objReportGeneration->report();

            objReportGeneration = &objCReportGeneration;
            objReportGeneration->report();

            break;
        }

        case 7:
            exit(1);

        default:
            cout<<"Please, Enter a Valid Number."<<endl;
            mainMenu();
            break;
    }
}

int main()
{
    mainMenu();

    return 0;
}
