class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector <string> res;
        for(int i=1; i<=3; i++){
            for(int j=1; j<=3; j++){
                for(int k=1; k<=3; k++){
                    int l = n-i-j-k;
                    if(l>=1 && l<=3){
                        int a = stoi(s.substr(0, i));
                        int b = stoi(s.substr(i, j));
                        int c = stoi(s.substr(i+j, k));
                        int d = stoi(s.substr(i+j+k, l));
                        //cout << a << "  " << b << " " << c << " " << d << "\n";
                        string str = "";
                        if(a>=0 && a<=255 && b>=0 && b<=255 && c>=0 && c<=255 && d>=0 && d<=255){
                            str = to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
                            if(str.size() == n+3)
                                res.push_back(str);
                        }
                    }
                }
            }
        }
        return res;
    }
};