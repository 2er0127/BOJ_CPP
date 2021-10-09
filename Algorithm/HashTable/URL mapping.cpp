#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct URLService {
    using ActualURL=string;
    using TinyURL=string;
    
private:
    unordered_map<TinyURL, ActualURL> data;
    
public:
    pair<bool, ActualURL> lookup(const TinyURL& url) const {
        auto it=data.find(url);
        if(it==data.end()) {
            return make_pair(false, string());
        }
        else {
            return make_pair(true, it->second);
        }
    }
    
}
