class Solution {
public:
    int maxArea(int h, int w, vector<int>& hr, vector<int>& vr) {
        sort(begin(hr),end(hr));
        sort(begin(vr),end(vr));
        int len=hr[0];
        for(int i=1;i<hr.size();i++){
            int curr=hr[i]-hr[i-1];
            if(curr>len) len=curr;
        }
        len=max(len,h-hr.back());
        int bre=vr[0];
        for(int i=1;i<vr.size();i++){
            int curr=vr[i]-vr[i-1];
            if(curr>bre) bre=curr;
        }
        bre=max(bre,w-vr.back());
        long long ans=(long long)len*(long long)bre;
        ans%=1000000007;
        return (int)ans;
    }
};