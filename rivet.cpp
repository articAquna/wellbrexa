#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<chrono>
#include<thread>
#include<algorithm>
#include<filesystem>
#include<vector>
#include<limits>
#include<cfloat>
#include<windows.h>

namespace fs = std::filesystem;
using namespace std;

// Global variables
int z = 0;
int z_old = 0;
string Y = "abc";

// Structure definitions
struct age {
    int day, month, year;
};

struct add {
    string padr, radr;
};

struct cont {
    string phone1[2], email[2];
};

struct net {
    int positive = 0;
    int negative = 0;
};

struct worker {
    string NAME;
    age AGE;
    add ADDRESS;
    cont REFERENCES;
    string JOB_status;
    float pay;
    float bonus;
    int signature[5];
    float increase = 0;
    net data;
    int id = 0;
};

// Function declarations
void calculation(worker &w);
void slow(int s);
bool read();
void screen(const worker &dummy);
bool display(const worker &dummy);
void tag(worker *W);
void transfer(const string &a, string *Y);
bool password(const string &a, const string &Y);
void newpassword();
void display(const worker dummy[]);
void computation(worker *W, int i);
void change(worker w[]);
int display();
void commit(worker W[]);
void scores(worker W[]);
void Personal_log(const worker dummy[]);
void transition();
void selection(int a, worker W[]);
string toLower(const string& str);

// Error Handling Functions

/**
 * Validates date input
 * @param day The day value
 * @param month The month value
 * @param year The year value
 * @return true if date is valid, false otherwise
 */
bool validateDate(int day, int month, int year) {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }
    
    return day <= daysInMonth[month - 1];
}

/**
 * Safely reads integer input with validation
 * @param prompt The message to display to the user
 * @param min Minimum allowed value
 * @param max Maximum allowed value
 * @return Valid integer input
 */
int safeIntInput(const string &prompt, int min = INT_MIN, int max = INT_MAX) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= min && value <= max) {
                return value;
            } else {
                cout << "Error: Input must be between " << min << " and " << max << ". Please try again.\n";
            }
        } else {
            cout << "Error: Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/**
 * Safely reads float input with validation
 * @param prompt The message to display to the user
 * @param min Minimum allowed value
 * @param max Maximum allowed value
 * @return Valid float input
 */
float safeFloatInput(const string &prompt, float min = 0.0f, float max = FLT_MAX) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= min && value <= max) {
                return value;
            } else {
                cout << "Error: Input must be between " << min << " and " << max << ". Please try again.\n";
            }
        } else {
            cout << "Error: Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/**
 * Safely reads string input with validation
 * @param prompt The message to display to the user
 * @param allowEmpty Whether to allow empty strings
 * @return Valid string input
 */
string safeStringInput(const string &prompt, bool allowEmpty = false) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);
        if (!value.empty() || allowEmpty) {
            return value;
        }
        cout << "Error: Input cannot be empty. Please try again.\n";
    }
}

/**
 * Validates email format
 * @param email The email address to validate
 * @return true if email format is valid, false otherwise
 */
bool validateEmail(const string &email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find_last_of('.');
    return (atPos != string::npos && dotPos != string::npos && 
            atPos < dotPos && dotPos < email.length() - 1 && atPos > 0);
}

/**
 * Validates phone number format
 * @param phone The phone number to validate
 * @return true if phone format is valid, false otherwise
 */
bool validatePhone(const string &phone) {
    if (phone.empty() || phone.length() < 10) return false;
    for (char c : phone) {
        if (!isdigit(c) && c != '+' && c != '-' && c != ' ' && c != '(' && c != ')') {
            return false;
        }
    }
    return true;
}

/**
 * Handles file opening errors
 * @param filename The name of the file
 * @param mode The mode (read/write)
 * @return true if file exists and is accessible, false otherwise
 */
bool handleFileError(const string &filename, const string &mode) {
    if (mode == "read") {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open file '" << filename << "' for reading.\n";
            cerr << "The file may not exist or you may not have read permissions.\n";
            return false;
        }
        file.close();
    } else if (mode == "write") {
        ofstream file(filename, ios::app);
        if (!file) {
            cerr << "Error: Unable to open file '" << filename << "' for writing.\n";
            cerr << "You may not have write permissions in this directory.\n";
            return false;
        }
        file.close();
    }
    return true;
}

/**
 * Clears the input buffer
 */
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Core Functions

/**
 * Displays a processing message and pauses execution
 * @param s Number of seconds to wait
 */
void slow(int s) {
    cout << "System is processing the data...\n";
    this_thread::sleep_for(chrono::seconds(s));
    system("cls");
}

