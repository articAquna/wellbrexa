#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<chrono>
#include<thread>
#include<algorithm>
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;
using namespace std;

int z = 0;
string Y = "abc";
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
struct net{
int positive;
int negative;
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
    net data;
    


};

void calculation(worker &w);
void slow(int s){
    cout << "system is proceesing the data\n";
    this_thread::sleep_for(chrono :: seconds(s));
}
bool read(){
    ifstream fin("markdown.txt");
    string characters;
    fin >> characters;
    fin.close();

    return(characters=="yes");

}

void screen(const worker &dummy){
    ofstream fout("workerdata.txt");


    fout << setw(20) << "Name" << setw(20) << dummy.NAME << endl;
    fout << setw(20) << "Date of Birth" << setw(5) << dummy.AGE.day << "/" << setw(2) << dummy.AGE.month << "/" << setw(4) << dummy.AGE.year << endl;
    fout << setw(20) << "Address" << endl << "Permanent: " << dummy.ADDRESS.padr << endl << "Temporary: " << dummy.ADDRESS.radr << endl;
    fout << setw(20) << "Job Status" << setw(20) << dummy.JOB_status << endl;
    fout << setw(20) << "Phone Numbers" << endl;
    for(int i = 0; i < 2; i++){
    fout << dummy.REFRENCES.phone1[i] << endl;
    }
    fout << setw(20) << "Emails" << endl;
    for(int i = 0; i < 2; i++){
    fout << dummy.REFRENCES.email[i] << endl;
    }
    fout << setw(20) << "Pay" << setw(10) << dummy.pay << endl;

    


}

bool display(const worker &dummy){
     system("cls");
    cout << setw(20) << "Name" << setw(20) << dummy.NAME << endl << endl;
    cout << setw(20) << "Date of Birth" << endl << setw(5) << dummy.AGE.day << "/" << setw(2) << dummy.AGE.month << "/" << setw(4) << dummy.AGE.year << endl;
    cout << setw(20) << "Address" << endl << "Permanent: " << dummy.ADDRESS.padr << endl << "Temporary: " << dummy.ADDRESS.radr << endl;
    cout << setw(20) << "Job Status" << endl << dummy.JOB_status << endl;
    cout << setw(20) << "Phone Numbers" << endl;
        for(int i = 0; i < 2; i++) cout << dummy.REFRENCES.phone1[i] << endl;
    cout << setw(20) << "Emails" << endl;
        for(int i = 0; i < 2; i++) cout << dummy.REFRENCES.email[i] << endl;
    cout << setw(20) << "Job Pay" << setw(10) << dummy.pay << endl;
    cout << endl << endl << endl;
    cout << "If this is your data, input 1: ";
    int v;
    cin >> v;
   return (v==1)?true :false;

}

void tag(worker *W){

    cout << "Dear worker, you will be provided with questions.";
    cout << "Infer and remember without verification, you're dead.\n";
    worker dummy = *W;
    do{
        cout << "Enter your name: ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin , dummy.NAME);


        cout << "Enter your age:\n";
        
            cout << "Day: ";
            cin >> dummy.AGE.day;
            cout << "Month: ";
            cin >> dummy.AGE.month;
            cout << "Year: ";
            cin >> dummy.AGE.year;
        
        cout <<"Now for your addresses:\n";

            cout << "Provide your permanent address: ";
            cin >> dummy.ADDRESS.padr;
            cout << "Provide your temporary address: ";
            cin >> dummy.ADDRESS.radr;

        cout <<"Now for your contacts:\n";

            cout << "Enter your 2 phone numbers:\n";
            for(int k = 0; k < 2; k++){
            cin >> dummy.REFRENCES.phone1[k];
                    }

            cout << "Enter your 2 email addresses:\n";
            for(int k = 0; k < 2; k++){
            cin >> dummy.REFRENCES.email[k];
                    }
           
        string commonJobs[5] = {

            "1=Administrative Assistant",
            "2=HR Officer",
            "3=Accountant",
            "4=IT Support",
            "5=Customer Service Representative"
                                                 };
            cout << "Choose your profession:" << endl; 
             for(int k = 0; k < 5; k++){
             cout << setw(10) << commonJobs[k] << endl; 
             }
             int v;
             cin >> v;
             dummy.JOB_status = commonJobs[v-1];

        cout << "Your pay: ";
             cin >> dummy.pay;



    }while(!display(dummy));

    screen(dummy);
    while(!fs:: exists("markdown.txt")){
        this_thread::sleep_for(chrono::seconds(1));
    }

    if(read()){
        cout << "Your form is validated. You may proceed.\n";
        *W = dummy;
        calculation(W[z]);

        z++;

    }else{
        cout << "Your data is terminated.";
        int a;
        cin >> a;
    }



}

