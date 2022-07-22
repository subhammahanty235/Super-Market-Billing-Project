#include <iostream>
#include <fstream>
using namespace std;
class Shopping{
  private:
    int prodCode ;
    float price;
    float dis;
    string prodName;
  public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void removeitem();
    void list();
    void recipt();
};

void Shopping::menu(){
  m:
  int choice ;
  string email , password;
  cout<<"\t\t\t\t---------------------------------------\n";
  cout<<"\t\t\t\t          Supermarket main menu        \n";
  cout<<"\t\t\t\t---------------------------------------\n";
  cout<<"\t\t\t\t                                       \n";
  cout<<"\t\t\t\t 1)Administrator    | \n";
  cout<<"\t\t\t\t 2)Buyer            | \n";
  cout<<"\t\t\t\t 3)exit             | \n";
  cout<<"\n\t\t\t Please select\n";
  cin>>choice;
  switch(choice){
    case 1:
      cout<<"\t\t\tplease login";
      cout<<"\t\t\t enter email";
      cin>>email;
      cout<<"\t\t\tenter password";
      cin>>password;
      if(email == "subham@gmail.com" && password == "subham@1234"){
        administrator();
      }
      else{
        cout<<"\t\t\t\t invalid username and password\n"
      }
      break;
    case 2:
      {
        
      buyer();
      }
    case 3:
      {
        exit(0);
      }
    default:
      cout<<"please select from the given options"<<endl;
  }
  goto m;
  
}

void Shopping::administrator(){
  m:
  int choice;
  cout<<"\t\t\t\t---------------------------------------\n";
  cout<<"\t\t\t\t           Administrator menu          \n";
  cout<<"\t\t\t\t---------------------------------------\n";
  cout<<"\t\t\t\t 1) add the product \n      ";
  cout<<"\t\t\t\t 2) modify the product \n   ";
  cout<<"\t\t\t\t 3) remove the product \n   ";
  cout<<"\t\t\t\t 4) Back to main menu \n    ";
  cout<<"\n\t\t\t Please select your choice\n";
  cin>>choice;
  switch(choice){
    case 1:
      {
        add();
        break;
      }
    case 2:
      {
        edit();
        break;
      }
    case 3:
      {
        removeitem();
        break;
      }
    default:
      cout<<"please select from the given options"<<endl;
      // break;
  }
  goto m;
  
}

void Shopping::buyer(){
  m:
  int choice;
  cout<<"\t\t\t\t---------------------------------------\n";
  cout<<"\t\t\t\t          Buyers section            \n";
  cout<<"\t\t\t\t---------------------------------------\n";
  cout<<"\t\t\t\t                                       \n";
  cout<<"\t\t\t\t 1)buy product      | \n";
  cout<<"\t\t\t\t 2)Go Back          | \n";
  // cout<<"\t\t\t\t 3)exit             | \n";
  cout<<"\n\t\t\t Please select\n";
  cin>>choice;
  switch(choice){
    case 1:
      {
        recipt();
        break;
      }
    case 2:
      {
        menu();
      }
    default:
      cout<<"please select from the given options"<<endl;
  }
  goto m;
}
void Shopping::add(){
  m:
  fstream data;
  int c , token=0 ;
  float p ,d;
  string n;
  cout<<"\n\n\t\t\t Add New Product\n";
  cout<<"\t\t Product code of the product: ";
  cin>>prodCode;
  cout<<"\n\t\t\t Name of the product : ";
  cin>>prodName;
  cout<<"\n\t\t\t price of the product : ";
  cin>>price;
  cout<<"\n\t\t\t Discount on the product : ";
  cin>>dis;
  data.open("database.txt" , ios::in);
  if(!data){
    data.open("database.txt",ios::app | ios::out);
    data<<" "<<prodCode<<" "<<prodName<<" "<<price<<" "<<dis<<"\n";
  }
  else{
    data>>c>>n>>p>>d;
    while(!data.eof()){
      if(c== prodCode){
        token++;
      }
      data>>c>>n>>p>>d;
    }
    data.close();
  }
  if (token == 1){
    goto m;
  }
  else{
    data.open("database.txt",ios::app | ios::out);
    data<<" "<<prodCode<<" "<<prodName<<" "<<price<<" "<<dis<<"\n";
    data.close();
    
  }
  cout<<"Record Inserted";
}
void Shopping::edit(){
  fstream data1 , data2;
  int prodKey , token =0 ;
  int c ;
  float p , d;
  string n;
  cout<<"\n\t\t\t modify the record"<<endl;
  cout<<"Product Code";
  cin>>prodKey;
  data1.open("database.txt", ios::in);
  if(!data1){
    cout<<"\n\n\t file doesn't exist";
    
  }
  else{
    data2.open("database2.txt" , ios::app | ios::out);
    data1>>prodName>>prodName>>price>>dis;
    while(!data1.eof()){
      if(prodKey== prodCode){
        cout<<"\n\t\t Product new code";
        cin>>c;
        cout<<"\n\t\t Name of the product";
        cin>>n;
        cout<<"\n\t\t Price";
        cin>>p;
        cout<<"\n\t\t Discount";
        cin>>d;
        data2<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
        cout<<"\n\n\t\t Record edited";
        token++;
      }
      else{
        data2<<' '<<prodCode<<" "<<prodName<<" "<<price<<" "<<dis<<'\n';;
        
      }
      data1>>prodCode>>prodName>>price>>dis;
    }
    data1.close();
    data2.close();
    remove("database.txt");
    rename("database2.txt", "database.txt");
    if(token == 0){
      cout<<"\n\t Record not found ";
    }
  }
  
}
void Shopping::removeitem(){
  fstream data1 , data2;
  int prodKey , token = 0;
  cout<<"\n\n\t Delete Product";
  cout<<"\n\t\t Product code: ";
  cin>>prodKey;
  data1.open("database.txt",ios::in);
  if(!data1){
    cout<<"File doesn't exist";
  }
  else{
    data2.open("database2.txt" , ios::app | ios::out);
    data1>>prodCode>>prodName>>price>>dis;
    while(!data1.eof()){
      if(prodCode == prodKey){
        cout<<"\n\t\t Product deleted successfully";
        token++;
      }
      else{
        data2<<" "<<prodCode<<' '<<prodName<<" "<<price<<" "<<dis<<"\n";
      }
      data1>>prodCode>>prodName>>price>>dis;
    }
    data1.close();
    data2.close();
    remove("database.txt");
    rename("database2.txt", "database.txt");
    if(token == 0){
      cout<<"Record not fount\n";
      
    }
    
  }
}
void Shopping::list(){
  fstream data;
  data.open("database.txt", ios::in);
  cout<<"\n\n|______________________________________________________";
  cout<<"Product NUmber \t\t Name \t\t Price\n";
  cout<<"\n\n|______________________________________________________";
  data>>prodCode>>prodName>>price>>dis;
  while(data.eof()){
    cout<<prodCode<<"\t\t"<<prodName<<"\t\t"<<price<<"\n";
    data>>prodCode>>prodName>>price>>dis;
  }
  data.close();
}

void Shopping::recipt(){
  fstream data;
  int acc
}
int main() {
  
}