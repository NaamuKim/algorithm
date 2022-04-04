#include <iostream>
#include <unordered_map>

using namespace std;

int v[10];

int main(){
    unordered_map<string, int> umap;

    umap.insert({"test1", 1});

    umap.emplace("test5", 5);

    umap["test1"]=4;

    for(auto item : umap){
        cout << item.first << "::" << item.second << "\n";
    }

    auto search = umap.find("test5");
    //find 메소드는 못 찾으면 end() 이터레이터를 반환함
    if(search != umap.end()){
        cout << "found :" << search -> first << " " << (*search).second << "\n";
    } else {
        cout << "not found..." <<"\n";
    }

    umap["test1"]++;
    cout << umap["test1"] << "\n";

    cout << umap.size() << "\n";
    umap.erase("test1");
    cout << umap.size() << "\n";

    return 0;
}