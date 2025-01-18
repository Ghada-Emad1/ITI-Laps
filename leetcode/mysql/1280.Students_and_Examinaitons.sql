--Write your MySQL query statement below
SELECT 
    S.student_id,
    S.student_name,
    subj.subject_name,
    COUNT(E.student_id) AS attended_exams
FROM 
    students S
Cross JOIN 
    Subjects subj
LEFT JOIN 
    Examinations E
    ON E.subject_name = subj.subject_name   AND  S.student_id=E.student_id
GROUP BY 
    S.student_id, S.student_name, subj.subject_name
ORDER BY 
    S.student_id, subj.subject_name;
