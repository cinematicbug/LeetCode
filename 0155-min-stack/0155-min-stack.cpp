class MinStack {
public:
    vector<int> aux_stack;
    vector<int> st;
    int min;

    MinStack() { min = INT_MAX; }

    void push(int value) {
        st.push_back(value);
        if (aux_stack.empty()) {
            aux_stack.push_back(value);
        } else {
            aux_stack.push_back(std::min(value, aux_stack.back()));
        }
    }

    void pop() {
        aux_stack.pop_back();
        st.pop_back();
    }

    int top() { return st.back(); }

    int getMin() { return aux_stack.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */