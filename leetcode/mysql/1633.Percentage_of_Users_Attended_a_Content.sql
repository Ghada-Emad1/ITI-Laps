-- Write your MySQL query statement below
SELECT contest_id , Round(count(distinct user_id)*100 / (
    select count(user_id) from Users
),2)
AS percentage
From Register
Group by contest_id
order by percentage DESC,contest_id