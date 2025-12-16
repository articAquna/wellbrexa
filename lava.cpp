#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<chrono>
#include<thread>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

int z = 0;
struct age{
    int day , month , year;
}
;

struct add{
    string padr , radr;
}
;

struct cont{
    string phone1[2], email[2];
}
;
struct worker{
    string NAME ;
    age AGE;
    add ADDRESS;
    cont REFRENCES;
    string JOB_status;


};

bool read(){
    ifstream fin("markdown.txt");
    string characters;
    fin >> characters;
    fin.close();

    return(characters=="yes");

}

void screen(const worker &dummy){
    ofstream fout("workerdata.txt");


    fout <<setw(10)<<"name"<<setw(10)<<dummy.NAME<<endl;
    fout <<setw(10)<<"date"<<setw(10)<<dummy.AGE.day<<setw(2)<<dummy.AGE.month<<setw(2)<< dummy.AGE.year <<endl;
    fout <<setw(10)<<"address"<<setw(10)<<dummy.ADDRESS.padr <<setw(2)<< dummy.ADDRESS.radr<<endl;
    fout <<setw(10)<<"JOBSTAUTS"<<setw(10)<<dummy.JOB_status <<setw(2)<< dummy.ADDRESS.radr<<endl;
    fout <<setw(10)<<"phoneNO\n";
    for(int i = 0 ; i<2 ; i++){
    fout <<setw(2)<< dummy.REFRENCES.phone1[i]<<endl;
    }
    fout <<setw(10)<<"EMAIL\n";
    for(int i = 0 ; i<2 ; i++){
    fout <<setw(2)<< dummy.REFRENCES.email[i]<<endl;
    }

    


}

bool display(const worker &dummy){

    cout <<setw(10)<<"name"<<setw(10)<<dummy.NAME<<endl;
    cout <<setw(10)<<"date"<<setw(5)<<dummy.AGE.day<<setw(5)<<dummy.AGE.month<<setw(5)<< dummy.AGE.year <<endl;
    cout <<setw(10)<<"address"<<setw(10)<<dummy.ADDRESS.padr <<setw(2)<< dummy.ADDRESS.radr<<endl;
    cout <<setw(10)<<"JOBSTAUTS"<<setw(10)<<dummy.JOB_status <<setw(2)<< dummy.ADDRESS.radr<<endl;
    cout <<setw(10)<<"phoneNO\n";
    for(int i = 0 ; i<2 ; i++){
    cout <<setw(2)<< dummy.REFRENCES.phone1[i]<<endl;
    }
    cout <<setw(10)<<"EMAIL\n";
    for(int i = 0 ; i<2 ; i++){
    cout <<setw(2)<< dummy.REFRENCES.email[i]<<endl;
    }

    cout <<endl<<endl<<endl;
    cout << "if this si your data input 1";
    int v;
    cin >> v;
   return (v==1)?true :false;

}

void tag(worker *W ){

    cout << "dear worker you will be provided with question";
    cout << "infer and remeber without varification youu dead \n";
    worker dummy = *W;
 do{
        cout << "enter your name ";

            getline(cin , dummy.NAME);

        cout << "enter uour age\n";
        
            cout << "your day ";
            cin >> dummy.AGE.day;
            cout << " your month";
            cin >> dummy.AGE.month;
            cout << "your year";
            cin >> dummy.AGE.year;
        
        cout <<"now for you adresses\n";
            cout << "prove your permaanet address\n";
            cin >> dummy.ADDRESS.padr;
            cout << " peovide temporary adress \n";
            cin >> dummy.ADDRESS.radr;

        cout <<"now for your contancts\n";

            cout << "enter your 2 phone numbers\n";
            for(int k = 0 ; k < 2; k++){
            cin >>  dummy.REFRENCES.phone1[k];
                    }

            cout << "enter your 2 email numbers\n";
            for(int k = 0 ; k < 2; k++){
            cin >>  dummy.REFRENCES.email[k];
                    }
           
        string commonJobs[5] = {
            "1=Administrative Assistant",
            "2=HR Officer",
            "3=Accountant",
            "4=IT Support",
            "5=Customer Service Representative"
          };
          cout << "choose you proffection"<<endl; 
          for (int k = 0 ; k < 5 ; k++){
            cout << setw(10) << commonJobs[k] << endl; 
          }
          int v;
          cin >> v;
          dummy.JOB_status = commonJobs[v-1];

    }while(!display(dummy));

    screen(dummy);
    while(!fs:: exists("markdown.txt")){
        this_thread::sleep_for(chrono::seconds(1));
    }

    if(read()){

        *W = dummy;
        z++;

    }else{
        cout << "your data is terminated";
        int a;
        cin >> a;
    }



}
int display(){
        int a;
        cout << setw(20) << "table of contetn\n";
            cout << " 1 register worker data menu \n";

        cin>>a;
        return a;
        

}
void selection(int a , worker W[] ){


    switch (a){
        case 1:  tag(&W[z]);
    }

}


int main(){
  const int total = 5;
  worker  W[total]; 

  
      selection(display() , W );

    



}