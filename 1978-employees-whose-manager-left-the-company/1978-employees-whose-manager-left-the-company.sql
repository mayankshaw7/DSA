# Write your MySQL query statement below
select t.employee_id from
(select e2.employee_id ,e2.manager_id from employees e2 where e2.salary<30000) as t
where t.manager_id Not in (select e3.employee_id from employees e3)
order by t.employee_id ;