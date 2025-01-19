# Write your MySQL query statement below
SELECT id,movie,description,rating
FROM Cinema
HAVING id%2=1 AND description <>'boring'
ORDER BY  rating desc;