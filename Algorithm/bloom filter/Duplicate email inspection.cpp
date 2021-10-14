#include <iostream>
#include <vector>
#include <openssl/md5.h>

using namespace std;

class BloomFilter {
    int nHashes;
    vector<bool> bits;
    
    //128bits(16bytes)
    static constexpr int hashSize=128/8;
    
    unsigned char hashValue[hashSize];
    
public:
    BloomFilter(int size, int hashes):bits(size), nHashes(hashes) {
        if(nHashes>hashSize) {
            throw("해시 함수 개수가 너무 많습니다.");
        }
        
        if(size>255) {
            throw("블룸 필터 크기가 255보다 클 수 없습니다.");
        }
    }
    
    void hash(const string& key) {
        MD5(reinterpret_cast<const unsigned char*>(key.data()), key.length(), hashValue);
    }
    
    void add(const string& key) {
        hash(key);
        for(auto it=&hashValue[0]; it<&hashValue[nHashes]; it++) {
            bits[*it%bits.size()]=true;
        }
        
        cout<<"블룸 필터에 추가: "<<key<<endl;
    }
    
}
