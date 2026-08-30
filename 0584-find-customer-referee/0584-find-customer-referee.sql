# Write your MySQL query statement below
/*
-- brtue force
-- select name from
-- ((select id,name from customer
-- where referee_id!=2)
-- UNION
-- (select id,name from customer
-- where referee_id is null)) as t
-- order by id;
*/
SELECT name 
FROM Customer 
WHERE referee_id != 2 OR referee_id IS NULL;
