#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]){
	string choice, key, text;
	int k, b = 0, bcount = 0, bmax = 0, z=0;
	int *keys;
    char ch, ch1;
	ifstream F;
	F.open(argv[1]);
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
    //getline(F, key);

    key="";
    F.get(ch);
        if ((ch1 == '\r') && (ch == '\n')) F.get(ch);
            while (1){
                if ((ch == '\n') || (ch == '\r') || (ch == '\0')) { break; }
                key += ch;
                //cout<<ch<<endl;
                F.get(ch);
            }
            ch1 = ch;
    for (int i = 0; i<key.length(); i++){
    	while (key[i]<='9' && key[i]>='0'){
    		b=b*10 + key[i] -'0';
            i++;
    	}
    	if (b > bmax){
    		bmax = b;
    	}
    	if (key[i]!=',' && key[i]!=' '&& !(key[i]<='9' && key[i]>='0')&& i<key.length()){
    		cerr<<"Wrong input"<<endl;
    		return 0;
    	}
        if (key[i]==',' && !(key[i-1]<='9' && key[i-1]>='0')){
            cerr<<"Wrong input"<<endl;
            return 0;
        }
        if (!(key[i]<='9' && key[i]>='0')&& i==0){
            cerr<<"Wrong input"<<endl;
            return 0;
        }

        if ( key[i]==',' && (key[i+1]!=' ' && !(key[i+1]<='9' && key[i+1]>='0')) &&  (i+1<=key.length())){
            cerr<<"Wrong input"<<endl;
            return 0;
        }
    	if ( key[i]==','){
    		b = 0;
    	}
    }
    keys = new int[bmax];
    k = 0;
    b=0;
    for (int i=0; i<bmax; i++){
    	keys[i]=-1;
    }
    for (int i = 0; i<key.length(); i++){
    	while (key[i]<='9' && key[i]>='0'){
    		b=b*10 + key[i] -'0';
            if( i+1 == key.length()){
                break;
            }
            else{
            i++;
        }
    	}
    	if ( (key[i]==',')||(i+1 == key.length())){  		
    		keys[k]=b;
    		k++;
            bcount++;
			b=0;
    	}
    }
    if (bcount != bmax){
        cerr<<"Wrong input"<<endl;
            return 0;
    }
    for (int i = 0; i < bmax ; i++){
    	if (keys[i]==-1){
    		cerr<<"Wrong input"<<endl;
    		return 0;
    	}
    }
    // getline(F, text);
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
    
    if (choice == "encrypt"){
    	for (int i = 0; i<bmax;i++){
    		for (int j =0; j<bmax; j++){
    			if (keys[j]==i+1){
    				b=j;
    			}
    		}
    		k =bmax;
    		if (b<=text.length()){
    			cout<<text[b];
    			while(b+k<=text.length()){;
    				cout<<text[b+k];
    				k=k+bmax;
    			}
    		}
    	}
    }
    else {
        k = text.length() / bmax;
        if (text.length()%bmax > 0){
            k++;
        }
        for(int j =0; j<k;j++){
    	for(int i=0; i< bmax ; i++){
            cout<<text[(keys[i]-1) * k+j];
        }
    }


    }
    cout<<endl;
    delete[] keys;
}
