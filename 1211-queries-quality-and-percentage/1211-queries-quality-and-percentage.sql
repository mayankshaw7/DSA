# Write your MySQL query statement below
select q.query_name as query_name,
ROUND(AVG(q.rating/q.position),2) as quality,
ROUND(sum(q.rating<3)*100/count(q.rating),2) as poor_query_percentage
from queries q 
group by query_name;