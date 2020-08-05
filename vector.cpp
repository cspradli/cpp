#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

const int ROW = 3;
const int COL = 2;

//print out all elements separated by spaces
template <class T>
void showAll(T& v){
        copy(v.begin(), v.end(), ostream_iterator<string>(cout," "));
        cout<<endl;
}

template <class T>
void insertMyWay(T& v, string s1, string s2){
        typename T::iterator pos;
        for(pos = v.begin(); pos != v.end(); pos++){
                if(*pos == s1) {
                        v.insert(pos, s2);
                        break;
                }
        }
}

void reverseChar(string& s){
        reverse(s.begin(), s.end());
}



int main(){
    
    const int SIZE = 7;
    vector<string> word;
    word.reserve(SIZE);

    word.push_back("a");
    word.push_back("man");
    word.push_back("plan");
    word.push_back("canal");
    word.push_back("Panama");

    showAll(word);
    insertMyWay(word, "plan", "a");
    showAll(word);

    vector<int> vec0;
    vector<int> vec1 (3); // 3 insts
    vector<int> vec2 (3, 10); //3 ints value of 10
    vector<int> vec3 (vec2.begin(), vec2.end()); // iterating via vec2
    vector<int> vec4 (vec3); //copy of vec3
    int myInt[] = {1,2,3}; // construct of arr
    vector<int> vec5 (myInt, myInt + sizeof(myInt) / sizeof(int));
    
    
    vector<string> Scientist;

    Scientist.push_back("James Maxwell");
    Scientist.push_back("Edwin Hubble");
    Scientist.push_back("Louis Pasteaur");

    cout<<"We have " << Scientist.size() << "scientists "<<endl;

    vector<string>::iterator iter;
    for(iter = Scientist.begin(); iter != Scientist.end(); ++iter){
            cout<<*iter<<endl;
    }
    
    cout<<Scientist.capacity()<<endl;    
    Scientist.reserve(20); //reserve memory for 20 additional elements
    cout<<Scientist.capacity()<<endl;    
    
    vector<vector<int>> v2D(ROW, vector<int>(COL, 99));
    for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                    cout << v2D[i][j] << " ";
            }
            cout<<endl;
    }
    return 0;
}
