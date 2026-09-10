# Write your MySQL query statement below
select r.contest_id ,
round((count(r.user_id)*100)/(SELECT COUNT(*) FROM Users),2) as percentage
from users u 
JOIN register as r on r.user_id=u.user_id
group by r.contest_id
order by percentage DESC, r.contest_id ASC;