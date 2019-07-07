#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"

// https://leetcode.com/problems/contains-duplicate-ii/
// #include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.count(nums[i]) && i - seen[nums[i]] <= k) {
                return true;
            } else {
                seen[nums[i]] = i;
            }
        }
        return false;
    }
};

void test1() {
    vector<int> v1{1,2,3,1};

    cout << "1 ? " << Solution().containsNearbyDuplicate(v1, 3) << endl;

    vector<int> v2{1,0,1,1};

    cout << "1 ? " << Solution().containsNearbyDuplicate(v2, 1) << endl;

    vector<int> v3{1,2,3,1,2,3};

    cout << "0 ? " << Solution().containsNearbyDuplicate(v3, 2) << endl;
}

void test2() {

}

void test3() {

}