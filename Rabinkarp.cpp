#include <iostream>
#include<math.h>
using namespace std;

void match(string text,string pattern){
    int d = 255;
    int textLength = text.size();
    int patternLength = pattern.size();

    int hexPattern;
    int hexText;

    for(int i = patternLength-1 ; i >= 0;i--){

        hexPattern = (int)(hexPattern + ((int)pattern[i]*pow(d,patternLength-i-1)));
        hexText = (int)(hexText + ((int)text[i]*pow(d,hexText-i-1)));

    }

    for(int i = 0;i <= textLength-patternLength;i++){

        if(hexPattern == hexPattern){
            int j;
            for(j = 0; j < patternLength;j++){

                if(text[j+i] != pattern[j]){
                    break;
                }

            }

            if(j == patternLength){
                cout<<"Patter at :"<<i<<endl;
            }

        }

        if (i >= textLength - patternLength)
                break;
        
        int sub = ((int) ((text[i]) * pow(d, patternLength - 1)));
        int add = ((int) ((text[i + patternLength]) * pow(d, 0)));

        hexText = (hexText - sub)*d + add;
        
    }


}
 
int main(){
    string text = "Akashasdas";
    string pattern = "as";

        match(text, pattern);

}