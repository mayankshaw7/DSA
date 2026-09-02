# Write your MySQL query statement below
-- //did with own
select t.unique_id,e.name from employees e left join(
select u.unique_id,e.name,e.id from EmployeeUNI as u
left join Employees as e on u.id=e.id) as t
on t.id=e.id;

