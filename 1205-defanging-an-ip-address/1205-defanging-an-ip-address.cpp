class Solution {
public:
    string defangIPaddr(string address) {
       string new_s = "";

       for (char i : address)
       {
            if (i == '.')
            {
                new_s += "[.]";
            }
            else
            {
                new_s += i;
            }
       }
       return new_s;
    }
};