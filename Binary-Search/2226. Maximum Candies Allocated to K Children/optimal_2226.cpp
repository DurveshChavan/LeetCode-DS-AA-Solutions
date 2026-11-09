class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l {1};

        int h {0};

        if (!candies.empty())
        {
         h = *max_element(candies.begin(), candies.end()) ;
        }

        int best {};

        while (l <= h)
        {
          int mid {l + (h - l) /2};

          long long childServed {0};

          for (int pile : candies)
          {
            childServed += pile / mid;
          }
          
          if (childServed >= k)
          {
              best = mid;
              l = mid + 1;
          }
          else
          {
            h = mid - 1;
          }
        }       
    
        return best;
      }
};

/*editorial ans
class Solution {
public:
    bool isPossible(long long candy,vector<int>& candies, long long k){
        // we'll check if giving candy to each children will work for k children
        long long children=0;
        for(auto &x:candies){
            children+=x/candy;
            
        }
        if(children>=k) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long s=0;
        for(auto &x:candies) s+=x;
        if(k>s) return 0;
        long long high=s/k;
        long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isPossible(mid,candies,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
*/