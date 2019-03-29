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
    for (const auto & entry : fs::directory_iterator("./")){
        string filename=replace(entry.path(),"./","");
        if(!is_number(string(1,filename[0]))){
            continue;
        }
        for (const auto & image : fs::directory_iterator(entry.path())){
            vector<string> splitName=split(image.path().string(),".");
            if(splitName.size()>1){
                string newName=splitName[splitName.size()-2];
                system(("convert "+image.path().string()+" -define bmp:compression-level=0 -type truecolor ."+newName+".bmp;rm "+image.path().string()+";").c_str());
//                cout << newName << endl;
            }
//            
        }
    }
    return 0;
}