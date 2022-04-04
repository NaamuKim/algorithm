#include <iostream>
#include <map>

using namespace std;    
int main(){
    map<string,int> _map;
    _map["손가락"]=10;
    _map["발가락"]=10;
    for(auto c : _map){
        cout << c.first << " : " << c.second << "\n";
    }

    return 0;
}
