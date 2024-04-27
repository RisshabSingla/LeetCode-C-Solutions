// class Solution {
// public:
//     // void showdq(deque<char>& g) {
//     //     deque<char>::iterator it;
//     //     for (it = g.begin(); it != g.end(); ++it)
//     //         cout << *it<<" ";
//     //     cout << '\n';
//     // }
//     int findFrontIndex(deque<char>& ring, int size, char ch) {
//         // cout<<"finding: "<<ch<<"\n";
//         // showdq(ring);
        
//         int index = -1;
//         for (int i = 0; i < size; i++) {
//             if (ring.at(i) == ch) {
//                 index = i;
//                 break;
//             }
//         }
//         return index;
//     }
//     int findBackIndex(deque<char>& ring, int size, char ch) {
//         int index = -1;
//         for (int i = size - 1; i >= 0; i--) {
//             if (ring.at(i) == ch) {
//                 index = i;
//                 break;
//             }
//         }
//         return size - index;
//     }
//     int findAns(string key, int index, deque<char>& ring, int klen, int rlen) {
//         if (index == klen) {
//             return 0;
//         }

//         int front = findFrontIndex(ring, rlen, key[index]);
//         int back = findBackIndex(ring, rlen, key[index]);
//         // cout << "front is: " << front << " back is: " << back << '\n';
//         int ans = 0;

//         // if (front < back) {
//         //     ans++;
//         //     ans += front;
//         //     while (front--) {
//         //         char ch = ring.front();
//         //         ring.pop_front();
//         //         ring.push_back(ch);
//         //     }
//         //     return ans + findAns(key, index + 1, ring, klen, rlen);
//         // }

//         // if (front > back) {
//         //     ans++;
//         //     ans += back;
//         //     while (back--) {
//         //         char ch = ring.back();
//         //         ring.pop_back();
//         //         ring.push_front(ch);
//         //     }
//         //     return ans + findAns(key, index + 1, ring, klen, rlen);
//         // }

//         // both front and back are equal

//         deque<char> nring(ring.begin(), ring.end());

//         int a = front + 1;
//         while (front--) {
//             char ch = nring.front();
//             nring.pop_front();
//             nring.push_back(ch);
//         }

//         a += findAns(key, index + 1, nring, klen, rlen);

//         int b = back + 1;
//         while (back--) {
//             char ch = ring.back();
//             ring.pop_back();
//             ring.push_front(ch);
//         }
//         b += findAns(key, index + 1, ring, klen, rlen);
//         return min(a, b);
//     }

//     int findRotateSteps(string rng, string key) {
//         deque<char> ring;
//         for (char& ch : rng) {
//             ring.push_back(ch);
//         }
//         int klen = key.length();
//         int rlen = rng.length(); 
//         return findAns(key, 0, ring, klen, rlen);
//     }
// };


class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> positions;
        for (int i = 0; i < ring.size(); ++i) {
            positions[ring[i]].push_back(i);
        }
        vector<vector<int>> memo(key.size(), vector<int>(ring.size(), -1));
        return helper(0, 0, positions, key, ring, memo);
    }
    
    int helper(int in_index, int pos, unordered_map<char, vector<int>>& positions, string& key, string& ring, vector<vector<int>>& memo) {
        if (in_index == key.size()) {
            return 0;
        }
        if (memo[in_index][pos] != -1) {
            return memo[in_index][pos];
        }
        int min_steps = INT_MAX;
        for (int i : positions[key[in_index]]) {
            int steps;
            if (i >= pos) {
                steps = min(i - pos, static_cast<int>(pos + ring.size()) - i);
            } else {
                steps = min(pos - i, static_cast<int>(i + ring.size()) - pos);
            }
            int next_steps = helper(in_index + 1, i, positions, key, ring, memo);
            min_steps = min(min_steps, steps + next_steps);
        }
        memo[in_index][pos] = min_steps + 1;
        return min_steps + 1;
    }
};
