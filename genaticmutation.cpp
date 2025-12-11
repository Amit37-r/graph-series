#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // i will check 
        if (startGene == endGene) return 0;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) return -1; 

        // taking lavel as zero it
        int lavel = 0;
        queue<string> q;
        unordered_set<string> visited; // to check whether that string is already taken or not
        visited.insert(startGene);
        q.push(startGene);

        while (!q.empty()) {
            int sz = q.size();               // <-- layer wrapper added
            for (int node = 0; node < sz; ++node) {
                string front = q.front();
                q.pop();

                for (int i = 0; i < 8; i++) {
                    // creating 4 diffrent string replacing ith character;
                    string t1 = front;
                    t1[i] = 'A';
                    if (t1 == endGene) {
                        return lavel + 1;
                        break;
                    }
                    if (bankSet.count(t1) && !visited.count(t1)) {
                        visited.insert(t1);
                        q.push(t1);
                    }

                    string t2 = front;
                    t2[i] = 'C';
                    if (t2 == endGene) {
                        return lavel + 1;
                        break;
                    }
                    if (bankSet.count(t2) && !visited.count(t2)) {
                        visited.insert(t2);
                        q.push(t2);
                    }

                    string t3 = front;
                    t3[i] = 'G';
                    if (t3 == endGene) {
                        return lavel + 1;
                        break;
                    }
                    if (bankSet.count(t3) && !visited.count(t3)) {
                        visited.insert(t3);
                        q.push(t3);
                    }

                    string t4 = front;
                    t4[i] = 'T';
                    if (t4 == endGene) {
                        return lavel + 1;
                        break;
                    }
                    if (bankSet.count(t4) && !visited.count(t4)) {
                        visited.insert(t4);
                        q.push(t4);
                    }
                }
            }
            lavel++;    // increment after finishing the level
        }

        return -1;
    }
};