void transfer(const string &a , string *Y ){
    *Y = a;
    cout << "Password updated successfully." << endl;
}
bool password(const string &a , const string &Y){
    return (a == Y);
}
void newpassword(){
    string p;
    cout<<"Input original password to proceed: ";
    cin >> p;
 if(password(p , Y)){
    cout << "Enter new password: ";
    string a;
    cin >> a;
    transfer(a,&Y);
    
 }else{
    cout << "Invalid password. Access denied.";
 }
 
 std::this_thread::sleep_for(std::chrono :: seconds(5));
 system("cls");
  
}

 


void display(const worker dummy[]  ){
    cout << "Input password to proceed: ";
    string a;
    cin >> a;
   if (password(a,Y)){

            for(int g = 0; g < z; g++){
                cout << setw(20) << "Name: " << setw(20) << dummy[g].NAME << endl;
                cout << setw(20) << "Date of Birth: " << setw(5) << dummy[g].AGE.day << "/" << setw(2) << dummy[g].AGE.month << "/" << setw(4) << dummy[g].AGE.year << endl << endl;
                cout << setw(20) << "Address: " << endl << "Permanent: " << dummy[g].ADDRESS.padr << endl << "Temporary: " << dummy[g].ADDRESS.radr << endl << endl;
                cout << setw(20) << "Job Status: " << dummy[g].JOB_status << endl << endl;
                cout << setw(20) << "Phone Numbers: " << endl;
                for(int i = 0; i < 2; i++) cout << dummy[g].REFRENCES.phone1[i] << endl;
                cout << endl; 
                cout << setw(20) << "Emails: " << endl;
                for(int i = 0; i < 2; i++) cout << dummy[g].REFRENCES.email[i] << endl;
                cout << endl;
                cout << setw(20) << "Pay: " << setw(10) << dummy[g].pay << endl << endl;    
                cout << setw(20) << "Benefit Level: " << setw(10) << dummy[g].increase << endl;
            

                cout << endl << endl << endl;
            } 

        }else {
            cout << "Invalid password." << endl;
        }
}
void cumputation(worker *W, int i){

    switch(i){
        case 0: (*W).increase += W->pay * 0.05;
        break;
        case 1: (*W).increase += W->pay * 0.10;
        break;
        case 2: (*W).increase += W->pay * 0.20;
    }

}

void calculation(worker &w){
    cout << "You will be posed with 5 questions in affirmation to the statement. Press 0 if true, else any key: ";

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
    bool check;
    for(int i = 0; i < 3; i++){
        bool flag = true;
        for(int j = 0; j < 3; j++){
            cout << conditions[i][j] << endl;
            cin >> check;
            if(check) flag = false;
        }
        if(flag) cumputation(&w, i);
    }

    w.bonus = w.pay + w.increase;
}

int display(){
        int a;
        cout << setw(30) << "Table of Contents" << endl;
            cout << "1. Register worker data menu" << endl;
            cout << "2. Display all workers' data as of now" << endl;
            cout << "3. Change system password" << endl;
            cout << "4. to view your personal data\n";
            cout << "5. enter commit about the system\n";
            cout << "6. view the status of teh system\n";
            

        cin>>a;
        return a;
        

}
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
   


