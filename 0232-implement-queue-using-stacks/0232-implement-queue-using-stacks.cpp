class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}

    void push(int x) { st1.push(x); }

    int pop() {
        int st_s = st1.size();
        for (int i = 0; i < st_s; i++) {
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }

        int y = st2.top();
        st2.pop();

        int st_s2 = st2.size();
        for (int i = 0; i < st_s2; i++) {
            int a = st2.top();
            st2.pop();
            st1.push(a);
        }

        return y;
    }

    int peek() {
        int st_s = st1.size();
        for (int i = 0; i < st_s; i++) {
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }

        int y = st2.top();

        int st_s2 = st2.size();
        for (int i = 0; i < st_s2; i++) {
            int x = st2.top();
            st2.pop();
            st1.push(x);
        }
        return y;
    }

    bool empty() { return st1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */