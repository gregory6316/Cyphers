#include <iostream>
#include <fstream>
using namespace std;
int gcd(int a, int b);
int modInverse(int a, int b);
ifstream F;
int main(int argc, char* argv[]){
    string choice;
    string buf;
    char ch, ch1;
    F.open(argv[1]);
    if (F.fail()) {cerr << "Error opening file";}
    choice = "";
   //getline(F, choice);
    //if ((ch1 == '\r') && (ch == '\n')) infile.get(ch);
           while (1){
                F.get(ch);
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                choice += ch;
            }
            ch1 = ch;
    if (choice != "encrypt" && choice != "decrypt" && choice != "break" ) {cerr << "Comand is not correct" << endl;}
    if (choice == "break"){
        int m1, n1, m2, n2, k, m, n, a1, b1;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string balphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ciphertext, cipher;
        // getline (F, cipher);
        // getline(F, ciphertext);
        cipher = "";
        ciphertext = "";
        F.get(ch);
        if ((ch1 == '\r') && (ch == '\n')) F.get(ch);
           while (1){
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                cipher += ch;
                F.get(ch);

            }
            ch1 = ch;
        F.get(ch);
        if ((ch1 == '\r') && (ch == '\n')) F.get(ch);
            while (!F.eof()){
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                ciphertext += ch;
                //cout<<ch<<endl;
                F.get(ch);
            }
            ch1 = ch;

        m1 = -1;
        m2 = -1;
        n1 = -1;
        n2 = -1; 
        for ( k = 0; k <= 25; k++){
            if (cipher[0] == alphabet[k])
                m1 = k;
        }
        if (m1 == -1){
            for ( k = 0; k <= 25; k++){
            if (cipher[0] == balphabet[k])
                m1 = k;
            }
        }
        if (m1 == -1) {
            cerr << "Wrong input\n";
            return 0;
        }
        for ( k = 0; k <= 25; k++){
            if (cipher[1] == alphabet[k])
                m2 = k;
        }
        if (m2 == -1){
            for ( k = 0; k <= 25; k++){
            if (cipher[1] == balphabet[k])
                m2 = k;
            }
        }
        if (m2 == -1) {
            cerr << "Wrong input\n";
            return 0;
        };
        for ( k = 0; k <= 25; k++){
            if (cipher[3] == alphabet[k])
                n1 = k;
        }
        if (n1 == -1){
            for ( k = 0; k <= 25; k++){
            if (cipher[3] == balphabet[k])
                n1 = k;
            }
        }
        if (n1 == -1) {
            cerr << "Wrong input\n";
            return 0;
        };
        for ( k = 0; k <= 25; k++){
            if (cipher[4] == alphabet[k])
                n2 = k;
        }
        if (n2 == -1){
            for ( k = 0; k <= 25; k++){
            if (cipher[4] == balphabet[k])
                n2 = k;
            }
        }
        if (n2 == -1) {
            cerr << "Wrong input\n";
            return 0;
        };
        m = m1 - m2;
        n = n1 - n2;
        if (m < 0 ){
            m = m + 26;
        }
         if (n < 0 ){
            n = n + 26;
        }
        if ((n % m) != 0){
            k = 1;
            while ((m*k) % 26 != 1){
                k++;
            }
            a1 = (n * k) % 26;   
        }
        else {
            a1 = n / m; 
        }
        b1 = n2 -  (m2 * a1);
        while (b1 < 0) {
            b1 = b1 + 26;
        } 
        for(int i = 0; i < ciphertext.length(); ++i){
                if (!(ciphertext[i] >= 'a' && ciphertext[i] <= 'z') && !(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') && !(ciphertext[i] == ' ' ) && !(ciphertext[i] == '_' ) && !(ciphertext[i] == '!' ) && !(ciphertext[i] == '?' )){
                    cerr << "Wrong input\n";
                    return 0;
                }
            }
        for(int i = 0; i <  ciphertext.length(); ++i){
                if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z'){
                    cout << (char)(modInverse(a1, 26) * (26 + ciphertext[i] - 'a' - b1) % 26 + 'a');
                } else if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z'){
                    cout << (char)(modInverse(a1, 26) * (26 + ciphertext[i] - 'A' - b1) % 26 + 'A');
                } else{
                    cout << ciphertext[i];
                }
            }
            cout<<"\n"; 


    }
    if (choice == "encrypt" || choice == "decrypt"){
        string input, numinput;
        //getline(F, numinput);
        numinput="";
        F.get(ch);
        if ((ch1 == '\r') && (ch == '\n')) F.get(ch);
            while (1){
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                numinput += ch;
                //cout<<ch<<endl;
                F.get(ch);
            }
            ch1 = ch;
        int a=0, b=0, i=0, j=0, flag = 0;
        for ( i=0; i<=numinput.length(); i++){
            if ((numinput[i]<='9') && (numinput[i]>='0')) a=a*10+numinput[i]-'0';
            else if (numinput[i] == '-'){
                flag = 1;
            } 
            else  if (numinput[i] != ' ') {
                cerr << "Wrong input a\n";
                return 0;      
            }
         else break;
     }
     if (flag){
        a = -a;
        flag =0;
     }
        for (  j=i+1; j<numinput.length(); j++)
            if ((numinput[j]<='9') && (numinput[j]>='0')){b=b*10+numinput[j]-'0';}
            else if (numinput[j] == '-'){
                flag = 1;
            }  
            else  if (numinput[j] != ' ' ) {
                cerr << "Wrong input \n";
                return 0;       
            }
            
        if (a==0 || b==0){
            cerr << "Wrong input\n";
            return 0;
        }
        if (flag){
        b = -b;
        flag =0;
     }
     cout<<numinput<<endl;
        cout<<a<<" "<<b<<endl;
        if (gcd(a,26) != 1 && a!=1 && a!=-1){
            cerr << "a and 26 must be coprime\n";
            return 0; 
        }
        //getline(F, input);
        F.get(ch);
        if ((ch1 == '\r') && (ch == '\n')) F.get(ch);
            while (!F.eof()){
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                input += ch;
                //cout<<ch<<endl;
                F.get(ch);
            }
            ch1 = ch;
        if(choice == "encrypt"){
            for(int i = 0; i < input.length(); ++i){
                if (!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z') && !(input[i] == ' ') && !(input[i] == '_') && !(input[i] == '?') && !(input[i] == '!')){
                    cerr << "Wrong input\n";
                    return 0;
                }
            }
            for(int i = 0; i < input.length(); ++i){
                if(input[i] >= 'a' && input[i] <= 'z'){
                    if ((a * (input[i] - 'a') + b) % 26 < 0){
                       cout << (char)((a * (input[i] - 'a') + b) % 26 + 26 + 'a'); 
                    }
                    else{
                    cout << (char)((a * (input[i] - 'a') + b) % 26 + 'a');
                }
                } else if(input[i] >= 'A' && input[i] <= 'Z'){
                   if ((a * (input[i] - 'A') + b) % 26 < 0){
                       cout << (char)((a * (input[i] - 'A') + b) % 26 + 26 + 'A'); 
                    }
                    else{
                    cout << (char)((a * (input[i] - 'A') + b) % 26 + 'A');
                }
                } 
                else cout << input[i];
            }
        } else{
            for(int i = 0; i < input.length(); ++i){
                if (!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z') && !(input[i] == ' ' ) && !(input[i] == '_') && !(input[i] == '?') && !(input[i] == '!')){
                    cerr << "Wrong input\n";
                    return 0;
                }
            }
            for(int i = 0; i < input.length(); ++i){
                if(input[i] >= 'a' && input[i] <= 'z'){
                    if ((modInverse(a, 26) * (26 + input[i] - 'a' - b) % 26) < 0){
                        cout << (char)(modInverse(a, 26) * (26 + input[i] - 'a' - b) % 26 + 26 + 'a');
                    }
                    else{
                    cout << (char)(modInverse(a, 26) * (26 + input[i] - 'a' - b) % 26 + 'a');
                }
                } else if(input[i] >= 'A' && input[i] <= 'Z'){
                    if ((modInverse(a, 26) * (26 + input[i] - 'A' - b) % 26) < 0){
                        cout << (char)(modInverse(a, 26) * (26 + input[i] - 'A' - b) % 26 + 26 + 'A');
                    }
                    else{
                    cout << (char)(modInverse(a, 26) * (26 + input[i] - 'A' - b) % 26 + 'A');
                }
                } 
                else cout << input[i];
            }
        }
        cout << '\n';
        return 0;
    }
}

    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
    int modInverse(int a, int b){
        int c=0;
        while (((a*c) % b != 1 ) && ((a*c) % b != -1 )){
            c++;
        }
        return c;
    }