#include <iostream>
#include <cctype>

using namespace std;

int main (int argc, char*argv[]) {
    if (argc != 2){
        cout<< "Incorrect amount of command line arguments." ;
    }
    
    int num;
    num = atoi(argv[1]);

    string userStr;
    getline(cin, userStr);
    int len = userStr.size();
    string newStr = userStr;


    for (int i = 0; i < len; i++) {
        if (isalpha(userStr[i])) {
            if (isupper(userStr[i])) {
               newStr[i] = tolower(userStr[i]);
                if ((i+num)<len) {
                    newStr[i+num] = toupper(userStr[i+num]);
                } else {
                    newStr[(i+num)%len] = toupper(userStr[(i+num)%len]);
                }
            } 
        }
    }

    cout << newStr<< endl;



    return 0;
}