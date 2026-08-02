class MinStack {
public:
 stack<long long>st;
 long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        }
        else {

            if (val >= mini) {
                st.push(val);
            }
            else {

                // Store encoded value
                st.push(2LL * val - mini);

                // Update minimum
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty())
            return;

        long long curr = st.top();
        st.pop();

        if (curr < mini) {

            // Recover previous minimum
            mini = 2LL * mini - curr;
        }
    }
    
    int top() {

        if (st.empty())
            return -1;

        long long curr = st.top();

        if (curr >= mini)
            return curr;

        return mini;
    }
    
    int getMin() {
        if (st.empty())
            return -1;

        return mini;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */