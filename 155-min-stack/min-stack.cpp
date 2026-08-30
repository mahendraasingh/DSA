class MinStack {
public:
vector<int>x;
        map<int,int>ma;
        stack<int>s;
    MinStack() {
        
    }
    void push(int value) {
        if(s.empty())s.push(value);
        else{ if(value<s.top()){s.push(value);}
        else s.push(s.top());}
        x.push_back(value);
    }
    void pop() {
        if(x.empty()){
            cout<<"not possible";
        }
        else{
            s.pop();
           x.pop_back();
        }
    }
    
    int top() {

            return x.back(); 
    }
    
    int getMin() {
        
 return s.top();
    }
};

