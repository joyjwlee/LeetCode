/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
  public:
    int getImportance(vector<Employee *> employees, int id) {
        // recur
        int ans = 0;
        for (Employee *i : employees) {
            // if we're at current, call on subordinates
            if (i->id == id) {
                ans += i->importance;
                for (int n : i->subordinates)
                    ans += getImportance(employees, n);
            }
        }
        return ans;
    }
};