/**
 * You are given a data structure of employee information, which includes the employee's unique id,
 * his importance value and his direct subordinates' id.
 * 
 * For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3.
 * They have importance value 15, 10 and 5, respectively.
 * Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]],
 * and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1,
 * the relationship is not direct.
 * 
 * Now given the employee information of a company, and an employee id,
 * you need to return the total importance value of this employee and all his subordinates.
 */

#include <iostream>
#include <vector>
#include <map>

// Employee info
class Employee
{
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    std::vector<int> subordinates;
    Employee(int id, int imp, std::vector<int> sub) : id(id), importance(imp), subordinates(sub) {}
};

int getImportance(std::vector<Employee *> employees, int id);
int dfsHelper(std::map<int, Employee *> m, int id);

int main(int argc, char const *argv[])
{
    std::vector<Employee *> employees = {
        new Employee(1, 5, {2, 3}),
        new Employee(2, 3, {}),
        new Employee(3, 3, {})};

    std::cout << getImportance(employees, 1) << '\n';

    return 0;
}

int getImportance(std::vector<Employee *> employees, int id)
{
    std::map<int, Employee *> m;
    for (auto emp : employees)
    {
        m[emp->id] = emp;
    }
    return dfsHelper(m, id);
}

int dfsHelper(std::map<int, Employee *> m, int id)
{
    Employee *emp = m[id];
    int total = emp->importance;

    for (auto sub : emp->subordinates)
    {
        total += dfsHelper(m, sub);
    }
    return total;
}