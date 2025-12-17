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
    float pay;
    float bonus;
    int signature[5];
    float increase = 0;


};

void calculation(worker &w);
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
    fout <<setw(10)<<"pay"<<setw(10)<<dummy.pay<<endl;

    


}

bool display(const worker &dummy){
     system("cls");

    cout <<setw(30)<<"name"<<setw(10)<<dummy.NAME<<endl<<endl;
    cout <<setw(5)<<"date"<<endl<<dummy.AGE.day<<setw(5)<<dummy.AGE.month<<setw(5)<< dummy.AGE.year <<endl;
    cout <<setw(5)<<"address"<<endl<<"permanet adress :"<<dummy.ADDRESS.padr <<endl<<"temporary adress :"<< dummy.ADDRESS.radr<<endl;
    cout <<setw(5)<<"JOBSTAUTS"<<endl<<dummy.JOB_status <<"\r  "<<endl;
    cout <<setw(5)<<"phoneNO\n";
        for(int i = 0 ; i<2 ; i++)cout <<dummy.REFRENCES.phone1[i]<<endl;
    cout <<setw(10)<<"EMAIL\n";
        for(int i = 0 ; i<2 ; i++)cout << dummy.REFRENCES.email[i]<<endl;
    cout <<setw(10)<<"job pay"<<setw(10)<<dummy.pay<<endl;
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

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

        cout << "you pay ";
             cin >> dummy.pay;



    }while(!display(dummy));

    screen(dummy);
    while(!fs:: exists("markdown.txt")){
        this_thread::sleep_for(chrono::seconds(1));
    }

    if(read()){
        cout << "your form is validated you may procddeed\n";
        *W = dummy;
        calculation(W[z]);

        z++;

    }else{
        cout << "your data is terminated";
        int a;
        cin >> a;
    }



}

void display(const worker dummy[]  ){

for(int g = 0 ; g < z ; g++ ){
    cout <<setw(30)<<"name : "<<setw(10)<<dummy[g].NAME<<endl ;
    cout <<setw(5)<<"date"<<endl<<dummy[g].AGE.day<<setw(5)<<dummy[g].AGE.month<<setw(5)<< dummy[g].AGE.year <<endl<<endl;
    cout <<setw(5)<<"address"<<endl<<dummy[g].ADDRESS.padr <<endl<< dummy[g].ADDRESS.radr<<endl<<endl;
    cout <<setw(5)<<"JOBSTAUTS"<<endl<<dummy[g].JOB_status <<endl<<endl;
    cout <<setw(5)<<"phoneNO\n";
     for(int i = 0 ; i<2 ; i++)cout <<setw(2)<< dummy[g].REFRENCES.phone1[i]<<endl;
     cout <<endl; 
    cout <<setw(10)<<"EMAIL\n";
     for(int i = 0 ; i<2 ; i++)cout <<setw(2)<< dummy[g].REFRENCES.email[i]<<endl;
     cout<<endl;
    cout <<setw(5)<<"pay"<<setw(5)<<dummy[g].pay<<endl<<endl;    
     cout <<setw(10)<<"benifitlevel"<<setw(10)<<dummy[g].increase<<endl;
   

     cout <<endl<<endl<<endl;
} 

}

void cumputation(worker *W, int i){

    switch (i){
        case 0 : (*W).increase +=  W->pay*0.05  ;
        break;
        case 1 : (*W).increase +=  W->pay*0.10 ;
        break;
        case 2 : (*W).increase +=  W->pay*0.20 ;
    }

}

void calculation(worker &w){
    cout << "you will be posed with 5 question in afferamation to hte statmetn press 0 else any key ";

    // all 3 condition in same row must be true if not only till 

                string conditions[3][3] = {
                {
                    "Commute distance exceeds 50 km",
                    "Family size is at least 2 members",
                    "Affected by a category-3 medical condition"
                },
                {
                    "Workload negatively impacts well-being",
                    "Monthly expenses exceed monthly income",
                    "Financially strained with fewer than 2 dependents"
                },
                {
                    "Fully self-dependent with no external support",
                    "Family size is at least 5 members",
                    "Financial burden exceeds 10,000 due to load or obligations"
                }
            };
        bool  check ;
        for(int i = 0; i< 3 ; i++){
            bool flag =true;
            for(int j = 0 ; j<3 ; j++){

              cout <<   conditions[i][j] << endl;
              cin >>  check;
              if(!check)flag=false;
            

            }
            if(flag)cumputation(&w,i);
        }

        w.bonus = w.pay + w.increase;

     
  
}

int display(){
        int a;
        cout << setw(20) << "table of contetn\n";
            cout << " 1 register worker data menu \n";
            cout << " 2 display all workers data as of now\n ";
          
        cin>>a;
        return a;
        

}
void selection(int a , worker W[]  ){
    system("cls");

    switch (a){
        case 1:  tag(&W[z]);
        break;
        case 2:  display(W);
        break;
   
    }



          
}


int main(){
  const int total = 5;
  worker  W[total];
  
  
while(true){
    selection(display() , W );
}



}