class FreqStack {
public:

    //group is used to store elements having same freq. so if same freq then delete the most recently pushed

    unordered_map <int,int> freq;
    unordered_map <int, stack<int>> group;
    int maxF;

    FreqStack() {
        maxF = 0;
    }
    
    void push(int val) 
    {
        freq[val]++;
        group[freq[val]].push(val);
        maxF = max(maxF,freq[val]);
    }
    
    int pop() 
    {
       int ele = group[maxF].top();
       freq[ele]--;
       group[maxF].pop();

       if(group[maxF].empty()) maxF--;
       
       return ele; 
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