/**
 * Reads validation status from file
 * @return true if validation is approved, false otherwise
 */
bool read() {
    if (!handleFileError("markdown.txt", "read")) {
        cerr << "Warning: Validation file not found. Creating default.\n";
        ofstream fout("markdown.txt");
        if (fout) {
            fout << "no";
            fout.close();
        }
        return false;
    }
    
    ifstream fin("markdown.txt");
    string characters;
    fin >> characters;
    fin.close();
    
    return (characters == "yes");
}

/**
 * Writes worker data to file
 * @param dummy The worker object to save
 */
void screen(const worker &dummy) {
    if (!handleFileError("workerdata.txt", "write")) {
        cerr << "Error: Failed to save worker data to file.\n";
        return;
    }
    
    ofstream fout("workerdata.txt", ios::app);
    if (!fout) {
        cerr << "Error: Unable to write to worker data file.\n";
        return;
    }
    
    fout << setw(20) << "Name" << setw(20) << dummy.NAME << endl;
    fout << setw(20) << "Date of Birth" << setw(5) << dummy.AGE.day << "/" 
         << setw(2) << dummy.AGE.month << "/" << setw(4) << dummy.AGE.year << endl;
    fout << setw(20) << "Address" << endl << "Permanent: " << dummy.ADDRESS.padr 
         << endl << "Temporary: " << dummy.ADDRESS.radr << endl;
    fout << setw(20) << "Job Status" << setw(20) << dummy.JOB_status << endl;
    fout << setw(20) << "Phone Numbers" << endl;
    for (int i = 0; i < 2; i++) {
        fout << dummy.REFERENCES.phone1[i] << endl;
    }
    fout << setw(20) << "Emails" << endl;
    for (int i = 0; i < 2; i++) {
        fout << dummy.REFERENCES.email[i] << endl;
    }
    fout << setw(20) << "Pay" << setw(10) << dummy.pay << endl;
    fout.close();
    
    cout << "Worker data saved successfully.\n";
}

/**
 * Displays worker information and asks for confirmation
 * @param dummy The worker object to display
 * @return true if data is confirmed, false otherwise
 */
bool display(const worker &dummy) {
    system("cls");
    cout << setw(20) << "Name" << setw(20) << dummy.NAME << endl << endl;
    cout << setw(20) << "Date of Birth" << endl << setw(5) << dummy.AGE.day << "/" 
         << setw(2) << dummy.AGE.month << "/" << setw(4) << dummy.AGE.year << endl;
    cout << setw(20) << "Address" << endl << "Permanent: " << dummy.ADDRESS.padr 
         << endl << "Temporary: " << dummy.ADDRESS.radr << endl;
    cout << setw(20) << "Job Status" << endl << dummy.JOB_status << endl;
    cout << setw(20) << "Phone Numbers" << endl;
    for (int i = 0; i < 2; i++) cout << dummy.REFERENCES.phone1[i] << endl;
    cout << setw(20) << "Emails" << endl;
    for (int i = 0; i < 2; i++) cout << dummy.REFERENCES.email[i] << endl;
    cout << setw(20) << "Pay" << setw(10) << dummy.pay << endl;
    cout << endl << endl;
    
    int v = safeIntInput("If this is your data, input 1: ", 0, 1);
    return (v == 1);
}

/**
 * Collects worker information through user input
 * @param W Pointer to worker array
 */
void tag(worker *W) {
    if (z != z_old) {
        int a = safeIntInput("Do you wish to update your data? If so, enter 1: ", 0, 1);
        if (a != 1) {
            return;
        }
    }
    
    cout << "Dear worker, you will be asked some questions. Please answer truthfully.\n";
    worker dummy = *W;
    
    do {
        // Get name
        clearInputBuffer();
        dummy.NAME = safeStringInput("Enter your name: ");
        
        // Get date of birth with validation
        bool validDate = false;
        while (!validDate) {
            cout << "Enter your date of birth:\n";
            dummy.AGE.day = safeIntInput("Day: ", 1, 31);
            dummy.AGE.month = safeIntInput("Month: ", 1, 12);
            dummy.AGE.year = safeIntInput("Year: ", 1900, 2100);
            
            if (validateDate(dummy.AGE.day, dummy.AGE.month, dummy.AGE.year)) {
                validDate = true;
            } else {
                cout << "Error: Invalid date. Please enter a valid date.\n";
            }
        }
        
        // Get addresses
        cout << "Now, your addresses:\n";
        clearInputBuffer();
        dummy.ADDRESS.padr = safeStringInput("Provide your permanent address: ");
        dummy.ADDRESS.radr = safeStringInput("Provide your temporary address: ");
        
        // Get contacts with validation
        cout << "Now, your contacts:\n";
        cout << "Enter your 2 phone numbers:\n";
        for (int k = 0; k < 2; k++) {
            bool validPhone = false;
            while (!validPhone) {
                dummy.REFERENCES.phone1[k] = safeStringInput("Phone " + to_string(k + 1) + ": ");
                if (validatePhone(dummy.REFERENCES.phone1[k])) {
                    validPhone = true;
                } else {
                    cout << "Error: Invalid phone number format. Please try again.\n";
                }
            }
        }
        
        cout << "Enter your 2 email addresses:\n";
        for (int k = 0; k < 2; k++) {
            bool validEmail = false;
            while (!validEmail) {
                dummy.REFERENCES.email[k] = safeStringInput("Email " + to_string(k + 1) + ": ");
                if (validateEmail(dummy.REFERENCES.email[k])) {
                    validEmail = true;
                } else {
                    cout << "Error: Invalid email format. Please try again.\n";
                }
            }
        }
        
        // Get job selection
        string commonJobs[5] = {
            "1=Administrative Assistant",
            "2=HR Officer",
            "3=Accountant",
            "4=IT Support",
            "5=Customer Service Representative"
        };
        cout << "Choose your profession:" << endl;
        for (int k = 0; k < 5; k++) {
            cout << setw(10) << commonJobs[k] << endl;
        }
        int v = safeIntInput("Enter choice (1-5): ", 1, 5);
        dummy.JOB_status = commonJobs[v - 1];
        
        // Get pay
        dummy.pay = safeFloatInput("Your pay: ", 0.0f, 1000000.0f);
        
    } while (!display(dummy));
    
    screen(dummy);
    
    // Wait for validation file
    cout << "Waiting for validation...\n";
    while (!fs::exists("markdown.txt")) {
        this_thread::sleep_for(chrono::seconds(1));
    }
    
    if (read()) {
        cout << "Your form is validated. You may proceed.\n";
        *W = dummy;
        W->id = z + 1;
        cout << "Assigned worker ID: " << W->id << endl;
        calculation(W[z]);
        z++;
        z_old++;
    } else {
        cout << "Your data has been terminated.\n";
        cout << "Press any key to continue...";
        clearInputBuffer();
        cin.get();
    }
}

/**
 * Updates the system password
 * @param a New password
 * @param Y Pointer to password variable
 */
void transfer(const string &a, string *Y) {
    *Y = a;
    cout << "Password updated successfully." << endl;
}

/**
 * Verifies password
 * @param a Input password
 * @param Y Stored password
 * @return true if passwords match, false otherwise
 */
bool password(const string &a, const string &Y) {
    return (a == Y);
}

/**
 * Changes system password
 */
void newpassword() {
    string p;
    cout << "Input original password to proceed: ";
    cin >> p;
    
    if (password(p, Y)) {
        cout << "Enter new password: ";
        string a;
        cin >> a;
        
        if (a.length() < 3) {
            cout << "Error: Password must be at least 3 characters long.\n";
        } else {
            transfer(a, &Y);
        }
    } else {
        cout << "Invalid password. Access denied.\n";
    }
    
    this_thread::sleep_for(chrono::seconds(5));
    system("cls");
}

/**
 * Displays all workers' data
 * @param dummy Array of worker objects
 */
