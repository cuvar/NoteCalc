#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

using namespace std;

//Split
//Splits a string by a token & returns an vector of substrings
vector<string> split(string str, char token){

    vector<string> newStrs;     //gets all separated strings
    int n = 0;                  //depicts the new string's beginning


    for(unsigned int i = 0; i < str.length(); i++){

        if(str[i] == token){

            newStrs.push_back(str.substr(n, i - n));
            n = i + 1;
        }
    }

    newStrs.push_back(str.substr(n, str.length() - n));

    return newStrs;
}



//StrToIntArr
//Converts a string of ints into an int array
int* strToIntArr(string str){
	int* arr = new int[str.length()];
	int k = 0;

	for(unsigned int i = 0; i < str.length(); i++){
		if(str[i] == '0'){
			arr[k] = 0;
		} else if(str[i] == '1'){
			arr[k] = 1;
		} else if(str[i] == '2'){
			arr[k] = 2;
		} else if(str[i] == '3'){
			arr[k] = 3;
		} else if(str[i] == '4'){
			arr[k] = 4;
		} else if(str[i] == '5'){
			arr[k] = 5;
		} else if(str[i] == '6'){
			arr[k] = 6;
		} else if(str[i] == '7'){
			arr[k] = 7;
		} else if(str[i] == '8'){
			arr[k] = 8;
		} else if(str[i] == '9'){
			arr[k] = 9;
		} else {
			k -= 1;
		}
		k++;
	}

	return arr;
}



//containsOnly
// proofes whether string contains only token or not
int containsOnly(string s, char token){
	int a = 0;

	for (char c : s){
		if(c == token){
			a = 1;
		}
		else {
			a = 0;
		}

		if(a == 0){
			return 0;
		}
	}

	return 1;
}

#endif // HELPER_H_INCLUDED
