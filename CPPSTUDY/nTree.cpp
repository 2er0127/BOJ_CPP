// N-항 트리를 이용한 파일 시스템 자료 구조

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct n_ary_node{
    string name;
    bool is_dir;
    vector<n_ary_node*> children;
};

struct file_system {
    using node=n_ary_node;
    using node_ptr=node*;
    
private:
    node_ptr root;
    node_ptr cwd;
    
public:
    file_system() {
        root=new node {"/", true, {}};
        cwd=root;
    }
    
    node_ptr find(const string& path) {
        if(path[0]=='/') { // 절대 경로
            return find_impl(root, path.substr(1));
        }
        else { // 상대 경로
            return find_impl(cwd, path);
        }
    }
    
private:
    node_ptr find_impl(node_ptr directory, const string& path) {
        if(path.empty())
            return directory;
        auto sep=path.find('/');
        string current_path=sep==string::npos ? path:path.substr(0, sep);
        string rest_path=sep==string::npos ? "":path.substr(sep+1);
        auto found=find_if(directory->children.begin(), directory->children.end(), [&](const node_ptr child) {
            return child->name==current_path;
        });
        if(found!=directory->children.end()) {
            return find_impl(*found, rest_path);
        }
        return NULL;
    }
    
public:
    bool add(const string& path, bool is_dir) {
        if(path[0]=='/') {
            return add_impl(root, path.substr(1), is_dir);
        }
        else {
            return add_impl(cwd, path, is_dir);
        }
    }
    
private:
    bool add_impl(node_ptr directory, const string& path, bool is_dir) {
        if(not directory->is_dir) {
            cout<<directory->name<<"은(는) 파일입니다."<<endl;
            return false;
        }
        
        auto sep=path.find('/');
        
        // path에 '/'가 없는 경우.
        if(sep==string::npos) {
            auto found=find_if(directory->children.begin(), directory->children.end(), [&](const node_ptr child) {
                return child->name==path;
            });
            
            if(found!=directory->children.end()) {
                cout<<directory->name<<"에 이미 "<<path<<" 이름의 파일/디렉토리가 있습니다."<<endl;
                return false;
            }
            
            directory->children.push_back(new node {path, is_dir, {}});
            return true;
        }
        
        // path에 '/'가 있는 경우.
        string next_dir=path.substr(0, sep);
        auto found=find_if(directory->children.begin(), directory->children.end(), [&](const node_ptr child) {
            return child->name==next_dir&&child->is_dir;
        });
        
        if(found!=directory->children.end()) {
            return add_impl(*found, path.substr(sep+1), is_dir);
        }
        
        // 해당 디렉토리가 없는 경우.
        cout<<directory->name<<"에 "<<next_dir<<" 이름의 디렉토리가 없습니다."<<endl;
        return false;
    }
    
public:
    bool change_dir(const string& path) {
        auto found=find(path);
    }
}

