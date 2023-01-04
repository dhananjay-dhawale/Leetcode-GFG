class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map <int,int> ump;
        for(auto i:tasks){
            ump[i]++;
        }
        int c = 0;
        for(auto i:ump){
            if(i.second == 1)
                return -1;
            if((i.second)%3 == 0){
                c += (i.second)/3;
            }
            else if((i.second)%3 == 1){
                c += ((i.second)-4)/3 + 2;
            }
            else{
                c += ((i.second)-2)/3 + 1;
            }
        }
        return c;
    }
};