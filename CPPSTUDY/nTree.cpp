// N-항 트리를 이용한 파일 시스템 자료 구조

#include <iostream>

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
}

