struct Node {
    Node* links[26];
    bool f = false;
    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    ~Node() {
        for(int i = 0; i < 26; i++) {
            if(links[i] != NULL) {
                delete links[i];
            }
        }
    }
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    void setEnd(){
        f = true;
    }
    bool isEnd(){
        return f;
    }
};
class Trie{
private: Node* root;
public:
    Trie(){
        root = new Node();
    }
    ~Trie() {
        delete root;
    }
    void insert(string& word){
        Node* node = root;
        int n = word.length();
        for(int j =n-1; j >= 0; j--){
            if(!node->containsKey(word[j])){
                node->put(word[j],new Node());
            }
            node = node->get(word[j]);
        }
        node->setEnd();
    }

    bool search(string& word){
        Node* node = root;
        int n = word.length();
        for(int i = n-1; i>=0; i--){
            if(!node->containsKey(word[i])){
                return node->isEnd();
            }
            if(node->isEnd()) return true;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
};

class StreamChecker {
private:
    Trie t;
    string s = "";
public:
    StreamChecker(vector<string>& words) {
        for(auto& x : words){
            t.insert(x);
        }
    }
    
    bool query(char letter) {
        s += letter;
        return t.search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */