class MyQueue {
public:
        stack<int> st;
        stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
    
        st.push(x);
       
    }
    
    int pop() {
        while(!st.empty()){
            int a=st.top();
            
            st2.push(a);
            st.pop();
        }
        

        int tops=st2.top();
        //cout<<tops<<endl;
        st2.pop();

        while(!st2.empty()){
            int b=st2.top();
            st.push(b);
            st2.pop();
        }

        return tops;
        //return 1;
    }
    
    int peek() {
       while(!st.empty()){
            int a=st.top();
            st2.push(a);
            st.pop();
        }

        int tops=st2.top();

        while(!st2.empty()){
            int b=st2.top();
            st.push(b);
            st2.pop();
        }

        return tops;
        //return 1;
    }
    
    bool empty() {
        if(st.empty()) return true;
        else return false;

        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
