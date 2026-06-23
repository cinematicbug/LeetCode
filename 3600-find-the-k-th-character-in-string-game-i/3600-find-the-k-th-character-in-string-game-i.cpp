class Solution {
public:
    int kthCharacter(int k) {
    if (k == 1) {
        return 'a';
    }
    
    int hl = 1;
    while (hl * 2 < k) {
        hl *= 2;
    }
    
    return kthCharacter(k - hl) + 1;
}
};