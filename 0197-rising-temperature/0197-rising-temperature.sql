# Write your MySQL query statement below
select w1.id from weather w join 
weather w1 on DATEDIFF(w1.recordDate,w.recordDate)=1 
where w1.temperature>w.temperature ;