void display(const worker dummy[]) {
    cout << "Input password to proceed: ";
    string a;
    cin >> a;
    
    if (password(a, Y)) {
        if (z == 0) {
            cout << "No worker data available.\n";
            this_thread::sleep_for(chrono::seconds(3));
            return;
        }
        
        for (int g = 0; g < z; g++) {
            cout << "---------------------------------------------------------------------------------------------------------\n";
            cout << setw(20) << "Name: " << setw(20) << dummy[g].NAME << endl;
            cout << setw(20) << "Date of Birth: " << setw(5) << dummy[g].AGE.day << "/" 
                 << setw(2) << dummy[g].AGE.month << "/" << setw(4) << dummy[g].AGE.year << endl << endl;
            cout << setw(20) << "Address: " << endl << "Permanent: " << dummy[g].ADDRESS.padr 
                 << endl << "Temporary: " << dummy[g].ADDRESS.radr << endl << endl;
            cout << setw(20) << "Job Status: " << dummy[g].JOB_status << endl << endl;
            cout << setw(20) << "Phone Numbers: " << endl;
            for (int i = 0; i < 2; i++) cout << dummy[g].REFERENCES.phone1[i] << endl;
            cout << endl;
            cout << setw(20) << "Emails: " << endl;
            for (int i = 0; i < 2; i++) cout << dummy[g].REFERENCES.email[i] << endl;
            cout << endl;
            cout << setw(20) << "Pay: " << setw(10) << dummy[g].pay << endl << endl;
            cout << setw(20) << "Benefit Level: " << setw(10) << dummy[g].increase << endl;
            cout << "---------------------------------------------------------------------------------------------------------\n";
            cout << endl << endl;
        }
        
        cout << "Press any key to continue...";
        clearInputBuffer();
        cin.get();
    } else {
        cout << "Invalid password." << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
    system("cls");
}

/**
 * Computes benefit increase based on category
 * @param W Pointer to worker object
 * @param i Category index
 */
void computation(worker *W, int i) {
    switch (i) {
        case 0:
            (*W).increase += W->pay * 0.05;
            break;
        case 1:
            (*W).increase += W->pay * 0.10;
            break;
        case 2:
            (*W).increase += W->pay * 0.20;
            break;
        default:
            cerr << "Error: Invalid computation category.\n";
            break;
    }
}

/**
 * Calculates worker benefits based on questionnaire
 * @param w Reference to worker object
 */
void calculation(worker &w) {
    cout << "You will be asked questions in affirmation to the statements.\n";
    cout << "Press 0 if true, else press 1: \n\n";
    
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
            "Financial burden exceeds 10,000 due to loans or obligations"
        }
    };
    
    for (int i = 0; i < 3; i++) {
        bool flag = true;
        cout << "\nCategory " << (i + 1) << ":\n";
        for (int j = 0; j < 3; j++) {
            cout << (j + 1) << ". " << conditions[i][j] << endl;
            int check = safeIntInput("Answer (0=True, 1=False): ", 0, 1);
            if (check != 0) flag = false;
        }
        if (flag) computation(&w, i);
    }
    
    w.bonus = w.pay + w.increase;
    cout << "\nBenefit calculation completed.\n";
    this_thread::sleep_for(chrono::seconds(2));
}

/**
 * Switches to a different worker
 * @param w Array of worker objects
 */
