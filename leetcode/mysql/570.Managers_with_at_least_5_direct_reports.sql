# Write your MySQL query statement below
SELECT  E1.name 
FROM Employee E1
JOIN Employee E2 
WHERE E1.id=E2.managerId 
group by E2.managerId
Having count(E2.managerId)>=5;
