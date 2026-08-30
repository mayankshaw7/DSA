# Write your MySQL query statement below
select name from
((select id,name from customer
where referee_id!=2)
UNION
(select id,name from customer
where referee_id is null)) as t
order by id;

