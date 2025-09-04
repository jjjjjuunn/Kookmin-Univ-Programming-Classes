/* 과제 원본
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ArrayData{
    int output[5] = { 0, };
public:
    ArrayData(int input[5]);
    void AscendingOrderFunction();
    void DescendingOrderFunction();
    friend void MaxMinFunction(ArrayData P);   
    ArrayData operator +(ArrayData Q);          
    int* getArray();                        // 추가 구현
    void ShowArray() const;                 // 추가 구현
};

ArrayData :: ArrayData(int input[5]) {
    for(int i = 0 ; i<5 ; i++){
        this->output[i] = input[i];
    }
}

void ArrayData :: AscendingOrderFunction(){
    
    cout << "ascending" << endl;

    vector<int> int_v;
    for(int i = 0 ; i<5 ; i++){
        int_v.push_back(this->output[i]);
    }
    sort(int_v.begin(),int_v.end());

    for(auto it = int_v.begin() ; it!= int_v.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;

    for(int i = 0 ; i<5 ; i++){
        output[i] = int_v.at(i);
    }
}

void ArrayData :: DescendingOrderFunction(){
    
    cout << "descending" << endl;
    vector<int> int_v;
    for(int i = 0 ; i<5 ; i++){
        int_v.push_back(this->output[i]);
    }
    sort(int_v.begin(),int_v.end(),greater<int>());

    for(auto it = int_v.begin() ; it!= int_v.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
        for(int i = 0 ; i<5 ; i++){
        output[i] = int_v.at(i);
    }
}

void MaxMinFunction(ArrayData P){
    cout << "MaxMin" << endl;
    int max = P.output[0], min = P.output[0];
    for(int i =1 ; i<5 ; i++){
        if(max < P.output[i]) max = P.output[i];
    }
    for(int i =1 ; i<5 ; i++){
        if(min > P.output[i]) min = P.output[i];
    }
    cout << "Max value is " << max << endl;
    cout << "Min value is " << min << endl;
}

ArrayData ArrayData :: operator +(ArrayData Q){
    int resArray[5];
    cout << "operator+" << endl;
    for(int i = 0 ; i<5 ; i++){
        resArray[i]= this->output[i] + Q.output[i];
    }
    return ArrayData(resArray);
}

int* ArrayData :: getArray() {
    return output;
}

void ArrayData :: ShowArray()const {
    for(int i = 0 ; i < 5 ; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "[[ 2nd Coding Assignment ]]" << endl;
    cout << "Write the five integer between 0 and 100: ";

    int int_array[5] = {};

    for(int i = 0 ; i<5 ; i++){
        cin >> int_array[i];
    }

    for(int i = 0 ; i<5 ; i++){
        if(int_array[i]<0 or int_array[i] > 100){
            cout << "Input is incorrect. So, this program is over ." << endl;
            exit(0);
        }
        for(int j = i+1 ; j<5 ; j++){
            if(int_array[i] == int_array[j]){
                cout << "Input is incorrect. So, this program is over ." << endl;
                exit(0);
            }
        }
    }

    for(int i = 0 ; i<5 ; i++){
        cout << int_array[i] << ' ';
    }
    cout << endl;

    ArrayData myArray(int_array);
    
    string choose_mode;
    cout << "Please select the mode(ascending or descending or maxmin or operator+): ";
    cin >> choose_mode;

    if(choose_mode == "ascending"){
        myArray.AscendingOrderFunction();
    }

    else if(choose_mode == "descending"){
        myArray.DescendingOrderFunction();
    }

    else if(choose_mode == "maxmin"){
        MaxMinFunction(myArray);
    }
    else if(choose_mode == "operator+"){

        myArray.AscendingOrderFunction();
        ArrayData tmpArray1(myArray.getArray());

        myArray.DescendingOrderFunction();
        ArrayData tmpArray2(myArray.getArray());
        
        ArrayData resArray(tmpArray1+tmpArray2);
        resArray.ShowArray();
    }
    else{
        cout << "Mode is incorrect. So, this program is over" << endl;
        exit(0);
    }
    return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ArrayData{
    int output[5] = { 0, };
public:
    ArrayData(int input[5]);
    void AscendingOrderFunction();
    void DescendingOrderFunction();
    friend void MaxMinFunction(ArrayData P);   
    friend ArrayData operator +(ArrayData R, ArrayData Q);      // 외부 함수로 구현해보기   
    int* getArray();                        // 추가 구현
    void ShowArray() const;                 // 추가 구현
};

ArrayData :: ArrayData(int input[5]) {
    for(int i = 0 ; i<5 ; i++){
        this->output[i] = input[i];
    }
}

void ArrayData :: AscendingOrderFunction(){
    
    cout << "ascending" << endl;

    vector<int> int_v;
    for(int i = 0 ; i<5 ; i++){
        int_v.push_back(this->output[i]);
    }
    sort(int_v.begin(),int_v.end());

    for(auto it = int_v.begin() ; it!= int_v.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;

    for(int i = 0 ; i<5 ; i++){
        output[i] = int_v.at(i);
    }
}

void ArrayData :: DescendingOrderFunction(){
    
    cout << "descending" << endl;
    vector<int> int_v;
    for(int i = 0 ; i<5 ; i++){
        int_v.push_back(this->output[i]);
    }
    sort(int_v.begin(),int_v.end(),greater<int>());

    for(auto it = int_v.begin() ; it!= int_v.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
        for(int i = 0 ; i<5 ; i++){
        output[i] = int_v.at(i);
    }
}

void MaxMinFunction(ArrayData P){
    cout << "MaxMin" << endl;
    int max = P.output[0], min = P.output[0];
    for(int i =1 ; i<5 ; i++){
        if(max < P.output[i]) max = P.output[i];
    }
    for(int i =1 ; i<5 ; i++){
        if(min > P.output[i]) min = P.output[i];
    }
    cout << "Max value is " << max << endl;
    cout << "Min value is " << min << endl;
}

ArrayData operator +(ArrayData R, ArrayData Q){
    int resArray[5];
    cout << "operator+" << endl;
    for(int i = 0 ; i<5 ; i++){
        resArray[i]= R.output[i] + Q.output[i];
    }
    return ArrayData(resArray);
}

int* ArrayData :: getArray() {
    return output;
}

void ArrayData :: ShowArray() const {
    for(int i = 0 ; i < 5 ; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "[[ 2nd Coding Assignment ]]" << endl;
    cout << "Write the five integer between 0 and 100: ";

    int int_array[5] = {};

    for(int i = 0 ; i<5 ; i++){
        cin >> int_array[i];
    }

    for(int i = 0 ; i<5 ; i++){
        if(int_array[i]<0 or int_array[i] > 100){
            cout << "Input is incorrect. So, this program is over ." << endl;
            exit(0);
        }
        for(int j = i+1 ; j<5 ; j++){
            if(int_array[i] == int_array[j]){
                cout << "Input is incorrect. So, this program is over ." << endl;
                exit(0);
            }
        }
    }

    for(int i = 0 ; i<5 ; i++){
        cout << int_array[i] << ' ';
    }
    cout << endl;

    ArrayData myArray(int_array);
    
    string choose_mode;
    cout << "Please select the mode(ascending or descending or maxmin or operator+): ";
    cin >> choose_mode;

    if(choose_mode == "ascending"){
        myArray.AscendingOrderFunction();
    }

    else if(choose_mode == "descending"){
        myArray.DescendingOrderFunction();
    }

    else if(choose_mode == "maxmin"){
        MaxMinFunction(myArray);
    }
    else if(choose_mode == "operator+"){

        myArray.AscendingOrderFunction();
        ArrayData tmpArray1(myArray.getArray());

        myArray.DescendingOrderFunction();
        ArrayData tmpArray2(myArray.getArray());
        
        ArrayData resArray(tmpArray1+tmpArray2);
        resArray.ShowArray();
    }
    else{
        cout << "Mode is incorrect. So, this program is over" << endl;
        exit(0);
    }
    return 0;
}