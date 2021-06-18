#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]){
    string math, eng, choice, alphabet_key, text;
    ifstream F;
    char ch, ch1;
    int alph, key, k;
    int* result, *shiftedresult;
    F.open(argv[1]);
    math = "0123456789+-=*/() .,!<>[]";
    eng = "abcdefghiklmnopqrstuvwxyz";
    //beng = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    if (F.fail()) {
        cerr << "Error opening file";
        return 0;
    }
    //getline(F, choice);
    choice = "";
    while (1){
                F.get(ch);
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                choice += ch;
            }
            ch1 = ch;
    if (choice != "encrypt" && choice != "decrypt") {
        cerr << "Comand is not correct" << endl;
        return 0;
    }
    //getline(F, alphabet_key);
    alphabet_key="";
    F.get(ch);
        if ((ch1 == '\r') && (ch == '\n')) F.get(ch);
            while (1){
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                alphabet_key += ch;
                //cout<<ch<<endl;
                F.get(ch);
            }
            ch1 = ch;
    if (alphabet_key[0]== 'e' && alphabet_key[1]== 'n' && alphabet_key[2]== 'g' && alphabet_key[3]== 'l' && alphabet_key[4]== 'i' && alphabet_key[5]== 's' && alphabet_key[6]== 'h' && alphabet_key[7]== ' '){
        alph = 1;
        k = 8;
    }
    else if (alphabet_key[0]== 'm' && alphabet_key[1]== 'a' && alphabet_key[2]== 't' && alphabet_key[3]== 'h' && alphabet_key[4]== ' ' ){
        alph = 2;
        k = 5;
    }

    else {
        cerr << "Wrong input1" << endl;
        return 0;
    }
    key = 0;

    for ( int i=k; i<alphabet_key.length(); i++){
            while ((alphabet_key[i]<='9') && (alphabet_key[i]>='0')) {
                key=key*10+alphabet_key[i]-'0';
                i++;
            } 
            if ((i+1) == alphabet_key.length() && !((alphabet_key[i]<='9') && (alphabet_key[i]>='0'))) {
                cerr << "Wrong input1\n";
                return 0;      
            }
            else break;
    }
    if (key % 2 == 0){
        cerr << "Key must be odd number!\n";
                return 0;      
    }
    //getline(F, text);
    text = "";
    F.get(ch);
        if ((ch1 == '\r') && (ch == '\n')) F.get(ch);
            while (!F.eof()){
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                text += ch;
                //cout<<ch<<endl;
                F.get(ch);
            }
            ch1 = ch;
    result = new int [2*text.length()];
    shiftedresult = new int [2*text.length()];
    if (choice == "encrypt" ){
        if (alph==1){
            for (int i = 0; i < text.length() ; i++){
                k = -1;
                for ( int j = 0; j<= 24; j++){
                    if (text[i] == eng[j]){
                        k = j;
                        result[2*i] = (k-k % 5)/5 + 1;
                        result[2*i+1] = k % 5 + 1;
                        
                    }
                }
                if (k == -1 && text[i]!='j'){
                cerr<<"wrong input\n";
                return 0;
                }
                if (text[i] == 'j'){
                    result[2*i] = (8-8 %5)/5+1;
                    result[2*i+1]= 8%5+1;

                }
            

            }
            // for  (int i=0; i<2*text.length();i++){
            //     cout<<result[i]<<' ';
            // }
        }
        else {
            for (int i = 0; i < text.length() ; i++){
                k =-1;
                for ( int j = 0; j<= 24; j++){
                    if (text[i] == math[j]){
                        k = j;
                        result[2*i] = (k-k % 5)/5 + 1;
                        result[2*i+1] = k % 5 + 1;
                    }
                }
                if (k == -1){
                cerr<<"wrong input\n";
                return 0;
            }

            }
        }
        for (int i = 0; i<2*text.length(); i++){
            //cout<<result[i];
            shiftedresult[i] = result[(i+key)%(2*text.length())];
            //cout<<shiftedresult[i];
        }
        for (int i = 0; i<text.length(); i++){
            if (alph == 1){
                cout << eng[(shiftedresult[2*i]-1)*5+(shiftedresult[2*i+1]-1)];
            }
            else{
                cout<< math[(shiftedresult[2*i]-1)*5+(shiftedresult[2*i+1]-1)];
            }
        }
        delete [] result;
        delete [] shiftedresult;
    }
    else{
        if (alph==1){
            for (int i = 0; i < text.length() ; i++){
                k = -1;
                for ( int j = 0; j< 24; j++){
                    if (text[i] == eng[j]){
                        k = j;
                        result[2*i] = (k-k % 5)/5 + 1;
                        result[2*i+1] = k % 5 + 1;
                    }
                }

            if (k == -1 && text[i] !='j'){
                cerr<<"wrong input\n";
                return 0;
            }
            if (text[i] == 'j'){
                    result[2*i] = (8-8 %5)/5+1;
                    result[2*i+1]= 8%5+1;

                }

            }
        }
        else {
            for (int i = 0; i < text.length() ; i++){
                k = -1;
                for ( int j = 0; j<= 24; j++){
                    if (text[i] == math[j]){
                        k = j;
                        result[2*i] = (k-k % 5)/5 + 1;
                        result[2*i+1] = k % 5 + 1;
                    }
                }
                if (k == -1){
                cerr<<"wrong input\n";
                return 0;
            }
            

            }
        }
        for (int i = 0; i<2*text.length(); i++){
            shiftedresult[i] = result[((i+(2*text.length()-key))%(2*text.length()))];
            
        }
        for (int i = 0; i<text.length(); i++){
            if (alph == 1){
                cout << eng[(shiftedresult[2*i]-1)*5+(shiftedresult[2*i+1]-1)];
            }
            else{
                cout<< math[(shiftedresult[2*i]-1)*5+(shiftedresult[2*i+1]-1)];
            }
        }
        cout<<endl;
        delete [] result;
        delete [] shiftedresult;
    }
    cout<<endl;
}