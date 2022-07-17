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
    unordered_map<int, int>v;
    
    int DFS(Employee* emp, vector<Employee*> employees){
        int res = emp->importance;
        
        for(auto next:emp->subordinates){
            res += DFS(employees[v[next]], employees);
        }
        
        cout << emp->id << "-> " << res << "\n";
        return res;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int s=0;
        for(auto node:employees){
            v[node->id] = s++;
        
        }
        
        return DFS(employees[v[id]], employees);
    }
};