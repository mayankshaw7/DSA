# Write your MySQL query statement below
-- did with my own without any help just me own thinking
select e.reports_to as employee_id,(select t.name from employees t where
t.employee_id=e.reports_to) as name,
count(e.reports_to) as reports_count,
round(avg(e.age),0) as average_age
from employees e
where e.reports_to is not null
group by e.reports_to
order by e.reports_to;