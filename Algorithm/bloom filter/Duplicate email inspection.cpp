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
    
    //OpenSSL 라이브러리의 MD5 알고리즘을 사용하여 주어진 이메일 주소로부터 해시 값 생성.
    //MD5:128bits(16bytes) 해싱 알고리즘. 각 바이트를 해시 값으로 사용하여 해시 함수를 대체할 수 있다.
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
    
    bool mayContain(const string* key) {
        hash(key);
        for(auto it=&hashValue[0]; it<&hashValue[nHashes]; it++) {
            if(!bits[*it%bits.size()]) {
                cout<<key<<" : 사용할 수 있는 이메일입니다."<<endl;
                return false;
            }
        }
        
        cout<<key<<" : 이미 사용 중입니다."<<endl;
        return true;
    }
};

int main() {
    BloomFilter bloom(128, 5);
    
    bloom.add("abc@googoo.com");
    bloom.add("xyz@googoo.com");
    
    bloom.mayContain("abc");
    bloom.mayContain("xyz@googoo.com");
    bloom.mayContain("xyz");
    
    bloom.add("abcd@googoo.com");
    bloom.add("zzzz@googoo.com");
    
    bloom.mayContain("abcd");
    bloom.mayContain("zzzz@googoo.com");
}