void commit(worker W[]) {

    std::vector<std::string> positiveWords = {
        "good", "happy", "love", "excellent", "great", "wonderful", "amazing", "like",
        "joy", "joyful", "delight", "delighted", "cheerful", "optimistic", "positive",
        "fantastic", "brilliant", "outstanding", "superb", "incredible", "fabulous",
        "awesome", "marvelous", "splendid", "terrific", "glorious", "successful",
        "accomplished", "peaceful", "calm", "friendly", "kind", "generous", "helpful",
        "supportive", "beautiful", "handsome", "charming", "graceful", "bright",
        "creative", "innovative", "smart", "intelligent", "wise", "strong", "powerful",
        "confident", "motivated", "inspired", "hopeful", "encouraging", "enthusiastic",
        "energetic", "fun", "funny", "playful", "adventurous", "curious", "lovely",
        "sweet", "caring", "compassionate", "affectionate", "romantic", "loyal",
        "trustworthy", "honest", "reliable", "resilient", "determined", "brave",
        "courageous", "fearless", "healthy", "fit", "strong-willed", "hardworking",
        "dedicated", "passionate", "talented", "skilled", "capable", "resourceful",
        "successful", "victorious", "winner", "thriving", "prosperous", "wealthy",
        "fortunate", "blessed", "grateful", "thankful", "appreciative", "positive-minded",
        "uplifting", "radiant", "vibrant", "glowing", "smiling", "laughing", "joyous"
    };
    std::vector<std::string> negativeWords = {
        "bad", "sad", "hate", "terrible", "awful", "horrible", "poor", "don't like",
        "frustrating", "boring", "angry", "upset", "annoyed", "disappointed", "miserable",
        "depressed", "lonely", "unhappy", "unpleasant", "painful", "hurt", "sick", "ill",
        "weak", "failure", "loser", "worthless", "useless", "hopeless", "pathetic",
        "disgusting", "gross", "nasty", "dirty", "messy", "chaotic", "confusing",
        "difficult", "hard", "problem", "issue", "error", "wrong", "fake", "liar",
        "selfish", "greedy", "jealous", "envy", "angst", "fear", "scared", "afraid",
        "anxious", "nervous", "stress", "stressed", "tired", "exhausted", "lazy",
        "ignorant", "stupid", "dumb", "foolish", "arrogant", "rude", "mean", "cruel",
        "violent", "abusive", "toxic", "negative", "unfair", "unjust", "corrupt",
        "evil", "sinful", "shameful", "guilty", "regret", "resentful", "bitter",
        "broken", "damaged", "lost", "confused", "trapped", "stuck", "weakness",
        "unreliable", "fake", "annoying", "disrespectful", "untrustworthy", "manipulative",
        "controlling", "oppressive", "harsh", "cold", "distant", "unfriendly"
    };

    std::string input;
    std::cout << "Enter your text: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::getline(std::cin, input);

    input = toLower(input);


    for (const auto& pos : positiveWords) {
        if (input.find(pos) != std::string::npos) {
            W[z].data.positive += 1;
        }
    }
    for (const auto& neg : negativeWords) {
        if (input.find(neg) != std::string::npos) {
            W[z].data.negative += 1 ;
        }
    }

    slow(5);
    system("cls");

}
void scores(worker W[]);

void Personal_log(const worker dummy[]){
    string a;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin , a);
    bool flag(true);
    for(int g = 0; g < z; g++){
        
        if(a == dummy[g].NAME ){
                cout << setw(20) << "Name: " << setw(20) << dummy[g].NAME << endl;
                cout << setw(20) << "Date of Birth: " << setw(5) << dummy[g].AGE.day << "/" << setw(2) << dummy[g].AGE.month << "/" << setw(4) << dummy[g].AGE.year << endl << endl;
                cout << setw(20) << "Address: " << endl << "Permanent: " << dummy[g].ADDRESS.padr << endl << "Temporary: " << dummy[g].ADDRESS.radr << endl << endl;
                cout << setw(20) << "Job Status: " << dummy[g].JOB_status << endl << endl;
                cout << setw(20) << "Phone Numbers: " << endl;
                for(int i = 0; i < 2; i++) cout << dummy[g].REFRENCES.phone1[i] << endl;
                cout << endl; 
                cout << setw(20) << "Emails: " << endl;
                for(int i = 0; i < 2; i++) cout << dummy[g].REFRENCES.email[i] << endl;
                cout << endl;
                cout << setw(20) << "Pay: " << setw(10) << dummy[g].pay << endl << endl;    
                cout << setw(20) << "Benefit Level: " << setw(10) << dummy[g].increase << endl;

                cout << endl << endl << endl;
                flag = false;
                cout << "to continue press 1";
                int p;
                cin >> p;
              
            } 
        }

       if(flag){
        cout << "no worker of that  name exists  "; 

       }
       std::this_thread::sleep_for(std :: chrono :: seconds(3));

       system("cls");


}

void selection(int a, worker W[]){
    system("cls");

    switch(a){

        case 1: tag(&W[z]);
        break;
        case 2: display(W);
        break;
        case 3: newpassword();
        break;
        case 4: Personal_log(W);
        break;
        case 5: commit(W);
        break;
        case 6: scores(W);
        
    }
}
void scores(worker W[]) {
    string s;
    cout << "input system password";
    cin >> s;
    if(password(s,Y)){
    int P,N;
    for(int i = 0 ; i < z ; i++){
        P += W[i].data.positive;
        N += W[i].data.negative;
        
    }

    if (P > N) {
        std::cout << "Overall Sentiment: Positive\n";
    }
    else if (N > P) {
        std::cout << "Overall Sentiment: Negative\n";
    }
    else {
        std::cout << "Overall Sentiment: Neutral\n";
    }

}else {
    cout << "invalid password";
}

slow(5);
system("cls");

}

int main(){

    const int total = 5;
    worker W[total];

    while(true){
        selection(display(), W);
    }
}