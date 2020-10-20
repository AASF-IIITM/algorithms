bool ispossible(int A, vector<int> &C, int mid) {
    int n = C.size(), painter = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += C[i];
        if(sum > mid) {
            painter++;
            sum = C[i];
            if(sum > mid || painter > A)
                return false;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int high = 0, low = 0, mid;
    int n = C.size();
    for(int i = 0; i < n; i++)
        high = (high + (1LL * C[i]) % 10000003) % 10000003;
    int ans = high;
    while(low <= high) {
        mid = (low + high) / 2;
        if(ispossible(A, C, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return int((ans * 1LL * B)%10000003);
}
