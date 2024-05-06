SELECT min(result.GRADE) GRADE, result.ID, result.EMAIL
FROM (
    SELECT 
        CASE 
            WHEN a.skill_code & d.skill_code && c.skill_code & d.skill_code THEN 'A'
            WHEN b.skill_code & d.skill_code THEN 'B'
            WHEN a.skill_code & d.skill_code THEN 'C'
            ELSE NULL
        END AS GRADE,
        d.id AS ID, 
        d.email AS EMAIL
    FROM 
        developers d,
        (SELECT s.code skill_code FROM skillcodes s WHERE s.category = 'Front End') a,
        (SELECT s.code skill_code FROM skillcodes s WHERE s.name = 'C#') b,
        (SELECT s.code skill_code FROM skillcodes s WHERE s.name = 'Python') c
    HAVING 
        GRADE IS NOT NULL
    order by GRADE ,ID
) result
# order by GRADE,ID
GROUP BY result.GRADE, result.ID, result.EMAIL;

