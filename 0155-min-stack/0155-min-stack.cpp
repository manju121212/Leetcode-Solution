class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }

    void push(int value) {
        long long val = value;

        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if (val <= mini) {
                long long encrypted = 2 * val - mini;
                st.push(encrypted);
                mini = val;
            }
            else {
                st.push(val);
            }
        }
    }

    void pop() {
        long long x = st.top();

        if (x < mini) {
            mini = 2 * mini - x;
        }

        st.pop();
    }

    int top() {
        long long x = st.top();

        if (x < mini) {
            return (int)mini;
        }

        return (int)x;
    }

    int getMin() {
        return (int)mini;
    }
};