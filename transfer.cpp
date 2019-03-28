#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <cmath>
#include <thread>
namespace fs = std::experimental::filesystem;
using namespace std;

std::string replace(std::string base, const std::string from, const std::string to){
    std::string SecureCopy = base;
    for (size_t start_pos = SecureCopy.find(from); start_pos != std::string::npos; start_pos = SecureCopy.find(from, start_pos)){
        SecureCopy.replace(start_pos, from.length(), to);
    }
    return SecureCopy;
}

bool is_number(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

vector<string> split(string str, string character){
    vector<string> result;
    long long s=0;
    long long i=0;
    while(i<str.length()){
        if(str[i]==character[0]||i==str.length()-1){
            long long x=i-s;
            if(i==str.length()-1){
                x++;
            }
            result.push_back(str.substr(s,x));
            s=i+1;
        }
        i++;
    }
    return result;
}

int main(){
    string path = "./";
    vector<int> counts=vector<int>(10);
    for(int i=0;i<10;i++){
        fs::create_directory(to_string(i));
    }
    for (const auto & entry : fs::directory_iterator(path)){
        string filename=replace(entry.path(),"./","");
        if(string(1,filename[0])!="D"){
            continue;
        }
        for (const auto & category : fs::directory_iterator(entry.path())){
            string currentPath=category.path();
            if(is_number(string(1,currentPath[currentPath.size()-1]))){
//                cout << currentPath << endl;
                int number=stoi(string(1,currentPath[currentPath.size()-1]));
                for (const auto & src : fs::directory_iterator(currentPath)){
                    string image=src.path();
                    vector<string> splitPath=split(image,"/");
                    image=splitPath[splitPath.size()-1];
                    int id=stoi(splitPath[splitPath.size()-2]);
                    vector<string> parsed=split(image,".");
                    if(parsed[1]=="png"){
//                        cout << number << ": " << image << endl;
//                        cout << "./"+to_string(number)+"/"+image << endl;
                        rename(src.path().c_str(),("./"+to_string(number)+"/"+to_string(counts[id]++)+".png").c_str());
                    }
                }
            }
        }
    }
    return 0;
}