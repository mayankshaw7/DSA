# Write your MySQL query statement below
select s.user_id ,
round(IFNULL(sum(c.action='confirmed')/count(c.user_id),0),2) as confirmation_rate 
from signups s left join confirmations as c
on c.user_id=s.user_id
group by s.user_id
;