void change(worker w[]) {
    if (z_old == 0) {
        cout << "No workers available to switch to.\n";
        slow(3);
        return;
    }
    
    cout << "Enter the employee ID: ";
    int k;
    cin >> k;
    
    if (cin.fail()) {
        cout << "Error: Invalid input.\n";
        clearInputBuffer();
        slow(3);
        return;
    }
    
    bool found = false;
    for (int i = 0; i < z_old; i++) {
        if (k == w[i].id) {
            z = i;
            cout << "Switched to worker: " << w[z].NAME << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Error: Worker ID not found. Switch declined.\n";
    }
    slow(3);
}

/**
 * Displays main menu
 * @return Selected menu option
 */
int display() {
    int a;
    cout << setw(30) << "Table of Contents" << endl;
    cout << "1. Register worker data menu" << endl;
    cout << "2. Display all workers' data as of now" << endl;
    cout << "3. Change system password" << endl;
    cout << "4. View your personal data" << endl;
    cout << "5. Enter comment about the system" << endl;
    cout << "6. View the status of the system" << endl;
    cout << "7. Switch users" << endl;
    cout << "8. Revert back to original status" << endl;
    
    a = safeIntInput("\nEnter your choice: ", 1, 8);
    return a;
}

/**
 * Converts string to lowercase
 * @param str Input string
 * @return Lowercase string
 */
string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

/**
 * Analyzes user comment for sentiment
 * @param W Array of worker objects
 */
void commit(worker W[]) {
    vector<string> positiveWords = {
        "good", "happy", "love", "excellent", "great", "wonderful", "amazing", "like",
        "joy", "joyful", "delight", "delighted", "cheerful", "optimistic", "positive",
        "fantastic", "brilliant", "outstanding", "superb", "incredible", "fabulous",
        "awesome", "marvelous", "splendid", "terrific", "glorious", "successful"
    };
    
    vector<string> negativeWords = {
        "bad", "sad", "hate", "terrible", "awful", "horrible", "poor", "don't like",
        "frustrating", "boring", "angry", "upset", "annoyed", "disappointed", "miserable",
        "depressed", "lonely", "unhappy", "unpleasant", "painful", "hurt", "sick"
    };
    
    string input;
    cout << "Enter your comment: ";
    clearInputBuffer();
    getline(cin, input);
    
    if (input.empty()) {
        cout << "Error: Comment cannot be empty.\n";
        slow(3);
        return;
    }
    
    input = toLower(input);
    
    for (const auto& pos : positiveWords) {
        if (input.find(pos) != string::npos) {
            W[z].data.positive += 1;
        }
    }
    
    for (const auto& neg : negativeWords) {
        if (input.find(neg) != string::npos) {
            W[z].data.negative += 1;
        }
    }
    
    cout << "Comment recorded successfully.\n";
    slow(3);
}

/**
 * Displays personal worker data by name
 * @param dummy Array of worker objects
 */
void Personal_log(const worker dummy[]) {
    if (z == 0) {
        cout << "No worker data available.\n";
        this_thread::sleep_for(chrono::seconds(3));
        system("cls");
        return;
    }
    
    string a;
    clearInputBuffer();
    a = safeStringInput("Enter worker name: ");
    
    bool flag = true;
    for (int g = 0; g < z; g++) {
        if (a == dummy[g].NAME) {
            cout << setw(20) << "Name: " << setw(20) << dummy[g].NAME << endl;
            cout << setw(20) << "Date of Birth: " << setw(5) << dummy[g].AGE.day << "/" 
                 << setw(2) << dummy[g].AGE.month << "/" << setw(4) << dummy[g].AGE.year << endl << endl;
            cout << setw(20) << "Address: " << endl << "Permanent: " << dummy[g].ADDRESS.padr 
                 << endl << "Temporary: " << dummy[g].ADDRESS.radr << endl << endl;
            cout << setw(20) << "Job Status: " << dummy[g].JOB_status << endl << endl;
            cout << setw(20) << "Phone Numbers: " << endl;
            for (int i = 0; i < 2; i++) cout << dummy[g].REFERENCES.phone1[i] << endl;
            cout << endl;
            cout << setw(20) << "Emails: " << endl;
            for (int i = 0; i < 2; i++) cout << dummy[g].REFERENCES.email[i] << endl;
            cout << endl;
            cout << setw(20) << "Pay: " << setw(10) << dummy[g].pay << endl << endl;
            cout << setw(20) << "Benefit Level: " << setw(10) << dummy[g].increase << endl;
            cout << endl;
            
            flag = false;
            cout << "To continue, press 1: ";
            int p;
            cin >> p;
            break;
        }
    }
    
    if (flag) {
        cout << "No worker with that name exists.\n";
    }
    
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
}

/**
 * Reverts to original user status
 */
void transition() {
    cout << "Returning user status to add new worker.\n";
    slow(2);
    z = z_old;
}

/**
 * Routes menu selection to appropriate function
 * @param a Menu option selected
 * @param W Array of worker objects
 */
void selection(int a, worker W[]) {
    system("cls");
    
    try {
        switch (a) {
            case 1:
                tag(&W[z]);
                break;
            case 2:
                display(W);
                break;
            case 3:
                newpassword();
                break;
            case 4:
                Personal_log(W);
                break;
            case 5:
                commit(W);
                break;
            case 6:
                scores(W);
                break;
            case 7:
                change(W);
                break;
            case 8:
                transition();
                break;
            default:
                cout << "Error: Invalid selection.\n";
                slow(2);
                break;
        }
    } catch (const exception &e) {
        cerr << "Error: An exception occurred - " << e.what() << endl;
        slow(3);
    }
}

/**
 * Displays overall system sentiment analysis
 * @param W Array of worker objects
 */
void scores(worker W[]) {
    string s;
    cout << "Input system password: ";
    cin >> s;
    
    if (password(s, Y)) {
        if (z_old == 0) {
            cout << "No worker data available for analysis.\n";
            slow(5);
            system("cls");
            return;
        }
        
        int P = 0, N = 0;
        for (int i = 0; i < z_old; i++) {
            P += W[i].data.positive;
            N += W[i].data.negative;
        }
        
        cout << "\n=== System Sentiment Analysis ===\n";
        cout << "Positive comments: " << P << endl;
        cout << "Negative comments: " << N << endl;
        
        if (P > N) {
            cout << "Overall Sentiment: Positive\n";
        } else if (N > P) {
            cout << "Overall Sentiment: Negative\n";
        } else {
            cout << "Overall Sentiment: Neutral\n";
        }
    } else {
        cout << "Invalid password.\n";
    }
    
    slow(5);
    system("cls");
}

/**
 * Main program entry point
 */
int main() {
    try {
        const int total = 5;
        worker W[total];
    
        
        while (true) {
            try {
                selection(display(), W);
            } catch (const exception &e) {
                cerr << "Error in menu selection: " << e.what() << endl;
                slow(3);
            }
        }
    } catch (const exception &e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
