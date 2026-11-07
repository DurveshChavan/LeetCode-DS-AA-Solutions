/*
l = 0;
h = n-1;

while (l <= h):
  mid = (l + h)/2
  if (array[mid] == target)
    return target found at index mid
  else if (array[mid] < target)
    l = mid+1;
   else
    h = mid-1;
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int l {0};
      int h {(static_cast<int> (nums.size())) - 1};
      /*iteration 1*/
      // [ 0 , 1 , 2, 3, 4, 2, 1 ]
      // [ l___________________h ]

      /*iteration 2*/

      while (l < h)
      {
        int mid {l + (h - l) / 2};
      /*iteration 1*/
      // [ 0 , 1 , 2, 3, 4, 2, 1 ]
      // |            ^          |
      // [           mid         ]

       /*iteration 2*/
      // [ 4, 2, 1]
      // |    ^   |


        if (nums[mid] < nums[mid+1])
        {
          l = mid + 1;
      /*iteration 1*/
      // [ 0 , 1 , 2, 3, 4, 2, 1 ]
      // [               l_____h ]
        }
        else
        {
          h = mid;
        }
      }
      return l;
    }
};
