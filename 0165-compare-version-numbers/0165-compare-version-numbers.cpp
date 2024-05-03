class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.size(),m=v2.size();

        int i=0,j=0;

        while(i<n || j<m)
        {
            int val1=0;

            while(i<n && v1[i]!='.')
            {
                val1=val1*10+(v1[i]-'0');
                i++;
            }
        
            int val2=0;
            while(j<m && v2[j]!='.')
            {
                val2=val2*10+(v2[j]-'0');
                j++;
            }

            if(val1>val2)
            {
                return 1;
            }

            if(val1<val2)
            {
                return -1;
            }

            i++,j++;

        }

        return 0;
    }
};